// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CRTDUpdateEvent ��װ��

class CRTDUpdateEvent : public COleDispatchDriver
{
public:
	CRTDUpdateEvent(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CRTDUpdateEvent(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRTDUpdateEvent(const CRTDUpdateEvent& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRTDUpdateEvent ����
public:
	void UpdateNotify()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_HeartbeatInterval()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_HeartbeatInterval(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void Disconnect()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IRTDUpdateEvent ����
public:

};
