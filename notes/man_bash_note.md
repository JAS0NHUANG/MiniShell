[gnu.org - Bash Reference Manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)

[1.2 What is a shell?](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#What-is-a-shell_003f)  
	- A macro processor that executes commands.
	- Provide some built--in commands(builtins)implementing functionality impossible or inconvenient to obtain via separate utilities.
	- Provides variables, flow control constructs, quoting, and functions.
	- Specifically for interactive use rather than to augment the programming language. Interactive features such as job control, command line editing, command history and aliases.

[2. Word Definitions](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Definitions)
	- POSIX
	- blank: space OR tab character.
	- builtin
	- control operator: A TOKEN that performs a control function. (`newline`, `||`, `&&`, `&`, `;`, `;;`, `;&`, `;;&`, `|`, `|&`, `(`, `)`). We only need to implement `|` I think?.
	- exit status
	- field ?
	- job
	- job control: stop(suspend) and restart(resume)
	- metacharacter: A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
	- operator: See Redirections
	- reserved word: 
	- signal: 
	- token: 
	- word: A sequence of characters treated as a unit by the shell. Words may not include unquoted metacharacters.  


