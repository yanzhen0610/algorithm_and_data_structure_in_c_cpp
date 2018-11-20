#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LEN 128

void print_arr(int* arr, int len);
void make_random(int* arr, int len);
void bubble_sort(int* arr, int len);
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

    bubble_sort(arr, LEN);
    puts("sorted!");
    print_arr(arr, LEN);

    return 0;
}

void make_random(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
        arr[i] = rand() % len;
}

void bubble_sort(int* arr, int len)
{
    int swapped = 0;
    int i;
    do
    {
        i = 0;
        swapped = 0;
        while (++i < len)
        {
            if (arr[i-1] > arr[i])
            {
                swapped = 1;
                swap(arr + i - 1, arr + i);
            }
        }
    } while (swapped);
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
