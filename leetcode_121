/*Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min = INT_MAX;
        int n = prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] < min){
                min = prices[i];
            }
            if(maxProfit < (prices[i]-min)){
                maxProfit = prices[i]-min;
            }
        }
        return maxProfit;
    }
};
