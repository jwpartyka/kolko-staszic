#include <bits/stdc++.h>

using namespace std;

int R(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));

    int n = R(1, 5), maks = 1e9;
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << R(-maks, maks) << " ";
    }
    cout << "\n";
}
