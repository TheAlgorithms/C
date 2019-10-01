#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
*PARÂMETROS DA FUNÇÃO**
-O primeiro parâmetro é o meu vetor (ordenado)
-O segundo parâmetro é o valor procurado
-O terceiro parâmetro é o tamanho do meu vetor
*VARIÁVEIS DA FUNÇÃO*
-l -> começo do segmento
-r -> final do segmento
-m -> meio do segmento ((l+r)/2);
-k -> valor procurado
-n -> tamanho do vetor
*EXPLICAÇÃO DO ALGORITMO*
O algoritmo basicamente compara o valor procurado com o elemento que esta
localizado no meio do array, se forem iguais, paramos e retornamos o índice em que está o elemento, caso não sejam iguais ele verifica
se o valor procurado é menor do que o elemento que esta localizado no meio do array, caso seja, o final do segmento é
atualizado e se torna m-1, porque já que o elemento procurado é menor do que o valor que está no meio do array, podemos assumir
que ele vai estar antes desse elemento, então atualizamos o final do segmento. Caso o valor procurado seja maior que o elemento localizado no meio
do array, nós atualizamos o começo do nosso segmento, pois sabemos que o nosso valor procurado é maior do que o elemento 
que está no meio do array, então o começo do nosso segmento se torna m+1, e assim
continuamos até que l > r ou até encontramos o valor e retornamos o índice em que o mesmo se encontra. Caso l > r e não tenhamos achado o valor, retornamos -1!
Podemos assumir tudo o que falei acima porque o array vai estar previamente ordenado.
*/

int binarySearch(int vet[], int k, int n){ 
    int l = 0, r = n-1, m;
    while(l<=r){
        m = (l+r)/2;
        if(k == vet[m]){
            return m;
        }else if(k < vet[m]){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return -1;
}

int main(){
    
    return 0;
}
