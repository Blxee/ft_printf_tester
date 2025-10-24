#include "castrum/castrum.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

void test_one_char_arg(void)
{
	char *fmts[] = {"hello %c", "%c hello", "hello %c world", "%c"};
	char args[] = { 'A',        'A',        'A',			  'A'};
	char out[1024], expected[1024];
	int fd1, fd2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ASSERT_EQ(ft_dprintf(fd1, fmts[i], args[i]), dprintf(fd2, fmts[i], args[i]));
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

int main(void)
{
	RUN_TEST(test_one_char_arg);
}
