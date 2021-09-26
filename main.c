/**
 * @file main.c
 * @author Guillaume LEMONNIER
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdarg.h>

#define TYPE_ARGUMENT   3

int main(void);

/// printf recode
void printer(char *print, ...);

/// convert integer value in char
char *convert(int value);

char *convert(int value) {
    char *string;
    int position = 0;
    for (int i = 10000; i > 0; i /= 10) {
        int stock = value / i;
        if (stock == 0) {
            string[position] = '0';
        } else if (stock == 1) {
            string[position] = '1';
        } else if (stock == 2) {
            string[position] = '2';
        } else if (stock == 3) {
            string[position] = '3';
        } else if (stock == 4) {
            string[position] = '4';
        } else if (stock == 5) {
            string[position] = '5';
        } else if (stock == 6) {
            string[position] = '6';
        } else if (stock == 7) {
            string[position] = '7';
        } else if (stock == 8) {
            string[position] = '8';
        } else if (stock == 9) {
            string[position] = '9';
        }
        position++;
        value = value - stock * i;
    }
    return string;
}

void printer(char *print, ...) {
    va_list arg;
    va_start(arg, print);

    for (int character = 0; print[character] != '\0'; character++) {
        if (print[character] != '%') {
            putchar(print[character]);
        } else {
            character++;
            char type = print[character];
            if (type == 's') {
                puts(va_arg(arg,
                char *));
            } else if (type == 'd') {
                putchar(va_arg(arg,
                int));
            } else if (type == 'f') {
                putchar(va_arg(arg,
                double));
            } else if (type == 'l') {
                character++;
                if (print[character] == 'd') {
                    putchar(va_arg(arg,
                    long int));
                } else if (print[character] == 'l') {
                    character++;
                    if (print[character] == 'd') {
                        putchar(va_arg(arg,
                        long long int));
                    }
                }
            }
        }
    }
    va_end(arg);
}

int main(void) {
    int val = 65000;
    char *text = "lol";
    float valf = 178.555;
    long int li = 8778787;
    long long int lli = 475778888;
    printer("oui oui oui\nint = %d\nstring = %sfloat = %f\nlong int = %ld\nlong long int = %lld \n", val, text, valf,
            li, lli);
    return 0;
}