public class Quine {
	private String self = "public class Quine {\n\tprivate String self = \"?\";\n\n\tvoid printSelf() {\n\t\tfor (int i=0; i<self.length(); i++) {\n\t\t\tchar c = self.charAt(i);\n\t\t\tif (c==63) {\n\t\t\t\tswitch (c) {\n\t\t\t\t\tcase '\\n': System.out.print(\"\\n\");\n\t\t\t\t\tcase '\\t': System.out.print(\"\\t\");\n\t\t\t\t\tcase '\\\': System.out.print(\"\\\\\");\n\t\t\t\t\tdefault: System.out.print(c);\n\t\t\t\t}\n\t\t\t} else System.out.print(c);\n\t\t}\n\t}\n\t\n\tpublic static void main(String[] args) {\n\t\tQuine q = new Quine();\n\n\t\tq.printSelf();\n\t}\n}\n";

	void printSelf() {
		for (int i=0; i<self.length(); i++) {
			if (self.charAt(i)==63) {
				for (int j=0; j<self.length(); j++) {
					char c = self.charAt(j);
					switch (c) {
						case '\n': System.out.print("\\n"); break;
						case '\t': System.out.print("\\t"); break;
						case '\\': System.out.print("\\\\"); break;
						default: System.out.print(c);
					}
				}
			} else System.out.print(self.charAt(i));
		}
	}
	
	public static void main(String[] args) {
		Quine q = new Quine();

		q.printSelf();
	}
}
