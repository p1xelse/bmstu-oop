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
void printSet(Set<T> &&set) {
    printSet(set);
}

int main() {
    Set<int> set1({1, 2, 3, 4});
    printSet(set1);

    Set<int> set2({2, 3});
    printSet(set2);

    printSet(set1 + set2);
    printSet(set1 - set2);

    return 0;
}
