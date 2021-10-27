
// Индивидуальные задачи на тему "Последовательности"
// #15

// Условие:
// Дана последовательность целых чисел.
// Определить минимальное нечетное число последовательности.
// При решении учесть, что нечётных чисел в последовательности может не быть.

#include <iostream>

int main()
{
    std::cout << "Enter number sequence length: ";
    int n;
    std::cin >> n;

    if (n > 0)
        std::cout << "Enter sequence of " << n << " elements: ";

    int min_odd = 0;
    for ( int i = 0; i < n; ++i )
    {
        int k;
        std::cin >> k;
        if ( std::abs(k % 2) == 1 )
            if ( !min_odd || k < min_odd )
                min_odd = k;
    }

    std::cout << '\n';
    if ( !min_odd )
        std::cout << "The sequence doesn't contain any odd number.\n";
    else
        std::cout << "Minimum odd number in the sequence is " << min_odd << '\n';
    std::cout << '\n';

    system("pause");
    return 0;
}
