#include "StdAfx.h"
#include "PlotSection.h"
#include "ArxHelper.h"

PlotSection::PlotSection(void)
{
	m_dRatioBase = 1.0;
	m_dRatioReal = 100.0;
	m_dStateWidth = 1.5;
	m_dStateHeight = 4;
	m_dStateInnerSlope = 1;
	m_dStateOutterSlope = 1.5;
	m_dDesignWidth = 1.5;
	m_dDesignHeight = 5;
	m_dDesignInnerSlope = 1.5;
	m_dDesignOutterSlope = 1.8;
	m_dLiningThick = 0.08;
	m_dTopDiff = 1;

	m_ptInsert = AcGePoint3d::kOrigin;
	m_dScale = 1000.0;
	m_dInnerLiningWidth = 300.0;
	m_dInnerGrassLength = 0.5;
	m_dGrassInterval = 200;
	m_nGrassNum = 5;

	//左块数据
	m_dLeftBlockTopWidth = 300;
	m_dLeftBlockBottomWidth = 500;
	m_dLeftBlockHeight = 500;
	//右块数据
	m_dBlockFilterBedWidth = 100;
	m_dBlockFilterBedHeight = 500;
	m_dBlockDragFeetWidth = 400;
	m_dBlockDrainWidth = 300;
	m_dBlockDrainHeight = 300;
	m_dBlockDrainThick = 100;

	//
	m_ptInnerStateBottom = AcGePoint3d::kOrigin;
	m_ptInnerDesignBottom = AcGePoint3d::kOrigin;
	m_ptOutterStateBottom = AcGePoint3d::kOrigin;
	m_ptOutterDesignBottom = AcGePoint3d::kOrigin;
	m_ptLeftBlockInsert = AcGePoint3d::kOrigin;
}

PlotSection::~PlotSection(void)
{
}

