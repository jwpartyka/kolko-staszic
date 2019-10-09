// Wyszukiwanie binarne po wyniku.
// Wynik jest liczbą RZECZYWISTĄ (czyli nie musi być całkowity).
// Naszym zadaniem jest zminimalizować wynik.
// Założenie: Od pewnego momentu, dla wszystkich liczb rzeczywistych istnieje
//            poprawne rozwiązanie. Czyli, jeżeli oznaczymy przez 1, że istnieje
//            rozwiązanie, a prze 0, że nie istnieje, to ma być tak (dla kolejnych liczba rzeczywistych):
//            ...000000000011111111111...
//
// Jeżeli mamy zmaksymalizować wynik, to założenie jest tak jakby na odwrót.
// Założyłem, że wynik zawsze istnieje. Pewnie nie zawsze tak musi być.

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9, INF = 1e9; // Dokładność z jaką chcemy poznać wynik.

// Funkcja sprawdzająca, czy istnieje poprawne rozwiązanie z wynikiem x.
bool check(double x) {
    return 1;
}

// Funkcja wypisująca poprawne rozwiązanie dla wyniku x
void wypisz_wynik(double x) {
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(9) << fixed;

    // Wyszukiwanie binarne po wyniku.
    // Zmienna 'l' powinna początkowo być ustawiona na najmniejszy możliwy wynik
    // Zmienna 'r' powinna być ustawiona na największy możliwy wynik
    double l = -INF, r = INF;
    while (r - l > EPS) {
        double mid = (l + r) / 2.;
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

    wypisz_wynik(l);
}
