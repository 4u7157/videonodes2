#ifndef __DYNAMIC_AID_H
#define __DYNAMIC_AID_H __FILE__

enum {
	CI_RED,
	CI_GREEN,
	CI_BLUE,
	CI_MAX
};

struct rgb_t {
	int rgb[CI_MAX];
};

struct formular_t {
	int numerator;
	int denominator;
};

<<<<<<< HEAD
struct dynamic_aid_param_t {
	int				vreg;
=======
struct m_gray_limit_t {
	int min;
	int max;
};

struct dynamic_aid_param_t {
	int				vreg;
	int				vref_h;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	const int		*iv_tbl;
	int				iv_max;
	int				*mtp;
	const int		*gamma_default;
	const struct formular_t *formular;
	const int		*vt_voltage_value;

	const int	*ibr_tbl;
	int			ibr_max;
<<<<<<< HEAD
	const int	*br_base;
	const int	**gc_tbls; /* Gamma curve tables */
	const int	*gc_lut; /* Gamma curve for generating the Lookup Table */
	const int	(*offset_gra)[];
	const struct rgb_t	(*offset_color)[];
=======
	const struct rgb_t	(*offset_color)[];
	int			*iv_ref;
	const int	(*m_gray)[];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
};

extern int dynamic_aid(struct dynamic_aid_param_t d_aid, int **gamma);

#endif /* __DYNAMIC_AID_H */
