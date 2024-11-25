#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(5 * sizeof(int)); // Allocate memory for 5 integers

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr); // Deallocate memory
    return 0;
}
