// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CSeriesCollection0 ��װ��

class CSeriesCollection0 : public COleDispatchDriver
{
public:
	CSeriesCollection0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSeriesCollection0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSeriesCollection0(const CSeriesCollection0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// SeriesCollection ����
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
	LPDISPATCH Add(VARIANT Source, long Rowcol, VARIANT SeriesLabels, VARIANT CategoryLabels, VARIANT Replace)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Source, Rowcol, &SeriesLabels, &CategoryLabels, &Replace);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT Extend(VARIANT Source, VARIANT Rowcol, VARIANT CategoryLabels)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Source, &Rowcol, &CategoryLabels);
		return result;
	}
	LPDISPATCH Item(VARIANT Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN _NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	VARIANT Paste(long Rowcol, VARIANT SeriesLabels, VARIANT CategoryLabels, VARIANT Replace, VARIANT NewSeries)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Rowcol, &SeriesLabels, &CategoryLabels, &Replace, &NewSeries);
		return result;
	}
	LPDISPATCH NewSeries()
	{
		LPDISPATCH result;
		InvokeHelper(0x45d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// SeriesCollection ����
public:

};
