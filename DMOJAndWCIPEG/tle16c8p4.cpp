#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int X, D, P, N, W;
ii planet[100010];
ll MOD = (ll) 1e9 + 7, memo[100010];

int main(){
    scanf("%d", &X);
    //cout << "DONE" << endl;
    if(X == 1){
        scanf("%d %d %d", &D, &N, &P);
        //cout << "DONE" << endl;
        planet[0] = ii(0, N);
        for(int i = 1; i <= P; i++) scanf("%lld %lld", &planet[i].first, &planet[i].second);
        planet[P+1] = ii(D, 0);
        sort(planet, planet+P+2);
        memo[P+1] = 1;
        for(int i = P; i > 0; i--){
            int idx = upper_bound(planet, planet+P+2, ii(planet[i].first+planet[i].second, 0x3f3f3f))-planet-1;
            memo[i] += 2*memo[i + 1]%MOD - memo[idx + 1]%MOD;
            memo[i] %= MOD;
            if(memo[i] < 0) memo[i] += MOD;
        }
        memo[0] = memo[1]-memo[(int)(upper_bound(planet, planet+P+2, ii(planet[0].first+planet[0].second, 0x3f3f3f))-planet)];
        memo[0] %= MOD;
        if(memo[0] < 0) memo[0] += MOD;
        //for(int i = 0; i <= P+1; i++) printf("%lld, ", memo[i]); cout << endl;
        cout << memo[0] << endl;
    }else{
        scanf("%d", &W);
        if(W == 0){
            printf("3 1 1\n2 1");
        }else if(W == 1){
            printf("2 1 1\n1 1");
        }else if (W == 2) {
            printf("2 2 1\n1 1");
        }else{
            vector<ii> vec;
            vec.push_back(ii((W&1) ? -2 : -1, W));
            int i = 0;
            while(W>1){
                i++;
                if(W&1){
                    W++;
                    W /= 2;
                    vec.push_back(ii(-i-1, W));
                }else{
                    W/=2;
                    vec.push_back(ii(-i,W));
                }
            }
            D = vec.size();
            //cout << D << endl;
            printf("%d %d %d\n", D, D, vec.size()-1);
            for(i = 1; i < (int)vec.size(); i++){
                printf("%d %lld\n", i, vec[i].first+D);
            }
        }
    }

    return 0;
}