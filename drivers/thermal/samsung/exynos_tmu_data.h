/*
 * exynos_tmu_data.h - Samsung EXYNOS tmu data header file
 *
 *  Copyright (C) 2013 Samsung Electronics
 *  Amit Daniel Kachhap <amit.daniel@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef _EXYNOS_TMU_DATA_H
#define _EXYNOS_TMU_DATA_H

/* Exynos generic registers */
#define EXYNOS_TMU_REG_TRIMINFO		0x0
#define EXYNOS_TMU_REG_TRIMINFO1	0x4
#define EXYNOS_TMU_REG_CONTROL		0x20
#define EXYNOS_TMU_REG_CONTROL1		0x24
#define EXYNOS_TMU_REG_STATUS		0x28
#define EXYNOS_TMU_REG_CURRENT_TEMP	0x40
#define EXYNOS_TMU_REG_INTEN		0x70
#define EXYNOS_TMU_REG_INTSTAT		0x74
#define EXYNOS_TMU_REG_INTCLEAR		0x78

#define EXYNOS_TMU_REF_VOLTAGE_OTP_SHIFT	18
#define EXYNOS_TMU_REF_VOLTAGE_OTP_MASK		0x1F
#define EXYNOS_TMU_REF_VOLTAGE_OTP_MASK_3BIT	0x7
#define EXYNOS_TMU_REF_VOLTAGE_SHIFT		24
#define EXYNOS_TMU_REF_VOLTAGE_MASK		0x1f
#define EXYNOS_TMU_BUF_SLOPE_SEL_OTP_MASK	0xf
#define EXYNOS_TMU_BUF_SLOPE_SEL_OTP_MASK_3BIT	0x7
#define EXYNOS_TMU_BUF_SLOPE_SEL_OTP_SHIFT	18
#define EXYNOS_TMU_BUF_SLOPE_SEL_MASK		0xf
#define EXYNOS_TMU_BUF_SLOPE_SEL_SHIFT		8
#define EXYNOS_TMU_CORE_EN_SHIFT		0
#define EXYNOS_TMU_MUX_ADDR_SHIFT		20
#define EXYNOS_TMU_MUX_ADDR_MASK		0x5
#define EXYNOS_TMU_PTAT_CON_SHIFT		20
#define EXYNOS_TMU_PTAT_CON_MASK		0x7
#define EXYNOS_TMU_BUF_CONT_SHIFT		12
#define EXYNOS_TMU_BUF_CONT_MASK		0xf

/* Exynos3250 specific registers */
#define EXYNOS_TMU_TRIMINFO_CON1	0x10

/* Exynos4210 specific registers */
#define EXYNOS4210_TMU_REG_THRESHOLD_TEMP	0x44
#define EXYNOS4210_TMU_REG_TRIG_LEVEL0	0x50

/* Exynos5250, Exynos4412, Exynos3250 specific registers */
#define EXYNOS_TMU_TRIMINFO_CON2	0x14
#define EXYNOS_THD_TEMP_RISE		0x50
#define EXYNOS_THD_TEMP_FALL		0x54
#define EXYNOS_EMUL_CON		0x80

#define EXYNOS_TRIMINFO_25_SHIFT	0
#define EXYNOS_TRIMINFO_85_SHIFT	8
#define EXYNOS_TMU_TRIP_MODE_SHIFT	13
#define EXYNOS_TMU_TRIP_MODE_MASK	0x7
#define EXYNOS_TMU_THERM_TRIP_EN_SHIFT	12

#define EXYNOS_TMU_INTEN_RISE0_SHIFT	0
#define EXYNOS_TMU_INTEN_RISE1_SHIFT	4
#define EXYNOS_TMU_INTEN_RISE2_SHIFT	8
#define EXYNOS_TMU_INTEN_RISE3_SHIFT	12
#define EXYNOS_TMU_INTEN_FALL0_SHIFT	16

#define EXYNOS_EMUL_TIME	0x1
#define EXYNOS_EMUL_TIME_MASK	0xffff
#define EXYNOS_EMUL_TIME_SHIFT	16
#define EXYNOS_EMUL_DATA_SHIFT	8
#define EXYNOS_EMUL_DATA_MASK	0xFF
#define EXYNOS_EMUL_ENABLE	0x1

