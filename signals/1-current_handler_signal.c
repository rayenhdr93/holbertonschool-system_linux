#include "signals.h"
/**
 * current_handler_signal - function that retrieves the
 * current handler of the signal SIGINT
 * Return: returns a pointer to the current handle
 *  of SIGINT, or NULL on failure
*/
void (*current_handler_signal(void))(int)
{
	void (*current)(int) = NULL;

	current = signal(SIGINT, NULL);
	signal(SIGINT, current);
	return (current);
}
