//
// Created by Павел Бахаруев on 19.10.2021.
//
#include<stdio.h>
#include<stdlib.h>

int agingAlgorithm(int pageFrames) {
    FILE *file = fopen("input.txt", "r");
    int c = 0, hit = 0, miss = 0, temp;
    while (fgetc(file) != EOF){
        fscanf(file, "%d", &temp);
        c++;
    }
    fclose(file);
    file = fopen("input.txt", "r");
    int *arr = calloc(c, sizeof(int));
    int *age = calloc(pageFrames, sizeof(int));
    int *frame = calloc(pageFrames, sizeof(int));
    //Look at all ages
    for (int i = 0; i < c; i++){
        fscanf(file, "%d", &arr[i]);
        int free = 0, hitted = 0;
        for(int j = 0; j < pageFrames; j++){
            age[j] = age[j] >> 1;
            if (frame[j] == arr[i] && hitted != 1){
                age[j] += (1<<31);
                hit++;
                hitted = 1;
            }
        }
        //First case
        if (!hitted){
            for(int j = 0; j < pageFrames; j++){
                if (frame[j] == 0){
                    frame[j] = arr[i];
                    age[j] = 1<<31;
                    miss++;
                    free = 1;
                    break;
                }
            }
        }
        //Second case
        if (!free && !hitted){
            int ind = 0;
            int min = age[0];
            for (int j = 1; j < pageFrames; j++){
                if (age[j] < min){
                    min = age[j];
                    ind = j;
                }
            }
            frame[ind] = arr[i];
            age[ind] = 1<<31;
            miss++;
        }
    }
    fclose(file);
    printf("Hit/Miss ratio: %f\n", (double) hit/miss);
    return 0;
}
int main(){
    agingAlgorithm(10);
    agingAlgorithm(50);
    agingAlgorithm(100);
}
