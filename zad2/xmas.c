#include <stdio.h>

const int MAX_BASE_WIDTH = 3;
const int MIN_BASE_WIDTH = 1;
const int BASE_HEIGHT    = 3;

int main()
{
    int height;
    printf("Input height:\n");
    scanf("%d", &height);

    if (height < 0) {
        printf("Invalid argument: negative height; exiting...\n");
        return 1;
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)  printf ("*");
        printf("\n");
    }

    int base_width = (height > MAX_BASE_WIDTH) ? MAX_BASE_WIDTH : MIN_BASE_WIDTH;

    for (int h = 0; h < BASE_HEIGHT; h++) {
        for (int i = 0; i <= height - base_width; i++) printf(" ");
        for (int j = 1; j <= base_width; j++)          printf("+");
        printf("\n");
    }
}

