#pragma once
#include "arxHeperDefine.h"

class ARXHELPER_API CExcelHelper
{
public:
	CExcelHelper(void);
	~CExcelHelper(void);

	static int ExportDataExcel(const CStringArray& strContentArray, int nColNum, CString strFileName = _T(""), CString strSheetName = _T("sheet1"));
	static int ImportDataExcel(CStringArray& strContentArray, int& nColNum);
};
