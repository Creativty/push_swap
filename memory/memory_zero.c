/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:15:13 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 17:54:40 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

inline void	memory_zero(void	*memory, int size)
{
	memory_set(memory, size, '\0');
}
