#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

#define LEN 128

void print_arr(int* arr, int len);
void make_random(int* arr, int len);
void selection_sort(int* arr, int len);
void swap(int* a, int* b);

int main(int argc, char** argv)
{
    int i;
    int* arr = malloc(sizeof(int) * LEN);
    srand(time(NULL));

    make_random(arr, LEN);
    puts("original");
    print_arr(arr, LEN);
    puts("\n");

    selection_sort(arr, LEN);
    puts("sorted!");
    print_arr(arr, LEN);

    return 0;
}

void make_random(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
        arr[i] = rand() % len;
}

void selection_sort(int* arr, int len)
{
    int min_index, min, i, j;
    for (i = 0; i < len; ++i)
    {
        min = INT_MAX, min_index = i;
        for (j = i + 1; j < len; ++j)
            if (arr[j] < min)
                min = arr[j], min_index = j;
        swap(arr + i, arr + min_index);
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
}
