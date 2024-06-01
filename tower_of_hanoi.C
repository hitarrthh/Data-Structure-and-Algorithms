#include <stdio.h>

void toh(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }

    toh(n - 1, from, to, aux);
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    toh(n - 1, aux, from, to);
}

int main() {
    int n;
    printf("Enter the number of disks: \n");
    scanf("%d", &n);
    if (n < 1) {
        printf("Number of disks must be at least 1.\n");
        return 1;
    }
    toh(n, 'A', 'B', 'C');

    return 0;
}
