#ifndef SORTTESTER_H
#define SORTTESTER_H
#include <chrono>
#include <vector>
#include "Sorts.hpp"

class SortTester {
public:
  static long long measureQuickSort(std::vector<int> arr, int left, int right) {
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, left, right);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  }

  static long long measureIntroSort(std::vector<int> arr, int left, int right) {
    auto start = std::chrono::high_resolution_clock::now();
    introSort(arr, left, right);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  }
};

#endif //SORTTESTER_H