BOOL PlotSection::CreateModel()
{
	BOOL bRet = TRUE;
	InitData();
	//标注
	m_DimStyleId = CArxHelper::GetDimStyleId(_T("1-100"),100);
	CreateStateModel();
	CreateDesignModel();

	AcDbLine* pInnerLine = new AcDbLine(m_ptInnerDesignBottom,m_ptInnerStateBottom);
	AcDbLine* pOutterLine = new AcDbLine(m_ptOutterDesignBottom,m_ptOutterStateBottom);

	CArxHelper::AddToCAD(pInnerLine);
	CArxHelper::AddToCAD(pOutterLine);

	//加标注
	CreateDim();
	CreateAnnotation();
	return bRet;
}
/*
BOOL PlotSection::CreateStateModel2()
{
	BOOL bRet = TRUE;

	AcGePoint3d ptTopLeft = m_ptInsert - AcGeVector3d::kXAxis * m_dStateWidth * m_dScale/2.0;
	AcGePoint3d ptTopRight = m_ptInsert + AcGeVector3d::kXAxis * m_dStateWidth * m_dScale/2.0;

	//InnerSlope
	//Grass
	double dInnerGrassLength = m_dInnerGrassLength * m_dScale;
	AcGeVector3d vectInnserSlope = (AcGeVector3d(-m_dStateInnerSlope,-1.0,0.0)).normal();
	AcGePoint3d ptInnserGrass = ptTopLeft + vectInnserSlope * dInnerGrassLength;

	AcGePoint3dArray arrLining;
	arrLining.append(ptInnserGrass);
	//Lining
	double dInnerSlopeLength = ((sqrt(1+m_dStateInnerSlope*m_dStateInnerSlope))*m_dStateHeight - m_dInnerGrassLength) * m_dScale;
	AcGePoint3d ptLiningTopLeft = ptInnserGrass - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	arrLining.append(ptLiningTopLeft);
	AcGePoint3d ptLiningBottomLeft = ptLiningTopLeft + vectInnserSlope * dInnerSlopeLength;
	arrLining.append(ptLiningBottomLeft);
	
	//
	AcGePoint3d pt1 = ptInnserGrass - AcGeVector3d::kYAxis * m_dLiningThick * m_dScale;
	AcGePoint3d pt2 = pt1 - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	AcGePoint3d pt3 = pt2 + vectInnserSlope * dInnerSlopeLength;
	arrLining.append(pt3);
	arrLining.append(pt2);
	arrLining.append(pt1);
	arrLining.append(ptInnserGrass);

	//OutterSlope
	AcGeVector3d vectOutterSlope = (AcGeVector3d(m_dStateOutterSlope,-1.0,0.0)).normal();
	double dOutterSlopeLength = (sqrt(1+m_dStateOutterSlope*m_dStateOutterSlope))*m_dStateHeight * m_dScale;
	AcGePoint3d ptOutterSlopeBottom = ptTopRight + vectOutterSlope * dOutterSlopeLength;

	//现在顶部
	AcDbLine* pLineTop = new AcDbLine(ptTopLeft,ptTopRight);
	CArxHelper::AddToCAD(pLineTop);
	//内坡
	AcDbLine* pLineInnerGrass = new AcDbLine(ptTopLeft, ptInnserGrass);
	CArxHelper::AddToCAD(pLineInnerGrass);
	//内坡草皮
	AcDbObjectId blockGrassId = CreateGrass();
	double dInnerDist = pLineInnerGrass->startPoint().distanceTo(pLineInnerGrass->endPoint());
	AcGeVector3d vectInner = (pLineInnerGrass->endPoint() - pLineInnerGrass->startPoint()).normal();
	double dAngle = AcGeVector3d::kXAxis.angleTo(-vectInner,AcGeVector3d::kZAxis);
	m_dGrassInterval = dInnerDist / m_nGrassNum;
	for (int i = 0; i < m_nGrassNum-1; ++ i)
	{
		AcGePoint3d pt = pLineInnerGrass->startPoint() + vectInner * (i+1) * m_dGrassInterval;
		CArxHelper::InsertBlock(blockGrassId, pt, dAngle);
	}


	CArxHelper::CreatePLine(arrLining);
	AcDbHatch* pHatch = NULL;
	CArxHelper::CreateHatch(pHatch,arrLining);
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
	CArxHelper::AddToCAD(pHatch);

	//外坡
	AcDbLine* pLineOutter = new AcDbLine(ptTopRight, ptOutterSlopeBottom);
	CArxHelper::AddToCAD(pLineOutter);
	//外坡草皮
	double dOutterDist = pLineOutter->startPoint().distanceTo(pLineOutter->endPoint());
	AcGeVector3d vect = (pLineOutter->endPoint() - pLineOutter->startPoint()).normal();
	dAngle = AcGeVector3d::kXAxis.angleTo(vect,AcGeVector3d::kZAxis);
	m_dGrassInterval = dOutterDist / m_nGrassNum;
	for (int i = 0; i < m_nGrassNum-1; ++ i)
	{
		AcGePoint3d pt = pLineOutter->startPoint() + vect * (i+1) * m_dGrassInterval;
		CArxHelper::InsertBlock(blockGrassId, pt, dAngle);
	}

	return bRet;
}
*/
AcDbObjectId PlotSection::CreateGrass()
{
	const double nGrassHeight = 20.5934 / m_dScale;
	const double nGrassThick = 0.254 / m_dScale;
	const int nGrassColor = 3;

	AcGePoint2d ptInsert = AcGePoint2d::kOrigin;
	AcGePoint2dArray arrPtE;
	AcGeDoubleArray arrBuldge;
	arrBuldge.append(-0.3077);
	arrBuldge.append(0.3077);
	arrBuldge.append(0.0);
	arrPtE.append(AcGePoint2d(13.1745 / m_dScale,18.7540 / m_dScale));
	arrPtE.append(AcGePoint2d(-13.1745 / m_dScale,18.7540 / m_dScale));
	arrPtE.append(AcGePoint2d(0.0, nGrassHeight));

	AcDbVoidPtrArray arrGrass;
	for(int i = 0; i < arrPtE.length(); ++ i)
	{
		AcDbPolyline* pGrass = new AcDbPolyline();
		pGrass->addVertexAt(0,ptInsert,arrBuldge.at(i));
		pGrass->addVertexAt(1,arrPtE.at(i),0.0);
		pGrass->setConstantWidth(nGrassThick);
		pGrass->setColorIndex(nGrassColor);
		arrGrass.append(pGrass);
	}

	return CArxHelper::CreateBlock(arrGrass,_T("CAO"));
}

