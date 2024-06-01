#include <stdio.h>

void merge(int a[], int p, int q, int r);
void mergesort(int a[], int p, int r);

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    int a[10];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nBEFORE SORTING\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("\nAFTER SORTING\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void merge(int a[], int p, int q, int r) {
    int i, j, k;
    int t1 = q - p + 1;  
    int t2 = r - q;
    int larr[t1], rarr[t2];
    for (i = 0; i < t1; i++) {
        larr[i] = a[p + i];
    }
    for (j = 0; j < t2; j++) {
        rarr[j] = a[q + 1 + j];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < t1 && j < t2) {
        if (larr[i] <= rarr[j]) {
            a[k] = larr[i];
            i++;
        } else {
            a[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < t1) {
        a[k] = larr[i];
        i++;
        k++;
    }
    while (j < t2) {
        a[k] = rarr[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
