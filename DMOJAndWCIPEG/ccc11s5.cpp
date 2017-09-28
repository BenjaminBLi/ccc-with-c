#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

/*
23
0 0 0 0 1 1 0 1 1 0 1 1 0 1 1 0 1 0 1 1 0 0 1
 */

int K, memo[26], cnt[26], st, en;
bool on[26];
vii groups;
vi len;
void process() {
    int onCnt = 0;
    fori(i, 0, K) {
        if (on[i]) {
            onCnt++;
        } else {
            if (onCnt >= 4)
                for (int j = 1; j <= onCnt; j++)
                    on[i-j] = false;
            onCnt = 0;
        }
    }
    if(on[K-1] && onCnt >= 4) {
        for (int j = 0; j <= onCnt; j++)
            on[K - 1 - j] = false;
    }
}

void getGroups(){
    st = en = 0;
    bool flag = false;
    fori(i, 0, K) {
        if(i) cnt[i] += cnt[i-1];
        if (on[i]) {
            cnt[i]++;
            if (flag) en++;
            else st = en = i, flag = true;
        } else {
            if (flag) {
                groups.pb(ii(st, en));
                len.pb(en - st + 1);
                flag = false;
            }
        }
    }
    if (flag) {
        groups.pb(ii(st, en));
        len.pb(en - st + 1);
    }
}

int main() {
    scanf("%d", &K);
    int tmp;
    fori(i, 0, K) {
        scanf("%d", &tmp);
        on[i] = tmp != 0;
    }

    process();
    getGroups();
    int sz = groups.size();
    memset(memo, 0x3f3f3f, sizeof(memo));
    fori(i, 0, sz) {
        st = groups[i].f, en = groups[i].s;
        memo[i] = 4 - (en - st + 1);
        if(i) memo[i] += memo[i-1];
        //cout << "I: " << i << endl;
        //fori(i, 0, sz) printf("%d, ", memo[i]); cout << endl;
        rfori(j, i - 1, 0) {
            if (st-groups[j].s+1 > 7) break;
            int len = max(4, en - groups[j].f+1);
            int t = len - (cnt[en] - (groups[j].f ? cnt[groups[j].f-1] : 0));
            int prev = 0;
            if(j) prev = memo[j-1];
            else if(j == 0 && i-j > 1) prev = memo[j];
            if(len == 6 && on[groups[j].f+2] && on[groups[j].f+ 3] && i-j == 2) t = 4;
            else if(len == 7 && on[groups[j].f+3] && i-j == 2) {
                t = 5;
                if(on[groups[j].f+2] || on[en-2]) t--;
                if(on[groups[j].f+1]) t--;
                if(on[en-1]) t--;
            }
            if (memo[i] > t + prev) {
       //         cout << "YES: PAIRED " << i << " with " << j << " ans: " << t + prev << endl;
        //        cout << "t: " << t << ", " << prev <<endl;
                memo[i] = t + prev;
            }
        }
    }
   // fori(i, 0, sz) printf("%d, ", memo[i]); cout << endl;

    printf("%d\n", memo[sz - 1]);

    return 0;
}
