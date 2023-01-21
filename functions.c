//
// Created by john on 17/01/2023 AD.
//

#include "functions.h"
#include "helper.h"
#include <stdio.h>
#include <sys/types.h>
#include <mach/mach.h>

void read_address() {
    pid_t pid;
    vm_address_t address;
    printf("PID: ");
    scanf("%d", &pid);
    printf("Address: ");
    scanf("%lx", &address);
    vm_map_read_t task = get_task(pid);
    mach_msg_type_number_t size = sizeof(int);
    vm_offset_t data = read(address, task, sizeof(int));
    for (size_t x=0;x<size;x++) {
        printf("%hhx\n", ((char*)data)[x]);
    }
}

void write_address() {
    pid_t pid;
    vm_address_t address;
    vm_offset_t data;
    printf("PID: ");
    scanf("%d", &pid);
    printf("Address: ");
    scanf("%lx", &address);
    printf("New integer: ");
    scanf("%ld", &data);
    vm_map_read_t task = get_task(pid);
    write(task, address, data);
}