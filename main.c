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


int main(void)
{
	FILE* Fitbit = fopen("FitbitData.csv", "r"), * results = fopen("result.csv", "w");
	char title[] = "Header line: Total Calories,Total Distance,Total Floors,Total Steps, Avg Heartrate, Max Steps, Sleep";
	FitbitData deets[1446] = { "", "", 0.0, 0.0, 0, 0, 0 };
	int count = 0;
	const char* target = "12cx7";
	char row[1446];
	double Calories_total = 0.0, Distance_total = 0.0;
	unsigned int max_sleep_sum = 0,max_step_min = 0,Heart_sum = 0, Floors_total = 0, Steps_total = 0, Steps_MAX = 0, sleep_sum = 0, Start_sleep = 0, End_sleep = 0;
	
	// checking the success of the file opening operation
	if (Fitbit == NULL)
	{
		perror("Error Opening File For Reading\n");
		return 1;
	}
	if (results == NULL)
	{
		perror("Error Opening File For Writing\n");
		return 1;
	}

	printf("patient minutes calories distance floors heartrate steps sleeplvl \n");
	fprintf(results, "%s\n", title);
	// reading each record in the file as a string, one line at atime, and filtering and deduping any lines that do not belong to the targetpatient or are duplicates
	while (fgets(row, sizeof(row), Fitbit)) {
		char* token = strtok(row, ",");
		char patient[10];
		strcpy(patient, token);

		if (strcmp(patient, target) == 0)
		{
			strcpy(deets[count].Patient, patient);
			printf("%d. %s", count, deets[count].Patient);
			fprintf(results,"%s", deets[count].Patient);

			strcpy(deets[count].minute, strtok(NULL, ","));
			printf(" %s", deets[count].minute);
			fprintf(results," %s", deets[count].minute);

			deets[count].calories = atof(strtok(NULL, ","));
			Calories_total += deets[count].calories;
			printf(" %lf", deets[count].calories);
			fprintf(results," %lf", deets[count].calories);

			deets[count].distance = atof(strtok(NULL, ","));
			Distance_total += deets[count].distance;
			printf(" %lf", deets[count].distance);
			fprintf(results," %lf", deets[count].distance);

			char* floor_str = strtok(NULL, ",");
			// correctly cleaning the data and parsing each record into thecorresponding fields
			deets[count].floors = (floor_str != NULL) ? atoi(floor_str) : 0;
			Floors_total += deets[count].floors;
			printf(" %d", deets[count].floors);
			fprintf(results," %d", deets[count].floors);

			char* Heart_str = strtok(NULL, ",");
			// correctly cleaning the data and parsing each record into thecorresponding fields
			deets[count].heartRate = (Heart_str != NULL) ? atoi(Heart_str) : 0;
			Heart_sum += deets[count].heartRate;
			printf(" %d", deets[count].heartRate);
			fprintf(results," %d", deets[count].heartRate);


			char* steps_str = strtok(NULL, ",");
			// correctly cleaning the data and parsing each record into thecorresponding fields
			deets[count].steps = (steps_str != NULL) ? atoi(steps_str) : 0;
			Steps_total += deets[count].steps;
			printf(" %d", deets[count].steps);
			fprintf(results," %d", deets[count].steps);

			int* Slvl = strtok(NULL, ",");
			if (Slvl != NULL) {
				if (atoi(Slvl) == 1) {
					deets[count].sleepLevel = ASLEEP;
				}
				else if (atoi(Slvl) == 2) {
					deets[count].sleepLevel = AWAKE;
				}
				else if (atoi(Slvl) == 3) {
					deets[count].sleepLevel = REALLYAWAKE;
				}
				else {
					deets[count].sleepLevel = NONE;
				}
			}
			else {
				deets[count].sleepLevel = NONE;
			}
			printf(" %d\n", deets[count].sleepLevel);
			fprintf(results," %d\n", deets[count].sleepLevel);
			
		}

		if (deets[count].steps > Steps_MAX)
		{
			Steps_MAX = deets[count].steps;
			max_step_min = count;
		}
		if(deets[count].sleepLevel > 1)
		{
			if (sleep_sum == 0) {
				Start_sleep = count;
			} 
			End_sleep = count;
			sleep_sum += deets[count].sleepLevel;
		}
		else
		{
			if (sleep_sum > max_sleep_sum)
			{
				max_sleep_sum = sleep_sum;
			}
			sleep_sum = 0;
		}
		count++;
	}

	
	double heart_avg = HEART_AVG(Heart_sum, count);

	
	
	fclose(Fitbit);
	

	fprintf(results, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");

	
	fprintf(results, "RESULTS: TOTAL CALORIES: %.2lf, TOTAL DISTANCE: %.2lf, TOTAL FLOORS: %u,TOTAL STEPS: %u,HEART AVERAGE: %.2lf,MAX STEPS: %u,START SLEEP: %u: END SLEEP: %u\n", Calories_total, Distance_total, Floors_total, Steps_total, heart_avg, Steps_MAX, Start_sleep, End_sleep);
	printf("RESULTS: TOTAL CALORIES: %.2lf, TOTAL DISTANCE: %.2lf, TOTAL FLOORS: %u,TOTAL STEPS: %u,HEART AVERAGE: %.2lf,MAX STEPS: %u,START SLEEP: %u: END SLEEP: %u\n", Calories_total, Distance_total, Floors_total, Steps_total, heart_avg, Steps_MAX, Start_sleep, End_sleep);
	


	
	fclose(results);

	return 0;
}
