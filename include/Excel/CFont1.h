// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CFont1 ��װ��

class CFont1 : public COleDispatchDriver
{
public:
	CFont1(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFont1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFont1(const CFont1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFont ����
public:
	STDMETHOD(get_Application)(Application * * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(get_Creator)(XlCreator * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(get_Parent)(LPDISPATCH * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(get_Background)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xb4, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Background)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb4, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Bold)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x60, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Bold)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Color)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Color)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_ColorIndex)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x61, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_ColorIndex)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x61, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_FontStyle)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xb1, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_FontStyle)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb1, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Italic)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Italic)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Name)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Name)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_OutlineFont)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xdd, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_OutlineFont)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xdd, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Shadow)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Shadow)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Size)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Size)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Strikethrough)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Strikethrough)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Subscript)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xb3, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Subscript)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb3, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Superscript)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xb2, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Superscript)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb2, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}
	STDMETHOD(get_Underline)(VARIANT * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Underline)(VARIANT RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, &newValue);
		return result;
	}

	// IFont ����
public:

};
