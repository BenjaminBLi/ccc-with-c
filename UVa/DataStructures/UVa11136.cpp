#include <bits/stdc++.h>
using namespace std;

int n, t, k;
multiset<int> bills;

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) && n){
        long long total = 0LL;
        bills.clear();
        for(int i = 0;i < n; i++){
            scanf("%d", &k);
            for(int i =0; i < k; i++){
                scanf("%d", &t);
                bills.insert(t);
            }
            total += *bills.rbegin() - *bills.begin();
            bills.erase(bills.find(*bills.begin()));
            bills.erase(bills.find(*bills.rbegin()));
        }
        printf("%lld\n", total);
    }
    return 0;
}
