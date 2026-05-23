/*
 * Windows Version Program
 *
 * Copyright 1997 by Marcel Baur (mbaur@g26.ethz.ch)
 * Copyright 2023 by Yuri Prokushev
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "windows.h"
#include "winver.h"

typedef BOOL (WINAPI *SHELLABOUT)(HWND hWnd, LPCSTR lpszCaption, LPCSTR lpszAboutText, HICON hIcon);

int PASCAL WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmdline, int show)
{
	char szTitle[50];
	SHELLABOUT lpShellAbout;
	int retVal=0;

	LoadString(inst, IDS_PACKAGE_NAME, szTitle, sizeof(szTitle));

	//Needed for Win95 and later??
	//InitCommonControls();

	lpShellAbout=(SHELLABOUT)GetProcAddress(GetModuleHandle("shell.dll"), "ShellAbout");

	if (lpShellAbout)
	{
		retVal=!lpShellAbout(0, szTitle, NULL, NULL);
	} else {
		// Most probably, we are in Windows 3.0 or earler, so no ShellAbout
		// Use own dialog, not standard...
	}
	return retVal;
}

