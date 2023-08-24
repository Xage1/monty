#include "monty.h"

/**
 * custom_getline - Read a line from a file stream
 * @lineptr: A pointer to a buffer to store the line
 * @n: A pointer to the size of the buffer
 * @stream: The file stream to read from
 * Return: The number of characters read, or -1 on error or EOF
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    char *pos = *lineptr;
    size_t count = 0;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            return (-1);
        }
    }

    while ((c = fgetc(stream)) != EOF && c != '\n')
    {
        if (count + 1 >= *n)
        {
            size_t new_size = *n * 2;
            char *new_lineptr = (char *)realloc(*lineptr, new_size);
            if (new_lineptr == NULL)
            {
                return (-1);
            }
            pos = new_lineptr + (pos - *lineptr);
            *lineptr = new_lineptr;
            *n = new_size;
        }

        *pos++ = c;
        count++;
    }

    if (c == EOF && count == 0)
    {
        return (-1);
    }

    *pos = '\0';
    return (count);
}
