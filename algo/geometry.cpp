#include <cstdio>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "numbers.cpp"

// begin-snippet geometry
template <typename T>
T sqrlen(T a, T b)
{
   return a*a + b*b;
}

template <typename T>
T cross(T vx, T vy, T ux, T uy)
{
    return vx * uy - ux * vy;
}

template <typename T>
T dot(T vx, T vy, T ux, T uy)
{
    return vx * ux + uy * vy;
}

template <typename P>
int side(P a, P b, P c)
{
    typename P::T r = cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
    if (neg(r)) return -1;
    if (pos(r)) return 1;
    return 0;
}

template <typename P>
bool left_turn(P a, P b, P c)
{
    return pos(cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y));
}

template <typename P>
bool colinear(P a, P b, P c)
{
    return zero(cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y));
}

template <typename P>
bool right_turn(P a, P b, P c)
{
    return neg(cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y));
}

template <typename P>
bool ninety_degree_turn(P a, P b, P c)
{
    return zero(dot(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y));
}

template <typename Q>
struct point {
    typedef Q T;
    T x, y;
    point() : x(T()), y(T()) {}
    point(T x, T y) : x(x), y(y) {}
    bool operator< (const point<T> p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }
};
// end-snippet


// begin-snippet area
template <typename P>
typename P::T area(const vector<P>& p)
{
    typename P::T result = (typename P::T)0;
    for (int i = 0; i + 1 < (int)p.size(); ++i) {
        result += cross(p[0], p[i], p[i+1]);
    }
    return result / (typename P::T)2;
}
// end-snippet

// begin-snippet convex_hull
// convex hull with simple edges (no colinear points)
template <typename P>
vector<P> convex_hull(vector<P> p)
{
    vector <P> res;
    sort(p.begin(), p.end());
    res.push_back(p[0]);
    if (eq(p[0].x, p.back().x) && eq(p[0].y, p.back().y))
        return res;
    // minimum number of vertices in the convex hull
    int limit = 1;
    // add vertices of the lower hull
    for (int i = 1; i < (int)p.size(); ++i) {
        while ((int)res.size() > limit && !left_turn(res[res.size() - 2], res.back(), p[i]))
            res.pop_back();
        res.push_back(p[i]);
    }
    // lower hull is built, set new limit
    limit = (int)res.size();
    // add vertices of the upper hull
    for (int i = p.size() - 1; i >= 0; --i) {
        while ((int)res.size() > limit && !left_turn(res[res.size() - 2], res.back(), p[i]))
            res.pop_back();
        res.push_back(p[i]);
    }
    // remove the first vertice, because it was added twice
    res.pop_back();
    return res;
} 
// end-snippet

// begin-snippet line
template<typename Q>
struct line {
    typedef Q P;
    typedef typename Q::T T;
    T a, b, c;
    void init(T a, T b, T c)
    {
        if (neg(a) || zero(a) && b < 0) init(-a, -b, -c);
        else {
            T k = gcd(gcd(abs(a), abs(b)), abs(c));
            if (zero(k)) k = (T)1;
            this->a = abs(a) / k;
            this->b = b / k;
            this->c = c / k;
        }
    }
    line () {}
    line (P p1, P p2)
    {
        init(p2.y-p1.y, p1.x-p2.x, p2.x*p1.y - p2.y*p1.x);
    }
    line (T a, T b, T c)
    {
        init(a, b, c);
    }
    bool operator< (const line<T>& l) const
    {
        return a != l.a ? a < l.a : (b != l.b ? b < l.b : c < l.c);
    }
    T f(P p) const
    {
        return a*p.x + b*p.y + c;
    }
    bool hits(P p) const
    {
        return zero(f(p));
    }
    double distance(P p) const
    {
        return abs((double)f(p) / sqrt((double)sqrlen(a, b)));
    }
    int side(P p) const
    {
        T r = f(p);
        if (neg(r)) return -1;
        if (pos(r)) return 1;
        return 0;
    }
    bool parallel(const line<P>& l) const
    {
        return eq(a*l.b, l.a*b);
    }
    bool same(const line<P>& l) const
    {
        return eq(a, l.a) && eq(b, l.b) && eq(c, l.c);
    }
    bool intersects(const line<P>& l) const
    {
        return !parallel(l) && !same(l);
    }
    P intersection(const line<P>& l) const
    {
        assert(intersects(l));
        if (zero(a)) return l.intersection(*this);
        T k = l.a*b - a*l.b;
        T q = l.a*c - a*l.c;
        P r;
        r.y = -q / k;
        r.x = -(b*r.y+c) / a;
        return r;
    }
};
// end-snippet

// begin-snippet segment
template<typename Q>
struct segment {
    typedef Q P;
    P a, b;
    
    segment() {}

    template <typename P>
    segment(P p1, P p2) : a(p1), b(p2) 
    {
        if (gt(a.x, b.x) || eq(a.x, b.x) && gt(a.y, b.y))
            swap(a, b);
    }

    bool operator< (const segment<P>& s) const
    {
        return a != s.a ? a < s.a : b < s.b;
    }

    template<typename P>
    bool hits(P p) const
    {
        return colinear(p, a, b) && between(p.x, a.x, b.x) && between(p.y, a.y, b.y);
    }

    double distance(P p) const
    {
        if (neg(dot(p.x-a.x, p.y-a.y, b.x-a.x, b.y-a.y))) 
        {
            return sqrt((double)sqrlen(p.x-a.x, p.y-a.y));
        }
        if (neg(dot(p.x-b.x, p.y-b.y, a.x-b.x, a.y-b.y))) 
        {
            return sqrt((double)sqrlen(p.x-b.x, p.y-b.y));
        }
        return getline().distance(p);
    }

    line<P> getline() const
    {
        return line<P>(a, b);
    }

    int side(P p) const
    {
        return side(a, b, p);
    }

    bool colinear(const segment<P>& s) const
    {
        return side(s.a) == 0 && side(s.b) == 0;
    }

    bool intersects(const segment<P>& s) const
    {
        if (!colinear(s))
            return (side(s.a) != side(s.b) && s.side(a) != s.side(b));
        return s.hits(a) || hits(s.a);
    }

    P intersection(const segment<P>& s) const
    {
        assert(intersects(s) && !colinear(s));
        return getline().intersection(s.line());
    }
};
// end-snippet


int main()
{
	
    int n;

    line<point<int> > l1(0, 1, -10);
    line<point<int> > l2(1, 0, -20);

    point<int> i = l1.intersection(l2);
    printf("%d %d\n", i.x, i.y);

    segment<point<double> > s1(point<double>(0, 0), point<double>(100, 200));
    segment<point<double> > s2(point<double>(50, 100), point<double>(1000, 200));

    point<double> j = s1.intersection(s2);
    cout << s1.side(s2.b) << " " << s1.getline().side(s2.b) << endl;
    printf("%lf %lf\n", j.x, j.y);

    printf("%lf\n", l1.distance(point<int>(0, 0)));

    return 0;

    scanf("%d",&n);

    vector < point<int> > p;
    for (int i = 0; i < n; ++i)
    {
        point<int> a;
        scanf("%d %d", &a.x, &a.y);
        p.push_back(a);
	}
    vector < point<int> > r = convex_hull(p);
    printf("%d\n", r.size());
    for (int i = 0; i < (int)r.size(); ++i)
    {
        printf("%d %d\n", r[i].x, r[i].y);
    }
    return 0;
}