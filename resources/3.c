#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	while ( (c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			fprintf(stderr, "output error\n");
		}
	};
	if (ferror(stdin))
	{
		fprintf(stderr, "input error \n");
	}
	exit(0);
}