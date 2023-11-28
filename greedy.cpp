#include <iostream>
#include <vector>
#include <algorithm>

int greedyCoinChange(std::vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end(), std::greater<int>());
    int count = 0;
    for (int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }
    return amount == 0 ? count : -1;
}

int main() {
    std::vector<int> coins = {1, 2, 5, 10, 20, 50};
    int amount = 93;
    std::cout << "Minimum coins required: " << greedyCoinChange(coins, amount);
    return 0;
}
