#include "StdAfx.h"
#include "ArxHelper.h"

CArxHelper::CArxHelper(void)
{
}

CArxHelper::~CArxHelper(void)
{
}

AcDbBlockTableRecord* CArxHelper::GetBlockTableRecord(AcDbDatabase* pDatabase, BOOL OpenWrite)
{
	AcDbBlockTable* pBlockTable = NULL;
	pDatabase->getBlockTable(pBlockTable,AcDb::kForRead);
	AcDbBlockTableRecord* pBTR = NULL;
	if (pBlockTable)
	{
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBTR, OpenWrite ? AcDb::kForWrite : AcDb::kForRead);
		pBlockTable->close();
	}
	return pBTR;
}

AcDbObjectId CArxHelper::GetBlockId(const CString& strName)
{
	AcDbBlockTable* pBlockTable = NULL;
	acdbCurDwg()->getBlockTable(pBlockTable,AcDb::kForRead);
	AcDbBlockTableRecord* pBTR = NULL;
	AcDbObjectId blockId = AcDbObjectId::kNull;
	if (pBlockTable)
	{
		pBlockTable->getAt(strName, blockId, AcDb::kForRead);
		pBlockTable->close();
	}

	return blockId;
}

AcDbObjectId CArxHelper::AddToCAD(AcDbEntity *pEntity,int colorIndex ,bool bClose, AcDbObjectId layerId)
{
	AcDbBlockTableRecord* pBlockTableRecord = GetBlockTableRecord();

	if(colorIndex>=0&&colorIndex<=256)
		pEntity->setColorIndex(colorIndex);
	if(layerId!=NULL)
		pEntity->setLayer(layerId);

	AcDbObjectId entityId;
	pBlockTableRecord->appendAcDbEntity(entityId,pEntity);

	if(bClose)
		pEntity->close();

	pBlockTableRecord->close();

	return entityId;
}

int CArxHelper::CreatePLine(AcDbPolyline*& pPolyline, const AcGePoint3dArray& arrPt, double dWith, BOOL bClose)
{
	pPolyline = new AcDbPolyline(arrPt.length());
	for(int i = 0; i < arrPt.length(); i++)
	{
		pPolyline->addVertexAt(i,arrPt.at(i).convert2d(AcGePlane::kXYPlane),0.0);
	}
	pPolyline->setConstantWidth(dWith);
	pPolyline->setClosed(bClose);
	return 0;
}

AcDbObjectId CArxHelper::CreatePLine(const AcGePoint3dArray& arrPt, double dWith, BOOL bClose )
{
	AcDbPolyline  *pLine = NULL;
	CreatePLine(pLine,arrPt,dWith,bClose);
	return AddToCAD(pLine);
}

int CArxHelper::CreateHatch(AcDbHatch*& pHatch, const AcGePoint3dArray& arrPt,double dScale)
{
	AcGePoint2dArray vertices;
	AcGeDoubleArray bulges;
	for (int i = 0; i < arrPt.length(); ++ i)
	{
		vertices.append(arrPt.at(i).convert2d(AcGePlane::kXYPlane));
		bulges.append(0.0);
	}

	if (vertices.length() > 0)
	{
		pHatch = new AcDbHatch();
		AcGeVector3d normal(0.0, 0.0, 1.0);
		pHatch->setNormal(normal);
		pHatch->setElevation(0.0);
		pHatch->setAssociative(Adesk::kFalse);
		pHatch->setPattern(AcDbHatch::kPreDefined, _T("SOLID"));
		pHatch->appendLoop(AcDbHatch::kExternal,vertices,bulges); 
		pHatch->evaluateHatch();
		pHatch->setPatternScale(dScale);
	}
	return 0;
}

AcDbObjectId CArxHelper::CreateBlock(const AcDbVoidPtrArray& arrEnt, const CString& strName)
{
	AcDbObjectId blockId = AcDbObjectId::kNull;
	AcDbBlockTableRecord* pBlockTableRecord = new AcDbBlockTableRecord();
	pBlockTableRecord->setName(strName);
	pBlockTableRecord->setOrigin(AcGePoint3d::kOrigin);
	for (int i = 0; i < arrEnt.length(); ++ i)
	{
		AcDbEntity* pEntity = (AcDbEntity*)arrEnt.at(i);
		pBlockTableRecord->appendAcDbEntity(pEntity);
		pEntity->close();
	}

	AcDbBlockTable* pBlockTable = NULL;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable, AcDb::kForWrite);
	pBlockTable->add(blockId,pBlockTableRecord);
	pBlockTableRecord->close();
	pBlockTable->close();
	return blockId;
}

