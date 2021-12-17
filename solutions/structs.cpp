
// Индивидуальные задачи на тему "Структуры"
// #15

// Условие:
// Даны сведения о спортсменах: ФИО, страна, вид спорта, рост, вес.
// Вычислить количество спортсменов, у которых рост превышает средний рост,
// а вес не превышает средний вес.

#include <iostream>
#include <string>

struct Athlete {
    std::string Name;
    std::string Country;
    std::string Sport;
    float Height = 0;
    float Weight = 0;
};

Athlete NextAthlete() {
    Athlete athlete;
    std::cout << "Give me athlete's data:\n";
    std::cout << "\tName: "; std::getline(std::cin >> std::ws, athlete.Name);
    std::cout << "\tCountry: "; std::getline(std::cin >> std::ws, athlete.Country);
    std::cout << "\tSport: ";   std::getline(std::cin >> std::ws, athlete.Sport);
    std::cout << "\tHeight: ";  std::cin >> athlete.Height;
    std::cout << "\tWeight: ";  std::cin >> athlete.Weight;
    std::cout << "\tDone.\n";
    return athlete;
}

int main() {
    int n; std::cin >> n;

    auto *athletes = new Athlete[n];
    for (int i = 0; i < n; ++i) {
        athletes[i] = NextAthlete();
        std::cout << '\n';
    }

    float averageHeight = 0,
          averageWeight = 0;

    {
        float heightsSum = 0,
              weightsSum = 0;
        for (int i = 0; i < n; ++i) {
            heightsSum += athletes[i].Height;
            weightsSum += athletes[i].Weight;
        }
        averageHeight = heightsSum / n;
        averageWeight = weightsSum / n;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        const Athlete& athlete = athletes[i];
        count += athlete.Height > averageHeight
                && athlete.Weight <= averageWeight;
    }

    std::cout << '\n';
    std::cout << "Results:\n";
    std::cout << "\tCriteria: Athlete's weighs below the average and height is above the average.\n";
    std::cout << "\tCount: " << count << '\n';
    std::cout << '\n';

    return 0;
}
