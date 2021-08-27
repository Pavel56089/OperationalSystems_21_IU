//
// Created by Павел Бахаруев on 27.08.2021.
//
#include <stdio.h>

int main(void)
{
    int num;
    int pred, npred;
    pred = -1;
    scanf( "%d", &num );
    for (int i = 0;i<num;i++){
        npred = 0;
        for (int j=0;j < (num - i);j++){
            printf(" ");
        }
        for (int j=0;j<2+pred;j++){
            printf("*");
            npred++;
        }
        for (int j=0;j < (num - i);j++){
            printf(" ");
        }
        pred = npred;
        printf("\n");
    }
    return 0;
}
