#ifdef TC_QTCREATOR
	#include <QDebug>
#endif // TC_QTCREATOR
#ifdef BOARD_ARMEBS4
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
#endif
#include "trace.h"

#define ADD_CRLF_SEQU 	0

#ifdef BOARD_ARMEBS4
	int Trace::checkStringEnding(char * str, unsigned long len)
	{
		if (!len)
		{
			return 0;
		}

		if (str[len-1] != '\n')
		{
#if (ADD_CRLF_SEQU != 0)
			// Add "\r\n" at the end of the string
			str[len] = '\r';
			str[len+1] = '\n';
			str[len+2] = '\0';
#else
			// Add "\n" at the end of the string
			str[len] = '\n';
			str[len+1] = '\0';
#endif
		}
#if (ADD_CRLF_SEQU != 0)
		// Check string finishing with "\r\n"
		else if (str[len-1] == '\n')
		{
			// Check if second last char is an '\r'
			if (len == 1 ||
				(len >= 2 && str[len-2] != '\r'))
			{
				// Squeeze a '\r'
				memmove(&str[len], &str[len-1], 2);
				str[len-1] = '\r';
			}
		}
#endif
		return strlen(str);
	}
#endif // BOARD_ARMEBS4

void Trace::out(string str)
{
#ifdef TC_QTCREATOR
	qDebug(str.data());
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
	if (str[str.length()-1] != '\n')
	{
		str += '\n';
	}
	printf(str.data());
#endif // BOARD_ARMEBS4
}

void Trace::out(const char * format, ...)
{
	char str[255];

#ifdef TC_QTCREATOR
	va_list args;

	va_start(args, format);
	vsprintf(str, format, args);
	va_end(args);

	qDebug(str);
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
	va_list args;

	// Format string
	va_start(args, format);
	vsprintf(str, format, args);
	va_end(args);

	checkStringEnding(str, strlen(str));

	printf(str);
#endif // BOARD_ARMEBS4
}
