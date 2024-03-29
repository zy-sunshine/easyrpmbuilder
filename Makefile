#############################################################################
# Makefile for building: bin/easyrpmbuilder
# Generated by qmake (2.01a) (Qt 4.6.0) on: ?? 2? 2 15:37:05 2010
# Project:  easyrpmbuilder.pro
# Template: app
# Command: /usr/lib/qt4/bin/qmake -unix -o Makefile easyrpmbuilder.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib/qt4/mkspecs/linux-g++ -I. -I/usr/lib/qt4/include/QtCore -I/usr/lib/qt4/include/QtGui -I/usr/lib/qt4/include -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/lib/qt4/lib
LIBS          = $(SUBLIBS)  -L/usr/lib/qt4/lib -lQtGui -L/usr/lib/qt4/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/easyrpmmainwindowimpl.cpp \
		src/main.cpp \
		src/settings.cpp \
		src/templateeditor.cpp \
		src/documentviewer.cpp \
		src/logview.cpp \
		src/sectionedit.cpp \
		src/changelogdialog.cpp \
		src/sourceeditdialog.cpp \
		src/patcheditdialog.cpp \
		src/editspecialoptions.cpp \
		src/highlighter.cpp \
		src/showmacros.cpp \
		src/macroviewcontainer.cpp \
		src/editprivatemacrofile.cpp \
		src/execscriptdialog.cpp \
		src/packageresultdialog.cpp \
		src/configtoolbardialog.cpp \
		src/editDesktopFile.cpp \
		src/desktopFileEditor.cpp build/moc_easyrpmmainwindowimpl.cpp \
		build/moc_settings.cpp \
		build/moc_templateeditor.cpp \
		build/moc_documentviewer.cpp \
		build/moc_logview.cpp \
		build/moc_changelogdialog.cpp \
		build/moc_sectionedit.cpp \
		build/moc_sourceeditdialog.cpp \
		build/moc_patcheditdialog.cpp \
		build/moc_editspecialoptions.cpp \
		build/moc_highlighter.cpp \
		build/moc_showmacros.cpp \
		build/moc_macroviewcontainer.cpp \
		build/moc_editprivatemacrofile.cpp \
		build/moc_execscriptdialog.cpp \
		build/moc_packageresultdialog.cpp \
		build/moc_configtoolbardialog.cpp \
		build/moc_editDesktopFile.cpp \
		build/moc_desktopFileEditor.cpp \
		qrc_icons.cpp
OBJECTS       = build/easyrpmmainwindowimpl.o \
		build/main.o \
		build/settings.o \
		build/templateeditor.o \
		build/documentviewer.o \
		build/logview.o \
		build/sectionedit.o \
		build/changelogdialog.o \
		build/sourceeditdialog.o \
		build/patcheditdialog.o \
		build/editspecialoptions.o \
		build/highlighter.o \
		build/showmacros.o \
		build/macroviewcontainer.o \
		build/editprivatemacrofile.o \
		build/execscriptdialog.o \
		build/packageresultdialog.o \
		build/configtoolbardialog.o \
		build/editDesktopFile.o \
		build/desktopFileEditor.o \
		build/moc_easyrpmmainwindowimpl.o \
		build/moc_settings.o \
		build/moc_templateeditor.o \
		build/moc_documentviewer.o \
		build/moc_logview.o \
		build/moc_changelogdialog.o \
		build/moc_sectionedit.o \
		build/moc_sourceeditdialog.o \
		build/moc_patcheditdialog.o \
		build/moc_editspecialoptions.o \
		build/moc_highlighter.o \
		build/moc_showmacros.o \
		build/moc_macroviewcontainer.o \
		build/moc_editprivatemacrofile.o \
		build/moc_execscriptdialog.o \
		build/moc_packageresultdialog.o \
		build/moc_configtoolbardialog.o \
		build/moc_editDesktopFile.o \
		build/moc_desktopFileEditor.o \
		build/qrc_icons.o
DIST          = /usr/lib/qt4/mkspecs/common/g++.conf \
		/usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		/usr/lib/qt4/mkspecs/features/yacc.prf \
		/usr/lib/qt4/mkspecs/features/lex.prf \
		easyrpmbuilder.pro
