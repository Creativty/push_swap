/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:14 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:21:59 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MEMORY_H
#define MEMORY_H

typedef unsigned char byte;

void	memory_zero(void *memory, int size);
void	memory_set(void *memory, int size, byte rune);

#endif
