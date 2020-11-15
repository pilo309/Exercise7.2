#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>
#include "Header.h"
#define SIZE 12


/*

Exercise 7.2: Dataindsamling med Raspberry Pi (fortsat fra sidste uge)

I sidste uge lavede du et program hvor du opsamlede data fra
temperatursensorer og fotoresistoren på din Raspberry Pi.

Du skal nu lave dette program om således:
- Hver gang der er gået et minut skal den størst og den mindste målte
værdi bestemmes og middelværdien skal beregnes.

- I stedet for at udskrive alle målte værdier på skærmen, skal kun den
største, den mindste og middelværdien udskrives.
NB! Brug det modul du lavede i exercise 7.1.

*/

int main(void)
{

	using namespace std;

	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	int ARRAY2[SIZE];        //definere vores 2 arrays
	int ARRAY1[SIZE];


	while (true)

	{
		for (size_t i = 0; i < SIZE; i++)			//få temeraturen og lys ind i hver array
													// hver 5. milisekund
		{
			ARRAY1[i] = getTemperature();
			ARRAY2[i] = getIntensity();
			Wait(5);
		}

		printf_s("\n\nTemeraturen er: \n");
		for (size_t i = 0; i < SIZE; i++)
			printf_s("%5.2d", ARRAY1[i]);

		printf_s("\n\nLysintensiteten er: \n");
		for (size_t i = 0; i < SIZE; i++)
			printf_s("%5.2d", ARRAY2[i]);

		cout << endl;				//genbruger vores max min og avg funktioner
		cout << "max temperature is: " << maxValue(ARRAY1, SIZE) << endl;
		cout << "max light intensity is: " << maxValue(ARRAY2, SIZE) << endl;
		cout << "min temperature is: " << minValue(ARRAY1, SIZE) << endl;
		cout << "min light intensity is: " << minValue(ARRAY2, SIZE) << endl;
		cout << "avg temperature is: " << average(ARRAY1, SIZE) << endl;
		cout << "avg light intensity is: " << average(ARRAY2, SIZE) << endl;

	}

	return 0;
}