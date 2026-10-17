/*A teacher wants to arrange student marks in ascending order and also measure how much
rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays
the array after every pass, counts the total number of element shifts, and displays the final sorted
list and shift count.*/


#include <stdio.h>

int main() {
    int a[100], n, i, j, key, shifts = 0;

    printf("Enter number of marks: ");
    scanf("%d", &n);

    printf("Enter marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }

        a[j + 1] = key;

        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }

    printf("Sorted marks: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nTotal element shifts: %d\n", shifts);

    return 0;
}
