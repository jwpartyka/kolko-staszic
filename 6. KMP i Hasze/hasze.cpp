// Program, który oblicza tablicę haszy wszystkich prefiksów słowa,
// a następnie odpowiada na q zapytań o porównanie dwóch podsłów słowa s

#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7, p = 997, MAXN = 1e6 + 5;

int pp[MAXN], H[MAXN];

// Funkcja zwracająca hasz słowa s[a, ..., b]
int hasz(int a, int b) {
    if (a == 0) {
        return H[b];
    }
    return ((0LL + H[b] - 1LL * H[a - 1] * pp[b - a + 1]) % mod + mod) % mod;
}

// Funkcja porównująca podsłowo s[a, ..., b] i s[c, ..., d]
bool cmp(int a, int b, int c, int d) {
    if (b - a != d - c) {
        return 0;
    }
    return hasz(a, b) == hasz(c, d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    pp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pp[i] = (1LL * pp[i - 1] * p) % mod;
    }

    H[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; ++i) {
        H[i] = (1LL * H[i - 1] * p + s[i] - 'a' + 1) % mod;
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cmp(a, b, c, d) << "\n";
    }
}
