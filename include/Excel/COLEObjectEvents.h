// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// COLEObjectEvents ��װ��

class COLEObjectEvents : public COleDispatchDriver
{
public:
	COLEObjectEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	COLEObjectEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COLEObjectEvents(const COLEObjectEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IOLEObjectEvents ����
public:
	STDMETHOD(GotFocus)()
	{
		HRESULT result;
		InvokeHelper(0x605, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(LostFocus)()
	{
		HRESULT result;
		InvokeHelper(0x606, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// IOLEObjectEvents ����
public:

};
