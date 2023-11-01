#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace Impl {
template <class T>
class List {
public:
    List();
    List(size_t size);
    List(std::initializer_list<T> init);

    ~List();
    
    size_t size() const noexcept;

    bool is_filled() const noexcept;
    bool in_range(size_t i) const noexcept;

    T& operator[](size_t i) const;
    void add(const T& val);
    void remove(size_t i);
    void pop_back() noexcept;

private:
    void allocate_space(size_t count = 1);
    void out_of_range(size_t i) const;

    T* data;

    size_t alloc_size, used_size;
};

template <class T>
List<T>::List(): List(0) {}

template <class T>
List<T>::List(size_t size): data{size == 0 ? nullptr : new T[size]}, alloc_size{size}, used_size{0} {}

template <class T>
List<T>::List(std::initializer_list<T> init): List(init.size()) {
    std::for_each(init.begin(), init.end(), [&](const T& x) {
        data[used_size++] = x;
    });
}

template <class T>
List<T>::~List() {
    if (data) delete[] data;
}

template <class T>
size_t List<T>::size() const noexcept {
    return used_size;
}

template <class T>
bool List<T>::is_filled() const noexcept {
    return alloc_size == used_size;
}

template <class T>
bool List<T>::in_range(size_t i) const noexcept {
    if (used_size == 0) return false;
    return i == std::clamp(i, (size_t)0, used_size - 1);
}

template <class T>
T& List<T>::operator[](size_t i) const {
    if (!in_range(i)) out_of_range(i);
    return data[i];
}

template <class T>
void List<T>::add(const T& val) {
    if (is_filled()) allocate_space();
    data[used_size++] = val;
}

template <class T>
void List<T>::remove(size_t i) {
    if (!in_range(i)) out_of_range(i);
    memmove(data + i, data + i + 1, sizeof(T) * (used_size-- - i));
}

template <class T>
void List<T>::pop_back() noexcept {
    if (used_size > 0) used_size--;
}

template <class T>
void List<T>::allocate_space(size_t count) {
    data = (T*)realloc(data, (alloc_size + count) * sizeof(T));
    alloc_size += count;
}

template <class T>
void List<T>::out_of_range(size_t i) const {
    std::stringstream ss;
    ss << "Tried accessing out-of-range index " << i;
    throw std::out_of_range{ss.str()};
}
}

int main() {
    using namespace Impl;

    List<int> numbers({1, 2, 3, 4, 5});
    numbers.add(6);

    numbers.remove(0);
    numbers.remove(4);
    numbers.remove(2);

    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
    }

    return EXIT_SUCCESS;
}
