//
//  practice.h
//  dataStructInC++
//
//  Created by May on 2021/2/26.
//

#ifndef practice_h
#define practice_h

#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

void pTest() {
    
    int count = 10;
    do {
        int n = 100;
        int *arr = SortTestHelper::generateRandomArray(n, 0, 100);
        insertionSort(arr, 0, n);
        SortTestHelper::isSorted(arr, n);
        count--;
    } while (count);
    
    cout<<"test past"<<endl;
}

#endif /* practice_h */
