#include "main.h"

/**
 * Get_sig - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void Get_sig(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
