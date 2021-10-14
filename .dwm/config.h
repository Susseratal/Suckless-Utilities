/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows default 1*/
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_white[]       = "#FFFFFF";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan1[]       = "#005577";
static const char col_cyan2[]       = "#00ff9f";
static const char col_black[]       = "#000000";
static const char col_pink1[]       = "#ff33ff";
static const char col_green1[]      = "#008000";
static const char col_green2[]      = "#00FF00";
static const char *colors[][3]      = {
	/*               fg          bg         border   */
	[SchemeNorm] = { col_green2, col_black, col_gray2 },
	[SchemeBar]  = { col_green2, col_black, col_green1}, /* Green windows */
	[SchemeTag]  = { col_black, col_green2, col_green1},

	/* [SchemeNorm] = { col_pink1, col_black, col_gray2}, */
	/* [SchemeBar]  = { col_pink1, col_black, col_pink1}, */ /* Pink windows */
	/* [SchemeTag]  = { col_black, col_pink1, col_pink1}, */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ 0,                            KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_green2, "-sb", col_green1, "-sf", col_black, NULL }; */ /* Green Dmenu */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_pink1, "-sb", col_pink1, "-sf", col_black, NULL }; /* Pink Dmenu */
static const char *termcmd[] = { "st", NULL };
static const char *browser[] = { "opera", NULL };
static const char *discord[] = { "discord", NULL };
static const char *keepass[] = { "keepassxc", NULL };
static const char *screenshot[] = { "scrot", NULL };
static const char *gotop[] = { "st", "gotop", NULL };
static const char *music[] = { "st", "python", "/home/iain/Programming/ncmusic/src/main.py" };
static const char *dwmbar[] = { "/home/iain/Shell/dwmbar.sh", NULL };
static const char *upvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%", NULL};
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%", NULL};
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *setvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "100%", NULL };
static const char *setkbdon[] = { "brightnessctl", "--device='smc::kbd_backlight'", "set", "255", NULL };
static const char *setkbdoff[] = { "brightnessctl", "--device='smc::kbd_backlight'", "set", "0", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/*{ MODKEY,                       XK_F10,    spawn,          {.v = dmenucmd } },*/
	{ MODKEY,                       XK_space,    spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = keepass } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = screenshot } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      spawn,          {.v = browser } },
	{ MODKEY,                       XK_d,      spawn,          {.v = discord } },
	{ MODKEY,                       XK_m,      spawn,          {.v = music} },
	{ MODKEY,                       XK_g,      spawn,          {.v = gotop} },
	{ MODKEY,                       XK_v,      togglebar,      {0} },
	{ MODKEY,                       XK_n,      spawn,          {.v = nemo} },
	{ MODKEY|ShiftMask,             XK_v,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_F1,     spawn,          {.v = setvol } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = dwmbar } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = downvol} },
	{ MODKEY,                       XK_F2,     spawn,          {.v = dwmbar } },
	{ MODKEY,                       XK_F3,     spawn,          {.v = upvol} },
	{ MODKEY,                       XK_F3,     spawn,          {.v = dwmbar } },
	{ MODKEY,                       XK_F4,     spawn,          {.v = mutevol} },
	{ MODKEY,                       XK_F4,     spawn,          {.v = dwmbar } },
	{ MODKEY,                       XK_F5,     spawn,          {.v = setkbdoff } },
	{ MODKEY,                       XK_F6,     spawn,          {.v = setkbdon } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	/*{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },*/
	/*{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },*/
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_F1,                      0)
	TAGKEYS(                        XK_F2,                      1)
	TAGKEYS(                        XK_F3,                      2)
	TAGKEYS(                        XK_F4,                      3)
	TAGKEYS(                        XK_F5,                      4)
	TAGKEYS(                        XK_F6,                      5)
	TAGKEYS(                        XK_F7,                      6)
	TAGKEYS(                        XK_F8,                      7)
	TAGKEYS(                        XK_F9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

