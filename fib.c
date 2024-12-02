#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_i(int times);
int fib_r(int times);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <index> <fib_method> <file_name>\n", argv[0]);
        return 1;
    }
    int index = atoi(argv[1]);
    char fib_method = argv[2][0];
    char *file_name = argv[3];

    FILE *file = fopen(file_name, "r");

    char data[100];
    fgets(data, sizeof(data), file);
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

    int prev1 = 0;
    int prev2 = 1;

    int next_term = prev1 + prev2;

    for (int ix = 3; ix <= times; ++ix) {
        prev1 = prev2;
        prev2 = next_term;
        next_term = prev1 + prev2;
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
