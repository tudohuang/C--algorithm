#include <iostream>
#include <vector>

int fib(int n) {
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 9;
    std::cout << "Fibonacci number is " << fib(n);
    return 0;
}
