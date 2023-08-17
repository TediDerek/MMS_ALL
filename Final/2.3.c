/*Имплементирайте същото задание, само че с POSIX нишки (pthread),
 като сумирането на цифрите на числата от всеки файл се извършва в отделна нишка.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>

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

void *routine(void *arguments)
{
    FILE *stream = fopen(((Arguments *)arguments)->filename, "r");
    if (stream == NULL)
    {
        perror("An error occured: \n");
        return 1;
    }
    unsigned long sum = 0;
    unsigned long c;
    size_t bytes_read;
    while ((bytes_read = fread(&c, sizeof(c), 1, stream)) == sizeof(unsigned long))
    {
        sum += sumdigits(c);
    }
    fclose(stream);
    return (void *)&sum;
}

typedef struct args_t
{
    char *filename;
} Arguments;

int main(int argc, char *argv[])
{
    Arguments args[argc];
    char *fifo = "myfifo";
    if (mkfifo(fifo, O_CREAT) == -1)
    {
        if (errno != EEXIST)
            perror("An error occured: \n");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        pthread_t t;
        args[i].filename = argv[i];
        // args[i].name_address = argv[i]
        if (pthread_create(&t, NULL, routine, args) == -1)
        {
            perror("Error in creating the thread.\n");
            exit(1);
        }
    }

    unsigned long total_sum = 0;
    for (int i = 1; i < argc; i++)
    {
        pthread_t t;
        unsigned long *local_sum;
        if (pthread_join(&t, &local_sum) == -1)
        {
            perror("Error in creating the thread.\n");
            exit(1);
        }
        total_sum += *local_sum;
    }
    printf("The total sum is: %lu\n", total_sum);
    return 0;
}