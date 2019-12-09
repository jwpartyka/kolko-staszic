// Algorytm KMP do wyszukiwania wzorca w tekście
// Aby wyszukać wzorzec s w tekście t należy stworzyć tablicę prefikso-sufiksów
// dla słowa s + '#' + t i sprawdzić ile razy w tablicy prefikso-sufiksów
// występuje długość wzorca.

#include <bits/stdc++.h>

using namespace std;

// Zwraca tablicę prefikso-sufiksów słowa s
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> ps(n, 0);
    int len = -1;
    for (int i = 0; i < n; ++i) {
        while (len >= 0 && s[i] != s[len]) {
            if (len == 0) {
                len = -1;
            } else {
                len = ps[len - 1];
            }
        }
        len++;
        ps[i] = len;
    }
    return ps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // s - wzorzec, t - tekst
    string s, t;
    cin >> s >> t;

    auto ps = kmp(s + '#' + t);
    int res = 0;
    for (int i : ps) {
        if (i == (int)s.size()) {
            res++;
        }
    }
    cout << res << "\n";
}