BOOL PlotSection::CreateDesignDim()
{
	BOOL bRet = TRUE;

	double dDist = 1.0;
	AcGePoint3d ptBase = m_ptInsert;
	AcGePoint3d pt1 = ptBase - AcGeVector3d::kXAxis * m_dDesignWidth / 2.0;
	AcGePoint3d pt2 = pt1 + AcGeVector3d::kXAxis * m_dDesignWidth;
	AcGePoint3d pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * dDist;
	CString strValue = _T("");
	strValue.Format(_T("%.0f"), m_dDesignWidth);
	AcDbAlignedDimension *pDim = new AcDbAlignedDimension(pt1, pt2,pt3,NULL,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = m_ptInnerGrassBottom;
	pt2 = pt1 - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * dDist;
	strValue.Format(_T("%.0f"), m_dInnerLiningWidth * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2,pt3,NULL,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	return bRet;
}

BOOL PlotSection::CreateLeftBlockDim()
{
	BOOL bRet = TRUE;

	double dDist = 1.0;
	AcGePoint3d ptBase = m_ptLeftBlockInsert;
	AcGePoint3d pt1 = ptBase;
	AcGePoint3d pt2 = pt1 - AcGeVector3d::kXAxis * m_dLeftBlockTopWidth;
	AcGePoint3d pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * dDist;
	CString strValue = _T("");
	strValue.Format(_T("%.0f"), m_dLeftBlockTopWidth * m_dScale);
	AcDbAlignedDimension *pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);
	pt1 = ptBase - AcGeVector3d::kYAxis * m_dLeftBlockHeight;
	pt2 = pt1 - AcGeVector3d::kXAxis * m_dLeftBlockBottomWidth;
	pt3 = (pt1 + pt2.asVector()) /  2.0 - AcGeVector3d::kYAxis * dDist * 3;
	strValue.Format(_T("%.0f"), m_dLeftBlockBottomWidth * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = ptBase - AcGeVector3d::kXAxis * m_dLeftBlockBottomWidth;
	pt2 = pt1 - AcGeVector3d::kYAxis * m_dLeftBlockHeight;
	pt3 = (pt1 + pt2.asVector()) / 2.0 - AcGeVector3d::kXAxis * dDist;
	strValue.Format(_T("%.0f"), m_dLeftBlockHeight * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2, pt3, strValue, m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	return bRet;
}

BOOL PlotSection::CreateRightBlockDim()
{
	BOOL bRet = TRUE;

	double dDist = 1.0;
	AcGePoint3d ptBase = m_ptRightBlockInsert;
	AcGePoint3d pt1 = ptBase;
	AcGePoint3d pt2 = pt1 + AcGeVector3d::kXAxis * m_dBlockFilterBedWidth;
	AcGePoint3d pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * 2 * dDist;
	CString strValue = _T("");
	strValue.Format(_T("%.0f"), m_dBlockFilterBedWidth * m_dScale);
	AcDbAlignedDimension *pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);
	pt1 = pt2;
	pt2 = pt1 + AcGeVector3d::kXAxis * m_dBlockDragFeetWidth;
	pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * dDist;
	strValue.Format(_T("%.0f"), m_dBlockDragFeetWidth * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = pt2;
	pt2 = pt1 + AcGeVector3d::kXAxis * m_dBlockDrainWidth;
	pt3 = (pt1 + pt2.asVector()) / 2.0 + AcGeVector3d::kYAxis * dDist;
	strValue.Format(_T("%.0f"), m_dBlockDrainWidth * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2, pt3, strValue, m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = pt2;
	pt2 = pt1 + AcGeVector3d::kXAxis * m_dBlockDrainThick;
	pt3 = (pt1 + pt2.asVector()) / 2.0 + AcGeVector3d::kYAxis * 2 * dDist;
	strValue.Format(_T("%.0f"), m_dBlockDrainThick * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2, pt3, strValue, m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = pt2;
	pt2 = pt1 - AcGeVector3d::kYAxis * m_dBlockFilterBedHeight;
	pt3 = (pt1 + pt2.asVector()) / 2.0 + AcGeVector3d::kXAxis * 3 * dDist;
	strValue.Format(_T("%.0f"), m_dBlockFilterBedHeight * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2, pt3, strValue, m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	return bRet;
}

BOOL PlotSection::CreateDim()
{
	BOOL bRet = TRUE;
	CArxHelper::SetLayer(_T("标注"));
	bRet = CreateLeftBlockDim();
	bRet = CreateRightBlockDim();
	bRet = CreateDesignDim();
	return bRet;
}


BOOL PlotSection::CreateAnnotation()
{
	BOOL bRet = TRUE;
	CArxHelper::SetLayer(_T("文字标注"));
	CString strText = _T("");
	strText.Format(_T("1:%g"),m_dDesignInnerSlope);
	AcGePoint3d pt1 = m_ptInsert - AcGeVector3d::kXAxis * m_dDesignWidth / 2.0;
	AcGePoint3d pt2 = m_ptInnerGrassBottom;
	CArxHelper::CreateText(strText,pt1, pt2, 1.0);
	return bRet;
}

AcDbObjectId PlotSection::CreateLeftBlock()
{
	CString strName = _T("LEFTBLOCK");
	AcDbObjectId blockId = CArxHelper::GetBlockId(strName);
	if ( AcDbObjectId::kNull == blockId)
	{
		AcGePoint3d ptInsert = AcGePoint3d::kOrigin;
		AcGePoint3dArray arrPts;
		AcGePoint3d pt1 = ptInsert - AcGeVector3d::kYAxis * m_dLeftBlockHeight;
		AcGePoint3d pt2 = pt1 - AcGeVector3d::kXAxis * m_dLeftBlockBottomWidth;
		AcGePoint3d pt3 = ptInsert - AcGeVector3d::kXAxis * m_dLeftBlockTopWidth;
		arrPts.append(ptInsert);
		arrPts.append(pt1);
		arrPts.append(pt2);
		arrPts.append(pt3);
		arrPts.append(ptInsert);
		/*
		AcDbDiametricDimension *pDim3 = new AcDbDiametricDimension(Pt6, Pt7,leaderLength,dimText,dimrecordid);
		pDim3->setLeaderLength(20);
		*/

		AcDbVoidPtrArray arrEnts;
		AcDbPolyline* pPolyline = new AcDbPolyline();
		for (int i = 0; i < arrPts.length(); ++ i)
		{
			pPolyline->addVertexAt(i,arrPts.at(i).convert2d(AcGePlane::kXYPlane),0.0);
		}
		arrEnts.append(pPolyline);
		AcDbHatch* pHatch = NULL;
		CArxHelper::CreateHatch(pHatch,arrPts);
		pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
		arrEnts.append(pHatch);

		blockId = CArxHelper::CreateBlock(arrEnts,strName);
	}

	return blockId;
}

AcDbObjectId PlotSection::CreateRightBlock()
{
	CString strName = _T("RIGHTBLOCK");
	AcDbObjectId blockId = CArxHelper::GetBlockId(strName);
	if ( AcDbObjectId::kNull == blockId)
	{
		AcGePoint3d ptInsert = AcGePoint3d::kOrigin;
		AcGePoint3dArray arrPts;
		AcGePoint3d pt1 = ptInsert;
		AcGePoint3d pt2 = pt1 - AcGeVector3d::kYAxis * m_dBlockFilterBedHeight;
		AcGePoint3d pt3 = pt2 + AcGeVector3d::kXAxis * m_dBlockFilterBedWidth;
		AcGePoint3d pt4 = pt1 + AcGeVector3d::kXAxis * m_dBlockFilterBedWidth;
		arrPts.append(pt1);
		arrPts.append(pt2);
		arrPts.append(pt3);
		arrPts.append(pt4);
		AcDbPolyline* pPolyline = NULL;
		AcDbVoidPtrArray arrEnts;
		CArxHelper::CreatePLine(pPolyline,arrPts);
		arrEnts.append(pPolyline);
		AcDbHatch* pHatch = NULL;
		CArxHelper::CreateHatch(pHatch,arrPts);
		pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
		arrEnts.append(pHatch);

		arrPts.setLogicalLength(0);
		pt1 = pt4 + AcGeVector3d::kXAxis * m_dBlockDragFeetWidth;
		pt2 = pt3 + AcGeVector3d::kXAxis * m_dBlockDragFeetWidth;
		arrPts.append(pt4);
		arrPts.append(pt1);
		arrPts.append(pt2);
		arrPts.append(pt3);
		CArxHelper::CreatePLine(pPolyline,arrPts);
		arrEnts.append(pPolyline);

		arrPts.setLogicalLength(0);
		AcGePoint3d ptDrain1 = pt1 - AcGeVector3d::kYAxis * m_dBlockDrainHeight;
		AcGePoint3d ptDrain2 = ptDrain1 + AcGeVector3d::kXAxis * m_dBlockDrainWidth;
		AcGePoint3d ptDrain3 = ptDrain2 + AcGeVector3d::kYAxis * m_dBlockDrainHeight;
		AcGePoint3d ptDrain4 = ptDrain3 + AcGeVector3d::kXAxis * m_dBlockDrainThick;
		AcGePoint3d ptDrain5 = ptDrain4 - AcGeVector3d::kYAxis * (m_dBlockDrainThick+m_dBlockDrainHeight);
		AcGePoint3d ptDrain6 = ptDrain1 - AcGeVector3d::kYAxis * m_dBlockDrainThick;
		arrPts.append(ptDrain1);
		arrPts.append(ptDrain2);
		arrPts.append(ptDrain3);
		arrPts.append(ptDrain4);
		arrPts.append(ptDrain5);
		arrPts.append(ptDrain6);
		CArxHelper::CreatePLine(pPolyline,arrPts);
		arrEnts.append(pPolyline);
		CArxHelper::CreateHatch(pHatch,arrPts);
		pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
		arrEnts.append(pHatch);

		blockId =  CArxHelper::CreateBlock(arrEnts,strName);
	}	

	return blockId;
}

BOOL PlotSection::CreateDesignModel()
{
	BOOL bRet = TRUE;
	int nColorIndex = 0;
	AcGePoint3d ptTopLeft = m_ptInsert - AcGeVector3d::kXAxis * m_dDesignWidth / 2.0;
	AcGePoint3d ptTopRight = m_ptInsert + AcGeVector3d::kXAxis * m_dDesignWidth/ 2.0;

	//InnerSlope
	//Grass
	double dInnerGrassLength = m_dInnerGrassLength;
	AcGeVector3d vectInnserSlope = (AcGeVector3d(-m_dDesignInnerSlope,-1.0,0.0)).normal();
	AcGePoint3d ptInnserGrass = ptTopLeft + vectInnserSlope * dInnerGrassLength;

	AcGePoint3dArray arrLining;
	arrLining.append(ptInnserGrass);
	//Lining
	double dInnerSlopeLength = ((sqrt(1+m_dDesignInnerSlope*m_dDesignInnerSlope))*m_dDesignHeight - m_dInnerGrassLength);
	AcGePoint3d ptLiningTopLeft = ptInnserGrass - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	arrLining.append(ptLiningTopLeft);
	AcGePoint3d ptLiningBottomLeft = ptLiningTopLeft + vectInnserSlope * dInnerSlopeLength;
	arrLining.append(ptLiningBottomLeft);
	m_ptInnerGrassBottom = ptLiningBottomLeft;

	//
	AcGePoint3d pt1 = ptInnserGrass - AcGeVector3d::kYAxis * m_dLiningThick;
	AcGePoint3d pt2 = pt1 - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	AcGePoint3d pt3 = pt2 + vectInnserSlope * dInnerSlopeLength;
	arrLining.append(pt3);
	arrLining.append(pt2);
	arrLining.append(pt1);
	arrLining.append(ptInnserGrass);
	m_ptLeftBlockInsert = ptLiningBottomLeft;
	AcDbObjectId leftBlockId = CreateLeftBlock();
	CArxHelper::InsertBlock(leftBlockId,ptLiningBottomLeft,0.0);
	m_ptInnerDesignBottom = pt3;

	//OutterSlope
	AcGeVector3d vectOutterSlope = (AcGeVector3d(m_dDesignOutterSlope,-1.0,0.0)).normal();
	double dOutterSlopeLength = (sqrt(1+m_dDesignOutterSlope*m_dDesignOutterSlope))*m_dDesignHeight;
	AcGePoint3d ptOutterSlopeBottom = ptTopRight + vectOutterSlope * dOutterSlopeLength;
	m_ptOutterDesignBottom = ptOutterSlopeBottom;

	//现在顶部
	AcDbLine* pLineTop = new AcDbLine(ptTopLeft,ptTopRight);
	CArxHelper::AddToCAD(pLineTop);
	//内坡
	AcDbLine* pLineInnerGrass = new AcDbLine(ptTopLeft, ptInnserGrass);
	CArxHelper::AddToCAD(pLineInnerGrass);
	//内坡草皮
	AcDbObjectId blockGrassId = CreateGrass();
	double dInnerDist = pLineInnerGrass->startPoint().distanceTo(pLineInnerGrass->endPoint());
	AcGeVector3d vectInner = (pLineInnerGrass->endPoint() - pLineInnerGrass->startPoint()).normal();
	double dAngle = AcGeVector3d::kXAxis.angleTo(-vectInner,AcGeVector3d::kZAxis);
	m_dGrassInterval = dInnerDist / m_nGrassNum;
	for (int i = 0; i < m_nGrassNum-1; ++ i)
	{
		AcGePoint3d pt = pLineInnerGrass->startPoint() + vectInner * (i+1) * m_dGrassInterval;
		CArxHelper::InsertBlock(blockGrassId, pt, dAngle);
	}


	CArxHelper::CreatePLine(arrLining);
	AcDbHatch* pHatch = NULL;
	CArxHelper::CreateHatch(pHatch,arrLining);
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
	CArxHelper::AddToCAD(pHatch);

	//外坡
	AcDbLine* pLineOutter = new AcDbLine(ptTopRight, ptOutterSlopeBottom);
	CArxHelper::AddToCAD(pLineOutter);
	//外坡草皮
	double dOutterDist = pLineOutter->startPoint().distanceTo(pLineOutter->endPoint());
	AcGeVector3d vect = (pLineOutter->endPoint() - pLineOutter->startPoint()).normal();
	dAngle = AcGeVector3d::kXAxis.angleTo(vect,AcGeVector3d::kZAxis);
	m_nGrassNum *= 3;
	m_dGrassInterval = dOutterDist / m_nGrassNum;
	for (int i = 0; i < m_nGrassNum-1; ++ i)
	{
		AcGePoint3d pt = pLineOutter->startPoint() + vect * (i+1) * m_dGrassInterval;
		CArxHelper::InsertBlock(blockGrassId, pt, dAngle);
	}
	AcDbObjectId rightBlockId = CreateRightBlock();
	CArxHelper::InsertBlock(rightBlockId,ptOutterSlopeBottom,0.0);
	m_ptRightBlockInsert = ptOutterSlopeBottom;

	return bRet;
}


BOOL PlotSection::InitData()
{
	BOOL bRet = TRUE;
	m_dScale = 1000.0;

	m_dStateWidth *= m_dScale;
	m_dStateHeight *= m_dScale;
	m_dDesignWidth *= m_dScale;
	m_dDesignHeight *= m_dScale;
	m_dLiningThick *= m_dScale;
	m_dTopDiff *= m_dScale;


	m_dScale = (m_dRatioReal / m_dRatioBase);

	m_dStateWidth /= m_dScale;
	m_dStateHeight /= m_dScale;
	m_dDesignWidth /= m_dScale;
	m_dDesignHeight /= m_dScale;
	m_dLiningThick /= m_dScale;
	m_dTopDiff /= m_dScale;


	m_dInnerLiningWidth /= m_dScale;

	//左块数据
	m_dLeftBlockTopWidth /= m_dScale;
	m_dLeftBlockBottomWidth /= m_dScale;
	m_dLeftBlockHeight /= m_dScale;
	//右块数据
	m_dBlockFilterBedWidth /= m_dScale;
	m_dBlockFilterBedHeight /= m_dScale;
	m_dBlockDragFeetWidth /= m_dScale;
	m_dBlockDrainWidth /= m_dScale;
	m_dBlockDrainHeight /= m_dScale;
	m_dBlockDrainThick /= m_dScale;

	m_ptInsert = m_ptInsert + AcGeVector3d::kYAxis * m_dDesignHeight;
	return bRet;
}

BOOL PlotSection::CreateStateModel()
{
	BOOL bRet = TRUE;
	int nColorIndex = 1;
	AcGePoint3d ptBase = m_ptInsert - AcGeVector3d::kYAxis * m_dTopDiff;
	AcGePoint3d ptTopLeft = ptBase - AcGeVector3d::kXAxis * m_dStateWidth / 2.0;
	AcGePoint3d ptTopRight = ptBase + AcGeVector3d::kXAxis * m_dStateWidth / 2.0;

	double dInnerSlopeLength = ((sqrt(1+m_dStateInnerSlope*m_dStateInnerSlope))*m_dStateHeight);
	AcGeVector3d vectInnserSlope = (AcGeVector3d(-m_dStateInnerSlope,-1.0,0.0)).normal();
	AcGePoint3d ptInnerSlopeBottom = ptTopLeft + vectInnserSlope * dInnerSlopeLength;

	double dOutterSlopeLength = ((sqrt(1+m_dStateOutterSlope*m_dStateOutterSlope))*m_dStateHeight);
	AcGeVector3d vectOutterSlope = (AcGeVector3d(m_dStateOutterSlope,-1.0,0.0)).normal();
	AcGePoint3d ptOutterSlopeBottom = ptTopRight + vectOutterSlope * dOutterSlopeLength;

	//设计顶部
	AcDbLine* pLineTop = new AcDbLine(ptTopLeft,ptTopRight);
	CArxHelper::AddToCAD(pLineTop,nColorIndex);
	//内坡
	AcDbLine* pLineInner = new AcDbLine(ptTopLeft, ptInnerSlopeBottom);
	CArxHelper::AddToCAD(pLineInner,nColorIndex);
	//外坡
	AcDbLine* pLineOutter = new AcDbLine(ptTopRight, ptOutterSlopeBottom);
	CArxHelper::AddToCAD(pLineOutter,nColorIndex);

	m_ptInnerStateBottom = ptInnerSlopeBottom;
	m_ptOutterStateBottom = ptOutterSlopeBottom;

	return bRet;
}
