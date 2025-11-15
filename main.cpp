#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "ArrayGenerator.hpp"
#include "SortTester.hpp"


int main() {
    const int MAX_N = 100000;
    const int RUNS = 7;

    std::ofstream csv("sorting_results.csv");
    csv << "N,Quick_Random,Intro_Random,Quick_Inverted,Intro_Inverted,Quick_Almost,Intro_Almost\n";

    std::vector<int> base = ArrayGenerator::GetRandomVector(MAX_N, 0, 6000);
    std::vector<int> inv = ArrayGenerator::GetInvertedVector(base);
    std::vector<int> alm = ArrayGenerator::GetAlmostSortedVector(base);

    for (int n = 500; n <= MAX_N; n += 1000) {
        long long qr = 0, qi = 0, qa = 0;  // QuickSort results
        long long ir = 0, ii = 0, ia = 0;  // IntroSort results

        for (int i = 0; i < RUNS; i++) {
            qr += SortTester::measureQuickSort(std::vector<int>(base.begin(), base.begin() + n), 0, n - 1);
            qi += SortTester::measureQuickSort(std::vector<int>(inv.begin(), inv.begin() + n), 0, n - 1);
            qa += SortTester::measureQuickSort(std::vector<int>(alm.begin(), alm.begin() + n), 0, n - 1);

            ir += SortTester::measureIntroSort(std::vector<int>(base.begin(), base.begin() + n), 0, n - 1);
            ii += SortTester::measureIntroSort(std::vector<int>(inv.begin(), inv.begin() + n), 0, n - 1);
            ia += SortTester::measureIntroSort(std::vector<int>(alm.begin(), alm.begin() + n), 0, n - 1);
        }

        csv << n << ","
            << qr / RUNS << "," << ir / RUNS << ","
            << qi / RUNS << "," << ii / RUNS << ","
            << qa / RUNS << "," << ia / RUNS << "\n";

        std::cout << "N=" << n << " done\n";
    }

    csv.close();
    std::cout << "CSV successfully saved to sorting_results.csv!\n";
    return 0;
}