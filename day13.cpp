/*  This code solves the Best Time to Buy and Sell Stock (Single Transaction) problem in O(N) time.


Buy at the lowest price.
Sell later at the highest possible price.
Return the maximum profit.

*/

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices, int N) {
    int profit = 0;
    int cp = prices[0];

    for(int i = 1; i < N; i++) {
        profit = max(profit, prices[i] - cp);
        cp = min(cp, prices[i]);
    }

    return profit;
}

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);

    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    cout << maximumProfit(prices, N);

    return 0;
}