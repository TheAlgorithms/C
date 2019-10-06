int maxProfit(int* prices, int pricesSize){
	/* If there is only only one day, profit cannot be made
	 */
	if(pricesSize <= 1) {
        return 0;
    }
    int min_element = prices[0];
    int max_difference = prices[1] - min_element;
    for(int i = 0; i < pricesSize; i++) {
		/* whenever maximum profit can be made, we sell the stock.
           so we change the maximum difference
		 */
        if(prices[i] - min_element > max_difference) {
            max_difference = prices[i] - min_element;
		}
		/* if a cheaper stock is available, we make that the minimum element
		 */
        if(min_element > prices[i]) {
            min_element = prices[i];
		}
    }
	/* return 0 if max_difference is less than zero, incase there is no way of making profits
	 */
    return (max_difference < 0)? 0 : max_difference;
}


