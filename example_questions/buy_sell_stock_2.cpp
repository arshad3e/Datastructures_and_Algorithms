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
