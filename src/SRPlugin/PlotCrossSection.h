#pragma once
#include <vector>
class PlotCrossSection
{
public:
	PlotCrossSection(void);
	~PlotCrossSection(void);

	struct ChannelData
	{
		int m_nNo;
		CString m_strName;
		double m_dIrrigatedArea;
		double m_dLength;
		double m_dVerticalSlope;
		double m_dLeftSlope;
		double m_dRightSlope;
		double m_dDesignFlow;
		double m_dEnhanceFlow;
		double m_dDesignWidth;
		double m_dHeight;
		double m_dDesignHeight;
		double m_dEnhanceHeight;
		double m_dLiningHeight;
		double m_dLiningThickness;
		CString m_strStartPileNo;
		CString m_strEndPileNo;
		double m_dTop;
		double m_dEnhance;
		double m_dDesign;
		double m_dBottom;
	};
	void appendData(const ChannelData& data);
	BOOL createModel();

protected:
	BOOL getBlockId(AcDbObjectId& blockId, const CString& strBlockName);
	BOOL insertBlockReference(const AcDbObjectId& blockId);
private:
	std::vector<ChannelData> m_arrChannelData;
	double m_dScale;
};

