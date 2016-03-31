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

	// �����˵�
	void CreateMenus();
	// ��Ӳ˵�
	void AddMenu(const TCHAR* menuName);
	// ����Ӳ˵���menuName-�˵���"--"Ϊ�ָ���,commandҪ�ӿո�
	void AddSubMenu(const TCHAR* menuName, const TCHAR* command=NULL);
	// ��ӷָ���
	void AddSeparator();
	// ��Ӷ����Ӳ˵��ָ���
	void AddSubSeparator();

	static bool IsMenuExist(IAcadPopupMenu *&pMnu,long &index,const TCHAR *mnuname,IAcadPopupMenus *mnus);//�˵��Ƿ���ڣ�������μ��� add by zhengzhilin
	static bool GetAcadApplication(IAcadApplication *&pAcadApp);
	static bool GetAcadMenuGroup(IAcadMenuGroup  **pVal,LPCTSTR menuname);
	static bool GetLastMenuFromMenubar(CString &sMenu);
	static void ClearMenu(IAcadPopupMenus *mnus,LPCTSTR menuname);
	static bool GetAcadApplication(LPDISPATCH * pVal);
	static bool GetAcadMenuGroup(IAcadMenuGroup  **pVal);
	static void CleanUpMenus(); //������Menuһ��Ҫ�����������

private:

	class CCADMenuArray : public CArray <CADMenu*, CADMenu*>
	{
	public:
		int AddMenu(CADMenu& menu);
		int AddMenu(const TCHAR* menuName, const TCHAR* command);
		~CCADMenuArray();
	};

	CArray <CCADMenuArray*, CCADMenuArray*> m_menus;
	int m_menuCount;  // �˵�����

	CStringArray m_TopMenuNames; // �˵���


};