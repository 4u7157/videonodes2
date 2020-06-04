/*
<<<<<<< HEAD
*
* File name: mtv319_port.h
*
* Description : Configuration for RAONTECH MTV319 Services.
*
* Copyright (C) (2013, RAONTECH)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation version 2.
*
* This program is distributed "as is" WITHOUT ANY WARRANTY of any
* kind, whether express or implied; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*/
=======
 *
 * File name: mtv319_port.h
 *
 * Description : Configuration for RAONTECH MTV319 Services.
 *
 * Copyright (C) (2013, RAONTECH)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifndef __MTV319_PORT_H__
#define __MTV319_PORT_H__

<<<<<<< HEAD
/*=============================================================================
 * Includes the user header files if neccessry.
 *===========================================================================*/
=======
/**
 * Includes the user header files if neccessry.
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(__KERNEL__) /* Linux kernel */
	#include <linux/io.h>
	#include <linux/kernel.h>
	#include <linux/delay.h>
	#include <linux/mm.h>
	#include <linux/mutex.h>
	#include <linux/uaccess.h>
	#include <linux/string.h>
	#include <linux/time.h>
	#include <linux/jiffies.h>

#elif defined(WINCE) || defined(WINDOWS) || defined(WIN32)
	#include <windows.h>
	#include <winbase.h>
	#include <string.h>
	#ifdef WINCE
		#include <drvmsg.h>
	#endif
#else
	#include <stdio.h>
	#include <string.h>
#endif

