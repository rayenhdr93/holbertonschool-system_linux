#include "signals.h"
/**
 * current_handler_sigaction - function that retrieves the current
 * handler of the signal SIGINT
 * Return:  returns a pointer to the current handler of SIGINT,
 *  or NULL on failure
*/
void (*current_handler_sigaction(void))(int){
	struct sigaction sig;

	if (sigaction(SIGINT, NULL, &sig) == -1)
		return (NULL);
	return (sig.sa_handler);
}