#define EXYNOS_MAX_TRIGGER_PER_REG	8

/* Exynos5260 specific */
#define EXYNOS5260_TMU_REG_INTEN		0xC0
#define EXYNOS5260_TMU_REG_INTSTAT		0xC4
#define EXYNOS5260_TMU_REG_INTCLEAR		0xC8
#define EXYNOS5260_EMUL_CON			0x100

/* Exynos4412 specific */
#define EXYNOS4412_MUX_ADDR_VALUE          6
#define EXYNOS4412_MUX_ADDR_SHIFT          20

/*exynos5440 specific registers*/
#define EXYNOS5440_TMU_S0_7_TRIM		0x000
#define EXYNOS5440_TMU_S0_7_CTRL		0x020
#define EXYNOS5440_TMU_S0_7_DEBUG		0x040
#define EXYNOS5440_TMU_S0_7_STATUS		0x060
#define EXYNOS5440_TMU_S0_7_TEMP		0x0f0
#define EXYNOS5440_TMU_S0_7_TH0			0x110
#define EXYNOS5440_TMU_S0_7_TH1			0x130
#define EXYNOS5440_TMU_S0_7_TH2			0x150
#define EXYNOS5440_TMU_S0_7_IRQEN		0x210
#define EXYNOS5440_TMU_S0_7_IRQ			0x230
/* exynos5440 common registers */
#define EXYNOS5440_TMU_IRQ_STATUS		0x000
#define EXYNOS5440_TMU_PMIN			0x004

#define EXYNOS5440_TMU_INTEN_RISE0_SHIFT	0
#define EXYNOS5440_TMU_INTEN_RISE1_SHIFT	1
#define EXYNOS5440_TMU_INTEN_RISE2_SHIFT	2
#define EXYNOS5440_TMU_INTEN_RISE3_SHIFT	3
#define EXYNOS5440_TMU_INTEN_FALL0_SHIFT	4
#define EXYNOS5440_TMU_TH_RISE4_SHIFT		24
#define EXYNOS5440_EFUSE_SWAP_OFFSET		8

#if defined(CONFIG_SOC_EXYNOS3250)
extern struct exynos_tmu_init_data const exynos3250_default_tmu_data;
#define EXYNOS3250_TMU_DRV_DATA (&exynos3250_default_tmu_data)
#else
#define EXYNOS3250_TMU_DRV_DATA (NULL)
#endif

/*exynos7580 specific registers*/
#define EXYNOS7580_TMU_RISE3_0                 0x50
#define EXYNOS7580_TMU_RISE7_4                 0x54
#define EXYNOS7580_TMU_TH_HW_TRIP_SHIFT		24

#define EXYNOS7580_TMU_FALL3_0                 0x60
#define EXYNOS7580_TMU_FALL7_4                 0x64

#define EXYNOS7580_TMU_REG_INTEN               0xC0
#define EXYNOS7580_TMU_REG_INTCLEAR            0xC8
#define EXYNOS7580_EMUL_CON                    0x110

#define EXYNOS7580_TMU_LPI0_MODE_EN_SHIFT	10

#define EXYNOS7580_TMU_VALID_P0			15

#define EXYNOS7580_TMU_INTEN_RISE0_SHIFT       0
#define EXYNOS7580_TMU_INTEN_RISE1_SHIFT       1
#define EXYNOS7580_TMU_INTEN_RISE2_SHIFT       2
#define EXYNOS7580_TMU_INTEN_RISE3_SHIFT       3
#define EXYNOS7580_TMU_INTEN_RISE4_SHIFT       4
#define EXYNOS7580_TMU_INTEN_RISE5_SHIFT       5
#define EXYNOS7580_TMU_INTEN_RISE6_SHIFT       6
#define EXYNOS7580_TMU_INTEN_RISE7_SHIFT       7
#define EXYNOS7580_TMU_INTEN_FALL0_SHIFT       16
#define EXYNOS7580_TMU_INTEN_FALL1_SHIFT       17
#define EXYNOS7580_TMU_INTEN_FALL2_SHIFT       18
#define EXYNOS7580_TMU_INTEN_FALL3_SHIFT       19
#define EXYNOS7580_TMU_INTEN_FALL4_SHIFT       20
#define EXYNOS7580_TMU_INTEN_FALL5_SHIFT       21
#define EXYNOS7580_TMU_INTEN_FALL6_SHIFT       22
#define EXYNOS7580_TMU_INTEN_FALL7_SHIFT       23

