#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_i(int times);
int fib_r(int times);

int main(int argc, char *argv[]) {
    int first_arg = atoi(argv[1]);

    char *temp = malloc(sizeof(argv[2]));
    strcpy(temp, argv[2]);
    char second_arg = temp[0];
    free(temp);

    char *third_arg = malloc(sizeof(argv[3]));
    strcpy(third_arg, argv[3]);

    FILE *file = fopen(third_arg, "r");

    char data[3];
    fgets(data, 3, file);
    int file_integer = atoi(data);

    int N = first_arg + file_integer;

    if (second_arg == 'i') {
        printf("%d\n", fib_i(N));
    } else if (second_arg == 'r') {
        printf("%d\n", fib_r(N));
    }

    fclose(file);
    free(third_arg);

    return 0;
}

int fib_i(int times) {
    if (times == 1) {
        return 0;
    }

    if (times == 2) {
        return 1;
    }

    --times;

    int t1 = 0;
    int t2 = 1;

    int next_term = t1 + t2;

    for (int ix = 3; ix <= times; ++ix) {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

int fib_r(int times) {
    if (times == 1) {
        return 0;
    }

    if (times == 2) {
        return 1;
    }

    return fib_r(times - 1) + fib_r(times - 2);
}
