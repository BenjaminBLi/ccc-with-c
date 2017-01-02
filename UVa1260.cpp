#include <bits/stdc++.h>
using namespace std;

int T, n, arr[1000];

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int sum = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++) if(arr[j] <= arr[i]) sum++;
            //cout << sum << endl;
        }
        printf("%d\n", sum);
    }
    return 0;
}
