/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:30:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 16:57:37 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>

void	log_msg(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_vfprintf(2, format, ap);
	write(2, "\n", 1);
	va_end(ap);
}
