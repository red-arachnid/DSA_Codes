// Given a vector<int> representing stock prices by day, find the maximum profit achievable 
// with one buy and one sell (buy before you sell), in a single pass — O(n) time, O(1) extra space. 
// Print the max profit and the (buy_day_index, sell_day_index) pair achieving it.

#include<bits/stdc++.h>
using namespace std;


int main() {
    vector<int> stocksPriceByDay = { 7, 10,  1,  5,  3,  6,  4 };
    
    int minPrice = stocksPriceByDay[0];
    int minPriceDay = 0;

    int maxProfit = 0;
    int bestSellDay = 0;
    int bestBuyDay = 0;

    for (int i = 1; i < stocksPriceByDay.size(); i++) {
        if (stocksPriceByDay[i] < minPrice) {
            minPrice = stocksPriceByDay[i];
            minPriceDay = i;
        }
        else if (stocksPriceByDay[i] - minPrice > maxProfit) {
            maxProfit = stocksPriceByDay[i] - minPrice;
            bestBuyDay = minPriceDay;
            bestSellDay = i;
        }
    }

    cout << "The Best day for the purchase is : " << bestBuyDay+1 << "\n";
    cout << "The Best day for sale is : " << bestSellDay+1 << "\n";
    cout << "Total profit for the trade is : " << maxProfit << "\n";

    return 0;
}