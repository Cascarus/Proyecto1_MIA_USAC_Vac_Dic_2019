  
#!/bin/bash
# -*- ENCODING: UTF-8 -*-
clear
bison -d parser.yy -v
flex scanner.l

read -n 1 -s -r -p $'Press any key to continue...\n'
