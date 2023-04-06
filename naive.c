#include <stdio.h>
#include <string.h>

void naiveMethod(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);
    int i, j;
    for (i = 0; i < n - m + 1; i++) {
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == m) {
            printf("We found pattern at index %d\n", i);
        }
    }
}

int main() {
    char txt[] = "aaacdfgeacbmaacabb";
    char pat[] = "acabb";
    naiveMethod(txt, pat);
    return 0;
}
