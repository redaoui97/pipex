#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	pid_t   pid;
	pid_t   pid2;
	int     ends[2];
	int		fd;
	char	file[]="/Users/rnabil/Desktop/pipex/Makefile";
	char    *args[]={"grep","printf",NULL};
	char    *args2[]={"wc", "-l", NULL};
	char	test[52];
	int     outfile;

	//Idk if I need to have NULL as the last argument for execve's 2nd arg
	// Create a pipe and error check

	//open an infile file descriptor and assigns it to stdin in the first process
		//executes the first command and terminates the first child process
		//A new child process is created taking the stdout of the pipe as stdin
		//executes the second command and stores the output in the outfile then exits
	if (pipe(ends) == -1)
		return (1);
	fd = open(file, O_RDWR);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		//child process 1
		dup2(fd, 0);
		dup2(ends[1], 1);

		close(fd);
		close (ends[0]);
		close (ends[1]);

		execve("/usr/bin/grep", args,envp);
		return (0);
	}
	// Parent process
	close (ends[1]);
	close (fd);
	pid2 = fork();
	outfile = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	printf("%d\n",outfile);
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
	{
		//child process 2
		dup2(outfile, 1);
		dup2(ends[0], 0);
		close(ends[0]);
		close(outfile);
		execve("/usr/bin/wc", args2, NULL);
		return (0);
	}
	close(outfile);
	close (ends[0]);
	waitpid(pid2, NULL, 0);
	return 0;
}
