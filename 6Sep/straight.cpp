#include <functional>
#include <iostream>
#include <utility>
#include <vector>


void print(const std::vector<int>& numbers, int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';
}

template <typename Compare>
std::pair<int, int> straight_util(const std::vector<int>& numbers,
                                  Compare comp) {
    int longestStart = 0;
    int longestEnd = 0;
    int currentStart = 0;
    int currentEnd = 0;
    for (int i = 1; i < numbers.size(); ++i) {
        if (comp(numbers[i-1], numbers[i])) {
            currentEnd = i;
        } else {
            if ((currentEnd - currentStart) > (longestEnd - longestStart)) {
                longestStart = currentStart;
                longestEnd = currentEnd;
            }
            currentStart = i;
        }
    }
    return std::make_pair(longestStart, longestEnd);
}

void straight(const std::vector<int>& numbers) {
    std::pair<int, int> pair1 = straight_util(numbers, std::less<int>());
    std::pair<int, int> pair2 = straight_util(numbers, std::greater<int>());

    if (pair1.second - pair1.first > pair2.second - pair2.first) {
        print(numbers, pair1.first, pair1.second);
    } else {
        print(numbers, pair2.first, pair2.second);
    }
}

int main() {
    std::vector<int> numbers = {1, 3, 3, 5, 6, 4, 2, 1, 7};
    // std::vector<int> numbers = {1, 3, 4, 5, 6, 4, 2, 1, 7};
    straight(numbers);
}
