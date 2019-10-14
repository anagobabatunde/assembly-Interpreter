#!/bin/bash

isMan() {
    command -v man >/dev/null 2>&1 || { echo >&2 "La commande man n'est pas installee. Veuillez l'installer avant de continuer."; exit 1; }
}

cmdHelp() {
        echo -e "Usage: ./manhelper.sh [COMMAND] <OPTION> [FLAG NAME]
OPTION:
    --usageflag [FLAG NAME] : Display information for the [FLAG NAME]
    --describe : Display description of the command"
}

noArg() {
if [[ $# -eq 0 ]] || [[ $# -gt 3 ]]; then
    cmdHelp; exit 1;
fi
}
isMan 
noArg $#
