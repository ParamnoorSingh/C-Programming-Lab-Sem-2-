#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createnode() {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &node->data);
    node->next = NULL;
    return node;
}

void insertNodeInBeg() {
    struct Node *newnode = createnode();
    newnode->next = head;
    head = newnode;
}

void insertNodeInEnd() {
    struct Node *newnode = createnode();
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertNodeAtPosition() {
    if (head == NULL) {
        printf("Invalid Position!\n");
        return;
    }
    
    int pos, cnt = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid Position!\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    struct Node *newnode = createnode();
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteNodeAtPosition() {
    if (head == NULL) {
        printf("Invalid Position!\n");
        return;
    }
    
    int pos, cnt = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid Position!\n");
        return;
    }

    struct Node *temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void createlist() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct Node *newNode = createnode();
        newNode->next = head;
        head = newNode;
    }
}

struct Node* searchNode(int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // Return pointer to node if found
        }
        current = current->next;
    }
    return NULL; // Node not found
}

void displaylist() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("List elements: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createlist();

    while (1) {
        printf("\n1. Insert Node at Beginning\n");
        printf("2. Insert Node at End\n");
        printf("3. Insert Node at Any Position\n");
        printf("4. Delete Node from Given Position\n");
        printf("5. Search Node in List\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNodeInBeg();
                break;
            case 2:
                insertNodeInEnd();
                break;
            case 3:
                insertNodeAtPosition();
                break;
            case 4:
                deleteNodeAtPosition();
                break;
            case 5: {
                int val;
                printf("Enter the value to search: ");
                scanf("%d", &val);
                struct Node* result = searchNode(val);
                if (result != NULL) {
                    printf("Value found in the list\n");
                } else {
                    printf("Value not found in the list\n");
                }
                break;
            }
            case 6:
                displaylist();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
