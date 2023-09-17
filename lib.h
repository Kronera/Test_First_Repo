/**********************************************************************************************
* Programmer: Natan Najera                                                                   *
* Class: CptS121; Lab section 02                                                             *
* Programming Assignment: Programming Assignment 01                                          *
* Date: 09/08/2023                                                                           *
*																							 *
* Description: program that reads, cleans, and writes the data from the FitbitDATA.csv		 *
*      CR: BENJAMIN SWANZEY FOR ASSISTANCE IN UNDERSTANDING  ternary operator                *
*********************************************************************************************/

#ifndef LIB_H
#define LIB_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structs
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;
typedef struct fitbit
{
	char Patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;



//prototypes
double HEART_AVG(int heart_sum, int count);


#endif