#ifdef __cplusplus
extern "C"{
#endif

<<<<<<< HEAD
/*############################################################################
#
# COMMON configurations
#
############################################################################*/
/*============================================================================
* The slave address for I2C and SPI.
*===========================================================================*/
#define RTV_CHIP_ADDR	0x86

/*============================================================================
* Modifies the basic data types if neccessry.
*===========================================================================*/
=======
/**
 *
 * COMMON configurations
 */

/**
 * The slave address for I2C and SPI.
 */
#define RTV_CHIP_ADDR	0x86

/**
 * Modifies the basic data types if neccessry.
 **/
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define BOOL		int
#define S8		s8
#define U8		u8
#define S16		s16
#define U16		u16
#define S32		s32
#define U32		u32

#define INT		int
#define UINT		unsigned int
#define LONG		long
#define ULONG		unsigned long

#define INLINE		inline

<<<<<<< HEAD
/*============================================================================
* Defines the package type of chip to target product.
*===========================================================================*/
#define RTV_CHIP_PKG_CSP
/* #define RTV_CHIP_PKG_QFN */

/*============================================================================
* Defines the external source freqenecy in KHz.
* Ex> #define RTV_SRC_CLK_FREQ_KHz	36000 // 36MHz
*===========================================================================*/
=======
/**
 * Defines the package type of chip to target product.
 **/
#define RTV_CHIP_PKG_CSP
/* #define RTV_CHIP_PKG_QFN */

/**
 * Defines the external source freqenecy in KHz.
 * Ex> #define RTV_SRC_CLK_FREQ_KHz	36000 // 36MHz
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef CONFIG_TDMB_XTAL_FREQ
#define RTV_SRC_CLK_FREQ_KHz		24000
#else
#define RTV_SRC_CLK_FREQ_KHz		24576
#endif

<<<<<<< HEAD
/*============================================================================
* Defines the Host interface.
*===========================================================================*/
=======
/**
 * Defines the Host interface.
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define RTV_IF_SPI /* AP: SPI Master Mode */
/*#define RTV_IF_TSIF*/ /* I2C + TSIF Master Mode*/
/* #define RTV_IF_SPI_SLAVE */ /* AP: SPI Slave Mode*/

<<<<<<< HEAD
/*============================================================================
* Defines the polarity of interrupt if necessary.
*===========================================================================*/
#define RTV_INTR_POLARITY_LOW_ACTIVE
/* #define RTV_INTR_POLARITY_HIGH_ACTIVE */

/*============================================================================
* Defines the delay macro in milliseconds.
*===========================================================================*/
=======
/**
 * Defines the polarity of interrupt if necessary.
 */
#define RTV_INTR_POLARITY_LOW_ACTIVE
/* #define RTV_INTR_POLARITY_HIGH_ACTIVE */

/**
 * Defines the delay macro in milliseconds.
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(__KERNEL__) /* Linux kernel */
	static INLINE void RTV_DELAY_MS(UINT ms)
	{
		unsigned long start_jiffies, end_jiffies;
		UINT diff_time;
		UINT _1ms_cnt = ms;

		start_jiffies = get_jiffies_64();

		do {
			end_jiffies = get_jiffies_64();

<<<<<<< HEAD
			diff_time = jiffies_to_msecs(end_jiffies - start_jiffies);
=======
			diff_time
				= jiffies_to_msecs(end_jiffies - start_jiffies);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (diff_time >= ms)
				break;

			mdelay(1);
		} while (--_1ms_cnt);
	}

#elif defined(WINCE)
	#define RTV_DELAY_MS(ms)    Sleep(ms)

#else
	extern void mtv_delay_ms(int ms);
<<<<<<< HEAD
	#define RTV_DELAY_MS(ms)	mtv_delay_ms(ms) // TODO
#endif

/*============================================================================
* Defines the debug message macro.
*===========================================================================*/
#if 1
    #define RTV_DBGMSG0(fmt)                   printk(fmt)
    #define RTV_DBGMSG1(fmt, arg1)             printk(fmt, arg1)
    #define RTV_DBGMSG2(fmt, arg1, arg2)       printk(fmt, arg1, arg2)
    #define RTV_DBGMSG3(fmt, arg1, arg2, arg3) printk(fmt, arg1, arg2, arg3)
=======
	#define RTV_DELAY_MS(ms)	mtv_delay_ms(ms) /* TODO */
#endif

/**
 * Defines the debug message macro.
 */
#if 1
	#define RTV_DBGMSG(fmt, args...) pr_info("MTV319: %s(): " fmt, __func__, ## args)
	#define RTV_DBGMSG0(fmt, args...) pr_info("MTV319: %s(): " fmt, __func__, ## args)
	#define RTV_DBGMSG1(fmt, args...) pr_info("MTV319: %s(): " fmt, __func__, ## args)
	#define RTV_DBGMSG2(fmt, args...) pr_info("MTV319: %s(): " fmt, __func__, ## args)
	#define RTV_DBGMSG3(fmt, args...) pr_info("MTV319: %s(): " fmt, __func__, ## args)

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#else
    /* To eliminates the debug messages. */
    #define RTV_DBGMSG0(fmt)			do {} while (0)
    #define RTV_DBGMSG1(fmt, arg1)		do {} while (0)
    #define RTV_DBGMSG2(fmt, arg1, arg2)	do {} while (0)
    #define RTV_DBGMSG3(fmt, arg1, arg2, arg3)	do {} while (0)
#endif
/*#### End of Common ###########*/


<<<<<<< HEAD
/*#############################################################################
#
# T-DMB specific configurations
#
#############################################################################*/
=======
/**
 *
 * T-DMB specific configurations
 */

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
/* Determine if the FIC is not handled by interrupt. */
/* #define RTV_FIC_POLLING_MODE */

/* Defines the number of sub channel to be open simultaneously. (AV + DATA) */
#define RTV_MAX_NUM_USE_SUBCHANNEL	1

#if defined(RTV_IF_SPI) || defined(RTV_IF_EBI2)
	/* #define RTV_SPI_FIC_DECODE_IN_PLAY */

	/* The size of interrupt level for CIF mode of SPI interface. */
	#define RTV_SPI_CIF_MODE_INTERRUPT_SIZE	(16 * 188)

#elif defined(RTV_IF_TSIF) || defined(RTV_IF_SPI_SLAVE)
	/*========================================================*/
	/* Selects FIC transmission path when SCAN and PLAY state */
	/* NA: Not Applicable                                     */
	/*========================================================*/
	/* #define RTV_FIC__SCAN_I2C__PLAY_NA */ /* Polling or Intrrupt. */
	/* #define RTV_FIC__SCAN_I2C__PLAY_I2C */ /* Polling or Intrrupt */
	/* #define RTV_FIC__SCAN_I2C__PLAY_TSIF*/ /* Polling or Intrrupt */
	#define RTV_FIC__SCAN_TSIF__PLAY_NA   /* Polling meaningless */
	/* #define RTV_FIC__SCAN_TSIF__PLAY_I2C */ /* Polling or Intrrupt */
	/* #define RTV_FIC__SCAN_TSIF__PLAY_TSIF */ /* Polling meaningless */
#endif

/* Determine whether or not FIC header generated by MTV319 is enabled. */
#if defined(RTV_FIC__SCAN_TSIF__PLAY_NA) \
	|| defined(RTV_FIC__SCAN_TSIF__PLAY_I2C) \
	|| defined(RTV_FIC__SCAN_TSIF__PLAY_TSIF)
#define RTV_SCAN_FIC_HDR_ENABLED /* Scan state */
#endif
/* Determine whether or not FIC header generated by MTV319 is enabled. */
<<<<<<< HEAD
//#define RTV_PLAY_FIC_HDR_ENABLED /* Play state */

/* Determine whether or not MSC header generated by MTV319 is enabled. */
//#define RTV_MSC_HDR_ENABLED
=======
/*#define RTV_PLAY_FIC_HDR_ENABLED */ /* Play state */

/* Determine whether or not MSC header generated by MTV319 is enabled. */
/*#define RTV_MSC_HDR_ENABLED*/
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos


/* Determine if the output of error-tsp is disable. */
/*#define RTV_ERROR_TSP_OUTPUT_DISABLE */

#ifndef RTV_ERROR_TSP_OUTPUT_DISABLE
	/* Determine if the NULL PID will generated for error-tsp. */
	/*#define RTV_NULL_PID_GENERATE*/

	/* Determine if the sync-byte was insert for error-tsp forcely. */
	#define RTV_FORCE_INSERT_SYNC_BYTE
#endif /* RTV_ERROR_TSP_OUTPUT_DISABLE */


/* Determine if the multi channel decoder is compiled with RAONTECH driver. */
#define RTV_MCHDEC_IN_DRIVER

#ifdef RTV_MCHDEC_IN_DRIVER
<<<<<<< HEAD
	/* Select the copying method of MCH decoded data(FIC and MSC).
	CIF decoder copy the decoded data into user space buffer direcly
	to fast operation.
	NOTE: Only applicable in RTV_MULTIPLE_CHANNEL_MODE defined. */
=======
	/*
	 * Select the copying method of MCH decoded data(FIC and MSC).
	 * CIF decoder copy the decoded data into user space buffer direcly
	 * to fast operation.
	 * NOTE: Only applicable in RTV_MULTIPLE_CHANNEL_MODE defined.
	 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	/* #define RTV_MCHDEC_DIRECT_COPY_USER_SPACE */
#endif


<<<<<<< HEAD
/*############################################################################
#
# Host Interface specific configurations
#
############################################################################*/
#if defined(RTV_IF_SPI)
	/*=================================================================
	* Defines the register I/O macros.
	*================================================================*/
	void mtv319_set_port_if(unsigned long interface);	
=======
/**
 *
 * Host Interface specific configurations
 *
 */
#if defined(RTV_IF_SPI)
	/**
	 * Defines the register I/O macros.
	 */
	void mtv319_set_port_if(unsigned long interface);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	U8 mtv319_spi_read(U8 page, U8 reg);
	void mtv319_spi_read_burst(U8 page, U8 reg, U8 *buf, int size);
	void mtv319_spi_write(U8 page, U8 reg, U8 val);
	void mtv319_spi_recover(unsigned char *buf, unsigned int intr_size);
	extern U8 g_bRtvPage;

	static INLINE U8 RTV_REG_GET(U8 reg)
	{
		if (g_bRtvPage == 0xF)
			reg ^= 0x10;

		return (U8)mtv319_spi_read(g_bRtvPage, (U8)(reg));
	}

	#define RTV_REG_BURST_GET(reg, buf, size)\
		mtv319_spi_read_burst(g_bRtvPage, (U8)(reg), buf, (size))

	static INLINE void RTV_REG_SET(U8 reg, U8 val)
	{
		if (g_bRtvPage == 0xF)
			reg ^= 0x10;

		mtv319_spi_write(g_bRtvPage, (U8)(reg), (U8)(val));
	}

	#define RTV_REG_MASK_SET(reg, mask, val)\
	do {					\
		U8 tmp;				\
		tmp = (RTV_REG_GET(reg)|(U8)(mask))\
				& (U8)((~(mask))|(val));\
		RTV_REG_SET(reg, tmp);		\
	} while (0)

	#define RTV_TSP_XFER_SIZE	188

#elif defined(RTV_IF_TSIF) || defined(RTV_IF_SPI_SLAVE)
<<<<<<< HEAD
	/*=================================================================
	* Defines the TS format.
	*================================================================*/
=======
	/**
	 * Defines the TS format.
	 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	/* #define RTV_TSIF_FORMAT_0 */ /* EN_high, CLK_rising */
	/* #define RTV_TSIF_FORMAT_1 */ /* EN_high, CLK_falling */
	/* #define RTV_TSIF_FORMAT_2 */ /* EN_low, CLK_rising */
	/* #define RTV_TSIF_FORMAT_3 */ /* EN_low, CLK_falling */
	#define RTV_TSIF_FORMAT_4 /* EN_high, CLK_rising + 1CLK add */
	/* #define RTV_TSIF_FORMAT_5 */ /* EN_high, CLK_falling + 1CLK add */
	/* #define RTV_TSIF_FORMAT_6 */ /* Parallel: EN_high, CLK_falling */

<<<<<<< HEAD
	/*=================================================================
	* Defines the TSIF speed.
	*================================================================*/
=======
	/**
	 * Defines the TSIF speed.
	 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	/* #define RTV_TSIF_SPEED_3_Mbps */ /* 2.41MHz */
	#define RTV_TSIF_SPEED_4_Mbps   /* 3.62MHz */
	/* #define RTV_TSIF_SPEED_5_Mbps */ /* 4.8MHz */
	/* #define RTV_TSIF_SPEED_6_Mbps */ /* 5.8MHz */
	/* #define RTV_TSIF_SPEED_8_Mbps */ /* 7.2MHz */
	/* #define RTV_TSIF_SPEED_10_Mbps */ /* 9.6MHz */
	/* #define RTV_TSIF_SPEED_15_Mbps */ /* 14.5MHz */
	/* #define RTV_TSIF_SPEED_30_Mbps */ /* 28.8MHz */
	/* #define RTV_TSIF_SPEED_60_Mbps */ /* 58.5MHz */

<<<<<<< HEAD
	/*=================================================================
	* Defines the TSP size. 188 or 204
	*================================================================*/
	#define RTV_TSP_XFER_SIZE	188

	/*=================================================================
	* Defines the register I/O macros.
	*================================================================*/
=======
	/**
	 * Defines the TSP size. 188 or 204
	 */
	#define RTV_TSP_XFER_SIZE	188

	/**
	 * Defines the register I/O macros.
	 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	void mtv319_set_port_if(unsigned long interface);
	U8 mtv319_i2c_read(U8 chipid, U8 reg);
	void mtv319_i2c_read_burst(U8 reg, U8 *buf, int size);
	void mtv319_i2c_write(U8 chipid, U8 reg, U8 val);
	extern U8 g_bRtvPage;

	static INLINE U8 RTV_REG_GET(U8 reg)
	{
		U8 bRegVal;

		if (g_bRtvPage != 0xF)
			bRegVal = mtv319_i2c_read((U8)RTV_CHIP_ADDR, (U8)(reg));
		else {
			mtv319_i2c_write(RTV_CHIP_ADDR, 0x02, (0x62|0x80));
			bRegVal = mtv319_i2c_read((U8)(0x62<<1), (U8)(reg));
		}

		return bRegVal;
	}

	#define	RTV_REG_BURST_GET(reg, buf, size)\
			mtv319_i2c_read_burst((U8)(reg), buf, size)

	static INLINE void RTV_REG_SET(U8 reg, U8 val)
	{
		if (g_bRtvPage != 0xF)
			mtv319_i2c_write(RTV_CHIP_ADDR, (U8)(reg), (U8)(val));
		else {
<<<<<<< HEAD
			   mtv319_i2c_write(RTV_CHIP_ADDR, 0x02, (0x62|0x80));
			   mtv319_i2c_write((0x62<<1), (U8)(reg), (U8)(val));
=======
			mtv319_i2c_write(RTV_CHIP_ADDR, 0x02, (0x62|0x80));
			mtv319_i2c_write((0x62<<1), (U8)(reg), (U8)(val));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}
	}

	#define	RTV_REG_MASK_SET(reg, mask, val)\
		do {					\
			U8 tmp;				\
			tmp = (RTV_REG_GET(reg)|(U8)(mask))\
					& (U8)((~(mask))|(val));\
			RTV_REG_SET(reg, tmp);		\
		} while (0)

#elif defined(RTV_IF_EBI2)
<<<<<<< HEAD
	/*=================================================================
	* Defines the register I/O macros.
	*================================================================*/
=======
	/**
	 * Defines the register I/O macros.
	 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	U8 tdmb_ebi2_read(U8 page, U8 reg);
	void tdmb_ebi2_read_burst(U8 page, U8 reg, U8 *buf, int size);
	void tdmb_ebi2_write(U8 page, U8 reg, U8 val);
	extern U8 g_bRtvPage;

	static INLINE U8 RTV_REG_GET(U8 reg)
	{
		if (g_bRtvPage == 0xF)
			reg ^= 0x10;

		return (U8)tdmb_ebi2_read(g_bRtvPage, (U8)(reg));
	}

	#define RTV_REG_BURST_GET(reg, buf, size)\
		tdmb_ebi2_read_burst(g_bRtvPage, (U8)(reg), buf, (size))

	static INLINE void RTV_REG_SET(U8 reg, U8 val)
	{
		if (g_bRtvPage == 0xF)
			reg ^= 0x10;

		tdmb_ebi2_write(g_bRtvPage, (U8)(reg), (U8)(val));
	}

	#define RTV_REG_MASK_SET(reg, mask, val)\
	do {					\
		U8 tmp;				\
		tmp = (RTV_REG_GET(reg)|(U8)(mask))\
				& (U8)((~(mask))|(val));\
		RTV_REG_SET(reg, tmp);		\
	} while (0)

	#define RTV_TSP_XFER_SIZE	188
#else
	#error "Must define the interface definition !"
#endif


<<<<<<< HEAD
/*############################################################################
#
# Pre-definintion by RAONTECH.
#
############################################################################*/
=======
/**
 *
 * Pre-definintion by RAONTECH.
 *
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(RTV_IF_SPI) || defined(RTV_IF_EBI2)
	#ifndef RTV_FIC_POLLING_MODE
		#define RTV_FIC_SPI_INTR_ENABLED /* FIC SPI Interrupt use. */
	#endif
#else
	#if !defined(RTV_FIC_POLLING_MODE)\
	&& !defined(RTV_FIC__SCAN_TSIF__PLAY_NA)\
	&& !defined(RTV_FIC__SCAN_TSIF__PLAY_TSIF)
		#define RTV_FIC_I2C_INTR_ENABLED /* FIC I2C Interrupt use. */
	#endif
#endif

/* Defines the multiple channel mode if all ts data was xfered in play state */
#if	(\
		(defined(RTV_SPI_FIC_DECODE_IN_PLAY)\
|| defined(RTV_FIC__SCAN_I2C__PLAY_TSIF)\
		|| defined(RTV_FIC__SCAN_TSIF__PLAY_TSIF))\
	&&\
		(RTV_MAX_NUM_USE_SUBCHANNEL >= 1)\
	)

	#define RTV_MULTIPLE_CHANNEL_MODE
