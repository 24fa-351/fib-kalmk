#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fibonacci_iter(int times);
unsigned long long fibonacci_recur(int times);

int main(int argc, char *argv[])
{
    // First argument is an integer
    int first_arg = atoi(argv[1]);

    // Second argument is "r" or "i"
    char *temp = malloc(sizeof(argv[2]));
    strcpy(temp, argv[2]);
    char second_arg = temp[0];
    free(temp);
    
    // Third argument is a file name
    char *third_arg = malloc(sizeof(argv[3]));
    strcpy(third_arg, argv[3]);

    // Open the file
    FILE *file = fopen(third_arg, "r");

    // Read the file and get the integer
    char data[3];
    fgets(data, 3, file);
    int file_integer = atoi(data);
    
    // Add two numbers together
    int N = first_arg + file_integer;
    
    // Compute the Nth Fibonacci number according to "i" or "r"
    // Fibonacci sequence starts with 0 and 1
    if (second_arg == 'i') 
        printf("%llu\n", fibonacci_iter(N));
    else if (second_arg == 'r')
        printf("%llu\n", fibonacci_recur(N));

    fclose(file);
    free(third_arg);

    return 0;
}

unsigned long long fibonacci_iter(int times)
{
    if (times == 1)
        return 0;

    --times;

    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long next_term = t1 + t2;

    for (int i = 3; i <= times; ++i)
    {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

unsigned long long fibonacci_recur(int times)
{
    if (times == 1)
        return 0;
    else if (times == 2)
        return 1;
    else 
        return fibonacci_recur(times - 1) + fibonacci_recur(times - 2);
} 