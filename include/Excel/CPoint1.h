// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CPoint1 ��װ��

class CPoint1 : public COleDispatchDriver
{
public:
	CPoint1(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CPoint1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPoint1(const CPoint1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Point ����
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT _ApplyDataLabels(long Type, VARIANT LegendKey, VARIANT AutoText, VARIANT HasLeaderLines)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Type, &LegendKey, &AutoText, &HasLeaderLines);
		return result;
	}
	LPDISPATCH get_Border()
	{
		LPDISPATCH result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT ClearFormats()
	{
		VARIANT result;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Copy()
	{
		VARIANT result;
		InvokeHelper(0x227, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_DataLabel()
	{
		LPDISPATCH result;
		InvokeHelper(0x9e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT Delete()
	{
		VARIANT result;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long get_Explosion()
	{
		long result;
		InvokeHelper(0xb6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Explosion(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_HasDataLabel()
	{
		BOOL result;
		InvokeHelper(0x4d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_HasDataLabel(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x4d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Interior()
	{
		LPDISPATCH result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_InvertIfNegative()
	{
		BOOL result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_InvertIfNegative(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerBackgroundColor()
	{
		long result;
		InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerBackgroundColor(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerBackgroundColorIndex()
	{
		long result;
		InvokeHelper(0x4a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerBackgroundColorIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerForegroundColor()
	{
		long result;
		InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerForegroundColor(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerForegroundColorIndex()
	{
		long result;
		InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerForegroundColorIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerSize()
	{
		long result;
		InvokeHelper(0xe7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkerStyle()
	{
		long result;
		InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkerStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT Paste()
	{
		VARIANT result;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long get_PictureType()
	{
		long result;
		InvokeHelper(0xa1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PictureType(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PictureUnit()
	{
		long result;
		InvokeHelper(0xa2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PictureUnit(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT Select()
	{
		VARIANT result;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	BOOL get_ApplyPictToSides()
	{
		BOOL result;
		InvokeHelper(0x67b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ApplyPictToSides(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x67b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_ApplyPictToFront()
	{
		BOOL result;
		InvokeHelper(0x67c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ApplyPictToFront(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x67c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_ApplyPictToEnd()
	{
		BOOL result;
		InvokeHelper(0x67d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ApplyPictToEnd(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x67d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Shadow()
	{
		BOOL result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Shadow(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_SecondaryPlot()
	{
		BOOL result;
		InvokeHelper(0x67e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_SecondaryPlot(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x67e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Fill()
	{
		LPDISPATCH result;
		InvokeHelper(0x67f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT ApplyDataLabels(long Type, VARIANT LegendKey, VARIANT AutoText, VARIANT HasLeaderLines, VARIANT ShowSeriesName, VARIANT ShowCategoryName, VARIANT ShowValue, VARIANT ShowPercentage, VARIANT ShowBubbleSize, VARIANT Separator)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x782, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Type, &LegendKey, &AutoText, &HasLeaderLines, &ShowSeriesName, &ShowCategoryName, &ShowValue, &ShowPercentage, &ShowBubbleSize, &Separator);
		return result;
	}

	// Point ����
public:

};
