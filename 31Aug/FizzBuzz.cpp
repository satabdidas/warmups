#include <iostream>
#include <string>

template <int n, int i>
class FizzBuzz {
public:
    enum {fb = false};
};

template <int n>
class FizzBuzz<n, 15> {
public:
    enum {fb = n % 15 == 0};
};

template <int n>
class FizzBuzz<n, 5> {
public:
    enum {fb = n % 5 == 0};
};

template <int n>
class FizzBuzz<n, 3> {
public:
    enum {fb = n % 3 == 0};
};

template <int i>
class FizzBuzzPrint {
public:
    FizzBuzzPrint<i-1> a;
    enum { fb = FizzBuzz<i, 15>::fb, f = FizzBuzz<i, 5>::fb, b = FizzBuzz<i, 3>::fb};
    void func() {
        a.func();
        if (fb) {
            std::cout << "FizzBuzz\n";
        } else if (f) {
            std::cout << "Fizz\n";
        } else if (b) {
            std::cout << "Buzz\n";
        } else {
            std::cout << i << '\n';
        }
    }
};

template <>
class FizzBuzzPrint <1> {
public:
    enum { fb = false, f = false, b = false};
    void func() { std::cout << "1\n"; }
};

void faasR(int i = 1) {
    if (i == 100) {
        return;
    }
    if (i % 15 == 0) {
        std::cout << "FizzBuzz\n";
    } else if (i % 5 == 0) {
        std::cout << "Buzz\n";
    } else if (i % 3 == 0) {
        std::cout << "Fizz\n";
    } else {
        std::cout << i << '\n';
    }

    faasR(i + 1);
}

void faas1(int d = 1, const std::string& str = std::string()) {
    for (int i = 1; i <= 100; i = i + d) {
        if (i % 15 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz\n";
        } else {
            if (str.empty()) {
                std::cout << i << '\n';
            } else {
                std::cout << str << '\n';
            }
        }
    }
}

int main() {
    std::cout << "Running faas1:\n";
    faas1();
    std::cout << "Running faas2:\n";
    faas1(2);
    std::cout << "Running faas3:\n";
    faas1(1, "blorp");
    std::cout << "Running faasR:\n";
    faasR();

    FizzBuzzPrint<100> a;
    a.func();
    return 0;
}
