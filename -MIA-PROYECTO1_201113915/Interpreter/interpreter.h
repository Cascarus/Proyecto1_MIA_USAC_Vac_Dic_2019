#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <Interpreter/nt_cat.h>
#include <Interpreter/nt_chgrp.h>
#include <Interpreter/nt_chmod.h>
#include <Interpreter/nt_chown.h>
#include <Interpreter/nt_cp.h>
#include <Interpreter/nt_edit.h>
#include <Interpreter/nt_exec.h>
#include <Interpreter/nt_fdisk.h>
#include <Interpreter/nt_find.h>
#include <Interpreter/nt_login.h>
#include <Interpreter/nt_logout.h>
#include <Interpreter/nt_loss.h>
#include <Interpreter/nt_mkdir.h>
#include <Interpreter/nt_mkdisk.h>
#include <Interpreter/nt_mkfile.h>
#include <Interpreter/nt_mkfs.h>
#include <Interpreter/nt_mkgrp.h>
#include <Interpreter/nt_mkusr.h>
#include <Interpreter/nt_mount.h>
#include <Interpreter/nt_mv.h>
#include <Interpreter/nt_pause.h>
#include <Interpreter/nt_recovery.h>
#include <Interpreter/nt_rm.h>
#include <Interpreter/nt_ren.h>
#include <Interpreter/nt_rep.h>
#include <Interpreter/nt_rmdisk.h>
#include <Interpreter/nt_rmgrp.h>
#include <Interpreter/nt_rmusr.h>
#include <Interpreter/nt_unmount.h>

class Interpreter
{
public:
    Interpreter();
    void tourAST(NodeAST *root);

    NT_Cat *cat = new NT_Cat();
    NT_Chgrp *chgrp = new NT_Chgrp();
    NT_Chmod *chmod = new NT_Chmod();
    NT_Chown *chown = new NT_Chown();
    NT_Cp *cp = new NT_Cp();
    NT_Edit *edit = new NT_Edit();
    NT_Exec *exec = new NT_Exec();
    NT_Fdisk *fdisk = new NT_Fdisk();
    NT_Find *find = new NT_Find();
    NT_Login *login = new NT_Login();
    NT_Logout *logout = new NT_Logout();
    NT_Loss *loss = new NT_Loss();
    NT_Mkdir *mkdir = new NT_Mkdir();
    NT_Mkdisk *mkdisk = new NT_Mkdisk();
    NT_Mkfile *mkfile = new NT_Mkfile();
    NT_Mkfs *mkfs = new NT_Mkfs();
    NT_Mkgrp *mkgrp = new NT_Mkgrp();
    NT_Mkusr *mkusr = new NT_Mkusr();
    NT_Mount *mount = new NT_Mount();
    NT_Mv *mv = new NT_Mv();
    NT_Pause *pause = new NT_Pause();
    NT_Recovery *recovery = new NT_Recovery();
    NT_Rm *rm = new NT_Rm();
    NT_Ren *ren = new NT_Ren();
    NT_Rep *rep = new NT_Rep();
    NT_Rmdisk *rmdisk = new NT_Rmdisk();
    NT_Rmgrp *rmgrp = new NT_Rmgrp();
    NT_Rmusr *rmusr = new NT_Rmusr();
    NT_Unmount *unmount = new NT_Unmount();

};

#endif // INTERPRETER_H
