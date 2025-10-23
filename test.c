#include "castrum/castrum.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <strings.h>

void test_no_args(void)
{
	char *fmt;
	char out[64];
	char expected[64];

	bzero(out, 64);
	bzero(expected, 64);
	fmt = "hello world";
	ft_sprintf(out, fmt);
	sprintf(expected, fmt);
	ASSERT_STR_EQ(out, expected)

	bzero(out, 64);
	bzero(expected, 64);
	fmt = "";
	ft_sprintf(out, fmt);
	sprintf(expected, fmt);
	ASSERT_STR_EQ(out, expected)
}

void test_one_char_arg(void)
{
	char *fmts[] = {"hello %c", "%c hello", "hello %c world", "%c"};
	char args[] = { 'A',        'A',        'A',			  'A'};
	char out[64];
	char expected[64];

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		bzero(out, 64);
		bzero(expected, 64);
		ft_sprintf(out, fmts[i], args[i]);
		sprintf(expected, fmts[i], args[i]);
		ASSERT_STR_EQ(out, expected)
	}
}

void test_one_str_arg(void)
{
	char *fmts[] = {"hello %s", "%s hello", "hello %s world", "%s"};
	char *args[] = {"world",      "hello",      "hey",              "hello"};
	char out[64];
	char expected[64];

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		bzero(out, 64);
		bzero(expected, 64);
		ft_sprintf(out, fmts[i], args[i]);
		sprintf(expected, fmts[i], args[i]);
		ASSERT_STR_EQ(out, expected)
	}
}

void test_one_byte_arg(void)
{
	char *fmts[] = {"hello %hhd", "%hhd hello", "hello %hhd world", "%hhd"};
	char args[] = { 123,        123,        123,              123};
	char out[64];
	char expected[64];

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		bzero(out, 64);
		bzero(expected, 64);
		ft_sprintf(out, fmts[i], args[i]);
		sprintf(expected, fmts[i], args[i]);
		ASSERT_STR_EQ(out, expected)
	}
}

void test_one_short_arg(void)
{
	char *fmts[] = {    "hello %hd", "%hd hello", "hello %hd world", "%hd"};
	short int args[] = {123,        123,        123,              123};
	char out[64];
	char expected[64];

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		bzero(out, 64);
		bzero(expected, 64);
		ft_sprintf(out, fmts[i], args[i]);
		sprintf(expected, fmts[i], args[i]);
		ASSERT_STR_EQ(out, expected)
	}
}

void test_one_int_arg(void)
{
	char *fmts[] = {"hello %d", "%d hello", "hello %d world", "%d"};
	int args[] = {  123,        123,        123,              123};
	char out[64];
	char expected[64];

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		bzero(out, 64);
		bzero(expected, 64);
		ft_sprintf(out, fmts[i], args[i]);
		sprintf(expected, fmts[i], args[i]);
		ASSERT_STR_EQ(out, expected)
	}
}

int main(void)
{
	RUN_TEST(test_no_args);
	RUN_TEST(test_one_char_arg);
	RUN_TEST(test_one_str_arg);
	RUN_TEST(test_one_byte_arg);
	RUN_TEST(test_one_short_arg);
	RUN_TEST(test_one_int_arg);
}
