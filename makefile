# SPDX-License-Identifier: LGPL-2.1-or-later
#
# A Makefile for osFree Janus Version
# Copyright 2026 (c) osFree project
#

DESCRIPTION    = Janus Version
TARGET_PACKAGE = DISK02
LICENSE        = LGPL-2.1-or-later
LICENSE_CHECK  = 1
EXPORTS        = VersionDlgProc.1

!include $(%ROOT)tools/mk/build.mk

