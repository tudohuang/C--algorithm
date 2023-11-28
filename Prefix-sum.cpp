#include <iostream>
#include <vector>

std::vector<int> prefixSum(const std::vector<int>& nums) {
    std::vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    return prefix;
}

int main() {
    std::vector<int> nums = {10, 20, 10, 5, 15};
    std::vector<int> prefix = prefixSum(nums);
    for (int sum : prefix) {
        std::cout << sum << " ";
    }
    return 0;
}