#include "dbmleader.h"
AcDbObjectId CArxHelper::CreateMLeader(const CString& strText, const AcGePoint3d& ptArrow, const AcGePoint3d& ptBase, const AcGeVector3d& vectDir)
{
	AcDbObjectId leaderId = AcDbObjectId::kNull;
	AcDbMText* pMText = new AcDbMText();
	pMText->setContents(strText);
	pMText->setColorIndex(4);
	AcDbExtents extents;
	pMText->getGeomExtents(extents);
	AcDbMLeader *pEnt=new AcDbMLeader();
	int i = 0;
	pEnt->setContentType(AcDbMLeaderStyle::kMTextContent);
	pEnt->addLeader(i);
	pEnt->addLeaderLine(ptArrow,i);
	pEnt->addLastVertex(i,ptBase);
	pEnt->setDoglegLength(1);
	pEnt->setDoglegDirection(i,vectDir);
	pEnt->setArrowSize(0.001);
	pEnt->setTextAttachmentType(AcDbMLeaderStyle::kAttachmentBottomLine,AcDbMLeaderStyle::kLeftLeader);
	pEnt->setTextAttachmentType(AcDbMLeaderStyle::kAttachmentBottomLine,AcDbMLeaderStyle::kRightLeader);
	pEnt->setTextAlignmentType(AcDbMLeaderStyle::kLeftAlignment);
	pEnt->setMText(pMText);

	AcGePoint3d pt = ptBase+vectDir*(extents.maxPoint().x-extents.minPoint().x)*1.1+AcGeVector3d::kYAxis*(extents.maxPoint().y-extents.minPoint().y)*1.1;
	pEnt->setTextLocation(pt);

	leaderId = AddToCAD(pEnt);
	return leaderId;
}

AcDbObjectId CArxHelper::InsertBlock(const AcDbObjectId& blockId, const AcGePoint3d& ptInsert, double dAngle)
{
	AcDbBlockReference* pBlockReference = new AcDbBlockReference();
	pBlockReference->setBlockTableRecord(blockId);
	pBlockReference->setNormal(AcGeVector3d::kZAxis);
	pBlockReference->setPosition(ptInsert);
	pBlockReference->setRotation(dAngle);

	return AddToCAD(pBlockReference);
}

AcDbObjectId CArxHelper::GetDimStyleId(const CString& strDimName,double dScale)
{
	Acad::ErrorStatus es = Acad::eOk;
	AcDbDimStyleTable* pDimStyleTable = NULL;
	es = acdbHostApplicationServices()->workingDatabase()->getDimStyleTable(pDimStyleTable,AcDb::kForWrite);
	AcDbDimStyleTableRecord* pDimStyleTableRecord = NULL;
	es = pDimStyleTable->getAt(strDimName,pDimStyleTableRecord,AcDb::kForWrite);
	AcDbObjectId styleId;
	if (Acad::eOk == es && NULL != pDimStyleTableRecord)
	{
		pDimStyleTable->getAt(strDimName, styleId);
	}
	else
	{
		pDimStyleTableRecord = new AcDbDimStyleTableRecord();
		pDimStyleTableRecord->setName(strDimName);
		pDimStyleTableRecord->setDimblk(_T(""));
		pDimStyleTableRecord->setDimdec(0);//小数位数
		pDimStyleTableRecord->setDimunit(2);//角度
		pDimStyleTableRecord->setDimzin(0);//删除后续零
		pDimStyleTableRecord->setDimasz(1);//箭头长度
		pDimStyleTableRecord->setDimexe(0.5);//尺寸界线在标注线上方延伸量
		pDimStyleTableRecord->setDimexo(0.5);//尺寸界线起点偏移量
		pDimStyleTableRecord->setDimdli(4.5);//尺寸线间距
		pDimStyleTableRecord->setDimtad(1);//文字位标注线上方于
		pDimStyleTableRecord->setDimtih(0);//尺寸界限内侧的文字水平放置
		pDimStyleTableRecord->setDimtxt(1);// 尺寸文字高度
		pDimStyleTableRecord->setDimgap(0.5);//标注线与文字间距

		pDimStyleTableRecord->setDimatfit(3);//Moves text first, then arrows
		pDimStyleTableRecord->setDimtoh(0);//在界线外，文字与尺寸线对齐
		pDimStyleTableRecord->setDimtmove(1);//Allows text to be moved freely without a leader
		pDimStyleTableRecord->setDimtix(true);//限制文字在界线内
		pDimStyleTableRecord->setDimtofl(true);//Force line inside extension lines
		pDimStyleTableRecord->setDimfxlenOn(true);
		pDimStyleTableRecord->setDimfxlen(2);
		pDimStyleTableRecord->setDimcen(1.5);
		pDimStyleTableRecord->setDimatfit(3);
		pDimStyleTableRecord->setDimtmove(1);

		pDimStyleTableRecord->setDimscale(1.0);// 全局比例
		pDimStyleTableRecord->setDimlfac(dScale);
		pDimStyleTableRecord->setDimlim(true);

		pDimStyleTable->add(styleId,pDimStyleTableRecord);
	}
	pDimStyleTableRecord->close();
	pDimStyleTable->close();


	return styleId;
}


