#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, arr[100010], memo[100010][10][5];

class chomp4 {
public:
    int dp(int idx, int bite, int eat) {
        if (idx >= n) return 0;
        if (memo[idx][bite][eat] != -1) return memo[idx][bite][eat];
        int ans = -(1<<29);

        if (eat == 0) {
            if(bite < 4) ans = max(ans, arr[idx] + dp(idx + 1, bite + 1, 1)); //take another bite
            ans = max(ans, dp(idx+1, bite, 0)); //continue not eating...
        }else {
            ans = max(ans, dp(idx+1, bite, 0)); //stop eating
            ans = max(ans, arr[idx] + dp(idx + 1, bite, 1)); //continue taking another bite
        }

        memo[idx][bite][eat] = ans;
        return ans;
    }

    void solve(std::istream &in, std::ostream &out) {
        in >> n;
        fori(i, 0, n) in >> arr[i];
        memset(memo, -1, sizeof(memo));
        rfori(i, n, 0){
            dp(i, 0, 0);
        }
        out << dp(0, 0, 0) << "\n";
    }
};
