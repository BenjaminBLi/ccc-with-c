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

map<char, int> cnt;
string s;

int main(){
    cin >> s;
    for(char c : s){
        cnt[c]++;
    }

    vector<pair<int, char>> curr;
    for(auto p : cnt){
        curr.pb({p.s, p.f});
    }

    sort(curr.begin(), curr.end());

    if(curr.size() <= 2){
        cout << 0 << endl;
    }else{
        int ans = 0;
        fori(i, 0, curr.size()-2){
            ans += curr[i].f;
        }
        cout << ans << endl;
    }


    return 0;
}

