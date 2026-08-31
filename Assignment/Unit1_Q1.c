/*A company stores employee IDs in ascending order. Write a C program that accepts n employee
IDs, searches for a required ID using Binary Search, displays its position when found, reports
when it is absent, and counts the number of comparisons. Test the program for both successful
and unsuccessful searches.*/

#include <stdio.h>
int main()
{
    int a[100], n, key;
    int low, high, mid, comparisons = 0;
    int found = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if(a[mid] == key)
        {
            found = 1;
            break;
        }
        else if(key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found)
        printf("Element found at position %d\n", mid + 1);
    else
        printf("Element not found\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}