#include <stdio.h>
#include <stdlib.h>

int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
    *result_count = arr_count;
    int* result = malloc(sizeof(int) * arr_count);
    
    int rotations = d;

    if (d > arr_count)
        rotations = d % arr_count;

    for (int i = 0; i < arr_count; i++) {
        if (i + rotations < arr_count) {
            *(result + i) = *(arr + i + rotations);
        }
        else {
            *(result + i) = *(arr + i - (arr_count - d));
        }
    }

    return result;
}

int main() {
    int n = 5;
    int rotations = 4;
    int array[5] = {1, 2, 3, 4, 5};
    int resultCount;

    int* result = rotateLeft(rotations, n, array, &resultCount);

    for (int i = 0; i < resultCount; i++) {
        printf("%d", result[i]);

        if (i < resultCount - 1)
            printf(" ");
    }

    return 0;
}

