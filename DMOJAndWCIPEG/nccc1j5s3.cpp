#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

ll n;

inline ll f(ll n){
    ll en = n*(n-1)/2;
    ll k = 1, cnt = 0;
    ll last = -1;
    int prev = 0;
    while(k < n){
        ll l = k+1;
        last = k;
        cnt += n-k;
        if(cnt*2 >= en) return last;
        k++;
    }
}

inline ll calc(ll c){
    return n*(n-1)/2 - c*(c-1)/2;
}

int main(){
    cin >> n;

    if(n <= 1000){
        cout << f(n) << endl;
        return 0;
    }


    int mid, lo = 1, hi = n-1;
    ll target = n*(n-1)/2;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        //cout << lo << ", " << mid << ", " << hi << endl;
        //cout << 2*calc(mid) << ": " << target << endl;
        if(2*calc(mid) < target){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    cout << (n-lo+1) << endl;

    return 0;
}

