// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CWebOptions ��װ��

class CWebOptions : public COleDispatchDriver
{
public:
	CWebOptions(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CWebOptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWebOptions(const CWebOptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// WebOptions ����
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
	BOOL get_RelyOnCSS()
	{
		BOOL result;
		InvokeHelper(0x76b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_RelyOnCSS(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x76b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_OrganizeInFolder()
	{
		BOOL result;
		InvokeHelper(0x76e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_OrganizeInFolder(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x76e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UseLongFileNames()
	{
		BOOL result;
		InvokeHelper(0x770, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseLongFileNames(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x770, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_DownloadComponents()
	{
		BOOL result;
		InvokeHelper(0x772, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_DownloadComponents(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x772, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_RelyOnVML()
	{
		BOOL result;
		InvokeHelper(0x773, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_RelyOnVML(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x773, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AllowPNG()
	{
		BOOL result;
		InvokeHelper(0x774, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AllowPNG(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x774, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ScreenSize()
	{
		long result;
		InvokeHelper(0x775, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ScreenSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x775, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PixelsPerInch()
	{
		long result;
		InvokeHelper(0x776, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PixelsPerInch(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x776, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_LocationOfComponents()
	{
		CString result;
		InvokeHelper(0x777, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_LocationOfComponents(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x777, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Encoding()
	{
		long result;
		InvokeHelper(0x71e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Encoding(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x71e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_FolderSuffix()
	{
		CString result;
		InvokeHelper(0x77a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void UseDefaultFolderSuffix()
	{
		InvokeHelper(0x77b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_TargetBrowser()
	{
		long result;
		InvokeHelper(0x883, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TargetBrowser(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x883, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// WebOptions ����
public:

};
