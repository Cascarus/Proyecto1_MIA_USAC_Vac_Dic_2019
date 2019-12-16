QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Bison/parser.cpp \
        Bison/scanner.cpp \
        IOConsole/ioconsole.cpp \
        Interpreter/interpreter.cpp \
        Interpreter/nt_cat.cpp \
        Interpreter/nt_chgrp.cpp \
        Interpreter/nt_chmod.cpp \
        Interpreter/nt_chown.cpp \
        Interpreter/nt_cp.cpp \
        Interpreter/nt_edit.cpp \
        Interpreter/nt_exec.cpp \
        Interpreter/nt_fdisk.cpp \
        Interpreter/nt_find.cpp \
        Interpreter/nt_login.cpp \
        Interpreter/nt_logout.cpp \
        Interpreter/nt_loss.cpp \
        Interpreter/nt_mkdir.cpp \
        Interpreter/nt_mkdisk.cpp \
        Interpreter/nt_mkfile.cpp \
        Interpreter/nt_mkfs.cpp \
        Interpreter/nt_mkgrp.cpp \
        Interpreter/nt_mkusr.cpp \
        Interpreter/nt_mount.cpp \
        Interpreter/nt_mv.cpp \
        Interpreter/nt_pause.cpp \
        Interpreter/nt_recovery.cpp \
        Interpreter/nt_ren.cpp \
        Interpreter/nt_rep.cpp \
        Interpreter/nt_rm.cpp \
        Interpreter/nt_rmdisk.cpp \
        Interpreter/nt_rmgrp.cpp \
        Interpreter/nt_rmusr.cpp \
        Interpreter/nt_unmount.cpp \
        NodeAST/nodeast.cpp \
        Plotter/plotter.cpp \
        main.cpp \
        procedures.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Bison/compilar.sh \
    Bison/parser.output\
    Bison/parser.yy \
    Bison/scanner.l
HEADERS += \
    Bison/parser.h \
    Bison/scanner.h \
    IOConsole/ioconsole.h \
    Interpreter/interpreter.h \
    Interpreter/nt_cat.h \
    Interpreter/nt_chgrp.h \
    Interpreter/nt_chmod.h \
    Interpreter/nt_chown.h \
    Interpreter/nt_cp.h \
    Interpreter/nt_edit.h \
    Interpreter/nt_exec.h \
    Interpreter/nt_fdisk.h \
    Interpreter/nt_find.h \
    Interpreter/nt_login.h \
    Interpreter/nt_logout.h \
    Interpreter/nt_loss.h \
    Interpreter/nt_mkdir.h \
    Interpreter/nt_mkdisk.h \
    Interpreter/nt_mkfile.h \
    Interpreter/nt_mkfs.h \
    Interpreter/nt_mkgrp.h \
    Interpreter/nt_mkusr.h \
    Interpreter/nt_mount.h \
    Interpreter/nt_mv.h \
    Interpreter/nt_pause.h \
    Interpreter/nt_recovery.h \
    Interpreter/nt_ren.h \
    Interpreter/nt_rep.h \
    Interpreter/nt_rm.h \
    Interpreter/nt_rmdisk.h \
    Interpreter/nt_rmgrp.h \
    Interpreter/nt_rmusr.h \
    Interpreter/nt_unmount.h \
    NodeAST/nodeast.h \
    Plotter/plotter.h \
    procedures.h \
    structs.h
