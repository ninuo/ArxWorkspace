#include "StdAfx.h"
#include "PlotVerticalSection.h"


PlotVerticalSection::PlotVerticalSection(void)
{
	m_dMaxAltitude = 1.0;
	m_dMinAltitude = 0.0;
	m_dIntervalPaper = 100.0;
	m_dScale = 1.0;
	m_dDigitHeight = 3.0;
	m_dChineseTextHeight = 4.0;


	m_pBTR = NULL;
	m_strPaperName = _T("A3");
	m_arrSheetTitle.RemoveAll();
	m_arrSheetTitle.Add(_T("桩号"));
	m_arrSheetTitle.Add(_T("坡降"));
	m_arrSheetTitle.Add(_T("现状渠底高程"));
	m_arrSheetTitle.Add(_T("设计渠底高程"));
	m_arrSheetTitle.Add(_T("设计水位高程"));
	m_arrSheetTitle.Add(_T("加大水位高程"));
	m_arrSheetTitle.Add(_T("设计渠顶高程"));
	m_paperFrame.setValue(1.0,_T("A3"));
	m_dPaperValidLength = m_paperFrame.getWidth() - m_paperFrame.getMarginLeft() - m_paperFrame.getMarginRight() - 50 - 6.9;
}


PlotVerticalSection::~PlotVerticalSection(void)
{
}

void PlotVerticalSection::appendData(const AltitudeData& data)
{
	m_arrData.push_back(data);
}

BOOL PlotVerticalSection::createPaperFrame(AcGePoint3d& ptInnerLB, AcGePoint3d& ptInnerRB, const AcGePoint3d& ptBase)
{
	BOOL bRet = TRUE;
	
	double dWidth = m_paperFrame.getWidth();
	double dHeight = m_paperFrame.getHeight();
	AcGeVector3d xDir = AcGeVector3d::kXAxis;
	AcGeVector3d yDir = AcGeVector3d::kYAxis;
	AcGePoint3d pt1 = ptBase;
	AcGePoint3d pt2 = pt1 + xDir * dWidth;
	AcGePoint3d pt3 = pt2 + yDir * dHeight;
	AcGePoint3d pt4 = pt1 + yDir * dHeight;

	//
	double dLeft = m_paperFrame.getMarginLeft();
	double dRight = m_paperFrame.getMarginRight();
	double dTop = m_paperFrame.getMarginTop();
	double dBottom = m_paperFrame.getMarginBottom();
	AcGePoint3d ptInner1 = pt1 + xDir * dLeft + yDir * dBottom;
	AcGePoint3d ptInner2 = ptInner1 + xDir * (dWidth - dLeft - dRight);
	AcGePoint3d ptInner3 = ptInner2 + yDir * (dHeight - dTop - dBottom);
	AcGePoint3d ptInner4 = ptInner1 + yDir * (dHeight - dTop - dBottom);

	AcGePoint3dArray arrPtS;
	arrPtS.append(pt1);
	arrPtS.append(pt2);
	arrPtS.append(pt3);
	arrPtS.append(pt4);
	arrPtS.append(ptInner1);
	arrPtS.append(ptInner2);
	arrPtS.append(ptInner3);
	arrPtS.append(ptInner4);

	AcGePoint3dArray arrPtE;
	arrPtE.append(pt2);
	arrPtE.append(pt3);
	arrPtE.append(pt4);
	arrPtE.append(pt1);
	arrPtE.append(ptInner2);
	arrPtE.append(ptInner3);
	arrPtE.append(ptInner4);
	arrPtE.append(ptInner1);

	for (int i = 0; i < arrPtS.length(); ++ i)
	{
		AcDbLine* pLine = new AcDbLine(arrPtS.at(i), arrPtE.at(i));
		m_pBTR->appendAcDbEntity(pLine);
		pLine->close();
	}

	ptInnerLB = ptInner1;
	ptInnerRB = ptInner2;
	return bRet;
}

double PlotVerticalSection::getPileDist(const CString& strName)
{
	CString strValue = strName;
	int nCommon = strValue.Find(_T("+"));
	return _tstof(strValue.Left(nCommon)) * 1000 + _tstof(strValue.Right(strValue.GetLength()-nCommon-1));
}

