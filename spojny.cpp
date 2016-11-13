#include <stdio.h>
#include <assert.h>

// Shortest version
#define I int
I y(I n,I*a,I*p){I b=0;for(I k;k<n;k++){I t=0;I l=k;while(!a[k]&&k<n){t++;k++;}if(t>b){*p=l;b=t;}}return b;}
// More interesting attempt not using for/while
// Not sure if it works 100%. If you can crash this I'll be happy to know
// It needs c++ compiler. You can compile this with $gcc spojny.cpp (But not with $gcc spojny.c)
I f(I i,I n,I*a,I*k,I*t,I*b,I*p){return(i>n)?*b:f(i+1,n,a,&(*k=(((!a[i+1]&&!*t)?i+1:*k))),&(*t=(a[i]==0)?(*t)+1:0),&(*b=(*t>*b)?*t:*b),&(*p=(*t>*b)?*k:*p));}I g(I n,I*a,I*p){I t=0;I k=0;I b=0;return f(0,n,a,&k,&t,&b,p);}

// Normal version
int max_sbstr(int n, int a[], int *pos) {
    int best = 0;
    int best_pos = -1;

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        int tmp_pos = i;

        while ((i < n) && (a[i] == 0))
        {
            tmp++;
            i++;
        }

        if (tmp > best) {
            best_pos = tmp_pos;
            best = tmp;
        }
    }

    *pos = best_pos;
    return best;
}

void test(int n, int *a){
    int posY = 0;
    int posG = 0;
    int resultY, resultG;
    printf("[test] { ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("}\n");

    resultY = y(n, a, &posY);
    resultG = g(n, a, &posG);

    assert(resultY == resultG);
    assert(posY == posG);

    printf("resultY: %d, resultG: %d\n", resultY, resultG);
    printf("posY:    %d, posG:    %d\n", posY, posG);
}

int main()
{
    int a[6]  = {0, 0, 0, 0, 0, 0};
    int b[11] = {0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 5};
    int c[7]  = {3, 3, 3, 3, 3, 3, 3};
    int d[5]  = {1, 2, 3, 4, 0};
    int e[5]  = {0, 1, 2, 3 ,4};
    int f[13] = {1, 0, 2, 3, 0, 0, 4, 5, 0, 0, 0, 0, 0};

    test(6,a);
    test(11,b);
    test(7,c);
    test(5,d);
    test(5,e);
    test(13,f);

    return 0;
}
