# get_next_line

This project was developed individually by:

- ipuig-pa

## Project Overview

---

This project is an implementation of `get_next_line` function, to return a line read from a file descriptor, to use in C projects. The function is designed to read text files line by line efficiently, with minimal memory usage.

## Compilation

---

Compile your program with the get_next_line function, defining the buffer size:

```bash
[ ]

bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

```

You can change the buffer size to any value. The function should work with any reasonable buffer size. If no BUFFER_SIZE is defined, it is set to 42 by default.

## Usage

---

### Function Prototype

```c
[ ]

c
char *get_next_line(int fd);

```

### Example Usage

```c
[ ]

c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);// Don't forget to free the allocated memory
    }

    close(fd);
    return (0);
}

```

### Reading from Standard Input

```c
[ ]

c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;

    printf("Enter text (Ctrl+D to exit):\n");
    while ((line = get_next_line(0)))// 0 is the file descriptor for standard input
    {
        printf("You entered: %s", line);
        free(line);
    }

    return (0);
}

```

## Features

---

- Reads text line by line from a file descriptor
- Works with files and standard input
- Returns the line including the terminating `\n` character (except at EOF with no newline)
- Returns `NULL` when there's nothing left to read or an error occurs
- Works with any buffer size defined at compilation time (Performance varies with buffer size)

### Bonus Part

- Handles multiple file descriptors simultaneously without losing track of reading position

## License

---

This project was developed as part of the curriculum at 42 School. Use of this code must comply with the school's academic integrity policies.
