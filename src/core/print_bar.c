#include "rt.h"

void	print_bar(char c)
{
	static int	test;

	if (!test)
		test = 0;
	if (test >= 0 && test <= 9)
		write(1, "\033[0;34m", 8);
	if (test >= 10 && test <= 19)
		write(1, "\033[1;34m", 8);
	if (test >= 20 && test <= 29)
		write(1, "\033[0;36m", 8);
	if (test >= 30 && test <= 39)
		write(1, "\033[1;36m", 8);
	if (test >= 40 && test <= 49)
		write(1, "\033[0;32m", 8);
	if (test >= 50 && test <= 59)
		write(1, "\033[1;32m", 8);
	if (test >= 60 && test <= 69)
		write(1, "\033[0;33m", 8);
	if (test >= 70 && test <= 79)
		write(1, "\033[1;33m", 8);
	if (test >= 80 && test <= 89)
		write(1, "\033[1;31m", 8);
	if (test >= 90 && test <= 100)
		write(1, "\033[0;31m", 8);
	write(1, &c, 1);
	write(1, "\033[0m", 5);
	test++;
}
