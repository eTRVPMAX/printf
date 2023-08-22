#include "main.h"

/**
 * writeBuffer - Writes the contents of the output buffer to stdout.
 * @output: Pointer to the OutputBuffer structure.
 */
void writeBuffer(OutputBuffer *output) {
    write(1, output->buffer, output->index);
    output->index = 0;
}

/**
 * addToBuffer - Adds a character to the output buffer.
 * @output: Pointer to the OutputBuffer structure.
 * @c: Character to be added to the buffer.
 */
void addToBuffer(OutputBuffer *output, char c) {
    if (c != -1) {
        output->buffer[output->index] = c;
        output->index++;

        if (output->index >= BUFFER_SIZE) {
            writeBuffer(output);
        }
    } else {
        writeBuffer(output);
    }
}

/**
 * _putchar - Writes a character to the output.
 * @c: Character to print.
 * Return: 1 On success.
 */
int _putchar(char c) {
    static OutputBuffer output = {{0}, 0};
    addToBuffer(&output, c);
    return (1);
}
/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str) {
    register int count = 0;
    while (str[count] != '\0') {
        _putchar(str[count]);
        count++;
    }
    return (count);
}

