#include <fiss/fiss.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <splash/splash.h>
#include <time.h>
uint8_t _fiss_debug_enabled = 0;
uint8_t _fiss_info_enabled = 1;
uint8_t _fiss_warn_enabled = 1;
uint8_t _fiss_error_enabled = 1;
uint8_t _fiss_fatal_enabled = 1;

uint8_t fiss_color_mode = 24;

uint8_t _fiss_time_enabled = 1;
uint8_t _fiss_date_enabled = 0;

uint8_t _fiss_file_line_enabled = 0;

time_t _fiss_time_t; 
struct tm _fiss_tm_t;



void _fiss_print_time_date24(FILE* stream_out){
	if(_fiss_time_enabled || _fiss_date_enabled){
		_fiss_time_t= time(NULL);
		_fiss_tm_t = *localtime(&_fiss_time_t);
	}
	else{
		return;
	}
	if(_fiss_date_enabled){
		fprintf(stream_out,color0 FISS_DATE_COLOR24 "%d/%02d/%02d " color0, _fiss_tm_t.tm_year + 1900, _fiss_tm_t.tm_mon + 1, _fiss_tm_t.tm_mday);
	}
	if(_fiss_time_enabled){
		fprintf(stream_out,color0 FISS_TIME_COLOR24 "%02d:%02d:%02d " color0, _fiss_tm_t.tm_hour, _fiss_tm_t.tm_min, _fiss_tm_t.tm_sec);	
	}

}
void _fiss_print_time_date8(FILE* stream_out){
	if(_fiss_time_enabled || _fiss_date_enabled){
		_fiss_time_t= time(NULL);
		_fiss_tm_t = *localtime(&_fiss_time_t);
	}
	else{
		return;
	}
	if(_fiss_time_enabled){
		fprintf(stream_out,color0 FISS_TIME_COLOR8 "%02d:%02d:%02d " color0, _fiss_tm_t.tm_hour, _fiss_tm_t.tm_min, _fiss_tm_t.tm_sec);	
	}
	if(_fiss_date_enabled){
		fprintf(stream_out,color0 FISS_DATE_COLOR8 "%d/%02d/%02d " color0, _fiss_tm_t.tm_year + 1900, _fiss_tm_t.tm_mon + 1, _fiss_tm_t.tm_mday);
	}
}
void _fiss_print_time_date3(FILE* stream_out){
	if(_fiss_time_enabled || _fiss_date_enabled){
		_fiss_time_t= time(NULL);
		_fiss_tm_t = *localtime(&_fiss_time_t);
	}
	else{
		return;
	}
	if(_fiss_time_enabled){
		fprintf(stream_out,color0 FISS_TIME_COLOR3 "%02d:%02d:%02d " color0, _fiss_tm_t.tm_hour, _fiss_tm_t.tm_min, _fiss_tm_t.tm_sec);	
	}
	if(_fiss_date_enabled){
		fprintf(stream_out,color0 FISS_DATE_COLOR3 "%d/%02d/%02d " color0, _fiss_tm_t.tm_year + 1900, _fiss_tm_t.tm_mon + 1, _fiss_tm_t.tm_mday);
	}
}
void _fiss_print_time_date0(FILE* stream_out){
	if(_fiss_time_enabled || _fiss_date_enabled){
		_fiss_time_t= time(NULL);
		_fiss_tm_t = *localtime(&_fiss_time_t);
	}
	else{
		return;
	}
	if(_fiss_time_enabled){
		fprintf(stream_out,"%02d:%02d:%02d ", _fiss_tm_t.tm_hour, _fiss_tm_t.tm_min, _fiss_tm_t.tm_sec);	
	}
	if(_fiss_date_enabled){
		fprintf(stream_out,"%d/%02d/%02d ", _fiss_tm_t.tm_year + 1900, _fiss_tm_t.tm_mon + 1, _fiss_tm_t.tm_mday);
	}
}

