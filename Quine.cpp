#include <cstdlib>
#include <cstring>
#include <iostream>

class Quine {
	private:
		char self[768] = "#include <cstdlib>\n#include <cstring>\n#include <iostream>\n#include <string>\n\nclass Quine {\n\tprivate:\n\t\tstd::string self;\n\tpublic:\n\t\tQuine() {\n\t\t\tself = \"?\";\n\t\t}\n\t\tvoid printSelf() {\n\t\t\tfor (int i=0; i<self.size(); i++) {\n\t\t\t\tif (self[i] == 63) {\n\t\t\t\t\tfor (int j=0; j<self.size(); j++) {\n\t\t\t\t\t\tswitch (self[j]) {\n\t\t\t\t\t\t\tcase '\\n': std::cout<<\"\\n\"; break;\n\t\t\t\t\t\t\tcase '\\t': std::cout<<\"\\t\"; break;\n\t\t\t\t\t\t\tcase '\\\': std::cout<<\"\\\\\"; break;\n\t\t\t\t\t\t\tdefault: std::cout<<self[i];\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t} else std::cout<<self[i];\n\t\t\t}\n\t\t}\n};\n\nint main() {\n\tQuine *q = new Quine();\n\tq->printSelf();\n\n\treturn 0;\n}\n";
	public:
		void printSelf() {
			for (int i=0; i<strlen(self); i++) {
				if (self[i] == 63) {
					for (int j=0; j<strlen(self); j++) {
						switch (self[j]) {
							case '\n': std::cout<<"\\n"; break;
							case '\t': std::cout<<"\\t"; break;
							case '\\': std::cout<<"\\\\"; break;
							default: std::cout<<self[i];
						}
					}
				} else std::cout<<self[i];
			}
		}
};

int main() {
	Quine *q = new Quine();
	q->printSelf();

	return 0;
}
