<h1 align="center">
	42 Cursus' Minishell
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' minishell project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://www.42courses.com/"><b>42cursus repo</b></a>.
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="#-study-summary">Study Summary</a>
</h3>

---


## 🤷🏻 About

> _Minishell is a simple UNIX-like command-line shell implementation . This project aims to introduce students to the fundamentals of operating systems and processes by developing a basic shell application._

For detailed information, refer to the [**subject of this project**](https://github.com/hovhannisyangevorg/Minishell/blob/main/en.subject.pdf).

	🚀 TLDR: this project consists of coding a basic shell.


## 📑 Index

`@root`

* [**📁 Include:**](Include/) 		Contains the program's headers.
* [**📁 Readline:**](Readline/) 	Contains the program's Readline library for Linux and MacOS.
* [**📁 Libft:**](Libft/) 		Contains the source code of the `libft` library, which is used in the program.
* [**📁 Src:**](Src/) 			Contains the source code of the program.
* [**📄 Makefile**](Makefile)   	Contains instructions for compiling the program and testing it.
* [**📄 Makefile.mk**](MakeFile.mk)   	Contains a header file for the makefile.
* [**🎭 en.subject.pdf**](MakeFile.mk)  Contains the subject file for the Minishell.


Note: program covers only mandatory requirements of the project's subject.


## 🛠️ Usage

### Requirements

The program is written in C language for **Linux** distributions and thus needs the **` CC ` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd Minishell
```
```shell
$ make Readline
```
```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```shell
$ ./minishell
```


## 🔗 Useful Links

* [The Linux Programming Interface](https://sciencesoftcode.files.wordpress.com/2018/12/the-linux-programming-interface-michael-kerrisk-1.pdf)
* [AST - Abstract syntax tree data structure](https://en.wikipedia.org/wiki/Abstract_syntax_tree)
* [Harm-Smits' 42 Docs - minishell](https://harm-smits.github.io/42docs/projects/minishell)
* [The Open Group Base Specifications - Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
* [Introduction to Systems Programming: a Hands-on Approach - Chapter 5. Writing Your Own Shell ](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)


## 😎 Study Summary

### Definition

**TLDR:** The shell is a command language interpreter. - [_Source_](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)

> The UNIX shell program interprets user commands, which are either directly entered by the user, or which can be read from a file called the shell script or shell program. Shell scripts are interpreted, not compiled. The shell reads commands from the script line per line and searches for those commands on the system, while a compiler converts a program into machine readable form, an executable file - which may then be used in a shell script.
>
> Apart from passing commands to the kernel, the main task of a shell is providing a user environment, which can be configured individually using shell resource configuration files. - [_Source_](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_01_01.html)

* [**Shell types**](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_01_01.html) (sh, bash, etc)
