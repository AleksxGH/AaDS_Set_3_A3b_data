//
// Created by user on 16.11.2025.
//

#ifndef SORTS_H
#define SORTS_H
#include <random>
#include <vector>

const int THRESHOLD = 16;

inline void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

inline void heapify(std::vector<int>& A, int n, int i, int offset) {
    int largest = i;
    int left = offset + 2 * (i - offset) + 1;
    int right = offset + 2 * (i - offset) + 2;

    if (left < offset + n && A[left] > A[largest]) {
        largest = left;
    }

    if (right < offset + n && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(A[i], A[largest]);
        heapify(A, n, largest, offset);
    }
}

inline void heapSort(std::vector<int>& A, int left, int right) {
    int n = right - left + 1;

    for (int i = left + n / 2 - 1; i >= left; i--) {
        heapify(A, n, i, left);
    }

    for (int i = right; i > left; i--) {
        std::swap(A[left], A[i]);
        heapify(A, i - left, left, left);
    }
}

inline int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

inline int randomized_partition(std::vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

inline void quickSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = randomized_partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

inline void modifiedQuickSort(std::vector<int>& arr, int left, int right, int depthLimit) {
    if (right - left + 1 <= THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }

    int pivot = partition(arr, left, right);
    if (left < pivot - 1) {
        modifiedQuickSort(arr, left, pivot - 1, depthLimit - 1);
    }
    if (pivot < right) {
        modifiedQuickSort(arr, pivot, right, depthLimit - 1);
    }
}

inline void introSort(std::vector<int>& arr, int left, int right) {
    int depthLimit = 2 * log2(right - left + 1);
    modifiedQuickSort(arr, left, right, depthLimit);
}

#endif //SORTS_H
