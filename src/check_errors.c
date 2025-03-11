/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:01:39 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/11 04:31:13 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(int flag)
{
	ft_putstr_fd("ERROR\n", 2);
	if (flag == 1)
		ft_putstr_fd("le nombre des parametres est incorrect:\n<Usage>:<./so_long> <nom_map.ber>\n", 2);
	if (flag == 2)
		ft_putstr_fd("L'extension de la map est incorrecte, merci de vous assurer que c'est map.ber.\n", 2);
	exit(1);
}