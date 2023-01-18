int coundDevices(char* bankRow){
    int result = 0;
    int bankRowSize = strlen(bankRow);
    for(int i = 0; i < bankRowSize; i++){
        if (bankRow[i] == '1'){
            result++;
        }
    }

    return result;
}

// Counting devices in each row
// Runtime: O(n*m), n-number of bank rows, m - max size of row.
// Space: O(1)
int numberOfBeams(char ** bank, int bankSize){
    int prevRowDevices = 0;
    int result = 0;
    for(int i = 0; i < bankSize; i++){
        int devices = coundDevices(bank[i]);
        if (devices == 0){
            continue;
        }

        result += devices * prevRowDevices;
        prevRowDevices = devices;
    }

    return result;
}
