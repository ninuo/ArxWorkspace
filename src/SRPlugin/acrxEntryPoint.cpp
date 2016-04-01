// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("PSH")
#include "PlotSection.h"
#include "PlotVerticalSection.h"
#include "PlotCrossSection.h"
//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CSRPluginApp : public AcRxArxApp {

public:
	CSRPluginApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here
		addMenu();	
		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}

	void addMenu()
	{
		CAddCADFrameMenu menu;
		menu.AddMenu(_T("我的菜单"));
		menu.AddSubMenu(_T("断面"), _T("PlotSection "));
		menu.AddSubMenu(_T("纵断面"), _T("PlotVerticalSection "));
		menu.AddSubMenu(_T("横断面"), _T("PlotCrossSection "));
		menu.CreateMenus();
	}


	// - PSHSRPlugin.CreatePatch command (do not rename)
	static void PSHSRPluginCreatePatch(void)
	{
		// Add your code for command PSHSRPlugin.CreatePatch here
		AcGePoint3dArray arrPt;
		arrPt.append(AcGePoint3d(0,0,0));
		arrPt.append(AcGePoint3d(1000,0,0));
		arrPt.append(AcGePoint3d(1500,1500,0));
		arrPt.append(AcGePoint3d(1000,2000,0));
		arrPt.append(AcGePoint3d(0,0,0));
		AcDbHatch* pHatch = NULL;
		CArxHelper::CreateHatch(pHatch,arrPt);
		pHatch->setPattern(AcDbHatch::kPreDefined, _T("AR-CONC"));
		CArxHelper::AddToCAD(pHatch);
		CArxHelper::CreatePLine(arrPt);
	}

	// - PSHSRPlugin.ReadData command (do not rename)
	static void PSHSRPluginPlotSection(void)
	{
		// Add your code for command PSHSRPlugin.ReadData here
		if (1)
		{
			CStringArray arrContent;
			int nColNum = 0;
			CExcelHelper::ImportDataExcel(arrContent,nColNum);
			if (nColNum == 0) return;
			AcGePoint3d pt = AcGePoint3d::kOrigin;
			for (int i = 0; i < arrContent.GetCount() / nColNum; ++ i)
			{
				if (0 == i) continue;
				PlotSection plotSection;
				for (int j = 0; j < nColNum; ++ j)
				{
					CString strValue = arrContent.GetAt(i*nColNum+j);
					switch (j)
					{
					case 0:
						break;
					case 1:
						plotSection.setName(strValue);
						break;
					case 2:
						{
							int nCommon = strValue.Find(_T("："));
							plotSection.setRatioBase(_tstof(strValue.Left(nCommon)));
							plotSection.setRatioReal(_tstof(strValue.Right(strValue.GetLength()-nCommon-1)));
						}
						break;
					case 3:
						plotSection.setStateWidth(_tstof(strValue));
						break;
					case 4:
						plotSection.setStateHeight(_tstof(strValue));
						break;
					case 5:
						plotSection.setStateInnerSlope(_tstof(strValue));
						break;
					case 6:
						plotSection.setStateOutterSlope(_tstof(strValue));
						break;
					case 7:
						plotSection.setDesignWidth(_tstof(strValue));
						break;
					case 8:
						plotSection.setDesignHeight(_tstof(strValue));
						break;
					case 9:
						plotSection.setDesignInnerSlope(_tstof(strValue));
						break;
					case 10:
						plotSection.setDesignOutterSlope(_tstof(strValue));
						break;
					case 11:
						plotSection.setLiningThick(_tstof(strValue));
						break;
					case 12:
						plotSection.setTopDiff(_tstof(strValue));
						break;
					}
				}
				//pt = pt + AcGeVector3d::kXAxis * (plotSection.getStateWidth() * (1+plotSection.getStateInnerSlope()+plotSection.getStateOutterSlope()) * 1000 * 2);
				plotSection.setInsert(pt);
				pt = pt + AcGeVector3d::kXAxis * 1000;
				plotSection.CreateModel();
			}
		}
		else
		{
			PlotSection plotSection;
			plotSection.CreateModel();
		}
	}

	static void setData(double& dDist, double& dMax, double& dMin, CString& strValue)
	{
		double dValue = _tstof(strValue);
		dMax = dMax > dValue ? dMax : dValue;
		dMin = dMin < dValue ? dMin : dValue;
		dDist = dValue;
	}

	// - PSHSRPlugin.VerticalSection command (do not rename)
	static void PSHSRPluginPlotVerticalSection(void)
	{
		// Add your code for command PSHSRPlugin.VerticalSection here
		CStringArray arrContent;
		int nColNum = 0;
		CExcelHelper::ImportDataExcel(arrContent,nColNum);
		if (nColNum == 0) return;
		AcGePoint3d pt = AcGePoint3d::kOrigin;
		double dAltitudeMax = -1.0E30;
		double dAltitudeMin = 1.0E30;
		PlotVerticalSection plot;
		for (int i = 0; i < arrContent.GetCount() / nColNum; ++ i)
		{
			if (0 == i) continue;
			PlotVerticalSection::AltitudeData data;
			double dValue = 0.0;
			for (int j = 0; j < nColNum; ++ j)
			{
				CString strValue = arrContent.GetAt(i*nColNum+j);
				switch (j)
				{
				case 0:
					data.m_strPileName = strValue;
					break;
				case 1:
					{
						dValue = _tstof(strValue);
						data.m_dSlope = dValue;
					}
					break;
				case 2:
					{
						setData(data.m_dStateBottomAltitude, dAltitudeMax, dAltitudeMin, strValue);
					}
					break;
				case 3:
					setData(data.m_dDesignBottomAltitude, dAltitudeMax, dAltitudeMin, strValue);
					break;
				case 4:
					setData(data.m_dDesignWaterAltitude, dAltitudeMax, dAltitudeMin, strValue);
					break;
				case 5:
					setData(data.m_dEnhanceWaterAltitude, dAltitudeMax, dAltitudeMin, strValue);
					break;
				case 6:
					setData(data.m_dDesignTopAltitude, dAltitudeMax, dAltitudeMin, strValue);
					break;
				}
			}

			plot.appendData(data);

			//pt = pt + AcGeVector3d::kXAxis * (plotSection.getStateWidth() * (1+plotSection.getStateInnerSlope()+plotSection.getStateOutterSlope()) * 1000 * 2);
			/*plotSection.setInsert(pt);
			pt = pt + AcGeVector3d::kXAxis * 1000;
			plotSection.CreateModel();*/
		}
		dAltitudeMax = ceil(dAltitudeMax/10.0)*10.0;
		dAltitudeMin = floor(dAltitudeMin/10.0)*10.0;

		plot.setMaxAltitude(dAltitudeMax);
		plot.setMinAltitude(dAltitudeMin);
		plot.createModel();
	}

	// - PSHSRPlugin.PlotCrossSection command (do not rename)
	static void PSHSRPluginPlotCrossSection(void)
	{
		// Add your code for command PSHSRPlugin.PlotCrossSection here
		CStringArray arrContent;
		int nColNum = 0;
		CExcelHelper::ImportDataExcel(arrContent,nColNum);
		if (nColNum == 0) return;
		PlotCrossSection plot;
		for (int i = 0; i < arrContent.GetCount() / nColNum; ++ i)
		{
			if (0 == i) continue;

			PlotCrossSection::ChannelData data;
			double dValue = 0.0;
			for (int j = 0; j < nColNum; ++ j)
			{
				CString strValue = arrContent.GetAt(i*nColNum+j);
				switch (j)
				{
				case 0:
					data.m_nNo = _tstoi(strValue);
					break;
				case 1:
					{
						data.m_strName = strValue;
					}
					break;
				case 2:
					{
						data.m_dIrrigatedArea = _tstof(strValue);
					}
					break;
				case 3:
					data.m_dIrrigatedArea = _tstof(strValue);
					break;
				case 4:
					data.m_dLength = _tstof(strValue);
					break;
				case 5:
					data.m_dVerticalSlope = _tstof(strValue);
					break;
				case 6:
					data.m_dLeftSlope = _tstof(strValue);
					break;
				case 7:
					data.m_dRightSlope = _tstof(strValue);
					break;
				case 8:
					data.m_dDesignFlow = _tstof(strValue);
					break;
				case 9:
					data.m_dEnhanceFlow = _tstof(strValue);
					break;
				case 10:
					data.m_dDesignWidth = _tstof(strValue);
					break;
				case 11:
					data.m_dHeight = _tstof(strValue);
					break;
				case 12:
					data.m_dDesignHeight = _tstof(strValue);
					break;
				case 13:
					data.m_dEnhanceHeight = _tstof(strValue);
					break;
				case 14:
					data.m_dLiningHeight = _tstof(strValue);
					break;
				case 15:
					data.m_dLiningThickness = _tstof(strValue);
					break;
				case 16:
					data.m_strStartPileNo = (strValue);
					break;
				case 17:
					data.m_strEndPileNo = (strValue);
					break;
				case 18:
					data.m_dTop = _tstof(strValue);
					break;
				case 19:
					data.m_dEnhance = _tstof(strValue);
					break;
				case 20:
					data.m_dDesign = _tstof(strValue);
					break;
				case 21:
					data.m_dBottom = _tstof(strValue);
					break;
				}
			}

			plot.appendData(data);

			//pt = pt + AcGeVector3d::kXAxis * (plotSection.getStateWidth() * (1+plotSection.getStateInnerSlope()+plotSection.getStateOutterSlope()) * 1000 * 2);
			/*plotSection.setInsert(pt);
			pt = pt + AcGeVector3d::kXAxis * 1000;
			plotSection.CreateModel();*/
		}
		plot.createModel();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CSRPluginApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CSRPluginApp, PSHSRPlugin, CreatePatch, CreatePatch, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSRPluginApp, PSHSRPlugin, PlotSection, PlotSection, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSRPluginApp, PSHSRPlugin, PlotVerticalSection, PlotVerticalSection, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSRPluginApp, PSHSRPlugin, PlotCrossSection, PlotCrossSection, ACRX_CMD_TRANSPARENT, NULL)
