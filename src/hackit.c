#include "lex/lex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	char input[60];
	token_array toks;
	for(;;)
	{
		printf("%s ", ">>");
		fgets(input, 60, stdin);
		char* err = lex(&toks, input);
		if(err != NULL)
		{
			printf("%s\n", err);
		}
		else
		{
			for(int index = 0; index < toks.len; index++)
			{
				printf("%s\n", toks.tok_array[index].tok_str);
			}
		}
		free_tok_array(&toks);	
	}
	return 0;
}