<<<<<<< HEAD
/* tc300k.h -- Linux driver for coreriver chip as touchkey
=======
/* tc300k.h -- Linux driver for coreriver chip as grip
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
 *
 * Copyright (C) 2013 Samsung Electronics Co.Ltd
 * Author: Junkyeong Kim <jk0430.kim@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#ifndef __LINUX_TC3XXK_H
#define __LINUX_TC3XXK_H

#define VENDOR_NAME	"CORERIVER"
#define MODULE_NAME	"grip_sensor"
<<<<<<< HEAD

#if defined(CONFIG_SENSORS_TC350K)
#define MODEL_NAME	"TC350K"
#elif defined(CONFIG_SENSORS_TC300K)
#define MODEL_NAME	"TC300K"
#elif defined(CONFIG_SENSORS_TC305K)
#define MODEL_NAME	"TC305K"
#else
#define MODEL_NAME	"TC3XXK"
#endif

/* TSK IC */
#define TC300K_TSK_IC	0x00
#define TC350K_TSK_IC	0x01
=======
#define MODEL_NAME	"TC3XXK"
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

struct tc3xxk_platform_data {
	int gpio_int;
	int gpio_sda;
	int gpio_scl;
<<<<<<< HEAD
	int gpio_pwr;
	int i2c_gpio;
	int (*power) (void *, bool on);
	int (*power_isp) (bool on);
	int (*keyled) (void *, bool on);
=======
	int ldo_en;
	int i2c_gpio;
	int (*power) (void *, bool on);
	int (*power_isp) (bool on);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	u32 irq_gpio_flags;
	u32 sda_gpio_flags;
	u32 scl_gpio_flags;
	const char *regulator_ic;
	bool boot_on_ldo;
	int bringup;
<<<<<<< HEAD

	int *keycode;
	int key_num;
	const char *fw_name;
	u32 sensing_ch_num;
	u32 use_bitmap;
	u32 tsk_ic_num;
=======
	int earjack_concept;

	const char *fw_name;
	u32 use_bitmap;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
};

#endif /* __LINUX_TC3XXK_H */
