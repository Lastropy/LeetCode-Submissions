class TextEditor:

    def __init__(self):
        self.s=""
        self.c=0
        

    def addText(self, text: str) -> None:
        self.s=self.s[:self.c]+text+self.s[self.c:]
        self.c+=len(text)
        

    def deleteText(self, k: int) -> int:
        k=min(len(self.s[:self.c]),k)
        self.s=self.s[:self.c-k]+self.s[self.c:]
        self.c-=k
        return k

    def cursorLeft(self, k: int) -> str:
        while k>0 and self.c>0:
            self.c-=1
            k-=1
        x=min(10,len(self.s[:self.c]))
        return self.s[self.c-x:self.c]

    def cursorRight(self, k: int) -> str:
        while k>0 and self.c<len(self.s):
            self.c+=1
            k-=1
        x=min(10,len(self.s[:self.c]))
        return self.s[self.c-x:self.c]
        


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)