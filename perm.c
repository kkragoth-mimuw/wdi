#include <stdio.h>

#define N 4

void perm(int pos, int n, int tmp[], int a[])
{
	if (pos == n) {
		printf("\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", tmp[i]);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int used = 0;
			for (int j = 0; j < pos; j++) {
				if (a[i] == tmp[j])
					used = 1;
			}
			if (!used) {
				tmp[pos] = a[i];
				perm(pos+1, n, tmp, a);
			}
		}
	}
}

int main()
{
	int A[N];
	for (int i = 0; i < N; i++) {
		A[i] = i+1;
	}

	int tmp[N];

	perm(0, N, tmp, A);
}