//把一层设置为OFF or ON
void CArxHelper::SetOneLayer(const TCHAR *name,int flag,bool YN)
	//flag 1:isoff 2:isfrozen 3:islocked
{
	AcDbLayerTable *pLayerTable;
	acdbCurDwg()->getLayerTable(pLayerTable,AcDb::kForRead);

	if(!pLayerTable->has(name))
	{
		pLayerTable->close();
		return;
	}

	AcDbObjectId id;
	pLayerTable->getAt(name,id);
	AcDbLayerTableRecord *pLayerTableRecord;
	acdbOpenObject(pLayerTableRecord,id,AcDb::kForWrite);

	switch(flag)
	{
	case 1:
		pLayerTableRecord->setIsOff(YN);
		break;
	case 2:
		pLayerTableRecord->setIsFrozen(YN);
		break;
	case 3:
		pLayerTableRecord->setIsLocked(YN);
		break;
	}

	pLayerTableRecord->close();
	pLayerTable->close();
}

AcDbObjectId CArxHelper::SetLayer(TCHAR* layerName)
{
	AcDbObjectId layerId = NULL;
	AcDbLayerTable *pLayerTbl;
	acdbCurDwg()->getLayerTable(pLayerTbl,AcDb::kForWrite);

	AcDbLayerTableIterator *pItr;
	pLayerTbl->newIterator(pItr);

	for(;!pItr->done();pItr->step())
	{
		AcDbLayerTableRecord *pLayer;
		pItr->getRecord(pLayer,AcDb::kForRead);

		TCHAR *str=NULL;
		pLayer->getName(str);
		if(_tcscmp(layerName,str)==0)
			layerId=pLayer->id();
		if(str!=NULL) delete []str;

		pLayer->close();

		if(layerId!=NULL)
			break;
	}

	delete pItr;
	pItr = NULL;

	if(layerId==NULL)
	{
		AcDbLayerTableRecord *pLayerTblRcd=new AcDbLayerTableRecord();
		Acad::ErrorStatus es = pLayerTblRcd->setName(layerName);
		if (es != Acad::eOk)
			pLayerTblRcd->setName(_T("0"));

		pLayerTbl->add(layerId,pLayerTblRcd);

		pLayerTblRcd->close();
	}

	pLayerTbl->close();

	acdbCurDwg() ->setClayer(layerId);

	return layerId;
}

AcDbObjectId CArxHelper::CreateText(const CString& strText, const AcGePoint3d& pt1, const AcGePoint3d& pt2, double dDist, BOOL bUp /* = TRUE */)
{
	AcDbObjectId textId = AcDbObjectId::kNull;
	AcGePoint3d pt = (pt1 + pt2.asVector()) / 2.0;
	AcDbMText* pMText = new AcDbMText();
	pMText->setContents(strText);
	pMText->setLocation(pt);

	pMText->setDirection(pt2-pt1);

	textId = AddToCAD(pMText,4);

	AcDbExtents extents;
	pMText->getGeomExtents(extents);
	AcGeVector3d vect = (pt2-pt1).normal() * (extents.maxPoint().x - extents.minPoint().x) / 2.0;
	AcGeMatrix3d xform = AcGeMatrix3d::translation(-vect);
	acdbOpenObject(pMText,textId,AcDb::kForWrite);
	pMText->transformBy(xform);
	pMText->close();
	return textId;
}

AcDbSolid* CArxHelper::CreateSolid(const AcGePoint3d& ptBase, double dHeight, double dWidth, int nColorIndex)
{
	AcGePoint3d pt1 = ptBase;
	AcGePoint3d pt2 = ptBase + AcGeVector3d::kYAxis * dHeight;
	AcGePoint3d pt3 = ptBase + AcGeVector3d::kXAxis * dWidth;
	AcGePoint3d pt4 = pt3 + AcGeVector3d::kYAxis * dHeight;

	AcDbSolid* pSolid = new AcDbSolid(pt1, pt2, pt3, pt4);
	pSolid->setColorIndex(nColorIndex);

	return pSolid;
}