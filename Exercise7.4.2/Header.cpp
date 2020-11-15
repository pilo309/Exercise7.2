#pragma once
#include "Header.h"

int maxValue(int* arrayPtr, const int size)
{
	int max = *arrayPtr; //det array pointeren peger på dens adressen

	for (size_t i = 1; i < size; i++) //hvor starte ved 1, det er fordi at *arrayPtr peger på 0 i forvejen!!!
	{
		*arrayPtr++;   //går en adresse længere op i array
		if (max < *arrayPtr) //hvis den nye adresse er større end maks
			max = *arrayPtr;
	}
	return max;
}

int minValue(int* arrayPtr, const int size)
{
	int min = *arrayPtr; //det array pointeren peger på dens adressen nummer 0

	for (size_t i = 1; i < size; i++)
	{
		*arrayPtr++;   //går en adresse længere op i array
		if (min > * arrayPtr) //hvis den nye adresse eks 1 er større end maks eks 0
			min = *arrayPtr;
	}
	return min;
}

double average(int array[], const int size)
{
	int total = 0;				//laver total variable som laver kummuleret sum

	for (size_t i = 0; i < size; i++)
		total += array[i];				//samme som total = total + array[i]

	return (total / size);				//dividerer med antallet af arrays = avg
}
