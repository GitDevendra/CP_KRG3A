#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern) {
    int d = 256;       // number of characters
    int q = 101;       // prime number
    int n = text.length();
    int m = pattern.length();
    int p = 0;         // hash for pattern
    int t = 0;         // hash for text
    int h = 1;

    // Calculate h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++) {

        // If hash matches, check characters
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABC";

    rabinKarp(text, pattern);
}
