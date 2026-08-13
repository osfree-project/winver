#
# A Makefile for osFree Janus Version
# (c) osFree project
#

DESC = osFree Janus Version
TARGET_API = WIN
ADD_COPT = -sg

EXPORTS = VersionDlgProc.1

!include $(%ROOT)tools/mk/build.mk