#define EXYNOS7580_TMU_RISE_INT_MASK   0xff
#define EXYNOS7580_TMU_RISE_INT_SHIFT  0
#define EXYNOS7580_TMU_FALL_INT_MASK   0xff
#define EXYNOS7580_TMU_FALL_INT_SHIFT  16

/* Define sensor type */
#define EXYNOS_TEM1456X			0x1
#define EXYNOS_TEM1455X			0x2

/*TEM1456X specific registers*/
#define EXYNOS_TEM1456X_TMU_TEMP_MASK		0x1ff
#define EXYNOS_TEM1456X_TRIMINFO_25_SHIFT	9
#define EXYNOS_TEM1456X_TRIMINFO_85_SHIFT	9
#define EXYNOS_TEM1456X_CALIB_SEL_SHIFT		23
#define EXYNOS_TEM1456X_CALIB_SEL_MASK		1
#define EXYNOS_TEM1456X_TMU_LPI0_MODE_EN_SHIFT	10

#define EXYNOS_TEM1456X_TMU_RISE6_7			0x50
#define EXYNOS_TEM1456X_TMU_RISE4_5			0x54
#define EXYNOS_TEM1456X_TMU_RISE2_3			0x58
#define EXYNOS_TEM1456X_TMU_RISE0_1			0x5C
#define EXYNOS_TEM1456X_TMU_TH_HW_TRIP_SHIFT		24

#define EXYNOS_TEM1456X_TMU_FALL6_7			0x60
#define EXYNOS_TEM1456X_TMU_FALL4_5			0x64
#define EXYNOS_TEM1456X_TMU_FALL2_3			0x68
#define EXYNOS_TEM1456X_TMU_FALL0_1			0x6C

#define EXYNOS_TEM1456X_TMU_REG_INTEN		0x110
#define EXYNOS_TEM1456X_TMU_REG_INTCLEAR		0x118

#define EXYNOS_TEM1456X_EMUL_CON			0x160
#define EXYNOS_TEM1456X_EMUL_DATA_SHIFT		7
#define EXYNOS_TEM1456X_EMUL_DATA_MASK		0x1FF

#define EXYNOS_TEM1456X_TMU_LPI0_MODE_EN_SHIFT	10
#define EXYNOS_TEM1456X_TMU_VALID_P0			15

#define EXYNOS_TEM1456X_TMU_INTEN_RISE0_SHIFT	0
#define EXYNOS_TEM1456X_TMU_INTEN_RISE1_SHIFT	1
#define EXYNOS_TEM1456X_TMU_INTEN_RISE2_SHIFT	2
#define EXYNOS_TEM1456X_TMU_INTEN_RISE3_SHIFT	3
#define EXYNOS_TEM1456X_TMU_INTEN_RISE4_SHIFT	4
#define EXYNOS_TEM1456X_TMU_INTEN_RISE5_SHIFT	5
#define EXYNOS_TEM1456X_TMU_INTEN_RISE6_SHIFT	6
#define EXYNOS_TEM1456X_TMU_INTEN_RISE7_SHIFT	7
#define EXYNOS_TEM1456X_TMU_INTEN_FALL0_SHIFT	16
#define EXYNOS_TEM1456X_TMU_INTEN_FALL1_SHIFT	17
#define EXYNOS_TEM1456X_TMU_INTEN_FALL2_SHIFT	18
#define EXYNOS_TEM1456X_TMU_INTEN_FALL3_SHIFT	19
#define EXYNOS_TEM1456X_TMU_INTEN_FALL4_SHIFT	20
#define EXYNOS_TEM1456X_TMU_INTEN_FALL5_SHIFT	21
#define EXYNOS_TEM1456X_TMU_INTEN_FALL6_SHIFT	22
#define EXYNOS_TEM1456X_TMU_INTEN_FALL7_SHIFT	23

