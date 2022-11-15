// Counting whole summ. evens sums number and odd summs number.
// Runtime: O(n),
// Space: O(1)
int numOfSubarrays(int* arr, int arrSize){
    int result = 0;
    int curSumm = 0;
    int currOddSumms = 0;
    int currEvenSumm = 0;
    int modulo = 1000000000 + 7;

    for(int i = 0; i < arrSize; i++){
        curSumm += arr[i];
        if (curSumm % 2 == 0){
            currEvenSumm++;
            result = (result + currOddSumms) % modulo;
        }
        else {
            currOddSumms++;
            result = (result + 1 + currEvenSumm) % modulo;
        }
    }

    return result % modulo;
}
