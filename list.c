#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 256

typedef struct {
    char description[MAX_TASK_LEN];
    int completed;
} Task;

void addTask(Task tasks[], int *taskCount);
void editTask(Task tasks[], int taskCount);
void markTaskComplete(Task tasks[], int taskCount);
void displayTasks(Task tasks[], int taskCount);
void menu();

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline character left in buffer

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                editTask(tasks, taskCount);
                break;
            case 3:
                markTaskComplete(tasks, taskCount);
                break;
            case 4:
                displayTasks(tasks, taskCount);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void menu() {
    printf("\nTo-Do List Manager\n");
    printf("1. Add Task\n");
    printf("2. Edit Task\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Display Tasks\n");
    printf("0. Exit\n");
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task description: ");
    fgets(tasks[*taskCount].description, MAX_TASK_LEN, stdin);
    tasks[*taskCount].description[strcspn(tasks[*taskCount].description, "\n")] = 0; // Remove newline
    tasks[*taskCount].completed = 0;
    (*taskCount)++;
    printf("Task added successfully!\n");
}

void editTask(Task tasks[], int taskCount) {
    int taskId;
    printf("Enter task ID to edit (1 to %d): ", taskCount);
    scanf("%d", &taskId);
    getchar(); // to consume newline character left in buffer

    if (taskId < 1 || taskId > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }

    printf("Enter new task description: ");
    fgets(tasks[taskId - 1].description, MAX_TASK_LEN, stdin);
    tasks[taskId - 1].description[strcspn(tasks[taskId - 1].description, "\n")] = 0; // Remove newline
    printf("Task edited successfully!\n");
}

void markTaskComplete(Task tasks[], int taskCount) {
    int taskId;
    printf("Enter task ID to mark as complete (1 to %d): ", taskCount);
    scanf("%d", &taskId);
    getchar(); // to consume newline character left in buffer

    if (taskId < 1 || taskId > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }

    tasks[taskId - 1].completed = 1;
    printf("Task marked as complete!\n");
}

void displayTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        printf("Task ID: %d\n", i + 1);
        printf("Description: %s\n", tasks[i].description);
        printf("Status: %s\n", tasks[i].completed ? "Complete" : "Incomplete");
        printf("\n");
    }
}
