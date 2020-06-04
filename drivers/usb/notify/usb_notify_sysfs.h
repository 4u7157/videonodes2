/*
<<<<<<< HEAD
 * Copyright (C) 2015 Samsung Electronics Co. Ltd.
=======
 * Copyright (C) 2015-2017 Samsung Electronics Co. Ltd.
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

<<<<<<< HEAD
  /* usb notify layer v2.0 */
=======
  /* usb notify layer v3.0 */

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifndef __LINUX_USB_NOTIFY_SYSFS_H__
#define __LINUX_USB_NOTIFY_SYSFS_H__

#define MAX_DISABLE_STR_LEN 32
<<<<<<< HEAD
#define MAX_HWPARAM_STR_LEN 1024
#define MAX_HWPARAM_STRING 10
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)

=======
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
enum u_interface_class_type {
	U_CLASS_PER_INTERFACE = 1,
	U_CLASS_AUDIO,
	U_CLASS_COMM,
	U_CLASS_HID,
	U_CLASS_PHYSICAL,
	U_CLASS_STILL_IMAGE,
	U_CLASS_PRINTER,
	U_CLASS_MASS_STORAGE,
	U_CLASS_HUB,
	U_CLASS_CDC_DATA,
	U_CLASS_CSCID,
	U_CLASS_CONTENT_SEC,
	U_CLASS_VIDEO,
	U_CLASS_WIRELESS_CONTROLLER,
	U_CLASS_MISC,
	U_CLASS_APP_SPEC,
	U_CLASS_VENDOR_SPEC,
};

#define MAX_WHITELIST_STR_LEN 256
#define MAX_CLASS_TYPE_NUM	USB_CLASS_VENDOR_SPEC
#endif

struct usb_notify_dev {
	const char *name;
	struct device *dev;
	struct otg_notify *o_notify;
	int index;
	unsigned long disable_state;
	char disable_state_cmd[MAX_DISABLE_STR_LEN];
	int (*set_disable)(struct usb_notify_dev *, int);
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
	void (*set_mdm)(struct usb_notify_dev *udev, int mdm_disable);
	char whitelist_str[MAX_WHITELIST_STR_LEN];
	int whitelist_array_for_mdm[MAX_CLASS_TYPE_NUM+1];
#endif
};

extern int usb_notify_dev_register(struct usb_notify_dev *ndev);
extern void usb_notify_dev_unregister(struct usb_notify_dev *ndev);
extern int usb_notify_class_init(void);
extern void usb_notify_class_exit(void);
#endif

