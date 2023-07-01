#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	FILE *file;
	char line[100];
	int a, small_fac = 1;
	long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: file can't open %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 100, file) != NULL)
	{
		num = strtoll(line, NULL, 10);
		a = 2;
		while (a * a <= num)
		{
			if (num % a == 0)
			{
				small_fac = a;
				break;
			}
			a++;
		}
		if (small_fac != 1)
			printf("%lld = %lld * %d\n", num, num / small_fac, small_fac);
		else
			printf("%lld is a prime number.\n", num);
	}
	fclose(file);
	return (0);
}
