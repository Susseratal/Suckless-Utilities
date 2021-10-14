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
I've made some tweaks so there are now two colour profiles. These do have to match up with the bashrc in order to look nice, but I'll update that too. Basically you can now swap between green on black with a pink dmenu and pink on black with a green dmenu. At the moment you have to use comments but I might make it a button push thing, if possible? Not sure how it would work though. 
If you have any questions about either of these, please feel free to ask, although I doubt I'll be able to answer them. List of changed keybinds follows:  
~ Iain xx  

Keybinds (only custom ones are here, everything else is deafult):  

DWM:
        
        MOD is Left Windows Key or Propellor/Command on Mac
        MOD + t == opens terminal
        MOD + b == opens browser (opera by default)
        MOD + d == opens discord (Much like browser, programs need to be installed)
        MOD + m == opens music player (needs to be installed)
        MOD + p == opens keepassxc (needs to be installed)
        MOD + space == dmenu
        MOD + q == kill current application
        MOD + Shift + T == tiling mode
        MOD + Shift + M == Single window mode
        MOD + Shift + D == decrease the number of windows on master in tiling mode
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
        MOD + Shift + O == Reset zoom level
        MOD + Control + c == Copy selected terminal text
        MOD + Control + v == Paste selected terminal text
