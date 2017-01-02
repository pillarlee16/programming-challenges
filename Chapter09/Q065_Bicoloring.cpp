#include <iostream>

#define MAX_VERTICES 200
#define MAX_DEGREES 200

#define NONE 0
#define RED 1
#define BLACK 2

using namespace std;

typedef struct {
    int edges[MAX_VERTICES][MAX_DEGREES];
    int degrees[MAX_VERTICES];
    int colors[MAX_VERTICES];       // 0: none, 1: red, 2: black
    int nvertices;
    int nedges;
} graph;

bool result;
void painting(graph *g, int v, int color);

int main(void) {
    int N, L;       // Number of vertices, Number of edges
    int i, j, k;    // counter
    int x, y;       // input vertices;

    graph G;

    cin >> N;
    while (N != 0) {
        cin >> L;

        // initialize graph
        G.nvertices = N;
        G.nedges = L;
        for (i = 0; i < N; i++) {
            G.colors[i] = NONE;
            G.degrees[i] = 0;
        }

        for (i = 0; i < L; i++) {
            cin >> x >> y;

            G.edges[x][G.degrees[x]] = y;
            G.degrees[x]++;
            G.edges[y][G.degrees[y]] = x;
            G.degrees[y]++;
        }
        result = true;
        painting(&G, 0, RED);

        if (result) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }

        cin >> N;
    }

    return 0;
}

void painting(graph *g, int v, int color) {
    if (!result) {
        return;
    }

    if (g->colors[v] > 0) {
        if (g->colors[v] != color) {
            result = false;
            return;
        }
    } else {
        int i;
        int t;
        int next;

        g->colors[v] = color;
        next = (color == RED) ? BLACK : RED;

        for (i = 0; i < g->degrees[v]; i++) {
            t = g->edges[v][i];
            painting(g, t, next);
        }
    }
}