#include <stdio.h>

int main()
{
    FILE* f;

    int count = 0,fl = 0;
    char c;
    char str2[] = "Array do not have 5 'e'."; 
    char str1[] = "Array have 5 'e'.";
    char arr[50];


    printf("Enter your array: ");
    gets_s(arr);

    fopen_s(&f, "READ.txt", "w");
    fwrite(arr, sizeof(arr[0]), sizeof(arr), f);
    fclose(f);




    fopen_s(&f,"READ.txt", "r");

    if (f == NULL)
    {
        printf("Error opening.");
        return 0;
    }



    while ( ( c = fgetc(f)) != EOF ) 
    {
        if ( c == 'e')
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
    }

    fclose(f);



    if (fl == 0)
    {
        fopen_s(&f, "INP.txt", "w");
        fwrite(str2,sizeof(str2[0]),sizeof(str2), f);
        fclose(f);
    }
    else
    {
        fopen_s(&f, "INP.txt", "w");
        fwrite(str1, sizeof(str1[0]), sizeof(str2), f);
        fclose(f);
    }
    

}

