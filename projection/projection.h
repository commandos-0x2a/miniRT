/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:40:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/15 13:01:28 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include <MLX42/MLX42.h>
# include <math.h>
# include "object.h"

// typedef struct s_projection
// {
//     t_vec3  position;
//     t_vec3  rotation;
// }   t_projection;

typedef struct s_geometric
{
    t_vector3  *vertices;
    int32_t  vertices_count;
    unsigned int *indices;
    int32_t indices_count;
}   t_geometric;

// void project_cube(mlx_t *mlx, t_cube *cube, t_camera *camera);

#endif
