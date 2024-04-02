#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000

int list[maxsize], size;

void Create() {
    int i;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    if (size > maxsize) {
        printf("List Overflow!!!\n");
    } else {
        printf("Enter the list elements:\n");
        for (i = 0; i < size; i++) {
            scanf("%d", &list[i]);
        }
    }
}

void Display() {
    if (size == 0) {
        printf("List is empty!!!\n");
    } else {
        printf("List elements are:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

void Insert() {
    if (size == 0) {
        printf("List is empty!!!\n");
        return;  // Return to avoid accessing empty list
    }

    int pos, value, i;
    printf("Enter the position where you want to insert a new element: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (pos >= 0 && pos <= size) {
        for (i = size; i > pos; i--) {  // Shift elements one position right
            list[i] = list[i - 1];
        }
        list[pos] = value;  // Insert value at the desired position
        size++;  // Increment size after adding the element
        printf("Element added at position %d and size is now %d\n", pos, size);
    } else {
        printf("Invalid position!!!\n");
    }
}

void Delete() {
    if (size == 0) {
        printf("List is empty!!!\n");
        return;  // Return to avoid accessing empty list
    }

    int pos, i;
    printf("Enter the position of the element you want to delete: ");
    scanf("%d", &pos);

    if (pos >= 0 && pos < size) {
        for (i = pos; i < size - 1; i++) {  // Shift elements one position left
            list[i] = list[i + 1];
        }
        size--;  // Decrement size after removing the element
        printf("Element deleted!!!\n");
    } else {
        printf("Invalid position!!!\n");
    }
}

void Search() {
    if (size == 0) {
        printf("List is empty!!!\n");
        return;  // Return to avoid accessing empty list
    }

    int val, i;
    printf("Enter the value to search: ");
    scanf("%d", &val);

    for (i = 0; i < size; i++) {
        if (list[i] == val) {
            break;
        }
    }

    if (i == size) {
        printf("Element not found!!!\n");
    } else {
        printf("Element found at position %d!!!\n", i);
    }
}

int main() {
    int choice;

    // Menu for user interaction
    printf("\nMenu:\n");
    printf("1. Create\n");
    printf("2. Insert\n");
    printf("3. Display\n");
    printf("4. Delete\n");
    printf("5. Search\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Insert();
                break;
            case 3:
                Display();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Search();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }

    return 0;
}
