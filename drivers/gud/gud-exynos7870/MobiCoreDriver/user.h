/*
 * Copyright (c) 2013-2015 TRUSTONIC LIMITED
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

<<<<<<< HEAD
#ifndef _MC_USER_H_
#define _MC_USER_H_
=======
#ifndef _USER_H_
#define _USER_H_
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

struct cdev;

int mc_user_init(struct cdev *cdev);
static inline void mc_user_exit(void)
{
}

<<<<<<< HEAD
#endif /* _MC_USER_H_ */
=======
#endif /* _USER_H_ */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
