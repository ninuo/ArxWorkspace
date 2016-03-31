#pragma once
#include "arxHeperDefine.h"

class ARXHELPER_API TSheet
{
public:
	TSheet(AcDbBlockTableRecord *pBTR,AcGePoint3d pt,AcDbObjectId layerId,int nColorIndex,AcGeDoubleArray colWidth, AcGeDoubleArray rowHigh);
	~TSheet(void);
	void DrawSheet();
	void InsertText(int posx,int posy,CString text,double texthigh,AcDbObjectId layerId,int color,
		AcDb::TextHorzMode hMode,AcDb::TextVertMode vMode,double dAngle = 0.0, int nAlign = 0);
	void InsertText(AcGePoint3d p,CString text,double texthigh,AcDbObjectId layerId,int color,
		AcDb::TextHorzMode hMode,AcDb::TextVertMode vMode,double dAngle = 0.0);
protected:
	void DrawLine(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	

private:
	AcDbBlockTableRecord* m_pBTR;
	AcGePoint3d m_ptBase;
	AcDbObjectId m_layerId;
	int m_nColorIndex;
	AcGeDoubleArray m_arrColWidth;
	AcGeDoubleArray m_arrRowHeight;


};

