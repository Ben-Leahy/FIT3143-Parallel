# Task 0 – Preparation (No Marks)

a. Read the Linux Environment Setup Guidelines
b. Download and set up the Linux environment (with Docker if needed)
c. Get familiar with the Linux environment
d. Confirm gcc and Open MPI are available within your Linux installation or docker environment
(for future labs/applied sessions)
Prepare to answer the following questions.

# Task 1 – Basic Linux Operations - Finding Help and File/Directory Manipulation

1. Which text-based command provides information on the use of other Linux commands and
   utilities?
   `man`
2. List the command line for finding help on the usage of ssh?
   `man ssh`
3. How do you access Linux manual pages? List the full command line for accessing a particular
   section.
   `man <section_number> <command>`
4. List the command-lines for creating directories.
   `mkdir`
5. List the command-lines for deleting sub-directories.
   `rm -r` (Recursive delete for non-empty directories)
6. List the command-line for creating a zero-length file.
   `touch`

# Task 2 – Basic Linux Operations – Access Control

7. Set the permissions for your home directory such that no one besides yourself can read your
   home directory’s contents. List the command line.
   `chmod 700 ~`
8. What does chmod 4775 filename do?
   `chmod - change file permissions. 
4 -> run from owner privileges
7 -> owner can read, write, execute
7 -> group can read, write, execute
5 -> others can read, execute`
9. How do you set the executable permission on a file (to make it executable)? List the
   command-line.
   `chmod +x`
   10.List the command-line for inspecting the permissions assigned to a particular file “hello.c”.
   `ls -l`

# Task 3 – Linux Shell

[Hint: Read the manual pages on your shell and then answer the following questions. You can run the
command echo $SHELL in the terminal to figure out the shell you are running] 11. How do you get the last command-line re-displayed?
`up arrow`
12.Which key-stroke invokes filename completion?
`tab`
13.Locate the file in your home directory/system containing the PATH variable. What does it do?
`The variable is a list of file paths. If you want to run an executable file contained inside these file paths, then you can do it from anywhere. Otherwise, you have to be running that executable from it's parent folder or similarly expressing it's location. ie, consider the command ls, which is probably just an executable file, but we can run it from anywhere because we store it in file paths -> ls is stored in bin/ls and /bin is within PATH. `
`There are multiple files containing PATH, including: /etc/paths, ~/.zshrc, ~/.zprofile, ~/.zshenv`
14.How do you inspect its value?
`echo $PATH`
15.What does the shell function alias do?
`it allows you to have short hand for a command`
16.How does which command work?
`it shows the full path for the command you are running (they have their own heirarchy)`
17.How do you execute a program file in the shell? List the command-line.
`./file_name`
18.How are the contents of a text file displayed? List the command-line.
`nano    (if you want to edit)
cat      (to just display)`
19.List the command-line for searching all files with an extension .html on the system.
`find / -type f -name "*.html" 2>/dev/null`
`ie, find a file, name and regex expression to match, supress errors so your screen doens't fill up`

# Task 4 – Basic Networking

20.Which command can show the IP address for the ethernet card (eth0)?
`ifconfig eth0` `Then the output we want is the inet part`
21.Which command can show the Hardware address for the ethernet card (eth0)?
`ifconfig eth0` `Then the output we want is the ether part`
22.What is the function of /etc/hosts file?
`maps hostnames to IP addresses. Ie, if we had mywebsite.com we might want to map that 127.0.0 for local host. Then we can test stuff`
23.What is the function of /etc/resolv.conf?
`This maps all websites on the internet to IP addresses, this is used if your computer can't find a mapping in /etc/hosts. `
