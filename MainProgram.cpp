// ============================================================================
//  Lab: C++ Templates  (STUDENT VERSION)
//  Course: Object-Oriented Programming with C++
//  Single file only. No headers. C++17.
//
//  Complete every TODO. Do NOT rename the functions/classes/methods,
//  and do NOT change their signatures - the autograder depends on them.
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// ================================
// CLASS / TEMPLATE DEFINITIONS
// ================================

// ---- Group 1: Basic function template -------------------------------------
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// ---- Group 2: Function template with multiple type parameters --------------
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// ---- Group 3: Class template ----------------------------------------------
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    // Constructor
    Pair(A first, B second)
        : first_(first), second_(second) {
    }
    // Getters
    A getFirst() const {
        return first_;
    }
    B getSecond() const {
        return second_;
    }
    // Setters
    void setFirst(A value) {
        first_ = value;
    }
    void setSecond(B value) {
        second_ = value;
    }
    // Swap values (assume A == B when called)
    void swapValues() {
        A temp = first_;
        first_ = second_;
        second_ = temp;
    }
};

// ---- Group 4: Generic container -------------------------------------------
template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    // Add item
    void add(const T& item) {
        items_.push_back(item);
    }

    // Size
    int size() const {
        return static_cast<int>(items_.size());
    }

    // Get item
    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return items_[index];
    }

    // Total sum
    T total() const {
        T sum = T();

        for (const auto& item : items_) {
            sum += item;
        }

        return sum;
    }
};

// ---- Group 5: Template specialization -------------------------------------
template <typename T>
int describe(const T& value) {
    return 1;
}

// Full specialization for std::string
template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}

// ---- Group 6: Non-type template parameter ---------------------------------
template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    // Default constructor
    FixedArray() {
        for (int i = 0; i < N; i++) {
            data_[i] = T();
        }
    }

    // Capacity
    int capacity() const {
        return N;
    }

    // Set element
    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }

        data_[index] = value;
    }

    // Access element
    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }

        return data_[index];
    }
};

// ================================
// FUNCTION IMPLEMENTATIONS / main
// ================================

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = "
              << maxValue(3, 7) << "\n";

    std::cout << "addValues(5, 2.5) = "
              << addValues(5, 2.5) << "\n";

    Pair<int, int> p(10, 20);
    p.swapValues();
    std::cout << "Pair after swap: "
              << p.getFirst() << " "
              << p.getSecond() << "\n";

    Box<int> box;
    box.add(5);
    box.add(10);
    box.add(15);

    std::cout << "Box size: "
              << box.size() << "\n";

    std::cout << "Box total: "
              << box.total() << "\n";

    std::cout << "describe(42) = "
              << describe(42) << "\n";

    std::cout << "describe(\"hello\") = "
              << describe(std::string("hello")) << "\n";

    FixedArray<int, 5> arr;
    arr.set(0, 100);
    arr.set(1, 200);

    std::cout << "FixedArray capacity: "
              << arr.capacity() << "\n";

    std::cout << "arr[0] = "
              << arr.at(0) << "\n";

    return 0;
}
