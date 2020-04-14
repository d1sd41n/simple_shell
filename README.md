## Simple Shell

<a href="https://ibb.co/5KvDSFz"><img src="https://i.ibb.co/GHkw8T1/Screenshot-from-2020-04-13-18-24-37.png" alt="Screenshot-from-2020-04-13-18-24-37" border="0"></a>

## Project Overview
In this project a shell for linux is created from scratch with most of its functions, such as executing programs and commands in addition to listing files etc.

This project was written in C in order to emulate the linux sh shell and study how its background processes work.

## Installing
1- Clone this Repo

2- Compile: 
>  gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

3- Run:
>  ./hsh
## Usage
This shell behaves similarly to sh, once you have run the program, a command prompt appears where you can type and execute the command you want.

```sh
$> ls
AUTHORS    _printenv.c	_stringcomp.c  holberton.h   man_1_simple_shell
README.md  _putchar.c	_strlen.c      hsh	     print_error.c
_getenv.c  _strcat.c	_strncmp.c     int2str.c     shell.c
_memcpy.c  _strdup.c	cpath.c        linkedlist.c
$>
```
You can also run the minishell in non-interactive mode

```sh
$ echo "date" | ./hsh
Mon Apr 13 18:55:18 -05 2020
$ 
```
For more information see: [man sh](https://linux.die.net/man/1/sh)

## Authors
* Daniel Perez [https://github.com/d1sd41n](https://github.com/d1sd41n)
* Roger Rendon [https://github.com/rogerrendons](https://github.com/rogerrendons)

## license
MIT

