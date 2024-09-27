#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_i(int times);
int fib_r(int times);

int main(int argc, char *argv[]) {
    int index = atoi(argv[1]);
    char fib_method = argv[2][0];
    char *file_name = argv[3];

    FILE *file = fopen(file_name, "r");

    char data[3];
    fgets(data, 3, file);
    int file_integer = atoi(data);

    int N = index + file_integer;

    if (fib_method == 'i') {
        printf("%d\n", fib_i(N));
    } else if (fib_method == 'r') {
        printf("%d\n", fib_r(N));
    }

    fclose(file);

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
