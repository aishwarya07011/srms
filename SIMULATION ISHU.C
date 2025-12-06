#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for each customer
typedef struct Node {
    int customerId;
    char name[30];
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to add a customer to the queue
void enqueue(int id, char name[]) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->customerId = id;
    strcpy(temp->name, name);
    temp->next = NULL;

    if(front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("Customer %d (%s) added to queue.\n", id, name);
}

// Function to remove a customer from the queue (serve them)
void dequeue() {
    if(front == NULL) {
        printf("Queue is empty, no customers to serve.\n");
        return;
    }

    Node* temp = front;
    printf("Serving customer %d (%s).\n", temp->customerId, temp->name);

    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

// Display queue status
void display() {
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = front;
    printf("\n---- Current Queue ----\n");
    while(temp != NULL) {
        printf("Customer %d (%s)\n", temp->customerId, temp->name);
        temp = temp->next;
    }
    printf("------------------------\n");
}

int main() {
    int choice, id;
    char name[30];

    printf("🏦 Bank Queue Simulation\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Customer Name: ");
                scanf("%s", name);
                enqueue(id, name);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting simulation...\n");
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}