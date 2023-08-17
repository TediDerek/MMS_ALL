#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

typedef struct BankAccount
{
    uint16_t number;
    char name[100];
    float balance;
    char currency[4];
} BankAccount;

typedef struct Node
{
    BankAccount d;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head;
    Node *tail;
} LL;

void print_node(Node *node);
Node * maxBalance(Node* head);
double totalBalance(Node *head);
void print_linked_list(LL *ll);
void push_back(BankAccount new_data, LL *ll);
void pop_back(LL *ll, BankAccount *result);
void push_front(BankAccount new_data, LL *ll);
void pop_front(LL *ll, BankAccount *result);
LL *init_linked_list();
void deinit_linked_list(LL *ll);

#endif