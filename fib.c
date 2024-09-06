#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci_iter(int times);
int fibonacci_recur(int times);

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
        printf("%d\n", fibonacci_iter(N));
    else if (second_arg == 'r')
        printf("%d\n", fibonacci_recur(N));

    fclose(file);
    free(third_arg);

    return 0;
}

int fibonacci_iter(int times)
{
    if (times == 1)
        return 0;

    --times;

    int t1 = 0;
    int t2 = 1;
    int next_term = t1 + t2;

    for (int i = 3; i <= times; ++i)
    {
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return next_term;
}

int fibonacci_recur(int times)
{
    if (times == 1)
        return 0;
    else if (times == 2)
        return 1;
    else 
        return fibonacci_recur(times - 1) + fibonacci_recur(times - 2);
} 