// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CXmlNamespace0 ��װ��

class CXmlNamespace0 : public COleDispatchDriver
{
public:
	CXmlNamespace0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CXmlNamespace0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXmlNamespace0(const CXmlNamespace0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XmlNamespace ����
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
	CString get_Uri()
	{
		CString result;
		InvokeHelper(0x915, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Prefix()
	{
		CString result;
		InvokeHelper(0x916, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// XmlNamespace ����
public:

};
