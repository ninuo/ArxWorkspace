#pragma once
#include "acdb.h"
#include "arxHeperDefine.h"

class ARXHELPER_API CArxHelper
{
public:
	CArxHelper(void);
	~CArxHelper(void);

	static int CreateHatch(AcDbHatch*& pHatch, const AcGePoint3dArray& arrPt,double dScale = 0.01);

	static int CreatePLine(AcDbPolyline*& pPolyline, const AcGePoint3dArray& arrPt, double dWith = 0.0, BOOL bClose = TRUE);

	static AcDbObjectId CreatePLine(const AcGePoint3dArray& arrPt, double dWith = 0.0, BOOL bClose = TRUE);

	static AcDbBlockTableRecord* GetBlockTableRecord(AcDbDatabase* pDatabase = acdbCurDwg(), BOOL OpenWrite = TRUE);

	static AcDbObjectId AddToCAD(AcDbEntity *pEntity,int colorIndex = 256,bool bClose = true,AcDbObjectId layerId=NULL);


	static AcDbObjectId CreateBlock(const AcDbVoidPtrArray& arrEnt, const CString& strName);

	static AcDbObjectId InsertBlock(const AcDbObjectId& blockId, const AcGePoint3d& ptInsert, double dAngle);

	static AcDbObjectId GetDimStyleId(const CString& strDimName,double dScale = 100.0);

	static AcDbObjectId GetBlockId(const CString& strName);

	static void SetOneLayer(const TCHAR *name,int flag,bool YN);

	static AcDbObjectId SetLayer(TCHAR* layerName);

	static AcDbObjectId CreateMLeader(const CString& strText, const AcGePoint3d& ptArrow, const AcGePoint3d& ptBase, const AcGeVector3d& vectDir);

	static AcDbObjectId CreateText(const CString& strText, const AcGePoint3d& pt1, const AcGePoint3d& pt2, double dDist, BOOL bUp = TRUE);

	static AcDbSolid* CreateSolid(const AcGePoint3d& ptBase, double dHeight, double dWidth, int nColorIndex);
};
