// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CDummy ��װ��

class CDummy : public COleDispatchDriver
{
public:
	CDummy(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDummy(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDummy(const CDummy& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IDummy ����
public:
	STDMETHOD(_ActiveSheetOrChart)()
	{
		HRESULT result;
		InvokeHelper(0x644, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(RGB)()
	{
		HRESULT result;
		InvokeHelper(0x41f, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(ChDir)()
	{
		HRESULT result;
		InvokeHelper(0x420, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(DoScript)()
	{
		HRESULT result;
		InvokeHelper(0x475, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(DirectObject)()
	{
		HRESULT result;
		InvokeHelper(0x473, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(RefreshDocument)()
	{
		HRESULT result;
		InvokeHelper(0x758, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// IDummy ����
public:

};
