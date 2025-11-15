#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H
#include <algorithm>

class ArrayGenerator {
public:
  static std::vector<int> GetRandomVector(int size, int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dis(min, max);
    std::vector<int> v(size);
    std::generate(v.begin(), v.end(), [&]() { return dis(gen); });
    return v;
  }

  static std::vector<int> GetInvertedVector(std::vector<int> v) {
    std::sort(v.begin(), v.end(), std::greater<int>());
    return v;
  }

  static std::vector<int> GetAlmostSortedVector(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    std::mt19937 gen(std::random_device{}());
    int swaps = v.size() / 20; // 5%
    while (swaps--) {
      std::swap(v[gen() % v.size()], v[gen() % v.size()]);
    }
    return v;
  }
};

#endif //ARRAYGENERATOR_H
