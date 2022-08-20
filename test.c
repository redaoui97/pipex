#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    pid_t   pid;
    pid_t   pid2;
    int     ends[2]; 
    char    res[100];
    char    *args[]={"ls","-la",NULL};
    char    *args2[]={"wc", "-l", NULL};
    int     output;

    // Create a pipe and error check
    if (pipe(ends) == -1)
        return (1);
    // output file 
    output = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
    // assign stdin and stdout to both ends of the pipes
    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        //child process 1
        dup2(ends[1], 1);
        close (ends[0]);
        //close the other end
        execve("/bin/ls", args,envp);
        return (0);
    }
    // Parent process
    waitpid(pid, NULL, 0); // Wait for child.
    pid2 = fork();
    if (pid2 == -1)
        return (1);
    if (pid2 == 0)
    {
        //child process 2
        //close both ends
        dup2(ends[0], 0);
        dup2(ends[1], 1);
        execve("usr/bin/wc", args2, NULL);
        return (0);
    }
    waitpid(pid2, NULL, 0);
    read(ends[0], &res, 3);
    res[3] = '\0';
    write (1, &res, 3);
    close (ends[0]);
    close (ends[1]);
    return 0;
}
