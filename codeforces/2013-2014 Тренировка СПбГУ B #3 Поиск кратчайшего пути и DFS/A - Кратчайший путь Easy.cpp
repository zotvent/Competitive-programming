#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const ll inf = 1e18;
const int N = 2005;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

struct node {
    int to;
    ll dist;
    
    node(int to, ll dist) : to(to), dist(dist) {};
};

int n, m, s, used[N];
ll d[N];
vector<node> g[N];

void input() {
    speed
    freopen("path_easy.in", "r", stdin);
    freopen("path_easy.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        g[from].pb(node(to, cost));
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].to;
        if (!used[to])
            dfs(to);
    }
}

void BellmanFord() {
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[s] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < g[j].size(); k++) {
                int to = g[j][k].to;
                ll dist = g[j][k].dist;
                if (d[j] < inf && d[to] > d[j]+dist)
                    d[to] = d[j]+dist;
            }
}

void solve() {
    BellmanFord();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++) {
            int to = g[i][j].to;
            ll dist = g[i][j].dist;
            if (d[i] < inf && d[to] > d[i]+dist && !used[to])
                dfs(to);
        }
}

void output() {
    for (int i = 1; i <= n; i++) {
        if (d[i] == inf)
            cout << '*';
        else if (used[i])
            cout << '-';
        else
            cout << d[i];
        cout << endl;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}