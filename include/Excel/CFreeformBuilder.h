// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CFreeformBuilder ��װ��

class CFreeformBuilder : public COleDispatchDriver
{
public:
	CFreeformBuilder(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFreeformBuilder(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFreeformBuilder(const CFreeformBuilder& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// FreeformBuilder ����
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
	void AddNodes(long SegmentType, long EditingType, float X1, float Y1, VARIANT X2, VARIANT Y2, VARIANT X3, VARIANT Y3)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6e2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SegmentType, EditingType, X1, Y1, &X2, &Y2, &X3, &Y3);
	}
	LPDISPATCH ConvertToShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x6e6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// FreeformBuilder ����
public:

};