#endif

#if defined(RTV_IF_SPI) || defined(RTV_IF_EBI2)
	#define RTV_MCH_HEADER_SYNC_BYTE		0xE2
#else
	#define RTV_MCH_HEADER_SYNC_BYTE		0x47
#endif

<<<<<<< HEAD
/*############################################################################
#
# Defines the critical object and macros.
#
############################################################################*/
=======
/**
 *
 * Defines the critical object and macros.
 *
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(__KERNEL__)
extern struct mutex raontv_guard;
#define RTV_GUARD_INIT		mutex_init(&raontv_guard)
#define RTV_GUARD_LOCK		mutex_lock(&raontv_guard)
#define RTV_GUARD_FREE		mutex_unlock(&raontv_guard)
#define RTV_GUARD_DEINIT	((void)0)

#elif defined(WINCE) || defined(WINDOWS) || defined(WIN32)
extern CRITICAL_SECTION		raontv_guard;
#define RTV_GUARD_INIT		InitializeCriticalSection(&raontv_guard)
#define RTV_GUARD_LOCK		EnterCriticalSection(&raontv_guard)
#define RTV_GUARD_FREE		LeaveCriticalSection(&raontv_guard)
#define RTV_GUARD_DEINIT	DeleteCriticalSection(&raontv_guard)

#else
/* temp: TODO */
#define RTV_GUARD_INIT		((void)0)
#define RTV_GUARD_LOCK		((void)0)
#define RTV_GUARD_FREE		((void)0)
#define RTV_GUARD_DEINIT	((void)0)
#endif


