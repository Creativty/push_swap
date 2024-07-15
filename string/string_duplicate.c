/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:22:41 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:22:46 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*string_duplicate(const char *str)
{
	return (string_substring(str, string_length(str)));
}
