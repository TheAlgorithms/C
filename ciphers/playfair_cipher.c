//Code by Rishabh Patel

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MX 5

int choice;

void playfair(char ch1, char ch2, char key[MX][MX]) {
    int i, j, w, x, y, z;
    for (i = 0; i < MX; i++) {
	for (j = 0; j < MX; j++) {
	    if (ch1 == key[i][j]) {
		w = i;
		x = j;
	    } else if (ch2 == key[i][j]) {
		y = i;
		z = j;
	    }
	}
    }
    if (w == y) {
		if(choice==1){
			x = (x + 1) % 5;
			z = (z + 1) % 5;
		}
		else{
			x = ((x - 1) % 5+5)%5;
			z = ((z - 1) % 5+5)%5;
		}
	printf("%c%c", key[w][x], key[y][z]);
    } else if (x == z) {
		if(choice==1){
			w = (w + 1) % 5;
			y = (y + 1) % 5;
		}
		else{
			w = ((w - 1) % 5+5)%5;
			y = ((y - 1) % 5+5)%5;
		}
	printf("%c%c", key[w][x], key[y][z]);
    }
	else {
	printf("%c%c", key[w][z], key[y][x]);
    }
}
void removeDuplicates(char str[]){
    int hash[256]        =  {0};
    int currentIndex     = 0;
    int lastUniqueIndex  = 0;

    while(*(str+currentIndex)){
	char temp = *(str+currentIndex);
	if(0 == hash[temp]){
	    hash[temp] = 1;
	    *(str+lastUniqueIndex) = temp;
	    lastUniqueIndex++;
	}
	currentIndex++;
    }
    *(str+lastUniqueIndex) = '\0';

}
void main() {
    int i, j, k = 0, l, m = 0, n;
    char key[MX][MX], keyminus[25], keystr[10], str[25] = {
	0
    };

	char alpa[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	clrscr();
	printf("\t\t\t\tPlayFair Cipher");
	printf("\n1.Encryption\n2.Decryption\n\nChoice(1 or 2):");
	scanf("%d",&choice);
	if(choice!=1 && choice!=2){ printf("Invalid Choice"); return;}
	fflush(stdin);
	printf("\nEnter key:");
	gets(keystr);
	printf("Enter the text:");
	gets(str);
	removeDuplicates(keystr);
	n = strlen(keystr);

	//convert the characters to uppertext
	for (i = 0; i < n; i++) {
		if (keystr[i] == 'j') keystr[i] = 'i';
		else if (keystr[i] == 'J') keystr[i] = 'I';
			keystr[i] = toupper(keystr[i]);
	}

	//convert all the characters of plaintext to uppertext
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'j') str[i] = 'i';
		else if (str[i] == 'J') str[i] = 'I';
		str[i] = toupper(str[i]);
	}

	// store all characters except key
	j = 0;
	for (i = 0; i < 26; i++) {
		for (k = 0; k < n; k++) {
			if (keystr[k] == alpa[i]) break;
			else if (alpa[i] == 'J') break;
		}
		if (k == n) {
			keyminus[j] = alpa[i];
			j++;
		}
	}

	//construct key keymatrix
	k = 0;
	for (i = 0; i < MX; i++) {
		for (j = 0; j < MX; j++) {
			if (k < n) {
				key[i][j] = keystr[k];
				k++;
			} else {
				key[i][j] = keyminus[m];
				m++;
			}
			printf("%c ", key[i][j]);
		}
		printf("\n");
	}

	// construct diagram and convert to cipher text
	printf("\nEntered text :%s\nOutput Text :", str);
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'J') str[i] = 'I';
			if (str[i + 1] == '\0') playfair(str[i], 'X', key);
			else {
				if (str[i + 1] == 'J') str[i + 1] = 'I';
					if (str[i] == str[i + 1]) playfair(str[i], 'X', key);
					else {
						playfair(str[i], str[i + 1], key);
						i++;
					}
			     }
	}
	getch();
}
