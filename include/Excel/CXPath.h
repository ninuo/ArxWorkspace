// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CXPath0 ��װ��

class CXPath0 : public COleDispatchDriver
{
public:
	CXPath0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CXPath0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXPath0(const CXPath0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XPath ����
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
	CString get__Default()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Value()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Map()
	{
		LPDISPATCH result;
		InvokeHelper(0x8d6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void SetValue(LPDISPATCH Map, LPCTSTR XPath, VARIANT SelectionNamespace, VARIANT Repeating)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BSTR VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x936, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Map, XPath, &SelectionNamespace, &Repeating);
	}
	void Clear()
	{
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_Repeating()
	{
		BOOL result;
		InvokeHelper(0x938, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	// XPath ����
public:

};
