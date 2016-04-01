#include "StdAfx.h"
#include "PlotCrossSection.h"


PlotCrossSection::PlotCrossSection(void)
{
	m_dScale = 0.2;
}


PlotCrossSection::~PlotCrossSection(void)
{
}

void PlotCrossSection::appendData(const ChannelData& data)
{
	m_arrChannelData.push_back(data);
}

BOOL PlotCrossSection::createModel()
{
	BOOL bRet = TRUE;
	AcDbObjectId blockId;
	bRet = getBlockId(blockId,_T("make_Tk_cx2015"));
	return bRet;
}

BOOL PlotCrossSection::getBlockId(AcDbObjectId& blockId, const CString& strBlockName)
{
	Acad::ErrorStatus es = Acad::eOk;
	//获得要插入的块名
	CString blockname = strBlockName;
	//blockname = "CHART-20";

	//寻找是否已经定义
	AcDbDatabase *pCurDb = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTable *pBlkTable;
	pCurDb->getBlockTable(pBlkTable, AcDb::kForRead);

	if(!pBlkTable->has(blockname))
	{
		pBlkTable->close();
		AcDbDatabase *pDwg =new AcDbDatabase (Adesk::kFalse) ;
		CString strConfigFileName = _T("");
		strConfigFileName.Format(_T("d:\\config.dwg"));
		pDwg->readDwgFile(strConfigFileName);
		es = pCurDb->insert (blockId, blockname, pDwg);
		delete pDwg ;
		pDwg = NULL;
		if ( es != Acad::eOk )
		{
			acutPrintf (_T("\n模板文件有误码.")) ;
			return FALSE;
		}
	}

	else
		pBlkTable->getAt(blockname, blockId);

	pBlkTable->close();
	
	return TRUE;
}

