#include "dynamic_array.h"
#include "sorting_algorithms.h"
void test_3_1(){
    DynamicArray<int> arr({5, 2, 2, 4, 2, 9});
    DynamicArray<int> arr1 = arr;
    DynamicArray<int> arr2 = arr;
    arr.bubble_sort([](int a, int b){return a > b;});
    for(int i = 0; i < arr.Size(); ++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    arr1.shacker_sort([](int a, int b){return a > b;});
    for(int i = 0; i < arr1.Size(); ++i){
        std::cout << arr1[i] << ' ';
    }
    std::cout << '\n';
    arr2.merge_sort([](int a, int b){return a > b;});
    for(int i = 0; i < arr2.Size(); ++i){
        std::cout << arr2[i] << ' ';
    }
    std::cout << '\n';
}