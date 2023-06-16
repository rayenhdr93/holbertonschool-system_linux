#include "signals.h"
/**
 * main - program that prints a description of a given signal
 * @argc: argc
 * @argv: argv
 * Return: return
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
	return (1);
}
