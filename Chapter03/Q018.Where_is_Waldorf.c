#include <stdio.h>
#include <string.h>

#define MEM 256
#define MAX_GRID 50

static char grids[MAX_GRID][MAX_GRID];
static int n_row, n_col;

int find_match(char word[], int start_i, int start_j) {
    static int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    static int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    int i, j, t, dir;

    for (dir = 0; dir < 8; dir++) {
        i = start_i;
        j = start_j;
        t = 0;
        while (i >= 0 && i < n_row && j >= 0 && j < n_col
            && word[t] != '\0' && word[t] == grids[i][j]) {
            i += di[dir];
            j += dj[dir];
            t++;
        }
        if (word[t] == '\0') {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int cases, t, i, j, k;
    int found;
    char line[MEM], word[MEM];
    
    scanf("%d", &cases);
    for (t = 0; t < cases; t++) {
        if (t > 0) putchar('\n');

        gets(line);

        // read grids
        scanf("%d %d", &n_row, &n_col);
        gets(line);
        for (i = 0; i < n_row; i++) {
            for (j = 0; j < n_col; j++) {
                grids[i][j] = getchar();
                if (grids[i][j] >= 'A' && grids[i][j] <= 'Z') {
                    grids[i][j] += ('a' - 'A');
                }
            }
            gets(line);
        }

        // read word
        scanf("%d", &k);
        gets(line);
        while (k-- > 0) {
            gets(word);
            for (i = 0; i < strlen(word); i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') word[i] += ('a' - 'A');
            }

            // find match
            found = 0;
            for (i = 0; i < n_row; i++) {
                for (j = 0; j < n_col; j++) {
                    found = find_match(word, i, j);
                    if (found) {
                        printf("%d %d\n", i+1, j+1);
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
}