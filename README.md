# Fissure: Cozy Debugging and Logging for C

Welcome to **Fissure** - your cozy companion for debugging and logging in C! Whether you're cuddling up with your code or navigating through debugging sessions, Fissure provides a warm and comfortable environment to enhance your development experience.

![example](https://github.com/Dizabanik/fissure/blob/0c15d7bb413f3daf1e50755ffcfe2c53398b0d88/2.png)

## Features

- **Detailed Debug Messages:** Keep track of your code's execution with comprehensive debug messages.
- **Logging Functionality:** Stay informed about the status of your application with detailed logging capabilities.
- **Warning Notifications:** Receive alerts for potential issues or disturbances in your application.
- **Error Handling:** Handle errors gracefully with detailed error messages and appropriate actions.
- **Critical Error Management:** Manage critical errors effectively with prompt notifications and necessary actions.
- **Colorful output:** Based on **Splash** library
## Installation

To integrate Fissure into your C project, follow these simple steps:

1. Clone the Fissure repository:

`git clone https://github.com/dizabanik/fissure.git`

2. Install [**Splash**](https://github.com/dizabanik/splash)
`git clone https://github.com/dizabanik/splash & mv ./splash/ ./fissure/`

**THAT'S IT! 😁**

## Usage

### Include header file

```c
#include "fissure/fiss.h"
```

### Enable features you need

To enable or disable features like debug mode, date printing, etc.:
```c
fiss_enable(debug); // enable debug(only for debug output)
fiss_disable(time); // disable time printing
```

### Debugging and Logging

Example:

```c
fiss_enable(debug);
int cats = 3;
float happiness_level = 9.5;
const char *activity = "snuggling";

// Let's start with some comforting debugging

fiss_debug("Checking cozy levels...", "cats found", "%d", cats, "Happiness level", "%f", happiness_level);
fiss_info("Feeling snug...", "cats snuggled", "%d", cats, "Current activity", "%s", activity);

// Oh no! A little hiccup, but just a warning
fiss_warn("Interrupted snuggle...", "Potential disturbance while", "%s", activity);
fiss_warnv("%f", happiness_level);

// Time to wrap up warm, we've encountered an error
fiss_error("Snuggle crisis!", "Cats remaining", "%d", cats - 1);
fiss_errorv("%s", activity, "<- Current Activity!");

// It's freezing, we can't go on like this!
fiss_fatal(colorize("Cuddle catastrophe!", SPLASH_BOLD color24(230, 69, 83)), "Cats abandoned, happiness level critical");
```
![example](https://github.com/Dizabanik/fissure/blob/0c15d7bb413f3daf1e50755ffcfe2c53398b0d88/1.png)

### Configuration

Customize Fissure's behavior by modifying the configuration macros in the `fiss.h` header file according to your preferences.
Example(changing the `ERRO` text into `ERROR!`, making text bold and red, on green background): 
```c
// IN fiss.h


#define FISS_DEBUG_TEXT "DEBU"
#define FISS_INFO_TEXT "INFO"
#define FISS_WARN_TEXT "WARN"
#define FISS_ERROR_TEXT "ERROR!" // We change this
#define FISS_FATAL_TEXT "FATA"

//...

// You can change only one color mode if you are making your debugging only for one type of terminals

#define FISS_ERROR_TEXT_COLOR_24 SPLASH_BOLD color24(210, 15, 57) bg24(64, 160, 43) // Green color rgb

#define FISS_ERROR_TEXT_COLOR_8 SPLASH_BOLD color8(160) bg8(34) // Green color 8-bit ID

#define FISS_ERROR_TEXT_COLOR_3 SPLASH_BOLD color3_4_var(SPLASH_COLOR_RED) bg3_4_var(SPLASH_COLOR_GREEN)

//...

```
![example](https://github.com/Dizabanik/fissure/blob/0c15d7bb413f3daf1e50755ffcfe2c53398b0d88/3.png)

# FULL DOCUMENTATION FOR EVERY FUNCTION YOU WILL USE:

## fiss_debug

Prints debug information to a specified output stream (stdout by default), typically for debugging purposes during software development.

### Arguments:
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_debug("Some text", "%d", intVariable, "more text", "and text");
```

### Format specifiers:
- `%d`: Prints an integer.
- `%f`: Prints a floating-point number.
- `%c`: Prints a character.
- `%s`: Prints a string.
- `%u`: Prints an unsigned integer.
- `%b`: Prints a boolean value as "true" or "false" (lowercase).
- `%B`: Prints a boolean value as "TRUE" or "FALSE" (uppercase).
- `%x`: Prints an integer in hexadecimal format (lowercase).
- `%X`: Prints an integer in hexadecimal format (uppercase).
- `%o`: Prints an integer in octal format.
- `%e`: Prints a floating-point number in scientific notation (lowercase).
- `%E`: Prints a floating-point number in scientific notation (uppercase).
- `%l`: Prints a long integer.
- `%L`: Prints a long long integer.
- `%U`: Prints an unsigned long long integer.

---

## fiss_debugv

Prints debug information to a specified output stream (stdout by default), typically for debugging purposes during software development.

### Arguments:
- `arg1`: Has to be a format specifier, so the next argument will be a variable to debug.
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_debugv("%f", floatVariable);
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_info

Prints some information to a specified output stream (stdout by default).

### Arguments:
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_info("Some text", "%d", intVariable, "more text", "and text");
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_infov

Prints some information to a specified output stream (stdout by default).

### Arguments:
- `arg1`: Has to be a format specifier, so the next argument will be a variable to print.
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_infov("%f", floatVariable);
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_warn

Prints warning information to a specified output stream (stdout by default).

### Arguments:
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_warn("Some text", "%d", intVariable, "more text", "and text");
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_warnv

Prints warning information to a specified output stream (stdout by default).

### Arguments:
- `arg1`: Has to be a format specifier, so the next argument will be a variable to print.
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_warnv("%f", floatVariable);
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_error

Prints error information to a specified output stream (stdout by default).

### Arguments:
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_error("Some text", "%d", intVariable, "more text", "and text");
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_errorv

Prints error information to a specified output stream (stdout by default).

### Arguments:
- `arg1`: Has to be a format specifier, so the next argument will be a variable to print.
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_errorv("%f", floatVariable);
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_fatal

Prints fatal error information to a specified output stream (stdout by default).

### Arguments:
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_fatal("Some text", "%d", intVariable, "more text", "and text");
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_fatalv

Prints fatal error information to a specified output stream (stdout by default).

### Arguments:
- `arg1`: Has to be a format specifier, so the next argument will be a variable to print.
- `...`: Variable number of arguments to be formatted and printed. Each argument can be a string or specified by a format string followed by the value(s) to be printed.

### Example:
```c
fiss_fatalv("%f", floatVariable);
```

### Format specifiers:
(Same as fiss_debug)

---

## fiss_enable

Enables fiss service.

### Arguments:
- `x`: Service name to enable.

### Example:
```c
fiss_enable(debug);
```

### Services:
- `debug`: Enable debug output (disabled by default).
- `info`: Enable info output.
- `warn`: Enable warnings output.
- `error`: Enable errors output.
- `fatal`: Enable fatal errors output.
- `time`: Enable time in output.
- `date`: Enable date in output (disabled by default).
- `file_line`: Enable file and line from where the function was called in output (disabled by default).

---

## fiss_disable

Disables fiss service.

### Arguments:
- `x`: Service name to disable.

### Example:
```c
fiss_disable(time);
```

### Services:
- `debug`: Disable debug output (disabled by default).
- `info`: Disable info output.
- `warn`: Disable warnings output.
- `error`: Disable errors output.
- `fatal`: Disable fatal errors output.
- `time`: Disable time in output.
- `date`: Disable date in output (disabled by default).
- `file_line`: Disable file and line from where the function was called in output (disabled by default).

---

## fiss_set_color_mode

Sets color mode for Fiss.

### Arguments:
- `x`: Color mode.

### Example:
```c
f

iss_set_color_mode(8);
```

### Color modes:
- `24`: 24-bit 'truecolor' mode (by default).
- `8`: 8-bit (256 colors) mode.
- `3`: 3-bit or 4-bit mode.
- `0` (or another value): No color mode (works with any terminal).

---

## License

This project is licensed under the MIT License - see the LICENSE file for details.