QMAKE_TARGET  = easyrpmbuilder
DESTDIR       = bin/
TARGET        = bin/easyrpmbuilder

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_easyrpmMainwindow.h build/ui_settings.h build/ui_templateeditor.h build/ui_documentViewer.h build/ui_logview.h build/ui_sectionedit.h build/ui_changelogDialog.h build/ui_sourceEditDialog.h build/ui_patchEditDialog.h build/ui_specialOptionDialog.h build/ui_showMacrosDialog.h build/ui_macroViewContainer.h build/ui_editPrivateMacroFileDialog.h build/ui_execScriptDialog.h build/ui_packageResultDialog.h build/ui_configToolBarDialog.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: easyrpmbuilder.pro  /usr/lib/qt4/mkspecs/linux-g++/qmake.conf /usr/lib/qt4/mkspecs/common/g++.conf \
		/usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		/usr/lib/qt4/mkspecs/features/yacc.prf \
		/usr/lib/qt4/mkspecs/features/lex.prf \
		/usr/lib/qt4/lib/libQtGui.prl \
		/usr/lib/qt4/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile easyrpmbuilder.pro
/usr/lib/qt4/mkspecs/common/g++.conf:
/usr/lib/qt4/mkspecs/common/unix.conf:
/usr/lib/qt4/mkspecs/common/linux.conf:
/usr/lib/qt4/mkspecs/qconfig.pri:
/usr/lib/qt4/mkspecs/features/qt_functions.prf:
/usr/lib/qt4/mkspecs/features/qt_config.prf:
/usr/lib/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt4/mkspecs/features/default_pre.prf:
/usr/lib/qt4/mkspecs/features/release.prf:
/usr/lib/qt4/mkspecs/features/default_post.prf:
/usr/lib/qt4/mkspecs/features/warn_on.prf:
/usr/lib/qt4/mkspecs/features/qt.prf:
/usr/lib/qt4/mkspecs/features/unix/thread.prf:
/usr/lib/qt4/mkspecs/features/moc.prf:
/usr/lib/qt4/mkspecs/features/resources.prf:
/usr/lib/qt4/mkspecs/features/uic.prf:
/usr/lib/qt4/mkspecs/features/yacc.prf:
/usr/lib/qt4/mkspecs/features/lex.prf:
/usr/lib/qt4/lib/libQtGui.prl:
/usr/lib/qt4/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile easyrpmbuilder.pro

