#include <cassert>
#include "immutable_list.h"
#include "list.h"
#include "dynamic_array.h"
#include "queue.h"
#include "priority_queue_and_heap.h"
void TestSequence(Sequence<int> *sequence) {
    ImmutableList<int> list1;
    ImmutableList<int> newList = list1.InsertAt(10, 0);
    assert(newList.GetLength() == 1);
    assert(newList[0] == 10);

    newList = newList.InsertAt(20, 1);
    assert(newList.GetLength() == 2);
    assert(newList[1] == 20);

    newList = newList.InsertAt(15, 1);
    assert(newList.GetLength() == 3);
    assert(newList[1] == 15);
    assert(newList[2] == 20);

    std::cout << "IMMUTABLE LINKED LIST TEST #1 PASSED SUCCESSFULLY\n";


    ImmutableList<int> list2;
    ImmutableList<int> newList2 = list2.InsertAt(10, 0);
    newList = newList.InsertAt(20, 1);
    newList = newList.InsertAt(30, 2);


    assert(newList[0] == 10);
    assert(newList[1] == 20);
    assert(newList[2] == 30);
    std::cout << "IMMUTABLE LINKED LIST TEST #2 PASSED SUCCESSFULLY\n";
    ImmutableList<int> newlist1, newlist2;
    newlist1 = newlist1.Append(52);
    newlist1 = newlist1.InsertAt(10, 1);
    newlist2 = newlist2.InsertAt(20, 0);
    newlist2 = newlist2.InsertAt(30, 1);
    ImmutableList<int> summ12, summ21;
    summ12 = newlist1 + newlist2;
    summ21 = newlist2 + newlist1;
    assert(summ12.GetLength() == 4);
    assert(summ12[0] == 52);
    assert(summ12[1] == 10);
    assert(summ12[2] == 20);
    assert(summ12[3] == 30);
    assert(summ21.GetLength() == 4);
    assert(summ21[0] == 20);
    assert(summ21[1] == 30);
    assert(summ21[2] == 52);
    assert(summ21[3] == 10);

    List<int> list;
    list.Append(1);
    list.Prepend(2);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);

    list.Append(3);
    list.Append(4);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 4);

    list.Append(5);
    list.Append(6);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.Get(4) == 5);
    assert(list.Get(5) == 6);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 6);

    std::cout << "LINKED LIST TEST PASSED SUCCESSFULLY\n";

    DynamicArray<int> dynArray;
    dynArray.Resize(1);
    dynArray[0] = 1;
    dynArray.Resize(2);
    dynArray[1] = 2;
    dynArray.Resize(3);
    dynArray[2] = 3;

    assert(dynArray.Size() == 3);
    assert(dynArray[0] == 1);
    assert(dynArray[1] == 2);
    assert(dynArray[2] == 3);

    dynArray.Resize(0);

    assert(dynArray.Size() == 0);
    assert(sequence->GetLength() == 0);

    sequence->Append(10);
    sequence->Append(20);

    assert((*sequence)[0] == 10);
    assert((*sequence)[1] == 20);
    std::cout << "DYNAMIC ARRAY TEST PASSED SUCCESSFULLY\n";

    ArraySequence<int> array;
    ListSequence<int> linkedlist;
    Sequence<int> *sequence2;
    if (sequence == dynamic_cast<ListSequence<int> *>(sequence)) {
        sequence2 = static_cast<Sequence<int> *>(&array);
    } else {
        sequence2 = static_cast<Sequence<int> *>(&linkedlist);
    }
    sequence2->Append(10);
    sequence2->Append(20);

    (*sequence2)[1] = 15;
    assert((*sequence2)[1] == 15);

    (*sequence2)[0] = 5;
    sequence2->InsertAt(10, 1);
    sequence2->InsertAt(20, 3);
    auto a = (*sequence2)[0];
    assert((*sequence2)[0] == 5);
    assert((*sequence2)[1] == 10);
    assert((*sequence2)[2] == 15);
    assert((*sequence2)[3] == 20);
    (*sequence2)[sequence2->GetLength() - 1] = 25;
    assert((*sequence2)[sequence2->GetLength() - 1] == 25);

    assert(sequence2->Prepend(1));
    assert((*sequence2)[1] == 5);

    assert(sequence2->Prepend(0));

    sequence2->Clear();
    assert(sequence2->GetLength() == 0);

    sequence2->Append(10);
    sequence2->Append(20);

    assert((*sequence2)[0] == 10);
    assert((*sequence2)[1] == 20);

    sequence2->Clear();
    assert(sequence2->GetLength() == 0);

    sequence2->Clear();
    assert(sequence2->GetLength() == 0);

}


