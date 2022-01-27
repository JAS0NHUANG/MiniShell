## First thing first  
[RTFM](notes/man_bash_note.md)  

## Quote validation
Check if there is any unclosed quotation before lexical analysis.

## Lexical analysis  
Take user input and store it into a linked-list as "tokens". Each "token" contains a "token value"(string) and a "token type"(int).  

## Envirenment variables  
Use hash table to store envirenment variables. (See the [hashtable - readme](https://github.com/JAS0NHUANG/MiniShell/tree/main/srcs/hashtable/readme.md) file about the usage of hashtable functions.)  
[Wikipedia - Hash table](https://en.wikipedia.org/wiki/Hash_table)  

## Substitution  

## Parsing  
We take the token list and send it to the parser to create an binary tree.  
The tree will have all the pipes as forking point and have left and right as commands.  
When there is more then 1 pipe, the first pipe will be connected to the second pipe's left side.
The second pipe will be connected to the third pipe's left side. And so on...  
If there is redirection token, we will create a linked-list to store all redirection types and it's filename inside.  
All the "WORD" token directly after the redirection token will be the file name, the other WORDs after the first WORD will all be put into the command's argument list.  
(ex: `echo > a hello > b` becomes: `["echo", "hello"]/(REDIR_OUT)"a"->(REDIR_OUT)"b"` and `> a echo hello > b` will produce the same element as above.  

So the command: `echo hello > filename | cat filename | grep a | wc > outfile1 -l > outfile2 ` will produce a tree like:
```
                            PIPE
                           /    \
                          /      CMD
                       PIPE      ["wc", "-l"]
                       /  \      (REDIR_OUT)"outfile1"->(REDIR_OUT)"outfile2"
                      /    CMD
                     PIPE  ["grep", "a"]
                    /    \
                  CMD     CMD
    ["echo", "hello"]     ["cat" "filename"]
  (REDIR_OUT)"filename"
```


## Builtins
- export
	- With no argument: in the MAN document of export. It mentions "When no arguments are given, the results are unspecified.". But we still print out the environment variable list as bash does(with some minor difference).  
	- If the argument(s) are given. We will check the validity of the argument: "key" started with only alphabets or `_`). Get the "value". And store the "key/value" pair into the environment variable hashtable.  

- env  
	Take no argument or option. It simply prints out the environment vairable list as "key=value".  

- unset  
	Check the validity of the arguments then remove the "key/value" pair from the environment variable hashtable if found.  
- cd  
- echo  
	Careful about the option "-nnnn"  
- pwd
- exit  

## Execution

	- Pipeline

	- Redirection

## Resources:  
  - [minishell - 42 Docs](https://harm-smits.github.io/42docs/projects/minishell)
  - [Introduction to Systems Programming - Chapter 5. Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

## Others' implementation:  
  - [Swoorup / mysh](https://github.com/Swoorup/mysh)  
  - [fpetras / minishell](https://github.com/fpetras/minishell)  

## Videos:  
  - [Projet Epitech minishell1 - Valentin BONNET](https://www.youtube.com/watch?v=h4D85AAz5GI)
  - [1337-42-minishell
](https://www.youtube.com/watch?v=xUfdQHEYh1w)
  - [Conférences 42sh 2019 - Architecture d'un shell](https://www.youtube.com/watch?v=oIFRiwFRSRY)
  - [Conférences Redirection et Pipe 42SH - 2019](https://www.youtube.com/watch?v=ceNaZzEoUhk)
  - [Minishell - playlist](https://www.youtube.com/playlist?list=PL7_TuD9ZDMhg5uLHLyd8em13XBKfjzCzR)
