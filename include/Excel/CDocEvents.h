// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CDocEvents ��װ��

class CDocEvents : public COleDispatchDriver
{
public:
	CDocEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDocEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDocEvents(const CDocEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// DocEvents ����
public:
	void SelectionChange(LPDISPATCH Target)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x607, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target);
	}
	void BeforeDoubleClick(LPDISPATCH Target, BOOL * Cancel)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_PBOOL ;
		InvokeHelper(0x601, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target, Cancel);
	}
	void BeforeRightClick(LPDISPATCH Target, BOOL * Cancel)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_PBOOL ;
		InvokeHelper(0x5fe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target, Cancel);
	}
	void Activate()
	{
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Deactivate()
	{
		InvokeHelper(0x5fa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Calculate()
	{
		InvokeHelper(0x117, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Change(LPDISPATCH Target)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x609, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target);
	}
	void FollowHyperlink(LPDISPATCH Target)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x5be, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target);
	}
	void PivotTableUpdate(LPDISPATCH Target)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x86c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Target);
	}

	// DocEvents ����
public:

};
