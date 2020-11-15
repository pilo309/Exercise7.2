#include <iostream>
#define SIZE 10
#include "Header.h"

/*

Exercise 7.1: Maksimum, minimum og middelværdi
Skriv et modul (header og source fil) med følgende tre funktioner
int maxValue( int *, const int )
int minValue( int *, const int )
double average( int [], const int )
Alle tre funktioner skal kunne ”modtage” et array og de skal kunne bestemme
hhv. den største værdi i arrayet, den mindste værdi i arrayet og gennemsnittet af
alle værdier i arrayet (Hint 7A).

NB! Grunden til, at der er forskel på parameterlisten i funktionerne, er, at du
skal prøve begge dele .

Skriv derefter et lille testprogram (main) hvori du tester dine funktioner.

*/

int main ()
{
	using namespace std;
	
	int scan;

	int array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		cin >> scan;
		array[i] = scan;
	}

	puts("dit array hedder nu\n");

	for(size_t i = 0; i < SIZE; i++)
		cout << array[i] << " " << endl;

	cout << "max value is" << maxValue(array, SIZE) << endl;
	cout << "min value is" << minValue(array, SIZE) << endl;
	cout << "avg value is" << average(array, SIZE) << endl;

	return 0;
}