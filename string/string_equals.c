/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:31:27 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/12 10:32:53 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_equals(const char *lhs, const char *rhs)
{
	int	i;

	i = 0;
	if (lhs == rhs)
		return (1);
	if (!lhs || !rhs)
		return (0);
	while (lhs[i] && rhs[i])
	{
		if (lhs[i] != rhs[i])
			return (0);
		i++;
	}
	return (lhs[i] == rhs[i]);
}
