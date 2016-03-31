// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

// CDummy 包装类

class CDummy : public COleDispatchDriver
{
public:
	CDummy(){} // 调用 COleDispatchDriver 默认构造函数
	CDummy(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDummy(const CDummy& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 属性
public:

	// 操作
public:


	// IDummy 方法
public:
	STDMETHOD(_ActiveSheetOrChart)()
	{
		HRESULT result;
		InvokeHelper(0x644, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(RGB)()
	{
		HRESULT result;
		InvokeHelper(0x41f, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(ChDir)()
	{
		HRESULT result;
		InvokeHelper(0x420, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(DoScript)()
	{
		HRESULT result;
		InvokeHelper(0x475, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(DirectObject)()
	{
		HRESULT result;
		InvokeHelper(0x473, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(RefreshDocument)()
	{
		HRESULT result;
		InvokeHelper(0x758, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// IDummy 属性
public:

};
