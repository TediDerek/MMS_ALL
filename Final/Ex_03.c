/*Да се напише програма, която чете от стандартния вход:
От първия ред се четат целите положителни числа N и M, разделени със whitespace.

От следващите N реда се четат следните данни разделени с whitespace:
Символният низ ROW
Номерът на реда
M на брой цели числа, разделени със whitespace

От последния ред се чете име на файл, в който да бъде записан резултатът.
Напишете програма, която създава N нишки - по една за всеки ред, започващ с ROW. Всяка нишка намира
средноаритметичното на съответния си ред. Накрая резултатите се записват в изходния файл.
Резултатите от всяка нишка да бъдат записани с точност от 3 символа след десетичната запетая.
Ако изходният файл не съществува - той се създава. Ако изходният файл съществува - печата се съобщение за грешка.
Нека редовете да бъдат записани в реда, в който са въведени.

Примерен вход:
5 6
ROW 1 21 14 31 -51 33 1
ROW 2 41 56 74 -21 42 -52
ROW 3 51 61 17 37 97 39
ROW 4 19 -1 85 -9 51 2
ROW 5 71 26 43 36 22 99
file1

Съдържанието на file1 след работата на програмата:
ROW 1 8.166
ROW 2 23.333
ROW 3 50.333
ROW 4 24.500
ROW 5 49.500
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct RowData
{
    int row;
    int *nums;
    int m;
    double result;

} RowData;

void *compute_mean(void *arg);

int main()
{
    int N, m;
    scanf("%d %d", &N, &m);

    RowData rows[N];
    for (int i = 0; i < N; i++)
    {
        char _tmp[4];
        scanf("%s %d", _tmp, &(rows[i].row));

        rows[i].nums = (int *)malloc(m * sizeof(int));
        rows[i].m = m;

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &(rows[i].nums[j]));
        }
    }

    char filename[100];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error: File already exists.\n");
        fclose(file);
        return 1;
    }

    pthread_t threads[N];

    for (int i = 0; i < N; i++)
    {
        if (pthread_create(&threads[i], NULL, compute_mean, &rows[i]) == -1)
        {
            perror("Error: Creating thread.\n");
            return 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (pthread_join(threads[i], NULL) == -1)
        {
            perror("Error: Joining thread.\n");
            return 2;
        }
    }

    file = fopen(filename, "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(file, "ROW %d %.3lf\n", rows[i].row, rows[i].result);
        free(rows[i].nums);
    }
    fclose(file);

    return 0;
}

void *compute_mean(void *arg)
{

    RowData *data = (RowData *)arg;
    int sum = 0;
    for (int i = 0; i < data->m; i++)
    {
        sum += data->nums[i];
    }

    data->result = (double)sum / data->m;
    return NULL;
}