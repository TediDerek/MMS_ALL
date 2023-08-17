/*Направете програма, която приема следните аргументи от командния ред:
filename
N
Програмата записва N на брой цели неотрицателни 64 битови числа в бинарен файл с името filename.
Ако файл с такова име не съществува - той се създава.
Ако съществува - предишното му съдържание се трие.
Вие имате избор какви числа да запишете във файла.

Примерно извикване:
./write_numbers numbers.bin 10000
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Argc invalid\n");
    }
    char *filename = argv[1];
    uint64_t N = strtoul(argv[2], NULL, 10);

    FILE *stream = fopen(filename, "w");

    if (!stream)
    {
        perror("fopen error");
    }

    uint64_t num;
    size_t bytes_written;
    for (uint64_t i = 0; i < N; i++)
    {
        num = i;
        bytes_written = fwrite(&num, sizeof(num), 1, stream);
        if (bytes_written != 1)
        {
            perror("fwrite error");
        }
    }

    fclose(stream);
    return 0;
}