


### Memory leaks

**to avoid leaks from readline**

- create readline.supp
```bash
{
   readline_still_reachable
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   obj:*/libreadline.so.*
}
```
- then run :
```bash
valgrind --leak-check=full --suppressions=readline.supp ./minishell
```








