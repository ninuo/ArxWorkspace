#include "StdAfx.h"
#include "PaperFrame.h"


CPaperFrame::CPaperFrame(void)
{
	m_dScale = 1.0;
	m_dWidth = 420;
	m_dHeight = 297;
	m_dMarginLeft = 5;
	m_dMarginRight = m_dMarginTop = m_dMarginBottom = 25;
	m_strName = _T("A3");
}


CPaperFrame::~CPaperFrame(void)
{
}

CPaperFrame::CPaperFrame(double dScale, const CString& strName)
{
	setValue(dScale,strName);
}

void CPaperFrame::setValue(double dScale, const CString& strName /* = _T */)
{
	m_dScale = dScale;
	if (0 == strName.CompareNoCase(_T("A0")))
	{
		m_dWidth = 1189;
		m_dHeight = 841;
		m_dMarginLeft = 25;
		m_dMarginRight = m_dMarginTop = m_dMarginBottom = 10;
	}
	else if (0 == strName.CompareNoCase(_T("A1")))
	{
		m_dWidth = 841;
		m_dHeight = 594;
		m_dMarginLeft = 25;
		m_dMarginRight = m_dMarginTop = m_dMarginBottom = 10;
	}
	else if (0 == strName.CompareNoCase(_T("A2")))
	{
		m_dWidth = 594;
		m_dHeight = 420;
		m_dMarginLeft = 25;
		m_dMarginRight = m_dMarginTop = m_dMarginBottom = 10;
	}
	else if (0 == strName.CompareNoCase(_T("A3")))
	{
		m_dWidth = 420;
		m_dHeight = 297;
		m_dMarginLeft = 25;
		m_dMarginRight = m_dMarginTop = m_dMarginBottom = 5;
	}
	else
	{
		m_dWidth = 297;
		m_dHeight = 210;
		m_dMarginLeft = 25;
		m_dMarginRight = m_dMarginTop = m_dMarginBottom = 5;
	}
}