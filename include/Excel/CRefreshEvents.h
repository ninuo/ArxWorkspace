// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CRefreshEvents ��װ��

class CRefreshEvents : public COleDispatchDriver
{
public:
	CRefreshEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CRefreshEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRefreshEvents(const CRefreshEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRefreshEvents ����
public:
	STDMETHOD(BeforeRefresh)(BOOL * Cancel)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x63c, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Cancel);
		return result;
	}
	STDMETHOD(AfterRefresh)(BOOL Success)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x63d, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Success);
		return result;
	}

	// IRefreshEvents ����
public:

};
