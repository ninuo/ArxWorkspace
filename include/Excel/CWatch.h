// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CWatch0 ��װ��

class CWatch0 : public COleDispatchDriver
{
public:
	CWatch0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CWatch0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWatch0(const CWatch0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Watch ����
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
	void Delete()
	{
		InvokeHelper(0x75, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	VARIANT get_Source()
	{
		VARIANT result;
		InvokeHelper(0xde, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	// Watch ����
public:

};
