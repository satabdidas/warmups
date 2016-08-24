#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>

using Count = int;
using Line = int;
using Key = std::pair<Count, Line>;

struct KeyComparator {
    bool operator () (const Key& key1, const Key& key2) const {
        if (key1.first == key2.first) {
            // The reverse check is there because if two lines have the same count
            // I want them to appear in the map in the ever order of their line number
            // so that when I reverse traverse the map, I get them in the correct order.
            return key1.second > key2.second;
        }
        return key1.first < key2.first;
    }
};

void rank(const std::string& fileName, const char c) {
    std::ifstream file(fileName);
    std::string str;
    std::multimap<Key, std::string, KeyComparator> rankMap;
    unsigned int line = 0;
    while (std::getline(file, str)) {
        unsigned int count = 0;
        for_each(str.begin(), str.end(),
                 [&](const char& cc) { if (c == cc) { ++count; }});
        rankMap.insert(std::make_pair(std::make_pair(count, line), str));
        ++line;
    }

    for_each(rankMap.crbegin(), rankMap.crend(),
             [](const std::pair<Key, std::string>& elem) {
                 std::cout << elem.second << '\n'; });
}

int main() {
    std::string fileName("input.txt");
    char c = 'e';

    rank(fileName, c);

    return 0;
}
