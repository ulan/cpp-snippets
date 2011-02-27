#include <cstdio>
#include <vector>
#include <functional>
#include <cassert>
#include <limits>
#include <iostream>
using namespace std;

// begin-snippet range_tree
template <typename Monoid>
struct range_tree {
    typedef typename Monoid::element_type T;
    T* nodes;
    int tree_size;
    int leaf_count;
    int leaf_offset;

    range_tree(int n)
    {
        leaf_count = n;
        leaf_offset = 1;
        while (leaf_offset < n) leaf_offset *= 2;
        tree_size = leaf_offset + n + 1;
        nodes = new T[tree_size];
        fill_n(nodes, tree_size, Monoid::zero());
    }

    ~range_tree()
    {
        delete [] nodes;
    }

    T get(int at)
    {
        assert_bounds(at, 0, leaf_count);
        return nodes[leaf_offset+at];
    }
    
    void set(int at, T value)
    {
        assert_bounds(at, 0, leaf_count);
        nodes[leaf_offset+at] = value;
        fix(at);
    }

    void add(int at, T delta)
    {
        assert_bounds(at, 0, leaf_count);
        set(at, Monoid::plus(get(at), delta));
    }

    void fix(int at)
    {
        for (int i = leaf_offset + at >> 1; i != 0; i >>= 1)
            nodes[i] = Monoid::plus(nodes[i << 1], nodes[i << 1 | 1]);
    }

    T sum(int cnt)
    {
        return sum(0, cnt);
    }

    T sum(int begin, int end) // sum of [begin; end), end not included
    {
        if (begin == end) return Monoid::zero();

        assert_bounds(end-1, 0, leaf_count);
        assert_bounds(begin, 0, end);

        int l = leaf_offset + begin;
        int r = leaf_offset + end-1;
        
        if (l == r) return nodes[l];

        T lsum = nodes[l];
        T rsum = nodes[r];
        for (; l >> 1 != r >> 1; l >>= 1, r >>= 1) {
            if (!(l & 1)) lsum = Monoid::plus(lsum, nodes[l ^ 1]);
            if ( (r & 1)) rsum = Monoid::plus(nodes[r ^ 1], rsum);
        }
        return Monoid::plus(lsum, rsum);
    }

    void assert_bounds(int i, int begin, int end)
    {
        if (!(begin <= i && i < end)) {
            cerr << "index out of bounds: " << begin << " <= " << i << " < " << end << endl;
            assert(begin <= i && i < end);
        }
    }
};

template<typename T>
struct sum_query {
    typedef T element_type;
    static inline T zero() {return (T)0;}
    static inline T plus(T a, T b) {return a + b;}
};

template<typename T>
struct min_query {
    typedef T element_type;
    static inline T zero() {return numeric_limits<T>::max();}
    static inline T plus(T a, T b) {return min(a, b);}
};

template<typename T>
struct max_query {
    typedef T element_type;
    static inline T zero() {return numeric_limits<T>::min();}
    static inline T plus(T a, T b) {return max(a, b);}
};
// end-snippet


int main()
{
    int n = 1024;
    range_tree< sum_query<int> > f(n);

    for (int i = 0; i < n; ++i)
        f.add(i, i);

    for (int i = 0; i < n; ++i)
        assert(f.sum(i) == i*(i-1)/2);

    for (int i = 1; i < n; i += 2)
        f.add(i, -i);
    
    assert(f.sum(n) == n*(n-1)/2 - (n/2)*(n/2));
    return 0;
}