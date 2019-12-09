#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5, LOG = 19;

vector<int> G[MAXN];
int lcap[MAXN][LOG + 1], pre[MAXN], pre_max[MAXN], dep[MAXN];
int tim = 0;

void dfs(int v, int p) {
    pre[v] = ++tim;
    lcap[v][0] = p;
    for (int i = 1; i <= LOG; ++i) {
        lcap[v][i] = lcap[lcap[v][i - 1]][i - 1];
    }

    for (int u : G[v]) {
        if (u == p) {
            continue;
        }
        dep[u] = dep[v] + 1;
        dfs(u, v);
    }
    pre_max[v] = tim;
}

int lca_depth(int a, int b) {
    if (dep[a] > dep[b]) {
        swap(a, b);
    }

    for (int i = LOG; i >= 0; --i) {
        if (dep[lcap[b][i]] > dep[a]) {
            b = lcap[b][i];
        }
    }
    if (a == b) {
        return a;
    }

    for (int i = LOG; i >= 0; --i) {
        if (lcap[a][i] != lcap[b][i]) {
            a = lcap[a][i];
            b = lcap[b][i];
        }
    }
    return lcap[a][0];
}

bool in_subtree(int a, int b) {
    return pre[a] <= pre[b] && pre[b] <= pre_max[a];
}

int lca_pre(int a, int b) {
    if (in_subtree(b, a)) {
        return b;
    }

    for (int i = LOG; i >= 0; --i) {
        if (!in_subtree(lcap[b][i], a)) {
            b = lcap[b][i];
        }
    }
    return lcap[b][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 1);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca_depth(a, b) << " " << lca_pre(a, b) << "\n";
    }
}
