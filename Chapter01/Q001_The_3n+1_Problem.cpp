#include <cstdio>

using namespace std;

long find_cycle(long n) {
    long cycle = 1;
    while (n != 1) {
        if (n % 2) {
            n = n * 3 + 1;
            cycle++;
        }
        while (!(n % 2)) {
            n = n / 2;
            cycle++;
        }
    }
    return cycle;
}

int main(void) {
    long N, M;
    while (scanf("%ld %ld", &N, &M) == 2) {
        long _N = N;
        long _M = M;
        if (N > M) {
            long tmp = M;
            M = N;
            N = tmp;
        }

        long max_cycle = 0;
        long cycle;
        for (long k = N; k <= M; k++) {
            cycle = find_cycle(k);
            if (cycle > max_cycle) {
                max_cycle = cycle;
            }
        }
        printf("%ld %ld %ld\n", _N, _M, max_cycle);
    }

    return 0;
}