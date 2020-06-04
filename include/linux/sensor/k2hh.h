<<<<<<< HEAD
#ifndef __K2DH_DEV_H
#define __K2DH_DEV_H


/*Platform data */
struct k2hh_platform_data {
	signed char orientation[9];
	unsigned int irq_gpio;
};

=======
#ifndef __K2DH_DEV_H
#define __K2DH_DEV_H


/*Platform data */
struct k2hh_platform_data {
        signed char orientation[9];
	unsigned int irq_gpio;
};

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif