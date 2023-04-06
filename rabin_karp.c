#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

void search(char* pat, char* txt, int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern. 
        // If the hash values match then only check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            // If p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char txt[] = "aaacdfgeacbmaacabb";
    char pat[] = "acabb";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}
