#include <iostream>

#include "Set.h"

using namespace std;

template <typename T>
void printSet(Set<T> &set) {
    for (auto iter = set.cbegin(); iter != set.cend(); ++iter)
        cout << *iter << " ";

    cout << endl;
}
template <typename T>
void printReverseSet(Set<T> &set) {
    for (auto iter = set.cend();; --iter) {
        if (iter != set.cend()) cout << *iter << " ";
        if (iter == set.cbegin()) break;
    }

    cout << endl;
}

template <typename T>
void printSet(Set<T> &&set) {
    printSet(set);
}

int main() {
    Set<int> set({1, 2, 3});
    auto iter = set.cend();
    iter--;

    cout << *iter << endl;
    Set<int> set2({4, 5, 6});

    set += set2;

    cout << *iter << endl;

    // auto iter = set1.cbegin();
    // iter++;
    // iter++;
    // iter--;
    // printReverseSet(set1);
    // cout << *iter;

    // Set<int> set2({2, 3});
    // printSet(set2);

    // printSet(set1 + set2);
    // printSet(set1 - set2);
    // auto iter = set1.cend();
    // iter--;

    return 0;
}
