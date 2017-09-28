#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2000005;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(string s,int len) {
    int l = 0;
    Ma[l++] = '$', Ma[l++] = '#';
    for (int i = 0; i < len; i++)
        Ma[l++] = s[i], Ma[l++] = '#';
    Ma[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i < l; i++) {
        Mp[i] = (mx > i ? min(Mp[2 * id - i], mx - i) : 1);
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])Mp[i]++;
        if (i + Mp[i] > mx)mx = i + Mp[i], id = i;
    }
}
string s;
ll st[MAXN*2],ed[MAXN*2];
int main() {
    int n;
    cin >> s;
    n = s.size();
    Manacher(s, n);
    for (int i = 1; i <= 2 * n + 1; i++) {
        st[i - Mp[i] + 1]++, st[i + 1]--;
        ed[i]++, ed[i + Mp[i]]--;
    }
    for (int i = 1; i <= 2 * n + 1; i++)
        st[i] += st[i - 1], ed[i] += ed[i - 1];
    for (int i = 1; i <= n; i++)
        st[i] = st[i * 2], ed[i] = ed[i * 2];
    ll res = 0;
    for (int i = 1; i <= n; i++)
        ed[i] += ed[i - 1];
    for (int i = 1; i < n; i++)
        res = (res + 1LL * ed[i] * st[i + 1]);
    return 0 * printf("%lld", res);
}