dist: 
	@$(CHK_DIR_EXISTS) build/easyrpmbuilder1.0.0 || $(MKDIR) build/easyrpmbuilder1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/easyrpmbuilder1.0.0/ && $(COPY_FILE) --parents src/easyrpmmainwindowimpl.h src/settings.h src/templateeditor.h src/documentviewer.h src/logview.h src/changelogdialog.h src/sectionedit.h src/sourceeditdialog.h src/patcheditdialog.h src/editspecialoptions.h src/highlighter.h src/showmacros.h src/macroviewcontainer.h src/editprivatemacrofile.h src/execscriptdialog.h src/packageresultdialog.h src/configtoolbardialog.h src/editDesktopFile.h src/desktopFileEditor.h build/easyrpmbuilder1.0.0/ && $(COPY_FILE) --parents src/icons.qrc build/easyrpmbuilder1.0.0/ && $(COPY_FILE) --parents src/easyrpmmainwindowimpl.cpp src/main.cpp src/settings.cpp src/templateeditor.cpp src/documentviewer.cpp src/logview.cpp src/sectionedit.cpp src/changelogdialog.cpp src/sourceeditdialog.cpp src/patcheditdialog.cpp src/editspecialoptions.cpp src/highlighter.cpp src/showmacros.cpp src/macroviewcontainer.cpp src/editprivatemacrofile.cpp src/execscriptdialog.cpp src/packageresultdialog.cpp src/configtoolbardialog.cpp src/editDesktopFile.cpp src/desktopFileEditor.cpp build/easyrpmbuilder1.0.0/ && $(COPY_FILE) --parents ui/easyrpmMainwindow.ui ui/settings.ui ui/templateeditor.ui ui/documentViewer.ui ui/logview.ui ui/sectionedit.ui ui/changelogDialog.ui ui/sourceEditDialog.ui ui/patchEditDialog.ui ui/specialOptionDialog.ui ui/showMacrosDialog.ui ui/macroViewContainer.ui ui/editPrivateMacroFileDialog.ui ui/execScriptDialog.ui ui/packageResultDialog.ui ui/configToolBarDialog.ui build/easyrpmbuilder1.0.0/ && $(COPY_FILE) --parents src/translations/german.ts src/translations/english.ts src/translations/spanish.ts src/translations/brazilian.ts src/translations/italian.ts build/easyrpmbuilder1.0.0/ && (cd `dirname build/easyrpmbuilder1.0.0` && $(TAR) easyrpmbuilder1.0.0.tar easyrpmbuilder1.0.0 && $(COMPRESS) easyrpmbuilder1.0.0.tar) && $(MOVE) `dirname build/easyrpmbuilder1.0.0`/easyrpmbuilder1.0.0.tar.gz . && $(DEL_FILE) -r build/easyrpmbuilder1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_easyrpmmainwindowimpl.cpp build/moc_settings.cpp build/moc_templateeditor.cpp build/moc_documentviewer.cpp build/moc_logview.cpp build/moc_changelogdialog.cpp build/moc_sectionedit.cpp build/moc_sourceeditdialog.cpp build/moc_patcheditdialog.cpp build/moc_editspecialoptions.cpp build/moc_highlighter.cpp build/moc_showmacros.cpp build/moc_macroviewcontainer.cpp build/moc_editprivatemacrofile.cpp build/moc_execscriptdialog.cpp build/moc_packageresultdialog.cpp build/moc_configtoolbardialog.cpp build/moc_editDesktopFile.cpp build/moc_desktopFileEditor.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_easyrpmmainwindowimpl.cpp build/moc_settings.cpp build/moc_templateeditor.cpp build/moc_documentviewer.cpp build/moc_logview.cpp build/moc_changelogdialog.cpp build/moc_sectionedit.cpp build/moc_sourceeditdialog.cpp build/moc_patcheditdialog.cpp build/moc_editspecialoptions.cpp build/moc_highlighter.cpp build/moc_showmacros.cpp build/moc_macroviewcontainer.cpp build/moc_editprivatemacrofile.cpp build/moc_execscriptdialog.cpp build/moc_packageresultdialog.cpp build/moc_configtoolbardialog.cpp build/moc_editDesktopFile.cpp build/moc_desktopFileEditor.cpp
build/moc_easyrpmmainwindowimpl.cpp: build/ui_easyrpmMainwindow.h \
		src/settings.h \
		build/ui_settings.h \
		src/templateeditor.h \
		build/ui_templateeditor.h \
		src/documentviewer.h \
		src/logview.h \
		build/ui_logview.h \
		src/sectionedit.h \
		build/ui_sectionedit.h \
		src/highlighter.h \
		src/changelogdialog.h \
		build/ui_changelogDialog.h \
		src/sourceeditdialog.h \
		build/ui_sourceEditDialog.h \
		src/patcheditdialog.h \
		build/ui_patchEditDialog.h \
		src/editspecialoptions.h \
		build/ui_specialOptionDialog.h \
		src/macroviewcontainer.h \
		build/ui_macroViewContainer.h \
		src/showmacros.h \
		build/ui_showMacrosDialog.h \
		src/editprivatemacrofile.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/editDesktopFile.h \
		src/desktopFileEditor.h \
		src/execscriptdialog.h \
		build/ui_execScriptDialog.h \
		src/packageresultdialog.h \
		build/ui_packageResultDialog.h \
		src/configtoolbardialog.h \
		build/ui_configToolBarDialog.h \
		src/easyrpmmainwindowimpl.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/easyrpmmainwindowimpl.h -o build/moc_easyrpmmainwindowimpl.cpp

build/moc_settings.cpp: build/ui_settings.h \
		src/settings.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/settings.h -o build/moc_settings.cpp

build/moc_templateeditor.cpp: build/ui_templateeditor.h \
		src/templateeditor.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/templateeditor.h -o build/moc_templateeditor.cpp

build/moc_documentviewer.cpp: src/documentviewer.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/documentviewer.h -o build/moc_documentviewer.cpp

build/moc_logview.cpp: build/ui_logview.h \
		src/logview.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/logview.h -o build/moc_logview.cpp