#pragma region REG_FISS_DEBUG
#define __fiss_debug_printf_var_24(format, type) fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 format color0 FISS_DEBUG_COLOR_24, arg, va_arg(args, type))
#define __fiss_debug_printf_var_8(format, type) fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_8"%s=" color0 FISS_VAR_VAL_COLOR_8 format color0 FISS_DEBUG_COLOR_8, arg, va_arg(args, type))
#define __fiss_debug_printf_var_3(format, type) fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 format color0 FISS_DEBUG_COLOR_3, arg, va_arg(args, type))
#define __fiss_debug_printf_var(format, type) fprintf(FISS_DEBUG_OUT,"%s="format, arg, va_arg(args, type))

void _fiss_debug(const char* file, int line, ...){
	if(_fiss_debug_enabled == 0) return;
	va_list args;

	const char* arg = NULL;
	const char* arg2 = NULL;
	va_start(args, line);
	if(fiss_color_mode == 24){
		_fiss_print_time_date24(FISS_DEBUG_OUT);
		fputs(FISS_DEBUG_TEXT_COLOR_24 FISS_DEBUG_TEXT color0" "FISS_DEBUG_COLOR_24, FISS_DEBUG_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_DEBUG_OUT,color0 FISS_FILE_COLOR24 "<%s:%d> "color0 FISS_DEBUG_COLOR_24, file, line);
		}
		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_DEBUG_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_debug_printf_var_24("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_debug_printf_var_24("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_debug_printf_var_24("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_debug_printf_var_24("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_debug_printf_var_24("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_debug_printf_var_24("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_debug_printf_var_24("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_debug_printf_var_24("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_debug_printf_var_24("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_debug_printf_var_24("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_debug_printf_var_24("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_debug_printf_var_24("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_debug_printf_var_24("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_DEBUG_COLOR_24, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_DEBUG_COLOR_24, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_DEBUG_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_DEBUG_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 8){
		_fiss_print_time_date8(FISS_DEBUG_OUT);
		fputs(FISS_DEBUG_TEXT_COLOR_8 FISS_DEBUG_TEXT color0" "FISS_DEBUG_COLOR_8, FISS_DEBUG_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_DEBUG_OUT,color0 FISS_FILE_COLOR8 "<%s:%d> "color0 FISS_DEBUG_COLOR_8, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_DEBUG_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_debug_printf_var_8("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_debug_printf_var_8("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_debug_printf_var_8("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_debug_printf_var_8("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_debug_printf_var_8("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_debug_printf_var_8("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_debug_printf_var_8("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_debug_printf_var_8("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_debug_printf_var_8("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_debug_printf_var_8("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_debug_printf_var_8("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_debug_printf_var_8("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_debug_printf_var_8("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_DEBUG_COLOR_8, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_DEBUG_COLOR_8, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_DEBUG_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_DEBUG_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 3){
		_fiss_print_time_date3(FISS_DEBUG_OUT);
		fputs(FISS_DEBUG_TEXT_COLOR_3 FISS_DEBUG_TEXT color0" "FISS_DEBUG_COLOR_3, FISS_DEBUG_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_DEBUG_OUT,color0 FISS_FILE_COLOR3 "<%s:%d> "color0 FISS_DEBUG_COLOR_3, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_DEBUG_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_debug_printf_var_3("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_debug_printf_var_3("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_debug_printf_var_3("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_debug_printf_var_3("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_debug_printf_var_3("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_debug_printf_var_3("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_debug_printf_var_3("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_debug_printf_var_3("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_debug_printf_var_3("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_debug_printf_var_3("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_debug_printf_var_3("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_debug_printf_var_3("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_debug_printf_var_3("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_DEBUG_COLOR_3, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_DEBUG_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_DEBUG_COLOR_3, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_DEBUG_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_DEBUG_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else{
		_fiss_print_time_date0(FISS_DEBUG_OUT);
		fputs(FISS_DEBUG_TEXT" ", FISS_DEBUG_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_DEBUG_OUT,"<%s:%d> ", file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_DEBUG_OUT,"%s", arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_debug_printf_var("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_debug_printf_var("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_debug_printf_var("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_debug_printf_var("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_debug_printf_var("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_debug_printf_var("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_debug_printf_var("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_debug_printf_var("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_debug_printf_var("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_debug_printf_var("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_debug_printf_var("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_debug_printf_var("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_debug_printf_var("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_DEBUG_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_DEBUG_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_DEBUG_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_DEBUG_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}

	fputs("\n", FISS_DEBUG_OUT);
	va_end(args);
}
#undef __fiss_debug_printf_var_24
#undef __fiss_debug_printf_var_8
#undef __fiss_debug_printf_var_3
#undef __fiss_debug_printf_var
#pragma endregion

#pragma region REG_FISS_INFO
#define __fiss_info_printf_var_24(format, type) fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 format color0 FISS_INFO_COLOR_24, arg, va_arg(args, type))
#define __fiss_info_printf_var_8(format, type) fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_8"%s=" color0 FISS_VAR_VAL_COLOR_8 format color0 FISS_INFO_COLOR_8, arg, va_arg(args, type))
#define __fiss_info_printf_var_3(format, type) fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 format color0 FISS_INFO_COLOR_3, arg, va_arg(args, type))
#define __fiss_info_printf_var(format, type) fprintf(FISS_INFO_OUT,"%s="format, arg, va_arg(args, type))

void _fiss_info(const char* file, int line, ...){
	if(_fiss_info_enabled == 0) return;
	va_list args;

	const char* arg = NULL;
	const char* arg2 = NULL;
	va_start(args, line);
	if(fiss_color_mode == 24){
		_fiss_print_time_date24(FISS_INFO_OUT);
		fputs(FISS_INFO_TEXT_COLOR_24 FISS_INFO_TEXT color0" "FISS_INFO_COLOR_24, FISS_INFO_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_INFO_OUT,color0 FISS_FILE_COLOR24 "<%s:%d> "color0 FISS_INFO_COLOR_24, file, line);
		}
		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_INFO_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_info_printf_var_24("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_info_printf_var_24("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_info_printf_var_24("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_info_printf_var_24("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_info_printf_var_24("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_info_printf_var_24("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_info_printf_var_24("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_info_printf_var_24("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_info_printf_var_24("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_info_printf_var_24("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_info_printf_var_24("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_info_printf_var_24("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_info_printf_var_24("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_INFO_COLOR_24, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_INFO_COLOR_24, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_INFO_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_INFO_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 8){
		_fiss_print_time_date8(FISS_INFO_OUT);
		fputs(FISS_INFO_TEXT_COLOR_8 FISS_INFO_TEXT color0" "FISS_INFO_COLOR_8, FISS_INFO_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_INFO_OUT,color0 FISS_FILE_COLOR8 "<%s:%d> "color0 FISS_INFO_COLOR_8, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_INFO_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_info_printf_var_8("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_info_printf_var_8("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_info_printf_var_8("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_info_printf_var_8("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_info_printf_var_8("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_info_printf_var_8("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_info_printf_var_8("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_info_printf_var_8("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_info_printf_var_8("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_info_printf_var_8("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_info_printf_var_8("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_info_printf_var_8("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_info_printf_var_8("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_INFO_COLOR_8, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_INFO_COLOR_8, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_INFO_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_INFO_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 3){
		_fiss_print_time_date3(FISS_INFO_OUT);
		fputs(FISS_INFO_TEXT_COLOR_3 FISS_INFO_TEXT color0" "FISS_INFO_COLOR_3, FISS_INFO_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_INFO_OUT,color0 FISS_FILE_COLOR3 "<%s:%d> "color0 FISS_INFO_COLOR_3, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_INFO_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_info_printf_var_3("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_info_printf_var_3("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_info_printf_var_3("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_info_printf_var_3("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_info_printf_var_3("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_info_printf_var_3("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_info_printf_var_3("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_info_printf_var_3("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_info_printf_var_3("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_info_printf_var_3("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_info_printf_var_3("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_info_printf_var_3("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_info_printf_var_3("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_INFO_COLOR_3, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_INFO_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_INFO_COLOR_3, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_INFO_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_INFO_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else{
		_fiss_print_time_date0(FISS_INFO_OUT);
		fputs(FISS_INFO_TEXT" ", FISS_INFO_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_INFO_OUT,"<%s:%d> ", file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_INFO_OUT,"%s", arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_info_printf_var("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_info_printf_var("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_info_printf_var("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_info_printf_var("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_info_printf_var("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_info_printf_var("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_info_printf_var("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_info_printf_var("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_info_printf_var("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_info_printf_var("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_info_printf_var("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_info_printf_var("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_info_printf_var("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_INFO_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_INFO_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_INFO_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_INFO_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}

	fputs("\n", FISS_INFO_OUT);
	va_end(args);
}
#undef __fiss_info_printf_var_24
#undef __fiss_info_printf_var_8
#undef __fiss_info_printf_var_3
#undef __fiss_info_printf_var


#pragma endregion

#pragma region REG_FISS_WARN
#define __fiss_warn_printf_var_24(format, type) fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 format color0 FISS_WARN_COLOR_24, arg, va_arg(args, type))
#define __fiss_warn_printf_var_8(format, type) fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_8"%s=" color0 FISS_VAR_VAL_COLOR_8 format color0 FISS_WARN_COLOR_8, arg, va_arg(args, type))
#define __fiss_warn_printf_var_3(format, type) fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 format color0 FISS_WARN_COLOR_3, arg, va_arg(args, type))
#define __fiss_warn_printf_var(format, type) fprintf(FISS_WARN_OUT,"%s="format, arg, va_arg(args, type))

void _fiss_warn(const char* file, int line, ...){
	if(_fiss_warn_enabled == 0) return;
	va_list args;

	const char* arg = NULL;
	const char* arg2 = NULL;
	va_start(args, line);
	if(fiss_color_mode == 24){
		_fiss_print_time_date24(FISS_WARN_OUT);
		fputs(FISS_WARN_TEXT_COLOR_24 FISS_WARN_TEXT color0" "FISS_WARN_COLOR_24, FISS_WARN_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_WARN_OUT,color0 FISS_FILE_COLOR24 "<%s:%d> "color0 FISS_WARN_COLOR_24, file, line);
		}
		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_WARN_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_warn_printf_var_24("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_warn_printf_var_24("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_warn_printf_var_24("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_warn_printf_var_24("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_warn_printf_var_24("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_warn_printf_var_24("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_warn_printf_var_24("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_warn_printf_var_24("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_warn_printf_var_24("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_warn_printf_var_24("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_warn_printf_var_24("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_warn_printf_var_24("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_warn_printf_var_24("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_WARN_COLOR_24, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_WARN_COLOR_24, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_WARN_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_WARN_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 8){
		_fiss_print_time_date8(FISS_WARN_OUT);
		fputs(FISS_WARN_TEXT_COLOR_8 FISS_WARN_TEXT color0" "FISS_WARN_COLOR_8, FISS_WARN_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_WARN_OUT,color0 FISS_FILE_COLOR8 "<%s:%d> "color0 FISS_WARN_COLOR_8, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_WARN_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_warn_printf_var_8("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_warn_printf_var_8("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_warn_printf_var_8("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_warn_printf_var_8("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_warn_printf_var_8("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_warn_printf_var_8("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_warn_printf_var_8("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_warn_printf_var_8("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_warn_printf_var_8("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_warn_printf_var_8("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_warn_printf_var_8("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_warn_printf_var_8("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_warn_printf_var_8("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_WARN_COLOR_8, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_WARN_COLOR_8, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_WARN_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_WARN_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 3){
		_fiss_print_time_date3(FISS_WARN_OUT);
		fputs(FISS_WARN_TEXT_COLOR_3 FISS_WARN_TEXT color0" "FISS_WARN_COLOR_3, FISS_WARN_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_WARN_OUT,color0 FISS_FILE_COLOR3 "<%s:%d> "color0 FISS_WARN_COLOR_3, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_WARN_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_warn_printf_var_3("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_warn_printf_var_3("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_warn_printf_var_3("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_warn_printf_var_3("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_warn_printf_var_3("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_warn_printf_var_3("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_warn_printf_var_3("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_warn_printf_var_3("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_warn_printf_var_3("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_warn_printf_var_3("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_warn_printf_var_3("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_warn_printf_var_3("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_warn_printf_var_3("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_WARN_COLOR_3, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_WARN_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_WARN_COLOR_3, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_WARN_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_WARN_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else{
		_fiss_print_time_date0(FISS_WARN_OUT);
		fputs(FISS_WARN_TEXT" ", FISS_WARN_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_WARN_OUT,"<%s:%d> ", file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_WARN_OUT,"%s", arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_warn_printf_var("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_warn_printf_var("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_warn_printf_var("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_warn_printf_var("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_warn_printf_var("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_warn_printf_var("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_warn_printf_var("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_warn_printf_var("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_warn_printf_var("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_warn_printf_var("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_warn_printf_var("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_warn_printf_var("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_warn_printf_var("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_WARN_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_WARN_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_WARN_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_WARN_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}

	fputs("\n", FISS_WARN_OUT);
	va_end(args);
}
#undef __fiss_warn_printf_var_24
#undef __fiss_warn_printf_var_8
#undef __fiss_warn_printf_var_3
#undef __fiss_warn_printf_var


#pragma endregion

#pragma region REG_FISS_ERROR
#define __fiss_error_printf_var_24(format, type) fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 format color0 FISS_ERROR_COLOR_24, arg, va_arg(args, type))
#define __fiss_error_printf_var_8(format, type) fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_8"%s=" color0 FISS_VAR_VAL_COLOR_8 format color0 FISS_ERROR_COLOR_8, arg, va_arg(args, type))
#define __fiss_error_printf_var_3(format, type) fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 format color0 FISS_ERROR_COLOR_3, arg, va_arg(args, type))
#define __fiss_error_printf_var(format, type) fprintf(FISS_ERROR_OUT,"%s="format, arg, va_arg(args, type))

void _fiss_error(const char* file, int line, ...){
	if(_fiss_error_enabled == 0) return;
	va_list args;

	const char* arg = NULL;
	const char* arg2 = NULL;
	va_start(args, line);
	if(fiss_color_mode == 24){
		_fiss_print_time_date24(FISS_ERROR_OUT);
		fputs(FISS_ERROR_TEXT_COLOR_24 FISS_ERROR_TEXT color0" "FISS_ERROR_COLOR_24, FISS_ERROR_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_ERROR_OUT,color0 FISS_FILE_COLOR24 "<%s:%d> "color0 FISS_ERROR_COLOR_24, file, line);
		}
		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_ERROR_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_error_printf_var_24("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_error_printf_var_24("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_error_printf_var_24("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_error_printf_var_24("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_error_printf_var_24("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_error_printf_var_24("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_error_printf_var_24("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_error_printf_var_24("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_error_printf_var_24("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_error_printf_var_24("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_error_printf_var_24("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_error_printf_var_24("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_error_printf_var_24("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_ERROR_COLOR_24, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_ERROR_COLOR_24, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_ERROR_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_ERROR_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 8){
		_fiss_print_time_date8(FISS_ERROR_OUT);
		fputs(FISS_ERROR_TEXT_COLOR_8 FISS_ERROR_TEXT color0" "FISS_ERROR_COLOR_8, FISS_ERROR_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_ERROR_OUT,color0 FISS_FILE_COLOR8 "<%s:%d> "color0 FISS_ERROR_COLOR_8, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_ERROR_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_error_printf_var_8("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_error_printf_var_8("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_error_printf_var_8("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_error_printf_var_8("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_error_printf_var_8("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_error_printf_var_8("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_error_printf_var_8("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_error_printf_var_8("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_error_printf_var_8("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_error_printf_var_8("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_error_printf_var_8("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_error_printf_var_8("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_error_printf_var_8("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_ERROR_COLOR_8, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_ERROR_COLOR_8, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_ERROR_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_ERROR_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 3){
		_fiss_print_time_date3(FISS_ERROR_OUT);
		fputs(FISS_ERROR_TEXT_COLOR_3 FISS_ERROR_TEXT color0" "FISS_ERROR_COLOR_3, FISS_ERROR_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_ERROR_OUT,color0 FISS_FILE_COLOR3 "<%s:%d> "color0 FISS_ERROR_COLOR_3, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_ERROR_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_error_printf_var_3("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_error_printf_var_3("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_error_printf_var_3("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_error_printf_var_3("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_error_printf_var_3("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_error_printf_var_3("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_error_printf_var_3("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_error_printf_var_3("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_error_printf_var_3("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_error_printf_var_3("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_error_printf_var_3("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_error_printf_var_3("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_error_printf_var_3("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_ERROR_COLOR_3, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_ERROR_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_ERROR_COLOR_3, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_ERROR_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_ERROR_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else{
		_fiss_print_time_date0(FISS_ERROR_OUT);
		fputs(FISS_ERROR_TEXT" ", FISS_ERROR_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_ERROR_OUT,"<%s:%d> ", file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_ERROR_OUT,"%s", arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_error_printf_var("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_error_printf_var("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_error_printf_var("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_error_printf_var("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_error_printf_var("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_error_printf_var("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_error_printf_var("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_error_printf_var("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_error_printf_var("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_error_printf_var("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_error_printf_var("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_error_printf_var("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_error_printf_var("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_ERROR_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_ERROR_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_ERROR_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_ERROR_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}

	fputs("\n", FISS_ERROR_OUT);
	va_end(args);
}
#undef __fiss_error_printf_var_24
#undef __fiss_error_printf_var_8
#undef __fiss_error_printf_var_3
#undef __fiss_error_printf_var


#pragma endregion

#pragma region REG_FISS_FATAL
#define __fiss_fatal_printf_var_24(format, type) fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 format color0 FISS_FATAL_COLOR_24, arg, va_arg(args, type))
#define __fiss_fatal_printf_var_8(format, type) fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_8"%s=" color0 FISS_VAR_VAL_COLOR_8 format color0 FISS_FATAL_COLOR_8, arg, va_arg(args, type))
#define __fiss_fatal_printf_var_3(format, type) fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 format color0 FISS_FATAL_COLOR_3, arg, va_arg(args, type))
#define __fiss_fatal_printf_var(format, type) fprintf(FISS_FATAL_OUT,"%s="format, arg, va_arg(args, type))

void _fiss_fatal(const char* file, int line, ...){
	if(_fiss_fatal_enabled == 0) return;
	va_list args;

	const char* arg = NULL;
	const char* arg2 = NULL;
	va_start(args, line);
	if(fiss_color_mode == 24){
		_fiss_print_time_date24(FISS_FATAL_OUT);
		fputs(FISS_FATAL_TEXT_COLOR_24 FISS_FATAL_TEXT color0" "FISS_FATAL_COLOR_24, FISS_FATAL_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_FATAL_OUT,color0 FISS_FILE_COLOR24 "<%s:%d> "color0 FISS_FATAL_COLOR_24, file, line);
		}
		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_FATAL_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_fatal_printf_var_24("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_fatal_printf_var_24("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_fatal_printf_var_24("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_fatal_printf_var_24("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_fatal_printf_var_24("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_fatal_printf_var_24("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_fatal_printf_var_24("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_fatal_printf_var_24("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_fatal_printf_var_24("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_fatal_printf_var_24("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_fatal_printf_var_24("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_fatal_printf_var_24("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_fatal_printf_var_24("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_FATAL_COLOR_24, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_24"%s="color0 FISS_VAR_VAL_COLOR_24 "%s " color0 FISS_FATAL_COLOR_24, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_FATAL_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_FATAL_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 8){
		_fiss_print_time_date8(FISS_FATAL_OUT);
		fputs(FISS_FATAL_TEXT_COLOR_8 FISS_FATAL_TEXT color0" "FISS_FATAL_COLOR_8, FISS_FATAL_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_FATAL_OUT,color0 FISS_FILE_COLOR8 "<%s:%d> "color0 FISS_FATAL_COLOR_8, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_FATAL_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_fatal_printf_var_8("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_fatal_printf_var_8("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_fatal_printf_var_8("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_fatal_printf_var_8("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_fatal_printf_var_8("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_fatal_printf_var_8("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_fatal_printf_var_8("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_fatal_printf_var_8("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_fatal_printf_var_8("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_fatal_printf_var_8("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_fatal_printf_var_8("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_fatal_printf_var_8("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_fatal_printf_var_8("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_FATAL_COLOR_8, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_8"%s="color0 FISS_VAR_VAL_COLOR_8 "%s " color0 FISS_FATAL_COLOR_8, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_FATAL_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_FATAL_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else if(fiss_color_mode == 3){
		_fiss_print_time_date3(FISS_FATAL_OUT);
		fputs(FISS_FATAL_TEXT_COLOR_3 FISS_FATAL_TEXT color0" "FISS_FATAL_COLOR_3, FISS_FATAL_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_FATAL_OUT,color0 FISS_FILE_COLOR3 "<%s:%d> "color0 FISS_FATAL_COLOR_3, file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_FATAL_OUT,"%s"color0, arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_fatal_printf_var_3("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_fatal_printf_var_3("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_fatal_printf_var_3("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_fatal_printf_var_3("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_fatal_printf_var_3("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_fatal_printf_var_3("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_fatal_printf_var_3("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_fatal_printf_var_3("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_fatal_printf_var_3("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_fatal_printf_var_3("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_fatal_printf_var_3("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_fatal_printf_var_3("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_fatal_printf_var_3("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_FATAL_COLOR_3, arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_FATAL_OUT,color0 FISS_VAR_NAME_COLOR_3"%s="color0 FISS_VAR_VAL_COLOR_3 "%s " color0 FISS_FATAL_COLOR_3, arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_FATAL_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_FATAL_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}
	else{
		_fiss_print_time_date0(FISS_FATAL_OUT);
		fputs(FISS_FATAL_TEXT" ", FISS_FATAL_OUT);
		if(_fiss_file_line_enabled){
			fprintf(FISS_FATAL_OUT,"<%s:%d> ", file, line);
		}

		arg = va_arg(args, const char*);
		while(arg != NULL){
			arg2 = va_arg(args, const char*);
			if(arg2 == NULL){
				fprintf(FISS_FATAL_OUT,"%s", arg);
				break;
			}
			if(arg2[0] == '%'){
				if(arg2[1] == 'd'){
					__fiss_fatal_printf_var("%d ", int);
				}
				else if (arg2[1] == 'f') {
					__fiss_fatal_printf_var("%f ", double);		
				}
				else if (arg2[1] == 'c') {
					__fiss_fatal_printf_var("\'%c\' ", int);		
				}
				else if (arg2[1] == 's') {
					__fiss_fatal_printf_var("\"%s\" ", const char*);		
				}
				else if (arg2[1] == 'u') {
					__fiss_fatal_printf_var("%u ", unsigned int);		
				}
				else if (arg2[1] == 'x') {
					__fiss_fatal_printf_var("%x ", int);		
				}
				else if (arg2[1] == 'X') {
					__fiss_fatal_printf_var("%X ", int);		
				}
				else if (arg2[1] == 'o') {
					__fiss_fatal_printf_var("%o ", int);		
				}
				else if (arg2[1] == 'e') {
					__fiss_fatal_printf_var("%e ", double);		
				}
				else if (arg2[1] == 'E') {
					__fiss_fatal_printf_var("%E ", double);		
				}
				else if (arg2[1] == 'l') {
					__fiss_fatal_printf_var("%ld ", long);		
				}
				else if (arg2[1] == 'L') {
					__fiss_fatal_printf_var("%lld ", long long);		
				}
				else if (arg2[1] == 'U') {
					__fiss_fatal_printf_var("%llu ", unsigned long long);		
				}
				else if(arg2[1] == 'b'){
					fprintf(FISS_FATAL_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "true" : "false");
				}
				else if(arg2[1] == 'B'){
					fprintf(FISS_FATAL_OUT,"%s=%s ", arg, (va_arg(args, int) == 1) ? "TRUE" : "FALSE");
				}
				else {
					fprintf(FISS_FATAL_OUT,"%s %s ", arg, arg2);
				}
			}
			else{
				fprintf(FISS_FATAL_OUT,"%s ", arg);
				arg = arg2;
				continue;
			}
			arg = va_arg(args, const char*);
		}
	}

	fputs("\n", FISS_FATAL_OUT);
	va_end(args);
}
#undef __fiss_fatal_printf_var_24
#undef __fiss_fatal_printf_var_8
#undef __fiss_fatal_printf_var_3
#undef __fiss_fatal_printf_var


#pragma endregion

