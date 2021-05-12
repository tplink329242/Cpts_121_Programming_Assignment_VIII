#include "paviii_function.h"

void test()
{
	int n = 0;
	n = 100;

	printf_s("The num %d, is %d\n", n, sum_primes(n));


	char max_char = '\0';
	int max_int = 0;

	char* string = "test string";

	Occurrences array[MAX_ASCII_NUM] = { 0, 0 };

	maximum_occurences(string, array, &max_int, &max_char);

	int array_int[4][5] = { -5, 6, 0, 2, 2, 2, 2, 2, 9, 3, 3, 3, 2, 1, -8, 7, -2, 6, 0, 4 };

	int* cont_start_ptr = array_int;
	int* cont_end_ptr = array_int;


	max_consecutive_integers(array_int, 4, 5, &cont_start_ptr, &cont_end_ptr);

	printf_s("Address of start: %p\n", &(array_int[0][3]));
	printf_s("Address of end: %p\n", &(array_int[1][2]));

	printf_s("start: %p\n", cont_start_ptr);
	printf_s("end: %p\n", cont_end_ptr);

	int is_para = 2;
	char string_test[20] = "race car";

	is_para = is_palindrome(string_test, 8);
}
