#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int		main(void)
{
	char	s1[100] = { 0 };
	char	s2[100] = { 0 };

	sprintf(s1, "%d\n%d\n%d\n", INT_MIN, 0, INT_MAX);
	sprintf(s2, "%s\n%s\n%s\n", ft_itoa(INT_MIN), ft_itoa(0), ft_itoa(INT_MAX));

	printf("ft_itoa: %s\n", strcmp(s1, s2) ? "FAILURE" : "OK");

	return 0;
}
