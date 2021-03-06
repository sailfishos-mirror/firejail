# Firejail profile alias for torbrowser-launcher
# This file is overwritten after every install/update
# Persistent local customizations
include tor-browser_vi.local
# Persistent global definitions
# added by included profile
#include globals.local

nodeny  ${HOME}/.tor-browser_vi

mkdir ${HOME}/.tor-browser_vi
allow  ${HOME}/.tor-browser_vi

# Redirect
include torbrowser-launcher.profile
