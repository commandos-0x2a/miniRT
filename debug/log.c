/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:30:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 18:01:14 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "log.h"

void	log_msg(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_vfprintf(DEBUG_FD, format, ap);
	write(DEBUG_FD, "\n", 1);
	va_end(ap);
}
