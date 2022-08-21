#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	pid_t   pid;
	pid_t   pid2;
	int     ends[2]; 
	char    *args[]={"ls","-la",NULL};
	char    *args2[]={"wc", "-l", NULL};
	int     outfile;

	//Idk if I need to have NULL as the last argument for execve's 2nd arg
	// Create a pipe and error check
	if (pipe(ends) == -1)
		return (1);
	// output file 
	// assign stdin and stdout to both ends of the pipes
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		//child process 1
		dup2(ends[1], 1);
		close (ends[0]);
		close (ends[1]);
		//close the other end
		execve("/bin/ls", args,envp);
		return (0);
	}
	// Parent process
	close (ends[1]);
	pid2 = fork();
	//outfile = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
	{
		//child process 2
		//close both ends
		dup2(ends[0], 0);
		close(ends[0]);
		// dup2(outfile, 1);
		// close(outfile);
		execve("/usr/bin/wc", args2, NULL);
		return (0);
	}
	close (ends[0]);
	waitpid(pid2, NULL, 0);
	return 0;
}