build/moc_changelogdialog.cpp: build/ui_changelogDialog.h \
		src/changelogdialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/changelogdialog.h -o build/moc_changelogdialog.cpp

build/moc_sectionedit.cpp: build/ui_sectionedit.h \
		src/highlighter.h \
		src/sectionedit.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/sectionedit.h -o build/moc_sectionedit.cpp

build/moc_sourceeditdialog.cpp: build/ui_sourceEditDialog.h \
		src/sourceeditdialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/sourceeditdialog.h -o build/moc_sourceeditdialog.cpp

build/moc_patcheditdialog.cpp: build/ui_patchEditDialog.h \
		src/patcheditdialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/patcheditdialog.h -o build/moc_patcheditdialog.cpp

build/moc_editspecialoptions.cpp: build/ui_specialOptionDialog.h \
		src/editspecialoptions.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/editspecialoptions.h -o build/moc_editspecialoptions.cpp

build/moc_highlighter.cpp: src/highlighter.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/highlighter.h -o build/moc_highlighter.cpp

build/moc_showmacros.cpp: src/highlighter.h \
		build/ui_showMacrosDialog.h \
		src/showmacros.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/showmacros.h -o build/moc_showmacros.cpp

build/moc_macroviewcontainer.cpp: build/ui_macroViewContainer.h \
		src/showmacros.h \
		src/highlighter.h \
		build/ui_showMacrosDialog.h \
		src/editprivatemacrofile.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/macroviewcontainer.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/macroviewcontainer.h -o build/moc_macroviewcontainer.cpp

build/moc_editprivatemacrofile.cpp: src/highlighter.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/editprivatemacrofile.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/editprivatemacrofile.h -o build/moc_editprivatemacrofile.cpp

build/moc_execscriptdialog.cpp: build/ui_execScriptDialog.h \
		src/highlighter.h \
		src/execscriptdialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/execscriptdialog.h -o build/moc_execscriptdialog.cpp

build/moc_packageresultdialog.cpp: build/ui_packageResultDialog.h \
		src/packageresultdialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/packageresultdialog.h -o build/moc_packageresultdialog.cpp

build/moc_configtoolbardialog.cpp: build/ui_configToolBarDialog.h \
		src/configtoolbardialog.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/configtoolbardialog.h -o build/moc_configtoolbardialog.cpp

build/moc_editDesktopFile.cpp: build/ui_macroViewContainer.h \
		src/showmacros.h \
		src/highlighter.h \
		build/ui_showMacrosDialog.h \
		src/desktopFileEditor.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/editDesktopFile.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/editDesktopFile.h -o build/moc_editDesktopFile.cpp

build/moc_desktopFileEditor.cpp: src/highlighter.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/desktopFileEditor.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/desktopFileEditor.h -o build/moc_desktopFileEditor.cpp

compiler_rcc_make_all: qrc_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_icons.cpp
qrc_icons.cpp: src/icons.qrc \
		src/icons/open.png \
		src/icons/help.png \
		src/icons/print.png \
		src/icons/add.png \
		src/icons/binary.png \
		src/icons/rpm.png \
		src/icons/logview.png \
		src/icons/source.png \
		src/icons/obsolete.png \
		src/icons/conflicts.png \
		src/icons/logo.png \
		src/icons/forward.png \
		src/icons/gohome.png \
		src/icons/saveas.png \
		src/icons/save.png \
		src/icons/settings.png \
		src/icons/rebuild.png \
		src/icons/qt.png \
		src/icons/configure.png \
		src/icons/skull.png \
		src/icons/new.png \
		src/icons/both.png \
		src/icons/provides.png \
		src/icons/del.png \
		src/icons/require.png \
		src/icons/editsources.png \
		src/icons/editpatches.png \
		src/icons/exit.png \
		src/icons/showmacros.png \
		src/icons/configtoolbar.png \
		src/icons/back.png
	/usr/lib/qt4/bin/rcc -name icons src/icons.qrc -o qrc_icons.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_easyrpmMainwindow.h build/ui_settings.h build/ui_templateeditor.h build/ui_documentViewer.h build/ui_logview.h build/ui_sectionedit.h build/ui_changelogDialog.h build/ui_sourceEditDialog.h build/ui_patchEditDialog.h build/ui_specialOptionDialog.h build/ui_showMacrosDialog.h build/ui_macroViewContainer.h build/ui_editPrivateMacroFileDialog.h build/ui_execScriptDialog.h build/ui_packageResultDialog.h build/ui_configToolBarDialog.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_easyrpmMainwindow.h build/ui_settings.h build/ui_templateeditor.h build/ui_documentViewer.h build/ui_logview.h build/ui_sectionedit.h build/ui_changelogDialog.h build/ui_sourceEditDialog.h build/ui_patchEditDialog.h build/ui_specialOptionDialog.h build/ui_showMacrosDialog.h build/ui_macroViewContainer.h build/ui_editPrivateMacroFileDialog.h build/ui_execScriptDialog.h build/ui_packageResultDialog.h build/ui_configToolBarDialog.h
