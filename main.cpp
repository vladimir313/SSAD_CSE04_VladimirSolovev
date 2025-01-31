#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void sec_to_time(int sec) {
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = sec % 60;
    std::cout << h << ":" << m << ":" << s << std::endl;
}

void swap_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void remove_dup_array(int arr[], int& n) {
    std::unordered_set<int> seen;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[index++] = arr[i];
        }
    }
    n = index;
}

void remove_dup_vector(std::vector<int>& vec) {
    std::unordered_set<int> seen;
    auto end = std::remove_if(vec.begin(), vec.end(), [&seen](int const &i) {
        return !seen.insert(i).second;
    });
    vec.erase(end, vec.end());
}

int main() {
    int seconds = 124660;
    std::cout << "task 1 output: ";
    sec_to_time(seconds);

    int x = 5, y = 10;
    std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
    swap_pointer(&x, &y);
    std::cout << "after swap by pointer: x = " << x << ", y = " << y << std::endl;
    x = 5, y = 10;
    swap_ref(x, y);
    std::cout << "after swap by reference: x = " << x << ", y = " << y << std::endl;

    int arr[] = {1, 3, 5, 3, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    remove_dup_array(arr, n);
    std::cout << "task 3a output: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec = {1, 3, 5, 3, 3, 4, 1, 2};
    remove_dup_vector(vec);
    std::cout << "task 3b output: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}