#include <bits/stdc++.h>
#define ii pair<ll, int>
#define f first
#define s second
using namespace std;
typedef long long ll;
struct event{
    int type, val, y;
    ll x;
    event(){};
    event(int id, ll a, int b, int c){
        x = a;
        y = b;
        val = c;
        type = id;
    }

    bool operator< (const event &o) const{
        if(x == o.x){
            if(y == o.y)
                return type < o.type;
            return y < o.y;
        }
        return x < o.x;
    }
    bool operator> (const event &o) const{
        if(x == o.x){
            if(y == o.y)
                return type > o.type;
            return y > o.y;
        }
        return x > o.x;
    }
    bool operator== (const event &o) const{
        return x == o.x && type == o.type && y == o.y && val == o.val;
    }
};

int NA, t;
ll ft[1000010];
string tmp;
ii stA;
char ch;

ll rsq(int b) {
    ll sum = 0;
    for (; b; b -= (b&(-b))){
        sum += ft[b];
    }
    return sum;
}
ll rsq(int a, int b) {
    return rsq(b) - rsq(a);
}

void adjust(int k, int v) {
    for (; k < 1000000; k += (k&(-k))) {
        ft[k] += v;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(;T--;) {
        cin >> tmp;
        fill(ft, ft+(int)1e6+1, 0);
        vector<event> events;
        for (int i = 0; i < 2; i++) {
            scanf("%lld %d %d", &stA.f, &stA.s, &NA);
            event c;
            for (int j = 0; j < NA; j++) {
                scanf(" %c %d", &ch, &t);
                if (ch == 'R') {
                    c = event(0, stA.f, stA.s, 1);
                    events.push_back(c);
                    stA.f += t;
                    c = event(0, stA.f, stA.s, -1);
                    events.push_back(c);
                } else if (ch == 'L') {
                    c = event(0, stA.f, stA.s, -1);
                    events.push_back(c);
                    stA.f -= t;
                    c = event(0, stA.f, stA.s, 1);
                    events.push_back(c);
                } else if (ch == 'D') {
                    c = event(1, stA.f, stA.s-t, stA.s);
                    events.push_back(c);
                    stA.s -= t;
                } else {
                    c = event(1, stA.f, stA.s, stA.s+t);
                    events.push_back(c);
                    stA.s += t;
                }
            }
        }
        ll ans = 0;
        sort(events.begin(), events.end());
        //cout << yCnt << endl;
        for(int i = 0; i < (int) events.size(); i++) {
            event c = events[i];
            if (c.type == 1) {
                int l = c.y, r = c.val-1;
                ll tmp = rsq(l, r);
                ans += tmp;
            } else {
                adjust(c.y, c.val);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
