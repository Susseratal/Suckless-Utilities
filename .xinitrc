#!/bin/sh

# set keyboard to ISO layout
setxkbmap gb

# set X stuff
userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps
if [ -f $sysresources ]; then
        xrdb -merge $sysresources

fi

# Xmodmap has keybinds in it. rebinds caps lock to escape
if [ -s ~/.Xmodmap ]; then
        xmodmap ~/.Xmodmap
fi

if [ -f "$userresources" ]; then
        xrdb -merge "$userresources"
fi

# look at the xinit stuff? Not actually certain what this does
if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


# Run all the programs on startup
nitrogen --restore & # Nitrogen handles the desktop image (needs to be installed)
xcompmgr & # Run a composite manager
picom & # Run a second one for good measure
unclutter & # Hides the mouse when it's not being used
dwmbar.sh --loop & # Run dwmbar script
exec dwm # Run DWM on startup
