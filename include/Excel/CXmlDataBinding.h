// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CXmlDataBinding0 ��װ��

class CXmlDataBinding0 : public COleDispatchDriver
{
public:
	CXmlDataBinding0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CXmlDataBinding0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXmlDataBinding0(const CXmlDataBinding0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XmlDataBinding ����
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
	long Refresh()
	{
		long result;
		InvokeHelper(0x589, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void LoadSettings(LPCTSTR Url)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x919, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Url);
	}
	void ClearSettings()
	{
		InvokeHelper(0x91a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	CString get_SourceUrl()
	{
		CString result;
		InvokeHelper(0x91b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// XmlDataBinding ����
public:

};
