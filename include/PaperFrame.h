#pragma once
#include "arxHeperDefine.h"

class ARXHELPER_API CPaperFrame
{
public:
	CPaperFrame(void);
	~CPaperFrame(void);
	CPaperFrame(double dScale, const CString& strName);
	void setValue(double dScale, const CString& strName);
	double getWidth() const { return m_dWidth * m_dScale; }
	void setWidth(double val) { m_dWidth = val; }
	double getHeight() const { return m_dHeight * m_dScale; }
	void setHeight(double val) { m_dHeight = val; }
	double getMarginLeft() const { return m_dMarginLeft * m_dScale; }
	void setMarginLeft(double val) { m_dMarginLeft = val; }
	double getMarginRight() const { return m_dMarginRight * m_dScale; }
	void setMarginRight(double val) { m_dMarginRight = val; }
	double getMarginTop() const { return m_dMarginTop * m_dScale; }
	void setMarginTop(double val) { m_dMarginTop = val; }
	double getMarginBottom() const { return m_dMarginBottom * m_dScale; }
	void setMarginBottom(double val) { m_dMarginBottom = val; }
private:
	double m_dScale;
	double m_dWidth;
	double m_dHeight;
	double m_dMarginLeft;
	double m_dMarginRight;
	double m_dMarginTop;
	double m_dMarginBottom;
	CString m_strName;
};

