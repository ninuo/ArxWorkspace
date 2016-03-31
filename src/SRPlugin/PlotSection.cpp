#include "StdAfx.h"
#include "PlotSection.h"

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

	m_dStateWidth = 3.6;
	m_dStateHeight = 12;
	m_dStateInnerSlope = 1.8;
	m_dStateOutterSlope = 1.8;
	m_dDesignWidth = 3.6;
	m_dDesignHeight = 12.3;
	m_dDesignInnerSlope = 1.8;
	m_dDesignOutterSlope = 2;
	m_dLiningThick = 0.08;
	m_dTopDiff = 0.3;
	m_dInterval = 10.0;

	//
	m_ptInsert = AcGePoint3d::kOrigin;
	m_dScale = 1000.0;
	m_dInnerLiningWidth = 300.0;
	m_dInnerGrassLength = 1.0;
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

	//
	AcGePoint3d pt = m_ptInsert - AcGeVector3d::kXAxis * m_dDesignHeight * m_dDesignInnerSlope * 2.0 / 3.0 - AcGeVector3d::kYAxis * m_dStateHeight / 4.0 ;
	CreateWaterLevelMark(pt,_T("校核水位"));
	pt = pt - AcGeVector3d::kXAxis * 20.0 - AcGeVector3d::kYAxis * 10.0;
	CreateWaterLevelMark(pt,_T("校核水位"));
	return bRet;
}


AcDbObjectId PlotSection::CreateGrass()
{
	CString strName = _T("CAO");
	AcDbObjectId blockId = CArxHelper::GetBlockId(strName);
	if ( AcDbObjectId::kNull == blockId)
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

		blockId = CArxHelper::CreateBlock(arrGrass,strName);
	}

	return blockId;
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
	strValue.Format(_T("%.0f"), m_dDesignWidth * m_dScale);
	AcDbAlignedDimension *pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
	CArxHelper::AddToCAD(pDim);

	pt1 = m_ptInnerGrassBottom;
	pt2 = pt1 - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
	pt3 = (pt1 + pt2.asVector()) /  2.0 + AcGeVector3d::kYAxis * dDist;
	strValue.Format(_T("%.0f"), m_dInnerLiningWidth * m_dScale);
	pDim = new AcDbAlignedDimension(pt1, pt2,pt3,strValue,m_DimStyleId);
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
	double dDist = 1.0;
	CArxHelper::SetLayer(_T("文字标注"));
	CString strText = _T("");
	strText.Format(_T("1:%g"),m_dDesignInnerSlope);
	AcGePoint3d pt1 = m_ptInsert - AcGeVector3d::kXAxis * m_dDesignWidth / 2.0;
	AcGePoint3d pt2 = m_ptInnerGrassBottom;
	CArxHelper::CreateText(strText,pt2, pt1, 1.0);

	//
	//strText = _T("草皮护坡");
	//AcGePoint3d ptArrow = (pt1 + pt2.asVector()) / 2.0;
	//AcGePoint3d ptBase = ptArrow + AcGeVector3d(-1.0,2.0,0.0) * dDist;
	//AcGeVector3d vectDir = -AcGeVector3d::kXAxis;
	//CArxHelper::CreateMLeader(strText, ptArrow, ptBase, vectDir);

	strText.Format(_T("1:%g"),m_dStateInnerSlope);
	pt1 = m_ptInnerStateTop;
	pt2 = m_ptInnerStateBottom;
	CArxHelper::CreateText(strText,pt2, pt1, 1.0);

	strText.Format(_T("1:%g"),m_dStateOutterSlope);
	pt1 = m_ptOutterStateTop;
	pt2 = m_ptOutterStateBottom;
	CArxHelper::CreateText(strText,pt1, pt2, 1.0);

	strText.Format(_T("1:%g"),m_dDesignOutterSlope);
	pt1 = m_ptOutterDesignTop;
	pt2 = m_ptOutterDesignBottom;
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

	m_ptInnerDesignTop = ptTopLeft;
	m_ptOutterDesignTop = ptTopRight;

	//OutterSlope
	AcGeVector3d vectOutterSlope = (AcGeVector3d(m_dDesignOutterSlope,-1.0,0.0)).normal();
	double dOutterSlopeLength = (sqrt(1+m_dDesignOutterSlope*m_dDesignOutterSlope))*m_dDesignHeight;
	AcGePoint3d ptOutterSlopeBottom = ptTopRight + vectOutterSlope * dOutterSlopeLength;
	m_ptOutterDesignBottom = ptOutterSlopeBottom;

	//现在顶部
	AcDbLine* pLineTop = new AcDbLine(ptTopLeft,ptTopRight);
	CArxHelper::AddToCAD(pLineTop);
	double dInterval = m_dInterval;
	int nDivideNum = int(m_dDesignHeight / dInterval) + 1;
	double dHeight = 100.0;
	//内坡草皮
	AcDbObjectId blockGrassId = CreateGrass();
	for (int i = 0; i < nDivideNum; ++ i)
	{
		dHeight = (i == nDivideNum-1 ? (m_dDesignHeight - i * dInterval) : dInterval);

		//InnerSlope
		//Grass
		double dInnerGrassLength = m_dInnerGrassLength;
		AcGeVector3d vectInnserSlope = (AcGeVector3d(-m_dDesignInnerSlope,-1.0,0.0)).normal();
		AcGePoint3d ptInnserGrass = ptTopLeft + vectInnserSlope * dInnerGrassLength;
		if (0 == i)
		{
			m_ptInnerGrassBottom = ptInnserGrass;
		}

		AcGePoint3dArray arrLining;
		arrLining.append(ptInnserGrass);
		//Lining
		double dInnerSlopeLength = ((sqrt(1+m_dDesignInnerSlope*m_dDesignInnerSlope))*dHeight - m_dInnerGrassLength);
		AcGePoint3d ptLiningTopLeft = ptInnserGrass - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
		arrLining.append(ptLiningTopLeft);
		AcGePoint3d ptLiningBottomLeft = ptLiningTopLeft + vectInnserSlope * dInnerSlopeLength;
		arrLining.append(ptLiningBottomLeft);

		//
		AcGePoint3d pt1 = ptInnserGrass - AcGeVector3d::kYAxis * m_dLiningThick;
		AcGePoint3d pt2 = pt1 - AcGeVector3d::kXAxis * m_dInnerLiningWidth;
		AcGePoint3d pt3 = pt2 + vectInnserSlope * dInnerSlopeLength;
		arrLining.append(pt3);
		arrLining.append(pt2);
		arrLining.append(pt1);
		arrLining.append(ptInnserGrass);
		m_ptLeftBlockInsert = ptLiningBottomLeft;
		if (i == nDivideNum-1)
		{
			AcDbObjectId leftBlockId = CreateLeftBlock();
			CArxHelper::InsertBlock(leftBlockId,ptLiningBottomLeft,0.0);
		}
		
		m_ptInnerDesignBottom = pt3;

		//内坡
		AcDbLine* pLineInnerGrass = new AcDbLine(ptTopLeft, ptInnserGrass);
		CArxHelper::AddToCAD(pLineInnerGrass);

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

		ptTopLeft = ptLiningBottomLeft;
	}
	//外坡
	AcDbLine* pLineOutter = new AcDbLine(ptTopRight, ptOutterSlopeBottom);
	CArxHelper::AddToCAD(pLineOutter);
	//外坡草皮
	double dOutterDist = pLineOutter->startPoint().distanceTo(pLineOutter->endPoint());
	AcGeVector3d vect = (pLineOutter->endPoint() - pLineOutter->startPoint()).normal();
	double dAngle = AcGeVector3d::kXAxis.angleTo(vect,AcGeVector3d::kZAxis);
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
	m_dInnerGrassLength *= m_dScale;
	m_dInterval *= m_dScale;


	m_dScale = (m_dRatioReal / m_dRatioBase);

	m_dStateWidth /= m_dScale;
	m_dStateHeight /= m_dScale;
	m_dDesignWidth /= m_dScale;
	m_dDesignHeight /= m_dScale;
	m_dLiningThick /= m_dScale;
	m_dTopDiff /= m_dScale;
	m_dInnerGrassLength /= m_dScale;


	m_dInnerLiningWidth /= m_dScale;
	m_dInterval /= m_dScale;
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
	m_ptInnerStateTop = ptTopLeft;
	m_ptOutterStateTop = ptTopRight;

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

