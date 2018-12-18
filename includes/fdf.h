/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 18:04:54 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 00:19:56 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "math.h"

# define TITLE "FDF"
# define MARGE 100
# define MARGE_X 500
# define ABS(x) (x < 0 ? -x : x)
# define H 1400 + MARGE
# define W 2500 + MARGE
# define LEFT 123
# define RIGHT 124
# define TOP 126
# define BOT 125
# define SPACE 49
# define P 35
# define L 37
# define W_ROTATE 13
# define S_ROTATE 1
# define PLUS 69
# define MOINS 78
# define ENTER 36

/*
** COUELURS;
*/
# define CIEL 808080
# define BLUE (0<<16) + (15<<8) + 250
# define RED (255<<16) + (0<<8) + 0
# define BLACK (0<<16) + (0<<8) + 0
# define WHITE (255<<16) + (255<<8) + 255

typedef struct		s_jump
{
	int				jump_right;
	int				jump_bot;
	int				cpt;
	int				color;
	float			speed_p;
	float			speed_m;
}					t_jump;

typedef struct		s_struct
{
	int				cpt_space;
	int				nb_ord;
	int				nb_abs;
	int				color_zero;
}					t_struct;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_vect
{
	t_point			vect_i;
	t_point			vect_j;
	t_point			vect_k;
	t_point			vect_ii;
	t_point			vect_jj;
	t_point			vect_kk;
	t_point			zuum;
	t_point			mrg;
}					t_vect;

typedef struct		s_tab
{
	t_point			**coord;
	t_vect			*vect;
	t_struct		*pos;
	t_jump			*jump;
	void			*mlx_ptr;
	void			*win_ptr;
	int				change_proj;
}					t_tab;

void				fdf(t_tab *tab, char **map);
char				**fdf_parsing(char **av, t_tab *tab);
int					cpt_col(char **map);
void				stock_point(t_tab *tab);
/*
** INITIALISATION
*/
t_tab				*init_all(t_tab *tab, char **map);
void				init_z(t_tab *tab, char **map);
void				init_vect(t_tab *tab);
void				actu_vect(t_tab *tab);
/*
** PROJECTIONS
*/
void				algo_obli(t_tab *tab);
void				algo_iso(t_tab *tab);
/*
** GESTION TOUCHE DU CLAVIER SOURIS
*/
int					zoom_win(int keycode, t_tab *tab);
int					space_color(int keycode, void *tmp);
int					zoom_mouse(int keycode, int x, int y, void *tmp);
/*
** AFFICHAGE
*/
void				tracer_segment(t_tab *tab);
void				put_line(t_tab *tab);
void				put_pix(t_tab *tab);
void				draw_line(t_point src, t_point dst, t_tab *tab, int color);
void				boucle_affiche(t_tab *tab);
void				affiche_help(t_tab *tab);
void				free_tab(t_tab *tab);

#endif
