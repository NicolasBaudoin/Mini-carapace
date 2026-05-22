#include "minishell.h"

// ==================== handle_dollar ====================
static char *handle_dollar(char *str, int *i, t_data *data, t_state state)
{
    char    *value;
    int     start;

    (*i)++;  // $ алгасах

    if (state == SINGLE_QUOTE)
        return (ft_strdup("$"));

    if (str[*i] == '?')  // $?
    {
        (*i)++;
        return (ft_itoa(g_status));
    }

    if (!str[*i] || (!ft_isalnum(str[*i]) && str[*i] != '_'))
        return (ft_strdup("$"));

    start = *i;
    while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
        (*i)++;

    char *key = ft_substr(str, start, *i - start);
    value = get_env_value(data, key);
    free(key);
    return (value);
}

// ==================== expander ====================
char *expander(char *str, t_data *data)
{
    char    *result;
    char    *tmp;
    int     i;
    t_state state;

    if (!str)
        return (NULL);

    result = ft_strdup("");
    i = 0;
    state = DEFAULT;

    while (str[i])
    {
        // Quote state update
        if (str[i] == '\'' && state == DEFAULT)
            state = SINGLE_QUOTE;
        else if (str[i] == '\'' && state == SINGLE_QUOTE)
            state = DEFAULT;
        else if (str[i] == '"' && state == DEFAULT)
            state = DOUBLE_QUOTE;
        else if (str[i] == '"' && state == DOUBLE_QUOTE)
            state = DEFAULT;

        if (str[i] == '$' && str[i + 1] && state != SINGLE_QUOTE)
        {
            tmp = handle_dollar(str, &i, data, state);
            result = ft_strjoin_free(result, tmp);
            free(tmp);
        }
        else
        {
            tmp = ft_strndup(str, i, i + 1);
            result = ft_strjoin_free(result, tmp);
            free(tmp);
            i++;
        }
    }
    return (result);
}