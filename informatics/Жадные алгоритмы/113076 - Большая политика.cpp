#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9 + 5;
const int N = 1e5 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

template <typename T>
struct Heap {

private:

    int _size;
    T val[N];

    void sift_up(int pos) {
        int p = (pos - 1) / 2;

        if (val[p] > val[pos]) {
            swap(val[p], val[pos]);
            sift_up(p);
        }
    }

    void sift_down(int pos) {
        int ch1 = 2 * pos + 1;
        int ch2 = 2 * pos + 2;

        if (ch1 < _size) {
            if (ch2 < _size) {
                if (val[ch1] < val[pos] && val[ch1] <= val[ch2]) {
                    swap(val[ch1], val[pos]);
                    sift_down(ch1);
                }
                else if (val[ch2] < val[pos] && val[ch2] < val[ch1]) {
                    swap(val[ch2], val[pos]);
                    sift_down(ch2);
                }
            }
            else {
                if (val[ch1] < val[pos]) {
                    swap(val[ch1], val[pos]);
                    sift_down(ch1);
                }
            }
        }
    }

public:

    Heap() {
        _size = 0;
    }

    void insert(T x) {
        val[_size] = x;
        sift_up(_size);
        _size++;
    }

    T get_min() {
        return val[0];
    }

    void extract_min() {
        swap(val[0], val[--_size]);
        sift_down(0);
    }

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

};

class Solution {

    int n;
    ll x, res;
    Heap<ll> heap;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            heap.insert(x);
        }
    }

    void prepare() {
    }

    void output() {
        cout << res;
    }

    void solution() {
        res = 0;

        while (heap.size() > 1) {
            ll first_min = heap.get_min();
            heap.extract_min();

            ll second_min = heap.get_min();
            heap.extract_min();

            ll sum = first_min + second_min;
            res += sum;

            heap.insert(sum);
        }
    }

public:

    Solution() {
    }

    void solve() {
        input();
        solution();
        output();
    }

};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}