BOOL PlotCrossSection::insertBlockReference(const AcDbObjectId& blockId)
{
	BOOL bRet = TRUE;

	AcGePoint3d ptBase = AcGePoint3d::kOrigin;
	//获得模型空间块表记录
	AcDbBlockTable *pBlockTable ;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable (pBlockTable, AcDb::kForRead) ;
	AcDbBlockTableRecord *pBlockTableRecord ;
	pBlockTable->getAt (ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite) ;
	pBlockTable->close () ;

	for (int i = 0; i < m_arrChannelData.size(); ++ i)
	{	
		//---- 设置插入点，旋转角度，比例等等
		AcDbBlockReference *pBlkRef =new AcDbBlockReference(ptBase,blockId) ;
		//pBlkRef->setBlockTableRecord (blockId) ;
		pBlkRef->setScaleFactors(AcGeScale3d(m_dScale,m_dScale,1));
		pBlkRef->setRotation (0.0) ;
		pBlkRef->setLayer(NULL); //设置图层
		pBlockTableRecord->appendAcDbEntity(pBlkRef);

		//获得属性
		AcDbBlockTableRecord *pBlkDefRecord;
		acdbOpenObject(pBlkDefRecord, blockId, AcDb::kForRead);

		if(pBlkDefRecord->hasAttributeDefinitions())
		{
			AcDbBlockTableRecordIterator *pIterator;
			pBlkDefRecord->newIterator(pIterator);

			for(pIterator->start(); !pIterator->done();pIterator->step())
			{
				AcDbEntity *pEnt = NULL;
				pIterator->getEntity(pEnt, AcDb::kForRead);
				AcDbAttributeDefinition *pAttDef = AcDbAttributeDefinition::cast(pEnt);

				if(pAttDef != NULL && !pAttDef->isConstant())
				{
					CString strTag = pAttDef->tagConst();
					int xx = 0;
					/*
					AcDbAttribute* pAtt = new AcDbAttribute();
					pAtt->setPropertiesFrom(pAttDef);
					pAtt->setInvisible( pAttDef->isInvisible() );

					pAtt->setHorizontalMode(pAttDef->horizontalMode());
					pAtt->setVerticalMode(pAttDef->verticalMode());

					AcGePoint3d basePt = pAttDef->alignmentPoint();
					basePt += ptBase.asVector();
					pAtt->setAlignmentPoint(basePt);

					pAtt->setHeight(pAttDef->height());
					pAtt->setTextStyle(pAttDef->textStyle());

					pAtt->setTag(pAttDef->tag());
					pAtt->setTextString(m_attrib);
					pAtt->setFieldLength(25);

					pBlkRef->appendAttribute(pAtt);
					pAtt->close();
					pEnt->close();
					*/
				}
				pAttDef->close();
			}
			delete pIterator;
		}//end if pBlkDefRecord->hasAttributeDefinitions

		pBlkDefRecord->close();
		pBlkRef->close();

		ptBase = ptBase + AcGeVector3d::kXAxis * 240;
	}
	pBlockTableRecord->close();
	/*
	BeginEditorCommand();
	//ShowWindow(SW_HIDE);
	ads_point pt={0,0,0};
	int rc=acedGetPoint(NULL,"\n选择插入点:",pt);
	if (rc==RTCAN||rc==RTNONE)
	{
		acutPrintf("\n*取消了插入操作*");
		CancelEditorCommand();
		return;
	}
	CompleteEditorCommand();

	//---- 设置插入点，旋转角度，比例等等
	AcDbBlockReference *pBlkRef =new AcDbBlockReference(AcGePoint3d(pt[0],pt[1],pt[2]),blockId) ;
	//pBlkRef->setBlockTableRecord (blockId) ;
	pBlkRef->setScaleFactors(AcGeScale3d(m_scale,m_scale,1));
	//pBlkRef->setPosition(AcGePoint3d(pt[0],pt[1],pt[2])) ;
	pBlkRef->setRotation (m_angle) ;
	pBlkRef->setLayer(NULL); //设置图层



	//获得模型空间块表记录
	AcDbBlockTable *pBlockTable ;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable (pBlockTable, AcDb::kForRead) ;
	AcDbBlockTableRecord *pBlockTableRecord ;
	pBlockTable->getAt (ACDB_MODEL_SPACE, pBlockTableRecord,AcDb::kForWrite) ;
	pBlockTable->close () ;
	pBlockTableRecord->appendAcDbEntity(pBlkRef);

	//获得属性
	AcDbBlockTableRecord *pBlkDefRecord;
	acdbOpenObject(pBlkDefRecord, blockId, AcDb::kForRead);

	if(pBlkDefRecord->hasAttributeDefinitions())
	{
		//AcDbObjectIterator* pBlkIterator = pBlkRef->attributeIterator(); //修改

		AcDbBlockTableRecordIterator *pIterator;
		pBlkDefRecord->newIterator(pIterator);

		for(pIterator->start(); !pIterator->done();pIterator->step())
		{
			AcDbEntity *pEnt;
			pIterator->getEntity(pEnt, AcDb::kForRead);
			AcDbAttributeDefinition *pAttDef = AcDbAttributeDefinition::cast(pEnt);

			if(pAttDef != NULL && !pAttDef->isConstant())
			{
				AcDbAttribute* pAtt = new AcDbAttribute();
				pAtt->setPropertiesFrom(pAttDef);
				pAtt->setInvisible( pAttDef->isInvisible() );

				pAtt->setHorizontalMode(pAttDef->horizontalMode());
				pAtt->setVerticalMode(pAttDef->verticalMode());

				AcGePoint3d basePt = pAttDef->alignmentPoint();
				basePt[0]+=pt[0];
				basePt[1]+=pt[1];
				basePt[2]+=pt[2];
				pAtt->setAlignmentPoint(basePt);

				pAtt->setHeight(pAttDef->height());
				pAtt->setTextStyle(pAttDef->textStyle());

				pAtt->setTag(pAttDef->tag());
				pAtt->setTextString(m_attrib);
				pAtt->setFieldLength(25);

				pBlkRef->appendAttribute(pAtt);
				pAtt->close();
				pEnt->close();
			}
		}
		delete pIterator;
	}//end if pBlkDefRecord->hasAttributeDefinitions

	pBlkDefRecord->close();
	pBlockTableRecord->close();
	pBlkRef->close();
	*/
	return bRet;
}