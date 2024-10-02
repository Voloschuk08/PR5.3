#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double z(const double k);
double z_rec(const double x);

int main()
{
    double kmin, kmax;
    int n;

    // Введення параметрів
    cout << "kmin = "; cin >> kmin;
    cout << "kmax = "; cin >> kmax;
    cout << "n = "; cin >> n;

    double dk = (kmax - kmin) / n;
    double k = kmin;

    cout << fixed;
    cout << "--------------------------------------------------" << endl;
    cout << "|" << setw(10) << "k" << " |"
        << setw(15) << "z(k)" << " |" << endl;
    cout << "--------------------------------------------------" << endl;

    // Обчислення та виведення значень у таблиці
    while (k <= kmax)
    {
        double result = z(k); // Обчислення z(k)
        cout << "|" << setw(10) << setprecision(5) << k << " |"
            << setw(15) << setprecision(5) << result << " |" << endl;
        k += dk;
    }

    cout << "--------------------------------------------------" << endl;

    return 0;
}

double z(const double k)
{
    double z_val;

    // Формула для обчислення z(k)
    z_val = 2 * (2 * k + 1) - pow(z_rec(2 * k - 1), 2) + sqrt(z_rec(k));

    return z_val;
}

// Допоміжна функція для обчислення z_rec(x)
double z_rec(const double x)
{
    if (abs(x) >= 1)
    {
        // Для |x| >= 1
        return (cos(x) + 1) / (exp(-x) + 1);
    }
    else
    {
        // Для |x| < 1
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;

        do {
            j++;
            double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);
            a *= R;
            S += a;
        } while (j < 4);

        return S;
    }
}
