#
# A Makefile for ANSI
# (c) osFree project,
# author, date
#

PROJ = winver
TRGT = $(PROJ).exe
DESC = Windows Version
#defines object file names in format objname.$(O)
srcfiles = $(p)winver$(e)
# defines additional options for C compiler
ADD_COPT = -zW
IMPORTS  = SHELLABOUT SHELL.22

!include $(%ROOT)tools/mk/appsw16.mk
