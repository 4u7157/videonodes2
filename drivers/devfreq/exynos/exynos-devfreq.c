/* linux/drivers/devfreq/exynos-devfreq.c
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * Samsung EXYNOS SoC series devfreq common driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 2 of the License,
 * or (at your option) any later version.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/reboot.h>
<<<<<<< HEAD
#include <linux/suspend.h>
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#include <linux/exynos-ss.h>

#include <soc/samsung/exynos-devfreq.h>
#include <soc/samsung/tmu.h>
#include <soc/samsung/ect_parser.h>

#include "../governor.h"

<<<<<<< HEAD
#define CREATE_TRACE_POINTS
#include <trace/events/exynos.h>

static int exynos_devfreq_tmu_notifier(struct notifier_block *nb, unsigned long event, void *v);
static int exynos_devfreq_set_voltage(u32 *target_volt, struct exynos_devfreq_data *data);
=======
static int exynos_devfreq_tmu_notifier(struct notifier_block *nb,
					unsigned long event, void *v);
static int exynos_devfreq_set_voltage(struct device *dev, u32 *target_volt,
					struct exynos_devfreq_data *data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

struct exynos_devfreq_init_func {
	int (*init_prepare)(struct exynos_devfreq_data *);
};

static struct exynos_devfreq_init_func exynos_devfreq_init[DEVFREQ_TYPE_END];
static struct exynos_devfreq_data *devfreq_data[DEVFREQ_TYPE_END];

#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
static ssize_t show_exynos_devfreq_info(struct device *dev,
					struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
	int i;

	count = snprintf(buf, PAGE_SIZE, "[Exynos DEVFREQ Data]\n"
<<<<<<< HEAD
			 "devfreq dev name : %20s\n"
			 "devfreq type     : %20d\n"
			 "Exynos SS flag   : %20u\n",
			 dev_name(data->dev), data->devfreq_type, data->ess_flag);

	count += snprintf(buf + count, PAGE_SIZE, "\n<Frequency data>\n"
			  "OPP list length  : %20u\n", data->max_state);
	count += snprintf(buf + count, PAGE_SIZE, "freq opp table\n");
	count += snprintf(buf + count, PAGE_SIZE, "\t  idx      freq       volt\n");

	for (i = 0; i < data->max_state; i++)
		count += snprintf(buf + count, PAGE_SIZE, "\t%5u %10u %10u\n",
				  data->opp_list[i].idx, data->opp_list[i].freq,
				  data->opp_list[i].volt);

	count += snprintf(buf + count, PAGE_SIZE,
			  "default_qos     : %20u\n" "initial_freq    : %20lu\n"
			  "min_freq        : %20u\n" "max_freq        : %20u\n"
			  "boot_timeout(s) : %20u\n" "max_state       : %20u\n"
			  "use_switch_clk  : %20s\n",
			  data->default_qos, data->devfreq_profile.initial_freq,
			  data->min_freq, data->max_freq, data->boot_qos_timeout, data->max_state,
			  data->use_switch_clk ? "true" : "false");

	count += snprintf(buf + count, PAGE_SIZE, "\n<Governor data>\n");
	count += snprintf(buf + count, PAGE_SIZE,
			  "governor_name   : %20s\n" "use_get_dev     : %20s\n"
			  "polling_ms(ms)  : %20u\n",
			  data->governor_name, data->use_get_dev ? "true" : "false",
			  data->devfreq_profile.polling_ms);

	if (data->use_get_dev) {
		/* This will be needed later */
	}

	count += snprintf(buf + count, PAGE_SIZE, "\n<Regulator data>\n"
			  "use_regulator   : %20s\n" "use_pd_off: %20s\n",
			  data->use_regulator ? "true" : "false",
			  data->use_pd_off ? "true" : "false");

	if (data->use_regulator) {
		count += snprintf(buf + count, PAGE_SIZE,
				  "regulator_name  : %20s\n" "regulator_max_uV: %20u\n"
				  "cold_volt_offset: %20u\n" "limit_cold_volt : %20u\n"
				  "min_cold_volt   : %20u\n"
				  "use_tmu         : %20s\n" "cl_dvfs         : %20s\n",
				  data->regulator_name, data->reg_max_volt,
				  data->cold_volt_offset, data->limit_cold_volt,
				  data->min_cold_volt,
				  data->use_tmu ? "true" : "false",
				  data->use_cl_dvfs ? "true" : "false");
	}

	count += snprintf(buf + count, PAGE_SIZE, "\n<UM data>\n"
			  "use_um        : %20s\n", data->use_um ? "true" : "false");

	if (data->use_um) {

		count += snprintf(buf + count, PAGE_SIZE,
				  "um_type       : %20u\n" "um_count      : %20u\n",
				  data->um_data.type, data->um_data.um_count);

		count += snprintf(buf + count, PAGE_SIZE, "um_list\n");
		for (i = 0; i < data->um_data.um_count; i++)
			count += snprintf(buf + count, PAGE_SIZE, "\t0x%08X\n", data->um_base[i]);
=======
			"devfreq dev name : %20s\n"
			"devfreq type     : %20d\n"
			"Exynos SS flag   : %20u\n",
			dev_name(data->dev), data->devfreq_type, data->ess_flag);

	count += snprintf(buf + count, PAGE_SIZE, "\n<Frequency data>\n"
			"OPP list length  : %20u\n", data->opp_list_length);
	count += snprintf(buf + count, PAGE_SIZE, "freq opp table\n");
	count += snprintf(buf + count, PAGE_SIZE,
				"\t  idx      freq       volt\n");

	for (i = 0; i < data->opp_list_length; i++)
		count += snprintf(buf + count, PAGE_SIZE, "\t%5u %10u %10u\n",
				data->opp_list[i].idx, data->opp_list[i].freq,
				data->opp_list[i].volt);

	count += snprintf(buf + count, PAGE_SIZE,
			"default_qos     : %20u\n" "initial_freq    : %20lu\n"
			"cal_qos_max     : %20u\n" "min_freq        : %20u\n"
			"max_freq        : %20u\n" "boot_timeout(s) : %20u\n"
			"max_state       : %20u\n" "use_switch_clk  : %20s\n",
			data->default_qos, data->devfreq_profile.initial_freq,
			data->cal_qos_max, data->min_freq, data->max_freq,
			data->boot_qos_timeout, data->max_state,
			data->use_switch_clk ? "true" : "false");

	count += snprintf(buf + count, PAGE_SIZE, "\n<Governor data>\n");
	count += snprintf(buf + count, PAGE_SIZE,
			"governor_name   : %20s\n" "use_get_dev     : %20s\n"
			"polling_ms(ms)  : %20u\n",
			data->governor_name, data->use_get_dev ? "true" : "false",
			data->devfreq_profile.polling_ms);

	if (data->use_get_dev) {
		if (data->gov_type == SIMPLE_ONDEMAND) {
			count += snprintf(buf + count, PAGE_SIZE,
					"upthreshold     : %20u\n" "downdifferential: %20u\n"
					"multi_weight    : %20u\n",
					data->simple_ondemand_data.upthreshold,
					data->simple_ondemand_data.downdifferential,
					data->simple_ondemand_data.multiplication_weight);
		} else if (data->gov_type == SIMPLE_EXYNOS) {
			count += snprintf(buf + count, PAGE_SIZE,
					"urgentthreshold : %20u\n" "upthreshold     : %20u\n"
					"downthreshold   : %20u\n" "idlethreshold   : %20u\n",
					data->simple_exynos_data.urgentthreshold,
					data->simple_exynos_data.upthreshold,
					data->simple_exynos_data.downthreshold,
					data->simple_exynos_data.idlethreshold);
		}
	}

	count += snprintf(buf + count, PAGE_SIZE, "\n<Regulator data>\n"
			"use_regulator   : %20s\n" "use_regulator_dummy: %20s\n",
			data->use_regulator ? "true" : "false",
			data->use_regulator_dummy ? "true" : "false");

	if (data->use_regulator) {
		count += snprintf(buf + count, PAGE_SIZE,
				"regulator_name  : %20s\n" "regulator_max_uV: %20u\n"
				"cold_volt_offset: %20u\n" "limit_cold_volt : %20u\n"
				"min_cold_volt   : %20u\n"
				"use_tmu         : %20s\n" "cl_dvfs         : %20s\n",
				data->regulator_name, data->reg_max_volt,
				data->cold_volt_offset, data->limit_cold_volt,
				data->min_cold_volt,
				data->use_tmu ? "true" : "false",
				data->use_cl_dvfs ? "true" : "false");
	}

	count += snprintf(buf + count, PAGE_SIZE, "\n<PPMU data>\n"
			"use_ppmu        : %20s\n", data->use_ppmu ? "true" : "false");

	if (data->use_ppmu) {

		count += snprintf(buf + count, PAGE_SIZE,
				"ppmu_type       : %20u\n" "ppmu_count      : %20u\n",
				data->ppmu_data.type, data->ppmu_data.ppmu_count);

		count += snprintf(buf + count, PAGE_SIZE, "ppmu_list\n");
		for (i = 0; i < data->ppmu_data.ppmu_count; i++)
			count += snprintf(buf + count, PAGE_SIZE, "\t0x%08X\n",
						data->ppmu_base[i]);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	return count;
}

static ssize_t show_exynos_devfreq_get_freq(struct device *dev,
<<<<<<< HEAD
					    struct device_attribute *attr, char *buf)
=======
					struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
	u32 get_freq = 0;

	if (data->ops.get_freq) {
<<<<<<< HEAD
		if (data->ops.get_freq(data->dev, &get_freq, data->clk))
=======
		if (data->ops.get_freq(data->dev, &get_freq, data))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			dev_err(data->dev, "failed get freq\n");
	}

	count = snprintf(buf, PAGE_SIZE, "%10u Khz\n", get_freq);

	return count;
}

static ssize_t show_exynos_devfreq_cmu_dump(struct device *dev,
<<<<<<< HEAD
					    struct device_attribute *attr, char *buf)
=======
					struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

	if (data->ops.cmu_dump) {
		mutex_lock(&data->lock);
<<<<<<< HEAD
		if (data->ops.cmu_dump(data))
=======
		if (data->ops.cmu_dump(data->dev, data))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			dev_err(data->dev, "failed CMU Dump\n");
		mutex_unlock(&data->lock);
	}

	count = snprintf(buf, PAGE_SIZE, "Done\n");

	return count;
}

static ssize_t show_exynos_devfreq_get_delay(struct device *dev,
<<<<<<< HEAD
					     struct device_attribute *attr, char *buf)
=======
					struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

<<<<<<< HEAD
	count += snprintf(buf, PAGE_SIZE, "set frequency delay: %d usec\n", data->setfreq_delay);
	count += snprintf(buf + count, PAGE_SIZE, "set target delay: %d usec\n",
			  data->target_delay);
