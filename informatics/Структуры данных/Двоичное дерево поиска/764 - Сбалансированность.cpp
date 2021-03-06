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
const int N = 1e4 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

template <typename T>
struct TreeNode {

    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T x) {
        val = x;
        left = NULL;
        right = NULL;
    }

};

class Solution {

    int x;
    bool balanced;
    TreeNode<int>* root;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        while (cin >> x) {
            if (x == 0) {
                break;
            }

            root = insert(root, x);
        }
    }

    TreeNode<int>* insert(TreeNode<int>* root, int x) {
        if (root) {
            if (x > root->val) {
                root->right = insert(root->right, x);
            }
            else if (x < root->val) {
                root->left = insert(root->left, x);
            }
        }
        else {
            root = new TreeNode<int>(x);
        }

        return root;
    }

    void prepare() {
    }

    void output() {
        cout << (balanced ? "YES" : "NO");
    }

    void solution() {
        balanced = true;
        height(root);
    }

    int height(TreeNode<int>* root) {
        if (!root) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) {
            balanced = false;
        }

        return max(left, right) + 1;
    }

public:

    Solution() {
        root = NULL;
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
