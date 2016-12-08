#include <assert.h>
#include <libft.h>

int main(void)
{
	t_array	*arr;

	arr = array_new(sizeof(int), 0);
	
	array_add(arr, (int[]) { 17 });
	assert(*(int *)array_get(arr, 0) == 17);
	
	array_free(arr);
	
	int	n = 20;
	arr = array_new(sizeof(int *), 0);

	array_add(arr, (int*[]) { &n });
	assert(**(int **)array_get(arr, 0) == 20);

	return (0);
}