void PlotVerticalSection::getCurrentPaperInfo(double& dSum, AcGeDoubleArray& arrWidth, int nIndex)
{
	dSum = 0.0;
	arrWidth.setLogicalLength(0);
	for (int i = nIndex; i < m_arrData.size()-1; ++ i)
	{
		AltitudeData& dataI = m_arrData[i];
		AltitudeData& dateNextI = m_arrData[i+1];
		double dDist = (getPileDist(dateNextI.m_strPileName) - getPileDist(dataI.m_strPileName));
		if (dSum + dDist > m_dPaperValidLength) break;
		dSum += dDist;
		arrWidth.append(dDist);
	}
}

void PlotVerticalSection::createLayers()
{
	m_layerTabId = CArxHelper::SetLayer(_T("tab"));

}

void PlotVerticalSection::initData()
{
	AltitudePlot dataStateBottomAltitude;
	dataStateBottomAltitude.m_nColorIndex = 4;
	dataStateBottomAltitude.m_strName = m_arrSheetTitle.GetAt(2);
	dataStateBottomAltitude.m_arrPts.setLogicalLength(0);
	m_arrAltitudePlot.push_back(dataStateBottomAltitude);

	AltitudePlot dataDesignBottomAltitude;
	dataDesignBottomAltitude.m_nColorIndex = 5;
	dataDesignBottomAltitude.m_strName = m_arrSheetTitle.GetAt(3);
	dataDesignBottomAltitude.m_arrPts.setLogicalLength(0);
	m_arrAltitudePlot.push_back(dataDesignBottomAltitude);

	AltitudePlot dataDesignWaterAltitude;
	dataDesignWaterAltitude.m_nColorIndex = 1;
	dataDesignWaterAltitude.m_strName = m_arrSheetTitle.GetAt(4);
	dataDesignWaterAltitude.m_arrPts.setLogicalLength(0);
	m_arrAltitudePlot.push_back(dataDesignWaterAltitude);

	AltitudePlot dataEnhanceWaterAltitude;
	dataEnhanceWaterAltitude.m_nColorIndex = 2;
	dataEnhanceWaterAltitude.m_strName = m_arrSheetTitle.GetAt(5);
	dataEnhanceWaterAltitude.m_arrPts.setLogicalLength(0);
	m_arrAltitudePlot.push_back(dataEnhanceWaterAltitude);


	AltitudePlot dataDesignTopAltitude;
	dataDesignTopAltitude.m_nColorIndex = 3;
	dataDesignTopAltitude.m_strName = m_arrSheetTitle.GetAt(6);
	dataDesignTopAltitude.m_arrPts.setLogicalLength(0);
	m_arrAltitudePlot.push_back(dataDesignTopAltitude);

}

