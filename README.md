# holbertonschool-simple_shell
## Description
`holbertonschool-simple_shell` is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them. This project is a basic implementation of a shell, similar to `sh`.
![Flowchart](https://1drv.ms/i/c/6f08a3b8b0e9d3a3/EQh4hLbzOPlEsj02YH0DAekBP-itiQMXdOGRhDV85-zn7Q?e=8HhHOE)
## Features
- Execute built-in commands like `env` and `exit`.
- Execute external commands found in the system's `PATH`.
- Handle command sequences with logical operators.
- Support for input redirection and pipes.
- Error handling for invalid commands and permissions.
## Files
- `simpleshell.c`: Entry point of the shell program.
- `main.h`: Header file containing function prototypes and struct definitions.
- `command_functions.c`: Contains functions for command execution and built-in commands.
- `aux_function.c`: Contains auxiliary string manipulation functions.
- `aux_function1.c`: Contains additional auxiliary functions.
- `sup_functions.c`: Contains supplementary functions for command handling.
- `testsuit.sh`: Script for testing the shell against standard `sh`.
- `man_1_simple_shell`: Manual page for the shell.
- `README.md`: This file.
- `AUTHORS`: List of contributors to the project.
## Usage
To compile the shell, run:
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```
To start the shell, run:
```
./shell
```
## Built-in Commands
- `env`: Prints the environment variables.
- `exit`: Exits the shell.
## Examples
```
($) ./shell
($) ls
file1 file2 file3
($) echo "Hello, World!"
Hello, World!
($) exit
```
## Testing
You can use the `testsuit.sh` script to test the shell against standard `sh`. The script will compare the output of commands run in both shells. To run the test, execute:
```sh
./testsuit.sh
```
## Authors
- Herve Le Guennec - [Github](github.com/krosenvag)
- Mathieu Zucalli - [Github](github.com/matzuc2)
