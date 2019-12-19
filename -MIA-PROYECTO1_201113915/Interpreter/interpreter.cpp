#include "interpreter.h"

Interpreter::Interpreter()
{

}

void Interpreter::tourAST(NodeAST *root)
{
    switch (root->type_)
    {
    case NTINSTRUCTIONS:
    {
        for (int i=0;i<root->childs.size();i++)
        {
            NodeAST node = root->childs.at(i).childs.at(0);
            tourAST(&node);
        }
    }
        break;

    case NTCAT:      { NodeAST node = root->childs.at(0); cat->tourAST(&node, root->command);      } break;
    case NTCHGRP:    { NodeAST node = root->childs.at(0); chgrp->tourAST(&node, root->command);    } break;
    case NTCHMOD:    { NodeAST node = root->childs.at(0); chmod->tourAST(&node, root->command);    } break;
    case NTCHOWN:    { NodeAST node = root->childs.at(0); chown->tourAST(&node, root->command);    } break;
    case NTCP:       { NodeAST node = root->childs.at(0); cp->tourAST(&node, root->command);       } break;
    case NTEDIT:     { NodeAST node = root->childs.at(0); edit->tourAST(&node, root->command);     } break;
    case NTEXEC:     { NodeAST node = root->childs.at(0); exec->tourAST(&node, root->command);     } break;
    case NTFDISK:    { NodeAST node = root->childs.at(0); fdisk->tourAST(&node, root->command);    } break;
    case NTFIND:     { NodeAST node = root->childs.at(0); find->tourAST(&node, root->command);     } break;
    case NTLOGIN:    { NodeAST node = root->childs.at(0); login->tourAST(&node, root->command);    } break;
    case NTLOGOUT:   { logout->execute(root->command);                                           } break;
    case NTLOSS:     { NodeAST node = root->childs.at(0); loss->tourAST(&node, root->command);     } break;
    case NTMKDIR:    { NodeAST node = root->childs.at(0); mkdir->tourAST(&node, root->command);    } break;
    case NTMKDISK:   { NodeAST node = root->childs.at(0); mkdisk->tourAST(&node, root->command);   } break;
    case NTMKFILE:   { NodeAST node = root->childs.at(0); mkfile->tourAST(&node, root->command);   } break;
    case NTMKFS:     { NodeAST node = root->childs.at(0); mkfs->tourAST(&node, root->command);     } break;
    case NTMKGRP:    { NodeAST node = root->childs.at(0); mkgrp->tourAST(&node, root->command);    } break;
    case NTMKUSR:    { NodeAST node = root->childs.at(0); mkusr->tourAST(&node, root->command);    } break;
    case NTMOUNT:    { NodeAST node = root->childs.at(0); mount->tourAST(&node, root->command);    } break;
    case NTMV:       { NodeAST node = root->childs.at(0); mv->tourAST(&node, root->command);       } break;
    case NTPAUSE:    { pause->execute(root->command);                                            } break;
    case NTRECOVERY: { NodeAST node = root->childs.at(0); recovery->tourAST(&node, root->command); } break;
    case NTRM:       { NodeAST node = root->childs.at(0); rm->tourAST(&node, root->command);      } break;
    case NTREN:      { NodeAST node = root->childs.at(0); ren->tourAST(&node, root->command);      } break;
    case NTREP:      { NodeAST node = root->childs.at(0); rep->tourAST(&node, root->command);      } break;
    case NTRMDISK:   { NodeAST node = root->childs.at(0); rmdisk->tourAST(&node, root->command);   } break;
    case NTRMGRP:    { NodeAST node = root->childs.at(0); rmgrp->tourAST(&node, root->command);    } break;
    case NTRMUSR:    { NodeAST node = root->childs.at(0); rmusr->tourAST(&node, root->command);    } break;
    case NTUNMOUNT:  { NodeAST node = root->childs.at(0); unmount->tourAST(&node, root->command);  } break;
    default:         {                                                              } break;

    }

}
