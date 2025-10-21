#include "castrum/castrum.h"

void foo(void)
{
	ASSERT_FALSE(1);
}

int main(void)
{
	RUN_TEST(foo);
}