BOOL PlotVerticalSection::createModel()
{
	BOOL bRet = TRUE;
	initData();
	m_pBTR = CArxHelper::GetBlockTableRecord();
	
	int nCount = 0;
	int nIndex = 0;
	double dSum = 0.0;
	AcGePoint3d pt = AcGePoint3d::kOrigin;
	AcGeDoubleArray arrWidth;
	while (1)
	{
		getCurrentPaperInfo(dSum,arrWidth,nIndex);
		nCount = arrWidth.length();
		if ( 0 == nCount) break;
		AcGePoint3d ptInnerLB;
		AcGePoint3d ptInnerRB;
		createPaperFrame(ptInnerLB,ptInnerRB,pt);
		
		AcGeDoubleArray colWidth;
		AcGeDoubleArray rowHeight;
		colWidth.append(50);
		colWidth.append(6.9);
		for (int i = 0; i <nCount; ++ i)
		{
			colWidth.append(arrWidth.at(i));
		}
		rowHeight.append(20);
		rowHeight.append(15);
		rowHeight.append(15);
		rowHeight.append(15);
		double dSheetHeight = 0.0;
		for (int i = 0; i < rowHeight.length(); ++ i)
		{
			dSheetHeight += rowHeight.at(i);
		}
		double dSheetWidth = 0.0;
		for (int i = 0; i < colWidth.length(); ++ i)
		{
			if (i > 0)
			{
				dSheetWidth += colWidth.at(i);
			}
		}
		AcGePoint3d ptSheet = ptInnerLB + AcGeVector3d::kXAxis * 10.0 + AcGeVector3d::kYAxis * (64.0625 + dSheetHeight);
		TSheet tSheet(m_pBTR,ptSheet,m_layerTabId,256, colWidth, rowHeight);
		tSheet.DrawSheet();
		tSheet.InsertText(0,0,_T("桩号"),m_dChineseTextHeight,m_layerTabId,3,AcDb::kTextCenter,AcDb::kTextVertMid);
		tSheet.InsertText(1,0,_T("设计底板高程"),m_dChineseTextHeight,m_layerTabId,3,AcDb::kTextCenter,AcDb::kTextVertMid);
		tSheet.InsertText(2,0,_T("设计水位"),m_dChineseTextHeight,m_layerTabId,3,AcDb::kTextCenter,AcDb::kTextVertMid);
		tSheet.InsertText(3,0,_T("设计渠顶高程"),m_dChineseTextHeight,m_layerTabId,3,AcDb::kTextCenter,AcDb::kTextVertMid);
		for (int i = 1; i < colWidth.length(); ++ i)
		{
			AltitudeData& data = m_arrData.at(nIndex+i-1);
			tSheet.InsertText(0,i,data.m_strPileName,m_dDigitHeight, m_layerTabId, 3, AcDb::kTextCenter,AcDb::kTextVertMid,PI/2.0,2);
			CString strValue = _T("");
			strValue.Format(_T("%.0f"),data.m_dDesignBottomAltitude);
			tSheet.InsertText(1,i,strValue,m_dDigitHeight, m_layerTabId, 3, AcDb::kTextCenter,AcDb::kTextVertMid,PI/2.0,2);
			strValue.Format(_T("%.0f"),data.m_dDesignWaterAltitude);
			tSheet.InsertText(2,i,strValue,m_dDigitHeight, m_layerTabId, 3, AcDb::kTextCenter,AcDb::kTextVertMid,PI/2.0,2);
			strValue.Format(_T("%.0f"),data.m_dDesignTopAltitude);
			tSheet.InsertText(3,i,strValue,m_dDigitHeight, m_layerTabId, 3, AcDb::kTextCenter,AcDb::kTextVertMid,PI/2.0,2);
		}

		AcGePoint3d ptPileBottom = ptSheet + AcGeVector3d::kXAxis* colWidth.at(0);
		for (int i = 1; i < colWidth.length(); ++ i)
		{
			ptPileBottom = ptPileBottom + AcGeVector3d::kXAxis * colWidth.at(i);
			AcGePoint3d pt1 = ptPileBottom;
			AcGePoint3d pt2 = ptPileBottom + AcGeVector3d::kYAxis * (m_dMaxAltitude -  m_dMinAltitude + 8.0);
			AcDbLine* pLine = new AcDbLine(pt1, pt2);
			pLine->setColorIndex(6);
			m_pBTR->appendAcDbEntity(pLine);
			pLine->close();
		}

		//填充数据
		for (int i = 0; i < m_arrAltitudePlot.size(); ++ i)
		{
			m_arrAltitudePlot.at(i).m_arrPts.setLogicalLength(0);
		}
		AcGePoint3d plotPt = ptSheet + AcGeVector3d::kXAxis* colWidth.at(0) + AcGeVector3d::kYAxis * 8.0;
		for (int i = 1; i < colWidth.length(); ++ i)
		{
			plotPt = plotPt + AcGeVector3d::kXAxis * colWidth.at(i);
			AltitudeData& data = m_arrData.at(nIndex+i-1);
			m_arrAltitudePlot[0].m_arrPts.append(plotPt + AcGeVector3d::kYAxis * (data.m_dStateBottomAltitude - m_dMinAltitude));
			m_arrAltitudePlot[1].m_arrPts.append(plotPt + AcGeVector3d::kYAxis * (data.m_dDesignBottomAltitude - m_dMinAltitude));
			m_arrAltitudePlot[2].m_arrPts.append(plotPt + AcGeVector3d::kYAxis * (data.m_dDesignWaterAltitude - m_dMinAltitude));
			m_arrAltitudePlot[3].m_arrPts.append(plotPt + AcGeVector3d::kYAxis * (data.m_dEnhanceWaterAltitude - m_dMinAltitude));
			m_arrAltitudePlot[4].m_arrPts.append(plotPt + AcGeVector3d::kYAxis * (data.m_dDesignTopAltitude - m_dMinAltitude));
		}

		for (int i = 0; i < m_arrAltitudePlot.size(); ++ i)
		{
			AltitudePlot& plot = m_arrAltitudePlot.at(i);
			AcDbPolyline* pPlot = NULL;
			CArxHelper::CreatePLine(pPlot,plot.m_arrPts,0.0,0);
			pPlot->setColorIndex(plot.m_nColorIndex);
			m_pBTR->appendAcDbEntity(pPlot);
			pPlot->close();

			AcDbText* pText = new AcDbText();
			pText->setPosition(plot.m_arrPts.at(0));
			pText->setTextString(plot.m_strName);
			pText->setColorIndex(plot.m_nColorIndex);
			pText->setHeight(1.0);
			AcDbObjectId textId = AcDbObjectId::kNull;
			m_pBTR->appendAcDbEntity(textId,pText);
			pText->close();
			AcDbExtents extents;
			pText->getGeomExtents(extents);
			AcGeVector3d vect = AcGeVector3d((extents.minPoint().x - extents.maxPoint().x) / 2.0,(extents.minPoint().y - extents.maxPoint().y) / 2.0,0);
			AcGeMatrix3d xform = AcGeMatrix3d::translation(vect);
			acdbOpenObject(pText,textId,AcDb::kForWrite);
			pText->transformBy(xform);
			pText->close();
		}
		AcGePoint3d ptMark = ptSheet + AcGeVector3d::kXAxis * 50.0;
		createMarkLine(ptMark, TRUE);
		ptMark = ptMark + AcGeVector3d::kXAxis * dSheetWidth;
		createMarkLine(ptMark, FALSE);
		pt = pt + AcGeVector3d::kXAxis * (m_paperFrame.getWidth() + m_dIntervalPaper);
		nIndex += nCount;
	}
	
	
	m_pBTR->close();
	return bRet;
}

