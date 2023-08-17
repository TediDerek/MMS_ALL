/*Направете програма, в която се подават като аргументи от командния ред списък от имената на бинарни файлове,
в които са записани цели неотрицателни 64 битови числа. Целта на програмата е да изведе сумата на цифрите на числата
от всеки файл. Сумирането трябва да стане с цифрите от десетичния запис на числата от всеки файл.
Сумирането да се извърши като за всеки файл се създаде отделен процес. Накрая родителския процес да изведе
общата сума в stdout.

Примерно извикване:
./filesSum file1 file2 file3 file4 file5

Примерен изход:
file1 - No such file or directory
file2 - 45
file3 - 100
file4 - Permission denied
file5 - 51
Total sum of digits - 196
*/

#include <stdio.h>
#include <sys/wait.h>

unsigned long sumdigits(unsigned long num)
{
    unsigned long sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Not enough arguments.\n");
        return 1;
    }

    unsigned long total_sum = 0;
    int pid;
    for (int i = 1; i < argc; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            printf("Fork failed.\n");
            return 1;
        }
        else if (pid == 0)
        {
            FILE *stream = fopen(argv[i], "r");
            if (stream == NULL)
            {
                perror("An error occured: \n");
                return 1;
            }
            unsigned long sum = 0;
            unsigned long c;
            size_t bytes_read;
            while ((bytes_read = fread(&c, sizeof(c), 1, stream)) == 1)
            {
                sum += sumdigits(c);
            }
            total_sum += sum;
            printf("In %s the local sum is: %lu\n", argv[i], sum);
            fclose(stream);
            return 0;
        }
    }

    // main process
    for (int i = 1; i < argc; i++)
    {
        wait(NULL);
    }
    printf("Total sum of digits - %lu\n", total_sum);

    return 0;
}