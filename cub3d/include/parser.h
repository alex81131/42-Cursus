/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:13 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/30 17:43:14 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "cub3d.h"
# define TEXTURES_NB 7
# define TEXTURES_PATH 5

typedef enum e_texture
{
	N = 0,
	S = 1,
	E = 2,
	W = 3,
	D = 4,
}	t_texture;

typedef struct s_data_texture
{
	void	tex_img[TEXTURES_PATH];
}