//
//  BubbleSort.h
//  dataStructInC++
//
//  Created by May on 2021/2/19.
//

#ifndef BubbleSort_h
#define BubbleSort_h

template<typename T>
void bubbleSort(T arr[], int n) {
    bool swaped;
    do {
        swaped = false;
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i+1]);
                swaped = true;
            }
        }
        n--;
    } while (swaped);
}

template<typename T>
void bubbleSort_1(T arr[], int n) {
    
    if (!arr || n < 2) return;
    
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubbleTest() {
    int c = 1000;
    do {
        int n = 1000;
        int *arr = SortTestHelper::generateRandomArray(n, 0, 50);
        bubbleSort(arr, n);
        assert(SortTestHelper::isSorted(arr, n));
        delete [] arr;
        c--;
    } while (c);
    cout<<"done"<<endl;
}

#endif /* BubbleSort_h */
