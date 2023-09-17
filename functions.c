/**********************************************************************************************
* Programmer: Natan Najera                                                                   *
* Class: CptS121; Lab section 02                                                             *
* Programming Assignment: Programming Assignment 01                                          *
* Date: 09/08/2023                                                                           *
*																							 *
* Description: program that reads, cleans, and writes the data from the FitbitDATA.csv		 *
*      CR: BENJAMIN SWANZEY FOR ASSISTANCE IN UNDERSTANDING  ternary operator                *
*********************************************************************************************/
#include "lib.h"


/*************************************************************
* Function: HEART_AVG ()								     *
* Date Created:  09/05/2023                                  *
* Date Last Modified: 09/08/2023                             *
* Description: calculates avg heart rate				     *
* Input parameters: int heart_sum and int count			     *
* Returns: average											 *
* Preconditions: Having a int heart_sum and int count        *
* Postconditions: returns double avg                         *
*************************************************************/
double HEART_AVG(int heart_sum, int count)
{
	double avg = 0.0;
	avg = (double)heart_sum / (double)count;

	return avg;
}
