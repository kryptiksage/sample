#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//return array with random values within limit
int* randomarray(int n, int max)
{
    int *a = (int *)malloc(sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n; i++)
        a[i] = rand()%max;
    return a;
}
//search()
int search(int i, int n, int *arr)
{
    int p = -1;
    for(int j=0; j<n; j++)
    {
        if(arr[j] == i)
            return j;
        else if(arr[j] > i)
            return p;
    }
    return p;
}
//chopsearch()
int chopsearch(int i, int n, int *arr, int amin, int amax)
{
    srand(time(NULL));
    int x = amin + rand()%(amax-amin+1);
    if((amax-amin) < 0)
        return -1;
    else
    {
        if(i<arr[x])
            return chopsearch(i, n, arr, amin, x-1);
        else if(i>arr[x])
            return chopsearch(i, n, arr, x+1, amax);
        else
        {
            for(int j=amin; j<=x; j++)
            {
                if(arr[j] == i)
                    return j;
            }
        }
    }
    
}
//median()
int median(int n, int *arr)
{
    for(int i=0; i<n; i++)
    {
        int  c = 0;
        for(int j=0; j<n; j++)
            if(arr[j]<arr[i])
                c++;
        if(c == n/2)
            return arr[i];

    }
}
int main()
{
    int *p = randomarray(5, 5);
    /*for(int i=0; i<5; i++)
        printf("%i\n", p[i]);*/
    int a[8] = {2, 8, 3, 7, 5, 6, 4, 1};
    /*for(int i = 1; i <= 7; i++)
    { 
        printf("Index: %i\n", chopsearch(i, 7, a, 0, 6));
    }*/
    printf("Median: %i\n", median(8, a));
    return 0;
}