// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CSmartTagRecognizer0 ��װ��

class CSmartTagRecognizer0 : public COleDispatchDriver
{
public:
	CSmartTagRecognizer0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSmartTagRecognizer0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSmartTagRecognizer0(const CSmartTagRecognizer0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// SmartTagRecognizer ����
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
	BOOL get_Enabled()
	{
		BOOL result;
		InvokeHelper(0x258, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Enabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x258, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_progID()
	{
		CString result;
		InvokeHelper(0x8a8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get__Default()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_FullName()
	{
		CString result;
		InvokeHelper(0x121, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// SmartTagRecognizer ����
public:

};
