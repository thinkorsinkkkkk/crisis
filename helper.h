//
// Created by john on 17/01/2023 AD.
//

#ifndef COOKIES_HELPER_H
#define COOKIES_HELPER_H
#include <mach/arm/thread_status.h>
#include <mach/mach_vm.h>
#include <sys/types.h>

arm_unified_thread_state_t get_state(thread_read_t target);
thread_act_array_t get_threads(task_t task, mach_msg_type_number_t count);
vm_map_read_t get_task(pid_t pid);
vm_offset_t read(vm_address_t address, vm_map_read_t task, mach_msg_type_number_t size);
void write(vm_map_read_t task, vm_address_t address, vm_offset_t data);
#endif //COOKIES_HELPER_H
