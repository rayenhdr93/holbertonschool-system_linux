#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - displays the information contained in the ELF file header
 * @argc: argc
 * @argv: argv
 * @env:  env
 * Return: return
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *exe[] = {"/usr/bin/readelf", "-W", "-h", "", NULL};

	exe[3] = argv[1];
	if (execve("/usr/bin/readelf", exe, env) == 1)
	{
		return (1);
	}
	else
	{
		perror("execv");
		return (0);
	}
}
