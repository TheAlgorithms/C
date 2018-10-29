#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_kmp(char*, char*, int);
int knuth_moris_pratt(char*, char*);

void main()
{
	puts("Knuth-Moris-Pratt Algorithm\n");
    
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	check_kmp(alphabet, "mno", 12);
	check_kmp(alphabet, "abc", 0);
	check_kmp(alphabet, "ijkq", -1);
	char* text = "aaabbbcccdddefghijklmnopqrstuvwxyz";
	check_kmp(text, "bbccc", 4);
}

void check_kmp(char* text, char* search_string, int expect)
{
	printf("Find: '%s' in:\n%s\n", search_string, text);

	int result = knuth_moris_pratt(text, search_string);
	if (result != -1)
	{
		int loop = 0;
		for (; loop < result; loop++)
			printf("-");

		for (; loop < result + strlen(search_string); loop++)
			printf("%c", text[loop]);

		for (; loop < strlen(text); loop++)
			printf("-");

		printf("\n");
	}
	else
		puts("Search string not found.");
	
	if (result == expect)
		puts("\nExpected result found. Test is valid.\n");
}

int knuth_moris_pratt(char* text, char* search_string)
{
	int text_length = strlen(text);
	int search_string_length = strlen(search_string);
	
	char* pexamine_array = malloc(search_string_length);
	if (pexamine_array == NULL)
		return -1;
	memset(pexamine_array, 0, search_string_length);
	char* pexamine = pexamine_array;
	
	int look_up = 0, iterator = 1;
	while (iterator < search_string_length)
	{
		if (search_string[look_up] == search_string[iterator])
			look_up++;
		else if (look_up > 0)
		{
			look_up = (int)(*(pexamine_array + look_up - 1));
			continue;
		}
		iterator++;
		pexamine++;
		*pexamine = (char)look_up;
	}

	iterator = 0;
	int sampler = 0;
	while (iterator < text_length)
	{
		if (text[iterator] == search_string[sampler])
		{
			if (sampler == search_string_length - 1)
			{
				free(pexamine_array);
				return iterator - search_string_length + 1;
			}
			sampler++;
		}
		else if (sampler > 0)
		{
			sampler = pexamine_array[sampler - 1];
			continue;
		}
		iterator++;
	}

	free(pexamine_array);
	return -1;
}