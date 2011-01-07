#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// begin-snippet fenwick
template <typename Group>
struct fenwick {
    typedef typename Group::element_type T;

    T* a;
    int n;
    
    fenwick(int n)
    {
        this->n = n;
        a = new T[n];
        fill_n(a, n, Group::zero);
    }
    ~fenwick()
    {
        delete [] a;
    }
    
    T get(int at)
    {
        return Group::plus(sum(at+1), Group::negation(sum(at)));
    }
    
    void set(int at, T value)
    {
        add(at, Group::plus(value, Group::negation(get(at))));
    }
    
    void add(int at, T delta)
    {
        for (int i = at; i < n; i |= i+1) 
            a[i] = Group::plus(a[i], delta);
    }

    T sum(int cnt)
    {
        T result = Group::zero();
        for (int i = cnt-1; i >= 0; i = (i & i+1) - 1)
            result = Group::plus(result, a[i]);
        return result;
    }

    T sum(int begin, int end) // sum of [begin; end), end not included
    {
        return Group::plus(sum(end), Group::negation(sum(begin)));
    }
};

template<typename T>
struct sum_query {
    typedef T element_type;
    static inline T zero() {return (T)0;}
    static inline T plus(T a, T b) {return a + b;}
    static inline T negation(T a) {return -a;}
};
// end-snippet


int main()
{
    int n = 1000;
    
    fenwick<sum_query<int> > f(n);

    for (int i = 0; i < n; ++i)
        f.set(i, i);

    for (int i = 0; i < n; ++i)
        assert(f.sum(i) == i*(i-1)/2);

    for (int i = 1; i < n; i += 2)
        f.add(i, -i);
    
    assert(f.sum(n) == n*(n-1)/2 - (n/2)*(n/2));
    return 0;
}