<<<<<<< HEAD
/*############################################################################
#
# Check erros by user-configurations.
#
############################################################################*/
=======
/**
 *
 * Check erros by user-configurations.
 *
 */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if !defined(RTV_CHIP_PKG_CSP) && !defined(RTV_CHIP_PKG_QFN)
	#error "Must define the package type !"
#endif

#if defined(RTV_IF_TSIF) || defined(RTV_IF_SPI_SLAVE)\
|| defined(RTV_IF_SPI)
    #if (RTV_CHIP_ADDR >= 0xFF)
	#error "Invalid chip address"
    #endif

#elif defined(RTV_IF_EBI2)

#else
	#error "Must define the interface definition !"
#endif


#ifndef RTV_MAX_NUM_USE_SUBCHANNEL
	#error "Should be define number of subchannel!"
#endif

#if (RTV_MAX_NUM_USE_SUBCHANNEL <= 0) || (RTV_MAX_NUM_USE_SUBCHANNEL > 4)
	#error "Must from 0 to 4 for subchannel. TDMB(1ea), DAB(2ea), DABP(1ea)"
#endif

#if (RTV_MAX_NUM_USE_SUBCHANNEL >= 2)
	#ifndef RTV_MSC_HDR_ENABLED
		#error "Must define RTV_MSC_HDR_ENABLED definition"
	#endif
