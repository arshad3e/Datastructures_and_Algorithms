#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_Profit(vector<int>& prices){
    int minPrice = INT_MAX;
    int maxProfit=0;

    for(int price : prices){

        minPrice = min(minPrice,price);

        maxProfit = max(maxProfit, price-minPrice);
    }
    return maxProfit;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    cout << "maxProfit:" << max_Profit(prices);

    return 0;

}

/* Add description

How It Works
Track the minimum price: Keep updating the minimum price while iterating.
Calculate profit: Compute the profit if the stock is sold at the current price.
Update the maximum profit: Compare and store the best profit seen so far.
Example Walkthrough
Given prices = [7, 1, 5, 3, 6, 4]:

Day 1: Price = 7 → minPrice = 7, maxProfit = 0
Day 2: Price = 1 → minPrice = 1
Day 3: Price = 5 → Profit = 5 - 1 = 4, maxProfit = 4
Day 4: Price = 3 → Profit = 3 - 1 = 2, no update
Day 5: Price = 6 → Profit = 6 - 1 = 5, maxProfit = 5
Day 6: Price = 4 → Profit = 4 - 1 = 3, no update
Maximum Profit = 5 */
