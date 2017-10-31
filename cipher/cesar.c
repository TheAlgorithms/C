#include <malloc.h>
#include <string.h>
#include <stdio.h>

#define CRIPT	1
#define DECRIPT	2

enum{
	SHORT = 2,
	MEDDLE = 8,
	LONG = 16
}KEYS;

/*
 * Este método usa a criptografia de cesar para criptografar menssagens
 * Parametros:
 * 	chave de valor inteiro
 * 	tipo de ação do método "criptografar" ou "descriptografar"
 * 	texto a ser processado
 * O retorno deverá ser o texto criptografado ou descriptografado
 */

unsigned char is_not_char(unsigned char c); // Faz a verificação dos caracteres

extern unsigned char *cesar(unsigned int key, unsigned char action, const char *value){
	int len = strlen(value);
	unsigned char *swap;

	if(action == CRIPT){ /*Verifica se vai criptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap, value);
		while(len--){
			if(is_not_char(swap[len])){
				swap[len] = toupper(swap[len]);	// Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "48" para "0"
				 */
				swap[len] -= 48;
				if(swap[len] < 0 || swap[len] > 42) // se o valor nao estiver entre 0 e 42, nao e' feito a criptografia
					return NULL;
				if(swap[len] > 9) // Reduz o intervalo entre 9 e A
					swap[len] -= 7;
				swap[len] = 	((swap[len] + key) % 36) > 9 ?	/* Verifica se caracter > 9
										// se sim, incrementa 7 no resultado
										// para transformar [: > a, ; > b, ...]
										*/
						((swap[len] + key) % 36) + 7 : (swap[len] + key) % 36;
				swap[len] += 48;	// Retorna valores originais da string
			}
		}
	}
	else if(action == DECRIPT){ /*Verifica se vai descriptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap,value);
		while(len--){
			if(is_not_char(swap[len])){
				swap[len] = toupper(swap[len]); // Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "65" para "0"
				 */
				swap[len] -= 48;
				if(swap[len] < 0 || swap[len] > 42) // se o valor nao estiver entre 0 e 26, nao e' feito a criptografia
					return NULL;
				if(swap[len] > 9) // Reduz o intervalo entre 9 e A
					swap[len] -= 7;
				signed int x =	((signed int) swap[len] - key); // Subtrai a chave aceitando numeros negativos
				x = (x < 0 ? 36+x : x);				// subtrai do valor total
				swap[len] = (unsigned char) (x > 9 ? (x + 7) : x); // Incrementa 7 no intervalo de 9 entre A
				swap[len] += 48;
			}
		}
	}

	return swap;
}

unsigned char is_not_char(unsigned char c){
	if(c <= 32 || (c > 32 && c < 48) || (c > 57 && c < 65) || c > 122)
		return 0;
	return 1;
}

void show_help();	// Mensagem de ajuda
void show_error();	// Mensagem de erro

int main(int argc, char **argv){
	int x,y;
	int key;
	unsigned char cri = 1;
	char *value;
	char *swap;
	/*
	 * O for percorre os parametros que iniciem com o caracter "-"
	 * para recolher as configurações
	 */
	for(x=1;x<argc;x++){
		if(argv[x][0] == '-'){
			swap = argv[x];
			for(y=1;y<strlen(swap);y++)
				if(swap[y] == 'k')
					sscanf(argv[++x],"%i",&key);	// Coleta a chave da criptografia
				else if(swap[y] == 's')
					value = argv[++x];		// Coleta o texto da criptografia
				else if(swap[y] == 'c')
					cri = 1;			// Define se vai criptografas ou descriptografar o texto
				else if(swap[y] == 'd')
					cri = 0;
				else if(swap[y] == 'h'){		// Chame a documentação
					show_help();
					return 0;
				}
				else{
					show_error();
					return 1;
				}
		}
		else{
			show_error();
			return 1;
		}
	}

	if(cri > 1){
		show_error();
		return 1;
	}

	/*
	 * passa as chaves negativas para positivas
	 */
	key = key < 0 ? key*(-1) : key;
	/*
	 * Executa a ação de criptografia
	 */
	if(cri)
		swap = cesar(key, CRIPT, value);
	else
		swap = cesar(key, DECRIPT, value);

	if(!swap)
		show_error();
	printf("%s",swap);// imprime na tela

	return 0;
}

void show_help(){
	puts("Use chars between A-z and a-z.\n");
	puts("Usage: cesar -ksc <number> <string>");
	puts("Usage: cesar -ksd <number> <string>");
	puts("");
	puts("	-k n		Key to cript or decript");
	puts("	-s <str>	String");
	puts("	-c		Cript string");
	puts("	-d		Decript string");
	puts("	-h		Show Help\n");
}
void show_error(){
	puts("Can net cript this string.\nUse -h to show help.");
}
