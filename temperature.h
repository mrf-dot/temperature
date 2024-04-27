/*
 * Convert between different temperature units
 * lowercase flags denote origin temperature sign
 * uppercase flags denote converted temperature sign
 * Temperature conversion is done with macros
 * Example: Convert 20 C to F
 * INPUT: temp -c 20 -F
 * OUTPUT: 68
 * */
#ifndef TEMPERATURE_H

#define TEMPERATURE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 20
#define F2C(T) (((T) - 32) * (0.5555))
#define K2C(T) ((T) - 273.15)
#define R2C(T) (((T) - 491.67) * (0.5555))
#define C2F(T) ((T) * 1.8 + 32)
#define C2K(T) ((T) + 273.15)
#define C2R(T) (((T) + 273.15) * 1.8)
#define HELP "TEMP: Authored by Mitch Feigenbaum\n\
temp [-<unit> <VAL>] [-<UNIT>]\n\
temp [-<unit> <VAL> -<unit> <VAL> -<unit> <VAL>] [-<UNIT> -<UNIT> -<UNIT>]\n\
OPTIONS:\n\
\t-c<n>\t\tConvert a temperature from Celsius\n\
\t-C\t\tConvert a temperature to Celsius\n\
\t-f<n>\t\tConvert a temperature from Fahrenheit\n\
\t-F\t\tConvert a temperature to Fahrenheit\n\
\t-h\t\tPrint this help message\n\
\t-k<n>\t\tConvert a temperature from Kelvin\n\
\t-K\t\tConvert a temperature to Kelvin\n\
\t-r<n>\t\tConvert a temperature from Rankine\n\
\t-R\t\tConvert a temperature to Rankine\n"

#endif

