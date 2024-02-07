#include "simplelinkedlist.h"

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#include "wordcount.h"

typedef struct Node Node;

struct Node
{
    char key[STRING_LENGTH + 1];
    int count;
    Node *next;
};

Node *head = NULL;

Node *findNodeFor(char str[STRING_LENGTH + 1]);
Node *insertNewNode(char key[STRING_LENGTH + 1]);

void runSimpleLinkedList(char (*array)[STRING_LENGTH + 1])
{
    for (int i = 0; i < TOTAL_STRINGS; i++)
    {
        if (strlen(array[i]) < 3)
        {
            printf("small string at index %d: %d\n", i, array[i][0]);
        }
        Node *node = findNodeFor(array[i]);
        if (node == NULL)
        {
            insertNewNode(array[i]);
        }
        else
        {
            node->count++;
        }
    }

    initialize();

    Node *curr = head;
    while (curr != NULL)
    {
        add(curr->key, curr->count);
        curr = curr->next;
    }

    finish();
}

Node *findNodeFor(char str[STRING_LENGTH + 1])
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    while (curr->next != NULL)
    {
        if (strcmp(curr->key, str) == 0)
        {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

Node *findTail()
{
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    return curr;
}

Node *insertNewNode(char key[STRING_LENGTH + 1])
{
    Node *node = malloc(sizeof(Node));
    strcpy(node->key, key);
    node->count = 1;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Node *tail = findTail();
        tail->next = node;
    }

    return node;
}