#endif

#if (RTV_MAX_NUM_USE_SUBCHANNEL == 0)
	#ifdef RTV_MSC_HDR_ENABLED
		#error "Must NOT define RTV_MSC_HDR_ENABLED definition"
	#endif
#endif


#if defined(RTV_IF_TSIF) || defined(RTV_IF_SPI_SLAVE)
	#if !defined(RTV_FIC__SCAN_I2C__PLAY_NA)\
	&& !defined(RTV_FIC__SCAN_I2C__PLAY_I2C)\
	&& !defined(RTV_FIC__SCAN_I2C__PLAY_TSIF)\
	&& !defined(RTV_FIC__SCAN_TSIF__PLAY_NA)\
	&& !defined(RTV_FIC__SCAN_TSIF__PLAY_I2C)\
	&& !defined(RTV_FIC__SCAN_TSIF__PLAY_TSIF)
		#error "No FIC path was defined for TSIF!"
	#endif

	#if defined(RTV_FIC__SCAN_I2C__PLAY_NA)\
		&& defined(RTV_FIC__SCAN_I2C__PLAY_I2C)\
		&& defined(RTV_FIC__SCAN_I2C__PLAY_TSIF)\
		&& defined(RTV_FIC__SCAN_TSIF__PLAY_NA)\
		&& defined(RTV_FIC__SCAN_TSIF__PLAY_I2C)\
		&& defined(RTV_FIC__SCAN_TSIF__PLAY_TSIF)
		#error "Should select only one FIC path for TSIF!"
	#endif
