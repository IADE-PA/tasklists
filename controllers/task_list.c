#include "task_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TaskList_ {
    Task** tasks;
    int num_tasks;
};

TaskList* task_list_new() {
    TaskList* task_list = malloc(sizeof(TaskList));
    task_list->tasks = NULL;
    task_list->num_tasks = 0;
    return task_list;
}

void task_list_destroy(TaskList* task_list) {
    for (int i = 0; i < task_list->num_tasks; i++) {
        task_destroy(task_list->tasks[i]);
    }
    free(task_list->tasks);
    free(task_list);
}

char* _generate_id(TaskList* task_list) {
    char* id = malloc(sizeof(char) * 10);
    sprintf(id, "%d", task_list->num_tasks);
    return id;
}

char* task_list_add_task(TaskList* task_list, char* description) {
    char* id = _generate_id(task_list);
    Task* task = task_new(id, description);
    free(id);
    task_list->num_tasks++;
    task_list->tasks = realloc(task_list->tasks, sizeof(Task*) * task_list->num_tasks);
    task_list->tasks[task_list->num_tasks - 1] = task;
    return task_get_id(task);
}

Task* task_list_get_task(TaskList* task_list, char* id) {
    for(int i = 0; i < task_list->num_tasks; i++) {
        if(strcmp(task_get_id(task_list->tasks[i]), id) == 0) {
            return task_list->tasks[i];
        }
    }
    return NULL;
}

void task_list_complete_task(TaskList* task_list, char* id) {
    Task* task = task_list_get_task(task_list, id);
    if(task != NULL) {
        task_set_completed(task);
    }
}

int task_list_get_num_tasks(TaskList* task_list) {
    return task_list->num_tasks;
}

Task** task_list_get_tasks(TaskList* task_list) {
    return task_list->tasks;
}
