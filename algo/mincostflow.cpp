#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

// begin-snippet mincostflow
template<typename L>
struct graph {
    struct edge {
        int fr;
        int to;
        L cap;
        L flow;
        L cost;
        edge(int fr, int to, L cap, L cost)
        {
            this->fr = fr;
            this->to = to;
            this->cap = cap;
            this->flow = 0;
            this->cost = cost;
        }
    };

    graph(int vertices)
    {
        oo = numeric_limits<L>::max()/2;
        n = vertices;
        distance = new L[n];
        backedge = new int[n];
    }

    ~graph()
    {
        delete [] distance;
        delete [] backedge;
    }

    void add_edge(int fr, int to, L cap, L cost)
    {
        int e = edges.size();
        edges.push_back(edge(fr, to, cap, cost));
    }

    L augment(int t, L delta)
    {
        if (backedge[t] < 0) return delta;
        edge& e = edges[backedge[t]];
        if (e.to == t) {
            delta = augment(e.fr, min(delta, e.cap - e.flow));
            e.flow += delta;
        } else {
            delta = augment(e.to, min(delta, e.flow));
            e.flow -= delta;
        }
        return delta;
    }

    void bellman_ford(int s, int t)
    {
        for (int i = 0; i < n; ++i) distance[i] = oo;
        distance[s] = 0;
        backedge[s] = -1;

        for (int i = 0; i < n && distance[t] == oo; ++i) {
            for (int j = 0; j < edges.size(); ++j) {
                edge e = edges[j];
                if (e.flow < e.cap) {
                    if (distance[e.to] > distance[e.fr] + e.cost) {
                        backedge[e.to] = j;
                        distance[e.to] = distance[e.fr] + e.cost;
                    }
                }
                if (e.flow > 0) {
                    if (distance[e.fr] > distance[e.to] - e.cost) {
                        backedge[e.fr] = j;
                        distance[e.fr] = distance[e.to] - e.cost;
                    }
                }
            }
        }
    }

    L mincostflow(int s, int t, L maxflow)
    {
        L totalflow = 0;
        L delta;
        do {

            bellman_ford(s, t);

            if (distance[t] < oo) delta = augment(t, maxflow - totalflow);
            else delta = 0;

            totalflow += delta;

        } while (delta > 0);
        if (totalflow != maxflow) return -1;
        L res = 0;
        for (int i = 0; i < edges.size(); ++i)
            res += edges[i].flow * edges[i].cost;
        return res;
    }

    L oo;
    int n;
    vector<edge> edges;
    L *distance;
    int *backedge;
};
// end-snippet



int main()
{
    int n, m;
    while (cin >> n >> m) {
        graph<long long> g(n); 
        while (m-- > 0) {
            int fr, to, cost;
            cin >> fr >> to >> cost;
            fr--; to--;
            if (fr < 0 || fr >= n || to < 0 || to >= n) for(;;);
            g.add_edge(fr, to, 0, cost);
            g.add_edge(to, fr, 0, cost);
        }
        long long D, K;
        cin >> D >> K;
        for (int i = 0; i < g.edges.size(); ++i)
            g.edges[i].cap = K;
        long long res = g.mincostflow(0, n-1, D);
        if (res < 0) cout << "Impossible." << endl;
        else cout << res << endl;
    }
    return 0;
}
