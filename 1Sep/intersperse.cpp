#include <algorithm>
#include <iostream>
#include <vector>


using List = std::vector<int>;
using ListOLists = std::vector<List>;

void intersperse(const ListOLists& inList, List& outList) {
    int j = 0;
    while (true) {
        int numAdded = 0;
        for (int i = 0; i < inList.size(); ++i) {
            if (j < inList[i].size()) {
                outList.push_back(inList[i][j]);
                ++numAdded;
            }
        }
        if (numAdded == 0) {
            break;
        }
        ++j;
    }
}

int main() {
    ListOLists inList = {{1, 2, 3, 4, 11, 12}, {5, 6, 7}, {8, 9, 10, 13}};
    List outList;
    intersperse(inList, outList);
    std::for_each(outList.begin(), outList.end(), [] (int x) { std::cout << x << " "; });
    return 0;
}
