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

const int MAXN = 250010;
int n;
string s1, s2;
int fail[MAXN];

void gen(){
    int i = 1, len = 0;
    while(i < n){
        if(s2[i] == s2[len]){
            len++;
            fail[i] = len;
            i++;
        }else{
            if(len) len = fail[len-1];
            else{
                fail[i] = 0;
                i++;
            }
        }
    }
}

int st = -1;
void getMatch(){
    gen();

    int i = 0, j = 0;
    while(i < (n<<1)){
        if(s2[j] == s1[i])
            i++, j++;
        if(j == n){
            st = i-j;
            return;
        }else if(i < (n<<1) && s2[j] != s1[i]){
            if(j) j = fail[j-1];
            else i++;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s1 >> s2;
    s1 += s1;
    getMatch();
    if(st <= 0) cout << st << endl;
    else cout << n-st << endl;
    return 0;
}

