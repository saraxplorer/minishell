/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exec_builtin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/26 18:37:27 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/08/26 19:37:26 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);//need to free after use
	if (!cwd)
		return (1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

//checks for -n flag
//returns 0 if -n is not found
//returns 1 if -n is found

static int	skip_newline(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	skip_newline_flag;

	i = 1;
	skip_newline_flag = 0;
	while (args[i] != NULL && skip_newline(args[i]) == 1)
	{
		skip_newline_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (skip_newline_flag == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	ft_exec_builtin(char **args)
{
	if (ft_strncmp(args[0], "pwd", 3) == 0)//we dont have strcmp
		return (ft_pwd());
	return (1);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_exec_builtin(argv + 1);//skip the program name
	return (0);
}