int maxcmp(int a, int b) {
	return (a >= b)? a : b;
}

/* max subarray problem by using Kadane's Algorithm
 */
int maxProfit(int* prices, int pricesSize){
	/* maxCur: current maximum 
	 * maxSoFar: found maximum for subarray so far
	 */
	int maxCur = 0, maxSoFar = 0;
	for(int i = 1; i < pricesSize; i++) {
		maxCur = maxcmp(0, maxCur + prices[i] - prices[i - 1]);
		maxSoFar = maxcmp(maxSoFar, maxCur);
	}
	return maxSoFar;
}
