#include <stdio.h>

int main() {
	FILE* fptr = fopen("test.c", "r");

	int c;
	while ((c=fgetc(fptr)) != EOF) {
		printf("%c", c);
	}
	return 0;
}
