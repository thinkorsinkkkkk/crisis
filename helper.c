#include <mach/mach.h>
#include <mach/mach_vm.h>
#include <mach/arm/thread_status.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

arm_unified_thread_state_t get_state(thread_read_t target) {
    arm_unified_thread_state_t state;
    mach_msg_type_number_t stateCnt = ARM_UNIFIED_THREAD_STATE_COUNT;
    kern_return_t res = thread_get_state(target, ARM_UNIFIED_THREAD_STATE, (thread_state_t) &state, &stateCnt);
    if (res) {
        fprintf(stderr, "can't get state, result %s\n", mach_error_string(res));
        exit(-1);
    }
    return state;
}


thread_act_array_t get_threads(task_t task, mach_msg_type_number_t count) {
    thread_act_array_t act_list[count];
    kern_return_t res = task_threads(task, act_list, &count);
    if (res) {
        fprintf(stderr, "can't get thread, result %s\n", mach_error_string(res));
        exit(-1);
    }
    return *act_list;
}

vm_map_read_t get_task(pid_t pid) {
    vm_map_read_t task;
    task_for_pid(current_task(), pid, &task);
    return task;
}

vm_offset_t read(vm_address_t address, vm_map_read_t task, mach_msg_type_number_t size) {
    vm_offset_t data;
    kern_return_t res = vm_read(task, address, (pointer_t)sizeof(int), &data, &size);
    if (res) {
        fprintf(stderr, "can't read, result %s\n", mach_error_string(res));
        exit(-1);
    }
    return data;
}

void write(vm_map_read_t task, vm_address_t address, vm_offset_t data) {
    kern_return_t res = vm_write(task, address, &data, sizeof(int));
    if (res) {
        fprintf(stderr, "can't write, result %s\n", mach_error_string(res));
        exit(-1);
    }
    else {
        printf("Success!\n");
    }
}
