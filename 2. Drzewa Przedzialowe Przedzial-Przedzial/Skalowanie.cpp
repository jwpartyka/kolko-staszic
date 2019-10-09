#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> sc;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        // Jeżeli odwołamy się do jakiegoś indeksu w mapie, ale nic tam nie przypiszemy,
        // to przypisze się automatycznie wartość 0
        sc[a[i]];
    }

    int numer = 1;
    for (auto &it : sc) {
        it.second = numer;
        numer++;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " --> " << sc[a[i]] << "\n";
    }
}

// Test: a = {5, 2, 7, 1000, 2} --> sc[a] = {2, 1, 3, 4, 1}
