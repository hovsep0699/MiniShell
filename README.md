# Minishell

Minishell is a minimalistic shell implementation that mimics the functionality of a basic Unix shell. It provides a command-line interface for executing commands and managing processes.

## Features

- The shell does not interpret unclosed quotes or unspecified special characters like `\` or `;`.
- It utilizes a single global variable to store relevant information, ensuring simplicity and ease of explanation.
- Displays a prompt when waiting for a new command.
- Implements a working history feature.
- Searches and launches the appropriate executable based on the PATH variable or provided relative/absolute path.
- Supports the following built-in commands:
  - `echo` with the `-n` option
  - `cd` with only a relative or absolute path
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options
- Supports quoting functionality:
  - `'` inhibits interpretation of a sequence of characters.
  - `"` inhibits interpretation of a sequence of characters except for `$`.
- Implements redirections:
  - `<` redirects input.
  - `>` redirects output.
  - `<<` reads input from the current source until a line containing only the delimiter is seen (does not update history).
  - `>>` redirects output with append mode.
- Implements pipes (`|`) for connecting the output of one command to the input of the next.
- Expands environment variables (`$` followed by characters) to their respective values.
- `$?` expands to the exit status of the most recently executed foreground pipeline.
- Supports the following keyboard shortcuts when running interactively:
  - `ctrl-C` prints a new prompt on a new line.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.

## Installation

To use Minishell, follow these steps:

Clone the Minishell repository:

```bash
git clone https://github.com/Hoso1999/Minishell.git && cd Minishell
```
### Compile Project
```bash
make && ./bin/minishell
```
### Examples
#### ls
```bash
sh$> ls
Makefile  README.md  bin  compile  includes  libs  objects  sources  subject.pdf
sh$>
```
#### pwd
```bash
sh$> pwd
/home/hohayrap/MiniShell
sh$>
```
#### heredoc
```bash
sh$> cat<<w << g
>dsadsafds
>dsadsafdds
>vv
>w
>dsadsadfcds
>dsadsadsadsadsadsadsasadsadsa
>g
dsadsadfcds
dsadsadsadsadsadsadsasadsadsa
sh$>
```
#### $?
```bash
sh$> grep
Usage: grep [OPTION]... PATTERNS [FILE]...
Try 'grep --help' for more information.
sh$> echo $?
2
sh$>
```
#### pipes
```bash
sh$> ls | grep Makefile 
Makefile
sh$> 
```
#### redirections
```bash
sh$> ls | grep Makefile > f
sh$> cat f
Makefile
sh$> 
```
```bash
sh$> ls | grep Makefile > f
sh$> ls | grep bin >> f
sh$> cat f
Makefile
bin
sh$> 
```