build/ui_easyrpmMainwindow.h: ui/easyrpmMainwindow.ui
	/usr/lib/qt4/bin/uic ui/easyrpmMainwindow.ui -o build/ui_easyrpmMainwindow.h

build/ui_settings.h: ui/settings.ui
	/usr/lib/qt4/bin/uic ui/settings.ui -o build/ui_settings.h

build/ui_templateeditor.h: ui/templateeditor.ui
	/usr/lib/qt4/bin/uic ui/templateeditor.ui -o build/ui_templateeditor.h

build/ui_documentViewer.h: ui/documentViewer.ui
	/usr/lib/qt4/bin/uic ui/documentViewer.ui -o build/ui_documentViewer.h

build/ui_logview.h: ui/logview.ui
	/usr/lib/qt4/bin/uic ui/logview.ui -o build/ui_logview.h

build/ui_sectionedit.h: ui/sectionedit.ui
	/usr/lib/qt4/bin/uic ui/sectionedit.ui -o build/ui_sectionedit.h

build/ui_changelogDialog.h: ui/changelogDialog.ui
	/usr/lib/qt4/bin/uic ui/changelogDialog.ui -o build/ui_changelogDialog.h

build/ui_sourceEditDialog.h: ui/sourceEditDialog.ui
	/usr/lib/qt4/bin/uic ui/sourceEditDialog.ui -o build/ui_sourceEditDialog.h

build/ui_patchEditDialog.h: ui/patchEditDialog.ui
	/usr/lib/qt4/bin/uic ui/patchEditDialog.ui -o build/ui_patchEditDialog.h

build/ui_specialOptionDialog.h: ui/specialOptionDialog.ui
	/usr/lib/qt4/bin/uic ui/specialOptionDialog.ui -o build/ui_specialOptionDialog.h

build/ui_showMacrosDialog.h: ui/showMacrosDialog.ui
	/usr/lib/qt4/bin/uic ui/showMacrosDialog.ui -o build/ui_showMacrosDialog.h

build/ui_macroViewContainer.h: ui/macroViewContainer.ui
	/usr/lib/qt4/bin/uic ui/macroViewContainer.ui -o build/ui_macroViewContainer.h

build/ui_editPrivateMacroFileDialog.h: ui/editPrivateMacroFileDialog.ui
	/usr/lib/qt4/bin/uic ui/editPrivateMacroFileDialog.ui -o build/ui_editPrivateMacroFileDialog.h

build/ui_execScriptDialog.h: ui/execScriptDialog.ui
	/usr/lib/qt4/bin/uic ui/execScriptDialog.ui -o build/ui_execScriptDialog.h

build/ui_packageResultDialog.h: ui/packageResultDialog.ui
	/usr/lib/qt4/bin/uic ui/packageResultDialog.ui -o build/ui_packageResultDialog.h

