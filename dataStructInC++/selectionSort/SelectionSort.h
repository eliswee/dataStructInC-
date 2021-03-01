//
//  SelectionSort.h
//  dataStructInC++
//
//  Created by May on 2021/2/18.
//

#ifndef SelectionSort_h
#define SelectionSort_h

#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

/*
 O(n^2)
 */
template <typename T>
void selectionSort (T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1 ; j < n ; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void selectionSortTest() {
    // int
    int a[10] = {10, 9, 8 , 7, 6, 5, 4, 3, 2, 1};
    selectionSort(a, 10);
    
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    
    // float
    float a1[10] = {10.2, 9.4, 8.2, 7.2, 6.1, 5.6, 4, 3, 2, 1};
    selectionSort(a1, 10);
    
    for (int i = 0; i < 10; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;
    
    // string
    string a2[4] = {"D", "B", "C", "A"};
    selectionSort(a2, 4);

    for (int i = 0; i < 4; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;

    Student a3[4] = {{"D", 90}, {"B", 100}, {"C", 95}, {"A",95}};
    selectionSort(a3, 4);

    for (int i = 0; i < 4; i++) {
        cout << a3[i] << " ";
    }
    cout << endl;
    
    int num = 10000;
    int *arr = SortTestHelper::generateRandomArray(num, 0, 100);
    selectionSort(arr, num);
    SortTestHelper::printArray(arr, num);
    delete [] arr;
}

#endif /* SelectionSort_h */
