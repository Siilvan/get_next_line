*This project has been created as part of the 42 curriculum by sgroenve.*

# get_next_line

## Description
The goal of this project is to make a function that reads a line from a file descriptor. The function needs to read with an user specified buffer size, it should work even if the buffer size is bigger than the length of the current line.

---

## Instructions

### Usage
This project doesnt contain a makefile, to use it you need to compile it with your target file. To choose the buffer size you need to compile with "-D BUFFER_SIZE=value", if not specified the buffer size will default to 10.

### Example
This is an example of how the project could be used.<br>
**example main.c:**
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Then create a test.txt file in the same place as the main.c. To compile run:
```bash
cc -D BUFFER_SIZE=10 main.c get_next_line.c get_next_line_utils.c
```

## Resources

### Documentation & References

*   [Stack overflow](https://stackoverflow.com/questions) - General questions.
