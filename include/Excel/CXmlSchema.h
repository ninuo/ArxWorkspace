// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CXmlSchema0 ��װ��

class CXmlSchema0 : public COleDispatchDriver
{
public:
	CXmlSchema0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CXmlSchema0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXmlSchema0(const CXmlSchema0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XmlSchema ����
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
	LPDISPATCH get_Namespace()
	{
		LPDISPATCH result;
		InvokeHelper(0x91c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_XML()
	{
		CString result;
		InvokeHelper(0x91d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// XmlSchema ����
public:

};
