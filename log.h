#ifndef _LOG_H
#define _LOG_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

FILE* logInfo;
FILE* logDebug;

void log_info(const char* str);
void log_debug(const char* str);
#endif // _LOG_H