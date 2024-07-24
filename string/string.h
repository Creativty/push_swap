/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:19:17 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:25:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

int		string_copy(const char *src, char *dst, int count);
int		string_length(const char *str);
int		string_length_safe(const char *str, int capacity);
int		string_includes(const char *str, char rune);
int		string_index_of(const char *hay, char needle);
int		string_index_of_safe(const char *hay, int length, char needle);
int		string_equals(const char *lhs, const char *rhs);
int		string_includes_not(const char *str, const char *charset);
char	*string_duplicate(const char *str);
char	*string_substring(const char *str, int sub_len);
char	*string_join(const char *lhs, int lcount, const char *rhs, int rcount);
char	**string_split(const char *str, char sep);

#endif
