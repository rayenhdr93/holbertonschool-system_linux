#include "signals.h"
/**
 * handle - handle
 * @signal: signal
 */
void handle(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}
/**
 * handle_signal - function that set a handle for the signal SIGINT
 * Return: return 0 on success, or -1 on error
*/
int handle_signal(void)
{
	if (signal(SIGINT, handle) == SIG_ERR)
		return (-1);
	return (0);
}
