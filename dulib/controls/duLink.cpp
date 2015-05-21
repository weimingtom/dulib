//+-------------------------------------------------------------------------
//
//  dulib - DirectUI Library
//  Copyright (C) BodSoft
//
//  File:       duLink.cpp
//
//  History:    Dec-18-2010   Tony Chen  Created
//
//--------------------------------------------------------------------------

#include "stdafx.h"
#include "duLink.h"

duLink::duLink()
{
	ZeroMemory(m_szURL, sizeof(TCHAR) * MAX_URL_LENGTH);
}

duLink::~duLink()
{
}

void WINAPI duLink::RegisterControlProperty()
{
	RegisterProperty(_T("url"), DU_PROPERTY_STRING, &m_szURL);
}

void WINAPI duLink::DrawObject(HDC hDC)
{
	duRect rcButton;
	Plugin_GetRect(this, &rcButton);
	rcButton.OffsetRect(-rcButton.left, -rcButton.top);

	duStyleGroup *pStyleGroup = (duStyleGroup *)GetResObj(GetStyle(), DU_RES_STYLEGROUP);
	if (pStyleGroup)
		pStyleGroup->Draw(hDC, &rcButton, GetState(), GetText(), GetAlpha());
}

void WINAPI duLink::OnMouseIn(POINT pt)
{
	Plugin_SetState(this, DU_STATE_OVER);
	Plugin_Redraw(this, TRUE);
}

void WINAPI duLink::OnMouseLeave(POINT pt)
{
	Plugin_SetState(this, DU_STATE_NORMAL);
	Plugin_Redraw(this, TRUE);
}

void WINAPI duLink::OnMouseLDown(POINT pt)
{
	Plugin_SetState(this, DU_STATE_PRESS);
	Plugin_Redraw(this, TRUE);
}

void WINAPI duLink::OnMouseLUp(POINT pt)
{
	UINT uState = GetState();

	Plugin_SetState(this, DU_STATE_OVER);
	Plugin_Redraw(this, TRUE);

	if (uState == DU_STATE_PRESS)
	{
        ShellExecute(NULL, _T("open"), m_szURL, NULL, NULL, SW_SHOW);
		NotifyUser(DUM_LKCLICK, NULL, NULL);
	}
}

LPCTSTR WINAPI duLink::GetURL()
{
	return m_szURL;
}

void WINAPI duLink::SetURL(LPCTSTR lpszURL)
{
	if(lpszURL)
		_tcsncpy(m_szURL, lpszURL, MAX_URL_LENGTH);
}

void WINAPI duLink::OpenURL()
{
     ShellExecute(NULL, _T("open"), m_szURL, NULL, NULL, SW_SHOW);
}
