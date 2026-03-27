#include <stdio.h>
#include <stdlib.h>

char peek(FILE* fptr) {
	long cur_pos = ftell(fptr);
	char c = fgetc(fptr);
	fseek(fptr, cur_pos, SEEK_SET);

	return c;
}
int isOperator(char c) {
	return (c=='+' || c=='-' || c=='=' || c=='*' || c=='/');
}
void advance(FILE* fptr) {
	fseek(fptr, 1, SEEK_CUR);
}

char** get_tokens(FILE* fptr) {
	char** all_tokens = malloc(2);
	char* token;

	int c;
	int i=0;
	while ((c = fgetc(fptr))!=EOF) {
		if (c=='+' || c=='-' || c=='=' || c=='*' || c=='/') {
			token = (char*)malloc(sizeof(char));
			if (isOperator(peek(fptr)) && isOperator(peek(fptr))!=EOF) {
				token = realloc(token, 2*sizeof(char));
				token[0] = c;
				token[1] = fgetc(fptr);
			} else token[0] = c;
		} else if (c=='\n' || c=='\t') continue;
		i++;
		printf("token: %s\n", token);
		//all_tokens = realloc(all_tokens, i);
		//all_tokens[i] = token;
	}
	return all_tokens;
}

int main(int argc, char* argv[]) {
	FILE* fptr = fopen(argv[1], "r");

	char** tokens = get_tokens(fptr);
	printf("%s\n",tokens[0]);
	int i=0;

	return 0;
}
