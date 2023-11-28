#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) 
            return m;
        if (arr[m] < x) 
            l = m + 1;
        else 
            r = m - 1;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = binarySearch(arr, x);
    if (result != -1)
        std::cout << "Element is found at index " << result;
    else
        std::cout << "Element is not present in array";
    return 0;
}
