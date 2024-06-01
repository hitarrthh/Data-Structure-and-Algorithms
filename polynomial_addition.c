#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int power) {
    struct Node* temp = *poly;
    struct Node* newNode = createNode(coeff, power);

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0, power = 0;
        if (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                coeff = poly1->coeff + poly2->coeff;
                power = poly1->power;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->power > poly2->power) {
                coeff = poly1->coeff;
                power = poly1->power;
                poly1 = poly1->next;
            } else {
                coeff = poly2->coeff;
                power = poly2->power;
                poly2 = poly2->next;
            }
        } else if (poly1) {
            coeff = poly1->coeff;
            power = poly1->power;
            poly1 = poly1->next;
        } else if (poly2) {
            coeff = poly2->coeff;
            power = poly2->power;
            poly2 = poly2->next;
        }
        insertTerm(&result, coeff, power);
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int n1, n2, coeff, power;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter coefficients and powers for Polynomial 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d%d", &coeff, &power);
        insertTerm(&poly1, coeff, power);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter coefficients and powers for Polynomial 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d%d", &coeff, &power);
        insertTerm(&poly2, coeff, power);
    }

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
