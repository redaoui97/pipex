<h3>Random infos</h3>
Notes: (some can vaguely relate to processes but to linux)
+Memory mapping : In linux kernel it is possible to map kernel address space to a user address space. This eliminates the overhead of copying user space information into the kernel space and vice versa. This can be done through a device driver and the user space device interface (/dev).
The basic unit for virtual memory manageemnt is a page, which size is usually 4K, Whenever we work with virtual memory we work with two types of addresses (virtual and physical). All CUP access (including from KERNEL space) uses virtual addresses that are translated by the MMU into physical addresses with the help of page tables. (Private virtyal memory address space managed by process) 
<img src="learning_materials/mmu.png">
+Page tables : 
<img src="learning_materials/page.png">
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

************************************************************************************************************************************************************************************************************************************************************
Parts: (from the GNU C library documentation)
1-Unix processes in C
2-Threads
3-Pipes ad FIFOs
------------------------------

1-UNIX processes in C: 
<p>
Processes are the primitive units for allocation of system resources. each process has its own address space and usually one thread of control. A process executes a program; you can have multiple processes executing the same program, but each process has its own copy of the program within its own address space and executes it independently of the other copies.
Processes are organized hierarchically, each process has a parent process which explicitly arranged to create it. The process created by a given parent are called child processes. A child inherits many of its attributes from the parent process.
+How can a program create a child process.
+How can a program terminate a child process.
+How can a program control a child process.
	-Process creation concept: A new process is created when one of the functions (posix_spawn, fork, _fork, vfork) is called
</p>
------------------------------------------------------------------------------------------------------------------------------

Project: 
Allowed function: <br>
-perror: prints a descriptive eror message to stderr <br>
-strerror:accepts an error number argument ernum and returns a pointer to the corresponding message string <br>
-access: <br>
-dup: <br>
-dup2: <br>
-execve: <br>
-fork: <br>
-pipe: <br>
-unlink: <br>
-wait: <br>
-waitpid: <br>
