#include <stdio.h>
#include "sample.h"

int main(int argc, char **argv)
{
	Sample s;
	if (s.sample(3) != 4)
	{
		goto fail;
	}

	if (s.sample(4) != 4)
	{
		goto fail;
	}

	if (s.sample(0) != 0)
	{
		goto fail;
	}

	if (s.sample(-1) != 1)
	{
		goto fail;
	}

	printf("Success!\n");
	return 0;
fail:
	fprintf(stderr, "Failed test!\n");
	return -1;
}