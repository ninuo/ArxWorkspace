// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CListDataFormat0 ��װ��

class CListDataFormat0 : public COleDispatchDriver
{
public:
	CListDataFormat0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CListDataFormat0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CListDataFormat0(const CListDataFormat0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ListDataFormat ����
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
	long get__Default()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Choices()
	{
		VARIANT result;
		InvokeHelper(0x92c, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long get_DecimalPlaces()
	{
		long result;
		InvokeHelper(0x92d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_DefaultValue()
	{
		VARIANT result;
		InvokeHelper(0x92e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsPercent()
	{
		BOOL result;
		InvokeHelper(0x92f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_lcid()
	{
		long result;
		InvokeHelper(0x930, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_MaxCharacters()
	{
		long result;
		InvokeHelper(0x931, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_MaxNumber()
	{
		VARIANT result;
		InvokeHelper(0x932, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT get_MinNumber()
	{
		VARIANT result;
		InvokeHelper(0x933, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	BOOL get_Required()
	{
		BOOL result;
		InvokeHelper(0x934, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Type()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL get_ReadOnly()
	{
		BOOL result;
		InvokeHelper(0x128, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_AllowFillIn()
	{
		BOOL result;
		InvokeHelper(0x935, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	// ListDataFormat ����
public:

};
