#pragma once
#include <vector>
class PlotVerticalSection
{
public:
	PlotVerticalSection(void);
	~PlotVerticalSection(void);

	struct AltitudeData
	{
		CString m_strPileName;
		double m_dSlope;
		double m_dStateBottomAltitude;
		double m_dDesignBottomAltitude;
		double m_dDesignWaterAltitude;
		double m_dEnhanceWaterAltitude;
		double m_dDesignTopAltitude;
	};

	struct AltitudePlot
	{
		CString m_strName;
		int m_nColorIndex;
		AcGePoint3dArray m_arrPts;
	};

	void appendData(const AltitudeData& data);
	double getMaxAltitude() const { return m_dMaxAltitude; }
	void setMaxAltitude(double val) { m_dMaxAltitude = val; }
	double getMinAltitude() const { return m_dMinAltitude; }
	void setMinAltitude(double val) { m_dMinAltitude = val; }
	BOOL createModel();

protected:
	BOOL createPaperFrame(AcGePoint3d& ptInnerLB, AcGePoint3d& ptInnerRB, const AcGePoint3d& ptBase);
	double getPileDist(const CString& strName);
	void getCurrentPaperInfo(double& dSum, AcGeDoubleArray& arrWidth, int nIndex);
	void createLayers();
	void createMarkLine(const AcGePoint3d& ptMark, BOOL bLeft );
	void initData();
private:
	std::vector<AltitudeData> m_arrData;
	double m_dMaxAltitude;
	double m_dMinAltitude;

	CStringArray m_arrSheetTitle;

	double m_dScale;
	CString m_strPaperName;
	AcDbBlockTableRecord* m_pBTR;
	CPaperFrame m_paperFrame;
	double m_dPaperValidLength;
	double m_dIntervalPaper;
	AcDbObjectId m_layerTabId;

	double m_dDigitHeight;
	double m_dChineseTextHeight;

	std::vector<AltitudePlot> m_arrAltitudePlot;
};

