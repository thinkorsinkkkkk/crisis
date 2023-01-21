#include <stdio.h>
#include "functions.h"

int main() {
    printf("hewwo welcome to my silly program uwu pls choose what u wanna do \n");
    printf("[1] read address\n");
    printf("[2] write to address\n");
    printf("[3] get stack pointer\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        read_address();
    }
    else if (choice == 2) {
        write_address();
    }
    else if (choice == 3) {
        get_stack_pointer();
    }
    else {
        printf("don't be dumb and make a choice\n");
    }
}