#endif


#ifndef RTV_TSP_XFER_SIZE
	#error "Must define the RTV_TSP_XFER_SIZE definition !"
#endif

#if (RTV_TSP_XFER_SIZE != 188) && (RTV_TSP_XFER_SIZE != 204)
	#error "Must 188 or 204 for TS size"
#endif


#if defined(RTV_IF_SPI) || defined(RTV_IF_EBI2)
	#ifdef RTV_MULTIPLE_CHANNEL_MODE
		#ifdef RTV_SPI_CIF_MODE_INTERRUPT_SIZE
			#if ((RTV_SPI_CIF_MODE_INTERRUPT_SIZE % 188) != 0)
				#error "Must multiple of 188"
			#endif
		#else
			#error "Should defined"
		#endif
	#endif

	#if defined(RTV_FIC_POLLING_MODE) && defined(RTV_SPI_FIC_DECODE_IN_PLAY)
		#error "Not support!"
	#endif
#endif

#if defined(RTV_IF_TSIF) || defined(RTV_IF_SPI_SLAVE)
#endif

int mtv319_assemble_fic(unsigned char *fic_buf, const unsigned char *ts_data,
			unsigned int ts_size);

void rtvOEM_PowerOn(int on);

#ifdef __cplusplus
}
#endif

#endif /* __MTV319_PORT_H__ */

