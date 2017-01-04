#include <iostream>

#define MAX_COMBI 10000

using namespace std;

int T, N;

int board[MAX_COMBI][8];
int start;
int target;
int fail[MAX_COMBI];

int result;
bool is_available;

bool discovered[MAX_COMBI];
int parent[MAX_COMBI];

int queue[MAX_COMBI];
int q_start_idx;
int q_end_idx;

void build_board();
void find(int n);
void process_result(int n);

bool is_valid(int n);
bool is_target(int n);

void to_digits(int n, int d[]);
int to_number(int x, int y, int z, int w);

bool empty();
void enqueue(int n);
int dequeue();



int main(void) {
    build_board();

    cin >> T;

    for (int t = 0; t < T; t++) {
        // process input data
        int tmp[4];
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
        start = to_number(tmp[0], tmp[1], tmp[2], tmp[3]);
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
        target = to_number(tmp[0], tmp[1], tmp[2], tmp[3]);

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
            fail[i] = to_number(tmp[0], tmp[1], tmp[2], tmp[3]);
        }

        // initialize states
        q_start_idx = 0;
        q_end_idx = -1;
        result = MAX_COMBI + 1;
        is_available = false;
        for (int i = 0; i < MAX_COMBI; i++) {
            discovered[i] = false;
            parent[i] = -1;
        }

        // start to turn wheels!!!
        find(start);
        if (is_available) {
            cout << result << endl;
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}

void build_board() {
    int d[4];
    for (int i = 0; i < MAX_COMBI; i++) {
        to_digits(i, d);

        board[i][0] = to_number((d[0] + 1) % 10, d[1], d[2], d[3]);
        board[i][1] = to_number((d[0] + 9) % 10, d[1], d[2], d[3]);
        board[i][2] = to_number(d[0], (d[1] + 1) % 10, d[2], d[3]);
        board[i][3] = to_number(d[0], (d[1] + 9) % 10, d[2], d[3]);
        board[i][4] = to_number(d[0], d[1], (d[2] + 1) % 10, d[3]);
        board[i][5] = to_number(d[0], d[1], (d[2] + 9) % 10, d[3]);
        board[i][6] = to_number(d[0], d[1], d[2], (d[3] + 1) % 10);
        board[i][7] = to_number(d[0], d[1], d[2], (d[3] + 9) % 10);
    }
}

void find(int n) {
    enqueue(n);
    discovered[n] = true;

    while (!empty()) {
        n = dequeue();
        if (is_target(n)) {
            is_available = true;
            process_result(n);
        }

        int m;
        for (int i = 0; i < 8; i++) {
            m = board[n][i];
            if (is_valid(m) && !discovered[m]) {
                enqueue(m);
                discovered[m] = true;
                parent[m] = n;
            }
        }
    }
}

void process_result(int n) {
    int count = 0;

    n = parent[n];
    while (n != -1) {
        count++;
        n = parent[n];
    }

    if (count < result) {
        result = count;
    }
}

bool is_valid(int n) {
    for (int i = 0; i < N; i++) {
        if (fail[i] == n) {
            return false;
        }
    }
    return true;
}

bool is_target(int n) {
    return n == target;
}

void to_digits(int n, int d[]) {
    for (int i = 3; i >= 0; i--) {
        d[i] = n % 10;
        n = n / 10;
    }
}

int to_number(int x, int y, int z, int w) {
    return (x * 1000) + (y * 100) + (z * 10) + w;
}

bool empty() {
    return q_start_idx > q_end_idx;
}

void enqueue(int n) {
    if (q_end_idx == MAX_COMBI - 1) {
        return;
    }
    queue[++q_end_idx] = n;
}
int dequeue() {
    if (empty()) {
        return -1;
    }
    return queue[q_start_idx++];
}