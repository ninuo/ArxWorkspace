// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CRTD ��װ��

class CRTD : public COleDispatchDriver
{
public:
	CRTD(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CRTD(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRTD(const CRTD& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRTD ����
public:
	STDMETHOD(get_ThrottleInterval)(long * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8c0, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_ThrottleInterval)(long RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8c0, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(RefreshData)()
	{
		HRESULT result;
		InvokeHelper(0x8c1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(RestartServers)()
	{
		HRESULT result;
		InvokeHelper(0x8c2, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// IRTD ����
public:

};
