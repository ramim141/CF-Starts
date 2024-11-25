#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("file.txt", "w"); // Open file in write mode

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fptr, "Hello, world!\n");
    fclose(fptr);

    fptr = fopen("file.txt", "r");
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    fclose(fptr);

    return 0;
}
