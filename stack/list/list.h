/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:00:34 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:25:09 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
}	t_list;

t_list			*list_new(void);
unsigned int	list_size(void *head);
void			list_free(t_list *head);
t_list			*list_tail(t_list *head);
t_list			*list_at(t_list *head, int position);

void			list_append(t_list **head, t_list *node);
void			list_insert(t_list **head, t_list *node);
t_list			*list_shift(t_list **head);
t_list			*list_pop(t_list **head);

#endif
