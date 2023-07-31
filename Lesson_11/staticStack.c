#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int data;
} Data;

void init_static_stack(size_t max_el_count);
int push(Data data);
int pop(Data *data);
void printElements();

size_t capacity = 0;
size_t currIdx = 0;
Data *stack = NULL;

int main(void)
{
    int size = 3;
    init_static_stack(size);
    for (size_t i = 1; i <= size; i++)
    {
        Data currData = {i};
        push(currData);
    }
    printElements();
    free(stack);
    return 0;
}

void init_static_stack(size_t max_el_count)
{
    capacity = max_el_count;
    stack = malloc(capacity * sizeof(*stack));
}

int push(Data data)
{
    if (currIdx >= capacity)
    {
        printf("IndexOutOfRangeException: Index exceeds the stack's capacity.\n");
        return 1;
    }
    if (currIdx < 0)
    {
        printf("Index cannot be a negative number.\n");
        return 1;
    }
    *(stack + currIdx) = data;
    currIdx++;
    return 0;
}

int pop(Data *data)
{
    if (currIdx <= 0)
    {
        printf("Cannot pop out of empty stack.\n");
        return 1;
    }
    if (currIdx > capacity)
    {
        printf("IndexOutOfRangeException: Index exceeds the stack's capacity.\n");
        return 1;
    }
    data = (stack + currIdx);
    currIdx--;
    return 0;
}

void printElements()
{
    for (size_t i = 0; i < currIdx; i++)
        printf("%d ", stack[i].data);
    printf("\n");
}
