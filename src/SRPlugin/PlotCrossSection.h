#pragma once
class PlotCrossSection
{
public:
	PlotCrossSection(void);
	~PlotCrossSection(void);

	BOOL createModel();

protected:
	BOOL getBlockId(AcDbObjectId& blockId);
};

