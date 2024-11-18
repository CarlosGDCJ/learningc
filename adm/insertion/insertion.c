#include <stdio.h>

void swap_int(void *data, int idx1, int idx2)
{
    int aux = ((int *)data)[idx2];
    ((int *)data)[idx2] = ((int *)data)[idx1];
    ((int *)data)[idx1] = aux;

}

int compare_int(void *data, int idx1, int idx2)
{
    int el1 = ((int *)data)[idx1];
    int el2 = ((int *)data)[idx2];

    if (el1 >= el2)
    {
        return 0;
    }
    return 1;

}

void insertion_sort(void *data, int (*compare) (void *, int, int), void (*swap) (void *, int, int), int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j > 0 && j < size; j--)
        {
            // if (data[j] < data[j - 1])
            if (compare(data, j, j - 1))
            {
                swap(data, j, j - 1);
            }
            else
            {
                break;
            }

        }
    }
}
int main(int argc, char **argv)
{
    int nums[100] = {66, 52, 7, 5, 88, 62, 55, 3, 41, 15, 81, 95, 15, 46, 70, 87, 39, 45, 87, 17, 43, 8, 36, 67, 53, 33, 39, 38, 59, 89, 19, 65, 81, 2, 72, 94, 7, 52, 86, 0, 12, 87, 81, 93, 4, 5, 43, 79, 9, 9, 36, 15, 66, 95, 23, 47, 34, 65, 76, 48, 69, 29, 48, 71, 28, 38, 71, 73, 32, 70, 72, 53, 8, 64, 25, 50, 92, 6, 56, 86, 66, 69, 49, 3, 98, 96, 39, 63, 97, 90, 16, 44, 74, 57, 25, 24, 24, 42, 96, 63}; 

    int size = 100;

    insertion_sort(nums, &compare_int, &swap_int, size);

    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");


    return 0;
}