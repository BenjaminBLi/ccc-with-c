#include <bits/stdc++.h>
using namespace std;

int C, d, k, T, curr, arr[30];
long long res, cnt, num;
string line; stringstream ss;
long long calc(int n){
    long long ret = 0;
    for(int i = 0; i < T; i++){
        ret += arr[i]*pow(n, i);
    }
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &C);
    for(;C--;){
        scanf("%d", &T);
        T++;
        for(int i = 0; i < T; i++) scanf("%d", &arr[i]);
        scanf("%d %d", &d, &k);
        cnt = 0, curr = 1;
        //cout << calc(1) <<endl;
        while(true){
            num = calc(curr);
            //cout << num << endl;
            cnt += d*curr;
            if(cnt >= k){
                res = num;
                break;
            }
            curr++;
        }
        printf("%lld\n", res);
        //cout << endl;

    }
    return 0;
}
