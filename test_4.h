#include "priority_queue_and_heap.h"
#include "BST.h"
#include "Heap.h"
#include "cassert"
void test_map(){
    bst<int> test = bst<int>({1, 2, 3}).map([](int x){return x + 5;});
    vector<int> a = test.lkp();
    for(int i = 1; i < 4; i++){
        assert(a[i - 1] == i + 5);
    }
}

void test_where(){
    vector<string> a = bst<string>({"333", "4444", "666666"}).where([](const string& s){return s.length() % 2 == 0;}).lpk();
    assert(a.size() == 2);
    assert(a[0] == "666666");
    assert(a[1] == "4444");
}

void test_reduce(){
    assert(bst<int>({1, 2, 3}).reduce([](int x1, int x2){return 2 * x1 + 3 * x2;}, 3) == 117);
}

void testExtractSubtree() {
    bst<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    bst<int> extractedTree = tree.extractSubtree(3);
    std::vector<int> expectedExtract = {1,3,4};

    assert(extractedTree.inorderTraversal() == expectedExtract);
}
void test_4(){
    test_map();
    test_where();
    test_reduce();
    testExtractSubtree();
    bst<int> testTree;
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(7);
    testTree.insert(1);
    testTree.insert(4);

    assert(testTree.search(5) != nullptr);
    assert(testTree.search(3) != nullptr);
    assert(testTree.search(7) != nullptr);
    assert(testTree.search(1) != nullptr);
    assert(testTree.search(4) != nullptr);
    assert(testTree.search(2) == nullptr);
    std::vector<int> inorderResult = testTree.inorderTraversal();
    assert(inorderResult == std::vector<int>({1, 3, 4, 5, 7}));
    testTree.delete_element(5);

    assert(testTree.search(5) == nullptr);
    assert(testTree.search(3) != nullptr);
    assert(testTree.search(7) != nullptr);
    assert(testTree.search(1) != nullptr);
    assert(testTree.search(4) != nullptr);
    assert(testTree.search(2) == nullptr);
    bst<int> testTree2;
    assert(testTree2.search(0) == nullptr);
    testTree2 = testTree.map([](int x){return x + 2;});
    vector<int> map_vector = testTree2.inorderTraversal();
    assert(map_vector == vector<int>({3,5,6,9}));
    Heap<int> heap;
    heap.insert(5);
    heap.insert(10);
    heap.insert(3);
    assert(heap.size() == 3);
    assert(heap.top() == 10);

    assert(heap.extractMax() == 10);
    assert(heap.size() == 2);
    assert(heap.top() == 5);

    Heap<int> heap2({1, 2, 3, 4});

    Heap<int> heap3({6, 7, 8});
    auto mergedHeap = heap2.mergeHeaps(heap2, heap3);
    assert(mergedHeap.size() == 7);
    assert(mergedHeap.top() == 8);

    assert(heap3.extractMax() == 8);
    assert(heap3.size() == 2);
    assert(heap3.top() == 7);

    Heap<int> emptyHeap;
    assert(emptyHeap.size() == 0);
}