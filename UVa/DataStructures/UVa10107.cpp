#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> lst;

int main() {
    while(scanf("%d", &n) == 1) {
        lst.push_back(n);
        sort(lst.begin(), lst.end());
        if(lst.size() % 2 == 0) {
            printf("%d\n", (lst[lst.size() / 2] + lst[lst.size() / 2 - 1]) / 2);
        } else printf("%d\n", lst[lst.size() / 2]);
    }
}
