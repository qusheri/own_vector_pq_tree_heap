#include "dynamic_array.h"
#include "sorting_algorithms.h"
void test_3_1(){
    DynamicArray<int> arr({5, 2, 2, 4, 2, 9});
    bubble_sort(arr, [](int a, int b){return a > b;});
    for(int i = 0; i < arr.Size(); ++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}