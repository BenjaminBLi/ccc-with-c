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

int K;
set<int> superprimes;
int last = 73939133;

class superprime {
public:
    bool isPrime(int n){
        if(n == 0) return true;
        if(n == 2) return true;
        if(n == 3) return true;
        if(n % 2 == 0 || n == 1) return false;
        for(int i = 3; i*i <= n; i += 2){
            if(n%i == 0) return false;
        }
        return true;
    }

    void gen(int curr){
        //cout << curr << endl;
        for(int i = 1; i < 10; i++){
            int tmp = curr;
            tmp *= 10;
            tmp += i;
            if(tmp > last || !isPrime(tmp)) continue;
            if(tmp) superprimes.insert(tmp);
            gen(tmp);
        }
    }

	void solve(std::istream& in, std::ostream& out) {
        gen(0);
        in >> K;
        int i = 0, ans = 0;
        for(int t : superprimes){
            i++;
            if(i == K){
                ans = t;
                break;
            }
        }
        out << ans << endl;
	}
};
