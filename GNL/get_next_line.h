/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:18:22 by cstefany          #+#    #+#             */
/*   Updated: 2021/11/06 20:18:24 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# if BUFFER_SIZE > 8000000
//#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
//# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);

#endif
