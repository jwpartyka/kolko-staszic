// Wyszukiwanie binarne po wyniku.
// Wynik jest liczbą całkowitą.
// Naszym zadaniem jest zminimalizować wynik.
// Założenie: Od pewnego momentu, dla wszystkich liczb całkowitych istnieje
//            poprawne rozwiązanie. Czyli, jeżeli oznaczymy przez 1, że istnieje
//            rozwiązanie, a prze 0, że nie istnieje, to ma być tak (dla kolejnych liczba całkowitych):
//            ...000000000011111111111...
//
// Jeżeli mamy zmaksymalizować wynik, to założenie jest tak jakby na odwrót.
// Założyłem, że wynik zawsze istnieje. Pewnie nie zawsze tak musi być.

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

// Funkcja sprawdzająca, czy istnieje poprawne rozwiązanie z wynikiem x.
bool check(int x) {
    // Do zaimplementowania
    return 1;
}

// Funkcja wypisująca poprawne rozwiązanie dla wyniku x
void wypisz_wynik(int x) {
    // Do zaimplementowania
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(9) << fixed;

    // Wyszukiwanie binarne po wyniku.
    // Zmienna 'l' powinna początkowo być ustawiona na najmniejszy możliwy wynik
    // Zmienna 'r' powinna być ustawiona na największy możliwy wynik
    int l = -INF, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            // Jeżeli istnieje rozwiązanie dla wartośći mid, to nie musimy już
            // sprawdzać większych wartośći, bo wiemy, że dla nich też jest OK.
            r = mid;
        } else {
            // W przeciwnym wypadku nie musimy sprawdzać mniejszych wartości,
            // bo dla nich też NIE MA OKEJ.
            l = mid;
        }
    }
    if (check(l)) {
        wypisz_wynik(l);
    } else {
        wypisz_wynik(r);
    }
}
