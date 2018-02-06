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

int n, freq[30], curr[30], cnt[30], k; 
vector<pair<int, char>> ans;
string a;

int main(){
    cin >> n >> k;
    cin >> a;
    string c;
    cin >> c;

    for(int i = 0; i < n; i++){
        freq[a[i]-'a']++;
    }

    vector<char> ans; 
    bool found = false;
    int val;
    fori(i, 0, n){
        if(found){
            curr[val]++;
            ans.pb((char) ('a' + val));
        }else if(i < k){
            //if character j is fully taken, we can take more of this char
            //first k letters are part of the lcs.
            fori(j, 0, 26){
                if(i + freq[j] - curr[j] == k){
                    curr[j]++;
                    ans.pb((char) ('a'+j));
                    found = true;
                    val = j;
                    break;
                }
            }

            if(!found){
                ans.pb(a[i]);
                curr[a[i]-'a']++;
            }
        }else{
            fori(j, 0, 26){
                if(curr[j] >= freq[j]){
                    curr[j]++;
                    ans.pb((char) ('a'+j));
                    break;
                }
            }
        }
    }

    if(k <= n && ans.size() == n) {
        for(char c : ans) putchar(c);
        cout<<endl;
    }
    else cout << "WRONGANSWER" << endl;

    
    return 0;
}

