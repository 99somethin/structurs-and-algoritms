#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char arr;

    struct Node* next;
};


struct Node* newNode(int data, struct Node* nextNode)
{
    
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Out of member");
        exit(0);
    }

    node->arr = data;


    node->next = nextNode;

    return node;
}


struct Node* constructList(char arr[], int n)
{
    struct Node* head = NULL, * node = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        node = newNode(arr[i], node);
        head = node;
    }

    return head;
}

void printList(struct Node* head)
{
    int count = 0, fl = 0;
    

    struct Node* ptr = head;

    while (ptr)
    {
        if (ptr->arr == 'e')
        {
            count++;
            if (count == 5)
            {
                fl++;
                break;
            }

        }
        else
        {
            count = 0;
        }

        ptr = ptr->next;

        if (ptr->arr == '\0')
        {
            break;
        }
    }

    if (fl == 0)
    {
        printf("\nThe array hasn't 5 'e' in line.\n");
    }
    else
    {
        printf("\nThe array has 5 'e' in line.\n");
    }

    
}

void add_node(struct Node* head,int count)
{
    struct Node* current;
    int i = 1;
    current = head;
    
    while ( i < count - 1 && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Don't have enough number");
        exit(1);
    }

    node->arr = '9';

    node->next = current->next;

    current->next = node;

}



struct Node* delete_node(struct Node* head)
{
    char value = '9';

    struct Node* current = NULL, * previous = NULL;

    current = head;

    while (current) 
    {
        if (current->arr == value) 
        {
            previous->next = current->next;
            free(current);
            current = previous->next;
        }
        previous = current;
        current = previous->next;
    }
    return head;
}

void printList_1(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%c", ptr->arr);
        ptr = ptr->next;

        if (ptr->arr == '\0')
        {
            break;
        }
    }

    printf("->NULL");
}


int main()
{
    char arr[20];
    int n, count = 0;
    
    printf("Enter your array: ");
    gets_s(arr);

    n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = constructList(arr, n);

    head = delete_node(head);

    printList(head);

    printList_1(head);


    printf("\nEnter position for add: ");
    scanf_s("%d", &count);
    add_node(head, count);

    printList_1(head);

}


