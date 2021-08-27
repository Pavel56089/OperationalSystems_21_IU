//
// Created by Павел Бахаруев on 27.08.2021.
//
#include <stdio.h>

void swap(int *v1, int *v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int main(void)
{
    int num1, num2;
    int pred, npred;
    pred = -1;
    scanf( "%d", &num1 );
    scanf( "%d", &num2 );
    swap(&num1, &num2);
    printf("%d, %d", num1, num2);
    return 0;
}
