#include <iostream>

using namespace std;

int main(void) {
    int N, M;
    int game = 0;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        if (game > 0) {
            cout << endl;
        }
        game++;
        
        int result[102][102];
        for (int i = 0; i <= N+1; i++) {
            for (int j = 0; j <= M+1; j++) {
                result[i][j] = 0;
            }
        }

        char map[102][102];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> map[i][j];

                if (map[i][j] == '*') {
                    result[i-1][j-1]++;     // up-left
                    result[i-1][j]++;       // up
                    result[i-1][j+1]++;     // up-right
                    result[i][j-1]++;       // left
                    result[i][j+1]++;       // right
                    result[i+1][j-1]++;     // down-left
                    result[i+1][j]++;       // down
                    result[i+1][j+1]++;     // down-right
                }
            }
        }

        cout << "Field #" << game << ":" << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (map[i][j] == '*') {
                    cout << map[i][j];
                } else {
                    cout << result[i][j];
                }
            }
            cout << endl;
        }
    }
}