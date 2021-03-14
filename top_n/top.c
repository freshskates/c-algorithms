#include <stdio.h>
void print(int arr[], int topn)
{
    printf("Top %d elements: \n", topn);
    for (int i = 0; i < topn; i++)
        printf("%d ", arr[i]);
}

void top_n(int a[], int array_size, int topn)
{
    int b[topn], min, index;
    for (int i = 0; i < topn; i++)
        b[i] = a[i];
    for (int k = topn; k < array_size; k++)
    {
        min = b[0], index = 0;
        for (int j = 0; j < topn; j++)
            if (min > b[j])
                min = b[j], index = j;
        if (a[k] > min)
            b[index] = a[k];
    }
    print(b, topn);
}

int main()
{
    int topn = 10;
    int array_size = 30;
    int arr[] = {2, 3, 5, 6, 1, 2, 3, 5, 7, 4, 23, 123, 54, 64, 123, 21, 999, 54, 34, 76, 45, 87, 98, 34, 234, 12, 43, 54, 23, 12, 43};
    top_n(arr, array_size, topn);
}