BOOL PlotSection::CreateWaterLevelMark(const AcGePoint3d& pt, const CString& strName)
{
	BOOL bRet = TRUE;
	double dLength = 0.8268;
	AcGePoint3dArray arrLeftPt;
	AcGePoint3dArray arrRightPt;
	arrLeftPt.append(pt-AcGeVector3d::kXAxis*0.8268/2.0);
	arrLeftPt.append(pt-AcGeVector3d::kXAxis*1.7595/2.0+AcGeVector3d::kYAxis*0.4878);
	arrLeftPt.append(pt-AcGeVector3d::kXAxis*2.6921/2.0+AcGeVector3d::kYAxis*0.8991);
	arrLeftPt.append(pt-AcGeVector3d::kXAxis*1.6416+AcGeVector3d::kYAxis*1.3487);
	arrLeftPt.append(pt+AcGeVector3d::kYAxis*1.3487);
	arrLeftPt.append(pt-AcGeVector3d::kXAxis*2.0000+AcGeVector3d::kYAxis*3.3487);
	arrLeftPt.append(pt+AcGeVector3d::kXAxis*2.0000+AcGeVector3d::kYAxis*3.3487);

	arrRightPt.append(pt+AcGeVector3d::kXAxis*0.8268/2.0);
	arrRightPt.append(pt+AcGeVector3d::kXAxis*1.7595/2.0+AcGeVector3d::kYAxis*0.4878);
	arrRightPt.append(pt+AcGeVector3d::kXAxis*2.6921/2.0+AcGeVector3d::kYAxis*0.8991);
	arrRightPt.append(pt+AcGeVector3d::kXAxis*11.4361+AcGeVector3d::kYAxis*1.3487);
	arrRightPt.append(pt-AcGeVector3d::kXAxis*2.0000+AcGeVector3d::kYAxis*3.3487);
	arrRightPt.append(pt+AcGeVector3d::kXAxis*2.0000+AcGeVector3d::kYAxis*3.3487);
	arrRightPt.append(pt+AcGeVector3d::kYAxis*1.3487);
	
	for (int i = 0; i < arrLeftPt.length(); ++ i)
	{
		AcDbLine* pLine = new AcDbLine(arrLeftPt.at(i),arrRightPt.at(i));
		CArxHelper::AddToCAD(pLine);
	}
	AcGePosition3d ptText = pt+AcGeVector3d::kXAxis*2.1000+AcGeVector3d::kYAxis*2.000;
	AcDbText* pText = new AcDbText(ptText,strName,NULL,2.0);
	CArxHelper::AddToCAD(pText,4);

	return bRet;
}