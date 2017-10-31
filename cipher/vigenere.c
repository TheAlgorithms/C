#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define CRIPT	1
#define DECRIPT	2

void show_help();	// Mensagem de ajuda
void show_error();	// Mensagem de erro

unsigned char is_not_char(unsigned char c);

extern unsigned char *vigenere(const char *key, unsigned char action, const char *value){
	int len = strlen(value);
	int klen = strlen(key);
	int x,y=0;

	unsigned char *swap;
	unsigned char *skey;
	skey = (unsigned char*) malloc(klen);
	strcpy(skey,key);
	if(action == CRIPT){ /*Verifica se vai criptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap, value);
		for(x=0; x<len; x++){
			if(is_not_char(swap[x])){
				skey[y] = toupper(skey[y]);
				swap[x] = toupper(swap[x]);	// Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "65" para "0"
				 */
				swap[x] -= 65;
				skey[y] -= 65;
				if(swap[x] < 0 || swap[x] > 26) // se o valor nao estiver entre 0 e 26, nao e' feito a criptografia
					return NULL;
				swap[x] = ((int)swap[x] + (skey[y%klen])) % 26;
				swap[x] += 65;
				y++;
			}
		}
	}
	else if(action == DECRIPT){ /*Verifica se vai descriptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap,value);
		for(x=0; x<len; x++){
			if(is_not_char(swap[x])){
				skey[y] = toupper(skey[y]);
				swap[x] = toupper(swap[x]); // Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "65" para "0"
				 */
				swap[x] -= 65;
				skey[y] -= 65;
				if(swap[x] < 0 || swap[x] > 26) // se o valor nao estiver entre 0 e 26, nao e' feito a criptografia
					return NULL;
				signed int c = ((signed int) swap[x] - (skey[y%klen])%26);
				c = (c < 0 ? 26+c : c);
				swap[x] = (unsigned char) c;
				swap[x] += 65;
				y++;
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

int main(int argc, char **argv){
	int x,y;
	unsigned char cri = 1;
	char *value;
	char *swap;
	unsigned char *key;
	/*
	 * O for percorre os parametros que iniciem com o caracter "-"
	 * para recolher as configurações
	 */
	for(x=1;x<argc;x++){
		if(argv[x][0] == '-'){
			swap = argv[x];
			for(y=1;y<strlen(swap);y++)
				if(swap[y] == 'k')
					//sscanf(argv[++x],"%i",&key);	// Coleta a chave da criptografia
					key = argv[++x];
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
	 * Executa a ação de criptografia
	 */
	char *_swap = malloc(strlen(value));
	x = 0;
	y=0;
	while(x<strlen(value)){
		if(value[y] != ' '){
			_swap[x] = value[y];
			x++;
		}
		y++;
	}

	if(cri)
		swap = vigenere(key, CRIPT, _swap);
	else
		swap = vigenere(key, DECRIPT, _swap);

	if(!swap)
		show_error();

	for(x=0; x<strlen(swap); x++){
		if(swap[x] != ' '){
			printf("%c",swap[x]);
			//if (x != strlen(swap)-1)
			/*if((x)%(strlen(key))){
				printf("");
			}*/
		}
	}
	printf("\n");
	
	//printf("%s",swap);// imprime na tela

	return 0;
}

void show_help(){
	puts("Use chars between A-z and a-z.\n");
	puts("Usage: cesar -ksc <number> <string>");
	puts("Usage: cesar -ksd <number> <string>");
	puts("");
	puts("	-k <str>	Key to cript or decript");
	puts("	-s <str>	String");
	puts("	-c		Cript string");
	puts("	-d		Decript string");
	puts("	-h		Show Help\n");
}
void show_error(){
	puts("Can net cript this string.\nUse -h to show help.");
}
