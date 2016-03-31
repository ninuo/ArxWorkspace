// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CSpeech ��װ��

class CSpeech : public COleDispatchDriver
{
public:
	CSpeech(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSpeech(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSpeech(const CSpeech& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ISpeech ����
public:
	STDMETHOD(Speak)(LPCTSTR Text, VARIANT SpeakAsync, VARIANT SpeakXML, VARIANT Purge)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x7e1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Text, &SpeakAsync, &SpeakXML, &Purge);
		return result;
	}
	STDMETHOD(get_Direction)(XlSpeakDirection * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa8, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_Direction)(XlSpeakDirection RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa8, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}
	STDMETHOD(get_SpeakCellOnEnter)(BOOL * RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8bb, DISPATCH_PROPERTYGET, VT_HRESULT, (void*)&result, parms, RHS);
		return result;
	}
	STDMETHOD(put_SpeakCellOnEnter)(BOOL RHS)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8bb, DISPATCH_PROPERTYPUT, VT_HRESULT, (void*)&result, parms, newValue);
		return result;
	}

	// ISpeech ����
public:

};
