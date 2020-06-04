/*
<<<<<<< HEAD
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
=======
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
 *      http://www.samsung.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/device.h>
#include <linux/err.h>

/* CAUTION : Do not be declared as external sec_class  */
static struct class *sec_class;
static atomic_t sec_dev;

static int __init sec_class_create(void)
{
	sec_class = class_create(THIS_MODULE, "sec");
	if (IS_ERR(sec_class)) {
		pr_err("Failed to create class(sec) %ld\n", PTR_ERR(sec_class));
		return PTR_ERR(sec_class);
	}
	return 0;
}

struct device *sec_device_create(void *drvdata, const char *fmt)
{
	struct device *dev;

	if (IS_ERR(sec_class)) {
		pr_err("Failed to create class(sec) %ld\n", PTR_ERR(sec_class));
		BUG();
	}

	if (!sec_class) {
		pr_err("Not yet created class(sec)!\n");
		BUG();
	}

	dev = device_create(sec_class, NULL, atomic_inc_return(&sec_dev),
			drvdata, fmt);
	if (IS_ERR(dev))
		pr_err("Failed to create device %s %ld\n", fmt, PTR_ERR(dev));
	else
		pr_debug("%s : %s : %d\n", __func__, fmt, dev->devt);

	return dev;
}
EXPORT_SYMBOL(sec_device_create);

<<<<<<< HEAD
=======
static int match_name(struct device *dev, const void *data)
{
	const char *name = data;

	return sysfs_streq(name, dev_name(dev));
}
struct device *sec_device_find(const char *name)
{
	return class_find_device(sec_class, NULL,
		(void *)name, match_name);
}
EXPORT_SYMBOL(sec_device_find);

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
void sec_device_destroy(dev_t devt)
{
	pr_info("%s : %d\n", __func__, devt);
	device_destroy(sec_class, devt);
}
EXPORT_SYMBOL(sec_device_destroy);

arch_initcall_sync(sec_class_create);
