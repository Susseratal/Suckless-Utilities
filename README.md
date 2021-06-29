ncmusic README
<!-- language: lang-none -->
                        _    _                       _   _ _ _ _   _           
         ___ _   _  ___| | _| | ___  ___ ___   _   _| |_(_) (_) |_(_) ___  ___ 
        / __| | | |/ __| |/ / |/ _ \/ __/ __| | | | | __| | | | __| |/ _ \/ __|
        \__ \ |_| | (__|   <| |  __/\__ \__ \ | |_| | |_| | | | |_| |  __/\__ \
        |___/\__,_|\___|_|\_\_|\___||___/___/  \__,_|\__|_|_|_|\__|_|\___||___/
                                                                       
Just my personal folder for my suckless utilities and configurations for such. Contains DWM configuration and ST configuration. Will update as I apply patches to both.  
If you want to remove any patches, just run "patch -R < [patch name]"  
The volume control keys also invoke the dwmbar script so that the sound output in the bar updates. Please check to make sure you've got the dwmbar shell script somewhere on your machine and the config.h file has a full path to it, otherwise you'll get a compiler error. (The dwmbar script comes with the git repo)  
If you have any questions about either of these, please feel free to ask, although I doubt I'll be able to answer them. List of changed keybinds follows:  
~ Iain xx  

Keybinds (only custom ones are here, everything else is deafult):  

DWM:
        
        MOD is Left Windows Key
        MOD + t == opens terminal
        MOD + b == opens browser (opera by default)
        MOD + d == opens discord (Much like browser, programs need to be installed)
        MOD + q == kill current application
        MOD + Shift + t == tiling mode
        MOD + Shift + d == decrease the number of windows on master in tiling mode
        MOD + F1 == Volume 100%
        MOD + F2 == Volume -5%
        MOD + F3 == Volume +5%
        MOD + F4 == Volume 0%

ST:

        Font: Source Code Pro #Monospaced
        Font Size: 16 #medium size
        Alpha: 0.9 #Dark
        Default Foreground: 10 #Green
        Default Background: 0 #Black

        MOD + Shift + J == Scroll Down
        MOD + Shift + K == Scroll Up
        MOD + Shift + H == Zoom in
        MOD + Shift + L == Zoom out
        MOD + Shift + Home == Reset zoom level
        MOD + Control + C == Copy selected terminal text
        MOD + Control + V == Paste selected terminal text
