self = "self = \"?\"\n\ndef printSelf():\n    for i in range(0, self.__len__()):\n        if self[i]==chr(63):\n            for j in range(0, self.__len__()):\n                if self[j]=='\\n':\n                    print(\"\\n\", end='')\n                elif self[j]=='\\t':\n                    print(\"\\t\", end='')\n                elif self[j]=='\\\':\n                    print(\"\\\\\", end='')\n                else:\n                    print(self[j], end='')\n        else:\n            print(self[i], end='')\n\n\nprintSelf()\n"

def printSelf():
    for i in range(0, self.__len__()):
        if self[i]==chr(63):
            for j in range(0, self.__len__()):
                if self[j]=='\n':
                    print("\\n", end='')
                elif self[j]=='\t':
                    print("\\t", end='')
                elif self[j]=='\\':
                    print("\\\\", end='')
                else:
                    print(self[j], end='')
        else:
            print(self[i], end='')


printSelf()
