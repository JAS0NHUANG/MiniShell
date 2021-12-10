- execve will set the "errono" and the ERRORS STRING.

- What I'm planning to do in the lexer:
	- Using a linked-list to store all lexems.
	- Each node will conatain: 1. The actual lexem. 2. It's type. 3. Pointer to the next node.
	- Need to take in account the "word definitions"(see [man_bash_note](./man_bash_note.md)).


