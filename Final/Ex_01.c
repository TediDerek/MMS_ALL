#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

#define ITEMS_COUNT 3
char *currency_arr[] = {"BGN", "DOLLAR", "YOAN", "EURO"};
int curr_arr_size = sizeof(currency_arr) / sizeof(currency_arr[0]);

char *gen_rand_str();
void gen_bankAccount(BankAccount *ba);

int main(int argc, char *argv[])
{
    LL *ll = init_linked_list();
    for (int i = 0; i < ITEMS_COUNT; i++)
    {
        BankAccount *ba = malloc(sizeof(*ba));
        gen_bankAccount(ba);
        push_back(*ba, ll);
    }

    print_linked_list(ll);
    double total = totalBalance(ll->head);
    printf("------------\n");
    printf("Total ballance: %lf\n", total);

    Node *max_ballance_node = maxBalance(ll->head);
    print_node(max_ballance_node);

    deinit_linked_list(ll);
    free(max_ballance_node);
    return 0;
}

char *gen_rand_str()
{
    int len = 1 + rand() % 20;
    char *str = malloc(len + 1);
    str[0] = rand() % 26 + 'A';
    for (int i = 1; i < len; i++)
    {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
    return str;
}

void gen_bankAccount(BankAccount *ba)
{
    ba->number = rand() % UINT16_MAX;
    int num_words = 2 + rand() % 4;

    for (int i = 0; i < num_words; i++)
    {
        char *curr_str = gen_rand_str();
        strcat(ba->name, curr_str);
        free(curr_str);
    }

    ba->balance = (rand() % 10000) / 100;

    int currency_len = rand() % 4;

    for (int i = 0; i < currency_len; i++)
    {
        char *cur = currency_arr[rand() % curr_arr_size];
        strcat(ba->currency, cur);
    }
}