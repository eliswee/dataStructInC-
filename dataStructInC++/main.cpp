//
//  main.cpp
//  dataStructInC++
//
//  Created by May on 2021/2/18.
//

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "selectionSort/SelectionSort.h"
#include "insertionSort/InsertionSort.h"
#include "bubbleSort/BubbleSort.h"
#include "MergeSort.h"
#include "practice.h"

void test();

int main(int argc, const char * argv[]) {
    test();
    return 0;
}

void test() {
    int n = 50000;
    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete(arr1);
    delete(arr2);
}
