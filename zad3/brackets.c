#include <stdio.h>
#include <stdbool.h>

const int max_length = 10000;

bool is_opposite(char l, char r) {
    char opposite;

    switch(l)
    {
        case '(': opposite = ')'; break;
        case ')': opposite = '('; break;
        case '>': opposite = '<'; break;
        case '<': opposite = '>'; break;
        case '{': opposite = '}'; break;
        case '}': opposite = '{'; break;
        case '[': opposite = ']'; break;
        case ']': opposite = '['; break;
    }
    return r == opposite;
}

bool stack_empty(int pos) {
    return pos == -1;
}

int main()
{
    char input[max_length];
    char stack[max_length];
    int stack_pos = -1;

    scanf("%s", input);

    for (int i = 0; i < max_length; i++) {
        if (input[i] == 0)
            break;
        if (!stack_empty(stack_pos)) {
            if (is_opposite(input[i], stack[stack_pos])) {
                stack_pos--;
            }
            else {
                stack[++stack_pos] = input[i];
            }
        } else {
            stack[++stack_pos] = input[i];
        }
    }

    if (stack_empty(stack_pos))
        printf("CORRECT BRACKETS\n");
    else
        printf("INCORRECT BRACKETS\n");
}
