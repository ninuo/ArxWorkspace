#include "StdAfx.h"
#include "TSheet.h"


TSheet::TSheet(AcDbBlockTableRecord *pBTR,AcGePoint3d pt,AcDbObjectId layerId,int nColorIndex,AcGeDoubleArray colWidth, AcGeDoubleArray rowHigh)
{
	m_pBTR = pBTR;
	m_ptBase = pt;
	m_layerId = layerId;
	m_nColorIndex = nColorIndex;
	m_arrColWidth = colWidth;
	m_arrRowHeight = rowHigh;
}


TSheet::~TSheet(void)
{
	m_arrRowHeight.setLogicalLength(0);
	m_arrColWidth.setLogicalLength(0);
}

void TSheet::DrawLine(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	AcDbLine* pLine = new AcDbLine(pt1, pt2);
	pLine->setColorIndex(m_nColorIndex);
	if (m_layerId)
	{
		pLine->setLayer(m_layerId);
	}
	m_pBTR->appendAcDbEntity(pLine);
	pLine->close();
}

void TSheet::DrawSheet()
{
	double dTotalWidth = 0.0;
	for (int i = 0; i < m_arrColWidth.length(); ++ i)
	{
		dTotalWidth += m_arrColWidth.at(i);
	}

	double dTotalHeight = 0.0;
	for (int i = 0; i < m_arrRowHeight.length(); ++ i)
	{
		dTotalHeight += m_arrRowHeight.at(i);
	}
	
	AcGePoint3d pt1 = m_ptBase;
	AcGePoint3d pt2 = pt1;
	pt2.x += dTotalWidth;
	for (int i = 0; i < m_arrRowHeight.length()+1; ++ i)
	{
		if (i > 0)
		{
			pt1.y -= m_arrRowHeight.at(i-1);
			pt2.y -= m_arrRowHeight.at(i-1);
		}
		DrawLine(pt1, pt2);
	}

	pt1 = m_ptBase;
	pt2 = pt1;
	pt2.y -= dTotalHeight;
	for (int i = 0; i < m_arrColWidth.length()+1; ++ i)
	{
		if (i > 0)
		{
			pt1.x += m_arrColWidth.at(i-1);
			pt2.x += m_arrColWidth.at(i-1);
		}
		DrawLine(pt1, pt2);
	}
}


void TSheet::InsertText(AcGePoint3d p,CString text,double texthigh,AcDbObjectId layerId,int color,
	AcDb::TextHorzMode hMode,AcDb::TextVertMode vMode,double dAngle)
{
	AcDbText *pText=new AcDbText(p,text);

	pText->setHorizontalMode(hMode);
	pText->setVerticalMode(vMode);

	pText->setNormal(AcGeVector3d::kZAxis);
	pText->setHeight(texthigh);
	pText->setAlignmentPoint(p);
	pText->setRotation(dAngle);
	AcDbExtents extents;
	pText->getGeomExtents(extents);
	AcGePoint3d p1=extents.maxPoint();
	AcGePoint3d p2=extents.minPoint();
	AcGePoint3d ptInset = AcGePoint3d(p.x-fabs(p2.x-p1.x)/2,p.y-fabs(p2.y-p1.y)/2,0);
	pText->setPosition(ptInset);

	if(layerId)
		pText->setLayer(layerId);
	pText->setColorIndex(color);

	m_pBTR->appendAcDbEntity(pText);  
	pText->close();
}

void TSheet::InsertText(int posx,int posy,CString text,double texthigh,AcDbObjectId layerId,int color,
	AcDb::TextHorzMode hMode,AcDb::TextVertMode vMode,double dAngle, int nAlign)
{
	AcGePoint3d pt = m_ptBase;
	for(int i = 0; i < m_arrColWidth.length(); ++i)
	{
		if(i>0)
			pt.x += m_arrColWidth[i-1];
		if(i==posy)
		{
			pt.x += (0 == nAlign ? m_arrColWidth[i]/2 : 1 == nAlign ? 0 : m_arrColWidth[i] - texthigh);
			break;
		}
	}
	for(int i = 0; i < m_arrRowHeight.length(); ++i)
	{
		if(i>0)
			pt.y -= m_arrRowHeight[i-1];
		if(i==posx)
		{
			pt.y -= m_arrRowHeight[i]/2;
			break;
		}
	}

	InsertText(pt,text,texthigh,layerId,color,hMode,vMode,dAngle);
}
