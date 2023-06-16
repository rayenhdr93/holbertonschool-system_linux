#include "signals.h"
/**
 * handle_sig - handle sig
 * @numsig: numsig
 */
void handle_sig(int numsig)
{
	printf("Caught %d\n", numsig);
}
/**
 * main - program that sets a handler for the signal SIGINT,
 * and exits right after the signal is received and handled
 * Return: return
 */
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = &handle_sig;
	sigaction(SIGINT, &sa, NULL);
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
