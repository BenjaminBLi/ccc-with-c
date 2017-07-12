#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef long double ld;
typedef long long ll;
int n;
ii cars[100010];
vector<ii> change;

/*
5
7 2
5 6
4 3
4 6
3 9
 */

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    ll t = gcd(a, b);
    a /= t;
    b /= t;
    return t * a * b;
}

long double calc(){
    long double ret = 0;
    ll tmp= 1;
    for(ii v : change){
        //printf("%d, %d\n", v.first, v.second);
        ll cV =  v.second;
        tmp = lcm(tmp, cV);
    }
    for(ii v : change){
        ret += v.first * tmp / v.second;
    }
    return ret / tmp;
}

bool comp(ii a, ii b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &cars[i].first, &cars[i].second);

    int cV = cars[0].second;
    int dist = cars[0].first;
    for(int i = 1; i < n; i++){
        if(cars[i].second > cV){
            change.push_back(ii(dist-cars[i].first, cV));
            cV = cars[i].second;
            dist = cars[i].first;
        }
    }
    change.push_back(ii(dist, cV));
    cout << calc() << endl;
    return 0;
}
