//+-------------------------------------------------------------------------
//
//  dulib - DirectUI Library
//  Copyright (C) BodSoft
//
//  File:       duLayout.h
//
//  History:    JAN-09-2010   Denny Chen  Created
//
//--------------------------------------------------------------------------
#pragma once

#include "duUtility.h"
#include "duPlugin.h"
#include "duTypes.h"

#define LAYOUT_NORMAL				 0 // 不用管理子对象
#define LAYOUT_LEFTTORIGHT			 1 // 将子对象从左到右排列
#define LAYOUT_RIGHTTOLEFT			 2 // 将子对象从右到左排列
#define LAYOUT_TOPTOBOTTOM			 3 // 将子对象从上到下排列
#define LAYOUT_BOTTOMTOTOP			 4 // 将子对象从下到上排列
#define LAYOUT_HORZ_BRIMMING		 5 // 将子对象水平充满 子对象宽度 = Layout宽度 / 子对象数量
#define LAYOUT_VERT_BRIMMING		 6 // 将子对象垂直充满 子对象高度 = Layout高度 / 子对象数量
#define LAYOUT_GRID					 7 // 将子对象换行表格排列


class duLayout : public duPlugin
{
public:
	virtual void WINAPI RegisterControlProperty();
	virtual void WINAPI OnCreate();
	virtual void WINAPI DrawObject(HDC hDC);
	virtual void WINAPI Resize(LPRECT lpRect);
	
	virtual void WINAPI OnChildShow(duPlugin *pChild, BOOL fVisible);
	virtual void WINAPI OnChildResize(duPlugin *pChild);
	virtual LRESULT WINAPI OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual int WINAPI GetLayoutType() { return m_nLayoutType; }
	virtual void WINAPI SetLayoutType(int nLayoutType) { m_nLayoutType = nLayoutType; }

	virtual int WINAPI GetStartX() { return m_nStartX; }
	virtual void WINAPI SetStartX(int nStartX) { m_nStartX = nStartX; }

	virtual int WINAPI GetStartY() { return m_nStartY; }
	virtual void WINAPI SetStartY(int nStartY) { m_nStartY = nStartY; }

	virtual int WINAPI GetXSpace() { return m_nXSpace; }
	virtual void WINAPI SetXSpace(int nXSpace) { m_nXSpace = nXSpace; }

	virtual int  WINAPI GetYSpace() { return m_nYSpace; }
	virtual void WINAPI SetYSpace(int nYSpace) { m_nYSpace = nYSpace; }

	virtual void WINAPI AdjustChilds();

	virtual BOOL WINAPI IsAlwaysHot() { return m_fAlwaysHot; }
	virtual void WINAPI SetAlwaysHot(BOOL fAlwaysHot);

	virtual void WINAPI FinalRelease() { delete this; }
	virtual LPCTSTR WINAPI GetTypeInfoName() { return _T("duLayout"); }	

public:
	duLayout();
	~duLayout();
	
public:
	void WINAPI AdjustLeftRight();
	void WINAPI AdjustRightLeft();
	void WINAPI AdjustTopBottom();
	void WINAPI AdjustBottomTop();
	void WINAPI AdjustHorzBrimming();
	void WINAPI AdjustVertBrimming();
	void WINAPI AdjustGrid();

protected:
	UINT m_nLayoutType;
	int m_nStartX;
	int m_nStartY;
	int m_nXSpace;
	int m_nYSpace;
	BOOL m_fAlwaysHot;
};

duPlugin *WINAPI GetPreVisible(duPlugin *pPlugin);
duPlugin *WINAPI GetNextVisible(duPlugin *pPlugin);
int WINAPI GetVisibleChildCount(duPlugin *pPlugin);
