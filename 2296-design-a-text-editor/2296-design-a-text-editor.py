class TextEditor:

    def __init__(self):
        self.left = []
        self.right = []

    def addText(self, text: str) -> None:
        self.left.append(text)

    def _cursor_left(self, k: int, add_position: Optional[bool] = None) -> str:
        n_chars = 0
        tokens = []
        while (remaining := k - n_chars) > 0 and self.left:
            s = self.left.pop()
            if len(s) > remaining:
                self.left.append(s[:-remaining])
                tokens.append(s[-remaining:])
                break
            else:
                tokens.append(s)
                n_chars += len(s)
        result = "".join(tokens[::-1])
        if result:
            if add_position is True:
                self.right.append(result[::-1])
            elif add_position is False:
                self.left.append(result)
        return result
    
    def deleteText(self, k: int) -> int:
        result = len(self._cursor_left(k))
        return result
        
    def cursorLeft(self, k: int) -> str:
        self._cursor_left(k, add_position=True)
        result = self._cursor_left(10, add_position=False)
        return result

    def cursorRight(self, k: int) -> str:
        self.left, self.right = self.right, self.left
        self._cursor_left(k, add_position=True)
        self.left, self.right = self.right, self.left
        result = self._cursor_left(10, add_position=False)
        return result