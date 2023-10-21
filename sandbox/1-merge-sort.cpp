#include <cstdlib>
#include <iostream>
#include <vector>

void print_arr_c(const int* const arr, size_t size);
void sort_arr_c(int* arr, size_t size);

void print_arr_cpp(const std::vector<int>& arr);
std::vector<int> sort_arr_cpp(const std::vector<int>& arr);

void sort_arr_ranges(std::vector<int>& arr);

int main(int argc, char** argv) {
    std::vector<int> x {6, 1, 3, 2, 9, 4};
   
    sort_arr_ranges(x);
    print_arr_cpp(x);

    return EXIT_SUCCESS;
}

void print_arr_c(const int* const arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

void print_arr_cpp(const std::vector<int>& arr) {
    for (int n : arr) {
        std::cout << n << ' ';
    }

    std::cout << std::endl;
}

void split_arr_c(int* arr, size_t l, size_t r) {
    if (l >= r) return;

    const size_t m = l + (r - l) / 2;
    split_arr_c(arr, l, m);
    split_arr_c(arr, m + 1, r);
    
    const size_t llen = m - l + 1, rlen = r - m;
    int *left = new int[llen],
        *right = new int[rlen];

    for (size_t i = 0; i < llen; i++) {
        left[i] = arr[l + i];
    }

    for (size_t i = 0; i < rlen; i++) {
        right[i] = arr[m + 1 + i];
    }

    std::cout << "Left:\n";
    print_arr_c(left, llen);

    std::cout << "Right:\n";
    print_arr_c(right, rlen);

    for (size_t i = l, li = 0, ri = 0; i <= r; i++) {
        if (li < llen && (ri >= rlen || left[li] < right[ri])) {
            arr[i] = left[li++];
        }
        else {
            arr[i] = right[ri++];
        }
    }

    std::cout << "Result:\n";
    print_arr_c(arr + l, llen + rlen);

    std::cout << std::endl;
    
    delete[] left;
    delete[] right;
}

std::vector<int> sort_arr_cpp(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    if (arr.size() == 1) return arr;

    const size_t size = arr.size();
    const size_t m = size / 2;

    const std::vector<int> left_view = std::vector<int>(arr.begin(), arr.begin() + m);
    const std::vector<int> right_view = std::vector<int>(arr.begin() + m, arr.end());

    const std::vector<int> left = sort_arr_cpp(left_view);
    const std::vector<int> right = sort_arr_cpp(right_view);

    std::vector<int> result;
    
    using vec_iter = std::vector<int>::const_iterator;
    vec_iter left_it = left.begin();
    vec_iter right_it = right.begin();

    for (size_t i = 0; i < size; i++) {
        if (left_it < left.end() && (right_it >= right.end() || *left_it < *right_it)) {
            result.push_back(*left_it++);
        }
        else {
            result.push_back(*right_it++);
        }
    }

    return result;
}

void sort_arr_c(int* arr, size_t size) {
    split_arr_c(arr, 0, size - 1);
}

void split_arr_ranges(std::vector<int>::iterator l, std::vector<int>::iterator r) {
    const size_t size = r - l;
    if (size < 2) return;

    const size_t m = size / 2;
    split_arr_ranges(l, l + m);
    split_arr_ranges(l + m, r);

    using vec_iter = std::vector<int>::iterator;

    vec_iter left = l;
    const vec_iter left_end = l + m;

    vec_iter right = left_end;
    const vec_iter right_end = r;

    std::vector<int> result;
    for (size_t i = 0; i < size; i++) {
        const bool use_left = left < left_end && (right >= right_end || *left < *right);
        result.push_back(use_left ? *left++ : *right++);
    }

    for (int n : result) *l++ = n;
}

void sort_arr_ranges(std::vector<int>& arr) {
    split_arr_ranges(arr.begin(), arr.end());
}
