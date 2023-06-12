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
 * handle_sigaction - function that set a handler for the signal SIGINT
 * Return: return 0 on success, or -1 on error
*/
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = &handle;
	return (sigaction(SIGINT, &sa, NULL));
}