#!/bin/sh

function getsound(){ 
pactl list sinks | grep '^[[:space:]]Volume:' | \
        head -n $(( $SINK + 1 )) | tail -n 1 | sed -e 's,.* \([0-9][0-9]*\)%.*,\1,' 
}

function set_once() {
        xsetroot -name "Sound: $(getsound)% | Updates: $(checkupdates | wc -l) | Installed Packages: $(pacman -Q | wc -l) | $(date "+%a %B %d %H:%M" --utc) "
}

if [ "$1" = "--loop" ]; then
        # Set DWM status bar
        while true; do
                set_once
                sleep 1m 
        done
else
        set_once
fi
