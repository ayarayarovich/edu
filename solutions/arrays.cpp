
// Индивидуальные задачи на тему "Массивы"
// #15

// Условие:
// Дан массив целых чисел. Сформировать новый логический массив,
// каждый элемент которого равен 0, если соответствующий
// элемент исходного массива совершенный и 1 в противном случае.

#include <iostream>

int main()
{
    std::cout << "Enter array length: ";
    int n;
    std::cin >> n;

    std::cout << "Enter sequence of " << n << " elements:\n";
    int arr[1000];
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    bool brr[1000];
    for (int i = 0; i < n; ++i) {
        int ds = 0;
        for (int d = 1; d <= arr[i] / 2; ++d)
            ds += d * (arr[i] % d == 0);

        bool isPerfect = arr[i] == ds;
        brr[i] = !isPerfect;
    }

    for (int i = 0; i < n; ++i)
        std::cout << brr[i] << ' ';
    std::cout << '\n';

    system("pause");
    return 0;
}
