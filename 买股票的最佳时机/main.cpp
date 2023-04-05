//
//  main.cpp
//  买股票的最佳时机
//
//  Created by dry on 2023/4/4.
//

#include <iostream>
#include <vector>
using namespace::std;
// 122.买卖股票的最佳时机II 可以买卖多次
int maxProfit(vector<int>& prices) {
    
    size_t len = prices.size();

    vector<vector<int>> dp(len, vector<int>(2, 0));

    dp[0][0] -= prices[0];  // dp[i][0] 表⽰第i天持有股票所得现⾦
    
    dp[0][1] = 0;           // dp[i][1] 表⽰第i天不持有股票所得最多现⾦

    for (int i = 1; i < len; i++) {
        // dp[i][0] = max(dp[i - 1][0],           - prices[i]);    // 121. 买卖股票的最佳时机 只买卖一次
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);    // 注意这⾥是和121. 买卖股票的最佳时机唯⼀不同的地⽅。
        
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

    }
    
    return dp[len - 1][1];

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
