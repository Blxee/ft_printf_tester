#include "castrum/castrum.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

void test_normal_str(void)
{
	char *fmts[] = {"hello %s", "%s hello", "hello %s world", "%   ",    "hello %s"};
	char *args[] = {"world",    "hey",      "there",		  "hello", NULL};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args[i]);
		ret2 = dprintf(fd2, fmts[i], args[i]);
		ASSERT_EQ(ret1, ret2);
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

void test_one_char_arg(void)
{
	char *fmts[] = {"hello %c", "%c hello", "hello %c world", "%c"};
	char args[] = { 'A',        'A',        'A',			  'A'};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args[i]);
		ret2 = dprintf(fd2, fmts[i], args[i]);
		ASSERT_EQ(ret1, ret2);
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

void test_one_pointer_arg(void)
{
	char *fmts[] = {"hello %p", "hello %p"};
	void *args[] = {0xffffffff, NULL};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args[i]);
		ret2 = dprintf(fd2, fmts[i], args[i]);
		ASSERT_EQ(ret1, ret2);
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

void test_one_int_arg(void)
{
	// char *fmts[] = { "hello %d", "hello %+d", "hello % d", "hello %0d", "hello %-d", "hello %.d", "hello %.0d", "hello %5d", "hello %-5d", "hello %05d", "hello %+5d", "hello % 5d", "hello %-+5d", "hello %- 5d", "hello %.3d", "hello %.5d", "hello %.10d", "hello %8.3d", "hello %8.5d", "hello %-8.5d", "hello %+8.5d", "hello % 8.5d", "hello %8.0d", "hello %.0d", "hello %08.0d", "value=%+10.5d end", "x=%- 10.3d y", "%+010.3d middle", "test: [% .5d]", "hello %u", "hello %05u", "hello %-5u", "hello %.5u", "hello %8.5u", "hello %08.5u", };
	// int args[] = {   0,          123,         -123,        42,          -42,         99999,       -99999,       1,           -1,           1000,         -1000,        12,           123,           4567,          -4567,        0,            987654321,     -987654321,    10,            0,              123,            -123,           255,           -255,         40000,          0,                   123,            123,               123,             123,        123,          123,          123,           -123,         2002342, };

	char *fmts[] = {"hello %d", "hello %u", "hello %d", "hello %-12d", "hello %010d", "hello %-010d", "hello %+d", "%+d hello"};
	int args[] = {  123,        123,        -123,       12,            123,           123,            123,         -123};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args[i]);
		ret2 = dprintf(fd2, fmts[i], args[i]);
		ASSERT_EQ(ret1, ret2);
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

void test_one_hex_arg(void)
{
	char *fmts[] = {"hello %x", "hello %X"};
	long args[] = { 0xffffffff, 0xffffffff};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args[i]);
		ret2 = dprintf(fd2, fmts[i], args[i]);
		ASSERT_EQ(ret1, ret2);
		close(fd1), close(fd2);
		fd1 = open("/tmp/test_ft_printf1.txt", O_RDONLY);
		fd2 = open("/tmp/test_ft_printf2.txt", O_RDONLY);
		bzero(out, 1024), bzero(expected, 1024);
		ASSERT_EQ(read(fd1, out, 1024), read(fd2, expected, 1024));
		ASSERT_STR_EQ(out, expected);
		close(fd1), close(fd2);
	}
}

void test_one_percent(void)
{
	char *fmts[] = {"hello %%", "hello %%"};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i]);
		ret2 = dprintf(fd2, fmts[i]);
		ASSERT_EQ(ret1, ret2);
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
	RUN_TEST(test_normal_str);
	RUN_TEST(test_one_int_arg);
	RUN_TEST(test_one_pointer_arg);
	RUN_TEST(test_one_hex_arg);
	RUN_TEST(test_one_percent);
}
