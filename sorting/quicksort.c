/*
I'm using the HoarePartition in my quickSort code.
*/

int HoarePartition(int vet[], int l, int r){
    int i = l, j = r+1, p = vet[l], temp;
    do{ 
        do{
            i = i+1;
        }while((vet[i] < p) && (i < r));
        do{
            j = j-1;
        }while(vet[j] > p);
        temp = vet[j];
        vet[j] = vet[i];
        vet[i] = temp;
    }while(i <j);
    temp = vet[j];
    vet[j] = vet[i];
    vet[i] = temp;
    temp = vet[j];
    vet[j] = vet[l];
    vet[l] = temp;
    return j;
}

/*
This is the quickSort function.
*/

void quickSort(int vet[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(vet, l, r); 
        quickSort(vet, l, s-1);
        quickSort(vet, s+1, r);
    }
}
