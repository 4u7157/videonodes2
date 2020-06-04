/*
 *  Host notify class driver
 *
<<<<<<< HEAD
 * Copyright (C) 2011-2013 Samsung, Inc.
=======
 * Copyright (C) 2011-2017 Samsung, Inc.
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
 * Author: Dongrak Shin <dongrak.shin@samsung.com>
 *
*/

<<<<<<< HEAD
=======
 /* usb notify layer v3.0 */

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifndef __LINUX_HOST_NOTIFY_H__
#define __LINUX_HOST_NOTIFY_H__

enum host_uevent_state {
	NOTIFY_HOST_NONE,
	NOTIFY_HOST_ADD,
	NOTIFY_HOST_REMOVE,
	NOTIFY_HOST_OVERCURRENT,
	NOTIFY_HOST_LOWBATT,
	NOTIFY_HOST_BLOCK,
	NOTIFY_HOST_UNKNOWN,
};

enum otg_hostnotify_mode {
	NOTIFY_NONE_MODE,
	NOTIFY_HOST_MODE,
	NOTIFY_PERIPHERAL_MODE,
	NOTIFY_TEST_MODE,
};

enum booster_power {
	NOTIFY_POWER_OFF,
	NOTIFY_POWER_ON,
};

enum set_command {
	NOTIFY_SET_OFF,
	NOTIFY_SET_ON,
};

struct host_notify_dev {
	const char *name;
	struct device *dev;
	int index;
	int state;
	int mode;
	int booster;
	int (*set_mode)(bool);
	int (*set_booster)(bool);
};

#ifdef CONFIG_USB_HOST_NOTIFY
extern int host_state_notify(struct host_notify_dev *ndev, int state);
extern int host_notify_dev_register(struct host_notify_dev *ndev);
extern void host_notify_dev_unregister(struct host_notify_dev *ndev);
#else
static inline int host_state_notify(struct host_notify_dev *ndev, int state)
	{return 0; }
static inline int host_notify_dev_register(struct host_notify_dev *ndev)
	{return 0; }
static inline void host_notify_dev_unregister(struct host_notify_dev *ndev) {}
#endif

#endif /* __LINUX_HOST_NOTIFY_H__ */
