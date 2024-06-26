#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
	printf("I'm child! My pid is %d.\n", getpid());
	exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
	printf("I'm parent! My pid is %d and the pid of my child is %d\n", getpid(), pid_c);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	pid_t ret;
	ret = fork(); // after call fork(), parent and child process have same memory status, but return different output.
	if (ret == -1)
		err(EXIT_FAILURE, "fork() failed!");
	if (ret == 0) {
		child();
	} else {
		parent(ret);
	}
	err(EXIT_FAILURE, "shouldn't reach here");
}
