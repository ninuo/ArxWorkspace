// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CAutoFilter ��װ��

class CAutoFilter : public COleDispatchDriver
{
public:
	CAutoFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CAutoFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAutoFilter(const CAutoFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// AutoFilter ����
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
	LPDISPATCH get_Range()
	{
		LPDISPATCH result;
		InvokeHelper(0xc5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Filters()
	{
		LPDISPATCH result;
		InvokeHelper(0x651, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// AutoFilter ����
public:

};
