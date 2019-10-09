// Drzewo przedziałowe przedział-przedział
// Operacje:
// 1) Dodaj wartość na przedziale
// 2) Zczytaj sumę z przedziału

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Największa możliwa liczba liści w drzewie przedziałowym
const int MAX_BASE = (1 << 19);

// Struct przechowujący wartości dla węzłów drzewa
// sum = suma wartości na przedziale
// lazy = wartość do zrzucenia
struct Node {
    ll sum, lazy;
};

Node Tree[2 * MAX_BASE];

void zepchnij(int node, int left, int right) {
    int sz = (right - left + 1) / 2;

    // 'i' przyjmie kolejno wartości '2 * node' i '2 * node + 1' - dzieci węzła node
    for (int i : {2 * node, 2 * node + 1}) {
        Tree[i].sum += 1LL * sz * Tree[node].lazy;
        Tree[i].lazy += Tree[node].lazy;
    }

    // Zerujemy lazy, bo nie chcemy w przyszłości znowu zepchnąć wartości,
    // którą już zepchnęliśmy
    Tree[node].lazy = 0;
}

// Dodaj liczbę c na przedziale [l, r].
// Początkowe wartości (node, left, right) = (1, 0, base - 1).
void chTree(int node, int left, int right, int l, int r, int v) {
    // Jeżeli przedział węzła node znajduje się całkowicie poza przedziałem
    // z zapytania, to wyjdź z tego węzła.
    if (r < left or right < l) {
        return;
    }

    // Jeżeli przedział węzła node znajduje się całkowicie wewnątrz przedziału
    // z zapytania, to jesteś w przedziale bazowym.
    if (l <= left and right <= r) {
        Tree[node].sum += 1LL * (right - left + 1) * v;
        Tree[node].lazy += v;
        return;
    }

    // Jeżeli jest coś do zepchnięcia, to to zepchnij
    if (Tree[node].lazy) {
        zepchnij(node, left, right);
    }

    int mid = (left + right) / 2;
    chTree(2 * node, left, mid, l, r, v);
    chTree(2 * node + 1, mid + 1, right, l, r, v);

    // Zaktualizuj wynik dla węzła na podstawie jego dzieci
    Tree[node].sum = Tree[2 * node].sum + Tree[2 * node + 1].sum;
}

// Zczytaj sumę z przedziału [l, r]
// Początkowe wartości (node, left, right) = (1, 0, base - 1).
ll read(int node, int left, int right, int l, int r) {
    // Jeżeli przedział węzła node znajduje się całkowicie poza przedziałem
    // z zapytania, to wyjdź z tego węzła.
    if (r < left or right < l) {
        return 0;
    }

    // Jeżeli przedział węzła node znajduje się całkowicie wewnątrz przedziału
    // z zapytania, to jesteś w przedziale bazowym.
    if (l <= left and right <= r) {
        return Tree[node].sum;
    }

    // Jeżeli jest coś do zepchnięcia, to to zepchnij
    if (Tree[node].lazy) {
        zepchnij(node, left, right);
    }

    int mid = (left + right) / 2;
    return read(2 * node, left, mid, l, r) + read(2 * node + 1, mid + 1, right, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // base = liczba liści w drzewie przedziałowym
    // Jeżeli ciąg liczb jest indeksowany od 1 do n to musi być warunek (base <= n).
    // Albo można zawsze od końców przedziałów odejmować 1, aby był od 0 do n - 1.
    int base = 1;
    while (base < n) {
        base *= 2;
    }

    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            int c;
            cin >> c;
            chTree(1, 0, base - 1, a, b, c);
        } else {
            cout << read(1, 0, base - 1, a, b) << "\n";
        }
    }
}
