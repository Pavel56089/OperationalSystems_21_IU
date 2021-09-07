#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* a, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}


int main(void)
{
	int a[10] = { 10, 9, 8, 7, 5, 6, 4, 3, 2, 1};
	bubble_sort(a, 10);
	for (int i = 0; i < 6; i++){
        printf("%d\n", arr[i]);
	}
	return 0;
}
