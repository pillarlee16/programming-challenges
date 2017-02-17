#include <stdio.h>
#include <string.h>

char* keyboard[4];
char fix_typing(char c);

int main(void) {
    char c;

    keyboard[0] = "`1234567890-=";
    keyboard[1] = "QWERTYUIOP[]\\";
    keyboard[2] = "ASDFGHJKL;'";
    keyboard[3] = "ZXCVBNM,./";

    while (!feof(stdin)) {
        int i;
        char temp[500];

        if (!gets(temp)) break;

        for (i = 0; i < (int)strlen(temp); i++) {
            printf("%c", fix_typing(temp[i]));
        }
        printf("\n");
    }

    return 0;
}

char fix_typing(char c) {
    if (c == ' ') return c;

    int i, j;
    char k;

    for (i = 0; i < 4; i++) {
        j = 0;
        while ((k = keyboard[i][j]) != '\0') {
            if (c == k) return keyboard[i][j-1];
            j++;
        }
    }

    return '\0';
}