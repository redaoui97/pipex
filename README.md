<h3>Random infos: </h3>
Notes: (some can vaguely relate to processes but to linux)
+Memory mapping : In linux kernel it is possible to map kernel address space to a user address space. This eliminates the overhead of copying user space information into the kernel space and vice versa. This can be done through a device driver and the user space device interface (/dev).
The basic unit for virtual memory manageemnt is a page, which size is usually 4K, Whenever we work with virtual memory we work with two types of addresses (virtual and physical). All CUP access (including from KERNEL space) uses virtual addresses that are translated by the MMU into physical addresses with the help of page tables. (Private virtyal memory address space managed by process) 
<img src="./learning_materials/mmu.png">
+Page tables : 
<img src="./learning_materials/page.png">
+MMU : (memory management unit) is used to translate virtual addresses into physical ones, is there mmu in each abstraction level? 
+memory metadata : 
+inodes : (index node) is a data structure that describes the objects of file systems, which includes files and directories. An inode contians a record of file and directory location in the file system, their names, owner account, and persmissions. This information is called metadata and is significant for the inenr functioning of the Linux operating system.
<ul>
Inode contents:
	<li>Device ID: Unique identifier of the device that contains the file.</li>
	<li>User ID: Identifier of hte user that owns the file. </li>
	<li>Group ID: Identifier of the filegroup that owns the file</li>
	<li>File size: Size of the file in the number of butes and blocks allocated to the file.</li>
	<li>Access permissions: Read, write and execute permissions</li>
	<li>Owner/Group: The user and group owners</lI>
	<li>File location: Physical location of the file on the disk</li>
	<li>Timestamps: Different timestamps to indicate inode creation time (ctime), modification time (mtime), and last access time (atime) </li> 
</ul>
+tty : virtual tty (teletypewriter) is a subsystem in Linux that makes process management, line editing and session management possible at the kernel level through tty drivers. The interaction between the tty and shell is called pseudo-tty
ext4 filesystem: Linux file system originally made for Minix OS
+linking: there are two types of links (soft links, hard links) to a file. a soft link(symbolic link) acts as a pointer or a reference to the file name, as it doesn't access the data in the original file. a hard link acts as a copy of the original file

************************************************************************************************************************************************************************************************************************************************************
Parts: (from the GNU C library documentation)<br>
<a href="#processes">1-Unix processes in C</a><br>
<a href="#threads">2-Threads</a><br>
<a href="#pipes">3-Pipes ad FIFOs</a><br>
<a href="#redirection">4-Redirection</a><br>
------------------------------

<h4 id="processes">1-UNIX processes in C: </h4>
<p>
Processes are the primitive units for allocation of system resources. each process has its own address space and usually one thread of control. A process executes a program; you can have multiple processes executing the same program, but each process has its own copy of the program within its own address space and executes it independently of the other copies.
Processes are organized hierarchically, each process has a parent process which explicitly arranged to create it. The process created by a given parent are called child processes. A child inherits many of its attributes from the parent process.
+How can a program create a child process.
+How can a program terminate a child process.
+How can a program control a child process.
	-Process creation concept: A new process is created when one of the functions (posix_spawn, fork, _fork, vfork) is called
</p>
<h4 id="pipes">3-Pipes and FIFOs: </h4>
A pipe is a mechanism for interprocess communication; data written to the pipe by one process can be read by another process. The data is handled in a first-in first-out (FIFO) order. The pipe has no name; it is create for noe use and both ends must be inhereted from the single process which created the pipe.<br>
A FIFO special file is similar to a pipe, but instad of being anonymous, temporary connection, a FIFO has a name. Processes open the FIFO by name in order to communicate through it.<br>
<h4 id="redirection">4-Stream Redirection:</h4>
Before the C shell executed a command, it scans the command line for redirection characters. These special notations direct the shell to redirect input and output.<br>
Overwrite : > (standard output) | < (standard input) | 2> (standard error)<br>
Append	  : >> (standard output) | << (standard input) | 2>> (standard error)<br>
You can redirect the standard input and output of a command with the following statements:<br>
<ul>
	<li>< File: Opens the File as the standard input</li>
	<li><< Word: (HEREDOC) Reads the shell input up to the line that matches the value of the Word variable. The result text is placed in an anonymous temporary file, which is given to the command as standard input.</li>
	<li>> File: Uses the specified File as tandard output, if File doesn't exist, it is created, otherwise it gets truncated and its previous content is lose</li>
	<li>>!File: Uses the specified File as tandard output. the ! is used to suppress the noclobber option that disables file truncation with > </li>
	<li>>& File: Uses the specified File as tandard output. The & redirects both stdout and stderr to the specified file</li>
	<li>>&! File: combination of >& File and >! File</li>
</ul>
-----------------------------------------------------<br>
Project: Allowed function: <br>
-perror: (void perror (const char *str)), prints a descriptive eror message to stderr <br>
-----------------------------------------------------<br>
-strerror: (char *strerror(int errnum)), accepts an error number argument ernum and returns a pointer to the corresponding message string <br>
-----------------------------------------------------<br>
-access: (int access(const char *path, int amode)), checks if the process has the rights to access the file from the path, using some arguments (F_OK: file exists, R_OK: can be accessed for reading, W_OK: can be accessed for writing, X_OK: can be accessed for execution) <br>
-----------------------------------------------------<br>
-dup: (int dup(int oldfd)), creates a copy of the file descriptor (uses the lowest numbered unused descriptor for fd)<br>
-----------------------------------------------------<br>
-dup2: (int dup2(int oldfd, int newfd)), similar to dup but instead of giving the lowest available descriptor it uses the descriptor number specified by the user<br>
-----------------------------------------------------<br>
-execve: int execve(const char *file, char *const argv[], char *const envp[]), transforms the calling process into a new process(ends the current program but not process and start a new one. Ofc the process still has the same PID). <a href="https://www.youtube.com/watch?v=iq7puCxsgHQ" target="_blank">check this video</a><br>
-----------------------------------------------------<br>
-fork: (pid_t fork(void)), Creates a new process called child process, that runs concurrently with the parent process (current or calling process). After the call of the fork function both processes will executed the following instructions<br>
-----------------------------------------------------<br>
-pipe: (int pipe(int pipefd[2])) : creates a pipe (a way to connect the output of one program to the input of another one without use of temporary files) <br> 
-----------------------------------------------------<br>
-unlink: (int unlink(const char *pathname)) : deletes a name fromthe filesystem. if that name was last likn to a file and no processs have the file open, the file is deleted and the sapce it was using is made available for reuse <br>
-----------------------------------------------------<br>
-wait: (pid_t wait(int *wstatus)) : blocks the calling process until one of its child processes exits or a signal to terminatex is received.<br>
-----------------------------------------------------<br>
-waitpid (pid_t waitpid(pid_t pid, int *wstatus, int options)): Parent process waits for the child process to finish<br>
----------------------------------------------------------------------<br>
----------------------------------------------------------------------<br>