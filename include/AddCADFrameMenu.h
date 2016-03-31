#pragma once
#include "arxHeperDefine.h"
#include <afxtempl.h>
#include "acadi.h"

typedef struct CADMenu
{
	TCHAR name[64];
	TCHAR macro[64];
}CADMenu;


class ARXHELPER_API CAddCADFrameMenu  
{
public:
	CAddCADFrameMenu();
	virtual ~CAddCADFrameMenu();

	// 创建菜单
	void CreateMenus();
	// 添加菜单
	void AddMenu(const TCHAR* menuName);
	// 添加子菜单，menuName-菜单名"--"为分隔符,command要加空格
	void AddSubMenu(const TCHAR* menuName, const TCHAR* command=NULL);
	// 添加分隔符
	void AddSeparator();
	// 添加二级子菜单分隔符
	void AddSubSeparator();

	static bool IsMenuExist(IAcadPopupMenu *&pMnu,long &index,const TCHAR *mnuname,IAcadPopupMenus *mnus);//菜单是否存在，避免二次加载 add by zhengzhilin
	static bool GetAcadApplication(IAcadApplication *&pAcadApp);
	static bool GetAcadMenuGroup(IAcadMenuGroup  **pVal,LPCTSTR menuname);
	static bool GetLastMenuFromMenubar(CString &sMenu);
	static void ClearMenu(IAcadPopupMenus *mnus,LPCTSTR menuname);
	static bool GetAcadApplication(LPDISPATCH * pVal);
	static bool GetAcadMenuGroup(IAcadMenuGroup  **pVal);
	static void CleanUpMenus(); //创建了Menu一定要调用这个函数

private:

	class CCADMenuArray : public CArray <CADMenu*, CADMenu*>
	{
	public:
		int AddMenu(CADMenu& menu);
		int AddMenu(const TCHAR* menuName, const TCHAR* command);
		~CCADMenuArray();
	};

	CArray <CCADMenuArray*, CCADMenuArray*> m_menus;
	int m_menuCount;  // 菜单个数

	CStringArray m_TopMenuNames; // 菜单名


};