#include <bits/stdc++.h>
using namespace std;

int n, a, freq[100010], cnt =0;
set<int> emps;
unordered_map<int, int> id;

int main() {
    scanf("%d", &n);
    scanf("%d", &a);
    emps.insert(a);
    id[a]=cnt++;
    bool ok = true;
    for(int i =1; i < n; i++) {
        scanf("%d", &a);
        auto it = emps.upper_bound( a);
        if (it != emps.begin()) it--;
        if (*it >= a) {
            ok = false;
            break;
        }
        if (freq[id[*it]] == 1) emps.erase(it);
        freq[id[*it]]++;
        emps.insert(a);
        id[a]=cnt++;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}