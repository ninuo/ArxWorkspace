// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CSmartTagOptions0 ��װ��

class CSmartTagOptions0 : public COleDispatchDriver
{
public:
	CSmartTagOptions0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSmartTagOptions0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSmartTagOptions0(const CSmartTagOptions0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// SmartTagOptions ����
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
	long get_DisplaySmartTags()
	{
		long result;
		InvokeHelper(0x8aa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DisplaySmartTags(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8aa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_EmbedSmartTags()
	{
		BOOL result;
		InvokeHelper(0x8ab, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_EmbedSmartTags(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8ab, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// SmartTagOptions ����
public:

};
