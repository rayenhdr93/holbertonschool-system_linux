#include <signal.h>
/**
 * pid_exist - function that tests if a process exists, given its PID
 * @pid: pid
 * Return: return 1 if the process with the PID pid exists, or 0 otherwise
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
