#include "StdAfx.h"
#include "ExcelHelper.h"
#include "Excel\CApplication.h"
#include "Excel\CRange.h"
#include "Excel\CWorkbook.h"
#include "Excel\CWorkbooks.h"
#include "Excel\CWorksheet.h"
#include "Excel\CWorksheets.h"
#include "Excel\CBorders.h"

CExcelHelper::CExcelHelper(void)
{
}

CExcelHelper::~CExcelHelper(void)
{
}

int ExportDataExcel(const CStringArray& strContentArray, int nColNum, CString strFileName /* = _T("") */, CString strSheetName /*= _T("sheet1")*/)
{
	int nRet = 0;
	int iRows = strContentArray.GetCount()/nColNum;
	int iCols = nColNum;
	if (iRows > 65536)	//65536为Excel2003版本的最大行数
	{
		AfxMessageBox(_T("已经超过了Excel目前的最大容量!"));
		return -1;
	}
	if (!strFileName.IsEmpty())
		if(FAILED(::CoInitialize(NULL))) return -1 ;

	CApplication oExcel;
	CWorkbooks oBooks;
	CWorkbook oBook;
	CWorksheets oSheets;
	CWorksheet oSheet;
	CRange oRange;

	COleVariant covOptional(DISP_E_PARAMNOTFOUND,VT_ERROR);
	if (oExcel.m_lpDispatch == NULL) {oExcel.CreateDispatch(_T("Excel.Application"));}
	if (!strFileName.IsEmpty())
		oExcel.put_Visible(FALSE);
	else
		oExcel.put_Visible(FALSE);
	oExcel.put_UserControl(TRUE);
	oBooks = oExcel.get_Workbooks();

	VARIANT vtFalse;
	vtFalse.vt=VT_BOOL;
	vtFalse.boolVal=VARIANT_FALSE;

	VARIANT vtTrue;
	vtTrue.vt=VT_BOOL;
	vtTrue.boolVal=VARIANT_TRUE;
	oBook = oBooks.Add(covOptional);
	oSheets = oBook.get_Worksheets();
	oSheet = oSheets.get_Item(COleVariant(short(1)));
	oSheet.put_Name(strSheetName);
	TCHAR cEndCellCol;
	CString strEndCellChars = _T("");
	if(iCols> 26)
	{
		cEndCellCol = TCHAR(_T('A') + iCols/26-1);
		strEndCellChars = CString(cEndCellCol);
	}
	cEndCellCol = TCHAR(_T('A') + iCols%26-1);
	strEndCellChars += CString(cEndCellCol);
	CString strEndCell;
	strEndCell.Format(strEndCellChars + _T("%d"), iRows);

	CString strEndColCell;
	strEndColCell.Format(strEndCellChars + _T("%d"), 1);

	CString strEndRowCell;
	strEndRowCell.Format(_T("A%d"), iRows);

	oRange = oSheet.get_Range(COleVariant(_T("A1")),COleVariant(strEndCell));

	CRange oRangeColHeader = oSheet.get_Range(COleVariant(_T("A1")),COleVariant(strEndColCell));
	CRange oRangeRowHeader = oSheet.get_Range(COleVariant(_T("A1")),COleVariant(strEndRowCell));

	for (long iRow = 1; iRow <= iRows; iRow++)
	{
		for (long iCol = 1; iCol <= iCols; iCol++)
		{
			CString szTemp = strContentArray.GetAt((iRow-1)*iCols+iCol-1);
			oRange.put_Item(COleVariant(iRow),COleVariant(iCol),COleVariant(szTemp));
		}
	}

	if (!strFileName.IsEmpty())
	{
		VARIANT vtFileName;
		vtFileName.vt=VT_BSTR;
		vtFileName.bstrVal=strFileName.AllocSysString();

		oBook.Close(vtTrue, vtFileName, vtFalse);
		SysFreeString(vtFileName.bstrVal);

		oExcel.Quit();

		::CoUninitialize();
	}
	else
	{
		oExcel.put_Visible(TRUE);
	}
	return nRet;
}

int CExcelHelper::ImportDataExcel(CStringArray& strContentArray, int& nColNum)
{
	int nRet = 0;
	strContentArray.RemoveAll();
	nColNum = 0;
	struct resbuf* result = acutNewRb(RTSTR);
	if(!(acedGetFileD(_T("导入文件..."),_T(""),_T("xls;xlsx"),32,result)==RTNORM))
	{
		free(result);
		return -1;
	}

	TCHAR filename[_MAX_PATH];
	_stprintf(filename,result->resval.rstring);
	free(result);

	CString strFileName;
	strFileName.Format(_T("%s"),filename);
	CString strSheetName = _T("Sheet1");
	if(FAILED(::CoInitialize(NULL))) return -1 ;

	CApplication oExcel;
	CWorkbooks oBooks;
	CWorkbook oBook;
	CWorksheets oSheets;
	CWorksheet oSheet;
	CRange oRange;

	COleVariant covOptional(DISP_E_PARAMNOTFOUND,VT_ERROR);
	// If you have not created Excel, create a new instance.
	if (oExcel.m_lpDispatch == NULL) {
		oExcel.CreateDispatch(_T("Excel.Application"));
	}
	// Show Excel to the user.
	oExcel.put_Visible(FALSE);
	oExcel.put_UserControl(TRUE);
	// Add a new workbook and get the first worksheet in that book.
	oBooks = oExcel.get_Workbooks();

	VARIANT vtFalse;
	vtFalse.vt=VT_BOOL;
	vtFalse.boolVal=VARIANT_FALSE;

	VARIANT vtTrue;
	vtTrue.vt=VT_BOOL;
	vtTrue.boolVal=VARIANT_TRUE;

	oBook = oBooks.Open(strFileName, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional);
	//	oBook = oBooks.Open(strFileName, vtFalse, vtTrue, vtFalse, vtFalse, vtTrue, vtFalse, vtFalse, vtFalse, vtTrue, vtFalse, vtFalse, vtTrue, vtTrue, vtTrue);
	oSheets = oBook.get_Worksheets();

	try
	{
		oSheet = oSheets.get_Item(COleVariant(strSheetName));
	}
	catch (...)
	{
		oBook.Close(vtFalse, vtFalse, vtFalse);
		oExcel.Quit();
		::CoUninitialize();
		AfxMessageBox(_T("Sheet的名称必须为")+strSheetName);
		return 1;
	}
	oRange = oSheet.get_UsedRange();

	// Get the data.
	COleSafeArray saRet(oRange.get_Value(covOptional));
	long iRows;
	long iCols;
	saRet.GetUBound(1, &iRows);
	saRet.GetUBound(2, &iCols);

	long index[2];

	// Loop through the data and report the contents.
	for (int rowCounter = 1; rowCounter <= iRows; rowCounter++)
	{
		for (int colCounter = 1; colCounter <= iCols; colCounter++)
		{
			index[0]=rowCounter;
			index[1]=colCounter;
			COleVariant vData;
			saRet.GetElement(index,vData);
			CString szdata(vData);
			strContentArray.Add(vData);
		}
	}
	oBook.Close(vtFalse, vtFalse, vtFalse);
	oExcel.Quit();

	::CoUninitialize();
	nColNum = iCols;
	return nRet;
}