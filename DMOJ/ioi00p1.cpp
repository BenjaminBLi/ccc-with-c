#include <bits/stdc++.h>
using namespace std;

int N, memo[2][5010];
string str;

int main() {
    cin >> N >> str;
    for (int l = 1; l <= N; l++) {
        for (int r = 1; r <= N; r++) {
            if (str[l - 1] == str[N - r]) memo[l & 1][r] = memo[(l - 1) & 1][r - 1] + 1;
            else memo[l & 1][r] = max(memo[(l - 1) & 1][r], memo[l & 1][r - 1]);
        }
    }
    printf("%d\n", N - memo[N & 1][N]);
    return 0;
}