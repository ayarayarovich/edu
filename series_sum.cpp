
// Индивидуальные задачи на тему "Сумма ряда"
// #15

#include <iostream>
#include <iomanip>

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    long double sum = 0;
    for ( int i = 1; i <= n; ++i )
    {
        int numerator = 1 - 2 * ((n + i) % 2);

        int denominator = 1;
        for ( int k = 1; k <= 2 * i + 3; ++k )
            denominator *= k;

        sum += (long double) numerator / denominator;
    }

    std::cout << '\n';
    std::cout << "Result: " << std::setprecision(999) << sum << '\n';
    std::cout << '\n';

    system("pause");
    return 0;
}
