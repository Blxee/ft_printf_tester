/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:54:23 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/07 11:57:38 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "castrum/castrum.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

void test_str(void)
{
	char *fmts[] = { "%s",    "hello %s", "%s hello", "hello %s world", "%s  ",  "  %s",     "hello %s", "%s hello", "%s", "%s%s",  "hello %s %s", "%s %s hello", "hello %s %s world", "%s%s  ",  "  %s%s",     "hello %s %s", "%s %s hello", "%s%s", "%s%s%s", "hello %s from %s far %s!"};
	char *args1[] = {"world", "",         "world",    "world",          "world", "world",    NULL,       NULL,       NULL, "world", "world",       "world",       "world",             "world",   "world",      NULL,          "hey",         NULL,   "hello",  "world"};
	char *args2[] = {NULL,    NULL,       NULL,       NULL,             NULL,    NULL,       NULL,       NULL,       NULL, "hey",   "",            "hey",         "hey",               "hey",     "hey",        "hey",         NULL,          NULL,   "world",  "somewhere"};
	char *args3[] = {NULL,    NULL,       NULL,       NULL,             NULL,    NULL,       NULL,       NULL,       NULL, NULL,    NULL,          NULL,          NULL,                NULL,      NULL,         NULL,          NULL,          NULL,   "hey",    "away"};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_char(void)
{
	char *fmts[] = {"hello %c", "%c hello", "hello %c world", "%c", "hello %c%c", "%c%c hello", "%c hello %c", "  %c  %c  ", "%c%c%%c", "hello %c from %c far %c away"};
	char args1[] = {'A',        'A',        'A',			  'A',  'A',          'A',          'A',		   'A',          'A',       'A',};
	char args2[] = {0,          0,          0,			      0,    'B',          'B',          'B',	       'B',          'B',       'B',};
	char args3[] = {0,          0,          0,			      0,    0,            0,            0,			   0,            'C',       'C',};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_pointer(void)
{
	char *fmts[] = { "%p",         "hello %p",   "%p hello",   "hello %p world", "  %p  ",     "%p", "hello %p", "%p hello", "hello %p world", "  %p  ", "%p%p",       "hello %p %p", "%p %p hello", "%p hello %p", "%p%p%p",     "hello %p from %p far %p away", "hello %p%p%p", "%p%p%p hello", " %p_%p %p_",  "%p%p%p", " %p hi %phi%phi"};
	void *args1[] = {&(char){'A'}, &(char){'A'}, &(char){'A'}, &(char){'A'},     &(char){'A'}, NULL, NULL,       NULL,       NULL,             NULL,     &(char){'A'}, &(char){'A'},  &(char){'A'},  &(char){'A'},  &(char){'A'}, &(char){'A'},                   &(char){'A'},   &(char){'A'},   &(char){'A'},  NULL,     NULL};
	void *args2[] = {NULL,         NULL,         NULL,         NULL,             NULL,         NULL, NULL,       NULL,       NULL,             NULL,     &(char){'A'}, &(char){'A'},  &(char){'A'},  &(char){'A'},  &(char){'A'}, &(char){'A'},                   &(char){'A'},   &(char){'A'},   &(char){'A'},  NULL,     NULL};
	void *args3[] = {NULL,         NULL,         NULL,         NULL,             NULL,         NULL, NULL,       NULL,       NULL,             NULL,     NULL,         NULL,          NULL,          NULL,          &(char){'A'}, &(char){'A'},                   &(char){'A'},   &(char){'A'},   &(char){'A'},  NULL,     NULL};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_decimal(void)
{
	char *fmts[] = {"%d", "%d", "%d", "%d",        "%d",       "hello %d", "hello %d", "hello %d", "hello %d",  "hello %d", "%d hello", "%d hello", "%d hello", "%d hello",  "%d hello", "hello %d world", "hello %d world", "hello %d world", "hello %d world", "hello %d world", "%d%d",      "hello %d %d", "%d %d hello", "hello %d from %d far", " %d  %d ",  "%d%d%d",   "hello %d from %d far %d place", "he%dll%do%do"};
	int args1[] = { 123,  -123, 0,    -2147483648, 2147483647, 123,        -123,       0,          -2147483648, 2147483647, 123,        -123,       0,          -2147483648, 2147483647, 123,              -123,             0,                -2147483648,      2147483647,       123,         -123,          0,             2147483647,             -2147483648, 123,        0,                               -123};
	int args2[] = {0,     0,    0,    0,           0,          0,          0,          0,          0,           0,          0,          0,          0,          0,           0,          0,                0,                0,                0,                0,                -2147483648, 0,             2147483647,    123,                    -123,        -123,       -2147483648,                     0};
	int args3[] = {0,     0,    0,    0,           0,          0,          0,          0,          0,           0,          0,          0,          0,          0,           0,          0,                0,                0,                0,                0,                0,           0,             0,             0,                      0,           2147483647, 123,                             2147483647};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_unsigned(void)
{
	char *fmts[] = {"%d", "%d", "%d", "%d",        "%d",       "hello %d", "hello %d", "hello %d", "hello %d",  "hello %d", "%d hello", "%d hello", "%d hello", "%d hello",  "%d hello", "hello %d world", "hello %d world", "hello %d world", "hello %d world", "hello %d world", "%d%d",      "hello %d %d", "%d %d hello", "hello %d from %d far", " %d  %d ",  "%d%d%d",   "hello %d from %d far %d place", "he%dll%do%do"};
	int args1[] = { 123,  -123, 0,    -2147483648, 2147483647, 123,        -123,       0,          -2147483648, 2147483647, 123,        -123,       0,          -2147483648, 2147483647, 123,              -123,             0,                -2147483648,      2147483647,       123,         -123,          0,             2147483647,             -2147483648, 123,        0,                               -123};
	int args2[] = {0,     0,    0,    0,           0,          0,          0,          0,          0,           0,          0,          0,          0,          0,           0,          0,                0,                0,                0,                0,                -2147483648, 0,             2147483647,    123,                    -123,        -123,       -2147483648,                     0};
	int args3[] = {0,     0,    0,    0,           0,          0,          0,          0,          0,           0,          0,          0,          0,          0,           0,          0,                0,                0,                0,                0,                0,           0,             0,             0,                      0,           2147483647, 123,                             2147483647};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_hex_lower(void) {
	char *fmts[] = {       "%x", "%x", "%x", "%x",       "hello %x", "%x hello", "hello %x world", " %x  ", "%x%x",     "%x%x", "%x%x", "%x%x",     "%x%x%x",   "hello %x from %x far %x away", "%x %x %x hello", "hello %x %x %x", "hel%xll%xo%xoo"};
	unsigned int args1[] = {123,  -123, 0,   4294967295, 123,        0,          4294967295,       -123,    0,          123,    123,    4294967295, 123,        -123,                           1,                -1,               123};
	unsigned int args2[] = {0,    0,    0,   0,          0,          0,          0,                0,       4294967295, -123,   0,      123,        0,          123,                            4294967295,       0,                12399};
	unsigned int args3[] = {0,    0,    0,   0,          0,          0,          0,                0,       0,          0,      0,      0,          4294967295, 0,                              -123,             123,              10};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_hex_upper(void)
{
	char *fmts[] = {       "%X", "%X", "%X", "%X",       "hello %X", "%X hello", "hello %X world", " %X  ", "%X%X",     "%X%X", "%X%X", "%X%X",     "%X%X%X",   "hello %X from %X far %X away", "%X %X %X hello", "hello %X %X %X", "hel%Xll%Xo%Xoo"};
	unsigned int args1[] = {123,  -123, 0,   4294967295, 123,        0,          4294967295,       -123,    0,          123,    123,    4294967295, 123,        -123,                           1,                -1,               123};
	unsigned int args2[] = {0,    0,    0,   0,          0,          0,          0,                0,       4294967295, -123,   0,      123,        0,          123,                            4294967295,       0,                12399};
	unsigned int args3[] = {0,    0,    0,   0,          0,          0,          0,                0,       0,          0,      0,      0,          4294967295, 0,                              -123,             123,              10};
	char out[1024], expected[1024];
	int fd1, fd2;
	int ret1, ret2;

	for (int i = 0; i < sizeof(fmts) / sizeof(*fmts); i++)
	{
		// TEST_INFO(fmts[i]);
		fd1 = open("/tmp/test_ft_printf1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open("/tmp/test_ft_printf2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ret1 = ft_dprintf(fd1, fmts[i], args1[i], args2[i], args3[i]);
		ret2 = dprintf(fd2, fmts[i], args1[i], args2[i], args3[i]);
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

void test_percent(void)
{
	char *fmts[] = {"%%", "hello %%", "%% hello", "he%%llo", "%%%%", "%% %% %%", "%%%%%%"};
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
	RUN_TEST(test_char);
	RUN_TEST(test_str);
	RUN_TEST(test_decimal);
	RUN_TEST(test_unsigned);
	RUN_TEST(test_pointer);
	RUN_TEST(test_hex_lower);
	RUN_TEST(test_hex_upper);
	RUN_TEST(test_percent);
}
