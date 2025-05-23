/************************************************************
Title   : Earthquake Rescue Robot Coordinator
NAME    : SAHIL KUMAR
ROLL NO : ME24I1009
Date    : 24 - 04 - 2025
Purpose : Simulate rescue coordination with queue, stack, logs,
          and robot repair tracking (linked lists)
************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define slots 6
//structure of queue
struct Queue {
    char* Mission;
    struct Queue* next;
};
struct Queue* front = NULL;
struct Queue* rear = NULL;
//structure of stack
struct Stack {
    char* Mission;
    struct Stack* next;
};
struct Stack *top = NULL;
// structure of singly linked list
struct Singlynode {
    char* name;
    struct Singlynode* next;
};
struct Singlynode* damagehead = NULL;
//structure of doubly linked list
struct Doublynode {
    char* name;
    struct Doublynode* next;
    struct Doublynode* prev;
};
struct Doublynode* repairhead = NULL;
struct Doublynode* repairtail = NULL;
//structure of circular linked list
struct Circularnode {
    char* name;
    struct Circularnode* next;
};
struct Circularnode* circularhead = NULL;
struct Circularnode* circulartail = NULL;
// Function to equeue an element in the queue
void enqueue(char* missionName) 
{   
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->Mission = strdup(missionName);
    newNode->next = NULL;
    if (rear == NULL) 
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
// Function to dequeue an element from the queue
char* dequeue() 
{
    if (front == NULL && rear == NULL) 
    {
        printf("Queue is empty\n");
        return NULL;
    }
    else 
    { 
        struct Queue* temp = front;
        char* missionName = strdup(front->Mission);
        printf("Dequeued element: %s\n", missionName);
        front = front->next;
        // if the queue is empty
        if (front == NULL) {
            rear = NULL;
        }
        free(temp->Mission);
        free(temp);
        return missionName;
    }
}
// Function to display the queue
void display() 
{
    struct Queue* temp = front;
    if (front == NULL && rear == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    else 
    {
        printf("Queue elements:\n ");
        while (temp != NULL) 
        {
            printf("%s <-> ", temp->Mission);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function to push the element in the stack
void push(char* missionName) 
{
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->Mission = strdup(missionName);
    newNode->next = top;
    top = newNode;
}
// Function to pop the element from the stack
char* pop() {
    if (top == NULL) 
    {
        printf("\nStack is empty\n");
        return NULL;
    }
    struct Stack* temp = top;
    char* missionName = strdup(top->Mission);
    // printf("Popped element: %s\n", missionName);
    top = top->next;
    free(temp->Mission);
    free(temp);
    return missionName;
}
// Function to display the stack
void displayStack() 
{
    struct Stack* temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    else {
        printf("Stack elements:\n ");
        while (temp != NULL) {
            printf("%s ", temp->Mission);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function to circularly log the mission names in the array
char* logarray[slots];
int logindex = 0;
// Function to log the mission names in the array
void logMission(char* missionName) 
{
    if(logarray[logindex] != NULL) 
    {
        printf("Overwriting: %s\n", logarray[logindex]);
        free(logarray[logindex]);
    }
       logarray[logindex] = strdup(missionName);
       printf("Logged: %s\n", missionName);
       logindex = (logindex + 1) % slots;
}
void displayLog() 
{
    printf("Log of mission names:\n");
    for(int i = 0; i < slots; i++) 
    {
        if(logarray[i] != NULL) 
        {
            printf("%s<-> ", logarray[i]);
        }
    }
    printf("\n");
}
//insertion of damaged robot
void insertDamagedRobot(char* robotName) 
{
    struct Singlynode* newNode = (struct Singlynode*)malloc(sizeof(struct Singlynode));
    newNode->name = strdup(robotName);
    newNode->next = NULL;
    if (damagehead == NULL) 
    {
        damagehead = newNode;
        return;
    }
    struct Singlynode* temp = damagehead;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
//deletion of damaged robot
char* deleteDamagedRobot(char* robotName)
{
    struct Singlynode* temp = damagehead;
    struct Singlynode* prev = NULL;
    while (temp != NULL && strcmp(temp->name, robotName) != 0) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        printf("Robot not found\n");
        return NULL;
    }
    if (prev == NULL) 
    {
        damagehead = temp->next;
    } 
    else 
    {
        prev->next = temp->next;
    }
    char* repairedRobotName = strdup(temp->name);
    free(temp->name);
    free(temp);
    return repairedRobotName;
}
//insertion of repaired robot
void insertRepairedRobot(char* robotName)
{
    struct Doublynode* newDoublyNode = (struct Doublynode*)malloc(sizeof(struct Doublynode));
    newDoublyNode->name = strdup(robotName);
    newDoublyNode->next = NULL;
    newDoublyNode->prev = repairtail;
    if (repairtail != NULL) 
    {
        repairtail->next = newDoublyNode;
    }else 
    {
        repairhead = newDoublyNode;
    }
    repairtail = newDoublyNode;
}
//forward traversal of repaired robot
void forwardTraversal() 
{   
    if (repairhead == NULL) 
    {
        printf("No repaired robots\n");
        return;
    }
    else 
    {  
        struct Doublynode* temp = repairhead;
        printf("Repaired robots in forward order:\n");
        while (temp != NULL) 
        {
            printf("%s ->", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}
//backward traversal of repaired robot
void backwardTraversal()
{
    if (repairhead == NULL) 
    {
        printf("No repaired robots\n");
        return;
    }
    else 
    {   
        printf("Repaired robots in backward order:\n");
        struct Doublynode* temp = repairtail;
        while (temp != NULL) 
        {
            printf("%s ->", temp->name);
            temp = temp->prev;
        }
        printf("\n");
    }
}
// Function to display the damaged robots
void displayDamaged() 
{
    if (damagehead == NULL)
    {
        printf("No damaged robots\n");
        return;
    }
    else 
    {
        printf("Damaged robots:\n");
        struct Singlynode* temp = damagehead;
        while (temp != NULL) 
        {
            printf("%s ->", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}
//priority redeployment of damaged robots
void redeployDamagedRobot(char* robotName) 
{
    struct Circularnode* newNode = (struct Circularnode*)malloc(sizeof(struct Circularnode));
    newNode->name = strdup(robotName);
    newNode->next = NULL;
    if (circularhead == NULL) 
    {
        circularhead = newNode;
        circulartail = newNode;
        circulartail->next = circularhead;
    } 
    else 
    {
        circulartail->next = newNode;
        circulartail = newNode;
        circulartail->next = circularhead;
    }
}
// Function to treverse the circular linked list twice
void traverseCircular() 
{
    if (circularhead == NULL) 
    {
        printf("No urgent redeployment robots.\n");
        return;
    }
    struct Circularnode* temp = circularhead;
    int cycles = 0;
    printf("\nUrgent Redeployment Cycle (2x):\n");
    do 
    {
        printf("%s -> ", temp->name);
        temp = temp->next;
        // If we have completed a cycle, increment cycles
        if (temp == circularhead)
            cycles++;
    } while (cycles < 2);
    printf("Back to start\n");
}

// Function to free the memory of the circular linked list
void freeMemory()
{
    struct Circularnode* temp = circularhead;
    if (temp == NULL) 
    {
        return;
    }
    struct Circularnode* nextNode;
    do 
    {
        nextNode = temp->next;
        free(temp->name);
        free(temp);
        temp = nextNode;
    } while (temp != circularhead);
}
//main function
// Assume all required structures and functions (enqueue, dequeue, push, pop, etc.) are already defined above
int main() 
{
    int choice;
    char robotName[100], *task, *urgentTask, *repairedRobot;
    int n, i, damagedCount, redeployCount;

    // Initialize logarray
    for (i = 0; i < slots; i++) 
        logarray[i] = NULL;

    do 
    {
        printf("\n============================\n");
        printf(" Earthquake Rescue Coordinator\n");
        printf("============================\n");
        printf("1. Enqueue Missions\n");
        printf("2. Dequeue All and Push to Stack\n");
        printf("3. Display Urgency Missions (LIFO)\n");
        printf("4. Log Missions\n");
        printf("5. Insert Damaged Robots\n");
        printf("6. Repair Robot\n");
        printf("7. Display Repaired Robots (Forward)\n");
        printf("8. Display Repaired Robots (Backward)\n");
        printf("9. Urgent Redeployment\n");
        printf("10. Traverse Redeployment List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter number of missions to enqueue: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) 
                {
                    printf("Enter mission name %d: ", i + 1);
                    scanf(" %[^\n]", robotName);
                    enqueue(robotName);
                }
                printf("Missions enqueued successfully.\n");
                display();
                break;
            case 2:
                while ((task = dequeue()) != NULL) 
                {
                    push(task);
                    free(task);
                }
                break;
            case 3:
                printf("\nUrgency Missions order according to LIFO principle:\n");
                while ((urgentTask = pop()) != NULL) 
                {
                    printf("%s > ", urgentTask);
                    free(urgentTask);
                }
                printf("\n");
                break;
            case 4:
                printf("Enter the number of missions you want to log: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) 
                {
                    printf("Enter mission name %d: ", i + 1);
                    scanf(" %[^\n]", robotName);
                    logMission(robotName);
                }
                displayLog();
                break;
            case 5:
                printf("Enter the number of damaged robots: ");
                scanf("%d", &damagedCount);
                for (i = 0; i < damagedCount; i++) 
                {
                    printf("Enter damaged robot name %d: ", i + 1);
                    scanf("%s", robotName);
                    insertDamagedRobot(robotName);
                }
                displayDamaged();
                break;
            case 6:
                printf("Enter the name of the robot to be repaired: ");
                scanf("%s", robotName);
                repairedRobot = deleteDamagedRobot(robotName);
                if (repairedRobot != NULL) 
                {
                    insertRepairedRobot(repairedRobot);
                    free(repairedRobot);
                }
                break;
            case 7:
                forwardTraversal();
                break;
            case 8:
                backwardTraversal();
                break;
            case 9:
                printf("Enter the number of robots for urgent redeployment: ");
                scanf("%d", &redeployCount);
                for (i = 0; i < redeployCount; i++) 
                {
                    printf("Enter robot name %d: ", i + 1);
                    scanf("%s", robotName);
                    redeployDamagedRobot(robotName);
                }
                break;
            case 10:
                traverseCircular();
                break;
            case 11:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    // Free all dynamically allocated memory before exit
    for (i = 0; i < slots; i++) {
        if (logarray[i] != NULL) {
            free(logarray[i]);
        }
    }
    struct Singlynode* temp = damagehead;
    while (temp != NULL) {
        struct Singlynode* next = temp->next;
        free(temp->name);
        free(temp);
        temp = next;
    }
    struct Doublynode* temp2 = repairhead;
    while (temp2 != NULL) 
    {
        struct Doublynode* next = temp2->next;
        free(temp2->name);
        free(temp2);
        temp2 = next;
    }
    freeMemory(); // for circular list
    return 0;
}
