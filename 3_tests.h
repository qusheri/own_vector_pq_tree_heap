#include "priority_queue&heap.h"
#include "queue.h"
#include "cassert"
void test_3(){
    PriorityQueue<int> pq;
    assert(pq.size() == 0);
    pq.Push(4);
    pq.Push(7);
    pq.Push(2);
    pq.Push(9);
    pq.Push(1);
    assert(pq.Max() == 9);
    assert(pq.size() == 5);
    pq.Pop();
    assert(pq.size() == 4);
    assert(pq.Max() == 7);
    pq.Pop();
    pq.Pop();
    assert(pq.Max() == 2);
    assert(pq.size() == 2);
    pq.Pop();
    pq.Pop();
    assert(pq.size() == 0);
    pq.Push(2);
    assert(pq.map<int>([](int x){return x * 52;}).Max() == 104);
    pq.Push(1);
    pq.Push(3);
    assert(pq.reduce<int>([](int x1, int x2){return 2 * x1 + 3 * x2;}, 4) == 172);
    PriorityQueue<int> pq2 = pq.where([](int x){return x % 2 == 0;});
    assert(pq2.Max() == 2);
    assert(pq2.size() == 1);


    Queue<int> queue;
    assert(queue.size() == 0);
    queue.push(5);
    assert(queue.front() == 5);
    queue.push(1);
    queue.push(3);
    assert(queue.size() == 3);
    assert(queue.front() == 5);
    queue.push(2);
    assert(queue.front() == 5);
    assert(queue.size() == 4);
    queue.pop();
    assert(queue.size() == 3);
    assert(queue.front() == 1);
    queue.pop();
    queue.pop();
    assert(queue.size() == 1);
    queue.pop();
    assert(queue.size() == 0);
    cout << "ALL TESTS PASSED SUCCESSFULLY\n";
}