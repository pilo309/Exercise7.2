#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>
#include "Header.h"
#define SIZE 12


/*

Exercise 7.4: Præsentation af data
Udvid dit program fra exercise 7.2 med en eller anden form for ”grafisk” 
præsentation af middelværdierne af lysintensiteten (du kan ikke lave ”rigtige”
grafer – men prøv at være lidt kreativ ).

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

		puts("light intensity scale: ");
			for (size_t i = 0; i < 100; i+= 2)
				cout << " " << i << " ";
			cout << endl;

			cout << "average light intensity: " << endl;
			for (size_t i = 0; i <= average(ARRAY2, SIZE); i +=2)
				cout << " * ";
			
	}

	return 0;
}