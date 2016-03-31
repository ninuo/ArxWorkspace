// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CSpellingOptions ��װ��

class CSpellingOptions : public COleDispatchDriver
{
public:
	CSpellingOptions(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSpellingOptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSpellingOptions(const CSpellingOptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ISpellingOptions ����
public:
	STDMETHOD(get_DictLang)(long * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8ac, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_DictLang)(long RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8ac, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_UserDict)(BSTR * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x8ad, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_UserDict)(LPCTSTR RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8ad, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_IgnoreCaps)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8ae, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_IgnoreCaps)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8ae, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_SuggestMainOnly)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8af, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_SuggestMainOnly)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8af, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_IgnoreMixedDigits)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b0, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_IgnoreMixedDigits)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b0, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_IgnoreFileNames)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b1, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_IgnoreFileNames)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b1, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_GermanPostReform)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b2, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_GermanPostReform)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b2, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_KoreanCombineAux)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b3, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_KoreanCombineAux)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b3, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_KoreanUseAutoChangeList)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b4, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_KoreanUseAutoChangeList)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b4, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_KoreanProcessCompound)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8b5, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_KoreanProcessCompound)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b5, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_HebrewModes)(XlHebrewModes * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8b6, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_HebrewModes)(XlHebrewModes RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8b6, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_ArabicModes)(XlArabicModes * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8b7, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_ArabicModes)(XlArabicModes RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8b7, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}

	// ISpellingOptions ����
public:

};
