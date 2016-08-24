#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using List1 = std::vector<char>;
using List2 = std::vector<std::pair<int, int>>;

void swapElem(char& first, char& second) {
    char temp = first;
    first = second;
    second = temp;
}

void swap(List1& list1, const List2& pairs) {
    for (const auto& it : pairs) {
        swapElem(list1[it.first], list1[it.second]);
    }
}

int main() {
    // List1 list1 = {'a', 'b', 'c'};
    // List2 list2 = {{0, 2}, {1, 2}};

    List1 list1 = {'a', 'b', 'c', 'e'};
    List2 list2 = {{0, 2}, {1, 2}, {2, 2}};

    swap(list1, list2);

    std::for_each(list1.begin(), list1.end(), [](char& c) {std::cout << c << " ";});
    std::cout << 'n';

    return 0;
}
