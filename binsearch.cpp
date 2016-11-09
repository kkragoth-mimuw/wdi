#include <cstdio>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<int> A = {1, 1, 1, 2, 2, 34, 37, 45, 78, 113, 122, 256, 333, 444};

int binsearch(int v) {
    int l = 0;
    int r = A.size() - 1;
    int m;

    while ((l <= r)) {
        m = (r + l ) / 2;

        std::cout << l << " " << m << " " << r << std::endl;

        if (A[m] == v) {
            return m;
        }

        if (v > A[m]) {
            l = m + 1;
        } else if (A[m] > v){
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    std::cout << "binsearch(1): "  << binsearch(1) << std::endl;
    std::cout << "binsearch(13): " << binsearch(13) << std::endl;
    std::cout << "binsearch(256): " << binsearch(256) << std::endl;
    return 0;
}
