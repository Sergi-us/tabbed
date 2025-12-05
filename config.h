/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]        = "JetBrainsMono NF ExtraLight:style=ExtraLight:size=8:antialias=true:autohint=true";
static const char* normbgcolor  = "#222222";
static const char* normfgcolor  = "#cccccc";
static const char* selbgcolor   = "#555555";
static const char* selfgcolor   = "#ffffff";
static const char* urgbgcolor   = "#111111";
static const char* urgfgcolor   = "#cc0000";
static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "...";
static const int  tabwidth      = 200;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 0;
static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu -l 10 -w $1`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define MODKEY ControlMask
static const Key keys[] = {
	/* modifier             key        function     argument */

	/* === Tab-Erstellung === */
	{ MODKEY|ShiftMask,     XK_Return, focusonce,   { 0 } },
	{ MODKEY|ShiftMask,     XK_Return, spawn,       { 0 } },

	/* === Tab-Navigation (Vi-Bindings) === */
	{ MODKEY|ShiftMask,     XK_h,      rotate,      { .i = -1 } }, // Vorheriger Tab
	{ MODKEY|ShiftMask,     XK_l,      rotate,      { .i = +1 } }, // Nächster Tab
	{ MODKEY|ShiftMask,     XK_j,      movetab,     { .i = -1 } }, // Tab nach links verschieben
	{ MODKEY|ShiftMask,     XK_k,      movetab,     { .i = +1 } }, // Tab nach rechts verschieben

	/* === Tab-Navigation (Pfeiltasten) === */
	{ MODKEY|ShiftMask,     XK_Left,   rotate,      { .i = -1 } }, // Vorheriger Tab
	{ MODKEY|ShiftMask,     XK_Right,  rotate,      { .i = +1 } }, // Nächster Tab

	/* === Schnellzugriff === */
	{ MODKEY,               XK_Tab,    rotate,      { .i = 0 } },  // Letzter Tab (toggle)

	/* === Tab-Auswahl per Nummer (Ctrl+Shift+1-9) === */
	{ MODKEY|ShiftMask,     XK_1,      move,        { .i = 0 } },
	{ MODKEY|ShiftMask,     XK_2,      move,        { .i = 1 } },
	{ MODKEY|ShiftMask,     XK_3,      move,        { .i = 2 } },
	{ MODKEY|ShiftMask,     XK_4,      move,        { .i = 3 } },
	{ MODKEY|ShiftMask,     XK_5,      move,        { .i = 4 } },
	{ MODKEY|ShiftMask,     XK_6,      move,        { .i = 5 } },
	{ MODKEY|ShiftMask,     XK_7,      move,        { .i = 6 } },
	{ MODKEY|ShiftMask,     XK_8,      move,        { .i = 7 } },
	{ MODKEY|ShiftMask,     XK_9,      move,        { .i = 8 } },
	{ MODKEY|ShiftMask,     XK_0,      move,        { .i = 9 } },

	/* === Tab-Auswahl per dmenu === */
	{ MODKEY,               XK_grave,  spawn,       SETPROP("_TABBED_SELECT_TAB") },

	/* === Tab schließen === */
	{ MODKEY|ShiftMask,     XK_q,      killclient,  { 0 } }, // Kitty-Style
	{ MODKEY|ShiftMask,     XK_w,      killclient,  { 0 } }, // Browser-Style

	/* === Urgent-Handling === */
	{ MODKEY|ShiftMask,     XK_u,      focusurgent, { 0 } }, // Zu urgent Tab springen
	{ MODKEY|ShiftMask,     XK_U,      toggle,      { .v = (void*) &urgentswitch } }, // Urgent-Switch toggle

	/* === Fullscreen (optional) === */
	/* { 0,                    XK_F11,    fullscreen,  { 0 } }, */
};

