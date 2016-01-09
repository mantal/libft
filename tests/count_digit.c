#include "libft.h"
#include <stdio.h>

int main()
{
	printf("%d: %ld\n", 0, count_digit(0));
	printf("%d: %ld\n", 1, count_digit(1));
	printf("%d: %ld\n", 10, count_digit(10));
	printf("%d: %ld\n", 100, count_digit(100));
	printf("%d: %ld\n", 1000, count_digit(1000));
	printf("%d: %ld\n", 10000, count_digit(10000));
	printf("%d: %ld\n", 100000, count_digit(100000));

	printf("%x: %ld\n", 0, count_digit_base(0, 16));
	printf("%x: %ld\n", 1, count_digit_base(1, 16));
	printf("%x: %ld\n", 10, count_digit_base(10, 16));
	printf("%x: %ld\n", 100, count_digit_base(100, 16));
	printf("%x: %ld\n", 1000, count_digit_base(1000, 16));
	printf("%x: %ld\n", 10000, count_digit_base(10000, 16));
	printf("%x: %ld\n", 100000, count_digit_base(100000, 16));

	printf("%o: %ld\n", 0, count_digit_base(0, 8));
	printf("%o: %ld\n", 1, count_digit_base(1, 8));
	printf("%o: %ld\n", 10, count_digit_base(10, 8));
	printf("%o: %ld\n", 100, count_digit_base(100, 8));
	printf("%o: %ld\n", 1000, count_digit_base(1000, 8));
	printf("%o: %ld\n", 10000, count_digit_base(10000, 8));
	printf("%o: %ld\n", 100000, count_digit_base(100000, 8));
	return 0;
}
