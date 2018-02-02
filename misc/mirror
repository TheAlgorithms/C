#include <stdio.h>
#include <string.h>  // we include the library string.h to the use of string 

void saisie (char *cpointeur); // Prototypes of the three functions used in the program
int compte (char *s);
char* miroir (char * s);

int main  (int argc , char *argv[])
{
char chaine[20];
saisie(chaine); 
printf("miroir est %s",miroir(chaine)); 	
	
}
// this function is used to put a string 
void saisie (char *cpointeur)               
{
	printf("saisir une chaine\n");
	scanf("%s",cpointeur); 
}
/* the function miroir (in french ) it means "mirror" , the major idea is to permute the first caractere with the last using an auxilary 
variable (aux) the the 2nd character with the penultimate one and so on .
we made a call to the function (compte) which counts the length of the string . As you can see clearly , I substruct 1 from the equation 
k = compte(s)-1 ; to get rid of the EOF caractere which is '\0' because it is not a caractere from the string typed */
char* miroir (char *s)
{
int i ;
char aux ; 
int k ; 
k = compte(s)-1 ; 
i = 0 ; 
while(i<=k)
{
aux = s[i]; 
s[i]=s[k]; 
s[k]=aux ;
k-- ;
i++ ;
}

return s  ; 	
}

// compte plays the role of strlen so we can change it by an strlen function if you want that 
int compte (char *s) 
{
	char *p ;
	int k ; 
	p=s ; 
	k=0 ; 
	while(*p!='\0')
	{
		p++ ; 
		k++ ; 	
	}
	return k ; 
}
