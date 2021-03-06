#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 1e5+5;
const int mod = 1e9+7;

using namespace std;

int n, a[N], k, l, r, t[4*N];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = gcd(t[2*v], t[2*v+1]);
}

int getGCD(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return -1;

    if (l <= tl && tr <= r)
        return t[v];

    int tm = (tl+tr)/2;
    int a = getGCD(2*v, tl, tm, l, min(r, tm)),
        b = getGCD(2*v+1, tm+1, tr, max(l, tm+1), r);

    if (a == -1 && b == -1) return -1;
    else if (a == -1) return b;
    else if (b == -1) return a;
    else return gcd(a, b);
}

int main() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> l >> r;
        cout << getGCD(1, 1, n, l, r) << ' ';
    }
    return 0;
}