build/ui_configToolBarDialog.h: ui/configToolBarDialog.ui
	/usr/lib/qt4/bin/uic ui/configToolBarDialog.ui -o build/ui_configToolBarDialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/easyrpmmainwindowimpl.o: src/easyrpmmainwindowimpl.cpp src/easyrpmmainwindowimpl.h \
		build/ui_easyrpmMainwindow.h \
		src/settings.h \
		build/ui_settings.h \
		src/templateeditor.h \
		build/ui_templateeditor.h \
		src/documentviewer.h \
		src/logview.h \
		build/ui_logview.h \
		src/sectionedit.h \
		build/ui_sectionedit.h \
		src/highlighter.h \
		src/changelogdialog.h \
		build/ui_changelogDialog.h \
		src/sourceeditdialog.h \
		build/ui_sourceEditDialog.h \
		src/patcheditdialog.h \
		build/ui_patchEditDialog.h \
		src/editspecialoptions.h \
		build/ui_specialOptionDialog.h \
		src/macroviewcontainer.h \
		build/ui_macroViewContainer.h \
		src/showmacros.h \
		build/ui_showMacrosDialog.h \
		src/editprivatemacrofile.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/editDesktopFile.h \
		src/desktopFileEditor.h \
		src/execscriptdialog.h \
		build/ui_execScriptDialog.h \
		src/packageresultdialog.h \
		build/ui_packageResultDialog.h \
		src/configtoolbardialog.h \
		build/ui_configToolBarDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/easyrpmmainwindowimpl.o src/easyrpmmainwindowimpl.cpp

build/main.o: src/main.cpp src/easyrpmmainwindowimpl.h \
		build/ui_easyrpmMainwindow.h \
		src/settings.h \
		build/ui_settings.h \
		src/templateeditor.h \
		build/ui_templateeditor.h \
		src/documentviewer.h \
		src/logview.h \
		build/ui_logview.h \
		src/sectionedit.h \
		build/ui_sectionedit.h \
		src/highlighter.h \
		src/changelogdialog.h \
		build/ui_changelogDialog.h \
		src/sourceeditdialog.h \
		build/ui_sourceEditDialog.h \
		src/patcheditdialog.h \
		build/ui_patchEditDialog.h \
		src/editspecialoptions.h \
		build/ui_specialOptionDialog.h \
		src/macroviewcontainer.h \
		build/ui_macroViewContainer.h \
		src/showmacros.h \
		build/ui_showMacrosDialog.h \
		src/editprivatemacrofile.h \
		build/ui_editPrivateMacroFileDialog.h \
		src/editDesktopFile.h \
		src/desktopFileEditor.h \
		src/execscriptdialog.h \
		build/ui_execScriptDialog.h \
		src/packageresultdialog.h \
		build/ui_packageResultDialog.h \
		src/configtoolbardialog.h \
		build/ui_configToolBarDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/settings.o: src/settings.cpp src/settings.h \
		build/ui_settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/settings.o src/settings.cpp

build/templateeditor.o: src/templateeditor.cpp src/templateeditor.h \
		build/ui_templateeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/templateeditor.o src/templateeditor.cpp

build/documentviewer.o: src/documentviewer.cpp src/documentviewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/documentviewer.o src/documentviewer.cpp

build/logview.o: src/logview.cpp src/logview.h \
		build/ui_logview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/logview.o src/logview.cpp

build/sectionedit.o: src/sectionedit.cpp src/sectionedit.h \
		build/ui_sectionedit.h \
		src/highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sectionedit.o src/sectionedit.cpp

build/changelogdialog.o: src/changelogdialog.cpp src/changelogdialog.h \
		build/ui_changelogDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/changelogdialog.o src/changelogdialog.cpp

build/sourceeditdialog.o: src/sourceeditdialog.cpp src/sourceeditdialog.h \
		build/ui_sourceEditDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sourceeditdialog.o src/sourceeditdialog.cpp

build/patcheditdialog.o: src/patcheditdialog.cpp src/patcheditdialog.h \
		build/ui_patchEditDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/patcheditdialog.o src/patcheditdialog.cpp

build/editspecialoptions.o: src/editspecialoptions.cpp src/editspecialoptions.h \
		build/ui_specialOptionDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/editspecialoptions.o src/editspecialoptions.cpp

build/highlighter.o: src/highlighter.cpp src/highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/highlighter.o src/highlighter.cpp

build/showmacros.o: src/showmacros.cpp src/showmacros.h \
		src/highlighter.h \
		build/ui_showMacrosDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/showmacros.o src/showmacros.cpp

