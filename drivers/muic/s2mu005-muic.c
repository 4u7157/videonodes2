/*
 * driver/misc/s2mu005.c - S2MU005 micro USB switch device driver
 *
 * Copyright (C) 2015 Samsung Electronics
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/delay.h>
<<<<<<< HEAD
#include <linux/wakelock.h>
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#include <linux/muic/muic.h>
#include <linux/mfd/samsung/s2mu005.h>
#include <linux/mfd/samsung/s2mu005-private.h>
#include <linux/muic/s2mu005-muic.h>

#if defined(CONFIG_MUIC_NOTIFIER)
#include <linux/muic/muic_notifier.h>
#endif /* CONFIG_MUIC_NOTIFIER */

#if defined(CONFIG_VBUS_NOTIFIER)
#include <linux/vbus_notifier.h>
#endif /* CONFIG_VBUS_NOTIFIER */

#if defined(CONFIG_MUIC_UART_SWITCH)
#include <mach/pinctrl-samsung.h>
#endif

<<<<<<< HEAD
#define GPIO_LEVEL_HIGH		1
#define GPIO_LEVEL_LOW		0

static void s2mu005_muic_handle_attach(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev, int adc, u8 vbvolt);
static void s2mu005_muic_handle_detach(struct s2mu005_muic_data *muic_data);
=======
static void s2mu005_muic_handle_attach(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev, int adc, u8 vbvolt);
static void s2mu005_muic_handle_detach(struct s2mu005_muic_data *muic_data);
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
static void s2mu005_muic_set_water_wa(struct s2mu005_muic_data *muic_data, bool en);
static int s2mu005_i2c_update_bit(struct i2c_client *i2c,
			u8 reg, u8 mask, u8 shift, u8 value);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

/*
#define DEBUG_MUIC
*/

#if defined(DEBUG_MUIC)
#define MAX_LOG 25
#define READ 0
#ifndef WRITE
#define WRITE 1
#endif

static u8 s2mu005_log_cnt;
static u8 s2mu005_log[MAX_LOG][3];

<<<<<<< HEAD
static int s2mu005_i2c_read_byte(struct i2c_client *client, u8 command);
static int s2mu005_i2c_write_byte(struct i2c_client *client,
			u8 command, u8 value);

=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void s2mu005_reg_log(u8 reg, u8 value, u8 rw)
{
	s2mu005_log[s2mu005_log_cnt][0] = reg;
	s2mu005_log[s2mu005_log_cnt][1] = value;
	s2mu005_log[s2mu005_log_cnt][2] = rw;
	s2mu005_log_cnt++;
	if (s2mu005_log_cnt >= MAX_LOG)
		s2mu005_log_cnt = 0;
}
static void s2mu005_print_reg_log(void)
{
	int i;
	u8 reg, value, rw;
	char mesg[256] = "";

	for (i = 0; i < MAX_LOG; i++) {
		reg = s2mu005_log[s2mu005_log_cnt][0];
		value = s2mu005_log[s2mu005_log_cnt][1];
		rw = s2mu005_log[s2mu005_log_cnt][2];
		s2mu005_log_cnt++;

		if (s2mu005_log_cnt >= MAX_LOG)
			s2mu005_log_cnt = 0;
		sprintf(mesg+strlen(mesg), "%x(%x)%x ", reg, value, rw);
	}
<<<<<<< HEAD
	pr_info("%s:%s\n", __func__, mesg);
=======
	pr_info("%s:%s:%s\n", MUIC_DEV_NAME, __func__, mesg);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}
