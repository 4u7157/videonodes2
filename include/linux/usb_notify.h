/*
 *  usb notify header
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
 /* usb notify layer v2.0 */
=======
 /* usb notify layer v3.0 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifndef __LINUX_USB_NOTIFY_H__
#define __LINUX_USB_NOTIFY_H__

#include <linux/notifier.h>
#include <linux/host_notify.h>
#include <linux/external_notify.h>
#include <linux/usblog_proc_notify.h>
<<<<<<< HEAD
=======
#if defined(CONFIG_USB_HW_PARAM)
#include <linux/usb_hw_param.h>
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
#include <linux/usb.h>
#endif

enum otg_notify_events {
	NOTIFY_EVENT_NONE,
	NOTIFY_EVENT_VBUS,
	NOTIFY_EVENT_HOST,
	NOTIFY_EVENT_CHARGER,
	NOTIFY_EVENT_SMARTDOCK_TA,
	NOTIFY_EVENT_SMARTDOCK_USB,
	NOTIFY_EVENT_AUDIODOCK,
	NOTIFY_EVENT_LANHUB,
	NOTIFY_EVENT_LANHUB_TA,
	NOTIFY_EVENT_MMDOCK,
	NOTIFY_EVENT_HMT,
	NOTIFY_EVENT_GAMEPAD,
	NOTIFY_EVENT_DRIVE_VBUS,
	NOTIFY_EVENT_ALL_DISABLE,
	NOTIFY_EVENT_HOST_DISABLE,
	NOTIFY_EVENT_CLIENT_DISABLE,
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
	NOTIFY_EVENT_MDM_ON_OFF,
#endif
	NOTIFY_EVENT_OVERCURRENT,
	NOTIFY_EVENT_SMSC_OVC,
	NOTIFY_EVENT_SMTD_EXT_CURRENT,
	NOTIFY_EVENT_MMD_EXT_CURRENT,
	NOTIFY_EVENT_DEVICE_CONNECT,
	NOTIFY_EVENT_GAMEPAD_CONNECT,
	NOTIFY_EVENT_LANHUB_CONNECT,
<<<<<<< HEAD
	NOTIFY_EVENT_VBUSPOWER,
=======
	NOTIFY_EVENT_POWER_SOURCE,
	NOTIFY_EVENT_VBUSPOWER,
	NOTIFY_EVENT_POGO,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	NOTIFY_EVENT_VIRTUAL,
};

#define VIRT_EVENT(a) (a+NOTIFY_EVENT_VIRTUAL)
#define PHY_EVENT(a) (a%NOTIFY_EVENT_VIRTUAL)
#define IS_VIRTUAL(a) (a >= NOTIFY_EVENT_VIRTUAL ? 1 : 0)

enum otg_notify_event_status {
	NOTIFY_EVENT_DISABLED,
	NOTIFY_EVENT_DISABLING,
	NOTIFY_EVENT_ENABLED,
	NOTIFY_EVENT_ENABLING,
	NOTIFY_EVENT_BLOCKED,
	NOTIFY_EVENT_BLOCKING,
};

enum otg_notify_evt_type {
	NOTIFY_EVENT_EXTRA = (1 << 0),
	NOTIFY_EVENT_STATE = (1 << 1),
	NOTIFY_EVENT_DELAY = (1 << 2),
	NOTIFY_EVENT_NEED_VBUSDRIVE = (1 << 3),
	NOTIFY_EVENT_NOBLOCKING = (1 << 4),
	NOTIFY_EVENT_NOSAVE = (1 << 5),
	NOTIFY_EVENT_NEED_HOST = (1 << 6),
	NOTIFY_EVENT_NEED_CLIENT = (1 << 7),
};

enum otg_notify_block_type {
	NOTIFY_BLOCK_TYPE_NONE = 0,
	NOTIFY_BLOCK_TYPE_HOST = (1 << 0),
	NOTIFY_BLOCK_TYPE_CLIENT = (1 << 1),
	NOTIFY_BLOCK_TYPE_ALL = (1 << 0 | 1 << 1),
};

#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
enum otg_notify_mdm_type {
	NOTIFY_MDM_TYPE_OFF,
	NOTIFY_MDM_TYPE_ON,
};
#endif

enum otg_notify_gpio {
	NOTIFY_VBUS,
	NOTIFY_REDRIVER,
};

enum otg_op_pos {
	NOTIFY_OP_OFF,
	NOTIFY_OP_POST,
	NOTIFY_OP_PRE,
};

enum ovc_check_value {
	HNOTIFY_LOW,
	HNOTIFY_HIGH,
	HNOTIFY_INITIAL,
};

<<<<<<< HEAD
enum usb_hw_param {
	USB_CCIC_WATER_INT_COUNT,
	USB_CCIC_DRY_INT_COUNT,
	USB_CCIC_I2C_ERROR_COUNT,
	USB_CCIC_OVC_COUNT,
	USB_CCIC_OTG_USE_COUNT,
	USB_CCIC_DP_USE_COUNT,
	USB_CCIC_VR_USE_COUNT,
	USB_HOST_SUPER_SPEED_COUNT,
	USB_HOST_HIGH_SPEED_COUNT,
	USB_HOST_FULL_SPEED_COUNT,
	USB_HOST_LOW_SPEED_COUNT,
	USB_CLIENT_SUPER_SPEED_COUNT,
	USB_CLIENT_HIGH_SPEED_COUNT,
	USB_HOST_CLASS_AUDIO_COUNT,
	USB_HOST_CLASS_COMM_COUNT,
	USB_HOST_CLASS_HID_COUNT,
	USB_HOST_CLASS_PHYSICAL_COUNT,
	USB_HOST_CLASS_IMAGE_COUNT,
	USB_HOST_CLASS_PRINTER_COUNT,
	USB_HOST_CLASS_STORAGE_COUNT,
	USB_HOST_CLASS_HUB_COUNT,
	USB_HOST_CLASS_CDC_COUNT,
	USB_HOST_CLASS_CSCID_COUNT,
	USB_HOST_CLASS_CONTENT_COUNT,
	USB_HOST_CLASS_VIDEO_COUNT,
	USB_HOST_CLASS_WIRELESS_COUNT,
	USB_HOST_CLASS_MISC_COUNT,
	USB_HOST_CLASS_APP_COUNT,
	USB_HOST_CLASS_VENDOR_COUNT,
	USB_CCIC_DEX_USE_COUNT,
	USB_CCIC_WATER_TIME_DURATION,
	USB_CCIC_WATER_VBUS_COUNT,
	USB_CCIC_VERSION,
	USB_CCIC_HW_PARAM_MAX,
};
=======
enum otg_notify_power_role {
	HNOTIFY_SINK,
	HNOTIFY_SOURCE,
};

enum otg_notify_data_role {
	HNOTIFY_UFP,
	HNOTIFY_DFP,
};

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
struct otg_notify {
	int vbus_detect_gpio;
	int redriver_en_gpio;
	int is_wakelock;
	int unsupport_host;
	int smsc_ovc_poll_sec;
	int auto_drive_vbus;
	int booting_delay_sec;
	int disable_control;
	int device_check_sec;
<<<<<<< HEAD
	int speed;
	unsigned long long hw_param[USB_CCIC_HW_PARAM_MAX];	
=======
	int pre_peri_delay_us;
	int speed;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	const char *muic_name;
	int (*pre_gpio)(int gpio, int use);
	int (*post_gpio)(int gpio, int use);
	int (*vbus_drive)(bool);
	int (*set_host)(bool);
	int (*set_peripheral)(bool);
	int (*set_charger)(bool);
	int (*post_vbus_detect)(bool);
	int (*set_lanhubta)(int);
	int (*set_battcall)(int, int);
<<<<<<< HEAD
=======
	int (*set_chg_current)(int);
	void (*set_ldo_onoff)(void *,unsigned int);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	void *o_data;
	void *u_notify;
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
	int sec_whitelist_enable;
#endif
};

struct otg_booster {
	char *name;
	int (*booster)(bool);
};

#ifdef CONFIG_USB_NOTIFY_LAYER
extern const char *event_string(enum otg_notify_events event);
extern const char *status_string(enum otg_notify_event_status status);
extern void send_otg_notify(struct otg_notify *n,
					unsigned long event, int enable);
extern struct otg_booster *find_get_booster(struct otg_notify *n);
extern int register_booster(struct otg_notify *n, struct otg_booster *b);
extern int register_ovc_func(struct otg_notify *n,
				int (*check_state)(void *), void *data);
extern int get_usb_mode(struct otg_notify *n);
extern unsigned long get_cable_type(struct otg_notify *n);
extern int is_usb_host(struct otg_notify *n);
extern void *get_notify_data(struct otg_notify *n);
extern void set_notify_data(struct otg_notify *n, void *data);
extern struct otg_notify *get_otg_notify(void);
extern int set_otg_notify(struct otg_notify *n);
extern void put_otg_notify(struct otg_notify *n);
<<<<<<< HEAD
=======
extern bool is_blocked(struct otg_notify *n, int type);
#if defined(CONFIG_USB_HW_PARAM)
extern unsigned long long *get_hw_param(struct otg_notify *n,
					enum usb_hw_param index);
extern int inc_hw_param(struct otg_notify *n,
					enum usb_hw_param index);
extern int inc_hw_param_host(struct host_notify_dev *dev,
					enum usb_hw_param index);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
extern int usb_check_whitelist_for_mdm(struct usb_device *dev);
#endif
#else
static inline const char *event_string(enum otg_notify_events event)
			{return NULL; }
static inline const char *status_string(enum otg_notify_event_status status)
			{return NULL; }
static inline void send_otg_notify(struct otg_notify *n,
					unsigned long event, int enable) { }
static inline struct otg_booster *find_get_booster(struct otg_notify *n)
			{return NULL; }
static inline int register_booster(struct otg_notify *n,
					struct otg_booster *b) {return 0; }
static inline int register_ovc_func(struct otg_notify *n,
			int (*check_state)(void *), void *data) {return 0; }
static inline int get_usb_mode(struct otg_notify *n) {return 0; }
static inline unsigned long get_cable_type(struct otg_notify *n) {return 0; }
static inline int is_usb_host(struct otg_notify *n) {return 0; }
static inline void *get_notify_data(struct otg_notify *n) {return NULL; }
static inline void set_notify_data(struct otg_notify *n, void *data) {}
static inline struct otg_notify *get_otg_notify(void) {return NULL; }
static inline int set_otg_notify(struct otg_notify *n) {return 0; }
static inline void put_otg_notify(struct otg_notify *n) {}
<<<<<<< HEAD
=======
static inline bool is_blocked(struct otg_notify *n, int type) {return false; }
#if defined(CONFIG_USB_HW_PARAM)
static unsigned long long *get_hw_param(struct otg_notify *n,
			enum usb_hw_param index) {return NULL; }
static int inc_hw_param(struct otg_notify *n,
			enum usb_hw_param index) {return 0; }
static int inc_hw_param_host(struct host_notify_dev *dev,
			enum usb_hw_param index) {return 0; }
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(CONFIG_USB_OTG_WHITELIST_FOR_MDM)
static inline int usb_check_whitelist_for_mdm(struct usb_device *dev)
			{return 0; }
#endif
#endif
<<<<<<< HEAD

#endif /* __LINUX_USB_NOTIFY_H__ */

=======
#endif /* __LINUX_USB_NOTIFY_H__ */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
