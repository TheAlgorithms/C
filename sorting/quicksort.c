
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
*VARIÁVEIS*
l -> início do segmento
r -> final do segmento
p -> pivô
*/

/*
Aqui na HoarePartition nós quebramos o vetor em 2, de acordo
com o nosso pivô. Um segmento irá possuir os elementos menores do que o nosso pivô
e o outro irá possuir os elementos maiores do que o nosso pivô.
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
A função recebe como parâmetro o vetor, o começo dele (que normalmente é 0) e o tamanho 
total do vetor -1 (tam-1, ou seja, tamanho do vetor -1). Após receber isso, 
se o começo do vetor for menor que o final do mesmo, chamamos a função da 
partition de Hoare, que divide nosso
vetor em 2, e salvamos na variável s o que a função retorna, após isso, chamamos
o quickSort novamente para as duas metades do array, uma de l até s-1, e a outra de 
s+1 até r, vamos fazendo isso enquanto l < r recursivamente.
*/

int quickSort(int vet[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(vet, l, r); 
        quickSort(vet, l, s-1);
        quickSort(vet, s+1, r);
    }
}

int main(){

    return 0;
}
