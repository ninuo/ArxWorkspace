// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CPublishObjects0 ��װ��

class CPublishObjects0 : public COleDispatchDriver
{
public:
	CPublishObjects0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CPublishObjects0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPublishObjects0(const CPublishObjects0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// PublishObjects ����
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
	LPDISPATCH Add(long SourceType, LPCTSTR Filename, VARIANT Sheet, VARIANT Source, VARIANT HtmlType, VARIANT DivID, VARIANT Title)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, SourceType, Filename, &Sheet, &Source, &HtmlType, &DivID, &Title);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(VARIANT Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xaa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPDISPATCH get__Default(VARIANT Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void Delete()
	{
		InvokeHelper(0x75, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Publish()
	{
		InvokeHelper(0x767, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// PublishObjects ����
public:

};
