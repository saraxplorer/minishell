
### READme In progress


***main will basically get divided into 2 parts- parsing and execution. In main the following functions are to be used***\

**1. readline**
```
char *readline(const char *prompt)
```
**Purpose:** It reads a line of text from the user input, typically from the terminal and returns a pointer to a dynamically allocated string containing that line. It does not modify or transform the input but simply returns it as-is.\
**Parameters:**\
prompt: A string that is displayed to the user before input is taken.\
**Returns:**\
-A pointer to the line read from input, which is allocated dynamically (you need to free it).\
-NULL if an error occurs or EOF is reached.\
**Basic use of readline**
compile with flag -lreadline
``` c
#include <readline/readline.h>

int main(int argc, char **argv, char **envp)
{
	char *input;
	input = readline("minishell:");
	if (input != NULL)
	{
		//process it here
		free(input);
	}
}
```
This will be used to make a prompt, waiting for commands.\
For multiple lines, it needs to be inside an infinite loop.

**2. addhistory**
```
void add_history(const char *line)
```
``` c
#include <readline/readline.h>
#include <stdlib.h>
#include <readline/history.h>


int main(int argc, char **argv, char **envp)
{
	char *input;
	
		while (1)
		{
			input = readline("minishell:");
			if (input != NULL)
			{
				add_history(input);
				free(input);
			}	
		}
}
```
Now, multiple inputs can be given and using up/down arrow, previous commands can be seen. Library header readline/history.h needs to be included for compiling.

Now main calls parsing in this stage which will process the input.
Then main calls the execution part.

***Execution***

**getcwd**
char *getcwd(char *__buf, size_t __size)

**Purpose:** getcwd gets the path of the current working directory (where your program is running) and stores it in a buffer.

**Parameters:**

__buf: A buffer (array) where the path will be stored. If __buf is NULL, getcwd will allocate memory for you.\
__size: The size of the buffer. If __buf is NULL and __size is 0, getcwd will allocate just enough memory to fit the path.\

**Return Value:**

Returns the buffer (__buf) containing the path if successful.
Returns NULL if it fails (e.g., if the buffer is too small or there's another error).
