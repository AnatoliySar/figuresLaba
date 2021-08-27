#include "log.h"
#include "stdarg.h"
#include "string.h"
#include "stdlib.h"

void log_info(const char* fmt, ...)
{
	char buffer[4096];
	char buffer2[4096];
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	sprintf(buffer, asctime(timeinfo));
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer2, sizeof(buffer), fmt, args);
	va_end(args);
	strcat(buffer, buffer2);
	fwrite(buffer, 1, strlen(buffer), logInfo);
	fwrite("\n\n", 1, 2, logInfo);
}

void log_debug(const char* fmt, ...)
{
	char buffer[4096];
	char buffer2[4096];
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	sprintf(buffer, asctime(timeinfo));
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer2, sizeof(buffer), fmt, args);
	va_end(args);
	strcat(buffer, buffer2);
	fwrite(buffer, 1, strlen(buffer), logDebug);
	fwrite("\n\n", 1, 2, logDebug);
}