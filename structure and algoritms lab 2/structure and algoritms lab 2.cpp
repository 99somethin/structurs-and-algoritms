#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    FILE* f;

    char str2[] = "Array do not have 5 'e'.";
    char str1[] = "Array have 5 'e'.";

    char* p = NULL;
    char ch;
    int count = 0, fl = 0;

    int i, n = 0,c = 1;


    printf("Enter your line: ");





    

    p = (char*) calloc(3,sizeof(char));

    if (p == NULL)
    {
        printf("Don't enough member.");
    }

    while (true)
    {
        ch = getchar();

        if (ch != '\n')
        {
            *(p+n) = ch;
        }
        else
        {
            break;
        }
        n++;

        if (n > 3 * c)
        {
            p = (char*)realloc(p, n + 3);
            c++;
        }

        if (p == NULL)
        {
            printf("Don't enough member.");
        }
    }
    printf("%s", p);


    /*fopen_s(&f, "READ.txt", "w");
    fwrite(p, sizeof(p[0]), sizeof(p), f);
    fclose(f);




    fopen_s(&f, "READ.txt", "r");

    if (f == NULL)
    {
        printf("Error opening.");
        return 0;
    }*/



    //second TASK

    /*p = (char*) malloc(1 * sizeof(char));

    if (p == NULL)
    {
        printf("Don't enough member.");
    }

    while (true)
    {
        ch = getchar();

        if (ch != '\n')
        {
            *(p+n) = ch;
        }
        else
        {
            break;
        }
        n++;

        
        p = (char*)realloc(p, n + 1);

        if (p == NULL)
        {
            printf("Don't enough member.");
        }
    }



    *(p+n) = '\n';

    n = 0;*/

    while ( *(p+n) != '\n')
    {
        if ( *(p+n) == 'e')
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
        n++;
    }

    


    if (fl != 0)
    {
        printf("Line have 5 'e' in line.");
    }
    else
    {
        printf("Line do not have 5 'e' in line.");
    }

    /*if (fl == 0)
    {
        fopen_s(&f, "INP.txt", "w");
        fwrite(str2, sizeof(str2[0]), sizeof(str2), f);
        fclose(f);
    }
    else
    {
        fopen_s(&f, "INP.txt", "w");
        fwrite(str1, sizeof(str1[0]), sizeof(str2), f);
        fclose(f);
    }*/


   /* free(p);*/
}