=======
	count += snprintf(buf, PAGE_SIZE, "set frequency delay: %d usec\n",
						data->setfreq_delay);
	count += snprintf(buf + count, PAGE_SIZE, "set target delay: %d usec\n",
						data->target_delay);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t show_debug_scaling_devfreq_max(struct device *dev,
=======
static ssize_t show_exynos_devfreq_pm_qos_max(struct device *dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
<<<<<<< HEAD
	int val;

	if (data->pm_qos_class_max) {
		val = pm_qos_read_req_value(data->pm_qos_class_max, &data->debug_pm_qos_max);
		if (val < 0) {
			dev_err(dev, "failed to read requested value\n");
			return count;
		}
		count += snprintf(buf, PAGE_SIZE, "%d\n", val);
	}
=======

	if (data->pm_qos_class_max)
		count += snprintf(buf, PAGE_SIZE, "%u\n", pm_qos_request(data->pm_qos_class_max));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t store_debug_scaling_devfreq_max(struct device *dev,
=======
static ssize_t store_exynos_devfreq_pm_qos_max(struct device *dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;
	u32 qos_value;

	ret = sscanf(buf, "%u", &qos_value);
	if (ret != 1)
		return -EINVAL;

	if (data->pm_qos_class_max) {
<<<<<<< HEAD
		if (pm_qos_request_active(&data->debug_pm_qos_max))
			pm_qos_update_request(&data->debug_pm_qos_max, qos_value);
=======
		if (pm_qos_request_active(&data->sys_pm_qos_max))
			pm_qos_update_request(&data->sys_pm_qos_max, qos_value);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	return count;
}

<<<<<<< HEAD
static ssize_t show_debug_scaling_devfreq_min(struct device *dev,
=======
static ssize_t show_exynos_devfreq_pm_qos(struct device *dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
<<<<<<< HEAD
	int val;

	val = pm_qos_read_req_value(data->pm_qos_class, &data->debug_pm_qos_min);
	if (val < 0) {
		dev_err(dev, "failed to read requested value\n");
		return count;
	}

	count += snprintf(buf, PAGE_SIZE, "%d\n", val);
=======

	count += snprintf(buf, PAGE_SIZE, "%u\n", pm_qos_request(data->pm_qos_class));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t store_debug_scaling_devfreq_min(struct device *dev,
=======
static ssize_t store_exynos_devfreq_pm_qos(struct device *dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;
	u32 qos_value;

	ret = sscanf(buf, "%u", &qos_value);
	if (ret != 1)
		return -EINVAL;

<<<<<<< HEAD
	if (pm_qos_request_active(&data->debug_pm_qos_min))
		pm_qos_update_request(&data->debug_pm_qos_min, qos_value);
=======
	if (pm_qos_request_active(&data->sys_pm_qos))
		pm_qos_update_request(&data->sys_pm_qos, qos_value);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

static ssize_t show_exynos_devfreq_disable_pm_qos(struct device *dev,
<<<<<<< HEAD
						  struct device_attribute *attr, char *buf)
=======
					struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

	count += snprintf(buf, PAGE_SIZE, "%s\n",
<<<<<<< HEAD
			  data->devfreq->disabled_pm_qos ? "disabled" : "enabled");
=======
			data->devfreq->disabled_pm_qos ? "disabled" : "enabled");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

static ssize_t store_exynos_devfreq_disable_pm_qos(struct device *dev,
<<<<<<< HEAD
						   struct device_attribute *attr,
						   const char *buf, size_t count)
=======
					struct device_attribute *attr,
					const char *buf, size_t count)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;
	u32 disable;

	ret = sscanf(buf, "%u", &disable);
	if (ret != 1)
		return -EINVAL;

	if (disable)
		data->devfreq->disabled_pm_qos = true;
	else
		data->devfreq->disabled_pm_qos = false;

	return count;
}

static ssize_t show_last_monitor_period(struct device *dev,
					struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

<<<<<<< HEAD
	count += snprintf(buf, PAGE_SIZE, "%u usec\n", jiffies_to_usecs(data->last_monitor_period));
=======
	count += snprintf(buf, PAGE_SIZE, "%u usec\n",
				jiffies_to_usecs(data->last_monitor_period));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t show_um_cur_freq(struct device *dev, struct device_attribute *attr, char *buf)
=======
static ssize_t show_ppmu_cur_freq(struct device *dev,
				struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

	count += snprintf(buf, PAGE_SIZE, "%u%%, %uKhz\n",
<<<<<<< HEAD
			  data->last_um_usage_rate, data->old_freq);
=======
				data->last_ppmu_usage_rate, data->old_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

<<<<<<< HEAD
static ssize_t show_test_cold_volt(struct device *dev, struct device_attribute *attr, char *buf)
=======
static ssize_t show_test_cold_volt(struct device *dev,
					struct device_attribute *attr, char *buf)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

<<<<<<< HEAD
	count += snprintf(buf, PAGE_SIZE, "%s\n", data->volt_offset ? "cold" : "normal");
=======
	count += snprintf(buf, PAGE_SIZE, "%s\n",
			data->volt_offset ? "cold" : "normal");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return count;
}

static ssize_t store_test_cold_volt(struct device *dev,
<<<<<<< HEAD
				    struct device_attribute *attr, const char *buf, size_t count)
=======
					struct device_attribute *attr,
					const char *buf, size_t count)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;
	u32 test;
	unsigned long test_event, test_state;

	ret = sscanf(buf, "%u", &test);
	if (ret != 1)
		return -EINVAL;

	if (test) {
		test_event = TMU_COLD;
		test_state = TMU_COLD;
	} else {
		test_event = TMU_COLD;
		test_state = TMU_NORMAL;
	}

	exynos_devfreq_tmu_notifier(&data->tmu_notifier, test_event, &test_state);

	return count;
}

static DEVICE_ATTR(exynos_devfreq_info, 0640, show_exynos_devfreq_info, NULL);
static DEVICE_ATTR(exynos_devfreq_get_freq, 0640, show_exynos_devfreq_get_freq, NULL);
static DEVICE_ATTR(exynos_devfreq_cmu_dump, 0640, show_exynos_devfreq_cmu_dump, NULL);
static DEVICE_ATTR(exynos_devfreq_get_delay, 0640, show_exynos_devfreq_get_delay, NULL);
<<<<<<< HEAD
static DEVICE_ATTR(debug_scaling_devfreq_min, 0640, show_debug_scaling_devfreq_min, store_debug_scaling_devfreq_min);
static DEVICE_ATTR(debug_scaling_devfreq_max, 0640, show_debug_scaling_devfreq_max,
						store_debug_scaling_devfreq_max);
static DEVICE_ATTR(disable_pm_qos, 0640, show_exynos_devfreq_disable_pm_qos,
		   store_exynos_devfreq_disable_pm_qos);
static DEVICE_ATTR(last_monitor_period, 0640, show_last_monitor_period, NULL);
static DEVICE_ATTR(um_cur_freq, 0640, show_um_cur_freq, NULL);
=======
static DEVICE_ATTR(exynos_devfreq_pm_qos, 0640, show_exynos_devfreq_pm_qos, store_exynos_devfreq_pm_qos);
static DEVICE_ATTR(exynos_devfreq_pm_qos_max, 0640, show_exynos_devfreq_pm_qos_max,
						store_exynos_devfreq_pm_qos_max);
static DEVICE_ATTR(disable_pm_qos, 0640, show_exynos_devfreq_disable_pm_qos,
					store_exynos_devfreq_disable_pm_qos);
static DEVICE_ATTR(last_monitor_period, 0640, show_last_monitor_period, NULL);
static DEVICE_ATTR(ppmu_cur_freq, 0640, show_ppmu_cur_freq, NULL);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static DEVICE_ATTR(test_cold_volt, 0640, show_test_cold_volt, store_test_cold_volt);

static struct attribute *exynos_devfreq_sysfs_entries[] = {
	&dev_attr_exynos_devfreq_info.attr,
	&dev_attr_exynos_devfreq_get_freq.attr,
	&dev_attr_exynos_devfreq_cmu_dump.attr,
	&dev_attr_exynos_devfreq_get_delay.attr,
<<<<<<< HEAD
	&dev_attr_debug_scaling_devfreq_min.attr,
	&dev_attr_debug_scaling_devfreq_max.attr,
	&dev_attr_disable_pm_qos.attr,
	&dev_attr_last_monitor_period.attr,
	&dev_attr_um_cur_freq.attr,
=======
	&dev_attr_exynos_devfreq_pm_qos.attr,
	&dev_attr_exynos_devfreq_pm_qos_max.attr,
	&dev_attr_disable_pm_qos.attr,
	&dev_attr_last_monitor_period.attr,
	&dev_attr_ppmu_cur_freq.attr,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	&dev_attr_test_cold_volt.attr,
	NULL,
};

static struct attribute_group exynos_devfreq_attr_group = {
<<<<<<< HEAD
	.name = "exynos_data",
	.attrs = exynos_devfreq_sysfs_entries,
};
#endif

static ssize_t show_scaling_devfreq_min(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
	int val;

	val = pm_qos_read_req_value(data->pm_qos_class, &data->sys_pm_qos_min);
	if (val < 0) {
		dev_err(dev, "failed to read requested value\n");
		return count;
	}

	count += snprintf(buf, PAGE_SIZE, "%d\n", val);

	return count;
}

static ssize_t store_scaling_devfreq_min(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;
	u32 qos_value;

	ret = sscanf(buf, "%u", &qos_value);
	if (ret != 1)
		return -EINVAL;

	if (pm_qos_request_active(&data->sys_pm_qos_min))
		pm_qos_update_request(&data->sys_pm_qos_min, qos_value);

	return count;
}

static DEVICE_ATTR(scaling_devfreq_min, 0640, show_scaling_devfreq_min, store_scaling_devfreq_min);

/* get frequency and delay time data from string */
static unsigned int *get_tokenized_data(const char *buf, int *num_tokens)
{
	const char *cp;
	int i;
	int ntokens = 1;
	unsigned int *tokenized_data;
	int err = -EINVAL;

	cp = buf;
	while ((cp = strpbrk(cp + 1, " :")))
		ntokens++;

	if (!(ntokens & 0x1))
		goto err;

	tokenized_data = kmalloc(ntokens * sizeof(unsigned int), GFP_KERNEL);
	if (!tokenized_data) {
		err = -ENOMEM;
		goto err;
	}

	cp = buf;
	i = 0;
	while (i < ntokens) {
		if (sscanf(cp, "%u", &tokenized_data[i++]) != 1)
			goto err_kfree;

		cp = strpbrk(cp, " :");
		if (!cp)
			break;
		cp++;
	}

	if (i != ntokens)
		goto err_kfree;

	*num_tokens = ntokens;
	return tokenized_data;

err_kfree:
	kfree(tokenized_data);
err:
	return ERR_PTR(err);
}

static ssize_t show_use_delay_time(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;

	mutex_lock(&data->devfreq->lock);
	count += snprintf(buf, PAGE_SIZE, "%s\n",
			  (data->simple_interactive_data.use_delay_time) ? "true" : "false");
	mutex_unlock(&data->devfreq->lock);
	return count;
}

static ssize_t store_use_delay_time(struct device *dev,
				    struct device_attribute *attr, const char *buf, size_t count)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret;

	mutex_lock(&data->devfreq->lock);
	ret = sscanf(buf, "%d", (int *)&data->simple_interactive_data.use_delay_time);
	mutex_unlock(&data->devfreq->lock);
	if (ret != 1)
		return -EINVAL;

	return count;
}

static ssize_t show_delay_time(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	ssize_t count = 0;
	int i;

	mutex_lock(&data->devfreq->lock);
	for (i = 0; i < data->simple_interactive_data.ndelay_time; i++) {
		count += snprintf(buf + count, PAGE_SIZE, "%d%s",
				data->simple_interactive_data.delay_time[i],
				(i == data->simple_interactive_data.ndelay_time - 1) ?
				"" : (i % 2) ? ":" : " ");
	}
	count += snprintf(buf + count, PAGE_SIZE, "\n");
	mutex_unlock(&data->devfreq->lock);
	return count;
}

static ssize_t store_delay_time(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct device *parent = dev->parent;
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ntokens;
	int *new_delay_time = NULL;

	new_delay_time = get_tokenized_data(buf , &ntokens);
	if (IS_ERR(new_delay_time))
		return PTR_RET(new_delay_time);

	mutex_lock(&data->devfreq->lock);
	kfree(data->simple_interactive_data.delay_time);
	data->simple_interactive_data.delay_time = new_delay_time;
	data->simple_interactive_data.ndelay_time = ntokens;
	mutex_unlock(&data->devfreq->lock);

	return count;
}

static DEVICE_ATTR(use_delay_time, 0640, show_use_delay_time, store_use_delay_time);
static DEVICE_ATTR(delay_time, 0640, show_delay_time, store_delay_time);

static struct attribute *devfreq_delay_time_sysfs_entries[] = {
	&dev_attr_use_delay_time.attr,
	&dev_attr_delay_time.attr,
	NULL,
};

static struct attribute_group devfreq_delay_time_attr_group = {
	.name = "interactive",
	.attrs = devfreq_delay_time_sysfs_entries,
};

=======
        .name   = "exynos_data",
        .attrs  = exynos_devfreq_sysfs_entries,
};
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef CONFIG_OF
#if defined(CONFIG_ECT)
static int exynos_devfreq_parse_ect(struct exynos_devfreq_data *data, const char *dvfs_domain_name)
{
	int i;
	void *dvfs_block;
	struct ect_dvfs_domain *dvfs_domain;

	dvfs_block = ect_get_block(BLOCK_DVFS);
	if (dvfs_block == NULL)
		return -ENODEV;

	dvfs_domain = ect_dvfs_get_domain(dvfs_block, (char *)dvfs_domain_name);
	if (dvfs_domain == NULL)
		return -ENODEV;

<<<<<<< HEAD
	data->max_state = dvfs_domain->num_of_level;
=======
	data->opp_list_length = dvfs_domain->num_of_level;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	for (i = 0; i < dvfs_domain->num_of_level; ++i) {
		data->opp_list[i].idx = i;
		data->opp_list[i].freq = dvfs_domain->list_level[i].level;
		data->opp_list[i].volt = 0;
	}

	return 0;
}
#endif

static int exynos_devfreq_parse_dt(struct device_node *np, struct exynos_devfreq_data *data)
{
<<<<<<< HEAD
	const char *devfreq_type;
	const char *use_get_dev;
	const char *use_regulator;
	const char *use_pd_off;
=======
	int opp_size;
	const char *devfreq_type;
	const char *use_get_dev;
	const char *use_regulator;
	const char *use_regulator_dummy;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	const char *use_tmu;
	const char *use_cl_dvfs;
	const char *use_switch_clk;
#if defined(CONFIG_ECT)
	const char *devfreq_domain_name;
#endif
<<<<<<< HEAD
	const char *buf;
	const char *use_delay_time;
	int ntokens;
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	int not_using_ect = true;
	u32 freq_array[6];
	u32 volt_array[4];

	if (!np)
		return -ENODEV;

	if (of_property_read_string(np, "devfreq_type", &devfreq_type))
		return -ENODEV;

	if (!strcmp(devfreq_type, "mif")) {
		data->devfreq_type = DEVFREQ_MIF;
		data->pm_qos_class = PM_QOS_BUS_THROUGHPUT;
		data->pm_qos_class_max = PM_QOS_BUS_THROUGHPUT_MAX;
<<<<<<< HEAD
		data->um_data.type = NONE_UM;
=======
		data->ppmu_data.type = NONE_PPMU;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		data->ess_flag = ESS_FLAG_MIF;
	} else if (!strcmp(devfreq_type, "int")) {
		data->devfreq_type = DEVFREQ_INT;
		data->pm_qos_class = PM_QOS_DEVICE_THROUGHPUT;
<<<<<<< HEAD
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
		data->pm_qos_class_max = PM_QOS_DEVICE_THROUGHPUT_MAX;
#else
		data->pm_qos_class_max = PM_QOS_RESERVED;
#endif
		data->um_data.type = NONE_UM;
=======
		data->ppmu_data.type = NONE_PPMU;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		data->ess_flag = ESS_FLAG_INT;
	} else if (!strcmp(devfreq_type, "disp")) {
		data->devfreq_type = DEVFREQ_DISP;
		data->pm_qos_class = PM_QOS_DISPLAY_THROUGHPUT;
<<<<<<< HEAD
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
		data->pm_qos_class_max = PM_QOS_DISPLAY_THROUGHPUT_MAX;
#else
		data->pm_qos_class_max = PM_QOS_RESERVED;
#endif
		data->um_data.type = NONE_UM;
=======
		data->ppmu_data.type = NONE_PPMU;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		data->ess_flag = ESS_FLAG_DISP;
	} else if (!strcmp(devfreq_type, "cam")) {
		data->devfreq_type = DEVFREQ_CAM;
		data->pm_qos_class = PM_QOS_CAM_THROUGHPUT;
<<<<<<< HEAD
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
		data->pm_qos_class_max = PM_QOS_CAM_THROUGHPUT_MAX;
#else
		data->pm_qos_class_max = PM_QOS_RESERVED;
#endif
		data->um_data.type = NONE_UM;
=======
		data->ppmu_data.type = NONE_PPMU;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		data->ess_flag = ESS_FLAG_ISP;
	} else {
		dev_err(data->dev, "not support devfreq type (%s)\n", devfreq_type);
		return -EINVAL;
	}

#if defined(CONFIG_ECT)
	if (of_property_read_string(np, "devfreq_domain_name", &devfreq_domain_name))
		return -ENODEV;
	not_using_ect = exynos_devfreq_parse_ect(data, devfreq_domain_name);
#endif
<<<<<<< HEAD
	if (not_using_ect) {
		dev_err(data->dev, "cannot parse the DVFS info in ECT");
		return -ENODEV;
	}

	if (of_property_read_u32_array(np, "freq_info", (u32 *)&freq_array,
				       (size_t)(ARRAY_SIZE(freq_array))))
=======

	if (not_using_ect) {
		if (of_property_read_u32(np, "opp_list_length", &data->opp_list_length))
			return -ENODEV;

		opp_size = sizeof(struct exynos_devfreq_opp_table) / sizeof(u32);
		if (of_property_read_u32_array(np, "opp_list", (u32 *)&data->opp_list,
					(size_t)(data->opp_list_length * opp_size)))
			return -ENODEV;
	}

	if (of_property_read_u32_array(np, "freq_info", (u32 *)&freq_array,
					(size_t)(ARRAY_SIZE(freq_array))))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return -ENODEV;

	data->devfreq_profile.initial_freq = freq_array[0];
	data->default_qos = freq_array[1];
	data->devfreq_profile.suspend_freq = freq_array[2];
<<<<<<< HEAD
	data->min_freq = freq_array[3];
	data->max_freq = freq_array[4];
	data->reboot_freq = freq_array[5];
=======
	data->cal_qos_max = freq_array[3];
	data->min_freq = freq_array[4];
	data->max_freq = freq_array[5];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (of_property_read_string(np, "use_get_dev", &use_get_dev))
		return -ENODEV;

	if (!strcmp(use_get_dev, "true")) {
		data->use_get_dev = true;
	} else if (!strcmp(use_get_dev, "false")) {
		data->use_get_dev = false;
	} else {
		dev_err(data->dev, "invalid use_get_dev string (%s)\n", use_get_dev);
		return -EINVAL;
	}

	if (of_property_read_u32(np, "polling_ms", &data->devfreq_profile.polling_ms))
		return -ENODEV;

	if (of_property_read_string(np, "gov_name", &data->governor_name))
		return -ENODEV;

<<<<<<< HEAD
	if (!strcmp(data->governor_name, "interactive")) {
		data->gov_type = SIMPLE_INTERACTIVE;
	} else {
		dev_err(data->dev, "invalid governor name (%s)\n", data->governor_name);
		return -EINVAL;
	}

	if (data->gov_type == SIMPLE_INTERACTIVE) {
		if (of_property_read_string(np, "use_delay_time", &use_delay_time))
			return -ENODEV;

		if (!strcmp(use_delay_time, "true")) {
			data->simple_interactive_data.use_delay_time = true;
		} else if (!strcmp(use_delay_time, "false")) {
			data->simple_interactive_data.use_delay_time = false;
		} else {
			dev_err(data->dev, "invalid use_delay_time : (%s)\n", use_delay_time);
			return -EINVAL;
		}

		if (data->simple_interactive_data.use_delay_time) {
			if (of_property_read_string(np, "delay_time_list", &buf)) {
				/*
				 * If there is not delay time list,
				 * delay time will be filled with default time
				 */
				data->simple_interactive_data.delay_time =
					kmalloc(sizeof(unsigned int), GFP_KERNEL);
				*(data->simple_interactive_data.delay_time)
					= DEFAULT_DELAY_TIME;
				data->simple_interactive_data.ndelay_time =
					DEFAULT_NDELAY_TIME;
				dev_info(data->dev, "set default delay time %d ms\n",
						DEFAULT_DELAY_TIME);
			} else {
				data->simple_interactive_data.delay_time =
					get_tokenized_data(buf, &ntokens);
				data->simple_interactive_data.ndelay_time = ntokens;
			}
		}
=======
	if (!strcmp(data->governor_name, "simple_ondemand")) {
		data->gov_type = SIMPLE_ONDEMAND;
	} else if (!strcmp(data->governor_name, "simple_exynos")) {
		data->gov_type = SIMPLE_EXYNOS;
	} else {
		dev_err(data->dev, "invalid governor name (%s)\n",
					data->governor_name);
		return -EINVAL;
	}

	if (data->gov_type == SIMPLE_ONDEMAND) {
		if (of_property_read_u32(np, "upthreshold",
				&data->simple_ondemand_data.upthreshold))
			return -ENODEV;

		if (of_property_read_u32(np, "downdifferential",
				&data->simple_ondemand_data.downdifferential))
			return -ENODEV;

		if (of_property_read_u32(np, "multi_weight",
				&data->simple_ondemand_data.multiplication_weight))
			return -ENODEV;
	} else if (data->gov_type == SIMPLE_EXYNOS) {
		if (of_property_read_u32(np, "urgent_thres",
				&data->simple_exynos_data.urgentthreshold))
			return -ENODEV;

		if (of_property_read_u32(np, "upthreshold",
				&data->simple_exynos_data.upthreshold))
			return -ENODEV;

		if (of_property_read_u32(np, "downthreshold",
				&data->simple_exynos_data.downthreshold))
			return -ENODEV;

		if (of_property_read_u32(np, "idlethreshold",
				&data->simple_exynos_data.idlethreshold))
			return -ENODEV;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	} else {
		dev_err(data->dev, "not support governor type %u\n", data->gov_type);
		return -EINVAL;
	}

	if (of_property_read_string(np, "use_reg", &use_regulator))
		return -ENODEV;

	if (!strcmp(use_regulator, "true")) {
		data->use_regulator = true;
	} else if (!strcmp(use_regulator, "false")) {
		data->use_regulator = false;
	} else {
		dev_err(data->dev, "invalid use_regulator string (%s)\n", use_regulator);
		return -EINVAL;
	}

	if (data->use_regulator) {
		if (of_property_read_string(np, "reg_name", &data->regulator_name))
			return -ENODEV;

		if (of_property_read_u32_array(np, "volt_info", (u32 *)&volt_array,
<<<<<<< HEAD
					       (size_t)(ARRAY_SIZE(volt_array))))
=======
						(size_t)(ARRAY_SIZE(volt_array))))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return -ENODEV;

		data->cold_volt_offset = volt_array[0];
		data->limit_cold_volt = volt_array[1];
		data->min_cold_volt = volt_array[2];
		data->reg_max_volt = volt_array[3];

<<<<<<< HEAD
		if (of_property_read_string(np, "use_pd_off", &use_pd_off))
			return -ENODEV;

		if (!strcmp(use_pd_off, "true")) {
			data->use_pd_off = true;
		} else if (!strcmp(use_pd_off, "false")) {
			data->use_pd_off = false;
		} else {
			dev_err(data->dev, "invalid use_pd_off string (%s)\n",
				use_pd_off);
=======
		if (of_property_read_string(np, "use_reg_dummy", &use_regulator_dummy))
			return -ENODEV;

		if (!strcmp(use_regulator_dummy, "true")) {
			data->use_regulator_dummy = true;
		} else if (!strcmp(use_regulator_dummy, "false")) {
			data->use_regulator_dummy = false;
		} else {
			dev_err(data->dev, "invalid use_regulator_dummy string (%s)\n",
							use_regulator_dummy);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return -EINVAL;
		}
	}

	if (of_property_read_u32(np, "boot_qos_timeout", &data->boot_qos_timeout)) {
		data->boot_qos_timeout = 40;	/* dafault timeout is 40 second */
<<<<<<< HEAD
		dev_info(data->dev, "set default boot timeout %u second\n", data->boot_qos_timeout);
=======
		dev_info(data->dev, "set default boot timeout %u second\n",
					data->boot_qos_timeout);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	if (of_property_read_string(np, "use_tmu", &use_tmu))
		return -ENODEV;

	if (!strcmp(use_tmu, "true")) {
		data->use_tmu = true;
	} else if (!strcmp(use_tmu, "false")) {
		data->use_tmu = false;
	} else {
		dev_err(data->dev, "invalid use_tmu string (%s)\n", use_tmu);
		return -EINVAL;
	}

	if (of_property_read_string(np, "use_cl_dvfs", &use_cl_dvfs))
		return -ENODEV;

	if (!strcmp(use_cl_dvfs, "true")) {
		data->use_cl_dvfs = true;
	} else if (!strcmp(use_cl_dvfs, "false")) {
		data->use_cl_dvfs = false;
	} else {
		dev_err(data->dev, "invalid use_cl_dvfs string (%s)\n", use_cl_dvfs);
		return -EINVAL;
	}

	if (of_property_read_string(np, "use_sw_clk", &use_switch_clk))
		return -ENODEV;

	if (!strcmp(use_switch_clk, "true")) {
		data->use_switch_clk = true;
	} else if (!strcmp(use_switch_clk, "false")) {
		data->use_switch_clk = false;
	} else {
		dev_err(data->dev, "invalid use_switch_clk string (%s)\n", use_switch_clk);
		return -EINVAL;
	}

<<<<<<< HEAD
	if (data->um_data.type == NONE_UM) {
		data->use_um = false;
		dev_info(data->dev, "not used UM monitor\n");
=======
	if (data->ppmu_data.type == NONE_PPMU) {
		data->use_ppmu = false;
		dev_info(data->dev, "not used PPMU monitor\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	} else {
		int i;
		phys_addr_t base;

<<<<<<< HEAD
		data->use_um = true;

		if (data->um_data.type >= NONE_UM) {
			dev_err(data->dev, "not support um type (%d)\n", data->um_data.type);
			return -EINVAL;
		}

		if (of_property_read_u32(np, "um_count", &data->um_data.um_count))
			return -ENODEV;

		if (of_property_read_u32_array(np, "um_list", (u32 *)&data->um_base,
					       (size_t)(data->um_data.um_count)))
			return -ENODEV;

		data->um_data.um_list = kzalloc(sizeof(struct um_addr) *
						data->um_data.um_count, GFP_KERNEL);
		if (data->um_data.um_list == NULL) {
			dev_err(data->dev, "failed allocated memory for um list");
			return -ENOMEM;
		}

		for (i = 0; i < data->um_data.um_count; i++) {
			dev_info(data->dev, "um list.%d : 0x%08X\n", i, data->um_base[i]);
			base = (phys_addr_t) data->um_base[i];
			data->um_data.um_list[i].base = (void __iomem *)base;
=======
		data->use_ppmu = true;

		if (data->ppmu_data.type >= NONE_PPMU) {
			dev_err(data->dev, "not support ppmu type (%d)\n", data->ppmu_data.type);
			return -EINVAL;
		}

		if (of_property_read_u32(np, "ppmu_count", &data->ppmu_data.ppmu_count))
			return -ENODEV;

		if (of_property_read_u32_array(np, "ppmu_list", (u32 *)&data->ppmu_base,
					(size_t)(data->ppmu_data.ppmu_count)))
			return -ENODEV;

		data->ppmu_data.ppmu_list = kzalloc(sizeof(struct ppmu_addr) *
						data->ppmu_data.ppmu_count, GFP_KERNEL);
		if (data->ppmu_data.ppmu_list == NULL) {
			dev_err(data->dev, "failed allocated memory for ppmu list");
			return -ENOMEM;
		}

		for (i = 0; i < data->ppmu_data.ppmu_count; i++) {
			dev_info(data->dev, "ppmu list.%d : 0x%08X\n", i, data->ppmu_base[i]);
			base = (phys_addr_t)data->ppmu_base[i];
			data->ppmu_data.ppmu_list[i].base = (void __iomem *)base;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}
	}

	return 0;
}
#else
static int exynos_devfreq_parse_dt(struct device_node *np, struct exynos_devfrq_data *data)
{
	return -EINVAL;
}
#endif

int register_exynos_devfreq_init_prepare(enum exynos_devfreq_type type,
<<<<<<< HEAD
					 int (*func) (struct exynos_devfreq_data *))
=======
				int (*func)(struct exynos_devfreq_data *))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	if (type >= DEVFREQ_TYPE_END) {
		pr_err("%s: unsupport devfreq type : %d\n", __func__, type);
		return -EINVAL;
	}

	exynos_devfreq_init[type].init_prepare = func;

	return 0;
}

<<<<<<< HEAD
s32 exynos_devfreq_get_opp_idx(struct exynos_devfreq_opp_table *table, unsigned int size, u32 freq)
{
	int i;

	for (i = 0; i < size; ++i) {
		if (table[i].freq == freq)
			return i;
	}

	return -ENODEV;
=======
s32 exynos_devfreq_get_opp_idx(struct exynos_devfreq_opp_table *table,
				unsigned int size, u32 freq)
{
        int i;

        for (i = 0; i < size; ++i) {
                if (table[i].freq == freq)
                        return i;
        }

        return -ENODEV;
}

u32 get_target_devfreq_rate(enum exynos_devfreq_type type, char *name, u32 freq)
{
	u32 target_rate = 0;

	if (!devfreq_data[type])
		return target_rate;

	if (devfreq_data[type]->ops.get_target_freq)
		target_rate = devfreq_data[type]->ops.get_target_freq(name, freq);

	dev_dbg(devfreq_data[type]->dev, "%s(%d): request freq: %u, target_freq: %u\n",
					__func__, type, freq, target_rate);

	return target_rate;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

int exynos_devfreq_sync_voltage(enum exynos_devfreq_type type, bool turn_on)
{
	struct exynos_devfreq_data *data;
	struct dev_pm_opp *target_opp;
	unsigned long freq = 0;
	int ret = 0;

	if (type >= DEVFREQ_TYPE_END || !devfreq_data[type]) {
		pr_err("%s: invalied devfreq type(%d)\n", __func__, type);
		return -EINVAL;
	}

	data = devfreq_data[type];

	mutex_lock(&data->lock);

	if (turn_on) {
		if (!data->vdd) {
<<<<<<< HEAD
			data->vdd = regulator_get(data->dev, data->regulator_name);
			if (IS_ERR(data->vdd)) {
				dev_err(data->dev, "%s: failed get regulator(%s)\n",
					__func__, data->regulator_name);
=======
			data->vdd = regulator_get(NULL, data->regulator_name);
			if (IS_ERR(data->vdd)) {
				dev_err(data->dev, "%s: failed get regulator(%s)\n",
						__func__, data->regulator_name);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				ret = -ENODEV;
				goto out;
			}

			rcu_read_lock();
			freq = (unsigned long)data->old_freq;
			target_opp = devfreq_recommended_opp(data->dev, &freq, 0);
			if (IS_ERR(target_opp)) {
				rcu_read_unlock();
				dev_err(data->dev, "not found valid OPP table for sync\n");
				regulator_put(data->vdd);
				ret = PTR_ERR(target_opp);
				goto out;
			}
			data->new_volt = dev_pm_opp_get_voltage(target_opp);
			rcu_read_unlock();

<<<<<<< HEAD
			ret = exynos_devfreq_set_voltage(&data->new_volt, data);
			if (ret) {
				dev_err(data->dev,
					"failed set voltage for sync voltage (%d:%luKhz:%uuV)\n",
					type, freq, data->new_volt);
=======
			ret = exynos_devfreq_set_voltage(data->dev, &data->new_volt, data);
			if (ret) {
				dev_err(data->dev, "failed set voltage for sync voltage (%d:%luKhz:%uuV)\n",
						type, freq, data->new_volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}

			data->old_volt = data->new_volt;
		}
	} else {
<<<<<<< HEAD
		if (data->vdd && data->use_pd_off) {
			ret = regulator_set_voltage(data->vdd, 1, data->reg_max_volt);
			if (ret) {
				dev_err(data->dev,
					"failed set voltage for preparing put regulator : %s\n",
					data->regulator_name);
				goto out;
			}

			regulator_put(data->vdd);
			data->vdd = NULL;
		}
=======
		if (data->vdd_dummy) {
			ret = regulator_set_voltage(data->vdd_dummy, 1, data->reg_max_volt);
			if (ret) {
				dev_err(data->dev, "failed set voltage for dummy regulator : %s\n",
						data->regulator_name);
				goto out;
			}
		}

		if (data->vdd) {
			regulator_put(data->vdd);
			data->vdd = NULL;
		}

		if (data->vdd_dummy)
			regulator_sync_voltage(data->vdd_dummy);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

out:
	mutex_unlock(&data->lock);
	return ret;
}

static enum volt_order_type exynos_devfreq_set_volt_order(struct exynos_devfreq_data *data)
{
	enum volt_order_type order;

	if (data->old_volt < data->new_volt + data->volt_offset)
		order = PRE_SET_VOLT;
	else if (data->old_volt > data->new_volt + data->volt_offset)
		order = POST_SET_VOLT;
	else
		order = KEEP_SET_VOLT;

	return order;
}

<<<<<<< HEAD
static u32 exynos_devfreq_get_limit_voltage(u32 voltage, struct exynos_devfreq_data *data)
=======
static u32 exynos_devfreq_get_limit_voltage(u32 voltage,
					struct exynos_devfreq_data *data)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	if (data->limit_cold_volt) {
		if (voltage > data->limit_cold_volt)
			return voltage;

		if (voltage + data->volt_offset > data->limit_cold_volt)
			return data->limit_cold_volt;
	}

	if (data->min_cold_volt) {
<<<<<<< HEAD
		if (data->volt_offset && (voltage + data->volt_offset) < data->min_cold_volt)
=======
		if (data->volt_offset &&
			(voltage + data->volt_offset) < data->min_cold_volt)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return data->min_cold_volt;
	}

	return voltage + data->volt_offset;
}

<<<<<<< HEAD
static int exynos_devfreq_set_voltage(u32 *target_volt, struct exynos_devfreq_data *data)
=======
static int exynos_devfreq_set_voltage(struct device *dev, u32 *target_volt,
					struct exynos_devfreq_data *data)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	int ret = 0;

	if (!data->use_regulator)
		return ret;

	if (!data->vdd)
		return -ENODEV;

	mutex_lock(&data->regulator_lock);

	*target_volt = exynos_devfreq_get_limit_voltage(*target_volt, data);

	if (data->ops.set_voltage_prepare)
		data->ops.set_voltage_prepare(data);

	ret = regulator_set_voltage(data->vdd, *target_volt, data->reg_max_volt);
	if (ret)
		dev_err(data->dev, "failed set voltage : %s, %uuV\n",
<<<<<<< HEAD
			data->regulator_name, *target_volt);
=======
				data->regulator_name, *target_volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (data->ops.set_voltage_post)
		data->ops.set_voltage_post(data);

	mutex_unlock(&data->regulator_lock);

	return ret;
}

<<<<<<< HEAD
static int exynos_init_freq_table(struct exynos_devfreq_data *data)
=======
static int exynos_init_freq_table(struct device *dev, struct exynos_devfreq_data *data)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	int i, ret;
	u32 freq, volt;

	/* volt_table should be filled (data->volt_table) */
	if (data->ops.get_volt_table) {
<<<<<<< HEAD
		ret = data->ops.get_volt_table(data->dev, data->max_state, data->opp_list);
		if (ret) {
			dev_err(data->dev, "failed get voltage table\n");
=======
		ret = data->ops.get_volt_table(dev, data->volt_table, data);
		if (ret) {
			dev_err(dev, "failed get voltage table\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return ret;
		}
	}

	for (i = 0; i < data->max_state; i++) {
		freq = data->opp_list[i].freq;
<<<<<<< HEAD
=======
		if (data->volt_table[0])
			data->opp_list[i].volt = data->volt_table[i];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		volt = data->opp_list[i].volt;

		data->devfreq_profile.freq_table[i] = freq;

<<<<<<< HEAD
		ret = dev_pm_opp_add(data->dev, freq, volt);
		if (ret) {
			dev_err(data->dev, "failed to add opp entries %uKhz\n", freq);
			return ret;
		} else {
			dev_info(data->dev, "DEVFREQ : %8uKhz, %8uuV\n", freq, volt);
=======
		ret = dev_pm_opp_add(dev, freq, volt);
		if (ret) {
			dev_err(dev, "failed to add opp entries %uKhz\n", freq);
			return ret;
		} else {
			dev_info(dev, "DEVFREQ : %8uKhz, %8uuV\n", freq, volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}
	}

	if (data->ops.init_freq_table) {
<<<<<<< HEAD
		ret = data->ops.init_freq_table(data);
		if (ret) {
			dev_err(data->dev, "failed init frequency table\n");
=======
		ret = data->ops.init_freq_table(dev, data);
		if (ret) {
			dev_err(dev, "failed init frequency table\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return ret;
		}
	}

	return 0;
}

<<<<<<< HEAD
static int exynos_devfreq_tmu_notifier(struct notifier_block *nb, unsigned long event, void *v)
{
	struct exynos_devfreq_data *data = container_of(nb, struct exynos_devfreq_data,
							tmu_notifier);
=======
static int exynos_devfreq_tmu_notifier(struct notifier_block *nb,
					unsigned long event, void *v)
{
	struct exynos_devfreq_data *data = container_of(nb, struct exynos_devfreq_data,
								tmu_notifier);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	struct dev_pm_opp *target_opp;
	unsigned long freq = 0;
	u32 *on = v;
	int ret = NOTIFY_OK;

	if (!data->use_tmu)
		return NOTIFY_OK;

	if (!data->use_regulator)
		return NOTIFY_OK;

	if (!data->vdd)
		return NOTIFY_BAD;

	if (event != TMU_COLD)
		return NOTIFY_OK;

	mutex_lock(&data->lock);

	if (data->use_cl_dvfs && (*on)) {
		if (data->ops.cl_dvfs_stop) {
<<<<<<< HEAD
			ret = data->ops.cl_dvfs_stop(data->dev, data->new_idx);
=======
			ret = data->ops.cl_dvfs_stop(data->new_idx, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(data->dev, "cl_dvfs does not stop in tmu\n");
				ret = NOTIFY_BAD;
				goto out;
			}
		}
	}

	if (*on) {
		data->new_volt = data->old_volt;

		if (!data->volt_offset)
			data->volt_offset = data->cold_volt_offset;
		else
			goto out2;

<<<<<<< HEAD
		ret = exynos_devfreq_set_voltage(&data->new_volt, data);
		if (ret) {
			dev_err(data->dev, "failed set voltage for low temp (%uuV:%uuV)\n",
				data->old_volt, data->volt_offset);
=======
		ret = exynos_devfreq_set_voltage(data->dev, &data->new_volt, data);
		if (ret) {
			dev_err(data->dev, "failed set voltage for low temp (%uuV:%uuV)\n",
					data->old_volt, data->volt_offset);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			ret = NOTIFY_BAD;
			goto out2;
		}

		data->old_volt = data->new_volt;
	} else {
		if (data->volt_offset)
			data->volt_offset = 0;
		else
			goto out2;

		rcu_read_lock();
		freq = (unsigned long)data->old_freq;
		target_opp = devfreq_recommended_opp(data->dev, &freq, 0);
		if (IS_ERR(target_opp)) {
			rcu_read_unlock();
			dev_err(data->dev, "not found valid OPP table in tmu notifier\n");
			ret = PTR_ERR(target_opp);
			goto out2;
		}
		data->new_volt = dev_pm_opp_get_voltage(target_opp);
		rcu_read_unlock();

<<<<<<< HEAD
		ret = exynos_devfreq_set_voltage(&data->new_volt, data);
		if (ret) {
			dev_err(data->dev, "failed set voltage from low temp (%uuV:%uuV)\n",
				data->old_volt, data->volt_offset);
=======
		ret = exynos_devfreq_set_voltage(data->dev, &data->new_volt, data);
		if (ret) {
			dev_err(data->dev, "failed set voltage from low temp (%uuV:%uuV)\n",
					data->old_volt, data->volt_offset);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			ret = NOTIFY_BAD;
			goto out2;
		}

		data->old_volt = data->new_volt;
	}

<<<<<<< HEAD
 out2:
	if (data->use_cl_dvfs && !(*on)) {
		if (data->ops.cl_dvfs_start) {
			ret = data->ops.cl_dvfs_start(data->dev);
=======
out2:
	if (data->use_cl_dvfs && !(*on)) {
		if (data->ops.cl_dvfs_start) {
			ret = data->ops.cl_dvfs_start(data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(data->dev, "cl_dvfs does not stop in tmu\n");
				ret = NOTIFY_BAD;
				goto out;
			}
		}
	}

out:
	mutex_unlock(&data->lock);

	return ret;
}

<<<<<<< HEAD
static int exynos_devfreq_reboot_notifier(struct notifier_block *nb, unsigned long val, void *v)
{
	struct exynos_devfreq_data *data = container_of(nb, struct exynos_devfreq_data,
							reboot_notifier);

	if (!data->vdd) {
		if (data->use_pd_off)
			return NOTIFY_OK;
		else {
			dev_err(data->dev, "failed reboot, regulator hasn't been registered\n");
			return NOTIFY_BAD;
		}
	}

	if (pm_qos_request_active(&data->default_pm_qos_min))
		pm_qos_update_request(&data->default_pm_qos_min, data->reboot_freq);
	if (pm_qos_request_active(&data->default_pm_qos_max))
		pm_qos_update_request(&data->default_pm_qos_max, data->reboot_freq);

	if (data->ops.reboot) {
		if (data->ops.reboot(data)) {
=======
static int exynos_devfreq_reboot_notifier(struct notifier_block *nb,
					unsigned long val, void *v)
{
	struct exynos_devfreq_data *data = container_of(nb, struct exynos_devfreq_data,
								reboot_notifier);

	if (pm_qos_request_active(&data->default_pm_qos))
		pm_qos_update_request(&data->default_pm_qos,
				data->devfreq_profile.initial_freq);

	if (data->ops.reboot) {
		if (data->ops.reboot(data->dev, data)) {
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			dev_err(data->dev, "failed reboot\n");
			return NOTIFY_BAD;
		}
	}

	return NOTIFY_OK;
}

<<<<<<< HEAD
static int exynos_devfreq_pm_notifier(struct notifier_block *nb,
					unsigned long pm_event, void *v)
{
	struct exynos_devfreq_data *data = container_of(nb, struct exynos_devfreq_data,
								pm_notifier);
	int ret;

	switch (pm_event) {
	case PM_SUSPEND_PREPARE:
		if (data->ops.pm_suspend_prepare) {
			ret = data->ops.pm_suspend_prepare(data);
			if (ret) {
				dev_err(data->dev, "failed pm_suspend_prepare\n");
				goto err;
			}
		}
		break;
	case PM_POST_SUSPEND:
		if (data->ops.pm_post_suspend) {
			ret = data->ops.pm_post_suspend(data);
			if (ret) {
				dev_err(data->dev, "failed pm_post_suspend\n");
				goto err;
			}
		}
		break;
	}

	return NOTIFY_OK;

err:
	return NOTIFY_BAD;
}

static int exynos_devfreq_notifier(struct notifier_block *nb, unsigned long val, void *v)
{
	struct devfreq_notifier_block *um_nb = container_of(nb, struct devfreq_notifier_block, nb);
	struct device *parent = um_nb->df->dev.parent;
=======
static int exynos_devfreq_notifier(struct notifier_block *nb,
					unsigned long val, void *v)
{
	struct devfreq_notifier_block *ppmu_nb = container_of(nb, struct devfreq_notifier_block, nb);
	struct device *parent = ppmu_nb->df->dev.parent;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	struct platform_device *pdev = container_of(parent, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int err;
	u64 cur_jiffies;

<<<<<<< HEAD
	mutex_lock(&um_nb->df->lock);
	err = update_devfreq(um_nb->df);
	if (err && err != -EAGAIN) {
		dev_err(&um_nb->df->dev, "devfreq failed with (%d) error\n", err);
		mutex_unlock(&um_nb->df->lock);
		return NOTIFY_BAD;
	}
	mutex_unlock(&um_nb->df->lock);
=======
	mutex_lock(&ppmu_nb->df->lock);
	err = update_devfreq(ppmu_nb->df);
	if (err && err != -EAGAIN) {
		dev_err(&ppmu_nb->df->dev, "devfreq failed with (%d) error\n", err);
		mutex_unlock(&ppmu_nb->df->lock);
		return NOTIFY_BAD;
	}
	mutex_unlock(&ppmu_nb->df->lock);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	cur_jiffies = get_jiffies_64();
	data->last_monitor_period = (u32)(cur_jiffies - data->last_monitor_jiffies);
	data->last_monitor_jiffies = cur_jiffies;

	return NOTIFY_OK;
}

<<<<<<< HEAD
static int exynos_devfreq_target(struct device *dev, unsigned long *target_freq, u32 flags)
=======
static int exynos_devfreq_target(struct device *dev,
				unsigned long *target_freq, u32 flags)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	struct platform_device *pdev = container_of(dev, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	struct timeval before_target, after_target, before_setfreq, after_setfreq;
	struct dev_pm_opp *target_opp;
	struct dev_pm_opp *switch_opp;
	unsigned long switch_freq;
	u32 switch_volt;
	u32 target_volt;
	s32 target_idx;
	s32 target_time = 0, setfreq_time = 0;
	int ret = 0;
<<<<<<< HEAD
	enum volt_order_type volt_order;
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (data->devfreq_disabled)
		return -EAGAIN;

	do_gettimeofday(&before_target);

	mutex_lock(&data->lock);

	rcu_read_lock();
	target_opp = devfreq_recommended_opp(dev, target_freq, flags);
	if (IS_ERR(target_opp)) {
		rcu_read_unlock();
		dev_err(dev, "not found valid OPP table\n");
		ret = PTR_ERR(target_opp);
		goto out;
	}

	*target_freq = dev_pm_opp_get_freq(target_opp);
	target_volt = dev_pm_opp_get_voltage(target_opp);
	rcu_read_unlock();

<<<<<<< HEAD
	target_idx = exynos_devfreq_get_opp_idx(data->opp_list, data->max_state, *target_freq);
=======
	target_idx = exynos_devfreq_get_opp_idx(data->opp_list, data->max_state,
							*target_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (target_idx < 0) {
		ret = -EINVAL;
		goto out;
	}

	data->new_freq = *target_freq;
	data->new_idx = target_idx;
	data->new_volt = target_volt;

<<<<<<< HEAD
=======
	if (data->ops.pre_update_target) {
		ret = data->ops.pre_update_target(dev, data);
		if (ret) {
			dev_err(dev, "failed pre update target\n");
			goto out;
		}
	}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (data->old_freq == data->new_freq)
		goto out;

	dev_dbg(dev, "LV_%d, %uKhz, %uuV ======> LV_%d, %uKhz, %uuV\n",
<<<<<<< HEAD
		data->old_idx, data->old_freq, data->old_volt,
		data->new_idx, data->new_freq, data->new_volt);

	/* calcuration to voltage set ordering */
	volt_order = exynos_devfreq_set_volt_order(data);

	exynos_ss_freq(data->ess_flag, data->old_freq, data->new_freq, ESS_FLAG_IN);
	trace_exynos_freq_in(data->ess_flag, data->old_freq);

	if (data->use_cl_dvfs && !data->volt_offset) {
		if (data->ops.cl_dvfs_stop) {
			ret = data->ops.cl_dvfs_stop(data->dev, data->new_idx);
=======
			data->old_idx, data->old_freq, data->old_volt,
			data->new_idx, data->new_freq, data->new_volt);

	/* calcuration to voltage set ordering */
	data->set_volt_order = exynos_devfreq_set_volt_order(data);

	exynos_ss_freq(data->ess_flag, data->old_freq, data->new_freq, ESS_FLAG_IN);

	if (data->use_cl_dvfs && !data->volt_offset) {
		if (data->ops.cl_dvfs_stop) {
			ret = data->ops.cl_dvfs_stop(data->new_idx, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "cl_dvfs does not stop\n");
				goto out;
			}
		}
	}

	if (data->use_switch_clk) {
		if (data->ops.get_switch_freq) {
<<<<<<< HEAD
			ret = data->ops.get_switch_freq(data->dev, data->old_freq,
							data->new_freq, &data->switch_freq);
=======
			ret = data->ops.get_switch_freq(data->old_freq, data->new_freq,
							&data->switch_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed get switch frequency\n");
				goto out;
			}
			switch_freq = data->switch_freq;
		} else {
			dev_err(dev, "get_switch_freq function is not exist\n");
			goto out;
		}

		if (data->ops.get_switch_voltage) {
<<<<<<< HEAD
			ret =
			    data->ops.get_switch_voltage(data->dev, data->old_freq, data->new_freq,
							 data->old_volt, data->new_volt,
							 &data->switch_volt);
=======
			ret = data->ops.get_switch_voltage(data->old_freq,
					data->new_freq, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed get switch voltage\n");
				goto out;
			}
			switch_volt = data->switch_volt;
		} else {
			rcu_read_lock();
			switch_opp = devfreq_recommended_opp(dev, &switch_freq, flags);
			if (IS_ERR(switch_opp)) {
				rcu_read_unlock();
				dev_err(dev, "not found valid OPP table for switch freq\n");
				ret = PTR_ERR(switch_opp);
				goto out;
			}

			switch_volt = dev_pm_opp_get_voltage(switch_opp);
			rcu_read_unlock();
		}

		if (data->ops.set_freq_prepare) {
<<<<<<< HEAD
			ret = data->ops.set_freq_prepare(data);
=======
			ret = data->ops.set_freq_prepare(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set frequency prepare\n");
				goto out;
			}
		}

		do_gettimeofday(&before_setfreq);

		if (switch_volt > data->old_volt) {
<<<<<<< HEAD
			ret = exynos_devfreq_set_voltage(&switch_volt, data);
=======
			ret = exynos_devfreq_set_voltage(dev, &switch_volt, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set voltage before switch freq\n");
				goto out;
			}
		}

		if (data->ops.change_to_switch_freq) {
<<<<<<< HEAD
			ret = data->ops.change_to_switch_freq(dev, data->sw_clk,
							      switch_freq, data->old_freq,
							      &data->new_freq);
=======
			ret = data->ops.change_to_switch_freq(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed change to switch frequency\n");
				goto out;
			}
		}

		if (switch_volt && switch_volt < data->old_volt) {
<<<<<<< HEAD
			ret = exynos_devfreq_set_voltage(&switch_volt, data);
=======
			ret = exynos_devfreq_set_voltage(dev, &switch_volt, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set voltage after switch freq\n");
				goto out;
			}
		}

		if (data->ops.set_freq) {
<<<<<<< HEAD
			ret = data->ops.set_freq(dev, data->new_freq, data->clk);
			if (ret) {
				dev_err(dev, "failed set frequency (%uKhz --> %uKhz)\n",
					data->old_freq, data->new_freq);
=======
			ret = data->ops.set_freq(dev, data->old_freq,
					data->new_freq, data);
			if (ret) {
				dev_err(dev, "failed set frequency (%uKhz --> %uKhz)\n",
						data->old_freq, data->new_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}
		}

		if (switch_volt < data->new_volt) {
<<<<<<< HEAD
			ret = exynos_devfreq_set_voltage(&data->new_volt, data);
			if (ret) {
				dev_err(dev,
					"failed set voltage before restore from switch freq\n");
=======
			ret = exynos_devfreq_set_voltage(dev, &data->new_volt, data);
			if (ret) {
				dev_err(dev, "failed set voltage before restore from switch freq\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}
		}

		if (data->ops.restore_from_switch_freq) {
<<<<<<< HEAD
			ret = data->ops.restore_from_switch_freq(dev, data->clk,
								 data->old_freq, data->new_freq);
=======
			ret = data->ops.restore_from_switch_freq(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed restore from switch frequency\n");
				goto out;
			}
		}

		if (switch_volt > data->new_volt) {
<<<<<<< HEAD
			ret = exynos_devfreq_set_voltage(&data->new_volt, data);
=======
			ret = exynos_devfreq_set_voltage(dev, &data->new_volt, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set voltage after restore from switch freq\n");
				goto out;
			}
		}

		do_gettimeofday(&after_setfreq);

		setfreq_time = (after_setfreq.tv_sec - before_setfreq.tv_sec) * USEC_PER_SEC +
<<<<<<< HEAD
		    (after_setfreq.tv_usec - before_setfreq.tv_usec);

		if (data->ops.set_freq_post) {
			ret = data->ops.set_freq_post(data);
=======
			(after_setfreq.tv_usec - before_setfreq.tv_usec);

		if (data->ops.set_freq_post) {
			ret = data->ops.set_freq_post(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set frequency post\n");
				goto out;
			}
		}
	} else {
<<<<<<< HEAD
		if (volt_order == PRE_SET_VOLT) {
			ret = exynos_devfreq_set_voltage(&data->new_volt, data);
			if (ret) {
				dev_err(dev, "failed set voltage (%uKhz:%uuV --> %uKhz:%uuV)\n",
					data->old_freq, data->old_volt,
					data->new_freq, data->new_volt);
=======
		if (data->set_volt_order == PRE_SET_VOLT) {
			ret = exynos_devfreq_set_voltage(dev, &data->new_volt, data);
			if (ret) {
				dev_err(dev, "failed set voltage (%uKhz:%uuV --> %uKhz:%uuV)\n",
						data->old_freq, data->old_volt,
						data->new_freq, data->new_volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}
		}

		if (data->ops.set_freq_prepare) {
<<<<<<< HEAD
			ret = data->ops.set_freq_prepare(data);
=======
			ret = data->ops.set_freq_prepare(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set frequency prepare\n");
				goto out;
			}
		}

		do_gettimeofday(&before_setfreq);
		if (data->ops.set_freq) {
<<<<<<< HEAD
			ret = data->ops.set_freq(dev, data->new_freq, data->clk);
			if (ret) {
				dev_err(dev, "failed set frequency (%uKhz --> %uKhz)\n",
					data->old_freq, data->new_freq);
=======
			ret = data->ops.set_freq(dev, data->old_freq,
					data->new_freq, data);
			if (ret) {
				dev_err(dev, "failed set frequency (%uKhz --> %uKhz)\n",
						data->old_freq, data->new_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}
		}
		do_gettimeofday(&after_setfreq);

		setfreq_time = (after_setfreq.tv_sec - before_setfreq.tv_sec) * USEC_PER_SEC +
<<<<<<< HEAD
		    (after_setfreq.tv_usec - before_setfreq.tv_usec);

		if (data->ops.set_freq_post) {
			ret = data->ops.set_freq_post(data);
=======
			(after_setfreq.tv_usec - before_setfreq.tv_usec);

		if (data->ops.set_freq_post) {
			ret = data->ops.set_freq_post(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "failed set frequency post\n");
				goto out;
			}
		}

<<<<<<< HEAD
		if (volt_order == POST_SET_VOLT) {
			ret = exynos_devfreq_set_voltage(&data->new_volt, data);
			if (ret) {
				dev_err(dev, "failed set voltage (%uKhz:%uuV --> %uKhz:%uuV)\n",
					data->old_freq, data->old_volt,
					data->new_freq, data->new_volt);
=======
		if (data->set_volt_order == POST_SET_VOLT) {
			ret = exynos_devfreq_set_voltage(dev, &data->new_volt, data);
			if (ret) {
				dev_err(dev, "failed set voltage (%uKhz:%uuV --> %uKhz:%uuV)\n",
						data->old_freq, data->old_volt,
						data->new_freq, data->new_volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				goto out;
			}
		}
	}

	if (data->use_cl_dvfs && !data->volt_offset) {
		if (data->ops.cl_dvfs_start) {
<<<<<<< HEAD
			ret = data->ops.cl_dvfs_start(data->dev);
=======
			ret = data->ops.cl_dvfs_start(data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			if (ret) {
				dev_err(dev, "cl_dvfs does not start\n");
				goto out;
			}
		}
	}

	exynos_ss_freq(data->ess_flag, data->old_freq, data->new_freq, ESS_FLAG_OUT);
<<<<<<< HEAD
	trace_exynos_freq_out(data->ess_flag, data->new_freq);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	data->old_freq = data->new_freq;
	data->old_idx = data->new_idx;
	data->old_volt = data->new_volt;

out:
	mutex_unlock(&data->lock);

	do_gettimeofday(&after_target);

	target_time = (after_target.tv_sec - before_target.tv_sec) * USEC_PER_SEC +
<<<<<<< HEAD
	    (after_target.tv_usec - before_target.tv_usec);
=======
			(after_target.tv_usec - before_target.tv_usec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	data->setfreq_delay = setfreq_time;
	data->target_delay = target_time;

<<<<<<< HEAD
	dev_dbg(dev, "target time: %d usec, setfreq time: %d usec\n", target_time, setfreq_time);
=======
	dev_dbg(dev, "target time: %d usec, setfreq time: %d usec\n",
			target_time, setfreq_time);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

<<<<<<< HEAD
static int exynos_devfreq_get_dev_status(struct device *dev, struct devfreq_dev_status *stat)
{
	struct platform_device *pdev = container_of(dev, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
=======
static int exynos_devfreq_get_dev_status(struct device *dev,
					struct devfreq_dev_status *stat)
{
	struct platform_device *pdev = container_of(dev, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	struct devfreq_simple_exynos_data *simple_exynos_data;
	s32 cur_idx = -1;
	int above_idx = 0;
	int below_idx = data->max_state - 1;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (data->devfreq_disabled)
		return -EAGAIN;

	if (data->ops.get_dev_status) {
<<<<<<< HEAD
		if (data->ops.get_dev_status(data))
=======
		if (data->ops.get_dev_status(dev, &data->ppmu_data, data))
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return -EAGAIN;
	}

	stat->current_frequency = data->devfreq->previous_freq;
<<<<<<< HEAD
	stat->busy_time = data->um_data.val_pmcnt;
	stat->total_time = data->um_data.val_ccnt;

	data->last_um_usage_rate = div64_u64(stat->busy_time * 100, stat->total_time);
=======

	if (data->gov_type == SIMPLE_EXYNOS) {
		simple_exynos_data = (struct devfreq_simple_exynos_data *)data->governor_data;

		cur_idx = exynos_devfreq_get_opp_idx(data->opp_list, data->max_state,
						(u32)stat->current_frequency);
		if (cur_idx < 0)
			return -EAGAIN;

		above_idx = cur_idx - 1;
		below_idx = cur_idx + 1;

		if (above_idx < 0)
			above_idx = 0;
		if (below_idx >= data->max_state)
			below_idx = data->max_state - 1;

		simple_exynos_data->above_freq = data->opp_list[above_idx].freq;
		simple_exynos_data->below_freq = data->opp_list[below_idx].freq;
	}

	stat->busy_time = data->ppmu_data.val_pmcnt;
	stat->total_time = data->ppmu_data.val_ccnt;

	data->last_ppmu_usage_rate = div64_u64(stat->busy_time * 100, stat->total_time);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return 0;
}

static int exynos_devfreq_suspend(struct device *dev)
{
	struct platform_device *pdev = container_of(dev, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret = 0;

<<<<<<< HEAD
	if (!data->vdd) {
		if (data->use_pd_off)
			return ret;
		else {
			dev_err(dev, "failed suspend. regulator hasn't been registered\n");
			return -ENODEV;
		}
	}

	if (pm_qos_request_active(&data->default_pm_qos_min))
		pm_qos_update_request(&data->default_pm_qos_min,
				data->devfreq_profile.suspend_freq);
	if (pm_qos_request_active(&data->default_pm_qos_max))
		pm_qos_update_request(&data->default_pm_qos_max,
				data->devfreq_profile.suspend_freq);

	if (data->ops.suspend) {
		ret = data->ops.suspend(data);
		if (ret) {
			dev_err(dev, "failed suspend\n");
			if (pm_qos_request_active(&data->default_pm_qos_min))
				pm_qos_update_request(&data->default_pm_qos_min,
							data->default_qos);
			if (pm_qos_request_active(&data->default_pm_qos_max))
				pm_qos_update_request(&data->default_pm_qos_max,
=======
	if (pm_qos_request_active(&data->default_pm_qos))
		pm_qos_update_request(&data->default_pm_qos,
				data->devfreq_profile.suspend_freq);
	if (pm_qos_request_active(&data->sys_pm_qos_max))
		pm_qos_update_request(&data->sys_pm_qos_max,
				data->devfreq_profile.suspend_freq);

	if (data->ops.suspend) {
		ret = data->ops.suspend(dev, data);
		if (ret) {
			dev_err(dev, "failed suspend\n");
			if (pm_qos_request_active(&data->default_pm_qos))
				pm_qos_update_request(&data->default_pm_qos,
							data->default_qos);
			if (pm_qos_request_active(&data->sys_pm_qos_max))
				pm_qos_update_request(&data->sys_pm_qos_max,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
							data->max_freq);
			return ret;
		}
	}

	return ret;
}

static int exynos_devfreq_resume(struct device *dev)
{
	struct platform_device *pdev = container_of(dev, struct platform_device, dev);
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);
	int ret = 0;

<<<<<<< HEAD
	if (!data->vdd) {
		if (data->use_pd_off)
			return ret;
		else {
			dev_err(dev, "failed resume. regulator hasn't been registered\n");
			return -ENODEV;
		}
	}

	if (data->ops.resume) {
		ret = data->ops.resume(data);
=======
	if (data->ops.resume) {
		ret = data->ops.resume(dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		if (ret)
			dev_err(dev, "failed resume\n");
	}

<<<<<<< HEAD
	if (pm_qos_request_active(&data->default_pm_qos_min))
		pm_qos_update_request(&data->default_pm_qos_min, data->default_qos);
	if (pm_qos_request_active(&data->default_pm_qos_max))
		pm_qos_update_request(&data->default_pm_qos_max, data->max_freq);
=======
	if (pm_qos_request_active(&data->default_pm_qos))
		pm_qos_update_request(&data->default_pm_qos, data->default_qos);
	if (pm_qos_request_active(&data->sys_pm_qos_max))
		pm_qos_update_request(&data->sys_pm_qos_max, data->max_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

static int exynos_devfreq_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct exynos_devfreq_data *data;
	struct dev_pm_opp *init_opp;
	unsigned long init_freq = 0;

	data = kzalloc(sizeof(struct exynos_devfreq_data), GFP_KERNEL);
	if (data == NULL) {
		dev_err(&pdev->dev, "failed to allocate devfreq data\n");
		ret = -ENOMEM;
		goto err_data;
	}

	data->dev = &pdev->dev;

	mutex_init(&data->lock);
	mutex_init(&data->regulator_lock);

	/* parsing devfreq dts data for exynos */
	ret = exynos_devfreq_parse_dt(data->dev->of_node, data);
	if (ret) {
		dev_err(data->dev, "failed to parse private data\n");
		goto err_parse_dt;
	}

<<<<<<< HEAD
=======
	data->max_state = data->opp_list_length;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	data->devfreq_profile.max_state = data->max_state;
	data->devfreq_profile.target = exynos_devfreq_target;
	if (data->use_get_dev)
		data->devfreq_profile.get_dev_status = exynos_devfreq_get_dev_status;

<<<<<<< HEAD
	if (data->gov_type == SIMPLE_INTERACTIVE) {
		data->simple_interactive_data.pm_qos_class = data->pm_qos_class;
		data->simple_interactive_data.pm_qos_class_max = data->pm_qos_class_max;
		data->governor_data = &data->simple_interactive_data;
=======
	if (data->gov_type == SIMPLE_ONDEMAND) {
		data->simple_ondemand_data.pm_qos_class = data->pm_qos_class;
		data->simple_ondemand_data.cal_qos_max = data->cal_qos_max;
		data->governor_data = &data->simple_ondemand_data;
	} else if (data->gov_type == SIMPLE_EXYNOS) {
		data->simple_exynos_data.pm_qos_class = data->pm_qos_class;
		data->simple_exynos_data.pm_qos_class_max = data->pm_qos_class_max;
		data->simple_exynos_data.cal_qos_max = data->cal_qos_max;
		data->governor_data = &data->simple_exynos_data;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	if (exynos_devfreq_init[data->devfreq_type].init_prepare == NULL) {
		dev_err(data->dev, "devfreq init prepare function is not regist\n");
		ret = -ENODEV;
		goto err_init_prepare;
	} else {
		ret = exynos_devfreq_init[data->devfreq_type].init_prepare(data);
		if (ret) {
<<<<<<< HEAD
			dev_err(data->dev, "failed devfreq(%d) init prepare\n", data->devfreq_type);
=======
			dev_err(data->dev, "failed devfreq(%d) init prepare\n",
						data->devfreq_type);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			goto err_init_prepare;
		}
	}

	if (data->ops.init) {
<<<<<<< HEAD
		ret = data->ops.init(data);
=======
		ret = data->ops.init(data->dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		if (ret) {
			dev_err(data->dev, "failed devfreq init\n");
			goto err_devfreq_init;
		}
	}

	data->devfreq_profile.freq_table = kzalloc(sizeof(int) * data->max_state, GFP_KERNEL);
	if (data->devfreq_profile.freq_table == NULL) {
		dev_err(data->dev, "failed to allocate for freq_table\n");
		ret = -ENOMEM;
		goto err_freqtable;
	}

<<<<<<< HEAD
	ret = exynos_init_freq_table(data);
=======
	ret = exynos_init_freq_table(data->dev, data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (ret) {
		dev_err(data->dev, "failed initailize freq_table\n");
		goto err_init_table;
	}

	devfreq_data[data->devfreq_type] = data;
	platform_set_drvdata(pdev, data);

	if (data->use_regulator) {
		data->volt_offset = 0;
		data->limit_cold_volt = data->opp_list[0].volt;
<<<<<<< HEAD
		data->vdd = regulator_get(data->dev, data->regulator_name);
=======
		data->vdd = regulator_get(NULL, data->regulator_name);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		if (IS_ERR(data->vdd)) {
			dev_err(data->dev, "failed get regulator(%s)\n", data->regulator_name);
			ret = -ENODEV;
			goto err_regulator;
		}
<<<<<<< HEAD
	}

	data->old_freq = data->devfreq_profile.initial_freq;
	data->old_idx = exynos_devfreq_get_opp_idx(data->opp_list, data->max_state, data->old_freq);
=======
		data->ops.set_voltage = exynos_devfreq_set_voltage;
	}

	/* This dummy regulator is for sync voltage */
	if (data->use_regulator_dummy) {
		data->vdd_dummy = regulator_get(NULL, data->regulator_name);
		if (IS_ERR(data->vdd_dummy)) {
			dev_err(data->dev, "failed get dummy regulator(%s)\n", data->regulator_name);
			ret = -ENODEV;
			goto err_regulator_dummy;
		}
	}

	data->old_freq = data->devfreq_profile.initial_freq;
	data->old_idx = exynos_devfreq_get_opp_idx(data->opp_list, data->max_state,
							data->old_freq);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (data->old_idx < 0) {
		ret = -EINVAL;
		goto err_old_idx;
	}

	rcu_read_lock();
	init_freq = (unsigned long)data->old_freq;
	init_opp = devfreq_recommended_opp(data->dev, &init_freq, 0);
	if (IS_ERR(init_opp)) {
		rcu_read_unlock();
		dev_err(data->dev, "not found valid OPP table for sync\n");
		ret = PTR_ERR(init_opp);
		goto err_get_opp;
	}
	data->new_volt = dev_pm_opp_get_voltage(init_opp);
	rcu_read_unlock();

<<<<<<< HEAD
	dev_info(data->dev, "Initial Frequency: %ld, Initial Voltage: %d\n", init_freq,
		 data->new_volt);

	ret = exynos_devfreq_set_voltage(&data->new_volt, data);
	if (ret) {
		dev_err(data->dev, "failed set voltage in probe (%ukhz:%uuV)\n",
			data->old_freq, data->new_volt);
=======
	dev_info(data->dev, "Initial Frequency: %ld, Initial Voltage: %d\n", init_freq, data->new_volt);

	ret = exynos_devfreq_set_voltage(data->dev, &data->new_volt, data);
	if (ret) {
		dev_err(data->dev, "failed set voltage in probe (%ukhz:%uuV)\n",
				data->old_freq, data->new_volt);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto err_set_voltage;
	}

	data->old_volt = data->new_volt;

	/* This flag guarantees initial frequency during boot time */
	data->devfreq_disabled = true;

	data->devfreq = devfreq_add_device(data->dev, &data->devfreq_profile,
<<<<<<< HEAD
					   data->governor_name, data->governor_data);
=======
					data->governor_name, data->governor_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (IS_ERR(data->devfreq)) {
		dev_err(data->dev, "failed devfreq device added\n");
		ret = -EINVAL;
		goto err_devfreq;
	}

	data->devfreq->min_freq = data->min_freq;
	data->devfreq->max_freq = data->max_freq;

<<<<<<< HEAD
	pm_qos_add_request(&data->sys_pm_qos_min, (int)data->pm_qos_class, data->default_qos);
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	pm_qos_add_request(&data->debug_pm_qos_min, (int)data->pm_qos_class, data->default_qos);
	pm_qos_add_request(&data->debug_pm_qos_max, (int)data->pm_qos_class_max, data->max_freq);
#endif
	if (data->pm_qos_class_max)
		pm_qos_add_request(&data->default_pm_qos_max, (int)data->pm_qos_class_max,
				   data->max_freq);
	pm_qos_add_request(&data->default_pm_qos_min, (int)data->pm_qos_class, data->default_qos);
	pm_qos_add_request(&data->boot_pm_qos, (int)data->pm_qos_class, data->default_qos);

	if (data->use_um) {
		/* if polling_ms is 0, update_devfreq function is called by um */
		if (data->devfreq_profile.polling_ms == 0) {
			data->um_nb = kzalloc(sizeof(struct devfreq_notifier_block), GFP_KERNEL);
			if (data->um_nb == NULL) {
				dev_err(data->dev, "failed to allocate notifier block\n");
				ret = -ENOMEM;
				goto err_um_nb;
			}

			data->um_nb->df = data->devfreq;
			data->um_nb->nb.notifier_call = exynos_devfreq_notifier;
=======
	pm_qos_add_request(&data->sys_pm_qos, (int)data->pm_qos_class, data->default_qos);
	if (data->pm_qos_class_max)
		pm_qos_add_request(&data->sys_pm_qos_max, (int)data->pm_qos_class_max,
								data->max_freq);
	pm_qos_add_request(&data->default_pm_qos, (int)data->pm_qos_class, data->default_qos);
	pm_qos_add_request(&data->boot_pm_qos, (int)data->pm_qos_class, data->default_qos);

	if (data->use_ppmu) {
		/* if polling_ms is 0, update_devfreq function is called by ppmu */
		if (data->devfreq_profile.polling_ms == 0) {
			data->ppmu_nb = kzalloc(sizeof(struct devfreq_notifier_block), GFP_KERNEL);
			if (data->ppmu_nb == NULL) {
				dev_err(data->dev, "failed to allocate notifier block\n");
				ret = -ENOMEM;
				goto err_ppmu_nb;
			}

			data->ppmu_nb->df = data->devfreq;
			data->ppmu_nb->nb.notifier_call = exynos_devfreq_notifier;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			data->last_monitor_jiffies = get_jiffies_64();
		}

		/*
<<<<<<< HEAD
		 * The UM data should be register.
		 * And if polling_ms is 0, um notifier should be register in callback.
		 */
		if (data->ops.um_register) {
			ret = data->ops.um_register(data);
			if (ret) {
				dev_err(data->dev, "failed register um\n");
				goto err_um;
=======
		 * The PPMU data should be register.
		 * And if polling_ms is 0, ppmu notifier should be register in callback.
		 */
		if (data->ops.ppmu_register) {
			ret = data->ops.ppmu_register(data->dev, data);
			if (ret) {
				dev_err(data->dev, "failed register ppmu\n");
				goto err_ppmu;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			}
		}
	}

	ret = devfreq_register_opp_notifier(data->dev, data->devfreq);
	if (ret) {
		dev_err(data->dev, "failed register opp notifier\n");
		goto err_opp_noti;
	}

	if (data->use_tmu) {
		data->tmu_notifier.notifier_call = exynos_devfreq_tmu_notifier;
		ret = exynos_tmu_add_notifier(&data->tmu_notifier);
		if (ret) {
			dev_err(data->dev, "failed register tmu notifier\n");
			goto err_tmu_noti;
		}
	}

	data->reboot_notifier.notifier_call = exynos_devfreq_reboot_notifier;
	ret = register_reboot_notifier(&data->reboot_notifier);
	if (ret) {
		dev_err(data->dev, "failed register reboot notifier\n");
		goto err_reboot_noti;
	}

<<<<<<< HEAD
	data->pm_notifier.notifier_call = exynos_devfreq_pm_notifier;
	ret = register_pm_notifier(&data->pm_notifier);
	if (ret) {
		dev_err(data->dev, "failed register pm notifier\n");
		goto err_pm_noti;
	}

	ret = sysfs_create_file(&data->devfreq->dev.kobj, &dev_attr_scaling_devfreq_min.attr);
	if (ret)
		dev_warn(data->dev, "failed create sysfs for devfreq pm_qos_min\n");

#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	ret = sysfs_create_group(&data->devfreq->dev.kobj, &exynos_devfreq_attr_group);
	if (ret)
		dev_warn(data->dev, "failed create sysfs for devfreq data\n");
#endif
	ret = sysfs_create_group(&data->devfreq->dev.kobj, &devfreq_delay_time_attr_group);
	if (ret)
		dev_warn(data->dev, "failed create sysfs for devfreq data\n");

	data->devfreq_disabled = false;
	pm_qos_update_request_timeout(&data->boot_pm_qos, data->devfreq_profile.initial_freq,
				      data->boot_qos_timeout * USEC_PER_SEC);
=======
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	ret = sysfs_create_group(&data->devfreq->dev.kobj,
				&exynos_devfreq_attr_group);
	if (ret)
		dev_warn(data->dev, "failed create sysfs for devfreq data\n");
#endif

	data->devfreq_disabled = false;

	pm_qos_update_request_timeout(&data->boot_pm_qos, data->devfreq_profile.initial_freq,
					data->boot_qos_timeout * USEC_PER_SEC);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	dev_info(data->dev, "devfreq is initialized!!\n");

	return 0;

<<<<<<< HEAD
err_pm_noti:
	unregister_reboot_notifier(&data->reboot_notifier);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
err_reboot_noti:
err_tmu_noti:
	devfreq_unregister_opp_notifier(data->dev, data->devfreq);
err_opp_noti:
<<<<<<< HEAD
	if (data->use_um) {
		if (data->ops.um_unregister)
			data->ops.um_unregister(data);
	}
err_um:
	if (data->um_nb)
		kfree(data->um_nb);
err_um_nb:
	if (data->ops.exit)
		data->ops.exit(data);
err_devfreq_init:
	pm_qos_remove_request(&data->boot_pm_qos);
	pm_qos_remove_request(&data->default_pm_qos_min);
	if (data->pm_qos_class_max)
		pm_qos_remove_request(&data->default_pm_qos_max);
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	pm_qos_remove_request(&data->debug_pm_qos_min);
	pm_qos_remove_request(&data->debug_pm_qos_max);
#endif
	pm_qos_remove_request(&data->sys_pm_qos_min);
=======
	if (data->use_ppmu) {
		if (data->ops.ppmu_unregister)
			data->ops.ppmu_unregister(data->dev, data);
	}
err_ppmu:
	if (data->ppmu_nb)
		kfree(data->ppmu_nb);
err_ppmu_nb:
	if (data->ops.exit)
		data->ops.exit(data->dev, data);
err_devfreq_init:
	pm_qos_remove_request(&data->boot_pm_qos);
	pm_qos_remove_request(&data->default_pm_qos);
	if (data->pm_qos_class_max)
		pm_qos_remove_request(&data->sys_pm_qos_max);
	pm_qos_remove_request(&data->sys_pm_qos);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	devfreq_remove_device(data->devfreq);
err_devfreq:
err_set_voltage:
err_get_opp:
err_old_idx:
<<<<<<< HEAD
=======
	if (data->use_regulator_dummy) {
		if (data->vdd_dummy)
			regulator_put(data->vdd_dummy);
	}
err_regulator_dummy:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (data->use_regulator) {
		if (data->vdd)
			regulator_put(data->vdd);
	}
err_regulator:
	platform_set_drvdata(pdev, NULL);
err_init_table:
	kfree(data->devfreq_profile.freq_table);
err_freqtable:
err_init_prepare:
<<<<<<< HEAD
	if (data->use_um)
		kfree(data->um_data.um_list);
=======
	if (data->use_ppmu)
		kfree(data->ppmu_data.ppmu_list);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
err_parse_dt:
	mutex_destroy(&data->regulator_lock);
	mutex_destroy(&data->lock);
	kfree(data);
err_data:

	return ret;
}

static int exynos_devfreq_remove(struct platform_device *pdev)
{
	struct exynos_devfreq_data *data = platform_get_drvdata(pdev);

<<<<<<< HEAD
	sysfs_remove_file(&data->devfreq->dev.kobj, &dev_attr_scaling_devfreq_min.attr);
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	sysfs_remove_group(&data->devfreq->dev.kobj, &exynos_devfreq_attr_group);
#endif
	sysfs_remove_group(&data->devfreq->dev.kobj, &devfreq_delay_time_attr_group);

	unregister_pm_notifier(&data->pm_notifier);
	unregister_reboot_notifier(&data->reboot_notifier);
	devfreq_unregister_opp_notifier(data->dev, data->devfreq);

	if (data->use_um) {
		if (data->ops.um_unregister)
			data->ops.um_unregister(data);
	}

	if (data->um_nb)
		kfree(data->um_nb);

	if (data->ops.exit)
		data->ops.exit(data);

	pm_qos_remove_request(&data->boot_pm_qos);
	pm_qos_remove_request(&data->default_pm_qos_min);
	if (data->pm_qos_class_max)
		pm_qos_remove_request(&data->default_pm_qos_max);
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	pm_qos_remove_request(&data->debug_pm_qos_min);
	pm_qos_remove_request(&data->debug_pm_qos_max);
#endif
	pm_qos_remove_request(&data->sys_pm_qos_min);
	devfreq_remove_device(data->devfreq);
=======
#ifdef CONFIG_ARM_EXYNOS_DEVFREQ_DEBUG
	sysfs_remove_group(&data->devfreq->dev.kobj,
				&exynos_devfreq_attr_group);
#endif
	unregister_reboot_notifier(&data->reboot_notifier);
	devfreq_unregister_opp_notifier(data->dev, data->devfreq);

	if (data->use_ppmu) {
		if (data->ops.ppmu_unregister)
			data->ops.ppmu_unregister(data->dev, data);
	}

	if (data->ppmu_nb)
		kfree(data->ppmu_nb);

	if (data->ops.exit)
		data->ops.exit(data->dev, data);

	pm_qos_remove_request(&data->boot_pm_qos);
	pm_qos_remove_request(&data->default_pm_qos);
	if (data->pm_qos_class_max)
		pm_qos_remove_request(&data->sys_pm_qos_max);
	pm_qos_remove_request(&data->sys_pm_qos);
	devfreq_remove_device(data->devfreq);
	if (data->use_regulator_dummy) {
		if (data->vdd_dummy)
			regulator_put(data->vdd_dummy);
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (data->use_regulator) {
		if (data->vdd)
			regulator_put(data->vdd);
	}
	platform_set_drvdata(pdev, NULL);
	kfree(data->devfreq_profile.freq_table);
<<<<<<< HEAD
	if (data->use_um)
		kfree(data->um_data.um_list);
=======
	if (data->use_ppmu)
		kfree(data->ppmu_data.ppmu_list);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	mutex_destroy(&data->regulator_lock);
	mutex_destroy(&data->lock);
	kfree(data);

	return 0;
}

static struct platform_device_id exynos_devfreq_driver_ids[] = {
	{
<<<<<<< HEAD
	 .name = EXYNOS_DEVFREQ_MODULE_NAME,
	 },
	{},
};

=======
		.name		= EXYNOS_DEVFREQ_MODULE_NAME,
	},
	{},
};
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
MODULE_DEVICE_TABLE(platform, exynos_devfreq_driver_ids);

static const struct of_device_id exynos_devfreq_match[] = {
	{
<<<<<<< HEAD
	 .compatible = "samsung,exynos-devfreq",
	 },
	{},
};

MODULE_DEVICE_TABLE(of, exynos_devfreq_match);

static const struct dev_pm_ops exynos_devfreq_pm_ops = {
	.suspend = exynos_devfreq_suspend,
	.resume = exynos_devfreq_resume,
};

static struct platform_driver exynos_devfreq_driver = {
	.probe = exynos_devfreq_probe,
	.remove = exynos_devfreq_remove,
	.id_table = exynos_devfreq_driver_ids,
	.driver = {
		.name = EXYNOS_DEVFREQ_MODULE_NAME,
		.owner = THIS_MODULE,
		.pm = &exynos_devfreq_pm_ops,
		.of_match_table = exynos_devfreq_match,
=======
		.compatible	= "samsung,exynos-devfreq",
	},
	{},
};
MODULE_DEVICE_TABLE(of, exynos_devfreq_match);

static const struct dev_pm_ops exynos_devfreq_pm_ops = {
	.suspend	= exynos_devfreq_suspend,
	.resume		= exynos_devfreq_resume,
};

static struct platform_driver exynos_devfreq_driver = {
	.probe		= exynos_devfreq_probe,
	.remove		= exynos_devfreq_remove,
	.id_table	= exynos_devfreq_driver_ids,
	.driver = {
		.name	= EXYNOS_DEVFREQ_MODULE_NAME,
		.owner	= THIS_MODULE,
		.pm	= &exynos_devfreq_pm_ops,
		.of_match_table	= exynos_devfreq_match,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	},
};

module_platform_driver(exynos_devfreq_driver);

MODULE_AUTHOR("Taekki Kim <taekki.kim@samsung.com>");
MODULE_DESCRIPTION("Samsung EXYNOS Soc series devfreq common driver");
MODULE_LICENSE("GPL");
