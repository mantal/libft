#include "libft.h"
#include <stdio.h>

int main()
{
	t_map *map = map_new();

	map_insert(map, "test", (int[]) { 17 });
	map_insert(map, "key", "value");

	printf("%s: %d\n", "test", *(int *)map_get(map, "test"));
	printf("%s: %s\n", "key", map_get(map, "key"));

	map_remove(map, "test");
	map_set(map, "key", "notvalue");

	printf("%s: %s\n", "test", map_get(map, "test"));
	printf("%s: %s\n", "key", map_get(map, "key"));

	map_free(map);
}
