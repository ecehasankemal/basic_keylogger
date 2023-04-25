/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylogger.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:40 by hece              #+#    #+#             */
/*   Updated: 2023/04/25 16:00:21 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYLOGGER_H
# define KEYLOGGER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_keylogger
{
	char	*buf;
	int		log_fd;
	int		attack_fd;
	int		flags;
	int		nbytes;
	int		bytes;
}				t_keylogger;

#endif
