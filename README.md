# MINISHELL

*This project has been created as part of the Ecole 42 Angouleme by     
                nbaudoin :  nbaudoin@student.42angouleme.fr &
                uuenkhba : uuenkhba@student.42angouleme.fr*

## Description
Minishell is a custom Unix shell developed as part of the 42 School curriculum. It is a simplified but functional version of Bash, designed to help students understand how shells work at a low level.
In simple terms, Minishell allows you to interact with your system through the command line by:

Displaying a prompt and reading user input.
Executing commands (both built-in and external programs).
Supporting pipes, redirections, heredoc, and variable expansion.

#### Supported Features

*   Prompt with command history using readline()
*   Pipes ()
*   Redirections: <, >, >>, << (heredoc)
*   Environment variable expansion ($VAR, $?)
*   Quotes handling: single quotes (' ') and double quotes (" ")
*   Signals: Ctrl+C, Ctrl+D, Ctrl+\ (behaves like bash)
*   Built-in commands:
        
        echo with -n option
        cd (with relative and absolute paths)
        pwd
        export
        unset
        env
        exit
#### Why This Project?
Minishell is one of the most difficult and educational projects at 42. It teaches many core concepts of system programming, such as:
*   Processes (fork, execve)
*   File descriptors (pipe, dup2, redirection)
*   Parsing (tokenization, quote handling, expansion)
*   Signal handling
*   Memory management

By completing this project, you will gain a deep understanding of how real shells like Bash operate.
## Instructions
### How to Compile and Run

1. Clone the repository
    
        Bash
        
        git clone https://github.com/yourusername/minishell.git
        cd minishell

2. Compile the project

        Bash
        
        make
This will compile the libft library and generate the minishell executable.

3. Launch Minishell

        Bash
        
        ./minishell
4. Start using it
Once launched, you will see the prompt:

        Bash
        
        minishell>
    
    You can now type commands just like in Bash.

#### Cleaning the project

    Bash
    
    make clean      # Remove object files
    make fclean     # Remove everything (executable + libft + objects)
    make re         # Recompile the entire project

#### Important Notes

*   Make sure readline library is installed on your system.
*   The project must be compiled with the flags -Wall -Wextra -Werror.
*   Memory leaks from the readline() function itself are allowed (as per 42 subject), but your own code must be leak-free.
*   Use valgrind to check for memory leaks:
Bash
    valgrind --leak-check=full --show-leak-kinds=all ./minishell

## Resources
### Official Documentation

*   Bash Manual
*   POSIX Shell Command Language
*   GNU Readline Library
*   Linux Manual Pages (especially execve, fork, pipe, dup2, signal)

### Useful Articles & Tutorials

*   Writing a simple shell in C (basic concepts)
*   Understanding Unix Processes and File Descriptors
*   How Shells Work – Everything You Need to Know
*   Heredoc Implementation Guide (search for <<)

### 42 School Related

*   Minishell Subject PDF
*   42 Common Instructions & Norm

### Tools

*   Valgrind – Memory leak detection
*   lldb / gdb – Debugging
*   readline tester & custom testers


### How AI Was Used in This Project
AI tools (mainly Grok by xAI) were used responsibly as a learning assistant in the following areas:

*   Explaining complex concepts (signals, file descriptors, heredoc logic).
*   Debugging difficult parts (especially parsing and expander logic).
*   Generating boilerplate code (Makefile structure, basic function templates).
*   Creating this README.md file (structure, examples, and formatting).
*   Suggesting better data structures and cleaner code organization.

All AI-generated code was carefully reviewed, understood, and modified before being used. No large portions were copy-pasted without full comprehension.