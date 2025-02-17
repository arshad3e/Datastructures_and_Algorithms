    int maxProfit(vector<int>& prices) {

        int min_value = prices[0];
        int profit =0;

        for(int price : prices){

            min_value=min(min_value, price);

            if(min_value < price){
                profit = profit + (price-min_value);
                min_value = price;
            }

        }
        return profit;
        
    }
};

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1]; // Add profit from each increase
        }
    }

    return profit;
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices1) << endl; // Output: 7

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit: " << maxProfit(prices2) << endl; // Output: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Max Profit: " << maxProfit(prices3) << endl; // Output: 0

    return 0;
}

/*Explanation
Example 1: prices = [7,1,5,3,6,4]
Buy at 1, sell at 5 → Profit 4
Buy at 3, sell at 6 → Profit 3
Total Profit = 4 + 3 = 7
Example 2: prices = [1,2,3,4,5]
Buy at 1, sell at 2 → Profit 1
Buy at 2, sell at 3 → Profit 1
Buy at 3, sell at 4 → Profit 1
Buy at 4, sell at 5 → Profit 1
Total Profit = → Profit = 0*/
