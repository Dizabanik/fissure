#ifndef FISSURE_H
#define FISSURE_H
#include <splash/splash.h>


// ---------CONFIGURATION---------
// |    |   |   |   |   |   |   |
// |    |   |   |   |   |   |   |
// Output stream of debug
#define FISS_DEBUG_OUT stdout
// Output stream of info
#define FISS_INFO_OUT stdout
// Output stream of warn
#define FISS_WARN_OUT stdout
// Output stream of error
#define FISS_ERROR_OUT stdout
// Output stream of fatal
#define FISS_FATAL_OUT stdout


// Texts for different output types
#define FISS_DEBUG_TEXT "DEBU"
#define FISS_INFO_TEXT "INFO"
#define FISS_WARN_TEXT "WARN"
#define FISS_ERROR_TEXT "ERRO"
#define FISS_FATAL_TEXT "FATA"


// Color for file and line
#define FISS_FILE_COLOR24 color24(108, 111, 133)
#define FISS_FILE_COLOR8 color8(239)
#define FISS_FILE_COLOR3 color3_4_var(SPLASH_COLOR_WHITE)


// Color for variable name
#define FISS_VAR_NAME_COLOR_24 color24(124, 127, 147)
#define FISS_VAR_NAME_COLOR_8 color8(243)
#define FISS_VAR_NAME_COLOR_3 

// Color for variable value
#define FISS_VAR_VAL_COLOR_24 color24(32, 159, 181)
#define FISS_VAR_VAL_COLOR_8 color8(31)
#define FISS_VAR_VAL_COLOR_3 color3_4_var(SPLASH_COLOR_CYAN)

// Color for date
#define FISS_DATE_COLOR24 
#define FISS_DATE_COLOR8
#define FISS_DATE_COLOR3

// Color for time
#define FISS_TIME_COLOR24
#define FISS_TIME_COLOR8
#define FISS_TIME_COLOR3

// Color for the 'DEBU' text
#define FISS_DEBUG_TEXT_COLOR_24 SPLASH_BOLD color24(114,135,253)
#define FISS_DEBUG_TEXT_COLOR_8 SPLASH_BOLD color8(62)
#define FISS_DEBUG_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_BLUE)

// Color for the text in debug output
#define FISS_DEBUG_COLOR_24
#define FISS_DEBUG_COLOR_8
#define FISS_DEBUG_COLOR_3

// Color for the 'INFO' text
#define FISS_INFO_TEXT_COLOR_24 SPLASH_BOLD color24(23, 146, 153)
#define FISS_INFO_TEXT_COLOR_8 SPLASH_BOLD color8(30)
#define FISS_INFO_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_GREEN)

// Color for the text in info output
#define FISS_INFO_COLOR_24
#define FISS_INFO_COLOR_8
#define FISS_INFO_COLOR_3

// Color for the 'WARN' text
#define FISS_WARN_TEXT_COLOR_24 SPLASH_BOLD color24(223, 142, 29)
#define FISS_WARN_TEXT_COLOR_8 SPLASH_BOLD color8(215)
#define FISS_WARN_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_YELLOW)

// Color for the text in warn output
#define FISS_WARN_COLOR_24
#define FISS_WARN_COLOR_8
#define FISS_WARN_COLOR_3

// Color for the 'ERRO' text
#define FISS_ERROR_TEXT_COLOR_24 SPLASH_BOLD color24(210, 15, 57)
#define FISS_ERROR_TEXT_COLOR_8 SPLASH_BOLD color8(160)
#define FISS_ERROR_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_RED)

// Color for the text in error output
#define FISS_ERROR_COLOR_24
#define FISS_ERROR_COLOR_8
#define FISS_ERROR_COLOR_3

// Color for the 'FATA' text
#define FISS_FATAL_TEXT_COLOR_24 SPLASH_BOLD color24(136, 57, 239)
#define FISS_FATAL_TEXT_COLOR_8 SPLASH_BOLD color8(93)
#define FISS_FATAL_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_MAGENTA)

// Color for the text in fatal output
#define FISS_FATAL_COLOR_24
#define FISS_FATAL_COLOR_8
#define FISS_FATAL_COLOR_3
// |    |   |   |   |   |   |   |
// |    |   |   |   |   |   |   |
// ---------CONFIGURATION---------


















