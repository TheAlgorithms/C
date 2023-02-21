// Using hashtable.
// Runtime: O(n + len(trust))
// Space: O(n)
int findJudge(int n, int** trust, int trustSize, int* trustColSize){
    int* personsToTrust = calloc(n + 1, sizeof(int));
    int* personsFromTrust = calloc(n + 1, sizeof(int));

    for(int i = 0; i < trustSize; i++){
        int* currentTrust = trust[i];
        personsToTrust[currentTrust[1]] += 1;
        personsFromTrust[currentTrust[0]] += 1;
    }

    int potentialJudjeNumber = -1;
    for(int i = 1; i < n + 1; i++){
        if (personsToTrust[i] == n - 1 && personsFromTrust[i] == 0){
            if (potentialJudjeNumber > -1){
                return -1;
            }

            potentialJudjeNumber = i;
        }
    }

    free(personsToTrust);
    free(personsFromTrust);

    return potentialJudjeNumber;
}
