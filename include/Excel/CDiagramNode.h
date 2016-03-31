// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

// CDiagramNode ��װ��

class CDiagramNode : public COleDispatchDriver
{
public:
	CDiagramNode(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDiagramNode(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDiagramNode(const CDiagramNode& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// DiagramNode ����
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH AddNode(long pos, long nodeType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, pos, nodeType);
		return result;
	}
	void Delete()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void MoveNode(LPDISPATCH pTargetNode, long pos)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pTargetNode, pos);
	}
	void ReplaceNode(LPDISPATCH pTargetNode)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pTargetNode);
	}
	void SwapNode(LPDISPATCH pTargetNode, BOOL swapChildren)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pTargetNode, swapChildren);
	}
	LPDISPATCH CloneNode(BOOL copyChildren, LPDISPATCH pTargetNode, long pos)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BOOL VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, copyChildren, pTargetNode, pos);
		return result;
	}
	void TransferChildren(LPDISPATCH pReceivingNode)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pReceivingNode);
	}
	LPDISPATCH NextNode()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH PrevNode()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Children()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Shape()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Root()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Diagram()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Layout()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Layout(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_TextShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// DiagramNode ����
public:

};
