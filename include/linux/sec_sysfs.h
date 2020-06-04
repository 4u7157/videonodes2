/*
<<<<<<< HEAD
* Copyright (c) 2016 Samsung Electronics Co., Ltd.
=======
* Copyright (c) 2014 Samsung Electronics Co., Ltd.
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
*      http://www.samsung.com
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*/

#ifndef SEC_SYSFS_H
#define SEC_SYSFS_H

#ifdef CONFIG_SEC_SYSFS
extern struct device *sec_device_create(void *drvdata, const char *fmt);
<<<<<<< HEAD
=======
extern struct device *sec_device_find(const char *name);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
extern void sec_device_destroy(dev_t devt);
#else
static inline struct device *sec_device_create(void *drvdata, const char *fmt)
{
	pr_err("No rule to make sec sysfs\n");
	return NULL;
}
static inline void sec_device_destroy(dev_t devt)
{
	return;
}
#endif

#endif /* SEC_SYSFS_H */
