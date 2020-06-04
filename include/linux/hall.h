#ifndef _HALL_H
#define _HALL_H
struct hall_platform_data {
	unsigned int rep:1;		/* enable input subsystem auto repeat */
	int gpio_flip_cover;
<<<<<<< HEAD
};
extern struct device *sec_key;

#ifdef CONFIG_SENSORS_HALL_IRQ_CTRL
extern void hall_irq_set(int state, bool auth_changed);
enum state {
	disable = 0,
	enable
};
#endif

=======
	int gpio_certify_cover;
};
extern struct device *sec_key;

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif /* _HALL_H */
