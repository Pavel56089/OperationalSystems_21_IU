//
// Created by Павел Бахаруев on 14.09.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int n = rand() % 10;
    int pid;

    pid = fork();

    // pif = 0 => child process
    if (pid == 0) {
        printf("Hello from child %d - %d\n", pid, n);
    }
    else {
        printf("Hello from parent %d - %d\n", pid, n);
    }

    return 0;

}
/*
OUTPUT:
Hello from parent 7412 - 7
Hello from child 0 -7
Hello from parent 7414 - 7
Hello from child 0 - 7
Hello from parent 7416 - 7
Hello from child 0 - 7
Hello from parent 7418 - 7
Hello from child 0 - 7
Hello from parent 7420 - 7
Hello from child 0 - 7
Hello from parent 7422 - 7
Hello from child 0 - 7
Hello from parent 7424 - 7
Hello from child 0 - 7
Hello from parent 7426 - 7
Hello from child 0 - 7
Hello from parent 7428 - 7
Hello from child 0 - 7
Hello from parent 7430 - 7
Hello from child 0 - 7

Unique parent^s pid increases every time. Child^s pids are zero always.
*/