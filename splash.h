#ifndef SPLASH_H
#define SPLASH_H
#include <stdint.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define SPLASH_PREFIX "\033"
#endif
#if defined __linux__ || __unix__
#define SPLASH_PREFIX "\x1b"
#endif
#define color24(r,g,b) SPLASH_PREFIX"[38;2;" #r ";" #g ";" #b "m"
#define color8(n) SPLASH_PREFIX"[38;5;" #n "m"
#define color3_4(n) SPLASH_PREFIX"[" #n "m"
#define bg24(r,g,b) SPLASH_PREFIX"[48;2;" #r ";" #g ";" #b "m"
#define bg8(n) SPLASH_PREFIX"[48;5;" #n "m"
#define bg3_4(n) color3_4(n)
#define color24_var(r,g,b) SPLASH_PREFIX"[38;2;" r ";" g ";" b "m"
#define color8_var(n) SPLASH_PREFIX"[38;5;" n "m"
#define color3_4_var(n) SPLASH_PREFIX"[" n "m"
#define bg24_var(r,g,b) SPLASH_PREFIX"[48;2;" r ";" g ";" b "m"
#define bg8_var(n) SPLASH_PREFIX"[48;5;" n "m"
#define bg3_4_var(n) color3_4_var(n)
#define color0 SPLASH_PREFIX"[0m"

#define colorize(str, col) color0 col str color0

#define SPLASH_COLOR_BLACK "30"
#define SPLASH_COLOR_RED "31"
#define SPLASH_COLOR_GREEN "32"
#define SPLASH_COLOR_YELLOW "33"
#define SPLASH_COLOR_BLUE "34"
#define SPLASH_COLOR_MAGENTA "35"
#define SPLASH_COLOR_CYAN "36"
#define SPLASH_COLOR_WHITE "37"

#define SPLASH_BRIGHT(x) x+70
#define SPLASH_BG(x) x+10

#define SPLASH_BOLD SPLASH_PREFIX"[1m"
#define SPLASH_BLINKING SPLASH_PREFIX"[5m"

typedef struct splash_color {
	uint8_t r,g,b;
} splash_color;


#ifdef SPLASH_NCURSES

unsigned int splash_max();

#endif

#endif
