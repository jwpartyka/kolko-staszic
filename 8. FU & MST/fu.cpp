#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

struct Fu {
    int head, sz;
};

Fu fu[MAXN];

// Funkcja inicjująca strukturę FU
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fu[i] = {i, 1};
    }
}

// Funkcja znajdująca reprezentanta zbioru a.
int Find(int a) {
    if (fu[a].head != a) {
        fu[a].head = Find(fu[a].head);
    }
    return fu[a].head;
}

// Funkcja łącząca zbiory a i b w jeden zbiór.
void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return;
    }

    if (fu[a].sz < fu[b].sz) {
        swap(a, b);
    }
    fu[b].head = a;
    fu[a].sz += fu[b].sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    init(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        cout << Find(i) << " ";
    }
    cout << "\n";
}
