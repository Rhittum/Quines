#include <stdio.h>
#include <string.h>

int main() {
	char self[512] = "#include <stdio.h>\n#include <string.h>\n\nint main() {\n\tchar self[256] = \"?\";\n\n\tfor (int i=0; i<strlen(self); i++) {\n\t\tif (self[i] == 63) {\n\t\t\tswitch (self[i]) {\n\t\t\t\tcase '\\n': printf(\"\\n\"); break;\n\t\t\t\tcase '\\t': printf(\"\\t\"); break;\n\t\t\t\tcase '\\\': printf(\"\\\\\"); break;\n\t\t\t\tdefault: printf(\"%c\", self[i]);\n\t\t\t}\n\t\t}\n\t\tprintf(\"%c\", self[i]);\n\t}\n\treturn 0;\n}\n";

	for (int i=0; i<strlen(self); i++) {
		if (self[i] == 63) {
			for (int j=0; j<strlen(self); j++) {
				switch (self[j]) {
					case '\n': printf("\\n"); break;
					case '\t': printf("\\t"); break;
					case '\\': printf("\\\\"); break;
					default: printf("%c", self[j]);
				}
			}
		} else printf("%c", self[i]);
	}
	return 0;
}
