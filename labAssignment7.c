#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element)*size);
    for(int i = 0; i < size; i++)
    {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(swaps[j].data > swaps[j + 1].data)
            {
                int temp = swaps[j].data;
                swaps[j].data = swaps[j + 1].data;
                swaps[j + 1].data = temp;
                swaps[j].numswaps++;
            }
        }
    }
    return swaps;
}

element* numSwapsSelectionSort(int* arr, int size)
{
    element* swaps = (element*)malloc(sizeof(element) * size);
    for (int i = 0; i < size; i++)
    {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(swaps[j].data < swaps[min].data)
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = swaps[i].data;
            swaps[i].data = swaps[min].data;
            swaps[min].data = temp;
            swaps[i].numswaps++;
        }
    }
    return swaps;
}

int main()
{
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    element* bubbleSwap1 = numSwapsBubbleSort(arr1, size);
    element* bubbleSwap2 = numSwapsBubbleSort(arr2, size);

    element* selectionSwap1 = numSwapsSelectionSort(arr1, size);
    element* selectionSwap2 = numSwapsSelectionSort(arr2, size);

    printf("array1 bubble sort:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d: %d\n", bubbleSwap1[i].data, bubbleSwap1[i].numswaps);
    }

    int totalBubbleArr1 = 0;
    for(int i = 0; i < size; i++)
    {
        totalBubbleArr1 += bubbleSwap1[i].numswaps;
    }
    printf("%d\n\n", totalBubbleArr1);

    printf("array2 bubble sort:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", bubbleSwap2[i].data, bubbleSwap2[i].numswaps);
    }

    int totalBubbleArr2 = 0;
    for(int i = 0; i < size; i++)
    {
        totalBubbleArr2 += bubbleSwap2[i].numswaps;
    }
    printf("%d\n\n", totalBubbleArr2);

    printf("array1 selection sort\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d: %d\n", selectionSwap1[i].data, selectionSwap1[i].numswaps);
    }

    int totalSelectionArr1 = 0;
    for(int i = 0; i < size; i++)
    {
        totalSelectionArr1 += selectionSwap1[i].numswaps;
    }
    printf("%d\n\n", totalSelectionArr1);

    printf("array2 selection sort\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d: %d\n", selectionSwap2[i].data, selectionSwap2[i].numswaps);
    }

    int totalSelectionArr2 = 0;
    for(int i = 0; i < size; i++)
    {
        totalSelectionArr2 += selectionSwap2[i].numswaps;
    }
    printf("%d\n\n", totalSelectionArr2);

    free(bubbleSwap1);
    free(bubbleSwap2);
    free(selectionSwap1);
    free(selectionSwap2);

    return 0;
}