#define EXYNOS_TEM1456X_TMU_RISE_INT_MASK		0xff
#define EXYNOS_TEM1456X_TMU_RISE_INT_SHIFT		0
#define EXYNOS_TEM1456X_TMU_FALL_INT_MASK		0xff
#define EXYNOS_TEM1456X_TMU_FALL_INT_SHIFT		16
#define EXYNOS_TEM1456X_VALID_MASK			0x1
#define EXYNOS_TEM1456X_VALID_P0_SHIFT		12
#define EXYNOS_TEM1456X_VALID_P1_SHIFT		13
#define EXYNOS_TEM1456X_VALID_P2_SHIFT		14
#define EXYNOS_TEM1456X_VALID_P3_SHIFT		15
#define EXYNOS_TEM1456X_VALID_P4_SHIFT		16

/*TEM1455X specific registers*/
#define EXYNOS_TEM1455X_MUX_ADDR_VALUE			0x0
#define EXYNOS_TEM1455X_TMU_TEMP_MASK         		0x1ff
#define EXYNOS_TEM1455X_TRIMINFO_25_SHIFT       	0
#define EXYNOS_TEM1455X_TRIMINFO_85_SHIFT       	9
#define EXYNOS_TEM1455X_CALIB_SEL_SHIFT         	23
#define EXYNOS_TEM1455X_CALIB_SEL_MASK          	1
#define EXYNOS_TEM1455X_TMU_LPI0_MODE_EN_SHIFT  	10

#define EXYNOS_TEM1455X_TMU_RISE6_7                     0x50
#define EXYNOS_TEM1455X_TMU_RISE4_5                     0x54
#define EXYNOS_TEM1455X_TMU_RISE2_3                     0x58
#define EXYNOS_TEM1455X_TMU_RISE0_1                     0x5C

#define EXYNOS_TEM1455X_TMU_FALL6_7                     0x60
#define EXYNOS_TEM1455X_TMU_FALL4_5                     0x64
#define EXYNOS_TEM1455X_TMU_FALL2_3                     0x68
#define EXYNOS_TEM1455X_TMU_FALL0_1                     0x6C

#define EXYNOS_TEM1455X_TMU_REG_INTEN        		0x110
#define EXYNOS_TEM1455X_TMU_REG_INTPEND   	        0x118
#define EXYNOS_TEM1455X_TMU_REG_INTCLEAR        	0x118

#define EXYNOS_TEM1455X_EMUL_CON                        0x160
#define EXYNOS_TEM1455X_EMUL_DATA_SHIFT         	7
#define EXYNOS_TEM1455X_EMUL_DATA_MASK          	0x1FF

#define EXYNOS_TEM1455X_TMU_LPI0_MODE_EN_SHIFT  	10
#define EXYNOS_TEM1455X_TMU_VALID_P0                    15

#define EXYNOS_TEM1455X_TMU_INTEN_RISE0_SHIFT   0
#define EXYNOS_TEM1455X_TMU_INTEN_RISE1_SHIFT   1
#define EXYNOS_TEM1455X_TMU_INTEN_RISE2_SHIFT   2
#define EXYNOS_TEM1455X_TMU_INTEN_RISE3_SHIFT   3
#define EXYNOS_TEM1455X_TMU_INTEN_RISE4_SHIFT   4
#define EXYNOS_TEM1455X_TMU_INTEN_RISE5_SHIFT   5
#define EXYNOS_TEM1455X_TMU_INTEN_RISE6_SHIFT   6
#define EXYNOS_TEM1455X_TMU_INTEN_RISE7_SHIFT   7
#define EXYNOS_TEM1455X_TMU_INTEN_FALL0_SHIFT   16
#define EXYNOS_TEM1455X_TMU_INTEN_FALL1_SHIFT   17
#define EXYNOS_TEM1455X_TMU_INTEN_FALL2_SHIFT   18
#define EXYNOS_TEM1455X_TMU_INTEN_FALL3_SHIFT   19
#define EXYNOS_TEM1455X_TMU_INTEN_FALL4_SHIFT   20
#define EXYNOS_TEM1455X_TMU_INTEN_FALL5_SHIFT   21
#define EXYNOS_TEM1455X_TMU_INTEN_FALL6_SHIFT   22
#define EXYNOS_TEM1455X_TMU_INTEN_FALL7_SHIFT   23

