#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// begin-snippet maxflow
template <typename L>
struct graph {
    struct edge {
        int fr;
        int to;
        L cap;
        L flow;
        edge(int fr, int to, L cap)
        {
            this->fr = fr;
            this->to = to;
            this->cap = cap;
            this->flow = L();
        }
    };

    graph(int vertices) {
        n = vertices;
        oo = (numeric_limits<L>::max()) / 2;
        fwd = new vector<int>[n];
        rev = new vector<int>[n];
        visited = new bool[n];
    }

    ~graph(){
        delete [] visited;
        delete [] fwd;
        delete [] rev;
    }

    void add_edge(int fr, int to, L cap)
    {
        int e = edges.size();
        edges.push_back(edge(fr, to, cap));
        fwd[fr].push_back(e);
        rev[to].push_back(e);
    }

    L augment(int i, int t, L delta)
    {
        if (i == t) return delta;
        if (visited[i]) return 0;
        visited[i] = true;
        for (int k = 0; k < fwd[i].size(); ++k) {
            edge& e = edges[fwd[i][k]];
            if (e.cap > e.flow) {
                int x = augment(e.to, t, min(delta, e.cap - e.flow));
                if (x > 0) {
                    e.flow += x;
                    return x;
                }
            }
        }
        for (int k = 0; k < rev[i].size(); ++k) {
            edge& e = edges[rev[i][k]];
            if (e.flow > 0) {
                int x = augment(e.fr, t, min(delta, e.flow));
                if (x > 0) {
                    e.flow -= x;
                    return x;
                }
            }
        }
        return 0;
    }

    L maxflow(int s, int t)
    {
        L res = 0;
        L delta;
        do {
            fill_n(visited, n, false);
            delta = augment(s, t, oo);
            res += delta;
        } while (delta > 0);
        return res;
    }

    int n;
    vector<edge> edges;
    vector<int> *fwd;
    vector<int> *rev;
    bool *visited;
    L oo; 
};
// end-snippet




int main()
{
    while (true)
    {

        int team_cnt, table_cnt;
        cin >> team_cnt >> table_cnt;
        if (team_cnt == 0 && table_cnt == 0) break;

        vector<int> team, table;

        for (int i = 0; i < team_cnt; ++i)
        {
            int x;
            cin >> x;
            team.push_back(x);
        }

        for (int i = 0; i < table_cnt; ++i)
        {
            int x;
            cin >> x;
            table.push_back(x);
        }

        int n = team_cnt + table_cnt + 2;
        int s = n - 2;
        int t = n - 1;
        graph<int> g(n); 

        for (int i = 0; i < team_cnt; ++i)
            g.add_edge(s, i, team[i]); 

        for (int i = 0; i < team_cnt; ++i)
        for (int j = 0; j < table_cnt; ++j)
            g.add_edge(i, j + team_cnt, 1);

        for (int j = 0; j < table_cnt; ++j)
            g.add_edge(j + team_cnt, t, table[j]);

        int r = g.maxflow(s, t);
        int sum = 0;
        for (int i = 0; i < team_cnt; ++i)
            sum += team[i];

        if (r != sum)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;

            vector<int> a[n];

            for (int k = 0; k < g.edges.size(); ++k)
            {
                graph<int>::edge e = g.edges[k];
                if (e.flow && e.fr < team_cnt && e.to >= team_cnt && e.to < team_cnt + table_cnt)
                {
                    a[e.fr].push_back(e.to - team_cnt + 1);
                }
            }
            for (int j = 0; j < team_cnt; ++j)
            {
                cout << a[j][0];
                for (int i = 1; i < a[j].size(); ++i)
                    cout << " " << a[j][i];
                cout << endl;
            }
        }
    }
    return 0;
}