build/macroviewcontainer.o: src/macroviewcontainer.cpp src/macroviewcontainer.h \
		build/ui_macroViewContainer.h \
		src/showmacros.h \
		src/highlighter.h \
		build/ui_showMacrosDialog.h \
		src/editprivatemacrofile.h \
		build/ui_editPrivateMacroFileDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/macroviewcontainer.o src/macroviewcontainer.cpp

build/editprivatemacrofile.o: src/editprivatemacrofile.cpp src/editprivatemacrofile.h \
		src/highlighter.h \
		build/ui_editPrivateMacroFileDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/editprivatemacrofile.o src/editprivatemacrofile.cpp

build/execscriptdialog.o: src/execscriptdialog.cpp src/execscriptdialog.h \
		build/ui_execScriptDialog.h \
		src/highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/execscriptdialog.o src/execscriptdialog.cpp

build/packageresultdialog.o: src/packageresultdialog.cpp src/packageresultdialog.h \
		build/ui_packageResultDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/packageresultdialog.o src/packageresultdialog.cpp

build/configtoolbardialog.o: src/configtoolbardialog.cpp src/configtoolbardialog.h \
		build/ui_configToolBarDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/configtoolbardialog.o src/configtoolbardialog.cpp

build/editDesktopFile.o: src/editDesktopFile.cpp src/editDesktopFile.h \
		build/ui_macroViewContainer.h \
		src/showmacros.h \
		src/highlighter.h \
		build/ui_showMacrosDialog.h \
		src/desktopFileEditor.h \
		build/ui_editPrivateMacroFileDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/editDesktopFile.o src/editDesktopFile.cpp

build/desktopFileEditor.o: src/desktopFileEditor.cpp src/desktopFileEditor.h \
		src/highlighter.h \
		build/ui_editPrivateMacroFileDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/desktopFileEditor.o src/desktopFileEditor.cpp

build/moc_easyrpmmainwindowimpl.o: build/moc_easyrpmmainwindowimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_easyrpmmainwindowimpl.o build/moc_easyrpmmainwindowimpl.cpp

build/moc_settings.o: build/moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_settings.o build/moc_settings.cpp

build/moc_templateeditor.o: build/moc_templateeditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_templateeditor.o build/moc_templateeditor.cpp

build/moc_documentviewer.o: build/moc_documentviewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_documentviewer.o build/moc_documentviewer.cpp

build/moc_logview.o: build/moc_logview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_logview.o build/moc_logview.cpp

build/moc_changelogdialog.o: build/moc_changelogdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_changelogdialog.o build/moc_changelogdialog.cpp

build/moc_sectionedit.o: build/moc_sectionedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_sectionedit.o build/moc_sectionedit.cpp

build/moc_sourceeditdialog.o: build/moc_sourceeditdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_sourceeditdialog.o build/moc_sourceeditdialog.cpp

build/moc_patcheditdialog.o: build/moc_patcheditdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_patcheditdialog.o build/moc_patcheditdialog.cpp

build/moc_editspecialoptions.o: build/moc_editspecialoptions.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_editspecialoptions.o build/moc_editspecialoptions.cpp

build/moc_highlighter.o: build/moc_highlighter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_highlighter.o build/moc_highlighter.cpp

build/moc_showmacros.o: build/moc_showmacros.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_showmacros.o build/moc_showmacros.cpp

build/moc_macroviewcontainer.o: build/moc_macroviewcontainer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_macroviewcontainer.o build/moc_macroviewcontainer.cpp

build/moc_editprivatemacrofile.o: build/moc_editprivatemacrofile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_editprivatemacrofile.o build/moc_editprivatemacrofile.cpp

build/moc_execscriptdialog.o: build/moc_execscriptdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_execscriptdialog.o build/moc_execscriptdialog.cpp

build/moc_packageresultdialog.o: build/moc_packageresultdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_packageresultdialog.o build/moc_packageresultdialog.cpp

build/moc_configtoolbardialog.o: build/moc_configtoolbardialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_configtoolbardialog.o build/moc_configtoolbardialog.cpp

build/moc_editDesktopFile.o: build/moc_editDesktopFile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_editDesktopFile.o build/moc_editDesktopFile.cpp

build/moc_desktopFileEditor.o: build/moc_desktopFileEditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_desktopFileEditor.o build/moc_desktopFileEditor.cpp

build/qrc_icons.o: qrc_icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_icons.o qrc_icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

