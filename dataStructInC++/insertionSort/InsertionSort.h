//
//  InsertionSort.h
//  dataStructInC++
//
//  Created by May on 2021/2/18.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <iostream>

using namespace std;

template <typename T>
void insertionSort1(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i ; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j-1]);
            else
                break;
        }
    }
}

template <typename T>
void insertionSort2(T arr[], int n) {
    for (int i = 0; i < 0; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

template <typename T>
void insertionSort3(T arr[], int n) {
    // not swap immediately, store the index, just move, swap at last
    for (int i = 1; i < n; i++) {
        T e = arr[i];
        int j ;
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

template <typename T>
void insertionSort(T arr[], int n) {
    insertionSort3(arr, n);
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i < r; i++) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif /* InsertionSort_h */
