/*
<<<<<<< HEAD
 * Copyright (c) 2013-2015 TRUSTONIC LIMITED
=======
 * Copyright (c) 2013-2017 TRUSTONIC LIMITED
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _MC_MAIN_H_
#define _MC_MAIN_H_

#include <linux/slab.h>		/* gfp_t */
#include <linux/fs.h>		/* struct inode and struct file */
<<<<<<< HEAD

#define MC_VERSION(major, minor) \
		(((major & 0x0000ffff) << 16) | (minor & 0x0000ffff))
=======
#include <linux/mutex.h>
#include <linux/version.h>

#define MC_VERSION(major, minor) \
		((((major) & 0x0000ffff) << 16) | ((minor) & 0x0000ffff))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define MC_VERSION_MAJOR(x) ((x) >> 16)
#define MC_VERSION_MINOR(x) ((x) & 0xffff)

#define mc_dev_err(fmt, ...) \
	dev_err(g_ctx.mcd, "%s: " fmt, __func__, ##__VA_ARGS__)

#define mc_dev_info(fmt, ...) \
	dev_info(g_ctx.mcd, "%s: " fmt, __func__, ##__VA_ARGS__)

#ifdef DEBUG
#define mc_dev_devel(fmt, ...) \
	dev_info(g_ctx.mcd, "%s: " fmt, __func__, ##__VA_ARGS__)
#else /* DEBUG */
#define mc_dev_devel(...)		do {} while (0)
#endif /* !DEBUG */

<<<<<<< HEAD
=======
#define TEE_START_NOT_TRIGGERED 1

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
/* MobiCore Driver Kernel Module context data. */
struct mc_device_ctx {
	struct device		*mcd;
	/* debugfs root */
	struct dentry		*debug_dir;

	/* Features */
	/* - SWd uses LPAE MMU table format */
	bool			f_lpae;
	/* - SWd can set a time out to get scheduled at a future time */
	bool			f_timeout;
	/* - SWd supports memory extension which allows for bigger TAs */
	bool			f_mem_ext;
	/* - SWd supports TA authorisation */
	bool			f_ta_auth;
	/* - SWd can map several buffers at once */
	bool			f_multimap;
	/* - SWd supports GP client authentication */
	bool			f_client_login;
	/* - SWd needs time updates */
	bool			f_time;

	/* Debug counters */
	atomic_t		c_clients;
	atomic_t		c_cbufs;
	atomic_t		c_sessions;
	atomic_t		c_wsms;
	atomic_t		c_mmus;
<<<<<<< HEAD
=======
	atomic_t		c_maps;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
};

extern struct mc_device_ctx g_ctx;

/* Debug stuff */
struct kasnprintf_buf {
<<<<<<< HEAD
=======
	struct mutex mutex;	/* Protect buf/size/off access */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	gfp_t gfp;
	void *buf;
	int size;
	int off;
};

<<<<<<< HEAD
=======
/* Wait for TEE to start and get status */
int mc_wait_tee_start(void);

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
extern __printf(2, 3)
int kasnprintf(struct kasnprintf_buf *buf, const char *fmt, ...);
ssize_t debug_generic_read(struct file *file, char __user *user_buf,
			   size_t count, loff_t *ppos,
			   int (*function)(struct kasnprintf_buf *buf));
<<<<<<< HEAD
int debug_generic_release(struct inode *inode, struct file *file);

static inline int kref_read(struct kref *kref)
{
	return atomic_read(&kref->refcount);
}
=======
int debug_generic_open(struct inode *inode, struct file *file);
int debug_generic_release(struct inode *inode, struct file *file);

#if KERNEL_VERSION(4, 11, 0) > LINUX_VERSION_CODE
static inline unsigned int kref_read(struct kref *kref)
{
	return atomic_read(&kref->refcount);
}
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#endif /* _MC_MAIN_H_ */
