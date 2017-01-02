#include <bits/stdc++.h>
using namespace std;

int n, arr[1001], t, m;

int main(){
    int cse = 1;
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) != EOF && n != 0){
        printf("Case %d:\n", cse++);
        //cout << n << endl;
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        //for(int i = 0;i < n; i++) cout << arr[i] << " ";
        //cout << endl;
        scanf("%d", &m);
        for(int i = 0;i < m; i++){
            scanf("%d", &t);
            int bdiff = 1<<30, best;
            //cout << bdiff;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j != i){
                        if(abs(t-(arr[i]+arr[j])) < bdiff){
                            //cout << "YES" << endl;
                            bdiff = abs(t-(arr[i]+arr[j])); best = arr[i]+arr[j];
                        }
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", t, best);
        }
    }
    return 0;
}
