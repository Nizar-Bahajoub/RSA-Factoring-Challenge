#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(unsigned long long num)
{
	unsigned long long i;
	if (num < 2)
		return (false);

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return (false);
	}
	return (true);
}


int main(int argc, char **argv)
{
	FILE *file;
	unsigned long long p, q, i;
	unsigned long long n;
	bool found = false;

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

	if (fscanf(file, "%llu", &n) != 1)
	{
		fprintf(stderr, "Error: Invalid number in the file\n");
		fclose(file);
		return (1);
	}

	fclose(file);

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0 && is_prime(i) && is_prime(n / i))
		{
			p = i;
			q = n / i;
			found = true;
			break;
		}
	}

	if (found)
		printf("%llu=%llu*%llu\n", n, q, p);
	else
		printf("%llu cannot be factorized into two prime numbers.\n", n);

	return (0);
}
