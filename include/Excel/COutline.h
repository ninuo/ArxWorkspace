// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// COutline0 ��װ��

class COutline0 : public COleDispatchDriver
{
public:
	COutline0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	COutline0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COutline0(const COutline0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Outline ����
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
	BOOL get_AutomaticStyles()
	{
		BOOL result;
		InvokeHelper(0x3bf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutomaticStyles(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x3bf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT ShowLevels(VARIANT RowLevels, VARIANT ColumnLevels)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &RowLevels, &ColumnLevels);
		return result;
	}
	long get_SummaryColumn()
	{
		long result;
		InvokeHelper(0x3c1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_SummaryColumn(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3c1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_SummaryRow()
	{
		long result;
		InvokeHelper(0x386, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_SummaryRow(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x386, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// Outline ����
public:

};
