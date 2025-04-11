#include <stdio.h>

#include <stdlib.h>



struct node
{
    char ch;

    node* next;
    node* prev;
};

void clear(struct node* head)
{
    struct node* head_use = head->next;

    head->ch = ' ';
    head->next = NULL;

    struct node* current = head_use;

    while (head_use)
    {
        head_use = head_use->next;


        if (current != NULL)
        {
            free(current);
        }



        current = head_use;
    }

}

void check_empty(struct node* head)
{
    if (head->ch == ' ' && head->next == NULL)
    {
        printf("Node is empty\n");
    }
    else
    {
        printf("Node is not empty\n");
    }
}

struct node* create(char a)
{
    struct node* first;

    first = (struct node*)malloc(sizeof(struct node)); // приведение типов и количество памяти, которое нужно выделить

    if (first == NULL)
    {
        printf("Do not have enough member.");
        exit(1);
    }

    first->ch = a;
    first->next = NULL;
    first->prev = NULL;

    return first;
}

void delete_node(struct node* current_pointer, struct node* head)
{
    struct node* begin = head;

    struct node* current = begin;

    current_pointer->prev = NULL;

    while (begin->next != current_pointer)
    {

        begin = begin->next;


        if (current != NULL)
        {
            free(current);
        }



        current = begin;
        
    }

    begin->next = current_pointer->next;

    

}


void delete_node_after(struct node* current_pointer, struct node* head)
{
    struct node* begin = current_pointer;

    begin->next = NULL;

    struct node* current = begin;

    while (begin->next != NULL)
    {

        begin = begin->next;


        if (current != NULL)
        {
            free(current);
        }



        current = begin;

    }

    begin->next = current_pointer->next;



}

void print_node(struct node* head)
{
    struct node* current = head;

    if (current->ch == ' ')
    {
        printf("\nThe table is empty\n");
    }

    printf("Your data: ");
    while (current)
    {
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

    if (current->next != NULL)
    {
        current->next->ch = value;
    }
    else
    {
        printf("Nodes is end\n");
    }
}

void add_char_before(struct node* current)
{
    char value;

    printf("\nEnter the value of new char: ");
    while ((getchar()) != '\n');

    scanf_s("%c", &value, 1);

    if (current->prev != NULL)
    {
        current->next->ch = value;
    }
    else
    {
        printf("Nodes is end\n");
    }
}

void push_back(struct node* head)
{
    char value;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* current = head;

    if (new_node == NULL)
    {
        printf("Don't have enough member.");
        exit(1);
    }
    printf("\nEnter the value of new char: ");
    scanf_s("%c", &value, 1);

    new_node->ch = value;
    new_node->next = NULL;
    

    while (current)
    {
        if (current->next == NULL)
        {
            current->next = new_node;
            new_node->prev = current;
            break;
        }
        current = current->next;
    }
}

void push_forward(struct node* head)
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
    new_node->next = head;
    new_node->prev = NULL;
}


void push_current(struct node* current_pointer, struct node* head)
{
    char value;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Don't have enough member.");
        exit(1);
    }

    new_node = head;

    printf("\nEnter the value of new char: ");
    while ((getchar()) != '\n');

    scanf_s("%c", &value, 1);

    while (new_node != current_pointer)
    {
        new_node = new_node->next;
    }

    new_node->next = current_pointer->next;


    current_pointer->next = new_node;

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

    current->ch = a;

    current->next = previous;
    current->prev = first;

    if (previous != NULL)
    {
        previous->prev = current;
    }

    return(current);
}


int main()
{
    char arr[20], char_for_save[20];
    int n, count = 0, choice,i = 0;

    printf("Enter your array: ");
    gets_s(arr);

   
    struct node* head = create(arr[i]);
    i++;
    
    struct node* current = add(head,arr[i]);
    i++;
    
    while (arr[i] != '\0')
    {
        current = add(current, arr[i]);
        i++;
    }

    struct node* current_pointer = head;

    do
    {
        printf("\nPress 0 to end the programm\n");
        printf("Press 1 to delete all data\n");
        printf("Press 2 to check for empty\n");
        printf("Press 3 to redirect pointer to the begin\n");
        printf("Press 4 to check is the pointer in the end\n");
        printf("Press 5 to relocate the pointer to forward\n");
        printf("Press 6 to show next pointer's value\n");
        printf("Press 7 to delete values before pointer's node\n");
        printf("Press 8 to take the value before pointer\n");
        printf("Press 9 to change the value after pointer\n");
        printf("Press 10 to add the node\n");
        printf("Press 11 to print the nodes\n");
        printf("Press 12 to check is the pointer in the begin\n");
        printf("Press 13 to relocate the pointer to back\n");
        printf("Press 14 to show prevvious pointer's value\n");
        printf("Press 15 to delete values after pointer's node\n");
        printf("Press 16 to change the value before pointer\n");
        printf("Press 17 to take the value after pointer\n");


        scanf_s("%d", &choice);

        if (choice > 17)
        {
            printf("There is not this command\n");
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
            break;
        }
        case 3:
        {
            current_pointer = head;
            break;
        }
        case 4:
        {
            if (current_pointer->next == NULL)
            {
                printf("Pointer locate in the end of node\n");
            }
            else
            {
                printf("Pointer not locate in the end of node\n");
            }
            break;
        }
        case 5:
        {
            if (current_pointer->next != NULL)
            {
                current_pointer = current_pointer->next;
            }
            else
            {
                printf("Pointer not locate in the end of node\n");
            }
            break;
        }
        case 6:
        {
            if (current_pointer->next != NULL)
            {
                printf("%c", (current_pointer->next)->ch);
            }
            else
            {
                printf("Current pointer's value is empty");
            }
            break;
        }
        case 7:
        {
            delete_node(current_pointer, head);
            break;
        }
        case 8:
        {
            i = 0;
            current = head;

            while (current != current_pointer)
            {
                char_for_save[i] = current->ch;
                current = current->next;
                i++;
            }

            delete_node(current_pointer, head);
            break;
        }
        case 9:
        {
            add_char(current_pointer);
            break;
        }
        case 10:
        {
            if (current_pointer->next == NULL)
            {
                push_back(head);
            }
            else if (current_pointer == head)
            {
                push_forward(head);
            }
            else
            {
                push_current(current_pointer, head);
            }
            break;
        }
        case 11:
        {
            print_node(head);
            break;
        }
        case 12:
        {
            if (current_pointer->prev == NULL)
            {
                printf("Pointer locate in the begin of node\n");
            }
            else
            {
                printf("Pointer not locate in the begin of node\n");
            }
            break;
        }
        case 13:
        {
            if (current_pointer->prev != NULL)
            {
                current_pointer = current_pointer->prev;
            }
            else
            {
                printf("Pointer locate in the begin of node\n");
            }
            break;
        }
        case 14:
        {
            if (current_pointer->prev != NULL)
            {
                printf("%c", (current_pointer->prev)->ch);
            }
            else
            {
                printf("Current pointer's value is empty");
            }
            break;
        }
        case 15:
        {
            delete_node_after(current_pointer, head);
            break;
        }
        case 16:
        {
            add_char_before(current_pointer);
            break;
        }
        case 17:
        {
            i = 0;
            current = current_pointer;

            while (current != NULL)
            {
                char_for_save[i] = current->ch;
                current = current->next;
                i++;
            }

            delete_node_after(current_pointer, head);
            break;
        }


        }




    } while (choice != 0);



}
