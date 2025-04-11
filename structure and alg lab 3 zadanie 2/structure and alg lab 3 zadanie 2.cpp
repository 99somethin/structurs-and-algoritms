#include <stdio.h>
#include <stdlib.h>

struct node
{
    char arr;

    struct node *next;
    struct node *prev;
};

struct node* create(char a)
{
    struct node* first;

    first = (struct node*)malloc(sizeof(struct node)); // приведение типов и количество памяти, которое нужно выделить

    if (first == NULL)
    {
        printf("Do not have enough member.");
        exit(1);
    }

    first->arr = a;
    first->next = NULL;
    first->prev = NULL;

    return first;
}

struct node* delete_node(node* first)
{
    struct node* next, * previous;

    previous = first->prev;
    next = first->next;

    if(previous != NULL)
    previous->next = first->next;

    if(next != NULL)
    next->prev = first->prev;

    free(first);

    return previous;

}

struct node* add(node* first,char a)
{
    struct node* current, * previous;

    current = (struct node*)malloc(sizeof(struct node));

    if (current == NULL)
    {
        printf("Do not have enough member.");
        exit(1);
    }

    previous = first->next;
    first->next = current;

    current->arr = a;

    current->next = previous;
    current->prev = first;

    if (previous != NULL)
    {
        previous->prev = current;
    }

    return(current);
}

struct node* add(node* first, char a)
{
    struct node* current, * previous;

    current = (struct node*)malloc(sizeof(struct node));

    if (current == NULL)
    {
        printf("Do not have enough member.");
        exit(1);
    }

    previous = first->next;
    first->next = current;

    current->arr = a;

    current->next = previous;
    current->prev = first;

    if (previous != NULL)
    {
        previous->prev = current;
    }

    return(current);
}

void print(node* first)
{
    struct node* current;
    current = first;

    while (current)
    {
        printf("%c",current->arr);
        current = current->next;
    }
}


int main()
{
    int i = 0;
    char arr[20];

    struct node* head = create('a');
    struct node* current = add(head, 'b');


    printf("Enter your array: ");
    gets_s(arr);


    while(arr[i] != '\0')
    {
        current = add(current,arr[i]);
        i++;
    }

    print(head);

}

