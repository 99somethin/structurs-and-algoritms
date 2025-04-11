#include <stdio.h>


//прямой выбор
//void sorted(int arr[],int n)
//{
//    int c,j,i,min = arr[0],temp;
//
//    for (i = 0; i < n - 1; i++)
//    {
//        min = i;
//
//        for (j = i + 1; j < n; j++)
//        {
//            if (arr[j] < arr[min])
//            {
//                min = j;
//            }
//        }
//
//        temp = arr[i];
//        arr[i] = arr[min];
//        arr[min] = temp;
//
//        for ( c = 0; c < n; c++)
//        {
//            if (c == i)
//            {
//                printf("%d |", arr[c]);
//            }
//            else
//            {
//                printf("%d ", arr[c]);
//            }
//        }
//        printf("\n");
//
//    }
//}

// простые вставки
void sorted(int arr[], int n)
{
    
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i,c;

        printf("x = %d\n", arr[i]);

        while (j > 0 && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            j--;

            for (int c = 0; c < n; c++)
            {
                if (c == i - 1)
                {
                    printf("%d |", arr[c]);
                }
                else
                {
                    printf("%d ", arr[c]);
                }
            }
            printf("\n");
        }
        
        for (int c = 0; c < n; c++)
        {
            if (c == i)
            {
                printf("%d |", arr[c]);
            }
            else
            {
                printf("%d ", arr[c]);
            }
        }
        printf("\n");

        arr[j] = value;

        for (int c = 0; c < n; c++)
        {
            if (c == i)
            {
                printf("%d |", arr[c]);
            }
            else
            {
                printf("%d ", arr[c]);
            }
        }
        printf("\n");


    }
}



//шейкер

//void sorted(int mass[], int count)
//{
//    int left = 0, right = count - 1; 
//    int flag = 1;
//
//
//
//    while ( (left < right) && flag > 0)
//    {
//        
//        flag = 0;
//        
//        for (int i = right; i > left; i--)  
//        {
//            if (mass[i - 1] > mass[i]) 
//            {           
//                int t = mass[i];
//                mass[i] = mass[i - 1];
//                mass[i - 1] = t;
//                flag = 1;
//                
//            }
//            for (int c = 0; c < count; c++)
//            {
//                if (c == left)
//                {
//                    printf(" |%d ", mass[c]);
//                }
//                else if (c == right)
//                {
//                    printf(" %d| ", mass[c]);
//                }
//                else
//                {
//                    printf(" %d ", mass[c]);
//                }
//            }
//            printf("\n");
//        }
//        left++;
//
//        for (int i = left; i < right; i++)
//        {
//            if (mass[i] > mass[i + 1])
//            {
//                int t = mass[i];
//                mass[i] = mass[i + 1];
//                mass[i + 1] = t;
//                flag = 1;
//            }
//            for (int c = 0; c < count; c++)
//            {
//                if (c == left)
//                {
//                    printf(" |%d ", mass[c]);
//                }
//                else if (c == right)
//                {
//                    printf(" %d| ", mass[c]);
//                }
//                else
//                {
//                    printf(" %d ", mass[c]);
//                }
//            }
//            printf("\n");
//        }
//        if (flag == 1)
//        {
//            right = right - 2;
//        }
//        else
//        {
//            right--;
//        }
//        
//    }
//}


void main() 
{
    int arr[] = { 2,1,4,7,5,0,10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sorted(arr,n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
        
}



