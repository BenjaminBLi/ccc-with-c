#include <bits/stdc++.h>
using namespace std;

int n, k, pre[2010], marks[2010], scores[2010];
map<int, int> points, score;
set<int> vals;

int main() {
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", marks + i);
        pre[i] = marks[i];
        if(i) pre[i] += pre[i-1];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", scores+i);
        points[scores[i]] = i;
    }

    for (int c = 0; c < n; c++) {

    }
    printf("%d\n", vals.size());

    return 0;
}
