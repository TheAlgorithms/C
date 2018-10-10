#include <stdio.h>

 int main(void)
{   
    //Storing Name in array
	char name[80];
	int i ,count = 0;
	
	printf("Enter the name\t");
	scanf("%s" ,& name);
	
	// loop will terminate after space
	for(i = 0; name[i]!='\0'; i++)
	{
	   count++;
    }
	
	printf("NUMBER OF CHARACTERS= %d ", count);
	return 0;
}
