#
# A Makefile for osFree Janus Version
# (c) osFree project
#

DESCRIPTION = Janus Version
LICENSE = LGPL-2.1-or-later
EXCLUDE_LICENSE=README.md

EXPORTS = VersionDlgProc.1

!include $(%ROOT)tools/mk/build.mk

