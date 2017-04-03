#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#define EPS 1e-9
using namespace std;
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
    bool operator<(point &b) const
    {
        if (x == b.x)
            return (y < b.y);
        return x < b.x;
    }
    bool operator==(point &b) const
    {
        return (x==b.x && y==b.y);
    }
};
bool cmp (const point& a, const point& b)
{
    if (a.x == b.x)
            return (a.y < b.y);
        return a.x < b.x;
}
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
struct line { double a, b, c;};
void point_to_line(point a, point b, line &l)
{
    if (fabs(a.x-b.x) < EPS)
    {
        l.a = 1.0; l.b = 0.0; l.c = -a.x;
    }
    else
    {
        l.a = -(double) (a.y-b.y) / (a.x-b.x);
        l.b = 1.0;
        l.c = -(double) (l.a * a.x) - a.y;
    }
}
struct vec {double x, y; vec(double a, double b) {x = a; y = b;}};
vec tovec(point a, point b){return vec(b.x - a.x, b.y-a.y);}
vec scale (vec v, double s) {return vec(v.x*s, v.y*s);}
point translate (point p, vec v) { return point(p.x + v.x, p.y + v.y);}
double magnitude (vec v) {return sqrt(v.x*v.x + v.y*v.y);}
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}
double dist_to_line(point p, point a, point b, point &c)
{
    // c = a + u * ab
    // projection : dot(ap,ab) / sq(ab)
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p,c);
}
double dist_to_lineseg(point p, point a, point b, point &c)
{
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y); return dist(p,a);
    }
    if (u > 1.0)
    {
        c = point(b.x, b.y); return dist(p,b);
    }
    return dist_to_line(p,a,b,c);
}
double angle(point a, point o, point b) //return angle AOB in rad, times 180.0/pi to get degree
{
    vec oa = tovec(o,a); vec ob = tovec(o,b);
    return acos(dot(oa, ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
double CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r)); /*> 0;*/} //return true if point R is on left side of line PQ
bool collinear (point p, point q, point r) {return fabs(cross(tovec(p,q), tovec(p,r)) ) < EPS;}
int N;
vector <point> allp;
int main()
{
    cin>>N;
    int a, b;
    cin>>a>>b;
    point p1 = point(a,b);
    for (int i = 1 ; i < N; i++)
    {
        int a, b;
        cin>>a>>b;
        allp.push_back(point(a,b));
    }
    sort(allp.begin(), allp.end(), cmp);
    int cnt = 0;
    do
    {
        cout<<"--------\n";
        for (int i = 0 ; i < allp.size(); i++)
            cout<<allp[i].x<<"   "<<allp[i].y<<"\n";
        bool isok = true;
        for (int i = 0; i < allp.size()&&isok; i++)
        {
            point v1s = (i==0)? p1 : allp[i-1];
            point v1e = allp[i];
            for (int j = i; j < allp.size()&&isok; j++)
            {
                point v2s = allp[j];
                point v2e = (j == (int)allp.size()-1)? p1: allp[j+1];
                if (v1s==v2e||v1e==v2s) continue;
                double res = CCW(v2s, v2e, v1s) * CCW(v2s, v2e, v1e);
                double res2 = CCW(v1s, v1e, v2s) * CCW(v1s, v1e, v2e);
                if (res <= 0 && res2 <= 0)
                {
                    isok = false;
                }
            }
        }
        if (isok) cnt++;
    } while (next_permutation(allp.begin(), allp.end()));
    cout<<cnt/2<<"\n";
}