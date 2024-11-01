/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:50:40 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/03 13:32:38 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include <stdlib.h>

typedef struct s_frame
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				ll;
	int				endian;
	struct s_frame	*before;
	struct s_frame	*next;
}	t_frame;

t_frame	*frame_lstnew(void);
void	frame_lstadd_back(t_frame **lst, t_frame *new);
void	frame_lstclear(t_frame **lst, void (*del)(void *));
t_frame	*frame_lstlast(t_frame *lst);
int		frame_lstsize(t_frame *lst);

#endif