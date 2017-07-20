#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

class FT{
private:
    vi ft;
public:
    FT(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b&(-b))){
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int) ft.size(); k += (k&(-k))) {
            ft[k] += v;
        }
    }
};

int n;
priority_queue<ii, vector<ii>, greater<ii>> pq;

int main(){
    scanf("%d", &n);
    FT c(n);
    for(int i = 1; i <= n ;i++) {
        int t;
        scanf("%d", &t);
        pq.push(ii(t, i));
    }
    int prev = pq.top().second;
    c.adjust(prev+1, -1);
    pq.pop();
    long long t = prev;
    cout << t << endl;
    while(pq.size()){
        int cIdx = pq.top().second;
        printf("%d %d\n", pq.top().first, cIdx);
        if(cIdx+c.rsq(cIdx) > prev + c.rsq(prev))
            t += cIdx - prev + c.rsq(cIdx);
        else{
            t += pq.size()-prev;
            t += cIdx + c.rsq(cIdx);
        }
        cout << cIdx + c.rsq(cIdx) << endl;
        cout << t << endl;
        prev = cIdx;
        c.adjust(prev, -1);
        pq.pop();
    }
    cout << t << endl;

    return 0;
}
