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

char szVersionBuf[128];

BOOL WINAPI VersionDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
        SetDlgItemText(hDlg, IDC_VERSION_TEXT, szVersionBuf);
        return TRUE;
    case WM_COMMAND:
        EndDialog(hDlg, 1);
        return TRUE;
    }
    return FALSE;
}

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdline, int show)
{
    char szTitle[50];
    DWORD dwVersion, dwFlags;
    WORD  wVersion;
    int   nMajor, nMinor, nDosMajor, nDosMinor;
    LPSTR lpMode  = "";
    LPSTR lpDebug = "";
    char  szFpu[16] = "";
    char  szDosVer[32] = "";
    FARPROC lpfnDlgProc;
    HINSTANCE hShell;
    SHELLABOUT pShellAbout;
    WORD oldErrorMode;
  
    if (hPrevInstance) return 0;

    LoadString(hInstance, IDS_PACKAGE_NAME, szTitle, sizeof(szTitle));

    /* Try shell.dll first (@todo Does'n work under Real Mode Windows 3.0) */
    oldErrorMode = SetErrorMode(SEM_NOOPENFILEERRORBOX);
    hShell = LoadLibrary("SHELL");
    SetErrorMode(oldErrorMode);
    if (hShell>=HINSTANCE_ERROR)
    {
        pShellAbout = (SHELLABOUT)GetProcAddress(hShell, "ShellAbout");
        if (pShellAbout)
        {
            BOOL bRet = pShellAbout(NULL, szTitle, NULL, NULL);
            FreeLibrary(hShell);
            return !bRet;
        }
        FreeLibrary(hShell);
    }

    /* Get version */
    dwVersion = GetVersion();
    wVersion  = LOWORD(dwVersion);
    nMajor    = LOBYTE(wVersion);
    nMinor    = HIBYTE(wVersion);

    /* Get DOS version from high word  */
    nDosMajor = HIBYTE(HIWORD(dwVersion));
    nDosMinor = LOBYTE(HIWORD(dwVersion));

    /* Get winflags */
    dwFlags = GetWinFlags();


    /* set current mode */
    if (dwFlags & WF_PMODE)
    {
        if (dwFlags & WF_STANDARD)
            lpMode = "Standard Mode";
        else
            lpMode = "386 Enhanced Mode";
    }
    else
    {
        if (dwFlags & WF_LARGEFRAME)
            lpMode = "Large Frame EMS";
        else if (dwFlags & WF_SMALLFRAME)
            lpMode = "Small Frame EMS";
        else
            lpMode = "Real Mode";
    }

    /* Debug version */
    if (GetSystemMetrics(SM_DEBUG))
        lpDebug = "DEBUG ";

    /* Check for 80x87 coprocessor */
    if (dwFlags & WF_80x87)
        lstrcpy(szFpu, " [80x87]");

    /* Format DOS version string if available */
    if (nDosMajor > 0 || nDosMinor > 0)
        wsprintf(szDosVer, " (DOS %d.%02d)", nDosMajor, nDosMinor);

    wsprintf(szVersionBuf, "%s osFree Janus %sVersion %d.%02d%s%s",
             lpMode, lpDebug, nMajor, nMinor, (LPSTR)szDosVer, (LPSTR)szFpu);

    lpfnDlgProc = MakeProcInstance((FARPROC)VersionDlgProc, hInstance);
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_VERSION_DLG), NULL, lpfnDlgProc);
    FreeProcInstance(lpfnDlgProc);

    return 1;
}
