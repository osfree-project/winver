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


BOOL WINAPI ShellAbout(HWND hWnd, LPCSTR lpszCaption, LPCSTR lpszAboutText,
                HICON hIcon);

int PASCAL WinMain (HINSTANCE inst, HINSTANCE prev, LPSTR cmdline, int show)
{
   char szTitle[50];
//   const char * (CDECL *wine_get_version)(void);
//   const DWORD (WINAPI *GetProcAddress32W)( DWORD hModule, LPCSTR lpszProc );
//   LoadLibraryEx32W

   LoadString(inst, IDS_PACKAGE_NAME, szTitle, 50);

//   wine_get_version = (void *)GetProcAddress32W(GetModuleHandle("ntdll.dll"), "wine_get_version");
//   if (wine_get_version) lstrcat( szTitle, wine_get_version() );

   return !ShellAbout(0, szTitle, NULL, NULL);
}