void PlotVerticalSection::createMarkLine(const AcGePoint3d& ptMark, BOOL bLeft )
{
	AcGeVector3d xDir = bLeft ? (-AcGeVector3d::kXAxis) : AcGeVector3d::kXAxis;
	AcGePoint3d ptMarkLine1 = ptMark + AcGeVector3d::kYAxis * 8.0;
	AcGePoint3d ptMarkLine2 = ptMarkLine1 + AcGeVector3d::kYAxis * (m_dMaxAltitude -  m_dMinAltitude);
	AcGePoint3d ptMarkLine3 = ptMarkLine2 + xDir * 1.0;
	AcGePoint3d ptMarkLine4 = ptMarkLine1 + xDir * 1.0;
	AcGePoint3dArray arrPts;
	arrPts.append(ptMarkLine1); arrPts.append(ptMarkLine2); arrPts.append(ptMarkLine3); arrPts.append(ptMarkLine4);
	AcDbPolyline* pMarkLine = NULL;

	CArxHelper::CreatePLine(pMarkLine,arrPts);
	pMarkLine->setColorIndex(3);
	m_pBTR->appendAcDbEntity(pMarkLine);
	pMarkLine->close();

	AcGePoint3d ptSolid = ptMarkLine1 + xDir * (bLeft ? 1.0 : 0.0) + AcGeVector3d::kYAxis * 10.0;
	for (double dValue = m_dMinAltitude + 10.0; dValue <= m_dMaxAltitude; dValue += 20.0)
	{
		AcDbSolid* pSolid = CArxHelper::CreateSolid(ptSolid,10.0,1.0,3);
		m_pBTR->appendAcDbEntity(pSolid);
		pSolid->close();

		ptSolid = ptSolid + AcGeVector3d::kYAxis * 10.0;
	}

	AcGePoint3d ptText = ptMarkLine1 + xDir * (bLeft ? 10.0 : 3.0) - AcGeVector3d::kYAxis * 1.5;
	for (double dValue = m_dMinAltitude; dValue <= m_dMaxAltitude; dValue += 10.0)
	{
		AcDbText* pText = new AcDbText();
		CString strValue = _T("");
		strValue.Format(_T("%.0f"),dValue);
		pText->setPosition(ptText);
		pText->setTextString(strValue);
		pText->setHeight(m_dDigitHeight);
		pText->setColorIndex(3);
		m_pBTR->appendAcDbEntity(pText);
		pText->close();

		ptText = ptText + AcGeVector3d::kYAxis * 10.0;
	}

	AcDbText* pText = new AcDbText();
	CString strValue = _T("");
	strValue.Format(_T("%s"),_T("高程(m)"));
	pText->setPosition(ptText);
	pText->setTextString(strValue);
	pText->setHeight(m_dChineseTextHeight);
	pText->setColorIndex(3);
	m_pBTR->appendAcDbEntity(pText);
	pText->close();

}