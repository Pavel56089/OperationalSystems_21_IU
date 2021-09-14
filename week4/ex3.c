//
// Created by Павел Бахаруев on 14.09.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int size = 100;
    char input[size];
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "^Z") == 0){
            return 0;
        }
        system(input);
    }

}
