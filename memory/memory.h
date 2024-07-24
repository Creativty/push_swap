/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:14 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:24:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

void	memory_zero(void *memory, int size);
void	memory_set(void *memory, int size, t_byte rune);
void	memory_free_count(void **array, int count, int self);
void	memory_free_cstyle(void **array, int self);
void	memory_move(void *src, t_uint count, void *dst);
void	memory_copy(void *src, t_uint count, void *dst);

#endif
