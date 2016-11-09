#include <stdio.h>

int max_sbstr(int n, int a[], int *pos) {
    int count_if = 0;
    int count_assign = 0;

    int best = 0;
    int best_pos = -1;


    for (int i = 0; i < n; i++) {
        int tmp = 0;
        int tmp_pos = i;

        while ((i < n) && (++count_if) && (a[i] == 0))
        {
            tmp++;
            i++;
        }

        if (tmp > best) {
            ++count_assign;
            best_pos = tmp_pos;
            best = tmp;
        }
    }

    printf("[count_op] = %d\n [count_assign] = %d\n", count_if, count_assign);
    *pos = best_pos;
    return best;
}


int main()
{
    int b[11] = {0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 5};
    int pos = 0;

    int result = max_sbstr(10, b, &pos);
    printf("%d %d\n", result, pos);

    return 0;
}
