#include <iostream>

#define MAXN 100

using namespace std;

int graph[MAXN][MAXN];
int maxin[MAXN];
int result;

int N, R;
int S, D, T;

bool processed[MAXN];

int input();
void solve();

int main(void) {

    int i = 1;
    while (input()) {
        solve();

        cout << "Scenario #" << i++ << endl;
        cout << "Minimum Number of Trips = " << result << endl << endl;
    }
    return 0;
}

int input() {
    cin >> N >> R;
    if (N == 0 && R == 0) {
        return 0;
    }

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }

    int c1, c2, p;
    for (i = 0; i < R; i++) {
        cin >> c1 >> c2 >> p;
        graph[c1-1][c2-1] = p;
        graph[c2-1][c1-1] = p;
    }

    cin >> S >> D >> T;
    S = S - 1;
    D = D - 1;

    return 1;
}

void solve() {
    int i, j, k;

    for (i = 0; i < N; i++) {
        maxin[i] = -1;
        processed[i] = false;
    }

    maxin[S] = 999999;
    for (i = 0; i < N; i++) {
        k = -1;
        for (j = 0; j < N; j++) {
            if (!processed[j] && (k == -1 || maxin[k] < maxin[j])) {
                k = j;
            }
        }

        processed[k] = true;

        for (j = 0; j < N; j++) {
            if (graph[k][j] == 0 || processed[j]) {
                continue;
            }

            int v = graph[k][j];
            if (maxin[k] < v) {
                v = maxin[k];
            }
            if (v > maxin[j]) {
                maxin[j] = v;
            }
        }
    }

    result = T / (maxin[D]-1);
    if (T % (maxin[D]-1) > 0) {
        result++;
    }
}
