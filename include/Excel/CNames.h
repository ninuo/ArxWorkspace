// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CNames0 ��װ��

class CNames0 : public COleDispatchDriver
{
public:
	CNames0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CNames0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CNames0(const CNames0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Names ����
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
	LPDISPATCH Add(VARIANT Name, VARIANT RefersTo, VARIANT Visible, VARIANT MacroType, VARIANT ShortcutKey, VARIANT Category, VARIANT NameLocal, VARIANT RefersToLocal, VARIANT CategoryLocal, VARIANT RefersToR1C1, VARIANT RefersToR1C1Local)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Name, &RefersTo, &Visible, &MacroType, &ShortcutKey, &Category, &NameLocal, &RefersToLocal, &CategoryLocal, &RefersToR1C1, &RefersToR1C1Local);
		return result;
	}
	LPDISPATCH Item(VARIANT Index, VARIANT IndexLocal, VARIANT RefersTo)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index, &IndexLocal, &RefersTo);
		return result;
	}
	LPDISPATCH _Default(VARIANT Index, VARIANT IndexLocal, VARIANT RefersTo)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index, &IndexLocal, &RefersTo);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	// Names ����
public:

};
