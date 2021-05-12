#ifndef PAVIII_H
#define PAVIII_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ASCII_NUM 128

	typedef struct occurrences
	{
		int num_occurrences;
		double frequency;
		
	} Occurrences;

	int my_strlen(const char* s);
	
	char* my_str_n_cat(char* destination, const char* source, int n);

	int binary_search(int array[], int length, int target);

	void bubble_sort(int array[], int length);

	bool IsPrime(int number);

	bool is_palindrome(char* string, int length);

	int sum_primes(unsigned int n);

	int maximum_occurences(const char* source, Occurrences array_track[MAX_ASCII_NUM], int* max_integer, char* max_character);

	void max_consecutive_integers(int array[][5], int x, int y, int** point_start, int** point_end);
	
	
#ifdef __cplusplus
}
#endif
#endif