#define EXYNOS_TEM1455X_TMU_RISE_INT_MASK               0xff
#define EXYNOS_TEM1455X_TMU_RISE_INT_SHIFT              0
#define EXYNOS_TEM1455X_TMU_FALL_INT_MASK               0xff
#define EXYNOS_TEM1455X_TMU_FALL_INT_SHIFT              16
#define EXYNOS_TEM1455X_VALID_MASK                      0x1
#define EXYNOS_TEM1455X_VALID_P0_SHIFT          12
#define EXYNOS_TEM1455X_VALID_P1_SHIFT          13
#define EXYNOS_TEM1455X_VALID_P2_SHIFT          14
#define EXYNOS_TEM1455X_VALID_P3_SHIFT          15
#define EXYNOS_TEM1455X_VALID_P4_SHIFT          16

/* Define Exynos Global constant value */
#define		EXYNOS_MAX_TEMP		125
#define		EXYNOS_MIN_TEMP		10
#define		EXYNOS_COLD_TEMP	15


#if defined(CONFIG_CPU_EXYNOS4210)
extern struct exynos_tmu_init_data const exynos4210_default_tmu_data;
#define EXYNOS4210_TMU_DRV_DATA (&exynos4210_default_tmu_data)
#else
#define EXYNOS4210_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS4412)
extern struct exynos_tmu_init_data const exynos4412_default_tmu_data;
#define EXYNOS4412_TMU_DRV_DATA (&exynos4412_default_tmu_data)
#else
#define EXYNOS4412_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS5250)
extern struct exynos_tmu_init_data const exynos5250_default_tmu_data;
#define EXYNOS5250_TMU_DRV_DATA (&exynos5250_default_tmu_data)
#else
#define EXYNOS5250_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS5260)
extern struct exynos_tmu_init_data const exynos5260_default_tmu_data;
#define EXYNOS5260_TMU_DRV_DATA (&exynos5260_default_tmu_data)
#else
#define EXYNOS5260_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS5420)
extern struct exynos_tmu_init_data const exynos5420_default_tmu_data;
#define EXYNOS5420_TMU_DRV_DATA (&exynos5420_default_tmu_data)
#else
#define EXYNOS5420_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS5440)
extern struct exynos_tmu_init_data const exynos5440_default_tmu_data;
#define EXYNOS5440_TMU_DRV_DATA (&exynos5440_default_tmu_data)
#else
#define EXYNOS5440_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS7580)
extern struct exynos_tmu_init_data const exynos7580_default_tmu_data;
#define EXYNOS7580_TMU_DRV_DATA (&exynos7580_default_tmu_data)
#else
#define EXYNOS7580_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS8890)
extern struct exynos_tmu_init_data exynos8890_default_tmu_data;
#define EXYNOS8890_TMU_DRV_DATA (&exynos8890_default_tmu_data)
#else
#define EXYNOS8890_TMU_DRV_DATA (NULL)
#endif

#if defined(CONFIG_SOC_EXYNOS7870)
extern struct exynos_tmu_init_data exynos7870_default_tmu_data;
#define EXYNOS7870_TMU_DRV_DATA (&exynos7870_default_tmu_data)
#else
#define EXYNOS7870_TMU_DRV_DATA (NULL)
#endif
<<<<<<< HEAD

#if defined(CONFIG_SOC_EXYNOS7570)
extern struct exynos_tmu_init_data exynos7570_default_tmu_data;
#define EXYNOS7570_TMU_DRV_DATA (&exynos7570_default_tmu_data)
#else
#define EXYNOS7570_TMU_DRV_DATA (NULL)
#endif
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif /*_EXYNOS_TMU_DATA_H*/
