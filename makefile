#
# A Makefile for WINVER
# (c) osFree project
#

PROJ  = winver1
PROJ1 = winver
TRGT = $(PROJ1).exe
DESC = osFree Janus Version
#defines object file names in format $(p)objname$(e)
srcfiles = $(p)winver$(e) 
# defines additional options for C compiler
ADD_COPT = -sg
HEAPSIZE = 4k

EXPORTS = VersionDlgProc.1

!include $(%ROOT)tools/mk/appsw16.mk

TARGETS = $(PATH)$(PROJ1).exe

.ico: $(MYDIR)res

$(PATH)$(PROJ1).exe: $(PATH)$(PROJ).exe $(MYDIR)rsrc.rc
 @$(SAY) RESCMP   $^. $(LOG)
 @$(RC) -q -30 -bt=windows $]@ $[@ -fe=$@ -fo=$^@ -i=$(MYDIR) -i=$(%WATCOM)$(SEP)h$(SEP)win
