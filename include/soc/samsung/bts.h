/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __EXYNOS_BTS_H_
#define __EXYNOS_BTS_H_

#if defined(CONFIG_EXYNOS8890_BTS)
#define CAM_FACTOR		3
#define MIF_UTIL		50
#define MIF_UTIL2		55
#define MIF_DECODING		828000	// TBD
#define MIF_ENCODING		1068000	// TBD
#define INT_UTIL		70
#define BUS_WIDTH		16
#define SIZE_FACTOR(a)		a = ((a) * 16 / 10)
#define FULLHD_SRC		1920 * 1080
#elif defined(CONFIG_EXYNOS7420_BTS) || defined(CONFIG_EXYNOS7890_BTS)
#define DECON_NOCNT		10
#define VPP_ROT			4
#define CAM_FACTOR		3
#define MIF_UTIL		50
#define MIF_UTIL2		60
#define MIF_UPPER_UTIL		44
#define MIF_DECODING		828000
#define MIF_ENCODING		1068000
#define INT_UTIL		65
#define NO_CNT_TH		100
#define BUS_WIDTH		16
#define SIZE_FACTOR(a)		a = ((a) * 16 / 10)
#define FULLHD_SRC		1920 * 1080
#else
#define FULLHD_SRC		1920 * 1080
#endif

enum bts_media_type {
	TYPE_DECON_INT,
	TYPE_DECON_EXT,
	TYPE_VPP0,
	TYPE_VPP1,
	TYPE_VPP2,
	TYPE_VPP3,
	TYPE_VPP4,
	TYPE_VPP5,
	TYPE_VPP6,
	TYPE_VPP7,
	TYPE_VPP8,
	TYPE_CAM,
	TYPE_YUV,
	TYPE_UD_ENC,
	TYPE_UD_DEC,
	TYPE_SPDMA,
};

enum vpp_bw_type {
	BW_DEFAULT,
	BW_ROT,
	BW_FULLHD_ROT,
};

<<<<<<< HEAD
#if defined(CONFIG_EXYNOS8890_BTS) || defined(CONFIG_EXYNOS7870_BTS) \
	||defined(CONFIG_EXYNOS7570_BTS)
=======
#if defined(CONFIG_EXYNOS8890_BTS) || defined(CONFIG_EXYNOS7870_BTS)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
void exynos_update_media_scenario(enum bts_media_type media_type,
		unsigned int bw, int bw_type);
#else
#define exynos_update_media_scenario(a, b, c) do {} while (0)
#endif

#if defined(CONFIG_EXYNOS7420_BTS) || defined(CONFIG_EXYNOS7890_BTS)
void exynos7_update_media_scenario(enum bts_media_type media_type,
		unsigned int bw, int bw_type);
int exynos7_update_bts_param(int target_idx, int work);
int exynos7_bts_register_notifier(struct notifier_block *nb);
int exynos7_bts_unregister_notifier(struct notifier_block *nb);
#elif defined(CONFIG_EXYNOS7870_BTS)
int exynos_update_bts_param(int target_idx, int work);
int exynos_bts_register_notifier(struct notifier_block *nb);
int exynos_bts_unregister_notifier(struct notifier_block *nb);
<<<<<<< HEAD
=======
int exynos_update_overlay_wincnt(int cnt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#else
#define exynos7_update_media_scenario(a, b, c) do {} while (0)
#define exynos7_update_bts_param(a, b) do {} while (0)
#define exynos7_bts_register_notifier(a) do {} while (0)
#define exynos7_bts_unregister_notifier(a) do {} while (0)
#define exynos_update_bts_param(a, b) do {} while (0)
#define exynos_bts_register_notifier(a) do {} while (0)
#define exynos_bts_unregister_notifier(a, b) do {} while (0)
#endif

#if defined(CONFIG_EXYNOS5430_BTS) || defined(CONFIG_EXYNOS5422_BTS)	\
	|| defined(CONFIG_EXYNOS5433_BTS)|| defined(CONFIG_EXYNOS7420_BTS) \
	|| defined(CONFIG_EXYNOS7890_BTS) || defined(CONFIG_EXYNOS8890_BTS) \
<<<<<<< HEAD
	|| defined(CONFIG_EXYNOS7870_BTS) || defined(CONFIG_EXYNOS7570_BTS)
=======
	|| defined(CONFIG_EXYNOS7870_BTS)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
void bts_initialize(const char *pd_name, bool on);
#else
#define bts_initialize(a, b) do {} while (0)
#endif

#if defined(CONFIG_EXYNOS7420_BTS) || defined(CONFIG_EXYNOS7890_BTS)
void exynos7_bts_show_mo_status(void);
#else
#define exynos7_bts_show_mo_status() do {} while (0)
#endif

#if defined(CONFIG_EXYNOS5430_BTS)
void exynos5_bts_show_mo_status(void);
#else
#define exynos5_bts_show_mo_status() do { } while (0)
#endif

#if defined(CONFIG_EXYNOS5430_BTS) || defined(CONFIG_EXYNOS5433_BTS)
void bts_otf_initialize(unsigned int id, bool on);
#else
#define bts_otf_initialize(a, b) do {} while (0)
#endif

#if defined(CONFIG_EXYNOS5422_BTS) || defined(CONFIG_EXYNOS5433_BTS)	\
	|| defined(CONFIG_EXYNOS7420_BTS) || defined(CONFIG_EXYNOS7890_BTS) \
<<<<<<< HEAD
	|| defined(CONFIG_EXYNOS8890_BTS) || defined(CONFIG_EXYNOS7870_BTS) \
	|| defined(CONFIG_EXYNOS7570_BTS)
=======
	|| defined(CONFIG_EXYNOS8890_BTS) || defined(CONFIG_EXYNOS7870_BTS)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
enum bts_scen_type {
	TYPE_MFC_UD_ENCODING = 0,
	TYPE_MFC_UD_DECODING,
	TYPE_LAYERS,
	TYPE_G3D_FREQ,
	TYPE_G3D_SCENARIO,
	TYPE_CAM_BNS,
};

void bts_scen_update(enum bts_scen_type type, unsigned int val);
#else
#define bts_scen_update(a, b) do {} while(0)
#endif

#endif
