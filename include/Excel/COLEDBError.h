// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// COLEDBError0 ��װ��

class COLEDBError0 : public COleDispatchDriver
{
public:
	COLEDBError0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	COLEDBError0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COLEDBError0(const COLEDBError0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// OLEDBError ����
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
	CString get_SqlState()
	{
		CString result;
		InvokeHelper(0x643, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ErrorString()
	{
		CString result;
		InvokeHelper(0x5d2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_Native()
	{
		long result;
		InvokeHelper(0x769, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Number()
	{
		long result;
		InvokeHelper(0x1c3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Stage()
	{
		long result;
		InvokeHelper(0x76a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// OLEDBError ����
public:

};
