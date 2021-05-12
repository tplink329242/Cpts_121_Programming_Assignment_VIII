#include "paviii_function.h"

int my_strlen(const char* s)
{
	int length = 0;
	while (s[length] != '\0')
	{
		length++;
	}

	return length;
}

char* my_str_n_cat(char* destination, const char* source, int n)
{
	const int length_source = my_strlen(source);
	const int length_destination = my_strlen(destination);

	//start writing
	if (n <= length_source)
	{
		for (int i = 0; i <= n; ++i)
		{
			destination[length_destination + i] = source[i];
		}
		destination[length_destination + n] = '\0';
	}
	else
	{
		for (int i = 0; i <= length_source; ++i)
		{
			destination[length_destination + i] = source[i];
		}
		for (int i = length_source; i < n; ++i)
		{
			destination[length_destination + length_source + i] = '\0';
		}
		destination[length_destination + length_source] = '\0';
	}

	return destination;
}

int binary_search(int array[], int length, int target)
{
	int target_index = -1;
	int left = 0;
	int mid = 0;
	int right = length;
	
	bool found = false;

	while (found == false && left <= right)
	{
		mid = (right - left) / 2;
		if (array[mid] == target)
		{
			found = true;
			target_index = mid;
		}
		if (array[mid] > target)
		{
			left = mid + 1;
		}
		if (array[mid] < target)
		{
			right = mid - 1;
		}
	}
	return target_index;
}

void bubble_sort(int array[], int length)
{
	int temp = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length -1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

bool IsPrime(int number)
{
	for (int i = 2; i <= number / 2; ++i)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

bool is_palindrome(char* string, int length)
{
	int res = false;
	
	if (length < 2) 
	{
		return true;                   
	}

	if (string[0] == ' ')
	{
		string++;
		res = is_palindrome(string, length - 1);
		return res;
	}
	
	if (string[length - 1] == ' ')
	{
		res = is_palindrome(string, length - 1);
		return res;
	}
	
	if (string[0] != string[length - 1])
	{
		return false;
	}

	string++;
	res = is_palindrome(string, length - 2);
	return res;
}

int sum_primes(unsigned int n)
{
	int sum = 0;
	int not_prime = 0;
	if (n < 2)
	{
		return -1;
	}
	if (n == 2)
	{
		return 2;
	}
	if (n > 2)
	{
		if (IsPrime(n))
		{
			sum = n + sum_primes(n - 1);
			return sum;
		}
		else
		{
			not_prime = sum_primes(n - 1);
		}
		return not_prime;
	}
}

int maximum_occurences(const char* source, Occurrences array_track[MAX_ASCII_NUM], int* max_integer, char* max_character)
{
	///1. fill out index array
	///2. get occurrences rate
	///3. find and return max integer and character

	char* temp = source;
	*max_integer = 0;
	*max_character = 0;

	//fill out array index
	while (*temp != '\0')
	{
		array_track[(int)(*temp)].num_occurrences += 1;
		temp++;
	}

	//get occurrence & get max value
	for (int i = 0; i < MAX_ASCII_NUM; ++i)
	{
		array_track[i].frequency = (double)(array_track[i].num_occurrences) / my_strlen(source);

		if (array_track[i].num_occurrences > *max_integer)
		{
			*max_integer = array_track[i].num_occurrences;
			*max_character = i;
		}
	}
	return 0;
}

void max_consecutive_integers(int array[][5], int x, int y, int** point_start, int** point_end)
{
	const int max_length = x * y;
	int* temp_array_ptr = array;

	int* temp_point_start = array;
	int* temp_point_end = array;
	
	int num_current_continuous = 1;
	int num_max_continuous = 0;

	//let first ptr go next position
	temp_array_ptr ++;
	
	for (int i = 1; i < max_length; ++i)
	{
		if (*temp_array_ptr == *temp_point_start)
		{
			num_current_continuous++;
			temp_point_end = temp_array_ptr;
		}
		else
		{
			if (num_current_continuous > num_max_continuous)
			{
				//start over
				num_max_continuous = num_current_continuous;
				*point_start = temp_point_start;
				*point_end = temp_point_end;
				num_current_continuous = 1;
			}

			temp_point_start = temp_array_ptr;
			temp_point_end = temp_array_ptr;
		}
		temp_array_ptr++;
	}
}
