/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:05:02 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/19 19:11:18 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

static void	color_msg(char *color, char *msg, int fd);
static void	error_msg(char *msg);
static void	malloc_error(void);
static void	usage_msg_and_exit(void);
void		validates_args(int argc, char *argv[]);

#endif