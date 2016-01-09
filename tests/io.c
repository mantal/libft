#include <io.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int		main(void)
{
	int		fd = open("./io.test", O_RDWR | O_CREAT, S_IRWXU);

	write(fd, "12345678", 8);
	close(fd);
	char	*s = io_map_file(ft_open("./io.test", O_RDWR), PROT_READ | PROT_WRITE);
	char	msg[] = "patate";
	memcpy(s, msg, 6);
	io_unmap_file(s);
	return (0);
}
