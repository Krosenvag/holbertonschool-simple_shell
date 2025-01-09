# holbertonschool-simple_shell
## Description
`holbertonschool-simple_shell` is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them. This project is a basic implementation of a shell, similar to `sh`.
![Flowchart](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&target=blank&highlight=0000ff&edit=_blank&layers=1&nav=1&title=Flowchart.drawio.png#R%3Cmxfile%3E%3Cdiagram%20name%3D%22Page-1%22%20id%3D%2240f53R1IdqKCDzqXQH81%22%3E7Vxbc5s4FP41nmkfmpEE4vKYOGm77W62t9nd9iWDbTlmisGLoXH2168EyEYXG0K4ZZKXxAgQ4ug7t09HTIzpevcu9jarP6IFCSYILHYT43KCEAQY0H%2Bs5T5vwdjOG25jf1FcdGj46v9H%2BJ1Fa%2BovyFa4MImiIPE3YuM8CkMyT4Q2L46jO%2FGyZRSIT914t0Rp%2BDr3ArX1b3%2BRrIpWaLmHE%2B%2BJf7vij7awmZ9Ze%2Fzq4lW2K28R3ZWajKuJMY2jKMl%2FrXdTEjDpccHk9709cnY%2FspiESZ0b0J%2B76%2BsfPz5%2BmX%2B%2Bnl59%2BJlMUfCm6OWXF6TFG28TL06KESf3XA60KypyenBxt%2FIT8nXjzdmZOzrrtG2VrAN6BOlPdVT8ESROyK7UVIzyHYnWJInv6SXFWQcUErs7SNwppLoqydosLvOKOb7d93SQAv1RCOIBQkGKUKbReu2Fi5vAD8kEWd6avXU4226yN7YCOqKLhf%2BL%2FrxlP%2F1wkya8nQ6hdEqRbByl4YKw4YBepGtzUd5zaSvCdq0ehQ1VCP62ZDeFCYm9eeL%2FIkybqGUZXHTYEkW3V%2B2S7KABVOFZnQlPhaqquuHinFlCejQPvO3Wn4uCEaVIdn7yD%2Ft9houj78V17PflrnTZ5T0%2FCOm7FDe5%2FPh7dgyovS8aDvdmR8LNn0jsU4mQuGg8OlnbKI3npAacqBW7JcW96Waz%2FvjXh5vfycb417j%2B%2FH2zcbiSk4XgANS5L80t1kwtb4tJ4GVYFTyQZr6LJ3yKKMAP0LKQBC1Xgkz%2B4sVdZSsvdYS5PhcdGbLi5oJROsrgt3%2FtRyASjw2RAiArwNgcd0iF3Ul8jgR3tiniDtoNcWfZR2xj%2B7g7pc4l2M3uE7K9iYm3oO1ZE6ADyD340I4ES0qqdSQaL9yGI9GKz6gjvvwvjxnL8ltF61m67Ud2piHIztREi1CnMU5XsjMV2U2TmN01QRcs9WHjoMFjQL3bceDBfoI%2FQ9TSvXcoCc86YW1al93DvEUYhSwFWXjb1V5oJQGx9k9eQsOIMGtBwKCt2ySOfu6zN3TCv1hm2cOAs%2Fz%2BE16GHsiRS8nzIMH1wDZczyndrYx4zFF5Hst1RT2WMVbX89im1BHo1%2FNYrQc8DYOXJoFSc9RpAp5T6BwJ6rAU75iyR60dZ7tSR7Bf1Dmto65AD%2BwBO3Utljsq7NhSjoblKa9tsewKEHaMHVeDnZyrWkbZOA8gsv5NI37izTajZ8%2FpBdDc7HLqqzjP6a1lTBhd82qWLpckfl3iwPKuR0KCOVCaAQ0L5uiQhDuKgziUSnPCdO0VeK2qdZ9ULBSDbexq5ASPa1z7clLZwpbs3mjohVMqW2kxOY5GYjJlPbOMhibTkahXLGdzHZtMLdGa27YZt2rf4pSUDN7sqLWjypeIkPQC%2F5blLHMSZqnEBVNRf%2B4F58WJtb9YsNsvYkKtsDfLumKQ2rA3zmSALyb4kvWVJlFuqbOu8%2FRnGgURS1GKDGrpB4HU1IK1sC2R1tiH9BVgk0HRnrVQaY1hrYUF7LK9eAPOgNkzP64aklN85kjsiA1FZCkOpnboJUEU9ZwsPgN6%2FFERvzEu%2FyUTtbgp7ixki6ZRXt%2FpGncqS%2FGNuoXQ31IgIaBf1x44SMc82ubBgyb4hEgz%2BZ2x5NCujgLeesH2eYcB2JAIOWvoMEAlS%2BbRmr0jM0lMDbI8i%2F6csEqirNRjqy3roOc%2FnX97X7e0o89lEQDPRHWxNeqCuBkqyx3KPEZ7gtcxDc%2FA23FrW52uOaNydxYS3V3jdM2yJb%2FZc7rG36MEPJ8VFdGnpmuSjdSnGg7KBJZ4MCPLiNsHP6R2dHHCH9ZYvPPieVHdiOx2NN6wRDNradby%2BnWP6GHkTLereSXzABqZh%2B4W7LjWV9cojSsaNuyWzIOJBjYPuizsJY6TDAySp9t2ho3jUIdLrUJgcGbjCuXXmpl9TNL2ehnW0L9PgLVBEmtjyWpem7WRihphzaJGigTvvnRZoV3HBwzE57g2ODku%2BXrubg8gz0fQrvHSJaHPIKjmZqU6qLZGpQVyOmw3XTY2TRFttlyr%2BWAtaNuvGmrY%2FSVlSXOyooi7XWUgjdM5e6lZGiR%2BSIcxzZPuPB1Xcu4iHZ9wjopOWsL6WZP1jMRZDJ%2BtSIfeWmGwomXpgaPL2E05RwJYca%2F7MnAhX0ddrUIbagC%2FiSlYbkj469VrzezQiIPqGbULI93s4pjVnIhut0tnIYzR2YpU%2FbqdY0FPVczTg%2BnmAByJ6bYl%2Bt9uuivDkQIFu7tdGXq5qjXKL8vXyvK1NNuWOXC%2BY%2FS0WFiTH4GTh%2BVIR6fkiaUxrhzANbUCrpQPKcR7S2mMa%2Bqfc3RcchoDe0hjjPaT%2BV7rn0e2Ur3n4vi2XtnD1KbuMT4zIXaAjS0ADalU1YLgzDGhi0zDdSyEUb9uTFf1%2FOLGTi%2Bbu5p1gX7d2ChWAZtr%2BtgW6aDNqsaEKZarmGorOxSxAkHP2xhMXT70wsRLKi0bd91SX68qbaocZEYUsOlY5ffnhMzA%2Bb%2F8sYu9RCrq%2FNv42oVecJ3ZwnL%2BX7US0SkD8LjPMnBkjcXYStu8mheeyhWsPe%2F54eMePHTSKb2I6Db0HhyZtop9zp0ZTKwrjXjxc4qfE8MRNPSKM1bDk6sdmacJW4nYL00M7OTkgP8QxA1WCYR1fONwbk5irlB3TDfWFLo%2FAYpLtpeHD%2Fc91M9BIC1r1SzteSjHBYFcEwDM0yyXMjK3B5YLj2K%2FR7t41l84rkV3C0g2ETbd6K%2BkyFD2Nl1HbipR%2BoUkaRzqNgf3%2F0k8dCbLR%2FcxIz4d%2FXjt7ipkaqtcqT7GNJDof4DhVDig5pv%2BHldwygvNRqLFcomE25TUNp2KjrrW4RrE9Uv4b0qBrDN4%2BK%2ByNYQajXhws2vKhYqa%2FNZxVUl1xmtx7%2Fpk45y6H1iwxlWhYmAZCE5DCykjCkgdDV5caKkUSpzFQWw2cq2kKfkIPhOMlMykw42r9PDwCfFc1IcvsRtX%2FwM%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)
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
