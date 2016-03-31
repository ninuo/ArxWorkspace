#pragma once

class PlotSection
{
public:
	PlotSection(void);
	~PlotSection(void);

	double getRatioBase() const { return m_dRatioBase; }
	void setRatioBase(double val) { m_dRatioBase = val; }
	
	double getRatioReal() const { return m_dRatioReal; }
	void setRatioReal(double val) { m_dRatioReal = val; }

	double getStateWidth() const { return m_dStateWidth; }
	void setStateWidth(double val) { m_dStateWidth = val; }

	double getStateHeight() const { return m_dStateHeight; }
	void setStateHeight(double val) { m_dStateHeight = val; }

	double getStateInnerSlope() const { return m_dStateInnerSlope; }
	void setStateInnerSlope(double val) { m_dStateInnerSlope = val; }

	double getStateOutterSlope() const { return m_dStateOutterSlope; }
	void setStateOutterSlope(double val) { m_dStateOutterSlope = val; }

	double getDesignWidth() const { return m_dDesignWidth; }
	void setDesignWidth(double val) { m_dDesignWidth = val; }

	double getDesignHeight() const { return m_dDesignHeight; }
	void setDesignHeight(double val) { m_dDesignHeight = val; }

	double getDesignInnerSlope() const { return m_dDesignInnerSlope; }
	void setDesignInnerSlope(double val) { m_dDesignInnerSlope = val; }

	double getDesignOutterSlope() const { return m_dDesignOutterSlope; }
	void setDesignOutterSlope(double val) { m_dDesignOutterSlope = val; }

	double getLiningThick() const { return m_dLiningThick; }
	void setLiningThick(double val) { m_dLiningThick = val; }

	double getTopDiff() const { return m_dTopDiff; }
	void setTopDiff(double val) { m_dTopDiff = val; }	
	
	CString getName() const { return m_strName; }
	void setName(CString val) { m_strName = val; }

	AcGePoint3d getInsert() const { return m_ptInsert; }
	void setInsert(AcGePoint3d val) { m_ptInsert = val; }

	BOOL CreateModel();

protected:
	BOOL CreateStateModel();
	BOOL InitData();
	BOOL CreateDesignModel();
	AcDbObjectId CreateGrass();
	AcDbObjectId CreateLeftBlock();
	AcDbObjectId CreateRightBlock();
	BOOL CreateDim();
	BOOL CreateLeftBlockDim();
	BOOL CreateRightBlockDim();
	BOOL CreateDesignDim();

	BOOL CreateAnnotation();
	BOOL CreateWaterLevelMark(const AcGePoint3d& pt, const CString& strName);
private:
	double m_dRatioBase;
	double m_dRatioReal;
	double m_dStateWidth;
	double m_dStateHeight;
	double m_dStateInnerSlope;
	double m_dStateOutterSlope;
	double m_dDesignWidth;
	double m_dDesignHeight;
	double m_dDesignInnerSlope;
	double m_dDesignOutterSlope;
	double m_dLiningThick;
	double m_dTopDiff;

	double m_dInnerGrassLength;

	double m_dGrassInterval;

	CString m_strName;
	//
	double m_dInnerLiningWidth;

	AcGePoint3d m_ptInsert;
	double m_dScale;
	double m_dInterval;

	//草
	int m_nGrassNum;

	//左块数据
	double m_dLeftBlockTopWidth;
	double m_dLeftBlockBottomWidth;
	double m_dLeftBlockHeight;

	//右块数据
	double m_dBlockFilterBedWidth;
	double m_dBlockFilterBedHeight;
	double m_dBlockDragFeetWidth;
	double m_dBlockDrainWidth;
	double m_dBlockDrainHeight;
	double m_dBlockDrainThick;

	//
	AcGePoint3d m_ptInnerStateBottom;
	AcGePoint3d m_ptInnerDesignBottom;
	AcGePoint3d m_ptOutterStateBottom;
	AcGePoint3d m_ptOutterDesignBottom;

	//标注
	AcDbObjectId m_DimStyleId;

	//添加标注
	AcGePoint3d m_ptLeftBlockInsert;
	AcGePoint3d m_ptRightBlockInsert;
	AcGePoint3d m_ptInnerGrassBottom;
	AcGePoint3d m_ptInnerStateTop;
	AcGePoint3d m_ptInnerDesignTop;
	AcGePoint3d m_ptOutterStateTop;
	AcGePoint3d m_ptOutterDesignTop;
};
