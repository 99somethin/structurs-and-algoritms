#include <stdio.h>

#include <stdlib.h>

struct node* NewNode(char, struct node*);

struct node
{
    char ch;
    
    node* next;
};

void clear(struct node* head)
{
    if (head == NULL)
    {
        printf("\nYour nodes is empty now.\n");
        return;
    }
        
  
    struct node* current = head->next;
    struct node* next;

    head->ch = ' ';
    head->next = NULL;

    while (current != NULL)
    {
        next = current->next;

        free(current);

        current = next;

    }
    printf("\nYour nodes is empty now.\n");
}

void check_empty(struct node* head)
{
    if (head == NULL)
    {
        printf("\nNode is empty\n");
    }
    else
    {
        printf("\nNode is not empty\n");
    }
}

struct node* CreateList(char arr[],int n)
{
    int i;
    struct node* head = NULL, * current = NULL;

    for (i = n - 1; i >= 0;i--)
    {
        if (arr[i] != -2 && arr[i] != '\0')
        {
            current = NewNode(arr[i], current);
            head = current;
        }
    }
    return head;
}

struct node* NewNode(char arr, struct node *current)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Don't have enough member.");
        exit(1);
    }

    new_node->ch = arr;

    new_node->next = current;

    return new_node;
}

void delete_node(struct node* current_pointer,struct node* head)
{
    if (current_pointer == NULL || current_pointer->next == NULL)
    {
        printf("\nCan not delete node.\n");
        return;
    }

    struct node* node_to_delete = current_pointer->next;
    current_pointer->next = node_to_delete->next;
    free(node_to_delete);

}

void print_node(struct node* head,struct node* pointer)
{
    struct node* current = head;

    if (current == NULL)
    {
        printf("\nThe table is empty\n");
    }

    printf("Your data: ");
    while (current)
    {
        if (current == pointer)
        {
            printf("*%c", current->ch);

            current = current->next;

            continue;
        }

        printf("%c", current->ch);

        current = current->next;

    }

    printf("\n");
}

void add_char(struct node* current)
{
    char value;

    printf("\nEnter the value of new char: ");
    while ((getchar()) != '\n');
    
    scanf_s("%c", &value, 1);

    current->next->ch = value;
}


void push_pointer(struct node* current)
{
    char value;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Don't have enough member.");
        exit(1);
    }

    printf("\nEnter the value of new char: ");
    while ((getchar()) != '\n');

    scanf_s("%c", &value, 1);
    new_node->ch = value;

    new_node->next = current->next;

    current->next = new_node;
}


int main()
{
    char arr[20], char_for_save;
    int n, count = 0, choice,choice2, fl = 0;

    struct node* head = NULL;
    struct node* current_pointer = NULL;
    

    while(true)
    {
        printf("Press 0 to end programm.\n");
        printf("Press 1 to start work with nodes.\n");

        scanf_s("%d", &choice2);

        if (choice2 > 1)
        {
            printf("Incorrect number.Try again.\n");
            continue;
        }

        while ((getchar()) != '\n');

        if (choice2 == 0)
        {
            break;
        }
       
        do
        {
            if (fl == 0)
            {
                printf("Enter your array: ");
                gets_s(arr);

                n = sizeof(arr) / sizeof(arr[0]);

                head = CreateList(arr, n);

                current_pointer = head;
            }
            fl++;

            printf("\nPress 0 to end the programm\n");
            printf("Press 1 to delete all data\n");
            printf("Press 2 to check for empty\n");
            printf("Press 3 to redirect pointer to the begin\n");
            printf("Press 4 to check is the pointer in the end\n");
            printf("Press 5 to relocate the pointer to forward\n");
            printf("Press 6 to show pointer's value\n");
            printf("Press 7 to delete pointer's node\n");
            printf("Press 8 to take the value\n");
            printf("Press 9 to change the value\n");
            printf("Press 10 to add the node\n");
            printf("Press 11 to print the nodes\n");

            scanf_s("%d", &choice);

            if (choice > 11)
            {
                printf("Incorrect number.Try again.\n");
                continue;
            }

            switch (choice)
            {

            case 1:
            {
                clear(head);
                break;
            }
            case 2:
            {
                check_empty(head);
                print_node(head, current_pointer);
                break;
            }
            case 3:
            {
                current_pointer = head;
                print_node(head, current_pointer);
                break;
            }
            case 4:
            {
                if (current_pointer == NULL || current_pointer->next == NULL)
                {
                    printf("\nPointer locate in the end of node\n");
                    print_node(head, current_pointer);
                }
                else
                {
                    printf("\nPointer not locate in the end of node\n");
                    print_node(head, current_pointer);
                }
                break;
            }
            case 5:
            {
                if (current_pointer != NULL && current_pointer->next != NULL)
                {
                    current_pointer = current_pointer->next;
                    printf("\nPointer go forward\n");
                    print_node(head, current_pointer);
                }
                else
                {
                    printf("\nPointer locate in the end of node\n");
                    print_node(head, current_pointer);
                }
                break;
            }
            case 6:
            {
                if (current_pointer != NULL)
                {
                    printf("\n Pointer's value = %c\n", current_pointer->ch);
                    print_node(head, current_pointer);
                }
                else
                {
                    printf("\nCurrent pointer's value is empty\n");
                    print_node(head, current_pointer);
                }
                break;
            }
            case 7:
            {
                delete_node(current_pointer, head);
                print_node(head, current_pointer);
                break;
            }
            case 8:
            {

                if (current_pointer == NULL || current_pointer->next == NULL)
                {
                    printf("\nCan not take node's value.\n");
                    print_node(head, current_pointer);
                }
                else
                {
                    char_for_save = current_pointer->next->ch;
                    delete_node(current_pointer, head);
                    printf("\nNodes value is: %c\n", char_for_save);
                    print_node(head, current_pointer);
                }
                break;
            }
            case 9:
            {
                if (current_pointer == NULL || current_pointer->next == NULL)
                {
                    printf("\nCan not change node's value.\n");
                    print_node(head, current_pointer);
                }
                else
                {
                    add_char(current_pointer);
                    print_node(head, current_pointer);
                }
                break;
            }
            case 10:
            {
                if (head == NULL)
                {
                    printf("Can not add node.\n");
                    print_node(head, current_pointer);
                }
                else
                {
                    push_pointer(current_pointer);
                    print_node(head, current_pointer);
                }
                break;

                
            }
            case 11:
            {
                print_node(head,current_pointer);
                break;
            }

            }



        } while (choice != 0);

        fl = 0;

    }
}