/*
 * Prints debug information to a specified output stream(stdout by default), typically for debugging purposes during software development.
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_debug("Some text", "%d", intVariable, "more text", "and text");`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_debug(...) _fiss_debug(__FILE__, __LINE__, __VA_ARGS__, NULL)

/*
 * Prints debug information to a specified output stream(stdout by default), typically for debugging purposes during software development.
 *
 *
 *
 * arg1: Has to be a format specifier, so next argument will be a variable to debug
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_debugv("%f", floatVariable);`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_debugv(...) _fiss_debug(__FILE__, __LINE__, "", __VA_ARGS__, NULL)


/*
 * Prints some information to a specified output stream(stdout by default).
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_info("Some text", "%d", intVariable, "more text", "and text");`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_info(...) _fiss_info(__FILE__, __LINE__, __VA_ARGS__, NULL)

/*
 * Prints some information to a specified output stream(stdout by default).
 *
 *
 *
 * arg1: Has to be a format specifier, so next argument will be a variable to print
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_infov("%f", floatVariable);`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_infov(...) _fiss_info(__FILE__, __LINE__, "", __VA_ARGS__, NULL)

/*
 * Prints warning information to a specified output stream(stdout by default).
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_warn("Some text", "%d", intVariable, "more text", "and text");`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_warn(...) _fiss_warn(__FILE__, __LINE__, __VA_ARGS__, NULL)

/*
 * Prints warning information to a specified output stream(stdout by default).
 *
 *
 *
 * arg1: Has to be a format specifier, so next argument will be a variable to print
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: Example: `fiss_warnv("%f", floatVariable);`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_warnv(...) _fiss_warn(__FILE__, __LINE__, "", __VA_ARGS__, NULL)

/*
 * Prints error information to a specified output stream(stdout by default).
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_error("Some text", "%d", intVariable, "more text", "and text");`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_error(...) _fiss_error(__FILE__, __LINE__, __VA_ARGS__, NULL)

/*
 * Prints error information to a specified output stream(stdout by default).
 *
 *
 *
 * arg1: Has to be a format specifier, so next argument will be a variable to print
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_errorv("%f", floatVariable);`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_errorv(...) _fiss_error(__FILE__, __LINE__, "", __VA_ARGS__, NULL)

/*
 * Prints fatal error information to a specified output stream(stdout by default).
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_fatal("Some text", "%d", intVariable, "more text", "and text");`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_fatal(...) _fiss_fatal(__FILE__, __LINE__, __VA_ARGS__, NULL)

/*
 * Prints fatal error information to a specified output stream(stdout by default).
 *
 *
 *
 * arg1: Has to be a format specifier, so next argument will be a variable to print
 *
 * ...: Variable number of arguments to be formatted and printed. Each argument can be string or specified by a format string followed by the value(s) to be printed.
 * 
 * Example: `fiss_fatalv("%f", floatVariable);`
 * 
 * 
 * Format specifiers:
 *      - %d: Prints an integer.
 *      - %f: Prints a floating-point number.
 *      - %c: Prints a character.
 *      - %s: Prints a string.
 *      - %u: Prints an unsigned integer.
 *      - %b: Prints a boolean value as "true" or "false" (lowercase).
 *      - %B: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
 *      - %x: Prints an integer in hexadecimal format (lowercase).
 *      - %X: Prints an integer in hexadecimal format (uppercase).
 *      - %o: Prints an integer in octal format.
 *      - %e: Prints a floating-point number in scientific notation (lowercase).
 *      - %E: Prints a floating-point number in scientific notation (uppercase).
 *      - %l: Prints a long integer.
 *      - %L: Prints a long long integer.
 *      - %U: Prints an unsigned long long integer.
*/
#define fiss_fatalv(...) _fiss_fatal(__FILE__, __LINE__, "", __VA_ARGS__, NULL)

/*
 * Enables fiss service
 *
 *
 *
 * x: service name to enable
 *
 * Example: `fiss_enable(debug);`
 * 
 * 
 * Services:
 *      - debug: enable debug output(disabled by default)
 *      - info: enable info output
 *      - warn: enable warnings output
 *      - error: enable errors output
 *      - fatal: enable fatal errors output
 *      - time: enable time in output
 *      - date: enable date in output(disabled by default)
 *      - file_line: enable file and line from where the function was called in output(disabled by default)
*/
#define fiss_enable(x) _fiss_##x##_enabled = 1
/*
 * Disables fiss service
 *
 *
 *
 * x: service name to disable
 *
 * Example: `fiss_disable(time);`
 * 
 * 
 * Services:
 *      - debug: disable debug output(disabled by default)
 *      - info: disable info output
 *      - warn: disable warnings output
 *      - error: disable errors output
 *      - fatal: disable fatal errors output
 *      - time: disable time in output
 *      - date: disable date in output(disabled by default)
 *      - file_line: disable file and line from where the function was called in output(disabled by default)
*/
#define fiss_disable(x) _fiss_##x##_enabled = 0
/*
 * Sets color mode for Fiss
 *
 *
 *
 * x: color mode
 *
 * Example: `fiss_set_color_mode(8);`
 * 
 * 
 * Color modes:
 *      - 24 : 24-bit 'truecolor' mode (by default)
 *      - 8 : 8-bit (256 colors) mode
 *      - 3 : 3-bit or 4-bit mode
 *      - 0 (or another value): no color mode (works with any terminal)
*/
#define fiss_set_color_mode(x) fiss_color_mode = x


void _fiss_debug(const char* file, int line, ...);
void _fiss_info(const char* file, int line, ...);
void _fiss_warn(const char* file, int line, ...);
void _fiss_error(const char* file, int line, ...);
void _fiss_fatal(const char* file, int line, ...);
extern uint8_t _fiss_debug_enabled;
extern uint8_t _fiss_info_enabled;
extern uint8_t _fiss_warn_enabled;
extern uint8_t _fiss_error_enabled;
extern uint8_t _fiss_fatal_enabled;
extern uint8_t _fiss_time_enabled;
extern uint8_t _fiss_date_enabled;
extern uint8_t _fiss_file_line_enabled;
extern uint8_t fiss_color_mode;
#endif

