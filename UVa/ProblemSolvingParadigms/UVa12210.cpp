#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
#define MAXN 10000
using namespace std;

typedef multiset<int> msi;
int B, S, t;
msi s;
multiset<int, greater<int>> b;

int main(){
    //freopen("in.txt", "r", stdin);
    int cnt = 1;
    for(;scanf("d %d", &B, &S) && B|S;){
        printf("Case %d:", cnt++);
        b.clear(); s.clear();
        fori(i, B){
            scanf("%d", &t);
            b.insert(t);
        }fori(i, S){
            scanf("%d", &t);
            s.insert(t);
        }
        if(B <= S) printf(" %d\n", 0);
        else{
            for(;b.size() && s.size();){
                int bach = *(b.begin());
                msi::iterator spn = s.lower_bound(bach);
                if(spn == s.end())
                    spn--;
                else if(spn != s.begin()){
                    msi::iterator prev = spn; prev--;
                    if(abs(bach-*prev) < abs(bach-*spn))
                        spn = prev;
                }
                b.erase(b.begin()); s.erase(spn);
            }

            int lowest = 1<<30;
            for(int bach : b){
                lowest = min(bach, lowest);
            }
            printf(" %d %d\n", b.size(), lowest);
        }
    }
    return 0;
}
