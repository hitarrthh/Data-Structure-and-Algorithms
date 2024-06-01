#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define DELETED -2

int h[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        h[i] = -1; // Initialize all slots as empty (-1)
    }
}

void insert(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        if (h[index] == -1 || h[index] == DELETED) {
            h[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        i++;
    }

    printf("Table is full. Cannot insert %d\n", key);
}

void display() {
    printf("\nHash Table elements:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (h[i] != -1 && h[i] != DELETED) {
            printf("Index %d: %d\n", i, h[i]);
        }
    }
}

void deleteKey(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        if (h[index] == key) {
            h[index] = DELETED; // Mark as deleted
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        i++;
    }

    printf("%d not found in the table\n", key);
}

int main() {
    initializeHashTable();

    int choice, key;

    while (1) {
        printf("\n1. Insert\t2. Display\t3. Delete\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the key to delete: ");
				scanf("%d", &key);
                deleteKey(key);
		}
	}
}
