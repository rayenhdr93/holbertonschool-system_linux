#include "signals.h"
/**
 * handle - handle
 * @numsig: numsig
 * @info: info
 * @pointer: pointer
 */
void handle(int numsig, siginfo_t *info, void *pointer)
{
	(void) numsig;
	(void) pointer;
	if (info)
	{
		printf("SIGQUIT send bu %i\n", info->si_pid);
		fflush(stdout);
	}
}
/**
 * trace_signal_sender - function that defines a handler for
 * the signal SIGQUIT (Control-\ in a shell)
 * Return: return 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;

	return (sigaction(SIGQUIT, &sa, NULL));
}
