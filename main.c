#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 256;
    pid_t pid = getpid();
    printf("Address: %p\n", &n);
    printf("PID: %d\n", pid);
    printf("============\n");
    printf("Before change: %i", n);
    getchar();
    printf("After change: %i\n", n);
}