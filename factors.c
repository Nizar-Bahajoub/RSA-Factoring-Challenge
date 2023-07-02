#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE *file;
	char line[1024];
	unsigned long long a, small_fac = 1;
	unsigned long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: file can't open %s", argv[1]);
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		num = strtoull(line, NULL, 10);
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
		printf("%llu = %llu * %llu\n", num, num / small_fac, small_fac);
	}
	fclose(file);
	return (0);
}