void s2mu005_read_reg_dump(struct s2mu005_muic_data *muic, char *mesg)
{
	u8 val;

	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_CTRL1, &val);
	sprintf(mesg+strlen(mesg), "CTRL1:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_SW_CTRL, &val);
	sprintf(mesg+strlen(mesg), "SW_CTRL:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_INT1_MASK, &val);
	sprintf(mesg+strlen(mesg), "IM1:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_INT2_MASK, &val);
	sprintf(mesg+strlen(mesg), "IM2:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_CHG_TYPE, &val);
	sprintf(mesg+strlen(mesg), "CHG_T:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_DEVICE_APPLE, &val);
	sprintf(mesg+strlen(mesg), "APPLE_DT:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_ADC, &val);
	sprintf(mesg+strlen(mesg), "ADC:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_DEVICE_TYPE1, &val);
	sprintf(mesg+strlen(mesg), "DT1:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_DEVICE_TYPE2, &val);
	sprintf(mesg+strlen(mesg), "DT2:%x ", val);
	s2mu005_read_reg(muic->i2c, S2MU005_REG_MUIC_DEVICE_TYPE3, &val);
	sprintf(mesg+strlen(mesg), "DT3:%x ", val);
}
void s2mu005_print_reg_dump(struct s2mu005_muic_data *muic_data)
{
	char mesg[256] = "";

	s2mu005_read_reg_dump(muic_data, mesg);

<<<<<<< HEAD
	pr_info("%s:%s\n", __func__, mesg);
=======
	pr_info("%s:%s:%s\n", MUIC_DEV_NAME, __func__, mesg);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}
#endif

static int s2mu005_i2c_read_byte(struct i2c_client *client, u8 command)
{
	u8 ret;
	int retry = 0;

	s2mu005_read_reg(client, command, &ret);

	while (ret < 0) {
<<<<<<< HEAD
		pr_err("[muic] %s: reg(0x%x), retrying...\n",
			__func__, command);
		if (retry > 10) {
			pr_err("[muic] %s: retry failed!!\n", __func__);
=======
		pr_err("%s:%s: reg(0x%x), retrying...\n", MUIC_DEV_NAME, __func__, command);
		if (retry > 5) {
			pr_err("%s:%s: retry failed!!\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			break;
		}
		msleep(100);
		s2mu005_read_reg(client, command, &ret);
		retry++;
	}

#ifdef DEBUG_MUIC
	s2mu005_reg_log(command, ret, retry << 1 | READ);
#endif
	return ret;
}
<<<<<<< HEAD
=======

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static int s2mu005_i2c_write_byte(struct i2c_client *client,
			u8 command, u8 value)
{
	int ret;
	int retry = 0;
	u8 written = 0;

	ret = s2mu005_write_reg(client, command, value);

	while (ret < 0) {
<<<<<<< HEAD
		pr_err("[muic] %s: reg(0x%x), retrying...\n",
			__func__, command);
		s2mu005_read_reg(client, command, &written);
		if (written < 0)
			pr_err("[muic] %s: reg(0x%x)\n",
				__func__, command);
		msleep(100);
=======
		pr_err("%s:%s: reg(0x%x), retrying...\n", MUIC_DEV_NAME, __func__, command);
		if (retry > 5) { 
			pr_err("%s:%s: retry failed!!\n", MUIC_DEV_NAME, __func__);
			break;
		}
		msleep(100);
		s2mu005_read_reg(client, command, &written);
		if (written < 0)
			pr_err("%s:%s: reg(0x%x)\n", MUIC_DEV_NAME, __func__, command);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		ret = s2mu005_write_reg(client, command, value);
		retry++;
	}
#ifdef DEBUG_MUIC
	s2mu005_reg_log(command, value, retry << 1 | WRITE);
#endif
	return ret;
}
<<<<<<< HEAD
static int s2mu005_i2c_guaranteed_wbyte(struct i2c_client *client,
			u8 command, u8 value)
{
	int ret;
	int retry = 0;
	int written;

	ret = s2mu005_i2c_write_byte(client, command, value);
	written = s2mu005_i2c_read_byte(client, command);

	while (written != value) {
		pr_err("[muic] reg(0x%x): written(0x%x) != value(0x%x)\n",
			command, written, value);
		if (retry > 10) {
			pr_err("[muic] %s: retry failed!!\n", __func__);
			break;
		}
		msleep(100);
		retry++;
		ret = s2mu005_i2c_write_byte(client, command, value);
		written = s2mu005_i2c_read_byte(client, command);
	}
	return ret;
}

#if defined(GPIO_USB_SEL)
static int s2mu005_set_gpio_usb_sel(int uart_sel)
{
	return 0;
}
#endif /* GPIO_USB_SEL */

static int s2mu005_set_gpio_uart_sel(int uart_sel)
{
	const char *mode;
#if !defined(CONFIG_MUIC_UART_SWITCH)
	int uart_sel_gpio = muic_pdata.gpio_uart_sel;
	int uart_sel_val;
	int ret;

	ret = gpio_request(uart_sel_gpio, "GPIO_UART_SEL");
	if (ret) {
		pr_err("[muic] failed to gpio_request GPIO_UART_SEL\n");
		return ret;
	}

	uart_sel_val = gpio_get_value(uart_sel_gpio);

	switch (uart_sel) {
	case MUIC_PATH_UART_AP:
		mode = "AP_UART";
		if (gpio_is_valid(uart_sel_gpio))
			gpio_direction_output(uart_sel_gpio, 1);
		break;
	case MUIC_PATH_UART_CP:
		mode = "CP_UART";
		if (gpio_is_valid(uart_sel_gpio))
			gpio_direction_output(uart_sel_gpio, 0);
		break;
	default:
		mode = "Error";
		break;
	}

	uart_sel_val = gpio_get_value(uart_sel_gpio);

	gpio_free(uart_sel_gpio);

	pr_err("[muic] %s, GPIO_UART_SEL(%d)=%c\n",
		mode, uart_sel_gpio, (uart_sel_val == 0 ? 'L' : 'H'));
#else
	switch (uart_sel) {
	case MUIC_PATH_UART_AP:
		mode = "AP_UART";
		pin_config_set(muic_pdata.uart_addr, muic_pdata.uart_rxd,
					PINCFG_PACK(PINCFG_TYPE_FUNC, 0x2));
		pin_config_set(muic_pdata.uart_addr, muic_pdata.uart_txd,
					PINCFG_PACK(PINCFG_TYPE_FUNC, 0x2));
		break;
	case MUIC_PATH_UART_CP:
		mode = "CP_UART";
		pin_config_set(muic_pdata.uart_addr, muic_pdata.uart_rxd,
					PINCFG_PACK(PINCFG_TYPE_FUNC, 0x3));
		pin_config_set(muic_pdata.uart_addr, muic_pdata.uart_txd,
					PINCFG_PACK(PINCFG_TYPE_FUNC, 0x3));
		break;
	default:
		mode = "Error";
		break;
	}

	printk(KERN_DEBUG "[muic] %s %s\n", __func__, mode);
#endif
	return 0;
}
=======

#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
static int s2mu005_i2c_update_bit(struct i2c_client *i2c,
			u8 reg, u8 mask, u8 shift, u8 value)
{
	int ret;
	u8 reg_val = 0;

	reg_val = s2mu005_i2c_read_byte(i2c, reg);
	reg_val &= ~mask;
	reg_val |= value << shift;
	ret = s2mu005_i2c_write_byte(i2c, reg, reg_val);
	pr_info("[update_bit:%s] reg(0x%x):  value(0x%x)\n", __func__, reg, reg_val);
	if (ret < 0) {
		pr_err("%s: Reg = 0x%X, mask = 0x%X, val = 0x%X write err : %d\n",
				__func__, reg, mask, value, ret);
	}

	return ret;
}
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#if defined(GPIO_DOC_SWITCH)
static int s2mu005_set_gpio_doc_switch(int val)
{
	int doc_switch_gpio = muic_pdata.gpio_doc_switch;
	int doc_switch_val;
	int ret;

	ret = gpio_request(doc_switch_gpio, "GPIO_DOC_SWITCH");
	if (ret) {
<<<<<<< HEAD
		pr_err("[muic] failed to gpio_request GPIO_DOC_SWITCH\n");
=======
		pr_err("%s:%s: failed to gpio_request GPIO_DOC_SWITCH\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return ret;
	}

	doc_switch_val = gpio_get_value(doc_switch_gpio);

	if (gpio_is_valid(doc_switch_gpio))
			gpio_set_value(doc_switch_gpio, val);

	doc_switch_val = gpio_get_value(doc_switch_gpio);

	gpio_free(doc_switch_gpio);

<<<<<<< HEAD
	pr_err("[muic] GPIO_DOC_SWITCH(%d)=%c\n",
		doc_switch_gpio, (doc_switch_val == 0 ? 'L' : 'H'));
=======
	pr_info("%s:%s: GPIO_DOC_SWITCH(%d)=%c\n",
		MUIC_DEV_NAME, __func__, doc_switch_gpio, (doc_switch_val == 0 ? 'L' : 'H'));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return 0;
}
#endif /* GPIO_DOC_SWITCH */

<<<<<<< HEAD
#ifdef CONFIG_SEC_FACTORY
=======
#if defined (CONFIG_SEC_FACTORY) && defined (CONFIG_USB_HOST_NOTIFY)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static int set_otg_reg(struct s2mu005_muic_data *muic_data, bool on)
{
	struct i2c_client *i2c = muic_data->i2c;
	u8 reg_val;
	int ret = 0;

	/* 0x1e : hidden register */
	ret = s2mu005_i2c_read_byte(i2c, 0x1e);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 0x1e reg(%d)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 0x1e reg(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* Set 0x1e[5:4] bit to 0x11 or 0x01 */
	if (on)
		reg_val = ret | (0x1 << 5);
	else
		reg_val = ret & ~(0x1 << 5);

	if (reg_val ^ ret) {
<<<<<<< HEAD
		pr_err("[muic] %s 0x%x != 0x%x, update\n", __func__, reg_val, ret);

		ret = s2mu005_i2c_guaranteed_wbyte(i2c, 0x1e, reg_val);
		if (ret < 0)
			pr_err("[muic] %s err write(%d)\n", __func__, ret);
	} else {
		pr_err("[muic] %s 0x%x == 0x%x, just return\n", __func__, reg_val, ret);
=======
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__, reg_val, ret);

		ret = s2mu005_i2c_write_byte(i2c, 0x1e, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write(%d)\n", MUIC_DEV_NAME, __func__, ret);
	} else {
		pr_info("%s:%s: 0x%x == 0x%x, just return\n", MUIC_DEV_NAME, __func__, reg_val, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, 0x1e);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read reg 0x1e(%d)\n", __func__, ret);
	else
		pr_err("[muic] %s after change(0x%x)\n", __func__, ret);
=======
		pr_err("%s:%s: err read reg 0x1e(%d)\n", MUIC_DEV_NAME, __func__, ret);
	else
		pr_info("%s:%s: after change(0x%x)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

static int init_otg_reg(struct s2mu005_muic_data *muic_data)
{
	struct i2c_client *i2c = muic_data->i2c;
	u8 reg_val;
	int ret = 0;

	/* 0x73 : check EVT0 or EVT1 */
	ret = s2mu005_i2c_read_byte(i2c, 0x73);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 'reg 0x73'(%d)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 'reg 0x73'(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if ((ret&0xF) > 0)
		return 0;

	/* 0x89 : hidden register */
	ret = s2mu005_i2c_read_byte(i2c, 0x89);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 'reg 0x89'(%d)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 'reg 0x89'(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* Set 0x89[1] bit : T_DET_VAL */
	reg_val = ret | (0x1 << 1);

	if (reg_val ^ ret) {
<<<<<<< HEAD
		pr_err("[muic] %s 0x%x != 0x%x, update\n", __func__, reg_val, ret);

		ret = s2mu005_i2c_guaranteed_wbyte(i2c, 0x89, reg_val);
		if (ret < 0)
			pr_err("[muic] %s err write(%d)\n", __func__, ret);
	} else {
		pr_err("[muic] %s 0x%x == 0x%x, just return\n", __func__, reg_val, ret);
=======
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__, reg_val, ret);

		ret = s2mu005_i2c_write_byte(i2c, 0x89, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write(%d)\n", MUIC_DEV_NAME, __func__, ret);
	} else {
		pr_info("%s:%s: 0x%x == 0x%x, just return\n", MUIC_DEV_NAME, __func__, reg_val, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, 0x89);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 'reg 0x89'(%d)\n", __func__, ret);
	else
		pr_err("[muic] %s after change(0x%x)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 'reg 0x89'(%d)\n", MUIC_DEV_NAME, __func__, ret);
	else
		pr_info("%s:%s: after change(0x%x)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* 0x92 : hidden register */
	ret = s2mu005_i2c_read_byte(i2c, 0x92);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 'reg 0x92'(%d)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 'reg 0x92'(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* Set 0x92[7] bit : EN_JIG_AP */
	reg_val = ret | (0x1 << 7);

	if (reg_val ^ ret) {
<<<<<<< HEAD
		pr_err("[muic] %s 0x%x != 0x%x, update\n", __func__, reg_val, ret);

		ret = s2mu005_i2c_guaranteed_wbyte(i2c, 0x92, reg_val);
		if (ret < 0)
			pr_err("[muic] %s err write(%d)\n", __func__, ret);
	} else {
		pr_err("[muic] %s 0x%x == 0x%x, just return\n",	__func__, reg_val, ret);
=======
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__, reg_val, ret);

		ret = s2mu005_i2c_write_byte(i2c, 0x92, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write(%d)\n", MUIC_DEV_NAME, __func__, ret);
	} else {
		pr_info("%s:%s: 0x%x == 0x%x, just return\n", MUIC_DEV_NAME, __func__, reg_val, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, 0x92);
	if (ret < 0)
<<<<<<< HEAD
		pr_err("[muic] %s err read 'reg 0x92'(%d)\n", __func__, ret);
	else
		pr_err("[muic] %s after change(0x%x)\n", __func__, ret);
=======
		pr_err("%s:%s: err read 'reg 0x92'(%d)\n", MUIC_DEV_NAME, __func__, ret);
	else
		pr_info("%s:%s: after change(0x%x)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}
#endif

<<<<<<< HEAD
static int s2mu005_muic_jig_on(struct s2mu005_muic_data *muic_data)
{
	bool en = muic_data->is_jig_on;
	int reg = 0;

	pr_err("[muic] %s: %s\n", __func__, en ? "on" : "off");

	reg = s2mu005_i2c_read_byte(muic_data->i2c,
		S2MU005_REG_MUIC_SW_CTRL);

	if (en)
		reg |= MANUAL_SW_JIG_EN;
	else
		reg &= ~(MANUAL_SW_JIG_EN);

	return s2mu005_i2c_write_byte(muic_data->i2c,
		S2MU005_REG_MUIC_SW_CTRL, (u8)reg);
=======
static int set_jig_sw(struct s2mu005_muic_data *muic_data, bool en)
{
	struct i2c_client *i2c = muic_data->i2c;
	bool cur = false;
	int reg_val = 0, ret = 0;

	reg_val = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	if (reg_val < 0)
		pr_err("%s:%s failed to read 0x%x\n", MUIC_DEV_NAME, __func__, reg_val);

	cur = !!(reg_val & MANUAL_SW_JIG_EN);

	if (!muic_data->jigonb_enable)
		en = false;

	if (en != cur) {
		pr_info("%s:%s  0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__,
			reg_val, reg_val);

		if (en)
			reg_val |= (MANUAL_SW_JIG_EN);
		else
			reg_val &= ~(MANUAL_SW_JIG_EN);

		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_SW_CTRL, reg_val);
		if (ret < 0)
			pr_err("%s:%s failed to write 0x%x\n", MUIC_DEV_NAME, __func__, reg_val);
	}

	return ret;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static ssize_t s2mu005_muic_show_uart_en(struct device *dev,
						struct device_attribute *attr, char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int ret = 0;

	if (!muic_data->is_rustproof) {
<<<<<<< HEAD
		pr_err("[muic] %s UART ENABLE\n",  __func__);
		ret = sprintf(buf, "1\n");
	} else {
		pr_err("[muic] %s UART DISABLE\n",  __func__);
=======
		pr_info("%s:%s: UART ENABLE\n", MUIC_DEV_NAME, __func__);
		ret = sprintf(buf, "1\n");
	} else {
		pr_info("%s:%s: UART DISABLE\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		ret = sprintf(buf, "0\n");
	}

	return ret;
}

static ssize_t s2mu005_muic_set_uart_en(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	if (!strncmp(buf, "1", 1))
		muic_data->is_rustproof = false;
	else if (!strncmp(buf, "0", 1))
		muic_data->is_rustproof = true;
	else
<<<<<<< HEAD
		pr_err("[muic] %s invalid value\n",  __func__);

	pr_err("[muic] %s uart_en(%d)\n",
		__func__, !muic_data->is_rustproof);

	return count;
}

static ssize_t s2mu005_muic_show_uart_sel(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	struct muic_platform_data *pdata = muic_data->pdata;
	int ret = 0;

	switch (pdata->uart_path) {
	case MUIC_PATH_UART_AP:
		pr_err("[muic] %s AP\n",  __func__);
		ret = sprintf(buf, "AP\n");
		break;
	case MUIC_PATH_UART_CP:
		pr_err("[muic] %s CP\n",  __func__);
		ret = sprintf(buf, "CP\n");
		break;
	default:
		pr_err("[muic] %s UNKNOWN\n",  __func__);
		ret = sprintf(buf, "UNKNOWN\n");
		break;
	}

	return ret;
}

static int switch_to_ap_uart(struct s2mu005_muic_data *muic_data);
static int switch_to_cp_uart(struct s2mu005_muic_data *muic_data);

static ssize_t s2mu005_muic_set_uart_sel(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	struct muic_platform_data *pdata = muic_data->pdata;

	if (!strncasecmp(buf, "AP", 2)) {
		pdata->uart_path = MUIC_PATH_UART_AP;
		switch_to_ap_uart(muic_data);
	} else if (!strncasecmp(buf, "CP", 2)) {
		pdata->uart_path = MUIC_PATH_UART_CP;
		switch_to_cp_uart(muic_data);
	} else
		pr_err("[muic] %s invalid value\n",  __func__);

	pr_err("[muic] %s uart_path(%d)\n",
		__func__, pdata->uart_path);

	return count;
}

static ssize_t s2mu005_muic_show_usb_sel(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	struct muic_platform_data *pdata = muic_data->pdata;

	switch (pdata->usb_path) {
	case MUIC_PATH_USB_AP:
		return sprintf(buf, "PDA\n");
	case MUIC_PATH_USB_CP:
		return sprintf(buf, "MODEM\n");
	default:
		break;
	}

	pr_err("[muic] %s UNKNOWN\n",  __func__);
	return sprintf(buf, "UNKNOWN\n");
}

static ssize_t s2mu005_muic_set_usb_sel(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	struct muic_platform_data *pdata = muic_data->pdata;

	if (!strncasecmp(buf, "PDA", 3))
		pdata->usb_path = MUIC_PATH_USB_AP;
	else if (!strncasecmp(buf, "MODEM", 5))
		pdata->usb_path = MUIC_PATH_USB_CP;
	else
		pr_err("[muic] %s invalid value\n", __func__);

	pr_err("[muic] %s usb_path(%d)\n",
		__func__, pdata->usb_path);
=======
		pr_info("%s:%s: invalid value\n", MUIC_DEV_NAME, __func__);

	pr_info("%s:%s: uart_en(%d)\n", MUIC_DEV_NAME, __func__, !muic_data->is_rustproof);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t s2mu005_muic_show_usb_en(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	return sprintf(buf, "%s:%s attached_dev = %d\n",
		MUIC_DEV_NAME, __func__, muic_data->attached_dev);
}

=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static ssize_t s2mu005_muic_set_usb_en(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	muic_attached_dev_t new_dev = ATTACHED_DEV_USB_MUIC;

	if (!strncasecmp(buf, "1", 1))
		s2mu005_muic_handle_attach(muic_data, new_dev, 0, 0);
	else if (!strncasecmp(buf, "0", 1))
		s2mu005_muic_handle_detach(muic_data);
	else
<<<<<<< HEAD
		pr_err("[muic] %s invalid value\n", __func__);

	pr_err("[muic] %s attached_dev(%d)\n",
		__func__, muic_data->attached_dev);
=======
		pr_info("%s:%s: invalid value\n", MUIC_DEV_NAME, __func__);

	pr_info("%s:%s: attached_dev(%d)\n", MUIC_DEV_NAME, __func__, muic_data->attached_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

static ssize_t s2mu005_muic_show_adc(struct device *dev,
				      struct device_attribute *attr, char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int ret;

	mutex_lock(&muic_data->muic_mutex);
	ret = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_ADC);
	mutex_unlock(&muic_data->muic_mutex);
	if (ret < 0) {
<<<<<<< HEAD
		pr_err("[muic] %s err read adc reg(%d)\n",
			__func__, ret);
=======
		pr_err("%s:%s: err read adc reg(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "UNKNOWN\n");
	}

	return sprintf(buf, "%x\n", (ret & ADC_MASK));
}

static ssize_t s2mu005_muic_show_usb_state(struct device *dev,
					    struct device_attribute *attr,
					    char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	static unsigned long swtich_slot_time;

	if (printk_timed_ratelimit(&swtich_slot_time, 5000))
<<<<<<< HEAD
		pr_err("[muic] %s muic_data->attached_dev(%d)\n",
			__func__, muic_data->attached_dev);
=======
		pr_info("%s:%s: muic_data->attached_dev(%d)\n",
			MUIC_DEV_NAME, __func__, muic_data->attached_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		return sprintf(buf, "USB_STATE_CONFIGURED\n");
	default:
		break;
	}

	return 0;
}

#ifdef DEBUG_MUIC
static ssize_t s2mu005_muic_show_mansw(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int ret;

	mutex_lock(&muic_data->muic_mutex);
	ret = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_SW_CTRL);
	mutex_unlock(&muic_data->muic_mutex);

<<<<<<< HEAD
	pr_info("func:%s ret:%d buf%s\n", __func__, ret, buf);

	if (ret < 0) {
		pr_err("%s: fail to read muic reg\n", __func__);
=======
	pr_info("%s:%s: ret:%d buf%s\n", MUIC_DEV_NAME, __func__, ret, buf);

	if (ret < 0) {
		pr_err("%s:%s: fail to read muic reg\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "UNKNOWN\n");
	}
	return sprintf(buf, "0x%x\n", ret);
}
static ssize_t s2mu005_muic_show_interrupt_status(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int st1, st2;

	mutex_lock(&muic_data->muic_mutex);
	st1 = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_INT1);
	st2 = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_INT2);
	mutex_unlock(&muic_data->muic_mutex);

<<<<<<< HEAD
	pr_info("func:%s st1:0x%x st2:0x%x buf%s\n", __func__, st1, st2, buf);

	if (st1 < 0 || st2 < 0) {
		pr_err("%s: fail to read muic reg\n", __func__);
=======
	pr_info("%s:%s: st1:0x%x st2:0x%x buf%s\n", MUIC_DEV_NAME, __func__, st1, st2, buf);

	if (st1 < 0 || st2 < 0) {
		pr_err("%s:%s: fail to read muic reg\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "UNKNOWN\n");
	}
	return sprintf(buf, "st1:0x%x st2:0x%x\n", st1, st2);
}
static ssize_t s2mu005_muic_show_registers(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	char mesg[256] = "";

	mutex_lock(&muic_data->muic_mutex);
	s2mu005_read_reg_dump(muic_data, mesg);
	mutex_unlock(&muic_data->muic_mutex);
<<<<<<< HEAD
	pr_info("%s:%s\n", __func__, mesg);
=======
	pr_info("%s:%s: %s\n", MUIC_DEV_NAME, __func__, mesg);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return sprintf(buf, "%s\n", mesg);
}

#endif

#if defined(CONFIG_USB_HOST_NOTIFY)
static ssize_t s2mu005_muic_show_otg_test(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int ret;
	u8 val = 0;

	mutex_lock(&muic_data->muic_mutex);
	ret = s2mu005_i2c_read_byte(muic_data->i2c,
		S2MU005_REG_MUIC_INT2_MASK);
	mutex_unlock(&muic_data->muic_mutex);

	if (ret < 0) {
<<<<<<< HEAD
		pr_err("[muic] %s: fail to read muic reg\n", __func__);
		return sprintf(buf, "UNKNOWN\n");
	}

	pr_err("[muic] func:%s ret:%d val:%x buf%s\n",
		__func__, ret, val, buf);
=======
		pr_err("%s:%s: fail to read muic reg\n", MUIC_DEV_NAME, __func__);
		return sprintf(buf, "UNKNOWN\n");
	}

	pr_info("%s:%s: ret:%d val:%x buf%s\n", MUIC_DEV_NAME, __func__, ret, val, buf);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	val &= INT_VBUS_ON_MASK;
	return sprintf(buf, "%x\n", val);
}

static ssize_t s2mu005_muic_set_otg_test(struct device *dev,
		struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

<<<<<<< HEAD
	pr_err("[muic] %s buf:%s\n", __func__, buf);
=======
	pr_info("%s:%s: buf:%s\n", MUIC_DEV_NAME, __func__, buf);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/*
	*	The otg_test is set 0 durring the otg test. Not 1 !!!
	*/

	if (!strncmp(buf, "0", 1)) {
		muic_data->is_otg_test = 1;
#ifdef CONFIG_SEC_FACTORY
		set_otg_reg(muic_data, 1);
#endif
<<<<<<< HEAD
	} else if (!strncmp(buf, "1", 1)) {
=======
	}
	else if (!strncmp(buf, "1", 1)) {
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		muic_data->is_otg_test = 0;
#ifdef CONFIG_SEC_FACTORY
		set_otg_reg(muic_data, 0);
#endif
<<<<<<< HEAD
	} else {
		pr_err("[muic] %s Wrong command\n", __func__);
=======
	}
	else {
		pr_info("%s:%s: Wrong command\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return count;
	}

	return count;
}
#endif

<<<<<<< HEAD
=======
static ssize_t s2mu005_muic_show_usb_en(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
		struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

		return sprintf(buf, "%s:%s attached_dev = %d\n",
						MUIC_DEV_NAME, __func__, muic_data->attached_dev);
}

static ssize_t s2mu005_muic_jig_disable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	if (muic_data->jig_disable)
		return sprintf(buf, "DISABLE\n");
	else
		return sprintf(buf, "ENABLE\n");
}

static ssize_t s2mu005_muic_jig_disable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	pr_info("%s:%s : %s\n", MUIC_DEV_NAME, __func__, buf);
	if (!strncasecmp(buf, "DISABLE", 7)) {
		muic_data->jig_disable = true;
		set_jig_sw(muic_data, false);
	} else {
		muic_data->jig_disable = false;
		set_jig_sw(muic_data, true);
	}

	return count;
}

#if defined(CONFIG_NEW_FACTORY_UART)
static ssize_t factory_uart_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	if (muic_data->pdata->is_factory_uart)
		return sprintf(buf, "ENABLE\n");
	else
		return sprintf(buf, "DISABLE\n");
}

static ssize_t factory_uart_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	pr_info("%s : %s\n", __func__, buf);
	if (!strncasecmp(buf, "ENABLE", 6)) {
		muic_data->pdata->is_factory_uart = true;
		set_jig_sw(muic_data, false);
	} else {
		muic_data->pdata->is_factory_uart = false;
		set_jig_sw(muic_data, true);
	}

	return count;
}
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static ssize_t s2mu005_muic_show_attached_dev(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

<<<<<<< HEAD
	pr_err("[muic] %s :%d\n",
		__func__, muic_data->attached_dev);
=======
	pr_info("%s:%s: attached_dev[%d]\n", MUIC_DEV_NAME, __func__, muic_data->attached_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_NONE_MUIC:
		return sprintf(buf, "No VPS\n");
	case ATTACHED_DEV_USB_MUIC:
		return sprintf(buf, "USB\n");
	case ATTACHED_DEV_CDP_MUIC:
		return sprintf(buf, "CDP\n");
	case ATTACHED_DEV_OTG_MUIC:
		return sprintf(buf, "OTG\n");
	case ATTACHED_DEV_TA_MUIC:
		return sprintf(buf, "TA\n");
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
		return sprintf(buf, "JIG UART OFF\n");
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
		return sprintf(buf, "JIG UART OFF/VB\n");
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
		return sprintf(buf, "JIG UART ON\n");
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
		return sprintf(buf, "JIG USB OFF\n");
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		return sprintf(buf, "JIG USB ON\n");
	case ATTACHED_DEV_DESKDOCK_MUIC:
<<<<<<< HEAD
		return sprintf(buf, "DESKDOCK\n");
	case ATTACHED_DEV_AUDIODOCK_MUIC:
		return sprintf(buf, "AUDIODOCK\n");
=======
	case ATTACHED_DEV_DESKDOCK_VB_MUIC:
		return sprintf(buf, "DESKDOCK\n");
	case ATTACHED_DEV_CHARGING_CABLE_MUIC:
		return sprintf(buf, "PS CABLE\n");
	case ATTACHED_DEV_FACTORY_UART_MUIC:
		return sprintf(buf, "FACTORY UART\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	default:
		break;
	}

	return sprintf(buf, "UNKNOWN\n");
}

<<<<<<< HEAD
static ssize_t s2mu005_muic_show_audio_path(struct device *dev,
					     struct device_attribute *attr,
					     char *buf)
{
	return 0;
}

static ssize_t s2mu005_muic_set_audio_path(struct device *dev,
					    struct device_attribute *attr,
					    const char *buf, size_t count)
{
	return 0;
=======
static ssize_t s2mu005_muic_show_is_jig_powered(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

	pr_info("%s:%s: attached_dev[%d]\n", MUIC_DEV_NAME, __func__, muic_data->attached_dev);

	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		return sprintf(buf, "1");
	case ATTACHED_DEV_NONE_MUIC:
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
	case ATTACHED_DEV_OTG_MUIC:
	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_DESKDOCK_MUIC:
	case ATTACHED_DEV_DESKDOCK_VB_MUIC:	
	case ATTACHED_DEV_CHARGING_CABLE_MUIC:		
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:	
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
	default:		
		break;
	}

	return sprintf(buf, "0");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static ssize_t s2mu005_muic_show_apo_factory(struct device *dev,
					     struct device_attribute *attr,
					     char *buf)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	const char *mode;

	/* true: Factory mode, false: not Factory mode */
	if (muic_data->is_factory_start)
		mode = "FACTORY_MODE";
	else
		mode = "NOT_FACTORY_MODE";

<<<<<<< HEAD
	pr_err("[muic] %s : %s\n",
		__func__, mode);
=======
	pr_info("%s:%s: mode status[%s]\n", MUIC_DEV_NAME, __func__, mode);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return sprintf(buf, "%s\n", mode);
}

static ssize_t s2mu005_muic_set_apo_factory(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	const char *mode;

<<<<<<< HEAD
	pr_err("[muic] %s buf:%s\n",
		__func__, buf);
=======
	pr_info("%s:%s: buf:%s\n", MUIC_DEV_NAME, __func__, buf);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* "FACTORY_START": factory mode */
	if (!strncmp(buf, "FACTORY_START", 13)) {
		muic_data->is_factory_start = true;
		mode = "FACTORY_MODE";
	} else {
<<<<<<< HEAD
		pr_err("[muic] %s Wrong command\n",  __func__);
=======
		pr_info( "%s:%s: Wrong command\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return count;
	}

	return count;
}

<<<<<<< HEAD
static DEVICE_ATTR(uart_en, 0664, s2mu005_muic_show_uart_en,
					s2mu005_muic_set_uart_en);
static DEVICE_ATTR(uart_sel, 0664, s2mu005_muic_show_uart_sel,
		s2mu005_muic_set_uart_sel);
static DEVICE_ATTR(usb_sel, 0664,
		s2mu005_muic_show_usb_sel, s2mu005_muic_set_usb_sel);
=======
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
static void s2mu005_muic_set_water_wa(struct s2mu005_muic_data *muic_data, bool en)
{
	struct i2c_client *i2c = muic_data->i2c;

	muic_data->is_water_wa = en;
	pr_info("%s: en : (%d)\n", __func__, (int)en);
	if (en) {
		/* W/A apply */
		s2mu005_i2c_update_bit(i2c,
				S2MU005_REG_MUIC_LDOADC_VSETH, LDOADC_VSET_MASK, 0, LDOADC_VSET_1_2V);
		usleep_range(WATER_TOGGLE_WA_MIN_DURATION_US, WATER_TOGGLE_WA_MAX_DURATION_US);
		s2mu005_i2c_update_bit(i2c,
				S2MU005_REG_MUIC_LDOADC_VSETH, LDOADC_VSET_MASK, 0, LDOADC_VSET_1_5V);
	} else {
		/* W/A unapply */
		s2mu005_i2c_update_bit(i2c,
				S2MU005_REG_MUIC_LDOADC_VSETH, LDOADC_VSET_MASK, 0, LDOADC_VSET_3V);
	}
	return;
}
#endif

static DEVICE_ATTR(uart_en, 0664, s2mu005_muic_show_uart_en,
					s2mu005_muic_set_uart_en);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static DEVICE_ATTR(adc, 0664, s2mu005_muic_show_adc, NULL);
#ifdef DEBUG_MUIC
static DEVICE_ATTR(mansw, 0664, s2mu005_muic_show_mansw, NULL);
static DEVICE_ATTR(dump_registers, 0664, s2mu005_muic_show_registers, NULL);
static DEVICE_ATTR(int_status, 0664, s2mu005_muic_show_interrupt_status, NULL);
#endif
static DEVICE_ATTR(usb_state, 0664, s2mu005_muic_show_usb_state, NULL);
#if defined(CONFIG_USB_HOST_NOTIFY)
<<<<<<< HEAD
static DEVICE_ATTR(otg_test, 0664,
		s2mu005_muic_show_otg_test, s2mu005_muic_set_otg_test);
#endif
static DEVICE_ATTR(attached_dev, 0664, s2mu005_muic_show_attached_dev, NULL);
static DEVICE_ATTR(audio_path, 0664,
		s2mu005_muic_show_audio_path, s2mu005_muic_set_audio_path);
static DEVICE_ATTR(apo_factory, 0664,
		s2mu005_muic_show_apo_factory,
		s2mu005_muic_set_apo_factory);
static DEVICE_ATTR(usb_en, 0664,
		s2mu005_muic_show_usb_en,
		s2mu005_muic_set_usb_en);

static struct attribute *s2mu005_muic_attributes[] = {
	&dev_attr_uart_en.attr,
	&dev_attr_uart_sel.attr,
	&dev_attr_usb_sel.attr,
=======
static DEVICE_ATTR(otg_test, 0664, s2mu005_muic_show_otg_test,
					s2mu005_muic_set_otg_test);
#endif
static DEVICE_ATTR(attached_dev, 0664, s2mu005_muic_show_attached_dev, NULL);
static DEVICE_ATTR(is_jig_powered, 0664, s2mu005_muic_show_is_jig_powered, NULL);
static DEVICE_ATTR(apo_factory, 0664, s2mu005_muic_show_apo_factory,
					s2mu005_muic_set_apo_factory);
static DEVICE_ATTR(usb_en, 0664, s2mu005_muic_show_usb_en,
					s2mu005_muic_set_usb_en);
static DEVICE_ATTR(jig_disable, 0664, s2mu005_muic_jig_disable_show,
					s2mu005_muic_jig_disable_store);
#if defined(CONFIG_NEW_FACTORY_UART)
static DEVICE_ATTR(factory_uart, 0664, factory_uart_show,
					factory_uart_store);
#endif

static struct attribute *s2mu005_muic_attributes[] = {
	&dev_attr_uart_en.attr,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	&dev_attr_adc.attr,
#ifdef DEBUG_MUIC
	&dev_attr_mansw.attr,
	&dev_attr_dump_registers.attr,
	&dev_attr_int_status.attr,
#endif
	&dev_attr_usb_state.attr,
#if defined(CONFIG_USB_HOST_NOTIFY)
	&dev_attr_otg_test.attr,
#endif
	&dev_attr_attached_dev.attr,
<<<<<<< HEAD
	&dev_attr_audio_path.attr,
	&dev_attr_apo_factory.attr,
	&dev_attr_usb_en.attr,
=======
	&dev_attr_is_jig_powered.attr,
	&dev_attr_apo_factory.attr,
	&dev_attr_usb_en.attr,
	&dev_attr_jig_disable.attr,
#if defined(CONFIG_NEW_FACTORY_UART)
	&dev_attr_factory_uart.attr,
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	NULL
};

static const struct attribute_group s2mu005_muic_group = {
	.attrs = s2mu005_muic_attributes,
};

<<<<<<< HEAD
static int set_ctrl_reg(struct s2mu005_muic_data *muic_data, int shift, bool on)
=======
#if defined(CONFIG_LANHUB_SUPPORT)
static int set_adc_mode_oneshot(struct s2mu005_muic_data *muic_data, bool oneshot)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct i2c_client *i2c = muic_data->i2c;
	u8 reg_val;
	int ret = 0;

<<<<<<< HEAD
	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);
	if (ret < 0)
		pr_err("[muic] %s err read CTRL(%d)\n",
			__func__, ret);

	if (on)
		reg_val = ret | (0x1 << shift);
	else
		reg_val = ret & ~(0x1 << shift);

	if (reg_val ^ ret) {
		pr_err("[muic] %s 0x%x != 0x%x, update\n",
			__func__, reg_val, ret);

		ret = s2mu005_i2c_guaranteed_wbyte(i2c, S2MU005_REG_MUIC_CTRL1,
				reg_val);
		if (ret < 0)
			pr_err("[muic] %s err write(%d)\n",
				__func__, ret);
	} else {
		pr_err("[muic] %s 0x%x == 0x%x, just return\n",
			__func__, reg_val, ret);
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);
	if (ret < 0)
		pr_err("[muic] %s err read CTRL(%d)\n", __func__, ret);
	else
		pr_err("[muic] %s after change(0x%x)\n",
			__func__, ret);

	return ret;
}

static int set_int_mask(struct s2mu005_muic_data *muic_data, bool on)
{
	int shift = CTRL_INT_MASK_SHIFT;
	int ret = 0;

	ret = set_ctrl_reg(muic_data, shift, on);

	return ret;
}

static int set_manual_sw(struct s2mu005_muic_data *muic_data, bool on)
{
	int shift = CTRL_MANUAL_SW_SHIFT;
	int ret = 0;

	ret = set_ctrl_reg(muic_data, shift, on);
=======
	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL3);
	if (ret < 0)
		pr_err("%s:%s: err read CTRL3(%d)\n", MUIC_DEV_NAME, __func__, ret);

	if (oneshot)
		reg_val = ret | (0x1 << CTRL_ONE_SHOT_SHIFT);
	else
		reg_val = ret & ~(0x1 << CTRL_ONE_SHOT_SHIFT);

	if (reg_val ^ ret) {
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__, reg_val, ret);

		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_CTRL3, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write(%d)\n", MUIC_DEV_NAME, __func__, ret);
	} else {
		pr_info("%s:%s: 0x%x == 0x%x, just return\n",
			MUIC_DEV_NAME, __func__, reg_val, ret);
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL3);
	if (ret < 0)
		pr_err("%s:%s: err read CTRL(%d)\n", MUIC_DEV_NAME, __func__, ret);
	else
		pr_info("%s:%s: after change(0x%x)\n", MUIC_DEV_NAME, __func__, ret);

	return ret;
}
#endif
static int set_ctrl_reg(struct s2mu005_muic_data *muic_data, int shift, bool on)
{
	struct i2c_client *i2c = muic_data->i2c;
	u8 reg_val;
	int ret = 0;

	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);
	if (ret < 0)
		pr_err("%s:%s: err read CTRL(%d)\n", MUIC_DEV_NAME, __func__, ret);

	if (on)
		reg_val = ret | (0x1 << shift);
	else
		reg_val = ret & ~(0x1 << shift);

	if (reg_val ^ ret) {
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__, reg_val, ret);

		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_CTRL1, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write(%d)\n", MUIC_DEV_NAME, __func__, ret);
	} else {
		pr_info("%s:%s: 0x%x == 0x%x, just return\n",
			MUIC_DEV_NAME, __func__, reg_val, ret);
		return 0;
	}

	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);
	if (ret < 0)
		pr_err("%s:%s: err read CTRL(%d)\n", MUIC_DEV_NAME, __func__, ret);
	else
		pr_info("%s:%s: after change(0x%x)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

static int set_com_sw(struct s2mu005_muic_data *muic_data,
			enum s2mu005_reg_manual_sw_value reg_val)
{
	struct i2c_client *i2c = muic_data->i2c;
	int ret = 0;
	int temp = 0;
<<<<<<< HEAD

	/*  --- MANSW [7:5][4:2][1][0] : DM DP RSVD JIG  --- */
	temp = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	if (temp < 0)
		pr_err("[muic] %s err read MANSW(0x%x)\n",
			__func__, temp);

	if ((reg_val & MANUAL_SW_DM_DP_MASK) != (temp & MANUAL_SW_DM_DP_MASK)) {
		pr_err("[muic] %s 0x%x != 0x%x, update\n",
			__func__, (reg_val & MANUAL_SW_DM_DP_MASK), (temp & MANUAL_SW_DM_DP_MASK));

		ret = s2mu005_i2c_guaranteed_wbyte(i2c,
			S2MU005_REG_MUIC_SW_CTRL, ((reg_val & MANUAL_SW_DM_DP_MASK)|(temp & 0x03)));
		if (ret < 0)
			pr_err("[muic] %s err write MANSW(0x%x)\n",
				__func__, ((reg_val & MANUAL_SW_DM_DP_MASK)|(temp & 0x03)));
	} else {
		pr_err("[muic] %s MANSW reg(0x%x), just pass\n",
			__func__, reg_val);
	}

	return ret;
}

static int com_to_open_with_vbus(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;

	reg_val = MANSW_OPEN_WITH_VBUS;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
		pr_err("[muic] %s set_com_sw err\n", __func__);

	return ret;
}

#ifndef com_to_open
=======
	int res = 0;
	/*  --- MANSW [7:5][4:2][1][0] : DM DP RSVD JIG  --- */
	temp = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	if (temp < 0)
		pr_err("%s:%s: err read MANSW(0x%x)\n", MUIC_DEV_NAME, __func__, temp);
	if (muic_data->jigonb_enable && !muic_data->jig_disable)
		reg_val |= (MANUAL_SW_JIG_EN);

	if (reg_val != temp) {
		pr_info("%s:%s: 0x%x != 0x%x, update\n", MUIC_DEV_NAME, __func__,
			reg_val, temp);

		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_SW_CTRL, reg_val);
		if (ret < 0)
			pr_err("%s:%s: err write MANSW(0x%x)\n", MUIC_DEV_NAME, __func__, reg_val);
	}
	res = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	if (res < 0)
		pr_err("%s:%s: err read MANSW(0x%x)\n", MUIC_DEV_NAME, __func__, res);
	return ret;
}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static int com_to_open(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;
<<<<<<< HEAD
	u8 vbvolt;

	vbvolt = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_DEVICE_APPLE);
	vbvolt &= DEV_TYPE_APPLE_VBUS_WAKEUP;
	if (vbvolt) {
		ret = com_to_open_with_vbus(muic_data);
		return ret;
	}
=======

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	reg_val = MANSW_OPEN;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
<<<<<<< HEAD
		pr_err("[muic] %s set_com_sw err\n", __func__);

	return ret;
}
#endif
=======
		pr_err("%s:%s: set_com_sw err\n", MUIC_DEV_NAME, __func__);

	return ret;
}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

static int com_to_usb(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;

<<<<<<< HEAD
	reg_val = MANSW_USB;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
		pr_err("[muic] %s set_com_usb err\n", __func__);
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
	reg_val = MANSW_USB;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
		pr_err("%s:%s: set_com_usb err\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

<<<<<<< HEAD
static int com_to_otg(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;

	reg_val = MANSW_OTG;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
		pr_err("[muic] %s set_com_otg err\n", __func__);

	return ret;
}
=======
#if defined(CONFIG_MUIC_S2MU005_ENABLE_AUTOSW)
static int com_to_open_jigen(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;
	struct i2c_client *i2c = muic_data->i2c;

	ret = set_ctrl_reg(muic_data, CTRL_MANUAL_SW_SHIFT, false);
	if (ret < 0)
		pr_err( "%s:%s: fail to update reg\n", MUIC_DEV_NAME, __func__);
	
	reg_val = (MANSW_OPEN | MANUAL_SW_JIG_EN);

	ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_SW_CTRL, reg_val);
	if (ret < 0)
		pr_err("%s:%s: err write MANSW\n", MUIC_DEV_NAME, __func__);

	ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	pr_info("%s:%s: MUIC_SW_CTRL=0x%x\n ", MUIC_DEV_NAME, __func__, ret);

	return ret;
}
#endif /* CONFIG_MUIC_S2MU005_ENABLE_AUTOSW */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

static int com_to_uart(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;

<<<<<<< HEAD
	if (muic_data->is_rustproof) {
		pr_err("[muic] %s rustproof mode\n", __func__);
=======
	pr_info("%s:%s: rustproof mode[%d]\n", MUIC_DEV_NAME, __func__, muic_data->is_rustproof);

	if (muic_data->is_rustproof)
	{
#if defined(CONFIG_MUIC_S2MU005_ENABLE_AUTOSW)
		ret = com_to_open_jigen(muic_data);
		if (ret)
			pr_err("%s:%s: manual open set err\n", MUIC_DEV_NAME, __func__);
#endif /* CONFIG_MUIC_S2MU005_ENABLE_AUTOSW */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return ret;
	}
	reg_val = MANSW_UART;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
<<<<<<< HEAD
		pr_err("[muic] %s set_com_uart err\n", __func__);

	return ret;
}

static int com_to_audio(struct s2mu005_muic_data *muic_data)
{
	enum s2mu005_reg_manual_sw_value reg_val;
	int ret = 0;

	reg_val = MANSW_AUDIO;
	ret = set_com_sw(muic_data, reg_val);
	if (ret)
		pr_err("[muic] %s set_com_audio err\n", __func__);

	return ret;
}

static int switch_to_dock_audio(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	ret = com_to_audio(muic_data);
	if (ret) {
		pr_err("[muic] %s com->audio set err\n", __func__);
		return ret;
	}

	return ret;
}

static int switch_to_system_audio(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	return ret;
}


static int switch_to_ap_usb(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	ret = com_to_usb(muic_data);
	if (ret) {
		pr_err("[muic] %s com->usb set err\n", __func__);
		return ret;
	}
=======
		pr_err("%s:%s: set_com_uart err\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

<<<<<<< HEAD
static int switch_to_cp_usb(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	ret = com_to_usb(muic_data);
	if (ret) {
		pr_err("[muic] %s com->usb set err\n", __func__);
		return ret;
	}

	return ret;
}

static int switch_to_ap_uart(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);
#if !defined(CONFIG_MUIC_UART_SWITCH)
	if (muic_data->pdata->gpio_uart_sel)
#endif
		muic_data->pdata->set_gpio_uart_sel(MUIC_PATH_UART_AP);

	ret = com_to_uart(muic_data);
	if (ret) {
		pr_err("[muic] %s com->uart set err\n", __func__);
		return ret;
	}

	return ret;
}

static int switch_to_cp_uart(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);
#if !defined(CONFIG_MUIC_UART_SWITCH)
	if (muic_data->pdata->gpio_uart_sel)
#endif
		muic_data->pdata->set_gpio_uart_sel(MUIC_PATH_UART_CP);

	ret = com_to_uart(muic_data);
	if (ret) {
		pr_err("[muic] %s com->uart set err\n", __func__);
		return ret;
	}

	return ret;
}

static int attach_charger(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev)
{
	int ret = 0;

	pr_err("[muic] %s : %d\n", __func__, new_dev);

	muic_data->attached_dev = new_dev;

	return ret;
}

static int detach_charger(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	return ret;
}

static int attach_usb_util(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev)
{
	int ret = 0;

	ret = attach_charger(muic_data, new_dev);
	if (ret)
		return ret;

	if (muic_data->pdata->usb_path == MUIC_PATH_USB_CP) {
		ret = switch_to_cp_usb(muic_data);
		return ret;
	}

	ret = switch_to_ap_usb(muic_data);
	return ret;
}

static int attach_usb(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev)
{
	int ret = 0;

	if (muic_data->attached_dev == new_dev) {
		pr_err("[muic] %s duplicated\n", __func__);
		return ret;
	}

	pr_err("%s:%s\n", MFD_DEV_NAME, __func__);

	pr_err("[muic] %s\n", __func__);

	ret = attach_usb_util(muic_data, new_dev);
	if (ret)
		return ret;

	return ret;
}
#if 0
static int set_vbus_interrupt(struct s2mu005_muic_data *muic_data, int enable)
{
	struct i2c_client *i2c = muic_data->i2c;
	int ret = 0;

	if (enable) {
		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_INT2_MASK,
			REG_INTMASK2_VBUS);
		if (ret < 0)
			pr_err("[muic] %s(%d)\n", __func__, ret);
	} else {
		ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_INT2_MASK,
			REG_INTMASK2_VALUE);
		if (ret < 0)
			pr_err("[muic] %s(%d)\n", __func__, ret);
	}
	return ret;
}
#endif
static int attach_otg_usb(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev)
{
	int ret = 0;

	if (muic_data->attached_dev == new_dev) {
		pr_err("[muic] %s duplicated\n", __func__);
		return ret;
	}

	pr_err("[muic] %s\n", __func__);

#ifdef CONFIG_MUIC_S2MU005_SUPPORT_LANHUB
	/* LANHUB doesn't work under AUTO switch mode, so turn it off */
	/* set MANUAL SW mode */
	set_manual_sw(muic_data, 0);

	/* enable RAW DATA mode, only for OTG LANHUB */
	set_ctrl_reg(muic_data, CTRL_RAW_DATA_SHIFT , 0);
#endif

	ret = com_to_otg(muic_data);

	muic_data->attached_dev = new_dev;

	return ret;
}

static int detach_otg_usb(struct s2mu005_muic_data *muic_data)
{
	struct muic_platform_data *pdata = muic_data->pdata;
	int ret = 0;

	pr_err("[muic] %s : %d\n",
		__func__, muic_data->attached_dev);

	ret = com_to_open(muic_data);
	if (ret)
		return ret;

#ifdef CONFIG_MUIC_S2MU005_SUPPORT_LANHUB
	/* disable RAW DATA mode */
	set_ctrl_reg(muic_data, CTRL_RAW_DATA_SHIFT , 1);

#ifdef CONFIG_MACH_DEGAS
	/* System rev less than 0.1 cannot use Auto switch mode in DEGAS */
	if (system_rev >= 0x1)
#endif
		/* set AUTO SW mode */
		set_manual_sw(muic_data, 1);
#endif

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	if (pdata->usb_path == MUIC_PATH_USB_CP)
		return ret;

	return ret;
}

static int detach_usb(struct s2mu005_muic_data *muic_data)
{
	struct muic_platform_data *pdata = muic_data->pdata;
	int ret = 0;

	pr_err("[muic] %s : %d\n",
		__func__, muic_data->attached_dev);

	ret = detach_charger(muic_data);
	if (ret)
		return ret;

	ret = com_to_open(muic_data);
	if (ret)
		return ret;

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	if (pdata->usb_path == MUIC_PATH_USB_CP)
		return ret;

	return ret;
}

static int attach_deskdock(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev, u8 vbvolt)
{
	int ret = 0;

	pr_err("[muic] %s vbus(%x)\n", __func__, vbvolt);

#ifdef CONFIG_MACH_DEGAS
	/* Audio-out doesn't work under AUTO switch mode, so turn it off */
	/* set MANUAL SW mode */
	set_manual_sw(muic_data, 0);
#endif

	ret = switch_to_dock_audio(muic_data);
	if (ret)
		return ret;

	if (vbvolt)
		ret = attach_charger(muic_data, new_dev);
	else
		ret = detach_charger(muic_data);
	if (ret)
		return ret;

	muic_data->attached_dev = new_dev;

	return ret;
}

static int detach_deskdock(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

#ifdef CONFIG_MACH_DEGAS
	/* System rev less than 0.1 cannot use Auto switch mode in DEGAS */
	if (system_rev >= 0x1)
		set_manual_sw(muic_data, 1); /* set AUTO SW mode */
#endif

	ret = switch_to_system_audio(muic_data);
	if (ret)
		pr_err("[muic] %s err changing audio path(%d)\n",
			__func__, ret);

	ret = detach_charger(muic_data);
	if (ret)
		pr_err("[muic] %s err detach_charger(%d)\n",
			__func__, ret);

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	return ret;
}

static int attach_audiodock(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev, u8 vbus)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	if (!vbus) {
		ret = detach_charger(muic_data);
		if (ret)
			pr_err("[muic] %s err detach_charger(%d)\n",
				__func__, ret);

		ret = com_to_open(muic_data);
		if (ret)
			return ret;

		muic_data->attached_dev = new_dev;

		return ret;
	}

	ret = attach_usb_util(muic_data, new_dev);
	if (ret)
		pr_err("[muic] %s attach_usb_util(%d)\n",
			__func__, ret);

	muic_data->attached_dev = new_dev;

	return ret;
}

static int detach_audiodock(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	ret = detach_charger(muic_data);
	if (ret)
		pr_err("[muic] %s err detach_charger(%d)\n",
			__func__, ret);

	ret = com_to_open(muic_data);
	if (ret)
		return ret;

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;
=======
static int switch_to_uart(struct s2mu005_muic_data *muic_data, int uart_status)
{
	int ret = 0;

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	if (muic_data->pdata->gpio_uart_sel)
		muic_data->pdata->set_gpio_uart_sel(uart_status);

	ret = com_to_uart(muic_data);
	if (ret) {
		pr_err("%s:%s: com->uart set err\n", MUIC_DEV_NAME, __func__);
		return ret;
	}

	return ret;
}

static int attach_usb(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
	ret = com_to_usb(muic_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

<<<<<<< HEAD
static int attach_jig_uart_boot_off(struct s2mu005_muic_data *muic_data,
				muic_attached_dev_t new_dev)
=======
static int attach_jig_uart_boot_on_off(struct s2mu005_muic_data *muic_data)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct muic_platform_data *pdata = muic_data->pdata;
	int ret = 0;

<<<<<<< HEAD
	pr_err("[muic] %s(%d)\n",
		__func__, new_dev);

	if (pdata->uart_path == MUIC_PATH_UART_AP)
		ret = switch_to_ap_uart(muic_data);
	else
		ret = switch_to_cp_uart(muic_data);

	ret = attach_charger(muic_data, new_dev);
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	if (pdata->uart_path == MUIC_PATH_UART_AP)
		ret = switch_to_uart(muic_data, MUIC_PATH_UART_AP);
	else
		ret = switch_to_uart(muic_data, MUIC_PATH_UART_CP);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

<<<<<<< HEAD
static int detach_jig_uart_boot_off(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_err("[muic] %s\n", __func__);

	ret = detach_charger(muic_data);
	if (ret)
		pr_err("[muic] %s err detach_charger(%d)\n", __func__, ret);

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	return ret;
}

static int attach_jig_uart_boot_on(struct s2mu005_muic_data *muic_data,
				muic_attached_dev_t new_dev)
{
	int ret = 0;

	pr_err("[muic] %s(%d)\n",
		__func__, new_dev);

	ret = set_com_sw(muic_data, MANSW_OPEN);
	if (ret)
		pr_err("[muic] %s set_com_sw err\n", __func__);

	muic_data->attached_dev = ATTACHED_DEV_JIG_UART_ON_MUIC;
	return ret;
}

static int dettach_jig_uart_boot_on(struct s2mu005_muic_data *muic_data)
{
	pr_err("[muic] %s\n", __func__);

	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;

	return 0;
}

static int attach_jig_usb_boot_off(struct s2mu005_muic_data *muic_data,
				u8 vbvolt)
{
	int ret = 0;

	if (muic_data->attached_dev == ATTACHED_DEV_JIG_USB_OFF_MUIC) {
		pr_err("[muic] %s duplicated\n", __func__);
		return ret;
	}

	pr_err("[muic] %s\n", __func__);

	ret = attach_usb_util(muic_data, ATTACHED_DEV_JIG_USB_OFF_MUIC);
=======

static int attach_jig_usb_boot_on_off(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	ret = attach_usb(muic_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (ret)
		return ret;

	return ret;
}

<<<<<<< HEAD
static int attach_jig_usb_boot_on(struct s2mu005_muic_data *muic_data,
				u8 vbvolt)
{
	int ret = 0;

	if (muic_data->attached_dev == ATTACHED_DEV_JIG_USB_ON_MUIC) {
		pr_err("[muic] %s duplicated\n", __func__);
		return ret;
	}

	pr_err("[muic] %s\n", __func__);

	ret = attach_usb_util(muic_data, ATTACHED_DEV_JIG_USB_ON_MUIC);
	if (ret)
		return ret;

	return ret;
}
=======
#ifdef CONFIG_MUIC_S2MU005_INNER_BATTERY
/* Power-off SW work-around by disconnecting JIG cable for EVT4
 * in case of In-battery model
 */
static void s2mu005_muic_power_off(struct s2mu005_muic_data *muic_data, int on)
{
	struct i2c_client *i2c = muic_data->i2c;
	int ret = 0;

	if (muic_data->muic_version >= 4) {
		if (on) {
			/* 0x27[0]=0 */
			ret = s2mu005_i2c_read_byte(i2c, 0x27);
			ret |= 0x30;
			s2mu005_i2c_write_byte(i2c, 0x27, (u8)ret);
		} else {
			/* 0x27[0]=1 : default */
			ret = s2mu005_i2c_read_byte(i2c, 0x27);
			ret &= ~0x30;
			ret |= 0x10;
			s2mu005_i2c_write_byte(i2c, 0x27, (u8)ret);
		}
	}
	pr_info("%s:%s: 0x27:0x%x, rev_id(%d)\n", MUIC_DEV_NAME,
			__func__, ret, muic_data->muic_version);
}
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

static void s2mu005_muic_handle_attach(struct s2mu005_muic_data *muic_data,
			muic_attached_dev_t new_dev, int adc, u8 vbvolt)
{
<<<<<<< HEAD
	int ret = 0;
	bool noti = (new_dev != muic_data->attached_dev) ? true : false;

	muic_data->is_jig_on = false;
	pr_err("[muic] %s : muic_data->attached_dev: %d, new_dev: %d, muic_data->suspended: %d\n",
		__func__, muic_data->attached_dev, new_dev, muic_data->suspended);

=======
	struct muic_platform_data *pdata = muic_data->pdata;
	int ret = 0;
	bool noti = (new_dev != muic_data->attached_dev) ? true : false;

	pr_info("%s:%s: muic_data->attached_dev: %d, new_dev: %d, muic_data->suspended: %d\n",
		MUIC_DEV_NAME, __func__, muic_data->attached_dev, new_dev, muic_data->suspended);

	if (new_dev == muic_data->attached_dev) {
		pr_info("%s:%s: Attach duplicated\n", MUIC_DEV_NAME, __func__);
		return;
	}

	/* Logically Detach Accessary */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
<<<<<<< HEAD
		if (new_dev != muic_data->attached_dev) {
			pr_err("[muic] %s new(%d)!=attached(%d)\n",
				__func__, new_dev, muic_data->attached_dev);
			ret = detach_usb(muic_data);
		}
		break;
	case ATTACHED_DEV_OTG_MUIC:
	/* OTG -> LANHUB, meaning TA is attached to LANHUB(OTG) */
		if (new_dev != muic_data->attached_dev) {
			pr_err("[muic] %s new(%d)!=attached(%d)",
				__func__, new_dev, muic_data->attached_dev);
			ret = detach_otg_usb(muic_data);
		}
		break;

	case ATTACHED_DEV_AUDIODOCK_MUIC:
		if (new_dev != muic_data->attached_dev) {
			pr_err("[muic] %s new(%d)!=attached(%d)\n",
				__func__, new_dev, muic_data->attached_dev);
			ret = detach_audiodock(muic_data);
		}
		break;

	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_UNDEFINED_CHARGING_MUIC:
		if (new_dev != muic_data->attached_dev) {
			pr_err("[muic] %s new(%d)!=attached(%d)\n",
				__func__, new_dev, muic_data->attached_dev);
			ret = detach_charger(muic_data);
		}
		break;

	case ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_FG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
		if (new_dev != ATTACHED_DEV_JIG_UART_OFF_MUIC) {
			pr_err("[muic] %s new(%d)!=attached(%d)\n",
				__func__, new_dev, muic_data->attached_dev);
			ret = detach_jig_uart_boot_off(muic_data);
		}
		break;

	case ATTACHED_DEV_JIG_UART_ON_MUIC:
	case ATTACHED_DEV_DESKDOCK_MUIC:
		if (new_dev != muic_data->attached_dev) {
			pr_err("[muic] %s new(%d)!=attached(%d)\n",
				__func__, new_dev, muic_data->attached_dev);

			if (muic_data->is_factory_start)
				ret = detach_deskdock(muic_data);
			else {
				noti = false;
				ret = dettach_jig_uart_boot_on(muic_data);
			}
		}
		break;
	default:
		break;
	}

#if defined(CONFIG_MUIC_NOTIFIER)
	if (noti) {
		if (!muic_data->suspended)
			muic_notifier_detach_attached_dev(muic_data->attached_dev);
		else
			muic_data->need_to_noti = true;
	}
#endif /* CONFIG_MUIC_NOTIFIER */

	switch (new_dev) {
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
		ret = attach_usb(muic_data, new_dev);
		break;
	case ATTACHED_DEV_OTG_MUIC:
		ret = attach_otg_usb(muic_data, new_dev);
		break;
	case ATTACHED_DEV_AUDIODOCK_MUIC:
		ret = attach_audiodock(muic_data, new_dev, vbvolt);
		break;
	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_UNDEFINED_CHARGING_MUIC:
		com_to_open_with_vbus(muic_data);
		ret = attach_charger(muic_data, new_dev);
		break;
	case ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_FG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
		muic_data->is_jig_on = true;
		ret = attach_jig_uart_boot_off(muic_data, new_dev);
		break;
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
		/* call attach_deskdock to wake up the device */
		muic_data->is_jig_on = true;
		if (muic_data->is_factory_start)
			ret = attach_deskdock(muic_data, new_dev, vbvolt);
		else {
			noti = false;
			ret = attach_jig_uart_boot_on(muic_data, new_dev);
		}
		break;
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
		muic_data->is_jig_on = true;
		ret = attach_jig_usb_boot_off(muic_data, vbvolt);
		break;
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		muic_data->is_jig_on = true;
		ret = attach_jig_usb_boot_on(muic_data, vbvolt);
		break;
	case ATTACHED_DEV_DESKDOCK_MUIC:
		ret = attach_deskdock(muic_data, new_dev, vbvolt);
		break;
	case ATTACHED_DEV_UNKNOWN_MUIC:
		com_to_open_with_vbus(muic_data);
		ret = attach_charger(muic_data, new_dev);
		break;
	default:
		noti = false;
		pr_err("[muic] %s unsupported dev=%d, adc=0x%x, vbus=%c\n",
			__func__, new_dev, adc, (vbvolt ? 'O' : 'X'));
		break;
	}

#if !defined(CONFIG_MUIC_S2MU005_ENABLE_AUTOSW)
	ret = s2mu005_muic_jig_on(muic_data);
#endif

	if (ret)
		pr_err("[muic] %s something wrong %d (ERR=%d)\n",
			__func__, new_dev, ret);

	pr_err("%s:%s\n", MFD_DEV_NAME, __func__);

=======
	case ATTACHED_DEV_OTG_MUIC:
#if defined(CONFIG_LANHUB_SUPPORT)
		if(new_dev == ATTACHED_DEV_USB_LANHUB_MUIC)
			break;
#endif
	case ATTACHED_DEV_CHARGING_CABLE_MUIC:
	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_UNDEFINED_CHARGING_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
	case ATTACHED_DEV_FACTORY_UART_MUIC:
	case ATTACHED_DEV_TIMEOUT_OPEN_MUIC:
#if defined(CONFIG_SEC_FACTORY) && defined(CONFIG_MUIC_S2MU005_DISCHARGING_WA)		
	case ATTACHED_DEV_CARKIT_MUIC:
#endif
#ifdef CONFIG_MUIC_S2MU005_INNER_BATTERY
		s2mu005_muic_power_off(muic_data, 0);
#endif
		s2mu005_muic_handle_detach(muic_data);
                break;
	case ATTACHED_DEV_DESKDOCK_MUIC:
	case ATTACHED_DEV_DESKDOCK_VB_MUIC:
		switch (new_dev) {
		case ATTACHED_DEV_DESKDOCK_MUIC:
		case ATTACHED_DEV_DESKDOCK_VB_MUIC:
			break;
		default:
#ifdef CONFIG_MUIC_S2MU005_INNER_BATTERY
		s2mu005_muic_power_off(muic_data, 0);
#endif
			s2mu005_muic_handle_detach(muic_data);
			break;
		}
		break;
	default:
		break;
	}
	pr_info("%s:%s: new(%d)!=attached(%d)\n", MUIC_DEV_NAME, __func__,
							new_dev, muic_data->attached_dev);
	muic_data->jigonb_enable = false;

	/* Attach Accessary */
	noti = true;
	switch (new_dev) {
	case ATTACHED_DEV_OTG_MUIC:
#if defined(CONFIG_LANHUB_SUPPORT)		
	case ATTACHED_DEV_USB_LANHUB_MUIC:
		set_ctrl_reg(muic_data, CTRL_MANUAL_SW_SHIFT, false);
		set_adc_mode_oneshot(muic_data, false);
#endif		
		ret = attach_usb(muic_data);
		break;
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
	case ATTACHED_DEV_TIMEOUT_OPEN_MUIC:	
		ret = attach_usb(muic_data);
		break;
	case ATTACHED_DEV_CHARGING_CABLE_MUIC:
	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_UNDEFINED_CHARGING_MUIC:
	case ATTACHED_DEV_UNKNOWN_MUIC:
		com_to_open(muic_data);
		break;
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
#ifdef CONFIG_MUIC_S2MU005_INNER_BATTERY 
		s2mu005_muic_power_off(muic_data, 1); 
#endif 
		if (pdata->is_new_factory)
#if !IS_ENABLED(CONFIG_SEC_FACTORY)
			muic_data->jigonb_enable = false;
#else
			muic_data->jigonb_enable = true;
#endif	
		else
			muic_data->jigonb_enable = true;
		ret = attach_jig_uart_boot_on_off(muic_data);
		break;
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
		if (pdata->is_new_factory)
			muic_data->jigonb_enable = false;
		else
			muic_data->jigonb_enable = true;
		ret = attach_jig_uart_boot_on_off(muic_data);
		break;
	case ATTACHED_DEV_FACTORY_UART_MUIC:
		muic_data->jigonb_enable = false;
		ret = attach_jig_uart_boot_on_off(muic_data);
		break;
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
#ifdef CONFIG_MUIC_S2MU005_INNER_BATTERY 
		s2mu005_muic_power_off(muic_data, 1); 
#endif 
#if defined(CONFIG_SEC_FACTORY) && defined(CONFIG_MUIC_S2MU005_DISCHARGING_WA)		
	case ATTACHED_DEV_CARKIT_MUIC:
#endif
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		if (pdata->is_new_factory)
			muic_data->jigonb_enable = false;
		else
			muic_data->jigonb_enable = true;
		ret = attach_jig_usb_boot_on_off(muic_data);
		break;
	case ATTACHED_DEV_DESKDOCK_MUIC:
	case ATTACHED_DEV_DESKDOCK_VB_MUIC:
		break;
	default:
		noti = false;
		pr_info("%s:%s: unsupported dev=%d, adc=0x%x, vbus=%c\n",
				MUIC_DEV_NAME, __func__, new_dev, adc, (vbvolt ? 'O' : 'X'));
		break;
	}

	if (ret)
		pr_err("%s:%s: something wrong %d (ERR=%d)\n", MUIC_DEV_NAME, __func__, new_dev, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#if defined(CONFIG_MUIC_NOTIFIER)
	if (noti) {
		if (!muic_data->suspended)
			muic_notifier_attach_attached_dev(new_dev);
		else
			muic_data->need_to_noti = true;
	}
#endif /* CONFIG_MUIC_NOTIFIER */
<<<<<<< HEAD
=======

	muic_data->attached_dev = new_dev;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void s2mu005_muic_handle_detach(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;
	bool noti = true;

<<<<<<< HEAD
	ret = com_to_open(muic_data);

	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		muic_data->is_jig_on = false;
	case ATTACHED_DEV_USB_MUIC:
	case ATTACHED_DEV_CDP_MUIC:
		ret = detach_usb(muic_data);
		break;
	case ATTACHED_DEV_OTG_MUIC:
		ret = detach_otg_usb(muic_data);
		break;
	case ATTACHED_DEV_TA_MUIC:
	case ATTACHED_DEV_UNDEFINED_CHARGING_MUIC:
		ret = detach_charger(muic_data);
		break;
	case ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_FG_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
		muic_data->is_jig_on = false;
		ret = detach_jig_uart_boot_off(muic_data);
		break;
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
		muic_data->is_jig_on = false;
	case ATTACHED_DEV_DESKDOCK_MUIC:
		if (muic_data->is_factory_start)
			ret = detach_deskdock(muic_data);
		else {
			noti = false;
			ret = dettach_jig_uart_boot_on(muic_data);
		}
		break;
	case ATTACHED_DEV_AUDIODOCK_MUIC:
		ret = detach_audiodock(muic_data);
		break;
	case ATTACHED_DEV_NONE_MUIC:
		pr_err("[muic] %s duplicated(NONE)\n", __func__);
		break;
	case ATTACHED_DEV_UNKNOWN_MUIC:
		pr_err("[muic] %s UNKNOWN\n", __func__);
		ret = detach_charger(muic_data);
		muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;
		break;
	default:
		noti = false;
		pr_err("[muic] %s invalid type(%d)\n",
			__func__, muic_data->attached_dev);
		muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;
		break;
	}

#if !defined(CONFIG_MUIC_S2MU005_ENABLE_AUTOSW)
	ret = s2mu005_muic_jig_on(muic_data);
#endif

	if (ret)
		pr_err("[muic] %s something wrong %d (ERR=%d)\n",
			__func__, muic_data->attached_dev, ret);
=======
	muic_data->jigonb_enable = false;
	
	if (muic_data->attached_dev == ATTACHED_DEV_NONE_MUIC) {
		pr_info("%s:%s: Detach duplicated(NONE)\n", MUIC_DEV_NAME, __func__);
		goto out_without_noti;
	}

	pr_info("%s:%s: Detach device[%d]\n", MUIC_DEV_NAME, __func__, muic_data->attached_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#if defined(CONFIG_MUIC_NOTIFIER)
	if (noti) {
		if (!muic_data->suspended)
			muic_notifier_detach_attached_dev(muic_data->attached_dev);
		else
			muic_data->need_to_noti = true;
	}
#endif /* CONFIG_MUIC_NOTIFIER */
<<<<<<< HEAD
=======

out_without_noti:
#if defined(CONFIG_LANHUB_SUPPORT)
	if (muic_data->attached_dev == ATTACHED_DEV_OTG_MUIC ||
			muic_data->attached_dev == ATTACHED_DEV_USB_LANHUB_MUIC) {
#ifdef CONFIG_MUIC_S2MU005_ENABLE_AUTOSW
		set_ctrl_reg(muic_data, CTRL_MANUAL_SW_SHIFT, true);
#endif
		set_adc_mode_oneshot(muic_data, true);
	}
#endif
	ret = com_to_open(muic_data);
	muic_data->attached_dev = ATTACHED_DEV_NONE_MUIC;
}

static void update_jig_state(struct s2mu005_muic_data *muic_data)
{
	struct muic_platform_data *pdata = muic_data->pdata;
	int jig_state;

	switch (muic_data->attached_dev) {
	case ATTACHED_DEV_JIG_UART_OFF_MUIC:
	case ATTACHED_DEV_JIG_UART_OFF_VB_MUIC:     /* VBUS enabled */
	case ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC:    /* for otg test */
	case ATTACHED_DEV_JIG_UART_OFF_VB_FG_MUIC:    /* for fg test */
	case ATTACHED_DEV_JIG_UART_ON_MUIC:
	case ATTACHED_DEV_JIG_UART_ON_VB_MUIC:       /* VBUS enabled */
	case ATTACHED_DEV_JIG_USB_OFF_MUIC:
	case ATTACHED_DEV_JIG_USB_ON_MUIC:
		jig_state = true;
		break;
	default:
		jig_state = false;
		break;
	}
	pr_info("%s jig_state : %d\n", __func__, jig_state);

	pdata->jig_uart_cb(jig_state);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void s2mu005_muic_detect_dev(struct s2mu005_muic_data *muic_data)
{
	struct i2c_client *i2c = muic_data->i2c;
	muic_attached_dev_t new_dev = ATTACHED_DEV_UNKNOWN_MUIC;
<<<<<<< HEAD
	int intr = MUIC_INTR_DETACH;
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	int vbvolt = 0, vmid = 0;
	int val1 = 0, val2 = 0, val3 = 0, val4 = 0, adc = 0;
	int val5 = 0, val6 = 0, val7 = 0;

	val1 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE1);
	val2 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE2);
	val3 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE3);
<<<<<<< HEAD
	val4 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS0);
=======
	val4 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_REV_ID);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	adc = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_ADC);
	val5 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_APPLE);
	val6 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CHG_TYPE);
	val7 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS2);

	vbvolt = !!(val5 & DEV_TYPE_APPLE_VBUS_WAKEUP);
<<<<<<< HEAD
	vmid = !!(val7 & 0x7);

	pr_err("[muic] dev[1:0x%x, 2:0x%x, 3:0x%x]\n"
		", adc:0x%x, vbvolt:0x%x, apple:0x%x, chg_type:0x%x, vmid:0x%x\n",
		val1, val2, val3, adc, vbvolt, val5, val6, vmid);
	pr_err("%s:%s\n", MFD_DEV_NAME, __func__);

	if (ADC_CONVERSION_MASK & adc) {
		pr_err("[muic] ADC conversion error!\n");
		return ;
	}

	/* Work-Around for EVT0 : only if VBUS connected, then apply CDP */
	/*========================================== */
	if (muic_data->muic_version == 0) {
		if (vbvolt) {
			intr = MUIC_INTR_ATTACH;
			new_dev = ATTACHED_DEV_USB_MUIC;
			pr_err("[muic] EVT0 Work-around USB_CDP DETECTED\n");
			}
	}
	/* Attached */
	switch (val1) {
	case DEV_TYPE1_CDP:
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_CDP_MUIC;
		pr_err("[muic] USB_CDP DETECTED\n");
		break;
	case DEV_TYPE1_USB:
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_USB_MUIC;
		pr_err("[muic] USB DETECTED\n");
		break;
	case DEV_TYPE1_DEDICATED_CHG:
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_TA_MUIC;
		pr_err("[muic] DEDICATED CHARGER DETECTED\n");
		break;
	case DEV_TYPE1_USB_OTG:
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_OTG_MUIC;
		pr_err("[muic] USB_OTG DETECTED\n");
		break;
	case DEV_TYPE1_T1_T2_CHG:
		intr = MUIC_INTR_ATTACH;
		/* 200K, 442K should be checkef */
=======
	vmid = (val7 & 0x7);

	pr_info("%s:%s: dev[1:0x%x, 2:0x%x, 3:0x%x]\n", MUIC_DEV_NAME, __func__, val1, val2, val3);
	pr_info("%s:%s: adc:0x%x, vbvolt:0x%x, apple:0x%x, chg_type:0x%x, vmid:0x%x, dev_id:0x%x\n",
				MUIC_DEV_NAME, __func__, adc, vbvolt, val5, val6, vmid, val4);

	if (ADC_CONVERSION_MASK & adc) {
		pr_err("%s:%s: ADC conversion error!\n", MUIC_DEV_NAME, __func__);
		return ;
	}

	/* Work-Around for EVT0 : only if VBUS connected, then apply USB */
	if(muic_data->muic_version == 0) {
		if (vbvolt) {
			new_dev = ATTACHED_DEV_USB_MUIC;
			pr_info("%s:%s: EVT0 Work-around USB DETECTED\n", MUIC_DEV_NAME, __func__);
		}
	}

	/* Detected */
	switch (val1) {
	case DEV_TYPE1_CDP:

		if (vbvolt) {
			new_dev = ATTACHED_DEV_CDP_MUIC;
			pr_info("%s:%s: USB_CDP DETECTED\n", MUIC_DEV_NAME, __func__);
		}
	
		break;
	case DEV_TYPE1_USB:
		if (vbvolt) {
			new_dev = ATTACHED_DEV_USB_MUIC;
			pr_info("%s:%s: USB DETECTED\n", MUIC_DEV_NAME, __func__);
		}
		break;
	case DEV_TYPE1_DEDICATED_CHG:
	if (vbvolt) {
		new_dev = ATTACHED_DEV_TA_MUIC;
		pr_info("%s:%s:DEDICATED CHARGER DETECTED\n", MUIC_DEV_NAME, __func__);
		}
		break;
	case DEV_TYPE1_USB_OTG:
		new_dev = ATTACHED_DEV_OTG_MUIC;
		pr_info("%s:%s: USB_OTG DETECTED\n", MUIC_DEV_NAME, __func__);
		if (vmid == 0x4) {
			pr_info("%s:%s: VMID DETECTED[%d]\n", MUIC_DEV_NAME, __func__, vmid);
			vbvolt = 1;
		}
		break;
	case DEV_TYPE1_T1_T2_CHG:
	if (vbvolt) {
		/* 200K, 442K should be checkef */
#if defined(CONFIG_SEC_FACTORY) && defined(CONFIG_MUIC_S2MU005_DISCHARGING_WA)
		new_dev = ATTACHED_DEV_CARKIT_MUIC;
		pr_info("%s:%s:CARKIT DETECTED\n", MUIC_DEV_NAME, __func__);
#else
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		if (ADC_CEA936ATYPE2_CHG == adc)
			new_dev = ATTACHED_DEV_TA_MUIC;
		else
			new_dev = ATTACHED_DEV_USB_MUIC;
<<<<<<< HEAD
		break;
=======
		pr_info("%s:%s: T1_T2 CHARGER DETECTED\n", MUIC_DEV_NAME, __func__);
#endif
	}
	else {
		/* W/A, 442k without VB changes to 523K (JIG_UART_OFF)
		To prevent to keep sleep mode*/
		new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
		pr_info("%s:%s: 442K->523K JIG_USB_OFF DETECTED\n", MUIC_DEV_NAME, __func__);
	}
		break;
#if defined (CONFIG_LANHUB_SUPPORT)
	case DEV_TYPE1_AUDIO_2:
		new_dev = ATTACHED_DEV_USB_LANHUB_MUIC;
		pr_info("%s:%s:LANHUB DETECTED DETECTED\n", MUIC_DEV_NAME, __func__);
		break;
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	default:
		break;
	}

	switch (val2) {
<<<<<<< HEAD
	case DEV_TYPE2_JIG_UART_OFF:
		intr = MUIC_INTR_ATTACH;
		if (muic_data->is_otg_test) {
			mdelay(100);
			val7 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS2);
			vmid = val7 & 0x7;
			if (vmid == 0x4) {
				pr_err("[muic] OTG_TEST DETECTED, vmid = %d\n", vmid);
				vbvolt = 1;
				new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC;
			} else
				new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
		} else if (vbvolt)
			new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_MUIC;
		else
			new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
		pr_err("[muic] JIG_UART_OFF DETECTED\n");
=======

	case DEV_TYPE2_SDP_1P8S:
		if (vbvolt && adc == ADC_OPEN) {
			new_dev = ATTACHED_DEV_TIMEOUT_OPEN_MUIC;
			pr_info("%s:%s: TIMEOUT_OPEN DETECTED\n", MUIC_DEV_NAME, __func__);
		}
	
		break; 
	case DEV_TYPE2_JIG_UART_OFF:
		if (muic_data->is_otg_test) {
			mdelay(1000);
			val7 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS2);
			vmid = val7 & 0x7;
			pr_info("%s:%s: vmid : 0x%x \n", MUIC_DEV_NAME, __func__, vmid);
			if (vmid == 0x4) {
				pr_info("%s:%s: OTG_TEST DETECTED, vmid = %d\n",
							MUIC_DEV_NAME, __func__, vmid);
				vbvolt = 1;
			}
			new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
		}
		else if (vbvolt) {
			new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_MUIC;
			pr_info("%s:%s: JIG_UART_OFF_VB DETECTED\n", MUIC_DEV_NAME, __func__);
		}
		else {
			new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
			pr_info("%s:%s: JIG_UART_OFF DETECTED\n", MUIC_DEV_NAME, __func__);
		}
		break;
	case DEV_TYPE2_JIG_UART_ON:
		if (new_dev != ATTACHED_DEV_JIG_UART_ON_MUIC) {
			new_dev = ATTACHED_DEV_JIG_UART_ON_MUIC;
			pr_info("%s:%s: JIG_UART_ON DETECTED\n", MUIC_DEV_NAME, __func__);
		}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		break;
	case DEV_TYPE2_JIG_USB_OFF:
		if (!vbvolt)
			break;
<<<<<<< HEAD
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_JIG_USB_OFF_MUIC;
		pr_err("[muic] JIG_USB_OFF DETECTED\n");
=======
		new_dev = ATTACHED_DEV_JIG_USB_OFF_MUIC;
		pr_info("%s:%s: JIG_USB_OFF DETECTED\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		break;
	case DEV_TYPE2_JIG_USB_ON:
		if (!vbvolt)
			break;
<<<<<<< HEAD
		intr = MUIC_INTR_ATTACH;
		new_dev = ATTACHED_DEV_JIG_USB_ON_MUIC;
		pr_err("[muic] JIG_USB_ON DETECTED\n");
		break;

	case DEV_TYPE2_JIG_UART_ON:
		if (new_dev != ATTACHED_DEV_JIG_UART_ON_MUIC) {
			intr = MUIC_INTR_ATTACH;
			new_dev = ATTACHED_DEV_JIG_UART_ON_MUIC;
			pr_err("[muic] ADC JIG_UART_ON DETECTED\n");
		}
=======
		new_dev = ATTACHED_DEV_JIG_USB_ON_MUIC;
		pr_info("%s:%s: JIG_USB_ON DETECTED\n", MUIC_DEV_NAME, __func__);
		break;
	default:
		break;
	}

	switch (val3) {
	case DEV_TYPE3_MHL:
		if (muic_data->pdata->is_factory_uart)
			new_dev = ATTACHED_DEV_FACTORY_UART_MUIC;
			pr_info("%s:%s: FACTORY_UART DETECTED\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		break;
	default:
		break;
	}

<<<<<<< HEAD
	if (muic_data->muic_version > 0) {

		if ((val6 & DEV_TYPE_CHG_TYPE) &&
			(new_dev == ATTACHED_DEV_UNKNOWN_MUIC)) {
			intr = MUIC_INTR_ATTACH;
			new_dev = ATTACHED_DEV_TA_MUIC;
			pr_err("[muic] TYPE3_CHARGER DETECTED\n");
		}

		if (val2 & DEV_TYPE2_AV || val3 & DEV_TYPE3_AV_WITH_VBUS) {
#ifdef CONFIG_MUIC_S2MU005_SUPPORT_DESKDOCK
			intr = MUIC_INTR_ATTACH;
			new_dev = ATTACHED_DEV_DESKDOCK_MUIC;
#else
			new_dev = ATTACHED_DEV_UNKNOWN_MUIC;
#endif
			pr_err("[muic] DESKDOCK DETECTED\n");
		}

	/* If there is no matching device found using device type registers
		use ADC to find the attached device */
		if (new_dev == ATTACHED_DEV_UNKNOWN_MUIC) {
			switch (adc) {
			case ADC_CEA936ATYPE1_CHG: /*200k ohm */
				intr = MUIC_INTR_ATTACH;
				/* This is workaournd for LG USB cable
						which has 219k ohm ID */
				new_dev = ATTACHED_DEV_USB_MUIC;
				pr_err("[muic] TYPE1 CHARGER DETECTED(USB)\n");
				break;
			case ADC_CEA936ATYPE2_CHG:
				intr = MUIC_INTR_ATTACH;
				new_dev = ATTACHED_DEV_TA_MUIC;
				pr_err("[muic] TYPE1/2 CHARGER DETECTED(TA)\n");
				break;
			case ADC_JIG_USB_OFF: /* 255k */
				if (!vbvolt)
					break;
				if (new_dev != ATTACHED_DEV_JIG_USB_OFF_MUIC) {
					intr = MUIC_INTR_ATTACH;
					new_dev = ATTACHED_DEV_JIG_USB_OFF_MUIC;
					pr_err("[muic] ADC JIG_USB_OFF DETECTED\n");
				}
				break;
			case ADC_JIG_USB_ON:
				if (!vbvolt)
					break;
				if (new_dev != ATTACHED_DEV_JIG_USB_ON_MUIC) {
					intr = MUIC_INTR_ATTACH;
					new_dev = ATTACHED_DEV_JIG_USB_ON_MUIC;
					pr_err("[muic] ADC JIG_USB_ON DETECTED\n");
				}
				break;
			case ADC_JIG_UART_OFF:
				intr = MUIC_INTR_ATTACH;
				if (muic_data->is_otg_test) {
					mdelay(100);
					val7 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS2);
					vmid = val7 & 0x7;
					if (vmid == 0x4) {
						pr_err("[muic] OTG_TEST DETECTED, vmid = %d\n", vmid);
						vbvolt = 1;
						new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC;
					} else
						new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
				} else if (vbvolt)
					new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_MUIC;
				else
					new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;

				pr_err("[muic] ADC JIG_UART_OFF DETECTED\n");
				break;
			case ADC_JIG_UART_ON:
				if (new_dev != ATTACHED_DEV_JIG_UART_ON_MUIC) {
					intr = MUIC_INTR_ATTACH;
					new_dev = ATTACHED_DEV_JIG_UART_ON_MUIC;
					pr_err("[muic] ADC JIG_UART_ON DETECTED\n");
				}
				break;
			case ADC_SMARTDOCK: /* 0x10000 40.2K ohm */
				/* SMARTDOCK is not supported */
				/* force not to charge the device with SMARTDOCK */
				break;
			case ADC_AUDIODOCK:
#ifdef CONFIG_MUIC_S2MU005_SUPPORT_AUDIODOCK
				intr = MUIC_INTR_ATTACH;
				new_dev = ATTACHED_DEV_AUDIODOCK_MUIC;
#endif
				pr_err("[muic] ADC AUDIODOCK DETECTED\n");
				break;
			case ADC_OPEN:
			/* sometimes muic fails to
				catch JIG_UART_OFF detaching */
			/* double check with ADC */
				if (new_dev == ATTACHED_DEV_JIG_UART_OFF_MUIC) {
					new_dev = ATTACHED_DEV_UNKNOWN_MUIC;
					intr = MUIC_INTR_DETACH;
					pr_err("[muic] ADC OPEN DETECTED\n");
				}
				break;
			default:
				pr_err("[muic] %s unsupported ADC(0x%02x)\n",
				__func__, adc);
				break;
			}
		}
	}
	/*========================================== */

#if 0
	if ((ATTACHED_DEV_UNKNOWN_MUIC == new_dev)
		&& (ADC_OPEN != adc)) {
		if (vbvolt) {
			intr = MUIC_INTR_ATTACH;
			new_dev = ATTACHED_DEV_UNDEFINED_CHARGING_MUIC;
			pr_err("[muic] UNDEFINED VB DETECTED\n");
		} else
			intr = MUIC_INTR_DETACH;
	}
#endif

	if (intr == MUIC_INTR_ATTACH)
		s2mu005_muic_handle_attach(muic_data, new_dev, adc, vbvolt);
	else
		s2mu005_muic_handle_detach(muic_data);
=======
	if(muic_data->muic_version > 0) {	// Start For EVT0

	/* This is for Apple cables */
	if (vbvolt && ((val5 & DEV_TYPE_APPLE_APPLE2P4A_CHG) || (val5 & DEV_TYPE_APPLE_APPLE2A_CHG) ||
		(val5 & DEV_TYPE_APPLE_APPLE1A_CHG) || (val5 & DEV_TYPE_APPLE_APPLE0P5A_CHG))) {
		new_dev = ATTACHED_DEV_TA_MUIC;
		pr_info("%s:%s: APPLE_CHG DETECTED\n", MUIC_DEV_NAME, __func__);
	}

	if ((val6 & DEV_TYPE_CHG_TYPE) &&
		(new_dev == ATTACHED_DEV_UNKNOWN_MUIC)) {
		/* This is workaround for LG USB cable which has 219k ohm ID */
		if (adc == ADC_CEA936ATYPE1_CHG || adc == ADC_JIG_USB_OFF) {
#if defined(CONFIG_SEC_FACTORY) && defined(CONFIG_MUIC_S2MU005_DISCHARGING_WA)
			new_dev = ATTACHED_DEV_CARKIT_MUIC;
			pr_err("[muic] CARKIT DETECTED\n");
#else
			new_dev = ATTACHED_DEV_USB_MUIC;
			pr_info("%s:%s: TYPE1_CHARGER DETECTED (USB)\n", MUIC_DEV_NAME, __func__);
#endif
		}
		else {
			new_dev = ATTACHED_DEV_TA_MUIC;
			pr_info("%s:%s: TYPE3_CHARGER DETECTED\n", MUIC_DEV_NAME, __func__);
		}
	}

	if (val2 & DEV_TYPE2_AV || val3 & DEV_TYPE3_AV_WITH_VBUS) {
		if (vbvolt) {
			new_dev = ATTACHED_DEV_DESKDOCK_VB_MUIC;
			pr_info("%s:%s: DESKDOCK+TA DETECTED\n", MUIC_DEV_NAME, __func__);
		}
		else {
			new_dev = ATTACHED_DEV_DESKDOCK_MUIC;
			pr_info("%s:%s: DESKDOCK DETECTED\n", MUIC_DEV_NAME, __func__);
		}

		/* If not support DESKDOCK */
//		new_dev = ATTACHED_DEV_UNKNOWN_MUIC;
	}

	/* If there is no matching device found using device type registers
		use ADC to find the attached device */
	if (new_dev == ATTACHED_DEV_UNKNOWN_MUIC) {
		switch (adc) {
		case ADC_CHARGING_CABLE:
//			new_dev = ATTACHED_DEV_CHARGING_CABLE_MUIC;
//			pr_info("%s:%s: ADC PS CABLE DETECTED\n", MUIC_DEV_NAME, __func__);
			break;
		case ADC_CEA936ATYPE1_CHG: /*200k ohm */
			/* This is workaround for LG USB cable
					which has 219k ohm ID */
			if (vbvolt) {
#if defined(CONFIG_SEC_FACTORY) && defined(CONFIG_MUIC_S2MU005_DISCHARGING_WA)
				new_dev = ATTACHED_DEV_CARKIT_MUIC;
				pr_info("%s:%s: CARKIT DETECTED\n", MUIC_DEV_NAME, __func__);
#else
				new_dev = ATTACHED_DEV_USB_MUIC;
				pr_info("%s:%s: ADC TYPE1 CHARGER DETECTED(USB)\n", MUIC_DEV_NAME, __func__);
#endif
			}
			break;
		case ADC_CEA936ATYPE2_CHG:
			if (vbvolt) {
				new_dev = ATTACHED_DEV_TA_MUIC;
				pr_info("%s:%s: ADC TYPE2 CHARGER DETECTED(TA)\n", MUIC_DEV_NAME, __func__);
			}
			break;
		case ADC_JIG_USB_OFF: /* 255k */
			if (!vbvolt)
				break;
			if (new_dev != ATTACHED_DEV_JIG_USB_OFF_MUIC) {
				new_dev = ATTACHED_DEV_JIG_USB_OFF_MUIC;
				pr_info("%s:%s: ADC JIG_USB_OFF DETECTED\n", MUIC_DEV_NAME, __func__);
			}
			break;
		case ADC_JIG_USB_ON:
			if (!vbvolt)
				break;
			if (new_dev != ATTACHED_DEV_JIG_USB_ON_MUIC) {
				new_dev = ATTACHED_DEV_JIG_USB_ON_MUIC;
				pr_info("%s:%s: ADC JIG_USB_ON DETECTED\n", MUIC_DEV_NAME, __func__);
			}
			break;
		case ADC_JIG_UART_OFF:
			if (muic_data->is_otg_test) {
				mdelay(1000);
				val7 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_SC_STATUS2);
				vmid = val7 & 0x7;
				pr_info("%s:%s: vmid : 0x%x \n", MUIC_DEV_NAME, __func__, vmid);
				if (vmid == 0x4) {
					pr_info("%s:%s: ADC OTG_TEST DETECTED, vmid = %d\n",
							MUIC_DEV_NAME, __func__, vmid);
					vbvolt = 1;
				}
				new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
			}
			else if (vbvolt) {
				new_dev = ATTACHED_DEV_JIG_UART_OFF_VB_MUIC;
				pr_info("%s:%s: ADC JIG_UART_OFF_VB DETECTED\n",
							MUIC_DEV_NAME, __func__);
			}
			else {
				new_dev = ATTACHED_DEV_JIG_UART_OFF_MUIC;
				pr_info("%s:%s: ADC JIG_UART_OFF DETECTED\n",
							MUIC_DEV_NAME, __func__);
			}
			break;
		case ADC_JIG_UART_ON:
			if (new_dev != ATTACHED_DEV_JIG_UART_ON_MUIC) {
				new_dev = ATTACHED_DEV_JIG_UART_ON_MUIC;
				pr_info("%s:%s: ADC JIG_UART_ON DETECTED\n",
							MUIC_DEV_NAME, __func__);
			}
			break;
		case ADC_DESKDOCK:
			if (vbvolt) {
				new_dev = ATTACHED_DEV_DESKDOCK_VB_MUIC;
				pr_info("%s:%s: ADC DESKDOCK+TA DETECTED\n",
							MUIC_DEV_NAME, __func__);
			}
			else {
				new_dev = ATTACHED_DEV_DESKDOCK_MUIC;
				pr_info("%s:%s: ADC DESKDOCK DETECTED\n",
							MUIC_DEV_NAME, __func__);
			}
			break;
#if defined(CONFIG_LANHUB_SUPPORT)
		case ADC_USB_LANHUB:
			new_dev = ATTACHED_DEV_USB_LANHUB_MUIC;
			pr_info("%s:%s: ADC LANHUB DETECTED\n", MUIC_DEV_NAME, __func__);
			break;
#endif			
		case ADC_OPEN:
			break;
		default:
			pr_info("%s:%s: unsupported ADC(0x%02x)\n", MUIC_DEV_NAME, __func__, adc);
			break;
		}
	}

	}	// End For EVT0

	if ((ATTACHED_DEV_UNKNOWN_MUIC == new_dev) && (ADC_OPEN != adc)) {
		if (vbvolt) {
			new_dev = ATTACHED_DEV_UNDEFINED_CHARGING_MUIC;
			pr_info("%s:%s: UNDEFINED VB DETECTED\n", MUIC_DEV_NAME, __func__);
		}
	}

	if (new_dev != ATTACHED_DEV_UNKNOWN_MUIC) {
		pr_info("%s:%s ATTACHED\n", MUIC_DEV_NAME, __func__);
		s2mu005_muic_handle_attach(muic_data, new_dev, adc, vbvolt);
	}
	else {
		pr_info("%s:%s DETACHED\n", MUIC_DEV_NAME, __func__);
		s2mu005_muic_handle_detach(muic_data);
	}

	if (muic_data->pdata->jig_uart_cb)
		update_jig_state(muic_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#if defined(CONFIG_VBUS_NOTIFIER)
	vbus_notifier_handle((!!vbvolt) ? STATUS_VBUS_HIGH : STATUS_VBUS_LOW);
#endif /* CONFIG_VBUS_NOTIFIER */

}

static int s2mu005_muic_reg_init(struct s2mu005_muic_data *muic_data)
{
	struct i2c_client *i2c = muic_data->i2c;
	int ret;
<<<<<<< HEAD
	int val1, val2, val3, adc;

	pr_err("[muic] %s\n", __func__);

#if 0
	ret = s2mu005_i2c_read_byte(i2c, S2MU005_MUIC_REG_DEVID);
	if (ret == 0x18)
		muic_data->rev_id = 2;
	else
		muic_data->rev_id = 0;
#endif
=======
	int val1, val2, val3, val4, adc, ctrl1;

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	val1 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE1);
	val2 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE2);
	val3 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_TYPE3);
<<<<<<< HEAD
	adc = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_ADC);
	pr_err("[muic] dev[1:0x%x, 2:0x%x, 3:0x%x], adc:0x%x\n", val1, val2, val3, adc);

	ret = s2mu005_i2c_guaranteed_wbyte(i2c,
			S2MU005_REG_MUIC_CTRL1, CTRL_MASK);
	if (ret < 0)
		pr_err("[muic] failed to write ctrl(%d)\n", ret);
=======
	val4 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
	val4 &= 0x03;
	adc = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_ADC);
	pr_info("%s:%s: dev[1:0x%x, 2:0x%x, 3:0x%x], adc:0x%x\n", MUIC_DEV_NAME, __func__,
									val1, val2, val3, adc);

	if ((val1 & DEV_TYPE1_USB_TYPES) ||
				(val2 & DEV_TYPE2_JIG_USB_TYPES)) {
			ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_SW_CTRL, val4 | MANUAL_SW_USB);
			if (ret < 0)
				pr_err("%s:%s usb type detect err %d\n",
					   MUIC_DEV_NAME, __func__, ret);
	} else if (val2 & DEV_TYPE2_JIG_UART_TYPES) {
			ret = s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_SW_CTRL, val4 | MANUAL_SW_UART);
			if (ret < 0)
				pr_err("%s:%s uart type detect err %d\n",
						MUIC_DEV_NAME, __func__, ret);
	}

	ret = s2mu005_i2c_write_byte(i2c,
			S2MU005_REG_MUIC_CTRL1, CTRL_MASK);

	if (ret < 0)
		pr_err( "%s:%s: failed to write ctrl(%d)\n", MUIC_DEV_NAME, __func__, ret);

	ctrl1 = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);
	pr_info("%s:%s: CTRL1:0x%02x\n", MUIC_DEV_NAME, __func__, ctrl1);
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
	s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_LDOADC_VSETL, LDOADC_VSET_3V);
	s2mu005_i2c_write_byte(i2c, S2MU005_REG_MUIC_LDOADC_VSETH, LDOADC_VSET_3V);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

static irqreturn_t s2mu005_muic_irq_thread(int irq, void *data)
{
	struct s2mu005_muic_data *muic_data = data;
<<<<<<< HEAD

	mutex_lock(&muic_data->muic_mutex);
	wake_lock(&muic_data->wake_lock);

	pr_err("%s:%s\n", MFD_DEV_NAME, __func__);

=======
	struct i2c_client *i2c = muic_data->i2c;
	enum s2mu005_reg_manual_sw_value reg_val;
	int ctrl, ret = 0;
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
	int vbvolt = 0, adc = 0;
#endif

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	mutex_lock(&muic_data->muic_mutex);
	wake_lock(&muic_data->wake_lock);
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
	vbvolt = !!(s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_DEVICE_APPLE) 
				& DEV_TYPE_APPLE_VBUS_WAKEUP);
	adc = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_ADC) & ADC_MASK;
	pr_info("%s:%s vbvolt : %d, adc: 0x%X, irq : %d\n",
				MFD_DEV_NAME, __func__, vbvolt, adc, irq);

	if (!vbvolt) {
		if (IS_AUDIO_ADC(adc) && !muic_data->is_water_wa) {
			if (irq == muic_data->irq_adc_change) {
				s2mu005_muic_set_water_wa(muic_data, true);
			}
		} else if (IS_WATER_ADC(adc) && !muic_data->is_water_wa) {
			if (irq == muic_data->irq_attach) {
				s2mu005_muic_set_water_wa(muic_data, true);
			}
		}
	}

	if (adc == ADC_OPEN
		&& irq ==  muic_data->irq_adc_change
		&& muic_data->is_water_wa) {
		usleep_range(WATER_TOGGLE_WA_MIN_DURATION_US, WATER_TOGGLE_WA_MAX_DURATION_US);
		s2mu005_muic_set_water_wa(muic_data, false);
	}
#endif
	/* check for muic reset and re-initialize registers */
	ctrl = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_CTRL1);

	if (ctrl == 0xDF) {
		/* CONTROL register is reset to DF */
#ifdef DEBUG_MUIC
		s2mu005_print_reg_log();
		s2mu005_print_reg_dump(muic_data);
#endif
		pr_err("%s:%s: err muic could have been reseted. Initilize!!\n",
						MUIC_DEV_NAME, __func__);
		s2mu005_muic_reg_init(muic_data);
		if (muic_data->is_rustproof) {
			pr_info("%s:%s: rustproof is enabled\n", MUIC_DEV_NAME, __func__);
			reg_val = MANSW_OPEN;
			ret = s2mu005_i2c_write_byte(i2c,
				S2MU005_REG_MUIC_SW_CTRL, reg_val);
			if (ret < 0)
				pr_err("%s:%s: err write MANSW\n", MUIC_DEV_NAME, __func__);
			ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
			pr_info("%s:%s: MUIC_SW_CTRL=0x%x\n ", MUIC_DEV_NAME, __func__, ret);
		} else {
			reg_val = MANSW_UART;
			ret = s2mu005_i2c_write_byte(i2c,
				S2MU005_REG_MUIC_SW_CTRL, reg_val);
			if (ret < 0)
				pr_err("%s:%s: err write MANSW\n", MUIC_DEV_NAME, __func__);
			ret = s2mu005_i2c_read_byte(i2c, S2MU005_REG_MUIC_SW_CTRL);
			pr_info("%s:%s: MUIC_SW_CTRL=0x%x\n ", MUIC_DEV_NAME, __func__, ret);
		}
#ifdef DEBUG_MUIC
		s2mu005_print_reg_dump(muic_data);
#endif
		/* MUIC Interrupt On */
		ret = set_ctrl_reg(muic_data, CTRL_INT_MASK_SHIFT, false);
#if defined (CONFIG_SEC_FACTORY) && defined (CONFIG_USB_HOST_NOTIFY)
		init_otg_reg(muic_data);
#endif
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* device detection */
	s2mu005_muic_detect_dev(muic_data);

	wake_unlock(&muic_data->wake_lock);
	mutex_unlock(&muic_data->muic_mutex);

	return IRQ_HANDLED;
}

static int s2mu005_init_rev_info(struct s2mu005_muic_data *muic_data)
{
	u8 dev_id;
	int ret = 0;

<<<<<<< HEAD
	pr_err("[muic] %s\n", __func__);

	dev_id = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_REV_ID);
	if (dev_id < 0) {
		pr_err("[muic] %s(%d)\n", __func__, dev_id);
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	dev_id = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_REV_ID);
	if (dev_id < 0) {
		pr_err( "%s:%s: dev_id(%d)\n", MUIC_DEV_NAME, __func__, dev_id);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		ret = -ENODEV;
	} else {
		muic_data->muic_vendor = 0x05;
		muic_data->muic_version = (dev_id & 0x0F);
<<<<<<< HEAD
		pr_err("[muic] %s : vendor=0x%x, ver=0x%x\n",
			__func__, muic_data->muic_vendor,
			muic_data->muic_version);
=======
		pr_info( "%s:%s: vendor=0x%x, ver=0x%x, dev_id=0x%x\n", MUIC_DEV_NAME, __func__,
					muic_data->muic_vendor, muic_data->muic_version, dev_id);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}
	return ret;
}

#define REQUEST_IRQ(_irq, _dev_id, _name)				\
do {									\
	ret = request_threaded_irq(_irq, NULL, s2mu005_muic_irq_thread,	\
				0, _name, _dev_id);	\
	if (ret < 0) {							\
		pr_err("%s:%s Failed to request IRQ #%d: %d\n",		\
				MUIC_DEV_NAME, __func__, _irq, ret);	\
		_irq = 0;						\
	}								\
} while (0)

static int s2mu005_muic_irq_init(struct s2mu005_muic_data *muic_data)
{
	int ret = 0;

	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	if (muic_data->mfd_pdata && (muic_data->mfd_pdata->irq_base > 0)) {
		int irq_base = muic_data->mfd_pdata->irq_base;

		/* request MUIC IRQ */
		muic_data->irq_attach = irq_base + S2MU005_MUIC_IRQ1_ATTATCH;
		REQUEST_IRQ(muic_data->irq_attach, muic_data, "muic-attach");

		muic_data->irq_detach = irq_base + S2MU005_MUIC_IRQ1_DETACH;
		REQUEST_IRQ(muic_data->irq_detach, muic_data, "muic-detach");

<<<<<<< HEAD
		muic_data->irq_rid_chg = irq_base + S2MU005_MUIC_IRQ1_RID_CHG;
		REQUEST_IRQ(muic_data->irq_rid_chg, muic_data, "muic-rid_chg");

		muic_data->irq_vbus_on = irq_base + S2MU005_MUIC_IRQ2_VBUS_ON;
		REQUEST_IRQ(muic_data->irq_vbus_on, muic_data, "muic-vbus_on");

		muic_data->irq_rsvd_attach = irq_base + S2MU005_MUIC_IRQ2_RSVD_ATTACH;
		REQUEST_IRQ(muic_data->irq_rsvd_attach, muic_data, "muic-rsvd_attach");

		muic_data->irq_adc_change = irq_base + S2MU005_MUIC_IRQ2_ADC_CHANGE;
		REQUEST_IRQ(muic_data->irq_adc_change, muic_data, "muic-adc_change");

		muic_data->irq_av_charge = irq_base + S2MU005_MUIC_IRQ2_AV_CHARGE;
		REQUEST_IRQ(muic_data->irq_av_charge, muic_data, "muic-av_charge");

		muic_data->irq_vbus_off = irq_base + S2MU005_MUIC_IRQ2_VBUS_OFF;
		REQUEST_IRQ(muic_data->irq_vbus_off, muic_data, "muic-vbus_off");

	}

	pr_err("%s:%s\n", MFD_DEV_NAME, __func__);
	pr_err("%s:%s muic-attach(%d), muic-detach(%d), muic-rid_chg(%d), muic-vbus_on(%d)",
		MUIC_DEV_NAME, __func__, muic_data->irq_attach,	muic_data->irq_detach, muic_data->irq_rid_chg,	\
			muic_data->irq_vbus_on);
	pr_err("muic-rsvd_attach(%d), muic-adc_change(%d), muic-av_charge(%d), muic-vbus_off(%d)\n",
		muic_data->irq_rsvd_attach, muic_data->irq_adc_change, muic_data->irq_av_charge, muic_data->irq_vbus_off);
=======
		muic_data->irq_vbus_on = irq_base + S2MU005_MUIC_IRQ2_VBUS_ON;
		REQUEST_IRQ(muic_data->irq_vbus_on, muic_data, "muic-vbus_on");

		muic_data->irq_adc_change = irq_base + S2MU005_MUIC_IRQ2_ADC_CHANGE;
		REQUEST_IRQ(muic_data->irq_adc_change, muic_data, "muic-adc_change");

		muic_data->irq_vbus_off = irq_base + S2MU005_MUIC_IRQ2_VBUS_OFF;
		REQUEST_IRQ(muic_data->irq_vbus_off, muic_data, "muic-vbus_off");
	}

	pr_info("%s:%s: muic-attach(%d), muic-detach(%d), muic-vbus_on(%d), muic-adc_change(%d), muic-vbus_off(%d)\n",
			MUIC_DEV_NAME, __func__, muic_data->irq_attach, muic_data->irq_detach,
			muic_data->irq_vbus_on, muic_data->irq_adc_change, muic_data->irq_vbus_off);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

#define FREE_IRQ(_irq, _dev_id, _name)					\
do {									\
	if (_irq) {							\
		free_irq(_irq, _dev_id);				\
		pr_info("%s:%s IRQ(%d):%s free done\n", MUIC_DEV_NAME,	\
				__func__, _irq, _name);			\
	}								\
} while (0)

static void s2mu005_muic_free_irqs(struct s2mu005_muic_data *muic_data)
{
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	/* free MUIC IRQ */
	FREE_IRQ(muic_data->irq_attach, muic_data, "muic-attach");
	FREE_IRQ(muic_data->irq_detach, muic_data, "muic-detach");
<<<<<<< HEAD
	FREE_IRQ(muic_data->irq_rid_chg, muic_data, "muic-rid_chg");
	FREE_IRQ(muic_data->irq_vbus_on, muic_data, "muic-vbus_on");
	FREE_IRQ(muic_data->irq_rsvd_attach, muic_data, "muic-rsvd_attach");
	FREE_IRQ(muic_data->irq_adc_change, muic_data, "muic-adc_change");
	FREE_IRQ(muic_data->irq_av_charge, muic_data, "muic-av_charge");
=======
	FREE_IRQ(muic_data->irq_vbus_on, muic_data, "muic-vbus_on");
	FREE_IRQ(muic_data->irq_adc_change, muic_data, "muic-adc_change");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	FREE_IRQ(muic_data->irq_vbus_off, muic_data, "muic-vbus_off");
}

#if defined(CONFIG_OF)
static int of_s2mu005_muic_dt(struct device *dev, struct s2mu005_muic_data *muic_data)
{
	struct device_node *np, *np_muic;
<<<<<<< HEAD
=======
	struct muic_platform_data *pdata = muic_data->pdata;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	int ret = 0;
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	np = dev->parent->of_node;
	if (!np) {
<<<<<<< HEAD
		pr_err("[muic] %s : could not find np\n", __func__);
		return -ENODEV;
	}

	np_muic = of_find_node_by_name(np, "muic");
	if (!np_muic) {
		pr_err("[muic] %s : could not find muic sub-node np_muic\n", __func__);
=======
		pr_err("%s:%s: could not find np\n", MUIC_DEV_NAME, __func__);
		return -ENODEV;
	}

	np_muic = of_find_node_by_name(NULL, "muic");
	if (!np_muic) {
		pr_err("%s:%s: could not find muic sub-node np_muic\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return -EINVAL;
	}

#if !defined(CONFIG_MUIC_UART_SWITCH)
	if (of_gpio_count(np_muic) < 1) {
<<<<<<< HEAD
		pr_err("[muic] %s : could not find muic gpio\n", __func__);
		muic_data->pdata->gpio_uart_sel = 0;
	} else
		muic_data->pdata->gpio_uart_sel = of_get_gpio(np_muic, 0);
#else
	muic_data->pdata->uart_addr =
		(const char *)of_get_property(np_muic, "muic,uart_addr", NULL);
	muic_data->pdata->uart_txd =
		(const char *)of_get_property(np_muic, "muic,uart_txd", NULL);
	muic_data->pdata->uart_rxd =
		(const char *)of_get_property(np_muic, "muic,uart_rxd", NULL);
#endif

=======
		pr_err("%s:%s: could not find muic gpio\n", MUIC_DEV_NAME, __func__);
		muic_data->pdata->gpio_uart_sel = 0;
	} else
		muic_data->pdata->gpio_uart_sel = of_get_gpio(np_muic, 0);
#endif
	pdata->is_new_factory = of_property_read_bool(np_muic, "new_factory");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	return ret;
}
#endif /* CONFIG_OF */

/* if need to set s2mu005 pdata */
static struct of_device_id s2mu005_muic_match_table[] = {
	{ .compatible = "samsung,s2mu005-muic",},
	{},
};

static int s2mu005_muic_probe(struct platform_device *pdev)
{
	struct s2mu005_dev *s2mu005 = dev_get_drvdata(pdev->dev.parent);
	struct s2mu005_platform_data *mfd_pdata = dev_get_platdata(s2mu005->dev);
	struct s2mu005_muic_data *muic_data;
	int ret = 0;

<<<<<<< HEAD
	pr_err("[muic] %s:%s\n", MFD_DEV_NAME, __func__);

	muic_data = kzalloc(sizeof(struct s2mu005_muic_data), GFP_KERNEL);
	if (!muic_data) {
		pr_err("[muic] %s: failed to allocate driver data\n", __func__);
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);

	muic_data = kzalloc(sizeof(struct s2mu005_muic_data), GFP_KERNEL);
	if (!muic_data) {
		pr_err( "%s:%s: failed to allocate driver data\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		ret = -ENOMEM;
		goto err_return;
	}

	if (!mfd_pdata) {
<<<<<<< HEAD
		pr_err("%s: failed to get s2mu005 mfd platform data\n", __func__);
=======
		pr_err("%s:%s: failed to get s2mu005 mfd platform data\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		ret = -ENOMEM;
		goto err_kfree;
	}

	/* save platfom data for gpio control functions */

	muic_data->dev = &pdev->dev;
	muic_data->i2c = s2mu005->i2c;
	muic_data->mfd_pdata = mfd_pdata;
	muic_data->pdata = &muic_pdata;
<<<<<<< HEAD
#if defined(CONFIG_OF)
	ret = of_s2mu005_muic_dt(&pdev->dev, muic_data);
	if (ret < 0)
		pr_err("[muic] no muic dt! ret[%d]\n", ret);
=======
	pr_info("factory_uart: %d\n", muic_data->pdata->is_factory_uart);
#if defined(CONFIG_OF)
	ret = of_s2mu005_muic_dt(&pdev->dev, muic_data);
	if (ret < 0)
		pr_err( "%s:%s: no muic dt! ret[%d]\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif /* CONFIG_OF */

	mutex_init(&muic_data->muic_mutex);
	muic_data->is_factory_start = false;
	muic_data->attached_dev = ATTACHED_DEV_UNKNOWN_MUIC;
	muic_data->is_usb_ready = false;
<<<<<<< HEAD
	platform_set_drvdata(pdev, muic_data);

#if !defined(CONFIG_MUIC_UART_SWITCH)
	if (muic_pdata.gpio_uart_sel)
#endif
		muic_pdata.set_gpio_uart_sel = s2mu005_set_gpio_uart_sel;
=======
	muic_data->jigonb_enable = false;
	muic_data->jig_disable = false;
#if !defined (CONFIG_SEC_FACTORY) && !defined (CONFIG_MUIC_S2MU005_WATER_WA_DISABLE)
	muic_data->is_water_wa = false;
#endif
	platform_set_drvdata(pdev, muic_data);

	if (muic_data->pdata->init_gpio_cb)
		ret = muic_data->pdata->init_gpio_cb(get_switch_sel());
	if (ret) {
		pr_err( "%s:%s: failed to init gpio(%d)\n", MUIC_DEV_NAME, __func__, ret);
		goto fail_init_gpio;
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifdef CONFIG_SEC_SYSFS
	/* create sysfs group */
	ret = sysfs_create_group(&switch_device->kobj, &s2mu005_muic_group);
	if (ret) {
<<<<<<< HEAD
		pr_err("[muic] failed to create sysfs\n");
=======
		pr_err( "%s:%s: failed to create sysfs\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto fail;
	}
	dev_set_drvdata(switch_device, muic_data);
#endif

	ret = s2mu005_init_rev_info(muic_data);
	if (ret) {
<<<<<<< HEAD
		pr_err("[muic] failed to init muic(%d)\n", ret);
=======
		pr_err( "%s:%s: failed to init muic(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto fail;
	}

	ret = s2mu005_muic_reg_init(muic_data);
	if (ret) {
<<<<<<< HEAD
		pr_err("[muic] failed to init muic(%d)\n", ret);
		goto fail;
	}

#if 0
	ret = s2mu005_i2c_read_byte(muic_data->i2c, S2MU005_REG_MUIC_SW_CTRL);
	if (ret < 0)
		pr_err("[muic] %s: err MANSW (%d)\n", __func__, ret);
	else {
		/* RUSTPROOF : disable UART connection if MANSW
			from BL is OPEN_RUSTPROOF */
		if (ret == MANSW_OPEN_RUSTPROOF) {
			muic_data->is_rustproof = true;
			com_to_open_with_vbus(muic_data);
		} else {
			muic_data->is_rustproof = false;
		}
	}
#else
	muic_data->is_rustproof = muic_data->pdata->rustproof_on;
#endif
=======
		pr_err( "%s:%s: failed to init muic(%d)\n", MUIC_DEV_NAME, __func__, ret);
		goto fail;
	}

	/* For Rustproof */
	muic_data->is_rustproof = muic_data->pdata->rustproof_on;
	if (muic_data->is_rustproof) {
		pr_info( "%s:%s: rustproof is enabled\n", MUIC_DEV_NAME, __func__);
		com_to_open(muic_data);
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (muic_data->pdata->init_switch_dev_cb)
		muic_data->pdata->init_switch_dev_cb();

	ret = s2mu005_muic_irq_init(muic_data);
	if (ret) {
<<<<<<< HEAD
		pr_err("[muic] %s: failed to init irq(%d)\n", __func__, ret);
=======
		pr_err( "%s:%s: failed to init irq(%d)\n", MUIC_DEV_NAME, __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto fail_init_irq;
	}

	wake_lock_init(&muic_data->wake_lock, WAKE_LOCK_SUSPEND, "muic_wake");

	/* initial cable detection */
<<<<<<< HEAD
	set_int_mask(muic_data, false);
#ifdef CONFIG_SEC_FACTORY
=======
	ret = set_ctrl_reg(muic_data, CTRL_INT_MASK_SHIFT, false);
#if defined (CONFIG_SEC_FACTORY) && defined (CONFIG_USB_HOST_NOTIFY)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	init_otg_reg(muic_data);
#endif
	s2mu005_muic_irq_thread(-1, muic_data);

	return 0;

fail_init_irq:
	s2mu005_muic_free_irqs(muic_data);
fail:
#ifdef CONFIG_SEC_SYSFS
	sysfs_remove_group(&switch_device->kobj, &s2mu005_muic_group);
#endif
	mutex_destroy(&muic_data->muic_mutex);
<<<<<<< HEAD
=======
fail_init_gpio:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
err_kfree:
	kfree(muic_data);
err_return:
	return ret;
}

static int s2mu005_muic_remove(struct platform_device *pdev)
{
	struct s2mu005_muic_data *muic_data = platform_get_drvdata(pdev);
#ifdef CONFIG_SEC_SYSFS
	sysfs_remove_group(&switch_device->kobj, &s2mu005_muic_group);
#endif

	if (muic_data) {
<<<<<<< HEAD
		pr_err("[muic] %s\n", __func__);
=======
		pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		disable_irq_wake(muic_data->i2c->irq);
		s2mu005_muic_free_irqs(muic_data);
		mutex_destroy(&muic_data->muic_mutex);
		i2c_set_clientdata(muic_data->i2c, NULL);
		kfree(muic_data);
	}
	return 0;
}

static void s2mu005_muic_shutdown(struct device *dev)
{
<<<<<<< HEAD
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
	int ret;

	pr_err("[muic] %s\n", __func__);
	if (!muic_data->i2c) {
		pr_err("[muic] %s no muic i2c client\n", __func__);
		return;
	}

	pr_err("[muic] open D+,D-,V_bus line\n");
	ret = com_to_open(muic_data);
	if (ret < 0)
		pr_err("[muic] fail to open mansw\n");

	/* set auto sw mode before shutdown to make sure device goes into */
	/* LPM charging when TA or USB is connected during off state */
	pr_err("[muic] muic auto detection enable\n");
	ret = set_manual_sw(muic_data, true);
	if (ret < 0) {
		pr_err("[muic] %s fail to update reg\n", __func__);
		return;
	}
=======
#if !defined(CONFIG_MUIC_S2MU005_JIGB_CONTROL)
		struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);
		int ret;
#endif
	
		pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
		
#if !defined(CONFIG_MUIC_S2MU005_JIGB_CONTROL)
		if (!muic_data->i2c) {
			pr_err( "%s:%s: no muic i2c client\n", MUIC_DEV_NAME, __func__);
			return;
		}
	
		pr_info("%s:%s: open D+,D-,V_bus line\n", MUIC_DEV_NAME, __func__);
		ret = com_to_open(muic_data);
		if (ret < 0)
			pr_err( "%s:%s: fail to open mansw\n", MUIC_DEV_NAME, __func__);
	
		/* set auto sw mode before shutdown to make sure device goes into */
		/* LPM charging when TA or USB is connected during off state */
		pr_info("%s:%s: muic auto detection enable\n", MUIC_DEV_NAME, __func__);
		ret = set_ctrl_reg(muic_data, CTRL_MANUAL_SW_SHIFT, true);
		if (ret < 0) {
			pr_err( "%s:%s: fail to update reg\n", MUIC_DEV_NAME, __func__);
			return;
		}
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

#if defined CONFIG_PM
static int s2mu005_muic_suspend(struct device *dev)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

<<<<<<< HEAD
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	muic_data->suspended = true;

	return 0;
}

static int s2mu005_muic_resume(struct device *dev)
{
	struct s2mu005_muic_data *muic_data = dev_get_drvdata(dev);

<<<<<<< HEAD
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	muic_data->suspended = false;

	if (muic_data->need_to_noti) {
		if (muic_data->attached_dev)
			muic_notifier_attach_attached_dev(muic_data->attached_dev);
		else
			muic_notifier_detach_attached_dev(muic_data->attached_dev);
		muic_data->need_to_noti = false;
	}

	return 0;
}
#else
#define s2mu005_muic_suspend NULL
#define s2mu005_muic_resume NULL
#endif

static SIMPLE_DEV_PM_OPS(s2mu005_muic_pm_ops, s2mu005_muic_suspend,
			 s2mu005_muic_resume);

static struct platform_driver s2mu005_muic_driver = {
	.driver = {
		.name = "s2mu005-muic",
		.owner	= THIS_MODULE,
		.of_match_table = s2mu005_muic_match_table,
#ifdef CONFIG_PM
		.pm = &s2mu005_muic_pm_ops,
#endif
		.shutdown = s2mu005_muic_shutdown,
	},
	.probe = s2mu005_muic_probe,
	.remove = s2mu005_muic_remove,
};

static int __init s2mu005_muic_init(void)
{
<<<<<<< HEAD
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	return platform_driver_register(&s2mu005_muic_driver);
}
module_init(s2mu005_muic_init);

static void __exit s2mu005_muic_exit(void)
{
<<<<<<< HEAD
=======
	pr_info("%s:%s\n", MUIC_DEV_NAME, __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	platform_driver_unregister(&s2mu005_muic_driver);
}
module_exit(s2mu005_muic_exit);

<<<<<<< HEAD
MODULE_DESCRIPTION("S2MU005 USB Switch driver");
=======
MODULE_DESCRIPTION("S.LSI S2MU005 MUIC driver");
MODULE_AUTHOR("<insun77.choi@samsung.com>");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
MODULE_LICENSE("GPL");
