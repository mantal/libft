#include "args.h"

void	foo(const char **args)
{
	printf("%s %s", args[0], args[1]);
}

int main(int argc, const char **argv)
{
	const t_option	opts[] =
	{
		{ .names = (char*[]){ "v", "verbose", (void*)0 }, .usage = "usage", .args_n = 1, .callback = &foo },
		{ }
	};

	options(&opts, argc, argv);
	return 0;
}
