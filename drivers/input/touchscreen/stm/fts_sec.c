#ifdef SEC_TSP_FACTORY_TEST

<<<<<<< HEAD
#define TSP_FACTEST_RESULT_PASS		2
#define TSP_FACTEST_RESULT_FAIL		1
#define TSP_FACTEST_RESULT_NONE		0

#define BUFFER_MAX					(256 * 1024) - 16
#define READ_CHUNK_SIZE				128 // (2 * 1024) - 16
=======
#define BUFFER_MAX			((256 * 1024) - 16)
#define READ_CHUNK_SIZE			128 // (2 * 1024) - 16
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

enum {
	TYPE_RAW_DATA = 0,
	TYPE_FILTERED_DATA = 2,
	TYPE_STRENGTH_DATA = 4,
	TYPE_BASELINE_DATA = 6
};

enum {
	BUILT_IN = 0,
	UMS,
};

<<<<<<< HEAD
enum CMD_STATUS {
	CMD_STATUS_WAITING = 0,
	CMD_STATUS_RUNNING,
	CMD_STATUS_OK,
	CMD_STATUS_FAIL,
	CMD_STATUS_NOT_APPLICABLE,
};

#ifdef FTS_SUPPORT_TOUCH_KEY
enum {
	TYPE_TOUCHKEY_RAW			= 0x34,
	TYPE_TOUCHKEY_STRENGTH	= 0x36,
	TYPE_TOUCHKEY_THRESHOLD	= 0x48,
};
#endif

=======
#ifdef FTS_SUPPORT_TOUCH_KEY
enum {
	TYPE_TOUCHKEY_RAW	= 0x34,
	TYPE_TOUCHKEY_STRENGTH	= 0x36,
};
#endif

#define FTS_FLASH_DATA_OFFSET_BASE			16

#define FTS_FLASH_WRITE_COMMAND_SEC_FACTORY_DEBUG	4
enum fts_nvm_data_type {		/* Write Command */
	FACTORY_TEST_RESULT = 1,	/* C7 01 */
	CALIBRATION_INFOMATION,		/* C7 02 */
	PRESSURE_STRENGTH,		/* C7 03 00 02*/
	PRESSURE_RAWDATA,		/* C7 03 00 03*/
	GROUP_INDEX,			/* C7 03 00 04*/
	SEC_FACTORY_DEBUG,		/* C7 04 */
};

struct fts_nvm_data_map {
	int type;
	int offset;
	int length;
};

#define NVM_CMD(mtype, moffset, mlength)		.type = mtype,	.offset = moffset,	.length = mlength

/* This Flash Meory Map is FIXED by STM firmware
 * Do not change MAP.
 */
struct fts_nvm_data_map nvm_data[] = {
	{NVM_CMD(0, 0, 0),},
	{NVM_CMD(FACTORY_TEST_RESULT, 0x0, 2),},	/* SEC */
	{NVM_CMD(CALIBRATION_INFOMATION, 0x2, 4),},	/* SEC */
	{NVM_CMD(PRESSURE_STRENGTH, 0x6, 0x20),},	/* STM */
	{NVM_CMD(PRESSURE_RAWDATA, 0x26, 0x20),},	/* STM */
	{NVM_CMD(GROUP_INDEX, 0x46, 1),},		/* STM */
	{NVM_CMD(SEC_FACTORY_DEBUG, 0x47, 4),},		/* SEC */
};

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void fw_update(void *device_data);
static void get_fw_ver_bin(void *device_data);
static void get_fw_ver_ic(void *device_data);
static void get_config_ver(void *device_data);
static void get_threshold(void *device_data);
static void module_off_master(void *device_data);
static void module_on_master(void *device_data);
static void get_chip_vendor(void *device_data);
static void get_chip_name(void *device_data);
<<<<<<< HEAD
=======
static void get_mis_cal_info(void *device_data);
static void get_wet_mode(void *device_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void get_x_num(void *device_data);
static void get_y_num(void *device_data);
static void get_checksum_data(void *device_data);
static void run_reference_read(void *device_data);
static void get_reference(void *device_data);
static void run_rawcap_read(void *device_data);
static void get_rawcap(void *device_data);
static void run_delta_read(void *device_data);
static void get_delta(void *device_data);
<<<<<<< HEAD
static void run_abscap_read(void *device_data);
static void run_absdelta_read(void *device_data);
=======
static void get_pat_information(void *device_data);
static void set_external_factory(void *device_data);
#ifdef FTS_SUPPORT_HOVER
static void run_abscap_read(void *device_data);
static void run_absdelta_read(void *device_data);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void run_ix_data_read(void *device_data);
static void run_ix_data_read_all(void *device_data);
static void run_self_raw_read(void *device_data);
static void run_self_raw_read_all(void *device_data);
<<<<<<< HEAD
static void run_trx_short_test(void *device_data);
static void get_cx_data(void *device_data);
static void get_cx_all_data(void *device_data);
static void run_cx_data_read(void *device_data);
#ifdef FTS_SUPPORT_TOUCH_KEY
static void run_key_cx_data_read(void *device_data);
#endif
static void set_tsp_test_result(void *device_data);
static void get_tsp_test_result(void *device_data);
static void hover_enable(void *device_data);
/* static void hover_no_sleep_enable(void *device_data); */
static void glove_mode(void *device_data);
static void get_glove_sensitivity(void *device_data);
static void clear_cover_mode(void *device_data);
static void fast_glove_mode(void *device_data);
=======
static void run_wtr_cx_data_read(void *device_data);
static void run_wtr_cx_data_read_all(void *device_data);
static void run_trx_short_test(void *device_data);
static void get_cx_data(void *device_data);
static void run_cx_data_read(void *device_data);
static void get_cx_all_data(void *device_data);
static void get_strength_all_data(void *device_data);
#ifdef FTS_SUPPORT_TOUCH_KEY
static void run_key_cx_data_read(void *device_data);
#endif
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
static void run_force_pressure_calibration(void *device_data);
static void set_pressure_test_mode(void *device_data);
static void run_pressure_strength_read_all(void *device_data);
static void run_pressure_rawdata_read_all(void *device_data);
static void run_pressure_ix_data_read_all(void *device_data);
static void set_pressure_strength(void *device_data);
static void set_pressure_rawdata(void *device_data);
static void set_pressure_data_index(void *device_data);
static void get_pressure_strength(void *device_data);
static void get_pressure_rawdata(void *device_data);
static void get_pressure_data_index(void *device_data);
static void set_pressure_strength_clear(void *device_data);
static void get_pressure_threshold(void *device_data);
static void set_pressure_user_level(void *device_data);
static void get_pressure_user_level(void *device_data);
#endif

static void set_tsp_test_result(void *device_data);
static void get_tsp_test_result(void *device_data);
static void increase_disassemble_count(void *device_data);
static void get_disassemble_count(void *device_data);
#ifdef FTS_SUPPORT_HOVER
static void hover_enable(void *device_data);
/* static void hover_no_sleep_enable(void *device_data); */
#endif
#ifdef CONFIG_GLOVE_TOUCH
static void glove_mode(void *device_data);
static void get_glove_sensitivity(void *device_data);
static void fast_glove_mode(void *device_data);
#endif
static void clear_cover_mode(void *device_data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void report_rate(void *device_data);
#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
static void interrupt_control(void *device_data);
#endif

<<<<<<< HEAD
#if defined(CONFIG_INPUT_BOOSTER) || defined(TOUCH_BOOSTER_DVFS)
static void boost_level(void *device_data);
#endif
static void set_lowpower_mode(void *device_data);
static void set_deepsleep_mode(void *device_data);
static void active_sleep_enable(void *device_data);
static void second_screen_enable(void *device_data);
static void set_longpress_enable(void *device_data);
static void set_sidescreen_x_length(void *device_data);
static void set_dead_zone(void *device_data);
#ifdef SMARTCOVER_COVER
static void smartcover_cmd(void *device_data);
#endif
#ifdef FTS_SUPPORT_STRINGLIB
static void quick_shot_enable(void *device_data);
static void scrub_enable(void *device_data);
static void quick_app_access_enable(void *device_data);
static void direct_indicator_enable(void *device_data);
static void spay_enable(void *device_data);
#endif
static void delay(void *device_data);
static void debug(void *device_data);
static void run_autotune_enable(void *device_data);
static void run_autotune(void *device_data);

static void set_mainscreen_disable(void *device_data);
static void set_rotation_status(void *device_data);

static void not_support_cmd(void *device_data);

static ssize_t store_cmd(struct device *dev, struct device_attribute *devattr,
			   const char *buf, size_t count);
static ssize_t show_cmd_status(struct device *dev,
				struct device_attribute *devattr, char *buf);
static ssize_t show_cmd_result(struct device *dev,
				struct device_attribute *devattr, char *buf);
static ssize_t cmd_list_show(struct device *dev,
				struct device_attribute *attr, char *buf);
static ssize_t fts_scrub_position(struct device *dev,
				struct device_attribute *attr, char *buf);
static ssize_t fts_edge_x_position(struct device *dev,
				struct device_attribute *attr, char *buf);

#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
static void tui_mode_cmd(struct fts_ts_info *info);
#endif

#define FT_CMD(name, func)	.cmd_name = name, .cmd_func = func
struct ft_cmd {
	struct list_head list;
	const char *cmd_name;
	void (*cmd_func) (void *device_data);
};
struct ft_cmd ft_commands[] = {
	{FT_CMD("fw_update", fw_update),},
	{FT_CMD("get_fw_ver_bin", get_fw_ver_bin),},
	{FT_CMD("get_fw_ver_ic", get_fw_ver_ic),},
	{FT_CMD("get_config_ver", get_config_ver),},
	{FT_CMD("get_threshold", get_threshold),},
	{FT_CMD("module_off_master", module_off_master),},
	{FT_CMD("module_on_master", module_on_master),},
	{FT_CMD("module_off_slave", not_support_cmd),},
	{FT_CMD("module_on_slave", not_support_cmd),},
	{FT_CMD("get_chip_vendor", get_chip_vendor),},
	{FT_CMD("get_chip_name", get_chip_name),},
	{FT_CMD("get_x_num", get_x_num),},
	{FT_CMD("get_y_num", get_y_num),},
	{FT_CMD("get_checksum_data", get_checksum_data),},
	{FT_CMD("run_reference_read", run_reference_read),},
	{FT_CMD("get_reference", get_reference),},
	{FT_CMD("run_rawcap_read", run_rawcap_read),},
	{FT_CMD("get_rawcap", get_rawcap),},
	{FT_CMD("run_delta_read", run_delta_read),},
	{FT_CMD("get_delta", get_delta),},
	{FT_CMD("run_abscap_read" , run_abscap_read),},
	{FT_CMD("run_absdelta_read", run_absdelta_read),},
	{FT_CMD("run_ix_data_read", run_ix_data_read),},
	{FT_CMD("run_ix_data_read_all", run_ix_data_read_all),},
	{FT_CMD("run_self_raw_read", run_self_raw_read),},
	{FT_CMD("run_self_raw_read_all", run_self_raw_read_all),},
	{FT_CMD("run_trx_short_test", run_trx_short_test),},
	{FT_CMD("get_cx_data", get_cx_data),},
	{FT_CMD("get_cx_all_data", get_cx_all_data),},
	{FT_CMD("run_cx_data_read", run_cx_data_read),},
#ifdef FTS_SUPPORT_TOUCH_KEY
	{FT_CMD("run_key_cx_data_read", run_key_cx_data_read),},
#endif
	{FT_CMD("set_tsp_test_result", set_tsp_test_result),},
	{FT_CMD("get_tsp_test_result", get_tsp_test_result),},
	{FT_CMD("hover_enable", hover_enable),},
	{FT_CMD("hover_no_sleep_enable", not_support_cmd),},
	{FT_CMD("glove_mode", glove_mode),},
	{FT_CMD("get_glove_sensitivity", get_glove_sensitivity),},
	{FT_CMD("clear_cover_mode", clear_cover_mode),},
	{FT_CMD("fast_glove_mode", fast_glove_mode),},
	{FT_CMD("report_rate", report_rate),},
#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
	{FT_CMD("interrupt_control", interrupt_control),},
#endif
#if defined(CONFIG_INPUT_BOOSTER)|| defined(TOUCH_BOOSTER_DVFS)
	{FT_CMD("boost_level", boost_level),},
#endif
	{FT_CMD("set_lowpower_mode", set_lowpower_mode),},
	{FT_CMD("set_deepsleep_mode", set_deepsleep_mode),},
	{FT_CMD("active_sleep_enable", active_sleep_enable),},
	{FT_CMD("second_screen_enable", second_screen_enable),},
	{FT_CMD("set_longpress_enable", set_longpress_enable),},
	{FT_CMD("set_sidescreen_x_length", set_sidescreen_x_length),},
	{FT_CMD("set_dead_zone", set_dead_zone),},
#ifdef FTS_SUPPORT_STRINGLIB
	{FT_CMD("quick_shot_enable", quick_shot_enable),},
	{FT_CMD("scrub_enable", scrub_enable),},
	{FT_CMD("quick_app_access_enable", quick_app_access_enable),},
	{FT_CMD("direct_indicator_enable", direct_indicator_enable),},
	{FT_CMD("spay_enable", spay_enable),},
#endif
#ifdef SMARTCOVER_COVER
	{FT_CMD("smartcover_cmd", smartcover_cmd),},
#endif
	{FT_CMD("delay", delay),},
	{FT_CMD("debug", debug),},
	{FT_CMD("run_autotune_enable", run_autotune_enable),},
	{FT_CMD("run_autotune", run_autotune),},
	{FT_CMD("set_mainscreen_disable", set_mainscreen_disable),},
	{FT_CMD("set_rotation_status", set_rotation_status),},
	{FT_CMD("not_support_cmd", not_support_cmd),},
};

static DEVICE_ATTR(cmd, S_IWUSR | S_IWGRP, NULL, store_cmd);
static DEVICE_ATTR(cmd_status, S_IRUGO, show_cmd_status, NULL);
static DEVICE_ATTR(cmd_result, S_IRUGO, show_cmd_result, NULL);
static DEVICE_ATTR(cmd_list, S_IRUGO, cmd_list_show, NULL);
static DEVICE_ATTR(scrub_pos, S_IRUGO, fts_scrub_position, NULL);
static DEVICE_ATTR(edge_pos, S_IRUGO, fts_edge_x_position, NULL);

static struct attribute *sec_touch_facotry_attributes[] = {
	&dev_attr_cmd.attr,
	&dev_attr_cmd_status.attr,
	&dev_attr_cmd_result.attr,
	&dev_attr_cmd_list.attr,
	&dev_attr_scrub_pos.attr,
	&dev_attr_edge_pos.attr,
	NULL,
};

static struct attribute_group sec_touch_factory_attr_group = {
	.attrs = sec_touch_facotry_attributes,
};

static int fts_check_index(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	int node;
	if (info->cmd_param[0] < 0
	  || info->cmd_param[0] >= info->SenseChannelLength
	  || info->cmd_param[1] < 0
	  || info->cmd_param[1] >= info->ForceChannelLength) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		strncat(info->cmd_result, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_FAIL;
		tsp_debug_info(true, &info->client->dev, "%s: parameter error: %u,%u\n",
			   __func__, info->cmd_param[0], info->cmd_param[1]);
		node = -1;
		return node;
	}
	node = info->cmd_param[1] * info->SenseChannelLength + info->cmd_param[0];
	tsp_debug_info(true, &info->client->dev, "%s: node = %d\n", __func__, node);
	return node;
}

static ssize_t fts_scrub_position(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
	char buff[CMD_STR_LEN] = { 0 };

	if (!info) {
		printk(KERN_ERR "%s: No platform data found\n",
				__func__);
		return -EINVAL;
	}

	if (!info->input_dev) {
		printk(KERN_ERR "%s: No input_dev data found\n",
				__func__);
		return -EINVAL;
	}

	tsp_debug_info(true, &info->client->dev, "%s: %d %d %d\n",
				__func__, info->scrub_id, info->scrub_x, info->scrub_y);
	snprintf(buff, sizeof(buff), "%d %d %d", info->scrub_id, info->scrub_x, info->scrub_y);

	info->scrub_id = 0;
	info->scrub_x = 0;
	info->scrub_y = 0;

	return snprintf(buf, TSP_BUF_SIZE, "%s\n", buff);
}

static ssize_t fts_edge_x_position(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
	char buff[CMD_STR_LEN] = { 0 };
	int edge_position_left, edge_position_right;

	if (!info) {
		printk(KERN_ERR "%s: No platform data found\n",
				__func__);
		return -EINVAL;
	}

	if (!info->input_dev) {
		printk(KERN_ERR "%s: No input_dev data found\n",
				__func__);
		return -EINVAL;
	}
#ifdef CONFIG_SEC_FACTORY
	if ((lcdtype == S6E3HF2_WQXGA_ID1) || (lcdtype == S6E3HF2_WQXGA_ID2)) {
		edge_position_left = -1;
		edge_position_right = info->board->max_x + 1 - info->board->grip_area;
	} else {
		edge_position_left = info->board->grip_area;
		edge_position_right = info->board->max_x + 1 - info->board->grip_area;
	}
#else
		edge_position_left = info->board->grip_area;
		edge_position_right = info->board->max_x + 1 - info->board->grip_area;
#endif
	tsp_debug_info(true, &info->client->dev, "%s: %d,%d\n", __func__, edge_position_left, edge_position_right);
	snprintf(buff, sizeof(buff), "%d,%d", edge_position_left, edge_position_right);

	return snprintf(buf, TSP_BUF_SIZE, "%s\n", buff);
}

static void clear_cover_cmd_work(struct work_struct *work)
{
	struct fts_ts_info *info = container_of(work, struct fts_ts_info,
						cover_cmd_work.work);

	if (info->cmd_is_running) {
		schedule_delayed_work(&info->cover_cmd_work, msecs_to_jiffies(5));
	} else {
		/* check lock   */
		mutex_lock(&info->cmd_lock);
		info->cmd_is_running = true;
		mutex_unlock(&info->cmd_lock);

		info->cmd_state = CMD_STATUS_RUNNING;
		tsp_debug_err(true, &info->client->dev,
			"%s param = %d, %d\n", __func__,
			info->delayed_cmd_param[0], info->delayed_cmd_param[1]);

		info->cmd_param[0] = info->delayed_cmd_param[0];
		if (info->delayed_cmd_param[0] > 1)
			info->cmd_param[1] = info->delayed_cmd_param[1];
		strcpy(info->cmd, "clear_cover_mode");
		clear_cover_mode(info);
	}
}

static ssize_t store_cmd(struct device *dev, struct device_attribute *devattr,
			   const char *buf, size_t count)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
	char *cur, *start, *end;
	char buff[CMD_STR_LEN] = { 0 };
	int len, i;
	struct ft_cmd *ft_cmd_ptr = NULL;
	char delim = ',';
	bool cmd_found = false;
	int param_cnt = 0;

	if (!info) {
		printk(KERN_ERR "%s: No platform data found\n",
				__func__);
		return -EINVAL;
	}

	if (!info->input_dev) {
		printk(KERN_ERR "%s: No input_dev data found\n",
				__func__);
		return -EINVAL;
	}

	if (strlen(buf) >= CMD_STR_LEN) {
		pr_err("%s: cmd length(strlen(buf)) is over (%d,%s)!!\n",
				__func__, (int)strlen(buf), buf);
		return -EINVAL;
	}

	if (count >= (unsigned int)CMD_STR_LEN) {
		pr_err("%s: cmd length(count) is over (%d,%s)!!\n",
				__func__, (unsigned int)count, buf);
		return -EINVAL;
	}

	if (info->cmd_is_running == true) {
		tsp_debug_err(true, &info->client->dev, "ft_cmd: other cmd is running.\n");
		if (strncmp("clear_cover_mode", buf, 16) == 0) {
			cancel_delayed_work(&info->cover_cmd_work);
			tsp_debug_err(true, &info->client->dev,
				"[cmd is delayed] %d, param = %d, %d\n", __LINE__, buf[17]-'0', buf[19]-'0');
			info->delayed_cmd_param[0] = buf[17]-'0';
			if (info->delayed_cmd_param[0] > 1)
				info->delayed_cmd_param[1] = buf[19]-'0';

			schedule_delayed_work(&info->cover_cmd_work, msecs_to_jiffies(10));
		}
		return -EBUSY;
	}
	else if (info->reinit_done == false) {
		tsp_debug_err(true, &info->client->dev, "ft_cmd: reinit is working\n");
		if (strncmp("clear_cover_mode", buf, 16) == 0) {
			cancel_delayed_work(&info->cover_cmd_work);
			tsp_debug_err(true, &info->client->dev,
				"[cmd is delayed] %d, param = %d, %d\n", __LINE__, buf[17]-'0', buf[19]-'0');
			info->delayed_cmd_param[0] = buf[17]-'0';
			if (info->delayed_cmd_param[0] > 1)
				info->delayed_cmd_param[1] = buf[19]-'0';

			if(info->delayed_cmd_param[0] == 0) schedule_delayed_work(&info->cover_cmd_work, msecs_to_jiffies(300));
		}
	}

	/* check lock   */
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = true;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = 1;
	memset(info->cmd_param, 0x00, ARRAY_SIZE(info->cmd_param));

	len = (int)count;
	if (*(buf + len - 1) == '\n')
		len--;
	memset(info->cmd, 0x00, ARRAY_SIZE(info->cmd));
	memcpy(info->cmd, buf, len);
	cur = strchr(buf, (int)delim);
	if (cur)
		memcpy(buff, buf, cur - buf);

	else
		memcpy(buff, buf, len);
	tsp_debug_info(true, &info->client->dev, "COMMAND : %s\n", buff);

	/* find command */
	list_for_each_entry(ft_cmd_ptr, &info->cmd_list_head, list) {
		if (!strncmp(buff, ft_cmd_ptr->cmd_name, CMD_STR_LEN)) {
			cmd_found = true;
			break;
		}
	}

	/* set not_support_cmd */
	if (!cmd_found) {
		list_for_each_entry(ft_cmd_ptr, &info->cmd_list_head, list) {
			if (!strncmp
			 ("not_support_cmd", ft_cmd_ptr->cmd_name,
			  CMD_STR_LEN))
				break;
		}
	}

	/* parsing parameters */
	if (cur && cmd_found) {
		cur++;
		start = cur;
		memset(buff, 0x00, ARRAY_SIZE(buff));

		do {
			if (*cur == delim || cur - buf == len) {
				end = cur;
				memcpy(buff, start, end - start);
				*(buff + strnlen(buff, ARRAY_SIZE(buff))) =
				'\0';
				if (kstrtoint
				 (buff, 10,
				  info->cmd_param + param_cnt) < 0)
					goto err_out;
				start = cur + 1;
				memset(buff, 0x00, ARRAY_SIZE(buff));
				param_cnt++;
			}
			cur++;
		} while ((cur - buf <= len) && (param_cnt <  CMD_PARAM_NUM));
	}
	tsp_debug_info(true, &info->client->dev, "cmd = %s\n", ft_cmd_ptr->cmd_name);
	for (i = 0; i < param_cnt; i++)
		tsp_debug_info(true, &info->client->dev, "cmd param %d= %d\n", i,
			  info->cmd_param[i]);

#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
	if (TRUSTEDUI_MODE_INPUT_SECURED & trustedui_get_current_mode())
		tui_mode_cmd(info);
	else
#endif
	ft_cmd_ptr->cmd_func(info);

err_out:
	return count;
}

static ssize_t show_cmd_status(struct device *dev,
				 struct device_attribute *devattr, char *buf)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
	char buff[16] = { 0 };

	if (!info) {
		printk(KERN_ERR "%s: No platform data found\n",
				__func__);
		return -EINVAL;
	}

	if (!info->input_dev) {
		printk(KERN_ERR "%s: No input_dev data found\n",
				__func__);
		return -EINVAL;
	}

	tsp_debug_info(true, &info->client->dev, "tsp cmd: status:%d\n", info->cmd_state);
	if (info->cmd_state == CMD_STATUS_WAITING)
		snprintf(buff, sizeof(buff), "WAITING");

	else if (info->cmd_state == CMD_STATUS_RUNNING)
		snprintf(buff, sizeof(buff), "RUNNING");

	else if (info->cmd_state == CMD_STATUS_OK)
		snprintf(buff, sizeof(buff), "OK");

	else if (info->cmd_state == CMD_STATUS_FAIL)
		snprintf(buff, sizeof(buff), "FAIL");

	else if (info->cmd_state == CMD_STATUS_NOT_APPLICABLE)
		snprintf(buff, sizeof(buff), "NOT_APPLICABLE");
	return snprintf(buf, TSP_BUF_SIZE, "%s\n", buff);
}

static ssize_t show_cmd_result(struct device *dev,
				 struct device_attribute *devattr, char *buf)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);

	if (!info) {
		printk(KERN_ERR "%s: No platform data found\n",
				__func__);
		return -EINVAL;
	}

	if (!info->input_dev) {
		printk(KERN_ERR "%s: No input_dev data found\n",
				__func__);
		return -EINVAL;
	}

	tsp_debug_info(true, &info->client->dev, "tsp cmd: result: %s\n",
		   info->cmd_result);
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = 0;
	return snprintf(buf, TSP_BUF_SIZE, "%s\n", info->cmd_result);
}

static ssize_t cmd_list_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
	int ii = 0;
	char buffer[info->cmd_buffer_size+CMD_STR_LEN];
	char buffer_name[CMD_STR_LEN];

	snprintf(buffer, CMD_STR_LEN, "++factory command list++\n");
	while (strncmp(ft_commands[ii].cmd_name, "not_support_cmd", 16) != 0) {
		snprintf(buffer_name, CMD_STR_LEN, "%s\n", ft_commands[ii].cmd_name);
		strcat(buffer, buffer_name);
		ii++;
	}

	tsp_debug_info(true, &info->client->dev,
		"%s: length : %u / %d\n", __func__,
		(unsigned int)strlen(buffer), info->cmd_buffer_size+CMD_STR_LEN);

	return snprintf(buf, TSP_BUF_SIZE, "%s\n", buffer);
}

static void set_default_result(struct fts_ts_info *info)
{
	char delim = ':';
	memset(info->cmd_result, 0x00, ARRAY_SIZE(info->cmd_result));
	memcpy(info->cmd_result, info->cmd, strnlen(info->cmd, CMD_STR_LEN));
	strncat(info->cmd_result, &delim, 1);
}

static void set_cmd_result(struct fts_ts_info *info, char *buff, int len)
{
	strncat(info->cmd_result, buff, len);
}

#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
static void tui_mode_cmd(struct fts_ts_info *info)
{
	char buff[16] = "TUImode:FAIL";
	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
static void set_wirelesscharger_mode(void *device_data);
static void set_grip_data(void *device_data);
static void set_dead_zone(void *device_data);
static void dead_zone_enable(void *device_data);
static void drawing_test_enable(void *device_data);
static void spay_enable(void *device_data);
static void aod_enable(void *device_data);
static void set_aod_rect(void *device_data);
static void get_aod_rect(void *device_data);
static void dex_enable(void *device_data);
static void brush_enable(void *device_data);
static void set_touchable_area(void *device_data);
static void delay(void *device_data);
static void debug(void *device_data);

static void run_force_calibration(void *device_data);

static void not_support_cmd(void *device_data);

static ssize_t fts_scrub_position(struct device *dev,
				struct device_attribute *attr, char *buf);

#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
extern int tui_force_close(uint32_t arg);
extern void tui_cover_mode_set(bool arg);
#endif

struct sec_cmd ft_commands[] = {
	{SEC_CMD("fw_update", fw_update),},
	{SEC_CMD("get_fw_ver_bin", get_fw_ver_bin),},
	{SEC_CMD("get_fw_ver_ic", get_fw_ver_ic),},
	{SEC_CMD("get_config_ver", get_config_ver),},
	{SEC_CMD("get_threshold", get_threshold),},
	{SEC_CMD("module_off_master", module_off_master),},
	{SEC_CMD("module_on_master", module_on_master),},
	{SEC_CMD("module_off_slave", not_support_cmd),},
	{SEC_CMD("module_on_slave", not_support_cmd),},
	{SEC_CMD("get_chip_vendor", get_chip_vendor),},
	{SEC_CMD("get_chip_name", get_chip_name),},
	{SEC_CMD("get_mis_cal_info", get_mis_cal_info),},
	{SEC_CMD("get_wet_mode", get_wet_mode),},
	{SEC_CMD("get_module_vendor", not_support_cmd),},
	{SEC_CMD("get_x_num", get_x_num),},
	{SEC_CMD("get_y_num", get_y_num),},
	{SEC_CMD("get_checksum_data", get_checksum_data),},
	{SEC_CMD("run_reference_read", run_reference_read),},
	{SEC_CMD("get_reference", get_reference),},
	{SEC_CMD("run_rawcap_read", run_rawcap_read),},
	{SEC_CMD("get_rawcap", get_rawcap),},
	{SEC_CMD("run_delta_read", run_delta_read),},
	{SEC_CMD("get_delta", get_delta),},
	{SEC_CMD("get_pat_information", get_pat_information),},
	{SEC_CMD("set_external_factory", set_external_factory),},
#ifdef FTS_SUPPORT_HOVER
	{SEC_CMD("run_abscap_read" , run_abscap_read),},
	{SEC_CMD("run_absdelta_read", run_absdelta_read),},
#endif
	{SEC_CMD("run_ix_data_read", run_ix_data_read),},
	{SEC_CMD("run_ix_data_read_all", run_ix_data_read_all),},
	{SEC_CMD("run_self_raw_read", run_self_raw_read),},
	{SEC_CMD("run_self_raw_read_all", run_self_raw_read_all),},
	{SEC_CMD("run_wtr_cx_data_read", run_wtr_cx_data_read),},
	{SEC_CMD("run_wtr_cx_data_read_all", run_wtr_cx_data_read_all),},
	{SEC_CMD("run_trx_short_test", run_trx_short_test),},
	{SEC_CMD("get_cx_data", get_cx_data),},
	{SEC_CMD("run_cx_data_read", run_cx_data_read),},
	{SEC_CMD("get_cx_all_data", get_cx_all_data),},
	{SEC_CMD("get_strength_all_data", get_strength_all_data),},
#ifdef FTS_SUPPORT_TOUCH_KEY
	{SEC_CMD("run_key_cx_data_read", run_key_cx_data_read),},
#endif
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	{SEC_CMD("run_force_pressure_calibration", run_force_pressure_calibration),},
	{SEC_CMD("set_pressure_test_mode", set_pressure_test_mode),},
	{SEC_CMD("run_pressure_strength_read_all", run_pressure_strength_read_all),},
	{SEC_CMD("run_pressure_rawdata_read_all", run_pressure_rawdata_read_all),},
	{SEC_CMD("run_pressure_ix_data_read_all", run_pressure_ix_data_read_all),},
	{SEC_CMD("set_pressure_strength", set_pressure_strength),},
	{SEC_CMD("set_pressure_rawdata", set_pressure_rawdata),},
	{SEC_CMD("set_pressure_data_index", set_pressure_data_index),},
	{SEC_CMD("get_pressure_strength", get_pressure_strength),},
	{SEC_CMD("get_pressure_rawdata", get_pressure_rawdata),},
	{SEC_CMD("get_pressure_data_index", get_pressure_data_index),},
	{SEC_CMD("set_pressure_strength_clear", set_pressure_strength_clear),},
	{SEC_CMD("get_pressure_threshold", get_pressure_threshold),},
	{SEC_CMD("set_pressure_user_level", set_pressure_user_level),},
	{SEC_CMD("get_pressure_user_level", get_pressure_user_level),},
#endif
	{SEC_CMD("set_tsp_test_result", set_tsp_test_result),},
	{SEC_CMD("get_tsp_test_result", get_tsp_test_result),},
	{SEC_CMD("increase_disassemble_count", increase_disassemble_count),},
	{SEC_CMD("get_disassemble_count", get_disassemble_count),},
#ifdef FTS_SUPPORT_HOVER
	{SEC_CMD("hover_enable", hover_enable),},
#endif
#ifdef CONFIG_GLOVE_TOUCH
	{SEC_CMD("glove_mode", glove_mode),},
	{SEC_CMD("get_glove_sensitivity", get_glove_sensitivity),},
	{SEC_CMD("fast_glove_mode", fast_glove_mode),},
#endif
	{SEC_CMD("clear_cover_mode", clear_cover_mode),},
	{SEC_CMD("report_rate", report_rate),},
#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
	{SEC_CMD("interrupt_control", interrupt_control),},
#endif
	{SEC_CMD("set_wirelesscharger_mode", set_wirelesscharger_mode),},
	{SEC_CMD("set_grip_data", set_grip_data),},
	{SEC_CMD("set_dead_zone", set_dead_zone),},
	{SEC_CMD("dead_zone_enable", dead_zone_enable),},
	{SEC_CMD("drawing_test_enable", drawing_test_enable),},
	{SEC_CMD("spay_enable", spay_enable),},
	{SEC_CMD("aod_enable", aod_enable),},
	{SEC_CMD("set_aod_rect", set_aod_rect),},
	{SEC_CMD("get_aod_rect", get_aod_rect),},
	{SEC_CMD("dex_enable", dex_enable),},
	{SEC_CMD("brush_enable", brush_enable),},
	{SEC_CMD("set_touchable_area", set_touchable_area),},
	{SEC_CMD("delay", delay),},
	{SEC_CMD("debug", debug),},
	{SEC_CMD("run_force_calibration", run_force_calibration),},
	{SEC_CMD("not_support_cmd", not_support_cmd),},
};

static ssize_t read_ito_check_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: %02X%02X%02X%02X\n", __func__,
		info->ito_test[0], info->ito_test[1],
		info->ito_test[2], info->ito_test[3]);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%02X%02X%02X%02X",
		info->ito_test[0], info->ito_test[1],
		info->ito_test[2], info->ito_test[3]);
}

static ssize_t read_raw_check_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	int ii, ret = 0;
	char *buffer = NULL;
	char temp[10] = { 0 };

	buffer = kzalloc(info->SenseChannelLength * info->ForceChannelLength * 6, GFP_KERNEL);
	if (!buffer)
		return -ENOMEM;

	for (ii = 0; ii < (info->SenseChannelLength * info->ForceChannelLength - 1); ii++) {
		snprintf(temp, 6, "%d ", info->pFrame[ii]);
		strncat(buffer, temp, 6);

		memset(temp, 0x00, 10);
	}

	snprintf(temp, 6, "%d", info->pFrame[ii]);
	strncat(buffer, temp, 6);

	ret = snprintf(buf, info->SenseChannelLength * info->ForceChannelLength * 6, buffer);
	kfree(buffer);

	return ret;
}

static ssize_t read_multi_count_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: %d\n", __func__, info->multi_count);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%d", info->multi_count);
}

static ssize_t clear_multi_count_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->multi_count = 0;
	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t read_wet_mode_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: %d\n", __func__, info->wet_count);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%d", info->wet_count);
}


static ssize_t clear_wet_mode_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->wet_count = 0;
	info->dive_count= 0;

	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t read_comm_err_count_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: %d\n", __func__, info->comm_err_count);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%d", info->comm_err_count);
}


static ssize_t clear_comm_err_count_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->comm_err_count = 0;

	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t read_module_id_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "ST%02X%04X%02X%02X%02X%02X",
		info->panel_revision, info->fw_main_version_of_ic,
		info->test_result.data[0], info->cal_count, info->pressure_cal_base, info->pressure_cal_delta);
}

static ssize_t read_vendor_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	unsigned char buffer[10] = { 0 };

	snprintf(buffer, 9, info->board->firmware_name + 8);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "STM_%s", buffer);
}

static ssize_t read_checksum_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: crc fail count in NV: %d\n", __func__, info->nv_crc_fail_count);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%d", info->nv_crc_fail_count);
}


static ssize_t clear_checksum_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

//	info->checksum_result = 0;

	input_info(true, &info->client->dev, "%s:nothing\n", __func__);

	return count;
}

static ssize_t clear_holding_time_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->time_longest = 0;

	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t read_holding_time_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: %ld\n", __func__,
		info->time_longest);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%ld", info->time_longest);
}

static ssize_t read_all_touch_count_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: touch:%d, force:%d, aod:%d, spay:%d\n", __func__,
			info->all_finger_count, info->all_force_count,
			info->all_aod_tap_count, info->all_spay_count);

	return snprintf(buf, SEC_CMD_BUF_SIZE,
			"\"TTCN\":\"%d\",\"TFCN\":\"%d\",\"TACN\":\"%d\",\"TSCN\":\"%d\"",
			info->all_finger_count, info->all_force_count,
			info->all_aod_tap_count, info->all_spay_count);
}

static ssize_t clear_all_touch_count_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->all_force_count = 0;
	info->all_aod_tap_count = 0;
	info->all_spay_count = 0;

	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t read_z_value_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	input_info(true, &info->client->dev, "%s: max:%d, min:%d, sum:%d\n", __func__,
			info->max_z_value, info->min_z_value,
			info->sum_z_value);

	if (info->all_finger_count > 0)
		return snprintf(buf, SEC_CMD_BUF_SIZE,
				"\"TMXZ\":\"%d\",\"TMNZ\":\"%d\",\"TAVZ\":\"%d\"",
				info->max_z_value, info->min_z_value,
				info->sum_z_value / info->all_finger_count);
	else
		return snprintf(buf, SEC_CMD_BUF_SIZE,
				"\"TMXZ\":\"%d\",\"TMNZ\":\"%d\"",
				info->max_z_value, info->min_z_value);

}

static ssize_t clear_z_value_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	info->max_z_value= 0;
	info->min_z_value= 0xFFFFFFFF;
	info->sum_z_value= 0;
	info->all_finger_count = 0;

	input_info(true, &info->client->dev, "%s: clear\n", __func__);

	return count;
}

static ssize_t pressure_enable_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[256] = { 0 };

	if (info->lowpower_flag & FTS_MODE_PRESSURE)
		snprintf(buff, sizeof(buff), "1");
	else
		snprintf(buff, sizeof(buff), "0");

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%s\n", buff);
}

static ssize_t pressure_enable_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	int ret;
	unsigned long value = 0;
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS;
#endif

	if (count > 2)
		return -EINVAL;

	ret = kstrtoul(buf, 10, &value);
	if (ret != 0)
		return ret;

	if (value == 1) {
		info->lowpower_flag |= FTS_MODE_PRESSURE;
	} else {
		info->lowpower_flag &= ~FTS_MODE_PRESSURE;
	}

#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, &info->lowpower_flag, sizeof(info->lowpower_flag));
	if (ret < 0)
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
#endif

	input_info(true, &info->client->dev, "%s: %d\n", __func__, value);
	return count;
}

static DEVICE_ATTR(ito_check, S_IRUGO, read_ito_check_show, NULL);
static DEVICE_ATTR(raw_check, S_IRUGO, read_raw_check_show, NULL);
static DEVICE_ATTR(multi_count, S_IRUGO | S_IWUSR | S_IWGRP, read_multi_count_show, clear_multi_count_store);
static DEVICE_ATTR(wet_mode, S_IRUGO | S_IWUSR | S_IWGRP, read_wet_mode_show, clear_wet_mode_store);
static DEVICE_ATTR(comm_err_count, S_IRUGO | S_IWUSR | S_IWGRP, read_comm_err_count_show, clear_comm_err_count_store);
static DEVICE_ATTR(module_id, S_IRUGO, read_module_id_show, NULL);
static DEVICE_ATTR(vendor, S_IRUGO, read_vendor_show, NULL);
static DEVICE_ATTR(checksum, S_IRUGO | S_IWUSR | S_IWGRP, read_checksum_show, clear_checksum_store);
static DEVICE_ATTR(holding_time, S_IRUGO | S_IWUSR | S_IWGRP, read_holding_time_show, clear_holding_time_store);
static DEVICE_ATTR(all_touch_count, S_IRUGO | S_IWUSR | S_IWGRP, read_all_touch_count_show, clear_all_touch_count_store);
static DEVICE_ATTR(z_value, S_IRUGO | S_IWUSR | S_IWGRP, read_z_value_show, clear_z_value_store);
static DEVICE_ATTR(scrub_pos, S_IRUGO, fts_scrub_position, NULL);
static DEVICE_ATTR(pressure_enable, S_IRUGO | S_IWUSR | S_IWGRP, pressure_enable_show, pressure_enable_store);

static struct attribute *sec_touch_facotry_attributes[] = {
	&dev_attr_scrub_pos.attr,
	&dev_attr_ito_check.attr,
	&dev_attr_raw_check.attr,
	&dev_attr_multi_count.attr,
	&dev_attr_wet_mode.attr,
	&dev_attr_comm_err_count.attr,
	&dev_attr_module_id.attr,
	&dev_attr_vendor.attr,
	&dev_attr_checksum.attr,
	&dev_attr_holding_time.attr,
	&dev_attr_all_touch_count.attr,
	&dev_attr_z_value.attr,
	&dev_attr_pressure_enable.attr,
	NULL,
};

static struct attribute_group sec_touch_factory_attr_group = {
	.attrs = sec_touch_facotry_attributes,
};

static int fts_check_index(struct fts_ts_info *info)
{
	struct sec_cmd_data *sec = &info->sec;
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int node;

	if (sec->cmd_param[0] < 0
		|| sec->cmd_param[0] >= info->SenseChannelLength
		|| sec->cmd_param[1] < 0
		|| sec->cmd_param[1] >= info->ForceChannelLength) {

		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_err(true, &info->client->dev, "%s: parameter error: %u,%u\n",
			   __func__, sec->cmd_param[0], sec->cmd_param[1]);
		node = -1;
		return node;
	}
	node = sec->cmd_param[1] * info->SenseChannelLength + sec->cmd_param[0];
	/* input_info(true, &info->client->dev, "%s: node = %d\n", __func__, node); */
	return node;
}

static ssize_t fts_scrub_position(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct sec_cmd_data *sec = dev_get_drvdata(dev);
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	input_info(true, &info->client->dev, "%s: %d %d %d\n",
				__func__, info->scrub_id, info->scrub_x, info->scrub_y);
	snprintf(buff, sizeof(buff), "%d %d %d", info->scrub_id, info->scrub_x, info->scrub_y);

	info->scrub_x = 0;
	info->scrub_y = 0;

	return snprintf(buf, SEC_CMD_BUF_SIZE, "%s\n", buff);
}

#if 0 //def CONFIG_TRUSTONIC_TRUSTED_UI
static void tui_mode_cmd(struct fts_ts_info *info)
{
	struct sec_cmd_data *sec = &info->sec;
	char buff[16] = "TUImode:FAIL";

	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}
#endif

static void not_support_cmd(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };
	set_default_result(info);
	snprintf(buff, sizeof(buff), "%s", "NA");
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
	tsp_debug_info(true, &info->client->dev, "%s: \"%s\"\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	sec_cmd_set_default_result(sec);
	snprintf(buff, sizeof(buff), "%s", "NA");
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void fw_update(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[64] = { 0 };
	int retval = 0;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	retval = fts_fw_update_on_hidden_menu(info, info->cmd_param[0]);

	if (retval < 0) {
		sprintf(buff, "%s", "NA");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_FAIL;
		tsp_debug_info(true, &info->client->dev, "%s: failed [%d]\n", __func__, retval);
	} else {
		sprintf(buff, "%s", "OK");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_OK;
		tsp_debug_info(true, &info->client->dev, "%s: success [%d]\n", __func__, retval);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[64] = { 0 };
	int retval = 0;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	retval = fts_fw_update_on_hidden_menu(info, sec->cmd_param[0]);

	if (retval < 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_err(true, &info->client->dev, "%s: failed [%d]\n", __func__, retval);
	} else {
		snprintf(buff, sizeof(buff), "%s", "OK");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_OK;
		input_info(true, &info->client->dev, "%s: success [%d]\n", __func__, retval);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	return;
}

<<<<<<< HEAD
static int fts_get_channel_info(struct fts_ts_info *info)
{
	int rc;
	unsigned char cmd[4] =
		{ 0xB2, 0x00, 0x14, 0x02 };
	unsigned char data[FTS_EVENT_SIZE];
	int retry = 0;

	memset(data, 0x0, FTS_EVENT_SIZE);

	rc = -1;
	fts_write_reg(info, &cmd[0], 4);
	cmd[0]=READ_ONE_EVENT;
	while (fts_read_reg
	       (info, &cmd[0], 1, (unsigned char *)data, FTS_EVENT_SIZE)) {

		if (data[0] == EVENTID_RESULT_READ_REGISTER) {
			if ((data[1] == cmd[1]) && (data[2] == cmd[2]))
			{
				info->SenseChannelLength = data[3];
				info->ForceChannelLength = data[4];

				rc = 0;
				break;
			}
		}

		if (retry++ > 30) {
			rc = -1;
			tsp_debug_info(true, &info->client->dev, "Time over - wait for channel info\n");
			break;
		}
		mdelay(5);
	}
=======
static int fts_get_channel_info(struct fts_ts_info *info)   // Need to change function for sysinfo
{
	int rc = -1;
	unsigned char data[FTS_EVENT_SIZE] = { 0 };

	memset(data, 0x0, FTS_EVENT_SIZE);

	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, FLUSHBUFFER);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	// Read Sense Channel
	rc = info->fts_get_sysinfo_data(info, FTS_SI_SENSE_CH_LENGTH, 3, data);
	if (rc <= 0) {
		info->SenseChannelLength = 0;
		input_err(true, info->dev, "%s: Get channel info Read Fail!! [Data : %2X]\n", __func__, data[0]);
		return rc;
	}
	info->SenseChannelLength = data[0];

	// Read Force Channel
	rc = info->fts_get_sysinfo_data(info, FTS_SI_FORCE_CH_LENGTH, 3, data);
	if (rc <= 0) {
		info->ForceChannelLength = 0;
		input_err(true, info->dev, "%s: Get channel info Read Fail!! [Data : %2X]\n", __func__, data[0]);
		return rc;
	}
	info->ForceChannelLength = data[0];

	fts_interrupt_set(info, INT_ENABLE);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return rc;
}

<<<<<<< HEAD
static void procedure_cmd_event(struct fts_ts_info *info, unsigned char *data)
{
	char buff[16] = { 0 };

	if ((data[1] == 0x00) && (data[2] == 0x62))
	{
		snprintf(buff, sizeof(buff), "%d",
					*(unsigned short *)&data[3]);
		tsp_debug_info(true, &info->client->dev, "%s: %s\n", "get_threshold", buff);
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_OK;

	}
	else if ((data[1] == 0x01) && (data[2] == 0xC6))
	{
		snprintf(buff, sizeof(buff), "%d",
					*(unsigned short *)&data[3]);
		tsp_debug_info(true, &info->client->dev, "%s: %s\n", "get_glove_sensitivity", buff);
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_OK;

	}
	else if ((data[1] == 0x07) && (data[2] == 0xE7))
	{
		if (data[3] <= TSP_FACTEST_RESULT_PASS) {
			sprintf(buff, "%s",
					data[3] == TSP_FACTEST_RESULT_PASS ? "PASS" :
					data[3] == TSP_FACTEST_RESULT_FAIL ? "FAIL" : "NONE");
			tsp_debug_info(true, &info->client->dev, "%s: success [%s][%d]", "get_tsp_test_result",
                                        data[3] == TSP_FACTEST_RESULT_PASS ? "PASS" :
                                        data[3] == TSP_FACTEST_RESULT_FAIL ? "FAIL" :
                                        "NONE", data[3]);
			set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
			info->cmd_state = CMD_STATUS_OK;
		}
		else
		{
			snprintf(buff, sizeof(buff), "%s", "NG");
			set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
			info->cmd_state = CMD_STATUS_FAIL;
			tsp_debug_info(true, &info->client->dev, "%s: %s\n",
							"get_tsp_test_result",
							buff);
		}

	}
}

void fts_print_frame(struct fts_ts_info *info, short *min, short *max)
=======
void fts_print_frame(struct fts_ts_info *info, short *min, short *max)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
{
	int i = 0;
	int j = 0;
	unsigned char *pStr = NULL;
	unsigned char pTmp[16] = { 0 };

	pStr = kzalloc(6 * (info->SenseChannelLength + 1), GFP_KERNEL);
	if (pStr == NULL) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "FTS pStr kzalloc failed\n");
		return;
	}

	memset(pStr, 0x0, 6 * (info->SenseChannelLength + 1));
	snprintf(pTmp, sizeof(pTmp), "    ");
	strncat(pStr, pTmp, 6 * info->SenseChannelLength);

	for (i = 0; i < info->SenseChannelLength; i++) {
		snprintf(pTmp, sizeof(pTmp), "Rx%02d  ", i);
		strncat(pStr, pTmp, 6 * info->SenseChannelLength);
	}

	tsp_debug_info(true, &info->client->dev, "FTS %s\n", pStr);
	memset(pStr, 0x0, 6 * (info->SenseChannelLength + 1));
	snprintf(pTmp, sizeof(pTmp), " +");
	strncat(pStr, pTmp, 6 * info->SenseChannelLength);

	for (i = 0; i < info->SenseChannelLength; i++) {
		snprintf(pTmp, sizeof(pTmp), "------");
		strncat(pStr, pTmp, 6 * info->SenseChannelLength);
	}

	tsp_debug_info(true, &info->client->dev, "FTS %s\n", pStr);

	for (i = 0; i < info->ForceChannelLength; i++) {
		memset(pStr, 0x0, 6 * (info->SenseChannelLength + 1));
		snprintf(pTmp, sizeof(pTmp), "Tx%02d | ", i);
		strncat(pStr, pTmp, 6 * info->SenseChannelLength);

		for (j = 0; j < info->SenseChannelLength; j++) {
			snprintf(pTmp, sizeof(pTmp), "%5d ", info->pFrame[(i * info->SenseChannelLength) + j]);
=======
		input_err(true, &info->client->dev, "%s: pStr kzalloc failed\n", __func__);
		return;
	}

	snprintf(pTmp, 4, "    ");
	strncat(pStr, pTmp, 4);


	for (i = 0; i < info->SenseChannelLength; i++) {
		snprintf(pTmp, 6, "Rx%02d  ", i);
		strncat(pStr, pTmp, 6);
	}

	input_raw_info(true, &info->client->dev, "%s\n", pStr);

	memset(pStr, 0x0, 6 * (info->SenseChannelLength + 1));
	snprintf(pTmp, 2, " +");
	strncat(pStr, pTmp, 2);

	for (i = 0; i < info->SenseChannelLength; i++) {
		snprintf(pTmp, 6, "------");
		strncat(pStr, pTmp, 6);

	}

	input_raw_info(true, &info->client->dev, "%s\n", pStr);

	for (i = 0; i < info->ForceChannelLength; i++) {
		memset(pStr, 0x0, 6 * (info->SenseChannelLength + 1));
		snprintf(pTmp, 7, "Tx%02d | ", i);
		strncat(pStr, pTmp, 7);


		for (j = 0; j < info->SenseChannelLength; j++) {
			snprintf(pTmp, 6, "%5d ", info->pFrame[(i * info->SenseChannelLength) + j]);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

			if (i > 0) {
				if (info->pFrame[(i * info->SenseChannelLength) + j] < *min)
					*min = info->pFrame[(i * info->SenseChannelLength) + j];

				if (info->pFrame[(i * info->SenseChannelLength) + j] > *max)
					*max = info->pFrame[(i * info->SenseChannelLength) + j];
			}
<<<<<<< HEAD
			strncat(pStr, pTmp, 6 * info->SenseChannelLength);
		}
		tsp_debug_info(true, &info->client->dev, "FTS %s\n", pStr);
=======
			strncat(pStr, pTmp, 6);
		}
		input_raw_info(true, &info->client->dev, "%s\n", pStr);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	kfree(pStr);
}

int fts_read_frame(struct fts_ts_info *info, unsigned char type, short *min,
		 short *max)
{
	unsigned char pFrameAddress[8] =
	{ 0xD0, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00 };
	unsigned int FrameAddress = 0;
	unsigned int writeAddr = 0;
	unsigned int start_addr = 0;
	unsigned int end_addr = 0;
	unsigned int totalbytes = 0;
	unsigned int remained = 0;
	unsigned int readbytes = 0xFF;
	unsigned int dataposition = 0;
	unsigned char *pRead = NULL;
	int rc = 0;
	int ret = 0;
	int i = 0;
<<<<<<< HEAD
	pRead = kzalloc(BUFFER_MAX, GFP_KERNEL);

	if (pRead == NULL) {
		tsp_debug_info(true, &info->client->dev, "FTS pRead kzalloc failed\n");
=======

	pRead = kzalloc(BUFFER_MAX, GFP_KERNEL);
	if (pRead == NULL) {
		input_err(true, &info->client->dev, "%s: pRead kzalloc failed\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		rc = 1;
		goto ErrorExit;
	}

	pFrameAddress[2] = type;
	totalbytes = info->SenseChannelLength * info->ForceChannelLength * 2;
	ret = fts_read_reg(info, &pFrameAddress[0], 3, pRead, pFrameAddress[3]);

	if (ret >= 0) {
<<<<<<< HEAD
		if (info->digital_rev == FTS_DIGITAL_REV_1)
			FrameAddress = pRead[0] + (pRead[1] << 8);
		else if (info->digital_rev == FTS_DIGITAL_REV_2)
			FrameAddress = pRead[1] + (pRead[2] << 8);
=======
		FrameAddress = pRead[1] + (pRead[2] << 8);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

		start_addr = FrameAddress+info->SenseChannelLength * 2;
		end_addr = start_addr + totalbytes;
	} else {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "FTS read failed rc = %d \n", ret);
=======
		input_err(true, &info->client->dev, "%s: read failed rc = %d\n", __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		rc = 2;
		goto ErrorExit;
	}

#ifdef DEBUG_MSG
<<<<<<< HEAD
	tsp_debug_info(true, &info->client->dev, "FTS FrameAddress = %X \n", FrameAddress);
	tsp_debug_info(true, &info->client->dev, "FTS start_addr = %X, end_addr = %X \n", start_addr, end_addr);
=======
	input_info(true, &info->client->dev, "%s: FrameAddress = %X\n", __func__, FrameAddress);
	input_info(true, &info->client->dev, "%s: start_addr = %X, end_addr = %X\n", __func__, start_addr, end_addr);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif

	remained = totalbytes;
	for (writeAddr = start_addr; writeAddr < end_addr; writeAddr += READ_CHUNK_SIZE) {
		pFrameAddress[1] = (writeAddr >> 8) & 0xFF;
		pFrameAddress[2] = writeAddr & 0xFF;

		if (remained >= READ_CHUNK_SIZE)
			readbytes = READ_CHUNK_SIZE;
		else
			readbytes = remained;

		memset(pRead, 0x0, readbytes);

#ifdef DEBUG_MSG
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "FTS %02X%02X%02X readbytes=%d\n",
=======
		input_info(true, &info->client->dev, "%s: %02X%02X%02X readbytes=%d\n", __func__,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			   pFrameAddress[0], pFrameAddress[1],
			   pFrameAddress[2], readbytes);

#endif
<<<<<<< HEAD
		if (info->digital_rev == FTS_DIGITAL_REV_1) {
			fts_read_reg(info, &pFrameAddress[0], 3, pRead, readbytes);
			remained -= readbytes;

			for (i = 0; i < readbytes; i += 2) {
				info->pFrame[dataposition++] =
				pRead[i] + (pRead[i + 1] << 8);
			}
		} else if (info->digital_rev == FTS_DIGITAL_REV_2) {
			fts_read_reg(info, &pFrameAddress[0], 3, pRead, readbytes + 1);
			remained -= readbytes;

			for (i = 1; i < (readbytes+1); i += 2) {
				info->pFrame[dataposition++] =
				pRead[i] + (pRead[i + 1] << 8);
			}
		}
=======

		fts_read_reg(info, &pFrameAddress[0], 3, pRead, readbytes + 1);
		remained -= readbytes;

		for (i = 1; i < (readbytes+1); i += 2) {
			info->pFrame[dataposition++] =
			pRead[i] + (pRead[i + 1] << 8);
		}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}
	kfree(pRead);

#ifdef DEBUG_MSG
<<<<<<< HEAD
	tsp_debug_info(true, &info->client->dev,
		   "FTS writeAddr = %X, start_addr = %X, end_addr = %X \n",
=======
	input_info(true, &info->client->dev,
		   "%s: writeAddr = %X, start_addr = %X, end_addr = %X\n", __func__,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		   writeAddr, start_addr, end_addr);
#endif

	switch (type) {
	case TYPE_RAW_DATA:
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "FTS [Raw Data : 0x%X%X] \n", pFrameAddress[0],
			FrameAddress);
		break;
	case TYPE_FILTERED_DATA:
		tsp_debug_info(true, &info->client->dev, "FTS [Filtered Data : 0x%X%X] \n",
			pFrameAddress[0], FrameAddress);
		break;
	case TYPE_STRENGTH_DATA:
		tsp_debug_info(true, &info->client->dev, "FTS [Strength Data : 0x%X%X] \n",
			pFrameAddress[0], FrameAddress);
		break;
	case TYPE_BASELINE_DATA:
		tsp_debug_info(true, &info->client->dev, "FTS [Baseline Data : 0x%X%X] \n",
=======
		input_raw_info(true, &info->client->dev, "%s: [Raw Data : 0x%X%X]\n", __func__, pFrameAddress[0],
			FrameAddress);
		break;
	case TYPE_FILTERED_DATA:
		input_raw_info(true, &info->client->dev, "%s: [Filtered Data : 0x%X%X]\n", __func__,
			pFrameAddress[0], FrameAddress);
		break;
	case TYPE_STRENGTH_DATA:
		input_raw_info(true, &info->client->dev, "%s: [Strength Data : 0x%X%X]\n", __func__,
			pFrameAddress[0], FrameAddress);
		break;
	case TYPE_BASELINE_DATA:
		input_raw_info(true, &info->client->dev, "%s: [Baseline Data : 0x%X%X]\n", __func__,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			pFrameAddress[0], FrameAddress);
		break;
	}
	fts_print_frame(info, min, max);

ErrorExit:
	return rc;
}

<<<<<<< HEAD
static int fts_panel_ito_test(struct fts_ts_info *info)
{
	unsigned char cmd = READ_ONE_EVENT;
	unsigned char data[FTS_EVENT_SIZE];
	unsigned char regAdd[4] = {0xB0, 0x03, 0x60, 0xFB};
	int retry = 0;
	int result = -1;

	fts_systemreset(info);
	fts_wait_for_ready(info);
	fts_command(info, SLEEPOUT);
	fts_delay(20);

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
	fts_write_reg(info, &regAdd[0], 4);
	fts_command(info, FLUSHBUFFER);
	fts_command(info, 0xA7);
	fts_delay(200);
	memset(data, 0x0, FTS_EVENT_SIZE);
	while (fts_read_reg
			(info, &cmd, 1, (unsigned char *)data, FTS_EVENT_SIZE)) {

		if ((data[0] == 0x0F) && (data[1] == 0x05)) {
=======
int fts_panel_ito_test(struct fts_ts_info *info)
{
	unsigned char cmd = READ_ONE_EVENT;
	unsigned char data[FTS_EVENT_SIZE];
	int retry = 0;
	int result = -1;

	fts_systemreset(info, 10);

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, FLUSHBUFFER);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	fts_command(info, 0xA7);    // ITO test command
	fts_delay(200);
	memset(data, 0x0, FTS_EVENT_SIZE);
	while (fts_read_reg(info, &cmd, 1, (unsigned char *)data, FTS_EVENT_SIZE)) {
		if ((data[0] == 0x0F) && (data[1] == 0x05)) {

			info->ito_test[0] = 0x0;
			info->ito_test[1] = 0x0;
			info->ito_test[2] = data[2];
			info->ito_test[3] = data[3];

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			switch (data[2]) {
			case 0x00 :
				result = 0;
				break;
			case 0x01 :
<<<<<<< HEAD
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Force channel [%d] open.\n",
					data[3]);
				break;
			case 0x02 :
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Sense channel [%d] open.\n",
					data[3]);
				break;
			case 0x03 :
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Force channel [%d] short to GND.\n",
					data[3]);
				break;
			case 0x04 :
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Sense channel [%d] short to GND.\n",
					data[3]);
				break;
			case 0x07 :
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Force channel [%d] short to force.\n",
					data[3]);
				break;
			case 0x0E :
				tsp_debug_info(true, &info->client->dev, "[FTS] ITO Test result : Sennse channel [%d] short to sense.\n",
=======
				input_info(true, &info->client->dev, "%s: Force channel [%d] open\n", __func__,
					data[3]);
				break;
			case 0x02 :
				input_info(true, &info->client->dev, "%s: Sense channel [%d] open\n", __func__,
					data[3]);
				break;
			case 0x03 :
				input_info(true, &info->client->dev, "%s: Force channel [%d] short to GND\n", __func__,
					data[3]);
				break;
			case 0x04 :
				input_info(true, &info->client->dev, "%s: Sense channel [%d] short to GND\n", __func__,
					data[3]);
				break;
			case 0x05 :
				input_info(true, &info->client->dev, "%s: Force channel [%d] short to VDD\n", __func__,
					data[3]);
				break;
			case 0x06 :
				input_info(true, &info->client->dev, "%s: Sense channel [%d] short to VDD\n", __func__,
					data[3]);
				break;
			case 0x07 :
				input_info(true, &info->client->dev, "%s: Force channel [%d] short to force\n", __func__,
					data[3]);
				break;
			case 0x08 :
				input_info(true, &info->client->dev, "%s: Sennse channel [%d] short to sense\n", __func__,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					data[3]);
				break;
			default:
				break;
			}

			break;
		}

		if (retry++ > 30) {
<<<<<<< HEAD
			tsp_debug_info(true, &info->client->dev, "Time over - wait for result of ITO test\n");
=======
			input_err(true, &info->client->dev, "%s: Time over - wait for result of ITO test\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			break;
		}
		fts_delay(10);
	}

<<<<<<< HEAD
	fts_systemreset(info);

	/* wait for ready event */
	fts_wait_for_ready(info);
=======
	fts_systemreset(info, 10);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifdef FTS_SUPPORT_NOISE_PARAM
	fts_set_noise_param(info);
#endif

<<<<<<< HEAD
	fts_command(info, SLEEPOUT);
	fts_command(info, SENSEON);

=======
	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif
<<<<<<< HEAD

	if (info->hover_enabled)
		fts_command(info, FTS_CMD_HOVER_ON);

	if (info->flip_enable) {
		fts_set_cover_type(info, true);
	} else {
		if (info->mshover_enabled)
			fts_command(info, FTS_CMD_MSHOVER_ON);
	}
=======
#ifdef FTS_SUPPORT_HOVER
	if (info->hover_enabled)
		fts_command(info, FTS_CMD_HOVER_ON);
#endif
	if (info->flip_enable) {
		fts_set_cover_type(info, true);
	}
#ifdef CONFIG_GLOVE_TOUCH
	else {
		if (info->glove_enabled)
			fts_command(info, FTS_CMD_GLOVE_ON);
	}
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TA_MODE
	if (info->TA_Pluged)
		fts_command(info, FTS_CMD_CHARGER_PLUGGED);
#endif

	info->touch_count = 0;

<<<<<<< HEAD
	fts_command(info, FLUSHBUFFER);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_interrupt_set(info, INT_ENABLE);
	enable_irq(info->irq);

	return result;
}

static void get_fw_ver_bin(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };
	set_default_result(info);

	if (strncmp(info->board->model_name, "G925", 4) == 0) {
		info->tspid_val= gpio_get_value(info->board->tspid);
		info->tspid2_val= gpio_get_value(info->board->tspid2);

		sprintf(buff, "ST%01X%01X%04X",
				info->tspid_val, info->tspid2_val,
				info->fw_main_version_of_bin);
	} else if (strncmp(info->board->model_name, "G920", 4) == 0) {
		sprintf(buff, "ST%02X%04X",
				info->panel_revision,
				info->fw_main_version_of_bin);
	} else {
		tsp_debug_info(true, &info->client->dev, "%s: Check model name[%s]!\n",
						__func__, info->board->model_name);
	}

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	sec_cmd_set_default_result(sec);

	snprintf(buff, sizeof(buff), "ST%02X%04X",
			info->panel_revision,
			info->fw_main_version_of_bin);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_fw_ver_ic(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };
	set_default_result(info);

	if (strncmp(info->board->model_name, "G925", 4) == 0) {
		info->tspid_val= gpio_get_value(info->board->tspid);
		info->tspid2_val= gpio_get_value(info->board->tspid2);

		sprintf(buff, "ST%01X%01X%04X",
				info->tspid_val, info->tspid2_val,
				info->fw_main_version_of_ic);
	} else if (strncmp(info->board->model_name, "G920", 4) == 0) {
		sprintf(buff, "ST%02X%04X",
				info->panel_revision,
				info->fw_main_version_of_ic);
	} else {
		tsp_debug_info(true, &info->client->dev, "%s: Check model name[%s]!\n",
						__func__, info->board->model_name);
	}

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
				__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);
	fts_get_version_info(info);
	enable_irq(info->irq);

	snprintf(buff, sizeof(buff), "ST%02X%04X",
			info->panel_revision,
			info->fw_main_version_of_ic);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_config_ver(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[20] = { 0 };

	snprintf(buff, sizeof(buff), "%s_ST_%04X",
		info->board->model_name ?: info->board->project_name ?: STM_DEVICE_NAME,
		info->config_version_of_ic);

	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[20] = { 0 };

	snprintf(buff, sizeof(buff), "%s_ST_%04X",
		info->board->model_name ?: info->board->project_name ?: "STM",
		info->config_version_of_ic);

	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_threshold(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned char cmd[4] =
		{ 0xB2, 0x00, 0x62, 0x02 };
	int timeout=0;

	set_default_result(info);

	if (info->touch_stopped) {
		char buff[CMD_STR_LEN] = { 0 };
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	fts_write_reg(info, &cmd[0], 4);
	info->cmd_state = CMD_STATUS_RUNNING;

	while (info->cmd_state == CMD_STATUS_RUNNING) {
		if (timeout++>30) {
			info->cmd_state = CMD_STATUS_FAIL;
			break;
		}
		msleep(10);
	}
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	unsigned char buff[16] = { 0 };
	unsigned char data[5] = { 0 };
	unsigned short finger_threshold = 0;
	int rc;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
				__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	sec->cmd_state = SEC_CMD_STATUS_RUNNING;
	rc = info->fts_get_sysinfo_data(info, FTS_SI_FINGER_THRESHOLD, 4, data);
	if (rc <= 0) {
		input_err(true, info->dev, "%s: Get threshold Read Fail!! [Data : %2X%2X]\n", __func__, data[0], data[1]);
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	finger_threshold = (unsigned short)(data[0] + (data[1] << 8));

	snprintf(buff, sizeof(buff), "%d", finger_threshold);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void module_off_master(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[3] = { 0 };
	int ret = 0;

	mutex_lock(&info->lock);
	if (info->enabled) {
		disable_irq(info->irq);
		info->enabled = false;
	}
	mutex_unlock(&info->lock);

	if (info->board->power)
		info->board->power(info, false);
	else
		ret = 1;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[3] = { 0 };
	int ret = 0;

	ret = fts_stop_device(info, false);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (ret == 0)
		snprintf(buff, sizeof(buff), "%s", "OK");
	else
		snprintf(buff, sizeof(buff), "%s", "NG");

<<<<<<< HEAD
	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	if (strncmp(buff, "OK", 2) == 0)
		info->cmd_state = CMD_STATUS_OK;
	else
		info->cmd_state = CMD_STATUS_FAIL;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	if (strncmp(buff, "OK", 2) == 0)
		sec->cmd_state = SEC_CMD_STATUS_OK;
	else
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void module_on_master(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[3] = { 0 };
	int ret = 0;

	mutex_lock(&info->lock);
	if (!info->enabled) {
		enable_irq(info->irq);
		info->enabled = true;
	}
	mutex_unlock(&info->lock);

	if (info->board->power)
		info->board->power(info, true);
	else
		ret = 1;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[3] = { 0 };
	int ret = 0;

	ret = fts_start_device(info);

	if (info->input_dev->disabled)
		fts_stop_device(info, info->lowpower_flag);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (ret == 0)
		snprintf(buff, sizeof(buff), "%s", "OK");
	else
		snprintf(buff, sizeof(buff), "%s", "NG");

<<<<<<< HEAD
	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	if (strncmp(buff, "OK", 2) == 0)
		info->cmd_state = CMD_STATUS_OK;
	else
		info->cmd_state = CMD_STATUS_FAIL;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	if (strncmp(buff, "OK", 2) == 0)
		sec->cmd_state = SEC_CMD_STATUS_OK;
	else
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_chip_vendor(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };
	strncpy(buff, "STM", sizeof(buff));
	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	strncpy(buff, "STM", sizeof(buff));
	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_chip_name(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };

	if (info->ic_product_id)
		strncpy(buff, "FTS4BD056", sizeof(buff));
	else
		strncpy(buff, "FTS4BD062", sizeof(buff));

	set_default_result(info);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	memcpy(buff, info->firmware_name + 7, 9);

	sec_cmd_set_default_result(sec);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static int get_mis_cal(struct fts_ts_info *info)
{
	unsigned char regAdd[3] = { 0 };
	unsigned char data[2] = { 0 };
	int ret;

	regAdd[0] = 0xC7;
	regAdd[1] = 0x05;

	ret = fts_write_reg(info, regAdd, 2);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to write\n", __func__);
		return -EIO;
	}

	fts_delay(50);

	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = 0x67;

	ret = fts_read_reg(info, regAdd, 3, data, 2);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read\n", __func__);
		return -EIO;
	}

	input_err(true, &info->client->dev, "%s: %02X, %02X\n", __func__, data[0], data[1]);

	return data[1];
}

static void get_mis_cal_info(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = get_mis_cal(info);
	if (ret < 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	snprintf(buff, sizeof(buff), "%d", ret);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_wet_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[3] = { 0 };
	unsigned char data[2] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = 0x66;

	ret = fts_read_reg(info, regAdd, 3, data, 2);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_err(true, &info->client->dev, "%s: %02X, %02X\n", __func__, data[0], data[1]);

	snprintf(buff, sizeof(buff), "%d", data[1]);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_x_num(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };

	set_default_result(info);
	snprintf(buff, sizeof(buff), "%d", info->SenseChannelLength);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = 2;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	sec_cmd_set_default_result(sec);
	snprintf(buff, sizeof(buff), "%d", info->SenseChannelLength);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_y_num(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };

	set_default_result(info);
	snprintf(buff, sizeof(buff), "%d", info->ForceChannelLength);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };

	sec_cmd_set_default_result(sec);
	snprintf(buff, sizeof(buff), "%d", info->ForceChannelLength);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_checksum_data(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[16] = { 0 };
	int rc;
	unsigned char regAdd[3];
	unsigned char buf[5];

	set_default_result(info);

	regAdd[0] = 0xb3;
	regAdd[1] = 0x00;
	regAdd[2] = 0x01;
	info->fts_write_reg(info, regAdd, 3);
	fts_delay(1);

	regAdd[0] = 0xb1;
	regAdd[1] = 0xEF;
	regAdd[2] = 0xFC;
	rc = info->fts_read_reg(info, regAdd, 3, buf, 5);

	snprintf(buff, sizeof(buff), "%02X%02X%02X%02X", buf[1], buf[2], buf[3], buf[4]);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[16] = { 0 };
	int rc;
	unsigned char data[6] = { 0 };

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	rc = fts_systemreset(info, 10);
	if (rc != FTS_NOT_ERROR) {
		snprintf(buff, sizeof(buff), "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	} else {
		fts_reinit(info);

		fts_interrupt_set(info, INT_DISABLE);

		rc = info->fts_get_sysinfo_data(info, FTS_SI_CONFIG_CHECKSUM, 5, data);
		if (rc <= 0) {
			input_err(true, info->dev, "%s: Get checksum data Read Fail!! [Data : %2X%2X%2X%2X]\n", __func__, data[1], data[0], data[3], data[2]);
			sec->cmd_state = SEC_CMD_STATUS_FAIL;
			return;
		}

		fts_interrupt_set(info, INT_ENABLE);

		snprintf(buff, sizeof(buff), "%02X%02X%02X%02X", data[1], data[0], data[3], data[2]);
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_OK;
		input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void run_reference_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;

	set_default_result(info);
	if (info->touch_stopped) {
		char buff[CMD_STR_LEN] = { 0 };
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	fts_read_frame(info, TYPE_BASELINE_DATA, &min, &max);
	snprintf(buff, sizeof(buff), "%d,%d", min, max);
<<<<<<< HEAD
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_reference(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	node = fts_check_index(info);
	if (node < 0)
		return;

	val = info->pFrame[node];
	snprintf(buff, sizeof(buff), "%d", val);
<<<<<<< HEAD
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void run_rawcap_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;
	unsigned char regAdd[4] = {0xB0, 0x04, 0x49, 0x00};

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (!info->run_autotune && (info->digital_rev == FTS_DIGITAL_REV_2))
		goto rawcap_read;
	else
		tsp_debug_info(true, &info->client->dev, "%s: set autotune\n\n", __func__);

	disable_irq(info->irq);

	if (info->digital_rev == FTS_DIGITAL_REV_1) {
		unsigned char data[FTS_EVENT_SIZE];
		unsigned char regAdd;
		int fail_retry = 0;

		fts_interrupt_set(info, INT_DISABLE);
		fts_command(info, CX_TUNNING);
		fts_delay(300);

		regAdd = READ_ONE_EVENT;
		while (fts_read_reg(info, &regAdd, 1, (unsigned char *)data, FTS_EVENT_SIZE)) {
			if ((data[0] == EVENTID_STATUS_EVENT) &&
				(data[1] == STATUS_EVENT_MUTUAL_AUTOTUNE_DONE)) {
				break;
			}

			if (fail_retry++ > FTS_RETRY_COUNT * 15) {
				tsp_debug_info(true, info->dev, "%s: Raw data read Time Over\n", __func__);
				break;
			}
			fts_delay(10);
		}

		fts_fw_wait_for_event(info, STATUS_EVENT_MUTUAL_AUTOTUNE_DONE);
		fts_fw_wait_for_event (info, STATUS_EVENT_WATER_SELF_AUTOTUNE_DONE);

		fts_interrupt_set(info, INT_ENABLE);
	} else if ((info->digital_rev == FTS_DIGITAL_REV_2)
#ifdef CONFIG_SEC_DEBUG_TSP_LOG
	&& !info->rawdata_read_lock
#endif
	) {
		fts_interrupt_set(info, INT_DISABLE);

		fts_command(info, SENSEOFF);
		fts_delay(50);
#ifdef FTS_SUPPORT_TOUCH_KEY
		if (info->board->support_mskey) {
			fts_command(info, FTS_CMD_KEY_SENSE_OFF); // Key Sensor OFF
		}
#endif
		fts_command(info, FLUSHBUFFER);

		fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
		fts_release_all_key(info);
#endif

		fts_execute_autotune(info);

		//STMicro Auto-tune protection disable
		fts_write_reg(info, regAdd, 4);
		fts_delay(1);

		fts_command(info, SLEEPOUT);
		fts_delay(1);
		fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_WATER_MODE
		fts_fw_wait_for_event(info, STATUS_EVENT_WATER_SELF_DONE);
#else
		fts_fw_wait_for_event (info, STATUS_EVENT_FORCE_CAL_DONE);
#endif
#ifdef FTS_SUPPORT_TOUCH_KEY
		if (info->board->support_mskey)
			fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

		fts_interrupt_set(info, INT_ENABLE);
	}
	enable_irq(info->irq);

rawcap_read:
	fts_delay(50);
	fts_read_frame(info, TYPE_FILTERED_DATA, &min, &max);

	snprintf(buff, sizeof(buff), "%d,%d", min, max);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	fts_read_frame(info, TYPE_FILTERED_DATA, &min, &max);
	snprintf(buff, sizeof(buff), "%d,%d", min, max);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_rawcap(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	node = fts_check_index(info);
	if (node < 0)
		return;

	val = info->pFrame[node];
	snprintf(buff, sizeof(buff), "%d", val);
<<<<<<< HEAD
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void run_delta_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	fts_read_frame(info, TYPE_STRENGTH_DATA, &min, &max);
	snprintf(buff, sizeof(buff), "%d,%d", min, max);
<<<<<<< HEAD
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_strength_all_data(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short min = 0x7FFF;
	short max = 0x8000;
	char all_strbuff[(info->ForceChannelLength)*(info->SenseChannelLength)*5];
	int i, j;

	memset(all_strbuff,0,sizeof(char)*((info->ForceChannelLength)*(info->SenseChannelLength)*5));	//size 5  ex(1125,)

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	fts_read_frame(info, TYPE_STRENGTH_DATA, &min, &max);


	for (i = 0; i < info->ForceChannelLength; i++) {
		for (j = 0; j < info->SenseChannelLength; j++) {

			snprintf(buff, sizeof(buff), "%d,", info->pFrame[(i * info->SenseChannelLength) + j]);
			strncat(all_strbuff, buff, sizeof(buff));
		}
	}

	sec->cmd_state = SEC_CMD_STATUS_OK;

	sec_cmd_set_cmd_result(sec, all_strbuff, strnlen(all_strbuff, sizeof(all_strbuff)));
	input_info(true, &info->client->dev, "%s: %ld (%ld)\n", __func__, strnlen(all_strbuff, sizeof(all_strbuff)),sizeof(all_strbuff));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_delta(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	node = fts_check_index(info);
	if (node < 0)
		return;

	val = info->pFrame[node];
	snprintf(buff, sizeof(buff), "%d", val);
<<<<<<< HEAD
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

void fts_read_self_frame(struct fts_ts_info *info, unsigned short oAddr)
{
=======
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_pat_information(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[22] = { 0 };
	sec_cmd_set_default_result(sec);

#ifdef PAT_CONTROL
	fts_get_calibration_information(info);
#endif
	/* fixed tune version will be saved at excute autotune */
	snprintf(buff, sizeof(buff), "P%02XT%04X",
		info->cal_count,info->tune_fix_ver);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_external_factory(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	info->external_factory = true;
	snprintf(buff, sizeof(buff), "OK");

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

#ifdef FTS_SUPPORT_HOVER
void fts_read_self_frame(struct fts_ts_info *info, unsigned short oAddr)
{
	struct sec_cmd_data *sec = &info->sec;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	char buff[66] = {0, };
	short *data = 0;
	char temp[9] = {0, };
	char temp2[512] = {0, };
	int i;
	int rc;
	int retry=1;
	unsigned char regAdd[6] = {0xD0, 0x00, 0x00, 0xD0, 0x00, 0x00};

	if (info->touch_stopped) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	if (!info->hover_enabled) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Hover is disabled\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP Hover disabled");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Hover is disabled\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP Hover disabled");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	while (!info->hover_ready) {
		if (retry++ > 500) {
<<<<<<< HEAD
			tsp_debug_info(true, &info->client->dev, "%s: [FTS] Timeout - Abs Raw Data Ready Event\n",
=======
			input_err(true, &info->client->dev, "%s: Timeout - Abs Raw Data Ready Event\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					  __func__);
			break;
		}
		fts_delay(10);
	}

	regAdd[1] = (oAddr >> 8) & 0xff;
	regAdd[2] = oAddr & 0xff;
	rc = info->fts_read_reg(info, &regAdd[0], 3, (unsigned char *)&buff[0], 5);
<<<<<<< HEAD
	if (!rc) {
		info->cmd_state = CMD_STATUS_FAIL;
		return;
	}

	if (info->digital_rev == FTS_DIGITAL_REV_1) {
		tsp_debug_info(true, &info->client->dev, "%s: Force Address : %02x%02x\n",
				__func__, buff[1], buff[0]);
		tsp_debug_info(true, &info->client->dev, "%s: Sense Address : %02x%02x\n",
				__func__, buff[3], buff[2]);
		regAdd[1] = buff[3];
		regAdd[2] = buff[2];
		regAdd[4] = buff[1];
		regAdd[5] = buff[0];
	} else if (info->digital_rev == FTS_DIGITAL_REV_2) {
		tsp_debug_info(true, &info->client->dev, "%s: Force Address : %02x%02x\n",
				__func__, buff[2], buff[1]);
		tsp_debug_info(true, &info->client->dev, "%s: Sense Address : %02x%02x\n",
				__func__, buff[4], buff[3]);
		regAdd[1] = buff[4];
		regAdd[2] = buff[3];
		regAdd[4] = buff[2];
		regAdd[5] = buff[1];
	}

	rc = info->fts_read_reg(info, &regAdd[0], 3,
							(unsigned char *)&buff[0],
							info->SenseChannelLength * 2 + 1);
	if (!rc) {
		info->cmd_state = CMD_STATUS_FAIL;
		return;
	}

	if (info->digital_rev == FTS_DIGITAL_REV_1)
		data = (short *)&buff[0];
	else
		data = (short *)&buff[1];
=======
	if (rc <= 0) {
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_info(true, &info->client->dev, "%s: Force Address : %02x%02x\n",
			__func__, buff[2], buff[1]);
	input_info(true, &info->client->dev, "%s: Sense Address : %02x%02x\n",
			__func__, buff[4], buff[3]);
	regAdd[1] = buff[4];
	regAdd[2] = buff[3];
	regAdd[4] = buff[2];
	regAdd[5] = buff[1];

	rc = info->fts_read_reg(info, &regAdd[0], 3,
					(unsigned char *)&buff[0],
					info->SenseChannelLength * 2 + 1);
	if (rc <= 0) {
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	data = (short *)&buff[1];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	memset(temp, 0x00, ARRAY_SIZE(temp));
	memset(temp2, 0x00, ARRAY_SIZE(temp2));

	for (i = 0; i < info->SenseChannelLength; i++) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev,
				"%s: Rx [%d] = %d\n", __func__,
				i,
				*data);
		sprintf(temp, "%d,", *data);
=======
		input_info(true, &info->client->dev,
				"%s: Rx [%d] = %d\n", __func__, i, *data);
		snprintf(temp, sizeof(temp), "%d,", *data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		strncat(temp2, temp, 9);
		data++;
	}

	rc = info->fts_read_reg(info, &regAdd[3], 3,
							(unsigned char *)&buff[0],
							info->ForceChannelLength * 2 + 1);
<<<<<<< HEAD
	if (!rc) {
		info->cmd_state = CMD_STATUS_FAIL;
		return;
	}

	if (info->digital_rev == FTS_DIGITAL_REV_1)
		data = (short *)&buff[0];
	else
		data = (short *)&buff[1];

	for (i = 0; i < info->ForceChannelLength; i++) {
		tsp_debug_info(true, &info->client->dev,
				"%s: Tx [%d] = %d\n", __func__, i, *data);
		sprintf(temp, "%d,", *data);
=======
	if (rc <= 0) {
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	data = (short *)&buff[1];

	for (i = 0; i < info->ForceChannelLength; i++) {
		input_info(true, &info->client->dev,
				"%s: Tx [%d] = %d\n", __func__, i, *data);
		snprintf(temp, sizeof(temp), "%d,", *data);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		strncat(temp2, temp, 9);
		data++;
	}

<<<<<<< HEAD
	set_cmd_result(info, temp2, strnlen(temp2, sizeof(temp2)));

	info->cmd_state = CMD_STATUS_OK;
=======
	sec_cmd_set_cmd_result(sec, temp2, strnlen(temp2, sizeof(temp2)));

	sec->cmd_state = SEC_CMD_STATUS_OK;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void run_abscap_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_read_self_frame(info, 0x000E);
}

static void run_absdelta_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
	fts_read_self_frame(info, 0x0012);
}

#define FTS_F_WIX1_ADDR	0x1FE7
#define FTS_S_WIX1_ADDR	0x1FE8
#define FTS_F_WIX2_ADDR	0x18FD
#define FTS_S_WIX2_ADDR	0x1929
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
	fts_read_self_frame(info, 0x0012);
}
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define FTS_WATER_SELF_RAW_ADDR	0x1A

static void fts_read_ix_data(struct fts_ts_info *info, bool allnode)
{
<<<<<<< HEAD
	char buff[CMD_STR_LEN] = { 0 };
=======
	struct sec_cmd_data *sec = &info->sec;
	char buff[SEC_CMD_STR_LEN] = { 0 };
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	unsigned short max_tx_ix_sum = 0;
	unsigned short min_tx_ix_sum = 0xFFFF;

	unsigned short max_rx_ix_sum = 0;
	unsigned short min_rx_ix_sum = 0xFFFF;

	unsigned char tx_ix2[info->ForceChannelLength + 4];
	unsigned char rx_ix2[info->SenseChannelLength + 4];

<<<<<<< HEAD
	unsigned short ix1_addr = FTS_F_WIX1_ADDR;
	unsigned short ix2_tx_addr = FTS_F_WIX2_ADDR;
	unsigned short ix2_rx_addr = FTS_S_WIX2_ADDR;

	unsigned char regAdd[FTS_EVENT_SIZE];
	unsigned char tx_ix1 = 0, rx_ix1 = 0;
	unsigned char buf[FTS_EVENT_SIZE] = {0};
	unsigned char r_addr = READ_ONE_EVENT;
=======
	unsigned char regAdd[FTS_EVENT_SIZE];
	unsigned short tx_ix1 = 0, rx_ix1 = 0;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	unsigned short force_ix_data[info->ForceChannelLength * 2 + 1];
	unsigned short sense_ix_data[info->SenseChannelLength * 2 + 1];
	int buff_size,j;
	char *mbuff = NULL;
	int num,n,a,fzero;
	char cnum;
<<<<<<< HEAD
	int retry = 0, i = 0;

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
		       __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

//	fts_command(info, SLEEPIN); // Sleep In for INT disable

	disable_irq(info->irq);

	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, SENSEOFF);

	fts_delay(50);

	#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
	}
	#endif
=======
	int i = 0;
	int comp_header_addr, comp_start_tx_addr, comp_start_rx_addr;
	unsigned int rx_num, tx_num;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
		       __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);

	fts_command(info, SENSEOFF);

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
	}
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	fts_command(info, FLUSHBUFFER);                 // Clear FIFO
	fts_delay(50);

<<<<<<< HEAD
	regAdd[0] = 0xB2;
	regAdd[1] = (ix1_addr >> 8)&0xff;
	regAdd[2] = (ix1_addr&0xff);
	regAdd[3] = 0x04;

	fts_write_reg(info, &regAdd[0], 4);
	fts_delay(1);

	retry = FTS_RETRY_COUNT * 3;
	do {
		if (retry < 0) {
			tsp_debug_err(true, &info->client->dev, "%s: failed to compare buf,[%x][%x][%x][%x] break1!\n",
							__func__, buf[1], buf[2], regAdd[1], regAdd[2]);
			break;
		}
		fts_delay(10);
		fts_read_reg(info, &r_addr, 1, &buf[0], FTS_EVENT_SIZE);
		retry--;
	} while (buf[1] != regAdd[1] || buf[2] != regAdd[2]);

	//read fifo
	tx_ix1 = buf[3] * 2;
	rx_ix1 = buf[4] * 2;

	regAdd[0] = 0xB2;
	regAdd[1] = (ix2_tx_addr >>8)&0xff;
	regAdd[2] = (ix2_tx_addr & 0xff);

	for (i = 0; i < info->ForceChannelLength / 4 + 1; i++) {
		fts_write_reg(info, &regAdd[0], 4);
		fts_delay(1);

		retry = FTS_RETRY_COUNT * 3;
		do {
			if (retry < 0) {
				tsp_debug_err(true, &info->client->dev, "%s: failed to compare buf,[%x][%x][%x][%x] break2!\n",
							__func__, buf[1], buf[2], regAdd[1], regAdd[2]);
				break;
			}
			fts_delay(10);
			fts_read_reg(info, &r_addr, 1, &buf[0], FTS_EVENT_SIZE);
			retry--;
		} while (buf[1] != regAdd[1] || buf[2] != regAdd[2]);

		//read fifo
		tx_ix2[i*4] = buf[3];
		tx_ix2[i*4+1] = buf[4];
		tx_ix2[i*4+2] = buf[5];
		tx_ix2[i*4+3] = buf[6];

		ix2_tx_addr += 4;
		regAdd[0] = 0xB2;
		regAdd[1] = (ix2_tx_addr >>8)&0xff;
		regAdd[2] = (ix2_tx_addr & 0xff);
	}

	regAdd[0] = 0xB2;
	regAdd[1] = (ix2_rx_addr >>8)&0xff;
	regAdd[2] = (ix2_rx_addr & 0xff);

	for(i = 0; i < info->SenseChannelLength / 4 + 1;i++) {
		fts_write_reg(info, &regAdd[0], 4);
		fts_delay(1);

		retry = FTS_RETRY_COUNT * 3;
		do {
			if (retry < 0) {
				tsp_debug_err(true, &info->client->dev, "%s: failed to compare buf,[%x][%x][%x][%x] break3!\n",
							__func__, buf[1], buf[2], regAdd[1], regAdd[2]);

				break;
			}
			fts_delay(10);
			fts_read_reg(info, &r_addr, 1, &buf[0], FTS_EVENT_SIZE);
			retry--;
		} while (buf[1] != regAdd[1] || buf[2] != regAdd[2]);

		//read fifo
		rx_ix2[i*4] = buf[3];
		rx_ix2[i*4+1] = buf[4];
		rx_ix2[i*4+2] = buf[5];
		rx_ix2[i*4+3] = buf[6];

		ix2_rx_addr += 4;
		regAdd[0] = 0xB2;
		regAdd[1] = (ix2_rx_addr >>8)&0xff;
		regAdd[2] = (ix2_rx_addr & 0xff);
	}

	for(i = 0; i < info->ForceChannelLength; i++) {
		force_ix_data[i] = tx_ix1 + tx_ix2[i];
		if(max_tx_ix_sum < tx_ix1 + tx_ix2[i] )
			max_tx_ix_sum = tx_ix1 + tx_ix2[i];
		if(min_tx_ix_sum > tx_ix1 + tx_ix2[i] )
			min_tx_ix_sum = tx_ix1 + tx_ix2[i];
	}

	for(i = 0; i < info->SenseChannelLength; i++) {
		sense_ix_data[i] = rx_ix1 + rx_ix2[i];
		if(max_rx_ix_sum < rx_ix1 + rx_ix2[i] )
			max_rx_ix_sum = rx_ix1 + rx_ix2[i];
		if(min_rx_ix_sum > rx_ix1 + rx_ix2[i] )
			min_rx_ix_sum = rx_ix1 + rx_ix2[i];
	}

	tsp_debug_info(true, &info->client->dev, "%s MIN_TX_IX_SUM : %d MAX_TX_IX_SUM : %d\n",
				__func__, min_tx_ix_sum, max_tx_ix_sum );
	tsp_debug_info(true, &info->client->dev, "%s MIN_RX_IX_SUM : %d MAX_RX_IX_SUM : %d\n",
				__func__, min_rx_ix_sum, max_rx_ix_sum );

	fts_systemreset(info);
	fts_wait_for_ready(info);

	fts_command(info, SLEEPOUT);
	fts_delay(1);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_WATER_MODE
	fts_fw_wait_for_event(info, STATUS_EVENT_WATER_SELF_DONE);
#else
	fts_fw_wait_for_event(info, STATUS_EVENT_FORCE_CAL_DONE);
#endif
=======
	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	/* Request compensation data */
	regAdd[0] = 0xB8;
	regAdd[1] = 0x20;		// SELF IX
	regAdd[2] = 0x00;
	fts_write_reg(info, &regAdd[0], 3);
	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, 0x20, 0x00);

	/* Read an address of compensation data */
	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = FTS_SI_COMPENSATION_OFFSET_ADDR;
	fts_read_reg(info, regAdd, 3, &buff[0], 4);
	comp_header_addr = buff[1] + (buff[2] << 8);

	/* Read header of compensation area */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_header_addr >> 8) & 0xFF;
	regAdd[2] = comp_header_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], 16 + 1);
	tx_num = buff[5];
	rx_num = buff[6];

	tx_ix1 = (short) buff[10] * FTS_SEC_IX1_TX_MULTIPLIER;		// Self TX Ix1
	rx_ix1 = (short) buff[11] * FTS_SEC_IX1_RX_MULTIPLIER;		// Self RX Ix1

	comp_start_tx_addr = comp_header_addr + 0x10;
	comp_start_rx_addr = comp_start_tx_addr + tx_num;

	memset(tx_ix2, 0x0, tx_num);
	memset(rx_ix2, 0x0, rx_num);

	/* Read Self TX Ix2 */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_start_tx_addr >> 8) & 0xFF;
	regAdd[2] = comp_start_tx_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &tx_ix2[0], tx_num + 1);

	/* Read Self RX Ix2 */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_start_rx_addr >> 8) & 0xFF;
	regAdd[2] = comp_start_rx_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &rx_ix2[0], rx_num + 1);

	for(i = 0; i < info->ForceChannelLength; i++) {
		force_ix_data[i] = tx_ix1 + tx_ix2[i + 1];
		if(max_tx_ix_sum < force_ix_data[i])
			max_tx_ix_sum = force_ix_data[i];
		if(min_tx_ix_sum > force_ix_data[i])
			min_tx_ix_sum = force_ix_data[i];
	}

	for(i = 0; i < info->SenseChannelLength; i++) {
		sense_ix_data[i] = rx_ix1 + rx_ix2[i + 1];
		if(max_rx_ix_sum < sense_ix_data[i])
			max_rx_ix_sum = sense_ix_data[i];
		if(min_rx_ix_sum > sense_ix_data[i])
			min_rx_ix_sum = sense_ix_data[i];
	}

	input_info(true, &info->client->dev, "%s: MIN_TX_IX_SUM : %d MAX_TX_IX_SUM : %d\n",
				__func__, min_tx_ix_sum, max_tx_ix_sum );
	input_info(true, &info->client->dev, "%s: MIN_RX_IX_SUM : %d MAX_RX_IX_SUM : %d\n",
				__func__, min_rx_ix_sum, max_rx_ix_sum );

	fts_systemreset(info, 10);

	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_fw_wait_for_event (info, STATUS_EVENT_FORCE_CAL_DONE_D3);

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

	enable_irq(info->irq);
	fts_interrupt_set(info, INT_ENABLE);

<<<<<<< HEAD
	if(allnode == true){
		buff_size = (info->ForceChannelLength + info->SenseChannelLength + 2)*5;
=======
	if (allnode == true) {
		buff_size = (info->ForceChannelLength + info->SenseChannelLength + 2) * 5;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		mbuff = kzalloc(buff_size, GFP_KERNEL);
	}
	if (mbuff != NULL) {
		char *pBuf = mbuff;
<<<<<<< HEAD
		for(i = 0; i < info->ForceChannelLength; i++) {
			num =  force_ix_data[i];
			n = 100000;
			fzero = 0;
			for(j=5;j>0;j--){
				n = n/10;
				a = num/n;
				if(a) fzero = 1;
				cnum = a + '0';
				num  = num - a*n;
				if(fzero)*pBuf++ = cnum;
			}
			if(!fzero) *pBuf++ = '0';
			*pBuf++ = ',';
			tsp_debug_info(true, &info->client->dev, "%d ", force_ix_data[i]);
		}
		for(i = 0; i < info->SenseChannelLength; i++) {
			num =  sense_ix_data[i];
			n = 100000;
			fzero = 0;
			for(j=5;j>0;j--){
				n = n/10;
				a = num/n;
				if(a) fzero = 1;
				cnum = a + '0';
				num  = num - a*n;
				if(fzero)*pBuf++ = cnum;
			}
			if(!fzero) *pBuf++ = '0';
			if(i < (info->SenseChannelLength-1)) *pBuf++ = ',';
			tsp_debug_info(true, &info->client->dev, "%d ", sense_ix_data[i]);
		}

		set_cmd_result(info, mbuff, buff_size);
		info->cmd_state = CMD_STATUS_OK;
		kfree(mbuff);
	}
	else {
		if(allnode == true){
		   snprintf(buff, sizeof(buff), "%s", "kzalloc failed");
		   info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		}
		else{
			snprintf(buff, sizeof(buff), "%d,%d,%d,%d", min_tx_ix_sum, max_tx_ix_sum, min_rx_ix_sum, max_rx_ix_sum);
			info->cmd_state = CMD_STATUS_OK;
		}
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
		for (i = 0; i < info->ForceChannelLength; i++) {
			num =  force_ix_data[i];
			n = 100000;
			fzero = 0;
			for (j = 5; j > 0; j--) {
				n = n / 10;
				a = num / n;
				if (a)
					fzero = 1;
				cnum = a + '0';
				num  = num - a*n;
				if (fzero)
					*pBuf++ = cnum;
			}
			if (!fzero)
				*pBuf++ = '0';
			*pBuf++ = ',';
			input_info(true, &info->client->dev, "Force[%d] %d\n", i, force_ix_data[i]);
		}
		for (i = 0; i < info->SenseChannelLength; i++) {
			num =  sense_ix_data[i];
			n = 100000;
			fzero = 0;
			for (j = 5; j > 0; j--) {
				n = n / 10;
				a = num / n;
				if (a)
					fzero = 1;
				cnum = a + '0';
				num  = num - a * n;
				if (fzero)
					*pBuf++ = cnum;
			}
			if (!fzero)
				*pBuf++ = '0';
			if (i < (info->SenseChannelLength - 1))
				*pBuf++ = ',';
			input_info(true, &info->client->dev, "Sense[%d] %d\n", i, sense_ix_data[i]);
		}

		sec_cmd_set_cmd_result(sec, mbuff, buff_size);
		sec->cmd_state = SEC_CMD_STATUS_OK;
		kfree(mbuff);
	} else {
		if (allnode == true) {
		   snprintf(buff, sizeof(buff), "%s", "kzalloc failed");
		   sec->cmd_state = SEC_CMD_STATUS_FAIL;
		} else {
			snprintf(buff, sizeof(buff), "%d,%d,%d,%d", min_tx_ix_sum, max_tx_ix_sum, min_rx_ix_sum, max_rx_ix_sum);
			sec->cmd_state = SEC_CMD_STATUS_OK;
		}
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}
}

static void run_ix_data_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_read_ix_data(info, false);
}

static void run_ix_data_read_all(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_read_ix_data(info, true);
}

static void fts_read_self_raw_frame(struct fts_ts_info *info, unsigned short oAddr, bool allnode)
{
<<<<<<< HEAD
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char D0_offset = 1;
	unsigned char regAdd[3] = {0xD0, 0x00, 0x00};
	unsigned char ReadData[info->SenseChannelLength * 2 + 1];
=======
	struct sec_cmd_data *sec = &info->sec;
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char D0_offset = 1;
	unsigned char regAdd[3] = {0xD0, 0x00, 0x00};
	unsigned char ReadData[(info->ForceChannelLength + info->SenseChannelLength) * 2 + 1];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	unsigned short self_force_raw_data[info->ForceChannelLength * 2 + 1];
	unsigned short self_sense_raw_data[info->SenseChannelLength * 2 + 1];
	unsigned int FrameAddress = 0;
	unsigned char count=0;
	int buff_size,i,j;
	char *mbuff = NULL;
	int num,n,a,fzero;
	char cnum;
	unsigned short min_tx_self_raw_data = 0xFFFF;
	unsigned short max_tx_self_raw_data = 0;
	unsigned short min_rx_self_raw_data = 0xFFFF;
	unsigned short max_rx_self_raw_data = 0;
<<<<<<< HEAD

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

//	fts_command(info, SLEEPIN); // Sleep In for INT disable

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, SENSEOFF);

	fts_delay(50);
=======
	unsigned char cmd[4] = {0xC7, 0x00, FTS_CFG_APWR, 0x00}; // Don't enter to IDLE

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	fts_systemreset(info, 60);

	// Don't enter to IDLE mode
	fts_write_reg(info, &cmd[0], 4);
	fts_delay(20);

	fts_command(info, FLUSHBUFFER);                 // Clear FIFO
	fts_delay(20);

	// Auto-Tune
	fts_command(info, CX_TUNNING);
	msleep(300);
	fts_fw_wait_for_event_D3(info, STATUS_EVENT_MUTUAL_AUTOTUNE_DONE, 0x00);

	fts_command(info, SELF_AUTO_TUNE);
	msleep(300);
	fts_fw_wait_for_event_D3(info, STATUS_EVENT_SELF_AUTOTUNE_DONE_D3, 0x00);

	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_delay(100);

	fts_command(info, SENSEOFF);
	fts_delay(100);

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
	}
#endif

<<<<<<< HEAD
	fts_command(info, FLUSHBUFFER);                 // Clear FIFO
	fts_delay(50);
=======
	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	regAdd[1] = 0x00;
	regAdd[2] = oAddr;
	fts_read_reg(info, regAdd, 3, &ReadData[0], 4);

	FrameAddress = ReadData[D0_offset] + (ReadData[D0_offset + 1] << 8);           // D1 : DOFFSET = 0, D2 : DOFFSET : 1

	regAdd[1] = (FrameAddress >> 8) & 0xFF;
	regAdd[2] = FrameAddress & 0xFF;

	fts_read_reg(info, regAdd, 3, &ReadData[0], info->ForceChannelLength * 2 + 1);

	for(count = 0; count < info->ForceChannelLength; count++) {
		self_force_raw_data[count] = ReadData[count*2+D0_offset] + (ReadData[count*2+D0_offset+1]<<8);

		if(max_tx_self_raw_data < self_force_raw_data[count])
			max_tx_self_raw_data = self_force_raw_data[count];
		if(min_tx_self_raw_data > self_force_raw_data[count])
			min_tx_self_raw_data = self_force_raw_data[count];
	}

	regAdd[1] = 0x00;
	regAdd[2] = oAddr + 2;
	fts_read_reg(info, regAdd, 3, &ReadData[0], 4);

	FrameAddress = ReadData[D0_offset] + (ReadData[D0_offset + 1] << 8);           // D1 : DOFFSET = 0, D2 : DOFFSET : 1

	regAdd[1] = (FrameAddress >> 8) & 0xFF;
	regAdd[2] = FrameAddress & 0xFF;

	fts_read_reg(info, regAdd, 3, &ReadData[0], info->SenseChannelLength * 2 + 1);

	for(count = 0; count < info->SenseChannelLength; count++) {
		self_sense_raw_data[count] = ReadData[count*2+D0_offset] + (ReadData[count*2+D0_offset+1]<<8);

		if(max_rx_self_raw_data < self_sense_raw_data[count])
			max_rx_self_raw_data = self_sense_raw_data[count];
		if(min_rx_self_raw_data > self_sense_raw_data[count])
			min_rx_self_raw_data = self_sense_raw_data[count];
	}

<<<<<<< HEAD
	tsp_debug_info(true, &info->client->dev, "%s MIN_TX_SELF_RAW: %d MAX_TX_SELF_RAW : %d\n",
				__func__, min_tx_self_raw_data, max_tx_self_raw_data );
	tsp_debug_info(true, &info->client->dev, "%s MIN_RX_SELF_RAW : %d MIN_RX_SELF_RAW : %d\n",
				__func__, min_rx_self_raw_data, max_rx_self_raw_data );

	fts_command(info, SLEEPOUT);
	fts_delay(1);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_WATER_MODE
	fts_fw_wait_for_event(info, STATUS_EVENT_WATER_SELF_DONE);
#else
	fts_fw_wait_for_event(info, STATUS_EVENT_FORCE_CAL_DONE);
#endif
=======
	input_info(true, &info->client->dev, "%s: MIN_TX_SELF_RAW: %d MAX_TX_SELF_RAW : %d\n",
				__func__, min_tx_self_raw_data, max_tx_self_raw_data );
	input_info(true, &info->client->dev, "%s: MIN_RX_SELF_RAW : %d MIN_RX_SELF_RAW : %d\n",
				__func__, min_rx_self_raw_data, max_rx_self_raw_data );


	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_delay(50);

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

	enable_irq(info->irq);
	fts_interrupt_set(info, INT_ENABLE);

<<<<<<< HEAD
	if(allnode == true){
		buff_size = (info->ForceChannelLength + info->SenseChannelLength + 2)*5;
=======
	if (allnode == true) {
		buff_size = (info->ForceChannelLength + info->SenseChannelLength + 2) * 7;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		mbuff = kzalloc(buff_size, GFP_KERNEL);
	}
	if (mbuff != NULL) {
		char *pBuf = mbuff;
<<<<<<< HEAD
		for(i = 0; i < info->ForceChannelLength; i++) {
			num =  self_force_raw_data[i];
			n = 100000;
			fzero = 0;
			for(j=5;j>0;j--){
				n = n/10;
				a = num/n;
				if(a) fzero = 1;
				cnum = a + '0';
				num  = num - a*n;
				if(fzero)*pBuf++ = cnum;
			}
			if(!fzero) *pBuf++ = '0';
			*pBuf++ = ',';
			tsp_debug_info(true, &info->client->dev, "%d ", self_force_raw_data[i]);
		}
		for(i = 0; i < info->SenseChannelLength; i++) {
			num =  self_sense_raw_data[i];
			n = 100000;
			fzero = 0;
			for(j=5;j>0;j--){
				n = n/10;
				a = num/n;
				if(a) fzero = 1;
				cnum = a + '0';
				num  = num - a*n;
				if(fzero)*pBuf++ = cnum;
			}
			if(!fzero) *pBuf++ = '0';
			if(i < (info->SenseChannelLength-1)) *pBuf++ = ',';
			tsp_debug_info(true, &info->client->dev, "%d ", self_sense_raw_data[i]);
		}


		set_cmd_result(info, mbuff, buff_size);
		info->cmd_state = CMD_STATUS_OK;
		kfree(mbuff);
	}
	else {
		if(allnode == true){
		   snprintf(buff, sizeof(buff), "%s", "kzalloc failed");
		   info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		}
		else{
			snprintf(buff, sizeof(buff), "%d,%d,%d,%d", min_tx_self_raw_data, max_tx_self_raw_data, min_rx_self_raw_data, max_rx_self_raw_data);
			info->cmd_state = CMD_STATUS_OK;
		}
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
		for (i = 0; i < info->ForceChannelLength; i++) {
			num =  self_force_raw_data[i];
			n = 100000;
			fzero = 0;
			for (j = 5; j > 0; j--) {
				n = n / 10;
				a = num / n;
				if (a)
					fzero = 1;
				cnum = a + '0';
				num  = num - a * n;
				if (fzero)
					*pBuf++ = cnum;
			}
			if (!fzero)
				*pBuf++ = '0';
			*pBuf++ = ',';
			input_info(true, &info->client->dev, "Force[%d] %d\n", i, self_force_raw_data[i]);
		}
		for (i = 0; i < info->SenseChannelLength; i++) {
			num =  self_sense_raw_data[i];
			n = 100000;
			fzero = 0;
			for (j = 5; j > 0; j--) {
				n = n / 10;
				a = num / n;
				if (a)
					fzero = 1;
				cnum = a + '0';
				num  = num - a * n;
				if (fzero)
					*pBuf++ = cnum;
			}
			if (!fzero)
				*pBuf++ = '0';
			if (i < (info->SenseChannelLength - 1))
				*pBuf++ = ',';
			input_info(true, &info->client->dev, "Sense[%d] %d\n", i, self_sense_raw_data[i]);
		}

		sec_cmd_set_cmd_result(sec, mbuff, buff_size);
		sec->cmd_state = SEC_CMD_STATUS_OK;
		kfree(mbuff);
	} else {
		if (allnode == true) {
		   snprintf(buff, sizeof(buff), "%s", "kzalloc failed");
		   sec->cmd_state = SEC_CMD_STATUS_FAIL;
		} else {
			snprintf(buff, sizeof(buff), "%d,%d,%d,%d", min_tx_self_raw_data, max_tx_self_raw_data, min_rx_self_raw_data, max_rx_self_raw_data);
			sec->cmd_state = SEC_CMD_STATUS_OK;
		}
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}
}

static void run_self_raw_read(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_read_self_raw_frame(info, FTS_WATER_SELF_RAW_ADDR,false);
}

static void run_self_raw_read_all(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;

	set_default_result(info);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	fts_read_self_raw_frame(info, FTS_WATER_SELF_RAW_ADDR,true);
}

static void run_trx_short_test(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	int ret = 0;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret = 0;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	ret = fts_panel_ito_test(info);
	if (ret == 0)
		snprintf(buff, sizeof(buff), "%s", "OK");
	else
		snprintf(buff, sizeof(buff), "%s", "FAIL");
<<<<<<< HEAD
	enable_irq(info->irq);

	info->cmd_state = CMD_STATUS_OK;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

=======

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}


>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define FTS_MAX_TX_LENGTH		44
#define FTS_MAX_RX_LENGTH		64

#define FTS_CX2_READ_LENGTH		4
#define FTS_CX2_ADDR_OFFSET		3
#define FTS_CX2_TX_START		0
<<<<<<< HEAD
#define FTS_CX2_BASE_ADDR		0x1000

static void get_cx_data(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======

static void get_cx_data(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	short val = 0;
	int node = 0;

	sec_cmd_set_default_result(sec);
	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	node = fts_check_index(info);
	if (node < 0)
		return;

<<<<<<< HEAD
	val = info->cx_data[node];
	snprintf(buff, sizeof(buff), "%d", val);
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_OK;
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

}

static void get_cx_all_data(void *device_data)
{
	const char HEX[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char mbuff[CMD_STR_LEN] = { 0 };
	char *buff;
	int i, j, buff_size;

	set_default_result(info);
	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(mbuff, sizeof(mbuff), "%s", "TSP turned off");
		set_cmd_result(info, mbuff, strnlen(mbuff, sizeof(mbuff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	buff_size = info->ForceChannelLength * info->SenseChannelLength * 2;
	buff = kzalloc(buff_size, GFP_KERNEL);
	if (buff != NULL) {
		char *pBuf = buff;
		if (info->cx_data) {
			for (j = 0; j < info->ForceChannelLength; j++) {
				for(i = 0; i < info->SenseChannelLength; i++) {
					*pBuf++ = HEX[(info->cx_data[(j * info->SenseChannelLength) + i] >> 4)&0x0f];
					*pBuf++ = HEX[info->cx_data[(j * info->SenseChannelLength) + i]&0x0f];
				}
				//          tsp_debug_info(true, &info->client->dev, "%s", info->cx_data[(j * info->SenseChannelLength) + i]);
			}
			//tsp_debug_info(true, &info->client->dev, "%s", info->cx_data[(j * info->SenseChannelLength) + i]);
		}

		set_cmd_result(info, buff, buff_size);
		info->cmd_state = CMD_STATUS_OK;
		tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

		kfree(buff);
	} else {
		snprintf(mbuff, sizeof(mbuff), "%s", "kzalloc failed");
		set_cmd_result(info, mbuff, strnlen(mbuff, sizeof(mbuff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
	}
}

static void run_cx_data_read(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char ReadData[info->ForceChannelLength][info->SenseChannelLength + FTS_CX2_READ_LENGTH];
	unsigned char regAdd[8];
	unsigned char buf[8];
	unsigned char r_addr = READ_ONE_EVENT;
	unsigned int addr, rx_num, tx_num;
	int i, j, cx_rx_length, max_tx_length, max_rx_length, address_offset = 0, start_tx_offset = 0, retry = 0;
	unsigned char *pStr = NULL;
	unsigned char pTmp[16] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	pStr = kzalloc(4 * (info->SenseChannelLength + 1), GFP_KERNEL);
	if (pStr == NULL) {
		tsp_debug_info(true, &info->client->dev, "FTS pStr kzalloc failed\n");
		return;
	}

	tsp_debug_info(true, &info->client->dev, "%s: start \n", __func__);

	fts_command(info, SENSEOFF);
	fts_delay(50);

=======
	if (info->cx_data)
		val = info->cx_data[node];
	snprintf(buff, sizeof(buff), "%d", val);
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	/* input_info(true, &info->client->dev, "%s: %s\n", __func__, buff); */

}

static void run_cx_data_read(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char ReadData[info->ForceChannelLength][info->SenseChannelLength + FTS_CX2_READ_LENGTH];
	unsigned char regAdd[8];
	unsigned int addr, rx_num, tx_num;
	int i, j;
	unsigned char *pStr = NULL;
	unsigned char pTmp[16] = { 0 };
	int ret;

	int comp_header_addr, comp_start_addr;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	pStr = kzalloc(4 * (info->SenseChannelLength + 1), GFP_KERNEL);
	if (pStr == NULL) {
		input_err(true, &info->client->dev, "%s: pStr kzalloc failed\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_info(true, &info->client->dev, "%s: start\n", __func__);

	disable_irq(info->irq);

	ret = fts_interrupt_set(info, INT_DISABLE);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to set of interrupt(%d)\n",
				__func__, INT_DISABLE);
		goto out;
	}

	ret = fts_command(info, SENSEOFF);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to send cmd(%d)\n",
				__func__, SENSEOFF);
		goto out;
	}
	fts_delay(50);

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		ret = fts_command(info, FTS_CMD_KEY_SENSE_OFF); // Key Sensor OFF
		if (ret <= 0) {
			input_err(true, &info->client->dev,
					"%s: failed to send cmd(%d)\n",
					__func__, FTS_CMD_KEY_SENSE_OFF);
			goto out;
		}
	}
#endif
	ret = fts_command(info, FLUSHBUFFER);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to send cmd(%d)\n",
				__func__, FLUSHBUFFER);
		goto out;
	}
	fts_delay(50);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	/* Request compensation data */
	regAdd[0] = 0xB8;
	regAdd[1] = 0x02;		// MUTUAL CX
	regAdd[2] = 0x00;
	ret = fts_write_reg(info, &regAdd[0], 3);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to write reg\n", __func__);
		goto out;
	}

	ret = fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, 0x02, 0x00);
	if (ret) {
		input_err(true, &info->client->dev,
				"%s: failed to wait for specific event\n",
				__func__);
		goto out;
	}

	/* Read an address of compensation data */
	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = FTS_SI_COMPENSATION_OFFSET_ADDR;
	ret = fts_read_reg(info, regAdd, 3, &buff[0], 4);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to read reg\n", __func__);
		goto out;
	}

	comp_header_addr = buff[1] + (buff[2] << 8);

	/* Read header of compensation area */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_header_addr >> 8) & 0xFF;
	regAdd[2] = comp_header_addr & 0xFF;
	ret = fts_read_reg(info, regAdd, 3, &buff[0], 16 + 1);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
				"%s: failed to read reg\n", __func__);
		goto out;
	}

	tx_num = buff[5];
	rx_num = buff[6];
	comp_start_addr = comp_header_addr + 0x10;

	/* Read compensation data */
	for (j = 0; j < tx_num; j++) {
		memset(&ReadData[j], 0x0, (rx_num + 1));
		memset(pStr, 0x0, 4 * (rx_num + 1));
		snprintf(pTmp, sizeof(pTmp), "Tx%02d | ", j);
		strncat(pStr, pTmp, 4 * rx_num);

		addr = comp_start_addr + (rx_num * j);
		regAdd[0] = 0xD0;
		regAdd[1] = (addr >> 8) & 0xFF;
		regAdd[2] = addr & 0xFF;
		ret = fts_read_reg(info, regAdd, 3, &ReadData[j][0], rx_num + 1);
		if (ret <= 0) {
			input_err(true, &info->client->dev,
				"%s: failed to read reg\n", __func__);
			goto out;
		}

		for (i = 0; i < rx_num; i++) {
			snprintf(pTmp, sizeof(pTmp), "%3d", ReadData[j][i + 1]);
			strncat(pStr, pTmp, 4 * rx_num);
		}
		input_raw_info(true, &info->client->dev, "%s\n", pStr);
	}

	if (info->cx_data) {
		for (j = 0; j < tx_num; j++) {
			for(i = 0; i < rx_num; i++)
				info->cx_data[(j * rx_num) + i] = ReadData[j][i + 1];
		}
	}

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
	}
#endif
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_command(info, SENSEON);
	fts_interrupt_set(info, INT_ENABLE);

	kfree(pStr);

	enable_irq(info->irq);
	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

	return;

out:
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
	}
#endif
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_command(info, SENSEON);
	fts_interrupt_set(info, INT_ENABLE);

	kfree(pStr);

	enable_irq(info->irq);
	snprintf(buff, sizeof(buff), "%s", "NG");
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_cx_all_data(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char ReadData[info->ForceChannelLength][info->SenseChannelLength + FTS_CX2_READ_LENGTH];
	unsigned char regAdd[8];
	unsigned int addr, rx_num, tx_num;
	int i, j;
	unsigned char *pStr = NULL;
	unsigned char pTmp[16] = { 0 };
	char all_strbuff[(info->ForceChannelLength)*(info->SenseChannelLength)*3];
	int comp_header_addr, comp_start_addr;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: start\n", __func__);

	pStr = kzalloc(4 * (info->SenseChannelLength + 1), GFP_KERNEL);
	if (pStr == NULL) {
		input_err(true, &info->client->dev, "%s: pStr kzalloc failed\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	fts_command(info, SENSEOFF);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF); // Key Sensor OFF
	}
#endif
	disable_irq(info->irq);
	fts_command(info, FLUSHBUFFER);
	fts_delay(50);

<<<<<<< HEAD
	tx_num = info->ForceChannelLength;
	rx_num = info->SenseChannelLength;

	if (info->digital_rev == FTS_DIGITAL_REV_1) {
		max_tx_length = FTS_MAX_TX_LENGTH -4;
		max_rx_length = FTS_MAX_RX_LENGTH -4;
	} else {
		max_tx_length = FTS_MAX_TX_LENGTH;
		max_rx_length = FTS_MAX_RX_LENGTH;
	}

	start_tx_offset = FTS_CX2_TX_START * max_rx_length / FTS_CX2_READ_LENGTH * FTS_CX2_ADDR_OFFSET;
	address_offset = max_rx_length /FTS_CX2_READ_LENGTH;

	for(j = 0; j < tx_num; j++) {
=======
	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	tx_num = info->ForceChannelLength;
	rx_num = info->SenseChannelLength;

	memset(all_strbuff, 0, sizeof(char) * (tx_num*rx_num*3));	//size 3  ex(45,)

	/* Request compensation data */
	regAdd[0] = 0xB8;
	regAdd[1] = 0x02;		// MUTUAL CX
	regAdd[2] = 0x00;
	fts_write_reg(info, &regAdd[0], 3);
	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, 0x02, 0x00);

	/* Read an address of compensation data */
	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = FTS_SI_COMPENSATION_OFFSET_ADDR;
	fts_read_reg(info, regAdd, 3, &buff[0], 4);
	comp_header_addr = buff[1] + (buff[2] << 8);

	/* Read header of compensation area */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_header_addr >> 8) & 0xFF;
	regAdd[2] = comp_header_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], 16 + 1);
	tx_num = buff[5];
	rx_num = buff[6];
	comp_start_addr = comp_header_addr + 0x10;

	/* Read compensation data */
	for (j = 0; j < tx_num; j++) {
		memset(&ReadData[j], 0x0, (rx_num + 1));
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		memset(pStr, 0x0, 4 * (rx_num + 1));
		snprintf(pTmp, sizeof(pTmp), "Tx%02d | ", j);
		strncat(pStr, pTmp, 4 * rx_num);

<<<<<<< HEAD
		addr = FTS_CX2_BASE_ADDR + (j * address_offset * FTS_CX2_ADDR_OFFSET) + start_tx_offset;

		if(rx_num % FTS_CX2_READ_LENGTH != 0)
			cx_rx_length = rx_num / FTS_CX2_READ_LENGTH + 1;
		else
			cx_rx_length = rx_num / FTS_CX2_READ_LENGTH;

		for(i = 0; i < cx_rx_length; i++) {
			regAdd[0] = 0xB2;
			regAdd[1] = (addr >> 8) & 0xff;
			regAdd[2] = (addr & 0xff);
			regAdd[3] = 0x04;
			fts_write_reg(info, &regAdd[0], 4);

			retry = FTS_RETRY_COUNT * 3;
			do {
				if (retry < 0) {
					tsp_debug_err(true, &info->client->dev,
							"%s: failed to compare buf, break!\n", __func__);
					break;
				}

				fts_read_reg(info, &r_addr, 1, &buf[0], FTS_EVENT_SIZE);
				retry--;
			} while (buf[1] != regAdd[1] || buf[2] != regAdd[2]);

			ReadData[j][i * 4] = buf[3] & 0x3F;
			ReadData[j][i * 4 + 1] = (buf[3] & 0xC0) >> 6 | (buf[4] & 0x0F) << 2;
			ReadData[j][i * 4 + 2] = ((buf[4] & 0xF0)>> 4) | ((buf[5] & 0x03) << 4);
			ReadData[j][i * 4 + 3] = buf[5] >> 2;
			addr = addr + 3;

			snprintf(pTmp, sizeof(pTmp), "%3d%3d%3d%3d ",
		        ReadData[j][i*4], ReadData[j][i*4+1], ReadData[j][i*4+2], ReadData[j][i*4+3]);
			strncat(pStr, pTmp, 4 *rx_num);
		}

		tsp_debug_info(true, &info->client->dev, "FTS %s\n", pStr);
=======
		addr = comp_start_addr + (rx_num * j);
		regAdd[0] = 0xD0;
		regAdd[1] = (addr >> 8) & 0xFF;
		regAdd[2] = addr & 0xFF;
		fts_read_reg(info, regAdd, 3, &ReadData[j][0], rx_num + 1);
		for (i = 0; i < rx_num; i++) {
			snprintf(pTmp, sizeof(pTmp), "%3d", ReadData[j][i + 1]);
			strncat(pStr, pTmp, 4 * rx_num);
		}
		input_info(true, &info->client->dev, "%s\n", pStr);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	if (info->cx_data) {
		for (j = 0; j < tx_num; j++) {
<<<<<<< HEAD
			for(i = 0; i < rx_num; i++)
				info->cx_data[(j * rx_num) + i] = ReadData[j][i];
=======
			for(i = 0; i < rx_num; i++){
				info->cx_data[(j * rx_num) + i] = ReadData[j][i + 1];
				snprintf(buff, sizeof(buff), "%d,", ReadData[j][i + 1]);
				strncat(all_strbuff, buff, sizeof(buff));
			}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}
	}

	kfree(pStr);

<<<<<<< HEAD
	snprintf(buff, sizeof(buff), "%s", "OK");
	enable_irq(info->irq);
	fts_command(info, SENSEON);
=======
	enable_irq(info->irq);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
	}
#endif
<<<<<<< HEAD
	info->cmd_state = CMD_STATUS_OK;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

#ifdef FTS_SUPPORT_TOUCH_KEY
#define USE_KEY_NUM 2
static void run_key_cx_data_read(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char key_cx2_data[2];
	unsigned char ReadData[USE_KEY_NUM * FTS_CX2_READ_LENGTH];
	unsigned char regAdd[8];
	unsigned char buf[8];
	unsigned char r_addr = READ_ONE_EVENT;
	unsigned int addr;
	int i = 0, retry = 0;

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
		            __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);

	addr = FTS_CX2_BASE_ADDR;

	regAdd[0] = 0xB2;
	regAdd[1] = (addr >> 8) & 0xff;
	regAdd[2] = (addr & 0xff);
	regAdd[3] = 0x04;

	fts_write_reg(info, &regAdd[0], 4);
	fts_delay(1);

	retry = FTS_RETRY_COUNT * 10;
	do {
		if (retry < 0) {
			tsp_debug_info(true, &info->client->dev,"%s: failed to compare buf, break!\n", __func__);
			break;
		}

		fts_read_reg(info, &r_addr, 1, &buf[0], FTS_EVENT_SIZE);
		retry--;
	} while (buf[1] != regAdd[1] || buf[2] != regAdd[2]);


	ReadData[i * 4] = buf[3] & 0x3F;
	ReadData[i * 4 + 1] = (buf[3] & 0xC0) >> 6 | (buf[4] & 0x0F) << 2;
	ReadData[i * 4 + 2] = ((buf[4] & 0xF0)>> 4) | ((buf[5] & 0x03) << 4);
	ReadData[i * 4 + 3] = buf[5] >> 2;

	key_cx2_data[0] = ReadData[2]; key_cx2_data[1] = ReadData[3];

	tsp_debug_info(true, &info->client->dev, "%s: [Key 1:%d][Key 2:%d]\n", __func__,
	            key_cx2_data[0], key_cx2_data[1]);

	//snprintf(buff, sizeof(buff), "%s", "OK");
	snprintf(buff, sizeof(buff), "%d,%d", key_cx2_data[0], key_cx2_data[1]);
	enable_irq(info->irq);

	info->cmd_state = CMD_STATUS_OK;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

static void set_tsp_test_result(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char regAdd[4] = {0xB0, 0x07, 0xE7, 0x00};

	set_default_result(info);

	if (info->cmd_param[0] < TSP_FACTEST_RESULT_NONE
				|| info->cmd_param[0] > TSP_FACTEST_RESULT_PASS) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
		return;
	}

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);

	regAdd[3] = info->cmd_param[0];
	fts_write_reg(info, &regAdd[0], 4);
	fts_delay(100);
	fts_command(info, FTS_CMD_SAVE_FWCONFIG);

	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CONFIG);

	enable_irq(info->irq);
	fts_interrupt_set(info, INT_ENABLE);

	snprintf(buff, sizeof(buff), "%s", "OK");
	info->cmd_state = CMD_STATUS_OK;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_tsp_test_result(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned char cmd[4] = {0xB2, 0x07, 0xE7, 0x01};
	int timeout = 0;

	set_default_result(info);

	if (info->touch_stopped) {
		char buff[CMD_STR_LEN] = { 0 };
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	fts_command(info, FLUSHBUFFER);
	fts_write_reg(info, &cmd[0], 4);
	info->cmd_state = CMD_STATUS_RUNNING;

	while (info->cmd_state == CMD_STATUS_RUNNING) {
		if (timeout++>30) {
			info->cmd_state = CMD_STATUS_FAIL;
			break;
		}
		fts_delay(10);
	}
}

static void hover_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped || !(info->reinit_done) || (info->fts_power_state == FTS_POWER_STATE_LOWPOWER)) {
		tsp_debug_info(true, &info->client->dev,
			"%s: [ERROR] Touch is stopped:%d, reinit_done:%d, power_state:%d\n",
			__func__, info->touch_stopped, info->reinit_done, info->fts_power_state);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;

		if(info->cmd_param[0]==1){
			info->retry_hover_enable_after_wakeup = 1;
			tsp_debug_info(true, &info->client->dev, "%s: retry_hover_on_after_wakeup \n", __func__);
=======
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, all_strbuff, strnlen(all_strbuff, sizeof(all_strbuff)));
	input_info(true, &info->client->dev, "%s: %ld (%ld)\n", __func__, strnlen(all_strbuff, sizeof(all_strbuff)),sizeof(all_strbuff));
}

static void fts_read_wtr_cx_data(struct fts_ts_info *info, bool allnode)
{
	struct sec_cmd_data *sec = &info->sec;
	char buff[512] = { 0 };
	unsigned char regAdd[8];
	unsigned char *result_tx = NULL;
	unsigned char *result_rx = NULL;
	char temp[8];
	unsigned int ii;
	unsigned int tx_num, rx_num;
        unsigned int comp_header_addr, comp_start_tx_addr, comp_start_rx_addr;
        int i;

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: ++\n", __func__);

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);

	fts_command(info, SENSEOFF);

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
	}
#endif
	fts_command(info, FLUSHBUFFER);
	fts_delay(50);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	result_tx = kzalloc(info->ForceChannelLength + 10, GFP_KERNEL);
	result_rx = kzalloc(info->SenseChannelLength + 10, GFP_KERNEL);
	if (!result_tx || !result_rx) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);

		snprintf(buff, sizeof(buff), "%s", "FAIL");
		goto err_alloc_mem;
	}

	/* Request compensation data */
	regAdd[0] = 0xB8;
	regAdd[1] = 0x20;		// SELF IX
	regAdd[2] = 0x00;
	fts_write_reg(info, &regAdd[0], 3);
	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, 0x20, 0x00);

	/* Read an address of compensation data */
	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = FTS_SI_COMPENSATION_OFFSET_ADDR;
	fts_read_reg(info, regAdd, 3, &buff[0], 4);
	comp_header_addr = buff[1] + (buff[2] << 8);

	/* Read header of compensation area */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_header_addr >> 8) & 0xFF;
	regAdd[2] = comp_header_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], 16 + 1);
	tx_num = buff[5];
	rx_num = buff[6];

	comp_start_tx_addr = comp_header_addr + 0x10 + tx_num + rx_num;
	comp_start_rx_addr = comp_start_tx_addr + tx_num;

	memset(result_tx, 0x0, tx_num);
	memset(result_rx, 0x0, rx_num);

	memset(buff, 0x0, 512);
	/* Read Self TX Cx2 */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_start_tx_addr >> 8) & 0xFF;
	regAdd[2] = comp_start_tx_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], tx_num + 1);

	for(i = 0; i < tx_num; i++) {
		result_tx[i] = buff[i + 1];
	}

	memset(buff, 0x0, 512);
	/* Read Self RX Ix2 */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_start_rx_addr >> 8) & 0xFF;
	regAdd[2] = comp_start_rx_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], rx_num + 1);

	for(i = 0; i < rx_num; i++) {
		result_rx[i] = buff[i + 1];
	}

	if (allnode) {
		char *data = 0;

		data = result_tx;
		for (ii = 0; ii < info->ForceChannelLength; ii++) {
			input_info(true, &info->client->dev,
					"%s: Tx[%d] = %d\n", __func__, ii, *data);
			snprintf(temp, sizeof(temp), "%d,", *data);
			strncat(buff, temp, 9);
			data++;
		}

		data = result_rx;
		for (ii = 0; ii < info->SenseChannelLength; ii++) {
			input_info(true, &info->client->dev,
					"%s: Rx[%d] = %d\n", __func__, ii, *data);
			snprintf(temp, sizeof(temp), "%d,", *data);
			strncat(buff, temp, 9);
			data++;
		}
	} else {
		unsigned char min_tx = 255, max_tx = 0, min_rx = 255, max_rx = 0;

		for (ii = 0; ii < info->ForceChannelLength; ii++) {
			input_info(true, &info->client->dev,
					"%s: Tx[%d] = %d\n", __func__, ii, result_tx[ii]);

			min_tx = min(min_tx, result_tx[ii]);
			max_tx = max(max_tx, result_tx[ii]);
		}

		for (ii = 0; ii < info->SenseChannelLength; ii++) {
			input_info(true, &info->client->dev,
					"%s: Rx[%d] = %d\n", __func__, ii, result_rx[ii]);
			min_rx = min(min_rx, result_rx[ii]);
			max_rx = max(max_rx, result_rx[ii]);
		}

		snprintf(buff, sizeof(buff), "%d,%d,%d,%d", min_tx, max_tx, min_rx, max_rx);

	}

err_alloc_mem:
	if (result_tx)
		kfree(result_tx);
	if (result_rx)
		kfree(result_rx);

	enable_irq(info->irq);
	fts_interrupt_set(info, INT_ENABLE);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
	}
#endif
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

}

static void run_wtr_cx_data_read(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
	fts_read_wtr_cx_data(info, false);
}

static void run_wtr_cx_data_read_all(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);

	sec_cmd_set_default_result(sec);
	fts_read_wtr_cx_data(info, true);
}

#ifdef FTS_SUPPORT_PRESSURE_SENSOR
int fts_read_pressure_data(struct fts_ts_info *info)
{
	unsigned char pressure_reg[3] = {0, };
	unsigned char buf[32] = {0, };
	short value[10] = {0, };
	int rtn, i = 0;
	int pressure_sensor_value = 0;

	pressure_reg[0] = 0xD0;
	pressure_reg[1] = 0x00;
	pressure_reg[2] = FTS_SI_PRESSURE_STRENGTH_ADDR;

	rtn = fts_read_reg(info, pressure_reg, 3, &buf[0], 4);
	if (rtn <= 0) {
		input_err(true, &info->client->dev, "%s: Pressure read failed rc = %d\n", __func__, rtn);
		return rtn;
	} else {
		pressure_reg[1] = buf[2];
		pressure_reg[2] = buf[1];
	}

	rtn = fts_read_reg(info, pressure_reg, 3, &buf[0], PRESSURE_SENSOR_COUNT * 2 + 1);
	if (rtn <= 0) {
		input_err(true, &info->client->dev, "%s: Pressure read failed rc = %d\n", __func__, rtn);
		return rtn;
	} else {
		for (i = 0; i < PRESSURE_SENSOR_COUNT; i++) {
			value[i] = buf[i * 2 + 1] + (buf[i * 2 + 1 + 1] << 8);
			pressure_sensor_value += value[i];
		}
	}

	if (info->debug_string & 0x2)
		input_info(true, &info->client->dev, "%s: %d %d %d %d %d %d %d %d %d %d %d\n", __func__,
			value[0], value[1], value[2], value[3], value[4],
			value[5], value[6], value[7], value[8], value[9],
			pressure_sensor_value);

	return pressure_sensor_value;
}
#endif

#ifdef FTS_SUPPORT_TOUCH_KEY
#define USE_KEY_NUM 2
static void run_key_cx_data_read(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char key_cx2_data[2], key_cx1_data, total_cx_data[USE_KEY_NUM];
	unsigned char ReadData[USE_KEY_NUM * FTS_CX2_READ_LENGTH];
	unsigned char regAdd[8];
	unsigned int addr;
	int /*tx_num, */rx_num, DOFFSET = 1;
	int comp_start_addr, comp_header_addr;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
		            __func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);

	/* Request compensation data */
	regAdd[0] = 0xB8;
	regAdd[1] = 0x10;   // For button
	regAdd[2] = 0x00;
	fts_write_reg(info, &regAdd[0], 3);
	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, regAdd[1], 0x00);

	/* Read an address of compensation data */
	regAdd[0] = 0xD0;
	regAdd[1] = 0x00;
	regAdd[2] = FTS_SI_COMPENSATION_OFFSET_ADDR;
	fts_read_reg(info, regAdd, 3, &buff[0], 4);
	comp_header_addr = buff[0 + DOFFSET] + (buff[1 + DOFFSET] << 8);

	/* Read header of compensation area */
	regAdd[0] = 0xD0;
	regAdd[1] = (comp_header_addr >> 8) & 0xFF;
	regAdd[2] = comp_header_addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &buff[0], 16 + DOFFSET);
	/*tx_num = buff[4 + DOFFSET];*/
	rx_num = buff[5 + DOFFSET];
	key_cx1_data = buff[9 + DOFFSET];
	comp_start_addr = comp_header_addr + 0x10;

	memset(&ReadData[0], 0x0, rx_num);
	/* Read compensation data */
	addr = comp_start_addr;
	regAdd[0] = 0xD0;
	regAdd[1] = (addr >> 8) & 0xFF;
	regAdd[2] = addr & 0xFF;
	fts_read_reg(info, regAdd, 3, &ReadData[0], rx_num + DOFFSET);
	key_cx2_data[0] = ReadData[0 + DOFFSET];
	key_cx2_data[1] = ReadData[1 + DOFFSET];
	total_cx_data[0] = key_cx1_data * 2 + key_cx2_data[0];
	total_cx_data[1] = key_cx1_data * 2 + key_cx2_data[1];

	//snprintf(buff, sizeof(buff), "%s", "OK");
	snprintf(buff, sizeof(buff), "%d,%d,%d,%d", key_cx2_data[0], key_cx2_data[1], total_cx_data[0], total_cx_data[1]);

	enable_irq(info->irq);
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

#ifdef FTS_SUPPORT_PRESSURE_SENSOR
static void run_force_pressure_calibration(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = {0};
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
#endif

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (info->touch_count > 0) {
		snprintf(buff, sizeof(buff), "%s", "NG_FINGER_ON");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		goto out_force_pressure_cal;
	}

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, FTS_CMD_PRESSURE_SENSE_OFF);

	info->fts_systemreset(info, 30);

	fts_command(info, PRESSURE_AUTO_TUNE);
	fts_delay(300);
	fts_fw_wait_for_event_D3(info, STATUS_EVENT_SELF_AUTOTUNE_DONE_D3, 0x00);

	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	info->fts_systemreset(info, 30);

	fts_command(info, SENSEON);
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
	fts_fw_wait_for_event (info, STATUS_EVENT_FORCE_CAL_DONE_D3);
	fts_interrupt_set(info, INT_ENABLE);
	enable_irq(info->irq);

	fts_get_factory_debug_information(info);

	info->pressure_cal_base++;

	if (info->pressure_cal_base > 0xFE)
		info->pressure_cal_base = 0xFE;

	fts_set_factory_debug_information(info, info->pressure_cal_base, info->pressure_cal_delta, info->nv_crc_fail_count);

#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, &info->lowpower_flag, sizeof(info->lowpower_flag));
	if (ret < 0)
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
#endif

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;

out_force_pressure_cal:
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

/*
 * index is 0 : cleared, do not calibrated
 * index is 1 : Ass'y
 * index is 2 : Rear
 * index is 3 : BackGlass
 */

static void set_pressure_test_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[4] = {0xC7, 0x03, 0x00, 0x00};
	int ret = 0;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		regAdd[3] = sec->cmd_param[0];
		ret = fts_write_reg(info, regAdd, 4);

		if (ret < 0) {
			snprintf(buff, sizeof(buff), "NG");
			sec->cmd_state = SEC_CMD_STATUS_FAIL;
		} else {
			snprintf(buff, sizeof(buff), "%s", "OK");
			sec->cmd_state = SEC_CMD_STATUS_OK;
		}
	}

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void run_pressure_strength_read_all(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAddr[3] = {0xD0, 0x00, FTS_SI_PRESSURE_STRENGTH_ADDR};
	unsigned char data[PRESSURE_SENSOR_COUNT * 2 + 1];
	int ret, i;
	short value[3] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	memset(data, 3, PRESSURE_SENSOR_COUNT * 2 + 1);

	ret = fts_read_reg(info, regAddr, 3, data, 4);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read pressure strength addr\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	regAddr[1] = data[2];
	regAddr[2] = data[1];

	memset(data, 0x00, PRESSURE_SENSOR_COUNT * 2 + 1);

	ret = fts_read_reg(info, regAddr, 3, data, PRESSURE_SENSOR_COUNT * 2 + 1);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read pressure strength\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_err(true, &info->client->dev, "%s: [3] %02X, %02X, %02X, %02X, %02X, %02X, %02X\n",
		__func__, data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

	for (i = 0; i < PRESSURE_SENSOR_COUNT; i++)
		value[i] = (short)(data[i * 2 + 1] | (data[i * 2 + 1 + 1] << 8));

	snprintf(buff, sizeof(buff), "%d,%d,%d", value[0], value[1], value[2]);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void run_pressure_rawdata_read_all(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAddr[3] = {0xD0, 0x00, 0x00};
	unsigned char data[PRESSURE_SENSOR_COUNT * 2 + 1];
	int ret, i;
	short value[3] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	memset(data, 3, PRESSURE_SENSOR_COUNT * 2 + 1);

	ret = info->fts_get_sysinfo_data(info, FTS_SI_PRESSURE_FILTERED_RAW_ADDR, 3, data);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read pressure rawdata addr\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	regAddr[1] = data[1];
	regAddr[2] = data[0];

	memset(data, 0x00, PRESSURE_SENSOR_COUNT * 2 + 1);

	ret = fts_read_reg(info, regAddr, 3, data, PRESSURE_SENSOR_COUNT * 2 + 1);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read pressure rawdata\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_err(true, &info->client->dev, "%s: [3] %02X, %02X, %02X, %02X, %02X, %02X, %02X\n",
		__func__, data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

	for (i = 0; i < PRESSURE_SENSOR_COUNT; i++)
		value[i] = (short)(data[i * 2 + 1] | (data[i * 2 + 1 + 1] << 8));

	snprintf(buff, sizeof(buff), "%d,%d,%d", value[0], value[1], value[2]);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}


#define FTS_PRESSURE_IX1	10
#define FTS_PRESSIRE_IX2	17
static void run_pressure_ix_data_read_all(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[3] = {0xB8, 0x00, 0x02};
	unsigned char data[32];
	int ret, i;
	int value[3] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	disable_irq(info->irq);
	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, SENSEOFF);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
#endif
	fts_command(info, FLUSHBUFFER);
	fts_delay(50);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	ret = fts_write_reg(info, regAdd, 3);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to write pressure ix\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, regAdd[1], regAdd[2]);

	memset(data, 0x00, 32);

	ret = info->fts_get_sysinfo_data(info, FTS_SI_COMPENSATION_OFFSET_ADDR, 7, data);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read ix offset addr\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	input_info(true, &info->client->dev, "%s: [0] 0x%02X, [0x%02X, 0x%02X], 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
		__func__, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);

	regAdd[0] = 0xD0;
	regAdd[1] = data[1];
	regAdd[2] = data[0];

	memset(data, 0x00, 32);

	ret = fts_read_reg(info, &regAdd[0], 3, data, 32);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to read ix\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}

	for (i = 0; i < 4; i++)
		input_info(true, &info->client->dev, "%s: [%d] 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
			__func__, i, data[i * 8 + 0], data[i * 8 + 1], data[i * 8 + 2], data[i * 8 + 3],
			data[i * 8 + 4], data[i * 8 + 5], data[i * 8 + 6], data[i * 8 + 7]);

	for (i = 0; i < PRESSURE_SENSOR_COUNT; i++)
		value[i] = ((data[FTS_PRESSURE_IX1] * 2) + data[FTS_PRESSIRE_IX2 + i]);

	snprintf(buff, sizeof(buff), "%d,%d,%d", value[0], value[1], value[2]);

	enable_irq(info->irq);
	fts_interrupt_set(info, INT_ENABLE);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_pressure_strength(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char strength[12] = { 0 };
	int ret, index;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: [index:%d], [1: %d], [2:%d], [3:%d]\n",
		__func__, sec->cmd_param[0], sec->cmd_param[1], sec->cmd_param[2], sec->cmd_param[3]);

	if ((sec->cmd_param[0] < 1) || (sec->cmd_param[0] > 4)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	index = sec->cmd_param[0];

	strength[0] = 0xC7;
	strength[1] = 0x03;
	strength[2] = 0x02;
	strength[3] = (char)index;
	strength[4] = (char)(sec->cmd_param[1] & 0xFF);
	strength[5] = (char)(sec->cmd_param[1] >> 8);
	strength[6] = (char)(sec->cmd_param[2] & 0xFF);
	strength[7] = (char)(sec->cmd_param[2] >> 8);
	strength[8] = (char)(sec->cmd_param[3] & 0xFF);
	strength[9] = (char)(sec->cmd_param[3] >> 8);
	strength[10] = 0x00;
	strength[11] = 0x00;

	fts_command(info, SENSEOFF);
	fts_delay(50);
	fts_command(info, FLUSHBUFFER);
	fts_interrupt_set(info, INT_DISABLE);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	ret = fts_write_reg(info, strength, 12);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		fts_command(info, FTS_CMD_SAVE_CX_TUNING);
		fts_delay(230);
		fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

		fts_command(info, FLUSHBUFFER);
		fts_delay(10);
		fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
		fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
		fts_interrupt_set(info, INT_ENABLE);
		return;
	}

	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);

	fts_get_factory_debug_information(info);

	info->pressure_cal_delta++;

	if (info->pressure_cal_delta > 0xFE)
		info->pressure_cal_delta = 0xFE;

	fts_set_factory_debug_information(info, info->pressure_cal_base, info->pressure_cal_delta, info->nv_crc_fail_count);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_pressure_rawdata(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char rawdata[12] = { 0 };
	int ret, index;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: [index:%d], [1: %d], [2:%d], [3:%d]\n",
		__func__, sec->cmd_param[0], sec->cmd_param[1], sec->cmd_param[2], sec->cmd_param[3]);

	if ((sec->cmd_param[0] < 1) || (sec->cmd_param[0] > 4)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	index = sec->cmd_param[0];

	rawdata[0] = 0xC7;
	rawdata[1] = 0x03;
	rawdata[2] = 0x03;
	rawdata[3] = (char)index;
	rawdata[4] = (char)(sec->cmd_param[1] & 0xFF);
	rawdata[5] = (char)(sec->cmd_param[1] >> 8);
	rawdata[6] = (char)(sec->cmd_param[2] & 0xFF);
	rawdata[7] = (char)(sec->cmd_param[2] >> 8);
	rawdata[8] = (char)(sec->cmd_param[3] & 0xFF);
	rawdata[9] = (char)(sec->cmd_param[3] >> 8);
	rawdata[10] = 0x00;
	rawdata[11] = 0x00;

	fts_command(info, SENSEOFF);
	fts_delay(50);
	fts_command(info, FLUSHBUFFER);
	fts_interrupt_set(info, INT_DISABLE);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	ret = fts_write_reg(info, rawdata, 12);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		fts_command(info, FTS_CMD_SAVE_CX_TUNING);
		fts_delay(230);
		fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

		fts_command(info, FLUSHBUFFER);
		fts_delay(10);
		fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
		fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
		fts_interrupt_set(info, INT_ENABLE);
		return;
	}

	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_pressure_data_index(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char data[12] = { 0 };
	int ret, index;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: %d\n",
		__func__, sec->cmd_param[0]);

	if ((sec->cmd_param[0] < 0) || (sec->cmd_param[0] > 4)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (sec->cmd_param[0] == 0)
		input_info(true, &info->client->dev, "%s: disable calibrated strength\n", __func__);

	index = sec->cmd_param[0];

	data[0] = 0xC7;
	data[1] = 0x03;
	data[2] = 0x01;
	data[3] = (char)index;

	fts_command(info, SENSEOFF);
	fts_delay(50);
	fts_command(info, FLUSHBUFFER);
	fts_interrupt_set(info, INT_DISABLE);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	ret = fts_write_reg(info, data, 4);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;

		if (index != 0x00) {
			fts_command(info, FTS_CMD_SAVE_CX_TUNING);
			fts_delay(230);
			fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);
		}

		fts_command(info, FLUSHBUFFER);
		fts_delay(10);
		fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
		fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
		fts_interrupt_set(info, INT_ENABLE);
		return;
	}

	if (index != 0x00) {
		fts_command(info, FTS_CMD_SAVE_CX_TUNING);
		fts_delay(230);
		fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);
	}

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_pressure_strength(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char *data = NULL;
	short strength[3] = { 0 };
	int ret, index;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: index: %d\n",
		__func__, sec->cmd_param[0]);

	if ((sec->cmd_param[0] < 1) || (sec->cmd_param[0] > 4)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	index = sec->cmd_param[0] - 1;

	data = kzalloc(nvm_data[PRESSURE_STRENGTH].length, GFP_KERNEL);
	if (!data) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return;
	}

	ret = get_nvm_data(info, PRESSURE_STRENGTH, data);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		kfree(data);
		return;
	}

	if ((data[index * 8 + 6] == 0xFF) && (data[index * 8 + 7] == 0xFF)) {
		input_info(true, &info->client->dev, "%s: flash is initailized, clear\n", __func__);
		memset(&data[index * 8], 0x00, 8);
	}

	strength[0] = (short)(data[index * 8 + 0] | ((data[index * 8 + 1] << 8) & 0xFF00));
	strength[1] = (short)(data[index * 8 + 2] | ((data[index * 8 + 3] << 8) & 0xFF00));
	strength[2] = (short)(data[index * 8 + 4] | ((data[index * 8 + 5] << 8) & 0xFF00));

	snprintf(buff, sizeof(buff), "%d,%d,%d", strength[0], strength[1], strength[2]);

	kfree(data);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_pressure_rawdata(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char *data = NULL;
	short rawdata[3] = { 0 };
	int ret, index;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: index: %d\n",
		__func__, sec->cmd_param[0]);

	if ((sec->cmd_param[0] < 1) || (sec->cmd_param[0] > 4)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	index = sec->cmd_param[0] - 1;

	data = kzalloc(nvm_data[PRESSURE_RAWDATA].length, GFP_KERNEL);
	if (!data) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return;
	}

	ret = get_nvm_data(info, PRESSURE_RAWDATA, data);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		kfree(data);
		return;
	}

	if ((data[index * 8 + 6] == 0xFF) && (data[index * 8 + 7] == 0xFF)) {
		input_info(true, &info->client->dev, "%s: flash is initailized, clear\n", __func__);
		memset(&data[index * 8], 0x00, 8);
	}

	rawdata[0] = (short)(data[index * 8 + 0] | ((data[index * 8 + 1] << 8) & 0xFF00));
	rawdata[1] = (short)(data[index * 8 + 2] | ((data[index * 8 + 3] << 8) & 0xFF00));
	rawdata[2] = (short)(data[index * 8 + 4] | ((data[index * 8 + 5] << 8) & 0xFF00));

	snprintf(buff, sizeof(buff), "%d,%d,%d", rawdata[0], rawdata[1], rawdata[2]);

	kfree(data);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_pressure_data_index(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char *data = NULL;
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	input_info(true, &info->client->dev, "%s: index: %d\n",
		__func__, sec->cmd_param[0]);

	data = kzalloc(nvm_data[GROUP_INDEX].length, GFP_KERNEL);
	if (!data) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return;
	}

	ret = get_nvm_data(info, GROUP_INDEX, data);
	if (ret <= 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		kfree(data);
		return;
	}

	if (data[0] == 0xFF) {
		input_info(true, &info->client->dev, "%s: flash is initailized, clear\n", __func__);
		memset(&data[0], 0x00, 1);
	}

	snprintf(buff, sizeof(buff), "%d", data[0]);

	kfree(data);

	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_pressure_strength_clear(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char data[12] = { 0 };
	int ret;
	int ii = 0;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}


	fts_command(info, SENSEOFF);
	fts_delay(50);
	fts_command(info, FLUSHBUFFER);
	fts_interrupt_set(info, INT_DISABLE);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif
	for (ii = 1; ii < 4; ii++) {
		data[0] = 0xC7;
		data[1] = 0x03;
		data[2] = 0x02;
		data[3] = ii;
		ret = fts_write_reg(info, data, 12);
		if (ret <= 0) {
			goto err_write_reg;
		}
	}

	input_info(true, &info->client->dev, "%s: clear strength\n", __func__);

	for (ii = 1; ii < 4; ii++) {
		data[0] = 0xC7;
		data[1] = 0x03;
		data[2] = 0x03;
		data[3] = ii;

		ret = fts_write_reg(info, data, 12);
		if (ret <= 0) {
			goto err_write_reg;
		}
	}

	input_info(true, &info->client->dev, "%s: clear rawdata\n", __func__);

	data[0] = 0xC7;
	data[1] = 0x03;
	data[2] = 0x01;
	data[3] = 0;

	ret = fts_write_reg(info, data, 4);
	if (ret <= 0) {
		goto err_write_reg;
	}

	input_info(true, &info->client->dev, "%s: clear group index\n", __func__);

	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

	return;

err_write_reg:
	snprintf(buff, sizeof(buff), "%s", "NG");
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);
	return;
}

static void get_pressure_threshold(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char data[3] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = info->fts_get_sysinfo_data(info, FTS_SI_PRESSURE_THRESHOLD, 3, data);
	if (ret <= 0)
		input_err(true, info->dev, "%s: failed to read pressure threshold\n", __func__);

	snprintf(buff, sizeof(buff), "%d", ((data[2] << 8) + data[1]));

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

/* low level is more sensitivity, except level-0(value 0) */
static void set_pressure_user_level(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char data[1] = { 0 };
	unsigned short addr;
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if ((sec->cmd_param[0] < 1) || (sec->cmd_param[0] > 5)) {
		input_err(true, &info->client->dev, "%s: wrong index.\n",
					__func__);
		snprintf(buff, sizeof(buff), "%s", "WRONG INDEX");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	addr = FTS_CMD_STRING_ACCESS + FTS_CMD_OFFSET_PRESSURE_LEVEL;
	data[0] = sec->cmd_param[0];

	ret = info->fts_write_to_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_set_user_level;

	ret = info->fts_read_from_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_set_user_level;

	input_info(true, &info->client->dev, "%s: set user level: %d\n", __func__, data[0]);

	info->pressure_user_level = data[0];

	fts_delay(20);

	addr = FTS_CMD_STRING_ACCESS + FTS_CMD_OFFSET_PRESSURE_THD_HIGH;
	data[0] = 0;
	ret = info->fts_read_from_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_set_user_level;

	input_info(true, &info->client->dev, "%s: HIGH THD: %d\n", __func__, data[0]);

	addr = FTS_CMD_STRING_ACCESS + FTS_CMD_OFFSET_PRESSURE_THD_LOW;
	data[0] = 0;
	ret = info->fts_read_from_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_set_user_level;

	input_info(true, &info->client->dev, "%s: HIGH LOW: %d\n", __func__, data[0]);

	snprintf(buff, sizeof(buff), "OK");

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	return;

out_set_user_level:
	snprintf(buff, sizeof(buff), "FAIL");

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void get_pressure_user_level(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char data[1] = { 0 };
	unsigned short addr;
	int ret;

	sec_cmd_set_default_result(sec);

	data[0] = sec->cmd_param[0];
	addr = FTS_CMD_STRING_ACCESS + FTS_CMD_OFFSET_PRESSURE_LEVEL;

	ret = info->fts_write_to_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_get_user_level;

	ret = info->fts_read_from_string(info, &addr, data, 1);
	if (ret <= 0)
		goto out_get_user_level;

	input_info(true, &info->client->dev, "%s: set user level: %d\n", __func__, data[0]);

	info->pressure_user_level = data[0];

	snprintf(buff, sizeof(buff), "%d", info->pressure_user_level);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	return;

out_get_user_level:
	snprintf(buff, sizeof(buff), "NG");

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

int fts_get_tsp_test_result(struct fts_ts_info *info)
{
	unsigned char *data = NULL;
	int ret;

	data = kzalloc(nvm_data[FACTORY_TEST_RESULT].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	ret = get_nvm_data(info, FACTORY_TEST_RESULT, data);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
			"%s: get failed. ret: %d\n", __func__, ret);
		goto err_read;
	}

	if (data[0] == 0xFF)
		data[0] = 0;
	if (data[1] == 0xFF)
		data[1] = 0;

	info->test_result.data[0] = data[0];
	info->disassemble_count = data[1];

err_read:
	kfree(data);
	return ret;
}
EXPORT_SYMBOL(fts_get_tsp_test_result);

static void get_tsp_test_result(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = fts_get_tsp_test_result(info);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed to get result\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		snprintf(buff, sizeof(buff), "M:%s, M:%d, A:%s, A:%d",
				info->test_result.module_result == 0 ? "NONE" :
				info->test_result.module_result == 1 ? "FAIL" :
				info->test_result.module_result == 2 ? "PASS" : "A",
				info->test_result.module_count,
				info->test_result.assy_result == 0 ? "NONE" :
				info->test_result.assy_result == 1 ? "FAIL" :
				info->test_result.assy_result == 2 ? "PASS" : "A",
				info->test_result.assy_count);

		sec_cmd_set_cmd_result(sec, buff, strlen(buff));
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
}

/* FACTORY TEST RESULT SAVING FUNCTION
 * bit 3 ~ 0 : OCTA Assy
 * bit 7 ~ 4 : OCTA module
 * param[0] : OCTA module(1) / OCTA Assy(2)
 * param[1] : TEST NONE(0) / TEST FAIL(1) / TEST PASS(2) : 2 bit
 */
static int fts_set_tsp_test_result(struct fts_ts_info *info)
{
	unsigned char *data = NULL;
	int ret;

	input_info(true, &info->client->dev, "%s: [0x%X] M:%s, M:%d, A:%s, A:%d\n",
		__func__, info->test_result.data[0],
		info->test_result.module_result == 0 ? "NONE" :
		info->test_result.module_result == 1 ? "FAIL" :
		info->test_result.module_result == 2 ? "PASS" : "A",
		info->test_result.module_count,
		info->test_result.assy_result == 0 ? "NONE" :
		info->test_result.assy_result == 1 ? "FAIL" :
		info->test_result.assy_result == 2 ? "PASS" : "A",
		info->test_result.assy_count);

	data = kzalloc(nvm_data[FACTORY_TEST_RESULT].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	data[0] = info->test_result.data[0];
	data[1] = info->disassemble_count;

	ret = set_nvm_data(info, FACTORY_TEST_RESULT, data);
	if (ret <= 0)
		input_err(true, &info->client->dev,
			"%s: set failed. ret: %d\n", __func__, ret);

	kfree(data);
	return ret;
}

static void set_tsp_test_result(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = fts_get_tsp_test_result(info);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to get_tsp_test_result\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}
	sec->cmd_state = SEC_CMD_STATUS_RUNNING;

	if (info->test_result.data[0] == 0xFF) {
		input_info(true, &info->client->dev,
			"%s: clear factory_result as zero\n",
			__func__);
		info->test_result.data[0] = 0;
	}

	if (sec->cmd_param[0] == TEST_OCTA_ASSAY) {
		info->test_result.assy_result = sec->cmd_param[1];
		if (info->test_result.assy_count < 3)
			info->test_result.assy_count++;

	} else if (sec->cmd_param[0] == TEST_OCTA_MODULE) {
		info->test_result.module_result = sec->cmd_param[1];
		if (info->test_result.module_count < 3)
			info->test_result.module_count++;
	}

	ret = fts_set_tsp_test_result(info);
	if (ret < 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void increase_disassemble_count(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = fts_get_tsp_test_result(info);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: [ERROR] failed to get_tsp_test_result\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		return;
	}
	sec->cmd_state = SEC_CMD_STATUS_RUNNING;

	if (info->disassemble_count < 0xFE)
		info->disassemble_count++;

	ret = fts_set_tsp_test_result(info);
	if (ret < 0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);

}

static void get_disassemble_count(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	int ret;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	ret = fts_get_tsp_test_result(info);
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed to get result\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {

		snprintf(buff, sizeof(buff), "%d", info->disassemble_count);

		sec_cmd_set_cmd_result(sec, buff, strlen(buff));
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
}

int fts_get_tsp_flash_data(struct fts_ts_info *info, int offset, unsigned char cnt, unsigned char* buf)
{
	unsigned char regAdd[3] = {0xB8, 0x00, 0x08};
  	unsigned char data[255] = { 0 };
	unsigned short offset_addr;
	int ret;

	ret = fts_write_reg(info, &regAdd[0], 3);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
			"%s: failed. ret: %d\n", __func__, ret);
		return -EINVAL;
	}

	ret = info->fts_get_sysinfo_data(info, FTS_SI_COMPENSATION_OFFSET_ADDR, 4, data);
	if (ret < 0) {
		input_err(true, &info->client->dev,
			"%s: failed. ret: %d\n", __func__, ret);
		return -EINVAL;
	}

	offset_addr = data[0] + (data[1] << 8);

	regAdd[0] = 0xD0;
	regAdd[1] = (offset_addr >> 8) & 0xFF;
	regAdd[2] = (offset_addr & 0xFF) + offset;

	ret = fts_read_reg(info, &regAdd[0], 3, (unsigned char *)buf, cnt + 1);
	if (ret <= 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n",
			__func__, ret);
		return ret;
	}
	return 0;
}

#ifdef PAT_CONTROL
int fts_set_calibration_information(struct fts_ts_info *info, unsigned char count, unsigned short version)
{
	unsigned char *data = NULL;
	int ret;

	data = kzalloc(nvm_data[CALIBRATION_INFOMATION].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	data[0] = count;
	data[1] = ((version >> 8) & 0xFF);
	data[2] = (version & 0xFF);
	data[3] = 0x00;

	ret = set_nvm_data(info, CALIBRATION_INFOMATION, data);
	if (ret <= 0)
	{
		input_err(true, &info->client->dev,
			"%s: set failed. ret: %d\n", __func__, ret);
	}
	else{
		info->cal_count = data[0];
		info->tune_fix_ver = (unsigned short)((data[1] << 8) | data[2]);
		input_info(true, &info->client->dev,
			"%s: pat count:%X, version:%X\n", __func__, info->cal_count, info->tune_fix_ver);
	}

	kfree(data);
	return ret;
}

int fts_get_calibration_information(struct fts_ts_info *info)
{
	unsigned char *data = NULL;
	int ret;

	data = kzalloc(nvm_data[CALIBRATION_INFOMATION].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	ret = get_nvm_data(info, CALIBRATION_INFOMATION, data);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
			"%s: set failed. ret: %d\n", __func__, ret);
	} else {
		info->cal_count = data[0];
		info->tune_fix_ver = (unsigned short)((data[1] << 8) | data[2]);
		input_info(true, &info->client->dev,
			"%s: pat count:%X, version:%X\n", __func__, info->cal_count, info->tune_fix_ver);
	}

	kfree(data);
	return ret;
}
#endif

int fts_set_factory_debug_information(struct fts_ts_info *info, unsigned char base, unsigned char delta, unsigned char checksum)
{
	unsigned char *data = NULL;
	int ret;

	/* save calibration count */
	data = kzalloc(nvm_data[SEC_FACTORY_DEBUG].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	data[0] = base;
	data[1] = delta;
	data[2] = checksum;
	data[3] = 0x00;

	/* SEC_FACTORY_DEBUG index is 4. refer "fts_nvm_data_type" write command */
	ret = set_nvm_data(info, FTS_FLASH_WRITE_COMMAND_SEC_FACTORY_DEBUG, data);
	if (ret <= 0)
		input_err(true, &info->client->dev,
			"%s: set failed. ret: %d\n", __func__, ret);

	kfree(data);

	return ret;
}

int fts_get_factory_debug_information(struct fts_ts_info *info)
{
	unsigned char *data = NULL;
	int ret;

	data = kzalloc(nvm_data[SEC_FACTORY_DEBUG].length, GFP_KERNEL);
	if (!data) {
		input_err(true, &info->client->dev, "%s: failed to alloc mem\n",
				__func__);
		return -ENOMEM;
	}

	ret = get_nvm_data(info, SEC_FACTORY_DEBUG, data);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
			"%s: set failed. ret: %d\n", __func__, ret);
	} else {
		if (data[0] == 0xFF)
			data[0] = 0x00;
		info->pressure_cal_base = data[0];

		if (data[1] == 0xFF)
			data[1] = 0x00;
		info->pressure_cal_delta = data[1];

		if (data[2] == 0xFF)
			data[2] = 0x00;
		info->nv_crc_fail_count = data[2];

		input_raw_info(true, &info->client->dev,
			"%s: pressure base:%X, delta:%X, crc fail count:%X\n", __func__,
			info->pressure_cal_base, info->pressure_cal_delta,
			info->nv_crc_fail_count);
	}

	kfree(data);
	return ret;
}

int set_nvm_data(struct fts_ts_info *info, unsigned char type, unsigned char *buf)
{
	unsigned char regAdd[256] = { 0 };
	unsigned int length = nvm_data[type].length;
	int ret;

	fts_command(info, SENSEOFF);
	fts_delay(50);
	fts_command(info, FLUSHBUFFER);
	fts_interrupt_set(info, INT_DISABLE);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	regAdd[0] = 0xC7;
	regAdd[1] = type;

	memcpy(&regAdd[2], buf, length);

	ret = fts_write_reg(info, regAdd, length + 2);
	if (ret < 0) {
		input_err(true, &info->client->dev,
			"%s: failed. ret: %d\n", __func__, ret);
		return ret;
	}

	fts_command(info, FTS_CMD_SAVE_CX_TUNING);
	fts_delay(230);
	fts_fw_wait_for_event(info, STATUS_EVENT_FLASH_WRITE_CXTUNE_VALUE);

	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);
	return ret;

}

int get_nvm_data(struct fts_ts_info *info, int type, unsigned char *nvdata)
{
	unsigned char regAdd[3] = {0xB8, 0x00, 0x08};
	unsigned char r_data[8] = { 0 };
  	unsigned char data[33] = { 0 };
	int size = 0, length = 0;
	int ret;

	size = sizeof(nvm_data) / sizeof(struct fts_nvm_data_map);
	if (type >= size)
		return -EINVAL;

	length = nvm_data[type].length + 1;

	fts_command(info, SENSEOFF);
	fts_delay(30);
	fts_interrupt_set(info, INT_DISABLE);
	fts_command(info, FLUSHBUFFER);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	ret = fts_write_reg(info, &regAdd[0], 3);
	if (ret <= 0) {
		input_err(true, &info->client->dev,
			"%s: write failed. ret: %d\n", __func__, ret);
		goto err_mode;
	}
	fts_fw_wait_for_specific_event(info, EVENTID_STATUS_REQUEST_COMP, regAdd[1], regAdd[2]);

	ret = info->fts_get_sysinfo_data(info, FTS_SI_COMPENSATION_OFFSET_ADDR, 7, r_data);
	if (ret < 0) {
		input_err(true, &info->client->dev,
			"%s: get failed. ret: %d\n", __func__, ret);
		goto err_mode;
	}

	input_info(true, &info->client->dev, "%s: 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
		__func__, r_data[0], r_data[1], r_data[2], r_data[3], r_data[4], r_data[5], r_data[6], r_data[7]);

	regAdd[0] = 0xD0;
	regAdd[1] = r_data[1];
	regAdd[2] = r_data[0];

	regAdd[2] += (FTS_FLASH_DATA_OFFSET_BASE + nvm_data[type].offset);

	ret = fts_read_reg(info, &regAdd[0], 3, data, length);
	if (ret < 0) {
		input_err(true, &info->client->dev,
			"%s: read failed. ret: %d\n", __func__, ret);
		goto err_mode;
	}

	input_raw_info(true, &info->client->dev, "%s: [%d][%d] (0x%02X), 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
		__func__, type, nvm_data[type].length, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);

	memcpy(nvdata, &data[1], nvm_data[type].length);

err_mode:
	fts_command(info, FLUSHBUFFER);
	fts_delay(10);
	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif
	fts_interrupt_set(info, INT_ENABLE);

	return ret;
}

#ifdef FTS_SUPPORT_HOVER
static void hover_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped || !(info->reinit_done) || (info->fts_power_state != FTS_POWER_STATE_ACTIVE)) {
		input_err(true, &info->client->dev,
			"%s: [ERROR] Touch is stopped:%d, reinit_done:%d, power_state:%d\n",
			__func__, info->touch_stopped, info->reinit_done, info->fts_power_state);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;

		if(sec->cmd_param[0]==1){
			info->retry_hover_enable_after_wakeup = 1;
			input_info(true, &info->client->dev, "%s: retry_hover_on_after_wakeup\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}

		goto out;
	}

<<<<<<< HEAD
	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		int enables;
		enables = info->cmd_param[0];
		if (enables == info->hover_enabled) {
			tsp_debug_dbg(true, &info->client->dev,
=======
	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		int enables;
		enables = sec->cmd_param[0];
		if (enables == info->hover_enabled) {
			input_dbg(true, &info->client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				"%s: Skip duplicate command. Hover is already %s.\n",
				__func__, info->hover_enabled ? "enabled" : "disabled");
		} else {
			if (enables) {
				unsigned char regAdd[4] = {0xB0, 0x01, 0x29, 0x41};
				unsigned char Dly_regAdd[4] = {0xB0, 0x01, 0x72, 0x04};
				fts_write_reg(info, &Dly_regAdd[0], 4);
				fts_write_reg(info, &regAdd[0], 4);
				fts_command(info, FTS_CMD_HOVER_ON);
				info->hover_enabled = true;
				info->hover_ready = false;
			} else {
				unsigned char Dly_regAdd[4] = {0xB0, 0x01, 0x72, 0x08};
				fts_write_reg(info, &Dly_regAdd[0], 4);
				fts_command(info, FTS_CMD_HOVER_OFF);
				info->hover_enabled = false;
				info->hover_ready = false;
			}
		}
		snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

out:
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;

out:
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

/* static void hover_no_sleep_enable(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned char regAdd[4] = {0xB0, 0x01, 0x18, 0x00};
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0]) {
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	unsigned char regAdd[4] = {0xB0, 0x01, 0x18, 0x00};
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		if (sec->cmd_param[0]) {
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			regAdd[3]=0x0F;
		} else {
			regAdd[3]=0x08;
		}
		fts_write_reg(info, &regAdd[0], 4);

		snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
} */

static void glove_mode(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		info->mshover_enabled = info->cmd_param[0];

		if (!info->touch_stopped && info->reinit_done) {
			if (info->mshover_enabled)
				fts_command(info, FTS_CMD_MSHOVER_ON);
			else
				fts_command(info, FTS_CMD_MSHOVER_OFF);
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
} */
#endif

#ifdef CONFIG_GLOVE_TOUCH
static void glove_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		info->glove_enabled = sec->cmd_param[0];

		if (!info->touch_stopped && info->reinit_done) {
			if (info->glove_enabled)
				fts_command(info, FTS_CMD_GLOVE_ON);
			else
				fts_command(info, FTS_CMD_GLOVE_OFF);
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void get_glove_sensitivity(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	unsigned char cmd[4] =
		{ 0xB2, 0x01, 0xC6, 0x02 };
	int timeout=0;

<<<<<<< HEAD
	set_default_result(info);

	if (info->touch_stopped) {
		char buff[CMD_STR_LEN] = { 0 };
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
=======
	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		char buff[SEC_CMD_STR_LEN] = { 0 };
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return;
	}

	fts_write_reg(info, &cmd[0], 4);
<<<<<<< HEAD
	info->cmd_state = CMD_STATUS_RUNNING;

	while (info->cmd_state == CMD_STATUS_RUNNING) {
		if (timeout++>30) {
			info->cmd_state = CMD_STATUS_FAIL;
=======
	sec->cmd_state = SEC_CMD_STATUS_RUNNING;

	while (sec->cmd_state == SEC_CMD_STATUS_RUNNING) {
		if (timeout++>30) {
			sec->cmd_state = SEC_CMD_STATUS_FAIL;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			break;
		}
		msleep(10);
	}
}

<<<<<<< HEAD
static void clear_cover_mode(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 3) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0] > 1) {
			info->flip_enable = true;
			info->cover_type = info->cmd_param[1];
		} else {
			info->flip_enable = false;
		}

		if (!info->touch_stopped && info->reinit_done) {
			if (info->flip_enable) {
				if (info->mshover_enabled
					&& (strncmp(info->board->project_name, "TB", 2) != 0))
					fts_command(info, FTS_CMD_MSHOVER_OFF);

				fts_set_cover_type(info, true);
			} else {
				fts_set_cover_type(info, false);

				if (info->fast_mshover_enabled)
					fts_command(info, FTS_CMD_SET_FAST_GLOVE_MODE);
				else if (info->mshover_enabled)
					fts_command(info, FTS_CMD_MSHOVER_ON);
			}
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};

static void fast_glove_mode(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		info->fast_mshover_enabled = info->cmd_param[0];

		if (!info->touch_stopped && info->reinit_done) {
			if (info->fast_mshover_enabled)
				fts_command(info, FTS_CMD_SET_FAST_GLOVE_MODE);
			else
				fts_command(info, FTS_CMD_SET_NOR_GLOVE_MODE);
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
static void fast_glove_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		info->fast_glove_enabled = sec->cmd_param[0];

		if (!info->touch_stopped && info->reinit_done) {
			if (info->fast_glove_enabled)
				fts_command(info, FTS_CMD_SET_FAST_GLOVE_MODE);
			else
				fts_command(info, FTS_CMD_SET_NOR_GLOVE_MODE);
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};
#endif

static void clear_cover_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 3) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		if (sec->cmd_param[0] > 1) {
			info->flip_enable = true;
			info->cover_type = sec->cmd_param[1];
#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
			if (TRUSTEDUI_MODE_TUI_SESSION & trustedui_get_current_mode()) {
				fts_delay(500);
				tui_force_close(1);
				fts_delay(200);
				if (TRUSTEDUI_MODE_TUI_SESSION & trustedui_get_current_mode()) {
					trustedui_clear_mask(TRUSTEDUI_MODE_VIDEO_SECURED|TRUSTEDUI_MODE_INPUT_SECURED);
					trustedui_set_mode(TRUSTEDUI_MODE_OFF);
				}
			}

			tui_cover_mode_set(true);
#endif			
		} else {
			info->flip_enable = false;
#ifdef CONFIG_TRUSTONIC_TRUSTED_UI
			tui_cover_mode_set(false);
#endif
		}

		if (!info->touch_stopped && info->reinit_done) {
			if (info->flip_enable) {
#ifdef CONFIG_GLOVE_TOUCH
				if (info->glove_enabled
					&& (strncmp(info->board->project_name, "TB", 2) != 0))
					fts_command(info, FTS_CMD_GLOVE_OFF);
#endif
				fts_set_cover_type(info, true);
			} else {
				fts_set_cover_type(info, false);
#ifdef CONFIG_GLOVE_TOUCH
				if (info->fast_glove_enabled)
					fts_command(info, FTS_CMD_SET_FAST_GLOVE_MODE);
				else if (info->glove_enabled)
					fts_command(info, FTS_CMD_GLOVE_ON);
#endif
			}
		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
};

static void report_rate(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 2) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0] == REPORT_RATE_90HZ)
			fts_change_scan_rate(info, FTS_CMD_FAST_SCAN);
		else if (info->cmd_param[0] == REPORT_RATE_60HZ)
			fts_change_scan_rate(info, FTS_CMD_SLOW_SCAN);
		else if (info->cmd_param[0] == REPORT_RATE_30HZ)
			fts_change_scan_rate(info, FTS_CMD_USLOW_SCAN);

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

out:
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 2) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		if (sec->cmd_param[0] == REPORT_RATE_90HZ)
			fts_change_scan_rate(info, FTS_CMD_FAST_SCAN);
		else if (sec->cmd_param[0] == REPORT_RATE_60HZ)
			fts_change_scan_rate(info, FTS_CMD_SLOW_SCAN);
		else if (sec->cmd_param[0] == REPORT_RATE_30HZ)
			fts_change_scan_rate(info, FTS_CMD_USLOW_SCAN);

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;

out:
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
static void interrupt_control(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		int enables;
		enables = info->cmd_param[0];
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		int enables;
		enables = sec->cmd_param[0];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		if (enables)
			fts_irq_enable(info, true);
		else
			fts_irq_enable(info, false);

		snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

out:
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

#if defined(CONFIG_INPUT_BOOSTER)
static void boost_level(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char max_level = 4;

#ifdef CONFIG_INPUT_BOOSTER
	max_level = BOOSTER_LEVEL_MAX;
#endif

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] >= max_level) {
		snprintf(buff, sizeof(buff), "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
#ifdef CONFIG_INPUT_BOOSTER
		change_booster_level_for_tsp(info->cmd_param[0]);
#endif
		tsp_debug_dbg(false, &info->client->dev,
						"%s %d\n",
						__func__, info->cmd_param[0]);

		snprintf(buff, sizeof(buff), "OK");
		info->cmd_state = CMD_STATUS_OK;
	}

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
	info->cmd_state = CMD_STATUS_WAITING;

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	return;
}
#endif

bool check_lowpower_mode(struct fts_ts_info *info)
{
	bool ret = 0;
	unsigned char flag = info->lowpower_flag & 0xFF;

	if (flag)
		ret = 1;

	tsp_debug_info(true, &info->client->dev,
		"%s: lowpower_mode flag : %d, ret:%d\n", __func__, flag, ret);

	if (flag & FTS_LOWP_FLAG_QUICK_CAM)
		tsp_debug_info(true, &info->client->dev, "%s: quick cam *- on\n", __func__);
	if (flag & FTS_LOWP_FLAG_2ND_SCREEN)
		tsp_debug_info(true, &info->client->dev, "%s: 2nd screen on\n", __func__);
	if (flag & FTS_LOWP_FLAG_BLACK_UI)
		tsp_debug_info(true, &info->client->dev, "%s: swipe finger on\n", __func__);
	if (flag & FTS_LOWP_FLAG_QUICK_APP_ACCESS)
		tsp_debug_info(true, &info->client->dev, "%s: quick app cmd on\n", __func__);
	if (flag & FTS_LOWP_FLAG_DIRECT_INDICATOR)
		tsp_debug_info(true, &info->client->dev, "%s: direct indicator cmd on\n", __func__);
	if (flag & FTS_LOWP_FLAG_SPAY)
		tsp_debug_info(true, &info->client->dev, "%s: spay cmd on\n", __func__);
	if (flag & FTS_LOWP_FLAG_TEMP_CMD)
		tsp_debug_info(true, &info->client->dev, "%s: known cmd on\n", __func__);

	return ret;

}

static void set_lowpower_mode(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
	        snprintf(buff, sizeof(buff), "%s", "NG");
	        info->cmd_state = CMD_STATUS_FAIL;
	} else {
#ifdef FTS_SUPPORT_SIDE_GESTURE
		if (info->board->support_sidegesture)
			info->lowpower_mode = info->cmd_param[0];
#endif
		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};

static void set_deepsleep_mode(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		info->deepsleep_mode = info->cmd_param[0];

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};

static void active_sleep_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
	/* To do here */
		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};


static void second_screen_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
	        snprintf(buff, sizeof(buff), "%s", "NG");
	        info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if(info->cmd_param[0])
			info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_2ND_SCREEN;
		else
			info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_2ND_SCREEN);

#ifdef FTS_SUPPORT_SIDE_GESTURE
		if (info->board->support_sidegesture)
			info->lowpower_mode = check_lowpower_mode(info);
#endif

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_longpress_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char regAdd[4] = {0xB0, 0x07, 0x10, 0x03};
	int ret;
	int bflag = 0;

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0])
			bflag = 1;
		else
			bflag = 0;

		if (bflag)
			regAdd[3] = 0x03;
		else
			regAdd[3] = 0x02;

		ret = fts_write_reg(info, regAdd, 4);

		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s failed. ret: %d\n", __func__, ret);
		else
			tsp_debug_info(true, &info->client->dev, "%s: on/off:%d, ret: %d\n", __func__, bflag, ret);

		fts_delay(1);

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_sidescreen_x_length(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	/* TB Side screen area length  */
	unsigned char regAdd[4] = {0xB0, 0x07, 0x1C, 0xA0}; //default Side screen x length setting
	int ret;

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 0xA0) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		regAdd[3] = info->cmd_param[0]; // Change Side screen x length

		ret = fts_write_reg(info, regAdd, 4);
		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s failed. ret: %d\n", __func__, ret);
		else
			tsp_debug_info(true, &info->client->dev, "%s: x length:%d, ret: %d\n", __func__, regAdd[3], ret);
		fts_delay(1);

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;

out:
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

static void set_wirelesscharger_mode(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		info->wirelesscharger_mode = sec->cmd_param[0];

		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		info->wirelesscharger_mode = sec->cmd_param[0];

		fts_wirelesscharger_mode(info);

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_WAITING;

out:
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};

/* ######################################################
    flag     1  :  set edge handler
              2  :  set (portrait, normal) edge zone data
              4  :  set (portrait, normal) dead zone data
              8  :  set landscape mode data
              16 :  mode clear
    data
              0x30, FFF (y start), FFF (y end),  FF(direction)
              0x31, FFFF (edge zone)
              0x32, FF (up x), FF (down x), FFFF (y)
              0x33, FF (mode), FFF (edge), FFF (dead zone)
    case
           edge handler set :  0x30....
           booting time :  0x30...  + 0x31...
           normal mode : 0x32...  (+0x31...)
           landscape mode : 0x33...
           landscape -> normal (if same with old data) : 0x33, 0
           landscape -> normal (etc) : 0x32....  + 0x33, 0
    ###################################################### */

void fts_set_grip_data_to_ic(struct fts_ts_info *info, u8 flag){
	u8 data[4] = { 0 };
	u8 regAdd[6] = {0xC6, 0x00, 0x00, 0x00, 0x00, 0x00};

	input_info(true, &info->client->dev, "%s: flag: %02X (clr,lan,nor,edg,han)\n", __func__, flag);

	if (flag & G_SET_EDGE_HANDLER) {
		if (info->grip_edgehandler_direction == 0) {
			data[0] = 0x0;
			data[1] = 0x0;
			data[2] = 0x0;
			data[3] = 0x0;
		} else {
			data[0] = (info->grip_edgehandler_start_y >> 4) & 0xFF;
			data[1] = (info->grip_edgehandler_start_y << 4 & 0xF0) | ((info->grip_edgehandler_end_y >> 8) & 0xF);
			data[2] = info->grip_edgehandler_end_y & 0xFF;
			data[3] = info->grip_edgehandler_direction & 0x3;
		}

		regAdd[1] = FTS_CMD_EDGE_HANDLER;
		regAdd[2] = data[0];
		regAdd[3] = data[1];
		regAdd[4] = data[2];
		regAdd[5] = data[3];

		fts_write_reg(info, regAdd, 6);
		input_info(true, &info->client->dev, "%s: 0x%02X %02X,%02X,%02X,%02X\n",
			__func__, FTS_CMD_EDGE_HANDLER, data[0], data[1], data[2], data[3]);
	}

	if (flag & G_SET_EDGE_ZONE) {
		data[0] = (info->grip_edge_range >> 8) & 0xFF;
		data[1] = info->grip_edge_range  & 0xFF;

		regAdd[1] = FTS_CMD_EDGE_AREA;
		regAdd[2] = data[0];
		regAdd[3] = data[1];

		fts_write_reg(info, regAdd, 4);
		input_info(true, &info->client->dev, "%s: 0x%02X %02X,%02X\n",
			__func__, FTS_CMD_EDGE_AREA, data[0], data[1]);
	}

	if (flag & G_SET_NORMAL_MODE) {
		data[0] = info->grip_deadzone_up_x & 0xFF;
		data[1] = info->grip_deadzone_dn_x & 0xFF;
		data[2] = (info->grip_deadzone_y >> 8) & 0xFF;
		data[3] = info->grip_deadzone_y & 0xFF;

		regAdd[1] = FTS_CMD_DEAD_ZONE;
		regAdd[2] = data[0];
		regAdd[3] = data[1];
		regAdd[4] = data[2];
		regAdd[5] = data[3];

		fts_write_reg(info, regAdd, 6);
		input_info(true, &info->client->dev, "%s: 0x%02X %02X,%02X,%02X,%02X\n",
			__func__, FTS_CMD_DEAD_ZONE, data[0], data[1], data[2], data[3]);
	}

	if (flag & G_SET_LANDSCAPE_MODE) {
		data[0] = info->grip_landscape_mode & 0x1;
		data[1] = (info->grip_landscape_edge >> 4) & 0xFF;
		data[2] = (info->grip_landscape_edge << 4 & 0xF0) | ((info->grip_landscape_deadzone >> 8) & 0xF);
		data[3] = info->grip_landscape_deadzone & 0xFF;

		regAdd[1] = FTS_CMD_LANDSCAPE_MODE;
		regAdd[2] = data[0];
		regAdd[3] = data[1];
		regAdd[4] = data[2];
		regAdd[5] = data[3];

		fts_write_reg(info, regAdd, 6);
		input_info(true, &info->client->dev, "%s: 0x%02X %02X,%02X,%02X,%02X\n",
			__func__, FTS_CMD_LANDSCAPE_MODE, data[0], data[1], data[2], data[3]);
	}

	if (flag & G_CLR_LANDSCAPE_MODE) {
		data[0] = info->grip_landscape_mode;

		regAdd[1] = FTS_CMD_LANDSCAPE_MODE;
		regAdd[2] = data[0];

		fts_write_reg(info, regAdd, 3);
		input_info(true, &info->client->dev, "%s: 0x%02X %02X\n",
			__func__, FTS_CMD_LANDSCAPE_MODE, data[0]);
	}
}

/* ######################################################
    index  0 :  set edge handler
              1 :  portrait (normal) mode
              2 :  landscape mode
    data
              0, X (direction), X (y start), X (y end)
                     direction : 0 (off), 1 (left), 2 (right)
                     ex) echo set_grip_data,0,2,600,900 > cmd

              1, X (edge zone), X (dead zone up x), X (dead zone down x), X (dead zone y)
                     ex) echo set_grip_data,1,200,10,50,1500 > cmd

              2, 1 (landscape mode), X (edge zone), X (dead zone)
                     ex) echo set_grip_data,2,1,200,100 > cmd

              2, 0 (portrait mode)
                     ex) echo set_grip_data,2,0  > cmd
###################################################### */

static void set_grip_data(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	u8 mode = G_NONE;

	sec_cmd_set_default_result(sec);

	memset(buff, 0, sizeof(buff));

	mutex_lock(&info->device_mutex);

	if (sec->cmd_param[0] == 0) {	// edge handler
		if (sec->cmd_param[1] == 0) {	// clear
			info->grip_edgehandler_direction = 0;
		} else if (sec->cmd_param[1] < 3) {
			info->grip_edgehandler_direction = sec->cmd_param[1];
			info->grip_edgehandler_start_y = sec->cmd_param[2];
			info->grip_edgehandler_end_y = sec->cmd_param[3];
		} else {
			input_err(true, &info->client->dev, "%s: cmd1 is abnormal, %d (%d)\n",
				__func__,sec->cmd_param[1], __LINE__);
			goto err_grip_data;
		}

		mode = mode | G_SET_EDGE_HANDLER;
		fts_set_grip_data_to_ic(info, mode);
	} else if (sec->cmd_param[0] == 1) {	// normal mode
		if (info->grip_edge_range != sec->cmd_param[1])
			mode = mode | G_SET_EDGE_ZONE;

		info->grip_edge_range = sec->cmd_param[1];
		info->grip_deadzone_up_x = sec->cmd_param[2];
		info->grip_deadzone_dn_x = sec->cmd_param[3];
		info->grip_deadzone_y = sec->cmd_param[4];
		mode = mode | G_SET_NORMAL_MODE;

		if (info->grip_landscape_mode == 1) {
			info->grip_landscape_mode = 0;
			mode = mode | G_CLR_LANDSCAPE_MODE;
		}

		fts_set_grip_data_to_ic(info, mode);
	} else if (sec->cmd_param[0] == 2) {	// landscape mode
		if (sec->cmd_param[1] == 0) { 	// normal mode
			info->grip_landscape_mode = 0;
			mode = mode | G_CLR_LANDSCAPE_MODE;
		} else if (sec->cmd_param[1] == 1) {
			info->grip_landscape_mode = 1;
			info->grip_landscape_edge = sec->cmd_param[2];
			info->grip_landscape_deadzone = sec->cmd_param[3];
			mode = mode | G_SET_LANDSCAPE_MODE;
		} else {
			input_err(true, &info->client->dev, "%s: cmd1 is abnormal, %d (%d)\n",
				__func__,sec->cmd_param[1], __LINE__);
			goto err_grip_data;
		}

		fts_set_grip_data_to_ic(info, mode);
	} else {
		input_err(true, &info->client->dev, "%s: cmd0 is abnormal, %d", __func__,sec->cmd_param[0]);
		goto err_grip_data;
	}

	mutex_unlock(&info->device_mutex);

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
	return;

err_grip_data:
	mutex_unlock(&info->device_mutex);

	snprintf(buff, sizeof(buff), "%s", "NG");
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
	return;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void set_dead_zone(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	unsigned char regAdd[2] = {0xC4, 0x00};
	int ret;

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 6) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0]==1)
			regAdd[1] = 0x01;	/* side edge top */
		else if (info->cmd_param[0]==2)
			regAdd[1] = 0x02;	/* side edge bottom */
		else if (info->cmd_param[0]==3)
			regAdd[1] = 0x03;	/* side edge All On */
		else if (info->cmd_param[0]==4)
			regAdd[1] = 0x04;	/* side edge Left Off */
		else if (info->cmd_param[0]==5)
			regAdd[1] = 0x05;	/* side edge Right Off */
		else if (info->cmd_param[0]==6)
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[2] = {0xC4, 0x00};
	int ret;

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 6) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		if (sec->cmd_param[0]==1)
			regAdd[1] = 0x01;	/* side edge top */
		else if (sec->cmd_param[0]==2)
			regAdd[1] = 0x02;	/* side edge bottom */
		else if (sec->cmd_param[0]==3)
			regAdd[1] = 0x03;	/* side edge All On */
		else if (sec->cmd_param[0]==4)
			regAdd[1] = 0x04;	/* side edge Left Off */
		else if (sec->cmd_param[0]==5)
			regAdd[1] = 0x05;	/* side edge Right Off */
		else if (sec->cmd_param[0]==6)
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			regAdd[1] = 0x06;	/* side edge All Off */
		else
			regAdd[1] = 0x0;	/* none	*/

<<<<<<< HEAD
		ret = fts_write_reg(info, regAdd, 2);

		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s failed. ret: %d\n", __func__, ret);
		else
			tsp_debug_info(true, &info->client->dev, "%s: reg:%d, ret: %d\n", __func__, info->cmd_param[0], ret);

		fts_delay(1);

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_mainscreen_disable_cmd(struct fts_ts_info *info, bool on)
{
	int ret;
	unsigned char regAdd[2] = {0xC2, 0x07};

	if (on){
		regAdd[0] = 0xC1;				// main screen disable
		info->mainscr_disable = true;
	}else{
		regAdd[0] = 0xC2;				// enable like normal
		info->mainscr_disable = false;
	}

	ret = fts_write_reg(info, regAdd, 2);

	if (ret < 0)
		tsp_debug_err(true, &info->client->dev, "%s failed. ret: %d\n", __func__, ret);
	else
		tsp_debug_info(true, &info->client->dev, "%s: reg:%d, ret: %d\n", __func__, info->cmd_param[0], ret);
	fts_delay(1);
}

static void set_mainscreen_disable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 2) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		if (info->cmd_param[0]==1){
			set_mainscreen_disable_cmd(info, 1);
		}else{
			set_mainscreen_disable_cmd(info, 0);
		}
		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

#ifdef SMARTCOVER_COVER
void change_smartcover_table(struct fts_ts_info *info)
{
	u8 i, j, k, h, temp, temp_sum;

	for(i=0; i<MAX_BYTE; i++)
		for(j=0; j<MAX_TX; j++)
			info->changed_table[j][i] = info->smart_cover[i][j];

	#if 1 // debug
	tsp_debug_info(true, &info->client->dev, "%s smart_cover value\n", __func__);
	for(i=0; i<MAX_BYTE; i++){
		pr_cont("[fts] ");
		for(j=0; j<MAX_TX; j++)
			pr_cont("%d ",info->smart_cover[i][j]);
		pr_cont("\n");
	}

	tsp_debug_info(true, &info->client->dev, "%s changed_table value\n", __func__);
	for(j=0; j<MAX_TX; j++){
		pr_cont("[fts] ");
		for(i=0; i<MAX_BYTE; i++)
			pr_cont("%d ",info->changed_table[j][i]);
		pr_cont("\n");
	}
	#endif

	tsp_debug_info(true, &info->client->dev, "%s %d\n", __func__, __LINE__);

	for(i=0; i<MAX_TX; i++)
		for(j=0; j<4; j++)
			info->send_table[i][j] = 0;
		tsp_debug_info(true, &info->client->dev, "%s %d\n", __func__, __LINE__);

	for(i=0; i<MAX_TX; i++){
		temp = 0;
		for(j=0; j<MAX_BYTE; j++)
			temp += info->changed_table[i][j];
		if(temp == 0 ) continue;

		for(k=0; k<4; k++){
			temp_sum = 0;
			for(h=0; h<8; h++){
				temp_sum += ((u8)(info->changed_table[i][h+8*k])) << (7-h);
			}
			info->send_table[i][k] = temp_sum;
		}

		tsp_debug_info(true, &info->client->dev, "i:%2d, %2X %2X %2X %2X \n", \
			i,info->send_table[i][0],info->send_table[i][1],info->send_table[i][2],info->send_table[i][3]);
	}
	tsp_debug_info(true, &info->client->dev, "%s %d\n", __func__, __LINE__);


}
void set_smartcover_mode(struct fts_ts_info *info, bool on)
{
	int ret;
	unsigned char regMon[2] = {0xC1, 0x0A};
	unsigned char regMoff[2] = {0xC2, 0x0A};

	if(on ==1){
		ret = fts_write_reg(info, regMon, 2);
		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s mode on failed. ret: %d\n", __func__, ret);
	}else{
		ret = fts_write_reg(info, regMoff, 2);
		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s mode off failed. ret: %d\n", __func__, ret);
	}
}
void set_smartcover_clear(struct fts_ts_info *info)
{
	int ret;
	unsigned char regClr[6] = {0xC5, 0xFF, 0x00, 0x00, 0x00, 0x00};

	ret = fts_write_reg(info, regClr, 6);
	if (ret < 0)
		tsp_debug_err(true, &info->client->dev, "%s data clear failed. ret: %d\n", __func__, ret);
}


void set_smartcover_data(struct fts_ts_info *info)
{
	int ret;
	u8 i, j;
	u8 temp=0;
	unsigned char regData[6] = {0xC5, 0x00, 0x00, 0x00, 0x00, 0x00};


	for(i=0; i<MAX_TX; i++){
		temp = 0;
		for(j=0; j<4; j++)
			temp += info->send_table[i][j];
		if(temp == 0 ) continue;

		regData[1] = i;

		for(j=0; j<4; j++)
			regData[2+j] = info->send_table[i][j];

		tsp_debug_info(true, &info->client->dev, "i:%2d, %2X %2X %2X %2X \n", \
			regData[1],regData[2],regData[3],regData[4], regData[5]);

		// data write
		ret = fts_write_reg(info, regData, 6);
		if (ret < 0)
			tsp_debug_err(true, &info->client->dev, "%s data write[%d] failed. ret: %d\n", __func__,i, ret);


	}

}

/* ####################################################
	func : smartcover_cmd [0] [1] [2] [3]
	index 0
		vlaue 0 : off (normal)
		vlaue 1 : off (globe mode)
		vlaue 2 :  X
		vlaue 3 : on
				clear -> data send(send_table value) ->  mode on
		vlaue 4 : clear smart_cover value
		vlaue 5 : data save to smart_cover value
			index 1 : tx channel num
			index 2 : data 0xFF
			index 3 : data 0xFF
		value 6 : table value change, smart_cover -> changed_table -> send_table

	ex)
	// clear
	echo smartcover_cmd,4 > cmd
	// data write (hart)
	echo smartcover_cmd,5,3,16,16 > cmd
	echo smartcover_cmd,5,4,56,56 > cmd
	echo smartcover_cmd,5,5,124,124 > cmd
	echo smartcover_cmd,5,6,126,252 > cmd
	echo smartcover_cmd,5,7,127,252 > cmd
	echo smartcover_cmd,5,8,63,248 > cmd
	echo smartcover_cmd,5,9,31,240 > cmd
	echo smartcover_cmd,5,10,15,224 > cmd
	echo smartcover_cmd,5,11,7,192 > cmd
	echo smartcover_cmd,5,12,3,128 > cmd
	// data change
	echo smartcover_cmd,6 > cmd
	// mode on
	echo smartcover_cmd,3 > cmd

###################################################### */

void smartcover_cmd(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };
	u8 i, j, t;

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 6) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {

		if(info->cmd_param[0]==0){			// off

			set_smartcover_mode(info, 0);
			tsp_debug_info(true, &info->client->dev, "%s mode off, normal\n", __func__);

		} else if(info->cmd_param[0]==1){	// off, globe mode

			set_smartcover_mode(info, 0);
			tsp_debug_info(true, &info->client->dev, "%s mode off, globe mode\n", __func__);

			if (info->fast_mshover_enabled)
				fts_command(info, FTS_CMD_SET_FAST_GLOVE_MODE);
			else if (info->mshover_enabled)
				fts_command(info, FTS_CMD_MSHOVER_ON);

		} else if(info->cmd_param[0]==3){	// on

			set_smartcover_clear(info);
			set_smartcover_data(info);
			tsp_debug_info(true, &info->client->dev, "%s data send\n", __func__);
			set_smartcover_mode(info, 1);
			tsp_debug_info(true, &info->client->dev, "%s mode on\n", __func__);

		} else if(info->cmd_param[0]==4){	// clear

			for(i=0; i<MAX_BYTE; i++)
				for(j=0; j<MAX_TX; j++)
					info->smart_cover[i][j] = 0;
			tsp_debug_info(true, &info->client->dev, "%s data clear\n", __func__);

		} else if(info->cmd_param[0]==5){	// data write

			if(info->cmd_param[1]<0 ||  info->cmd_param[1]>= 32){
				tsp_debug_info(true, &info->client->dev, "%s data tx size is over[%d]\n", \
					__func__,info->cmd_param[1]);
				snprintf(buff, sizeof(buff), "%s", "NG");
				info->cmd_state = CMD_STATUS_FAIL;
				goto fail;
			}
			tsp_debug_info(true, &info->client->dev, "%s data %2X, %2X, %2X\n", __func__, \
				info->cmd_param[1],info->cmd_param[2],info->cmd_param[3] );

			t = info->cmd_param[1];
			info->smart_cover[t][0] = (info->cmd_param[2]&0x80)>>7;
			info->smart_cover[t][1] = (info->cmd_param[2]&0x40)>>6;
			info->smart_cover[t][2] = (info->cmd_param[2]&0x20)>>5;
			info->smart_cover[t][3] = (info->cmd_param[2]&0x10)>>4;
			info->smart_cover[t][4] = (info->cmd_param[2]&0x08)>>3;
			info->smart_cover[t][5] = (info->cmd_param[2]&0x04)>>2;
			info->smart_cover[t][6] = (info->cmd_param[2]&0x02)>>1;
			info->smart_cover[t][7] = (info->cmd_param[2]&0x01);
			info->smart_cover[t][8] = (info->cmd_param[3]&0x80)>>7;
			info->smart_cover[t][9] = (info->cmd_param[3]&0x40)>>6;
			info->smart_cover[t][10] = (info->cmd_param[3]&0x20)>>5;
			info->smart_cover[t][11] = (info->cmd_param[3]&0x10)>>4;
			info->smart_cover[t][12] = (info->cmd_param[3]&0x08)>>3;
			info->smart_cover[t][13] = (info->cmd_param[3]&0x04)>>2;
			info->smart_cover[t][14] = (info->cmd_param[3]&0x02)>>1;
			info->smart_cover[t][15] = (info->cmd_param[3]&0x01);

		} else if(info->cmd_param[0]==6){	// data change

			change_smartcover_table(info);
			tsp_debug_info(true, &info->client->dev, "%s data change\n", __func__);

		} else {

			tsp_debug_info(true, &info->client->dev, "%s cmd[%d] not use\n", __func__, info->cmd_param[0] );
			snprintf(buff, sizeof(buff), "%s", "NG");
			info->cmd_state = CMD_STATUS_FAIL;
			goto fail;

		}

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
fail:
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
};
#endif

static void set_rotation_status(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->cmd_param[0] < 0 || info->cmd_param[0] > 3) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
	} else {
		int status = info->cmd_param[0] % 2;

		if (status)
			fts_enable_feature(info, FTS_FEATURE_DUAL_SIDE_GUSTURE, true);
		else
			fts_enable_feature(info, FTS_FEATURE_DUAL_SIDE_GUSTURE, false);

		snprintf(buff, sizeof(buff), "%s", "OK");
		info->cmd_state = CMD_STATUS_OK;
	}
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

#ifdef FTS_SUPPORT_STRINGLIB
static void quick_shot_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	if (info->cmd_param[0]) {
		info->fts_mode |= FTS_MODE_QUICK_SHOT;
		info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_QUICK_CAM;
	} else {
		info->fts_mode &= ~FTS_MODE_QUICK_SHOT;
		info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_QUICK_CAM);
	}

	ret = info->fts_write_to_string(info, &addr, &info->fts_mode, sizeof(info->fts_mode));
	if (ret < 0) {
		dev_err(&info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;
=======
		ret = fts_write_reg(info, regAdd, 2);

		if (ret < 0)
			input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		else
			input_info(true, &info->client->dev, "%s: reg:%d, ret: %d\n", __func__, sec->cmd_param[0], ret);

		fts_delay(1);

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void dead_zone_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[2] = {0xC2, 0x0C};
	int ret;

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		if (sec->cmd_param[0]==0) {
			regAdd[0] = 0xC1;	/* dead zone disable */
		} else {
			regAdd[0] = 0xC2;	/* dead zone enable */
		}

		ret = fts_write_reg(info, regAdd, 2);

		if (ret < 0)
			input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		else
			input_info(true, &info->client->dev, "%s: reg:%d, ret: %d\n", __func__, sec->cmd_param[0], ret);

		fts_delay(1);

		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void drawing_test_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS;
#endif
	int ret = 0;
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (!sec->cmd_param[0]) {
		info->lowpower_flag |= FTS_MODE_PRESSURE;
	} else {
		info->lowpower_flag &= ~FTS_MODE_PRESSURE;
	}

#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, &info->lowpower_flag, sizeof(info->lowpower_flag));
#endif
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;

		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

out:
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void spay_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS;
#endif
	int ret = 0;
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0]) {
		info->lowpower_flag |= FTS_MODE_SPAY;
	} else {
		info->lowpower_flag &= ~FTS_MODE_SPAY;
	}

#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, &info->lowpower_flag, sizeof(info->lowpower_flag));
#endif
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;

		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

out:
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void aod_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS;
#endif
	int ret = 0;
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0]) {
		info->lowpower_flag |= FTS_MODE_AOD;
	} else {
		info->lowpower_flag &= ~FTS_MODE_AOD;
	}

#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, &info->lowpower_flag, sizeof(info->lowpower_flag));
#endif
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
	info->cmd_state = CMD_STATUS_OK;

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

out:
	info->lowpower_mode = check_lowpower_mode(info);
	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void scrub_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
	char buff[CMD_STR_LEN] = { 0 };

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);

		snprintf(buff, sizeof(buff), "%s", "TSP turned off");

		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	set_default_result(info);

	if (info->cmd_param[0]) {
		info->fts_mode |= FTS_MODE_SCRUB;
		info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_BLACK_UI;

	} else {
		info->fts_mode &= ~FTS_MODE_SCRUB;
		info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_BLACK_UI);
	}

	ret = info->fts_write_to_string(info, &addr, &info->fts_mode, sizeof(info->fts_mode));
	if (ret < 0) {
		dev_err(&info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;

		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
	info->cmd_state = CMD_STATUS_OK;

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

out:
	info->lowpower_mode = check_lowpower_mode(info);

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void quick_app_access_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
	char buff[CMD_STR_LEN] = { 0 };

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);

		snprintf(buff, sizeof(buff), "%s", "TSP turned off");

		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	set_default_result(info);

	if (info->cmd_param[0]) {
		info->fts_mode |= FTS_MODE_QUICK_APP_ACCESS;
		info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_QUICK_APP_ACCESS;

	} else {
		info->fts_mode &= ~FTS_MODE_QUICK_APP_ACCESS;
		info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_QUICK_APP_ACCESS);
	}

	ret = info->fts_write_to_string(info, &addr, &info->fts_mode, sizeof(info->fts_mode));
	if (ret < 0) {
		dev_err(&info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;

		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
	info->cmd_state = CMD_STATUS_OK;

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

out:
	info->lowpower_mode = check_lowpower_mode(info);

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void direct_indicator_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
	char buff[CMD_STR_LEN] = { 0 };

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);

		snprintf(buff, sizeof(buff), "%s", "TSP turned off");

		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	set_default_result(info);

	if (info->cmd_param[0]) {
		info->fts_mode |= FTS_MODE_DIRECT_INDICATOR;
		info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_DIRECT_INDICATOR;

	} else {
		info->fts_mode &= ~FTS_MODE_DIRECT_INDICATOR;
		info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_DIRECT_INDICATOR);
	}

	ret = info->fts_write_to_string(info, &addr, &info->fts_mode, sizeof(info->fts_mode));
	if (ret < 0) {
		dev_err(&info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;

=======
	sec->cmd_state = SEC_CMD_STATUS_OK;

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

out:
	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_aod_rect(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	u8 data[8] = {0, };
	int i, ret = -1;
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS + 2;
#endif

	sec_cmd_set_default_result(sec);

#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
	input_info(true, &info->client->dev, "%s: w:%d, h:%d, x:%d, y:%d\n",
			__func__, sec->cmd_param[0], sec->cmd_param[1],
			sec->cmd_param[2], sec->cmd_param[3]);
#endif

	for (i = 0; i < 4; i++) {
		data[i * 2] = sec->cmd_param[i] & 0xFF;
		data[i * 2 + 1] = (sec->cmd_param[i] >> 8) & 0xFF;
		info->rect_data[i] = sec->cmd_param[i];
	}

	disable_irq(info->client->irq);
#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_write_to_string(info, &addr, data, sizeof(data));
#endif
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		goto NG;
	}

	enable_irq(info->client->irq);

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
	return;
NG:
	enable_irq(info->client->irq);
	snprintf(buff, sizeof(buff), "%s", "NG");
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
}

static void get_aod_rect(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	u8 data[8] = {0, };
	u16 rect_data[4] = {0, };
	int i, ret = -1;
#ifdef FTS_SUPPORT_STRINGLIB
	unsigned short addr = FTS_CMD_STRING_ACCESS + 2;
#endif

	sec_cmd_set_default_result(sec);

	disable_irq(info->client->irq);
#ifdef FTS_SUPPORT_STRINGLIB
	ret = info->fts_read_from_string(info, &addr, data, sizeof(data));
#endif
	if (ret < 0) {
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		goto NG;
	}

	enable_irq(info->client->irq);

	for (i = 0; i < 4; i++)
		rect_data[i] = (data[i * 2 + 1] & 0xFF) << 8 | (data[i * 2] & 0xFF);

#if !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
	input_info(true, &info->client->dev, "%s: w:%d, h:%d, x:%d, y:%d\n",
			__func__, rect_data[0], rect_data[1], rect_data[2], rect_data[3]);
#endif

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
	return;
NG:
	enable_irq(info->client->irq);
	snprintf(buff, sizeof(buff), "%s", "NG");
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);
}

/*
 *  C2 13: Disable dex mode
 *  C1 13 01: Full screen mode
 *  C1 13 02: Iris mode
 */
static void dex_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[3] = {0xC1, 0x13};
	int ret;

	sec_cmd_set_default_result(sec);

	if (!info->board->support_dex) {
		input_err(true, &info->client->dev, "%s: not support DeX mode\n", __func__);
		goto out;
	}

	if ((sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) &&
		(sec->cmd_param[1] < 0 || sec->cmd_param[1] > 1)) {
		input_err(true, &info->client->dev, "%s: not support param\n", __func__);
		goto out;
	}

	info->dex_mode = sec->cmd_param[0];
	if (info->dex_mode) {
		input_err(true, &info->client->dev, "%s: set DeX touch_pad mode%s\n",
			__func__, sec->cmd_param[1] ? " & Iris mode" : "");
		info->input_dev = info->input_dev_pad;
		regAdd[0] = 0xC1;
		if (sec->cmd_param[1]) {
			/* Iris mode */
			info->dex_mode = 0x02;
			info->dex_name = "[DeXI]";
		} else {
			info->dex_name = "[DeX]";
		}
		regAdd[2] = info->dex_mode;
	} else {
		input_err(true, &info->client->dev, "%s: set touch mode\n", __func__);
		info->input_dev = info->input_dev_touch;
		info->dex_name = "";
		regAdd[0] = 0xC2;
	}

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		goto out;
	}

	ret = fts_write_reg(info, regAdd, info->dex_mode ? 3 : 2);
	if (ret < 0)
		input_err(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
	else
		input_info(true, &info->client->dev, "%s: reg:%d, ret: %d\n", __func__, regAdd[2], ret);

	snprintf(buff, sizeof(buff), "%s", "OK");
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_OK;
	sec_cmd_set_cmd_exit(sec);
	return;

out:
	snprintf(buff, sizeof(buff), "%s", "NG");
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_exit(sec);
}

static void brush_enable(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[2] = {0xC1, 0x14};
	int ret;

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		goto out;
	}

	info->brush_mode = sec->cmd_param[0];

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	input_info(true, &info->client->dev,
		"%s: set brush mode %s\n", __func__, info->brush_mode ? "enable" : "disable");

	if (info->brush_mode == 0)
		regAdd[0] = 0xC2;	/* 0: Disable Artcanvas min phi mode */
	else
		regAdd[0] = 0xC1;	/* 1: Enable Artcanvas min phi mode  */

	ret = fts_write_reg(info, regAdd, 2);
	if (ret < 0) {
		input_err(true, &info->client->dev,
					"%s: failed to set brush mode\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
	info->cmd_state = CMD_STATUS_OK;

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

out:
	info->lowpower_mode = check_lowpower_mode(info);

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void spay_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	unsigned short addr = FTS_CMD_STRING_ACCESS;
	int ret;
	char buff[CMD_STR_LEN] = { 0 };

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);

		snprintf(buff, sizeof(buff), "%s", "TSP turned off");

		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	set_default_result(info);

	if (info->cmd_param[0]) {
		info->fts_mode |= FTS_MODE_SPAY;
		info->lowpower_flag = info->lowpower_flag | FTS_LOWP_FLAG_SPAY;
	} else {
		info->fts_mode &= ~FTS_MODE_SPAY;
		info->lowpower_flag = info->lowpower_flag & ~(FTS_LOWP_FLAG_SPAY);
	}

	ret = info->fts_write_to_string(info, &addr, &info->fts_mode, sizeof(info->fts_mode));
	if (ret < 0) {
		tsp_debug_info(true, &info->client->dev, "%s: failed. ret: %d\n", __func__, ret);
		snprintf(buff, sizeof(buff), "%s", "NG");
		info->cmd_state = CMD_STATUS_FAIL;

=======
	sec->cmd_state = SEC_CMD_STATUS_OK;

out:
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void set_touchable_area(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	unsigned char regAdd[2] = {0xC1, 0x15};
	int ret;

	sec_cmd_set_default_result(sec);

	if (sec->cmd_param[0] < 0 || sec->cmd_param[0] > 1) {
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
		goto out;
	}

	info->touchable_area = sec->cmd_param[0];

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		sec->cmd_state = SEC_CMD_STATUS_NOT_APPLICABLE;
		goto out;
	}

	input_info(true, &info->client->dev,
		"%s: set 16:9 mode %s\n", __func__, info->touchable_area ? "enable" : "disable");

	if (info->touchable_area == 0)
		regAdd[0] = 0xC2;	/* 0: Disable 16:9 mode */
	else
		regAdd[0] = 0xC1;	/* 1: Enable 16:9 mode  */

	ret = fts_write_reg(info, regAdd, 2);
	if (ret < 0) {
		input_err(true, &info->client->dev,
					"%s: failed to set 16:9 mode\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto out;
	}

	snprintf(buff, sizeof(buff), "%s", "OK");
<<<<<<< HEAD
	info->cmd_state = CMD_STATUS_OK;

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

out:
	info->lowpower_mode = check_lowpower_mode(info);

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}
#endif

static void delay(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	info->delay_time = info->cmd_param[0];

	tsp_debug_info(true, &info->client->dev, "%s: delay time is %d\n", __func__, info->delay_time);
	snprintf(buff, sizeof(buff), "%d", info->delay_time);

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	sec->cmd_state = SEC_CMD_STATUS_OK;

out:
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void delay(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	info->delay_time = sec->cmd_param[0];

	input_info(true, &info->client->dev, "%s: delay time is %d\n", __func__, info->delay_time);
	snprintf(buff, sizeof(buff), "%d", info->delay_time);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static void debug(void *device_data)
{
<<<<<<< HEAD
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	info->debug_string = info->cmd_param[0];

	tsp_debug_info(true, &info->client->dev, "%s: command is %d\n", __func__, info->debug_string);

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void run_autotune_enable(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	info->run_autotune = info->cmd_param[0];

	tsp_debug_info(true, &info->client->dev, "%s: command is %s\n",
			__func__, info->run_autotune ? "ENABLE" : "DISABLE");

	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);
	info->cmd_state = CMD_STATUS_WAITING;

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

static void run_autotune(void *device_data)
{
	struct fts_ts_info *info = (struct fts_ts_info *)device_data;
	char buff[CMD_STR_LEN] = { 0 };

	set_default_result(info);

	if (info->touch_stopped) {
		dev_info(&info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
	}

	if (info->touch_stopped) {
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));
		info->cmd_state = CMD_STATUS_NOT_APPLICABLE;
		return;
	}

	if (!info->run_autotune){
		tsp_debug_info(true, &info->client->dev, "%s: autotune is disabled, %d\n", __func__, info->run_autotune);
		goto autotune_fail;
	}

#ifdef CONFIG_SEC_DEBUG_TSP_LOG
	if(info->rawdata_read_lock == 1){
		tsp_debug_info(true, &info->client->dev, "%s: ramdump mode is runing, %d\n", __func__, info->rawdata_read_lock);
		goto autotune_fail;
	}
#endif

	disable_irq(info->irq);

	if (info->digital_rev == FTS_DIGITAL_REV_2) {
		fts_interrupt_set(info, INT_DISABLE);

		fts_command(info, SENSEOFF);
		fts_delay(50);

#ifdef FTS_SUPPORT_TOUCH_KEY
		if (info->board->support_mskey) {
			fts_command(info, FTS_CMD_KEY_SENSE_OFF);
		}
#endif
		fts_command(info, FLUSHBUFFER);

		fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
		fts_release_all_key(info);
#endif

		fts_execute_autotune(info);

		fts_command(info, SLEEPOUT);
		fts_delay(1);
		fts_command(info, SENSEON);

#ifdef FTS_SUPPORT_WATER_MODE
		fts_fw_wait_for_event(info, STATUS_EVENT_WATER_SELF_DONE);
#else
		fts_fw_wait_for_event(info, STATUS_EVENT_FORCE_CAL_DONE);
#endif
#ifdef FTS_SUPPORT_TOUCH_KEY
		if (info->board->support_mskey)
			fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

		fts_interrupt_set(info, INT_ENABLE);
	}else {
		tsp_debug_info(true, &info->client->dev, "%s: digital_rev not matched, %d\n", __func__, info->digital_rev);
		goto autotune_fail;
	}

	enable_irq(info->irq);
	snprintf(buff, sizeof(buff), "%s", "OK");
	info->cmd_state = CMD_STATUS_OK;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	return;

autotune_fail:
	snprintf(buff, sizeof(buff), "%s", "NG");
	info->cmd_state = CMD_STATUS_FAIL;
	set_cmd_result(info, buff, strnlen(buff, sizeof(buff)));

	mutex_lock(&info->cmd_lock);
	info->cmd_is_running = false;
	mutex_unlock(&info->cmd_lock);

	tsp_debug_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
=======
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };

	sec_cmd_set_default_result(sec);

	info->debug_string = sec->cmd_param[0];

	input_info(true, &info->client->dev, "%s: command is %d\n", __func__, info->debug_string);

	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	sec->cmd_state = SEC_CMD_STATUS_WAITING;
	sec_cmd_set_cmd_exit(sec);

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
}

/* for Tablet model : TSP connection check : using mis_cal data
 * return true : connected
 * return false : not connected or error */
static bool tsp_connection_check(struct fts_ts_info *info)
{
	int ret;

	disable_irq(info->irq);
	/* 1. Auto-Tune & NOT save data */
	fts_command(info, CX_TUNNING);
	msleep(300);
	fts_fw_wait_for_event_D3(info, STATUS_EVENT_MUTUAL_AUTOTUNE_DONE, 0x00);

	fts_command(info, SELF_AUTO_TUNE);
	msleep(300);
	fts_fw_wait_for_event_D3(info, STATUS_EVENT_SELF_AUTOTUNE_DONE_D3, 0x00);
	enable_irq(info->irq);

	/* 2. check mis_cal info */
	ret = get_mis_cal(info);

	return (ret == 0) ? true : false;
}

#ifdef PAT_CONTROL
int fts_ts_tclm(struct fts_ts_info *info, bool boot, bool run_force)
{
	/* get ic information */
	info->fts_get_version_info(info);

	/* read nv value of cal_count & tune_fix_ver */
	fts_get_calibration_information(info);
	input_info(true, &info->client->dev, "%s: cal_count [%02X]\n", __func__, info->cal_count);
	input_info(true, &info->client->dev, "%s: tune_fix_ver [%04X] afe_base [%04X]\n", __func__,
		info->tune_fix_ver, info->board->afe_base);

	/* initialize nv default value from 0xff to 0x00 */
	if (info->cal_count == 0xFF && info->tune_fix_ver == 0xFFFF) {
		info->cal_count = PAT_COUNT_ZERO;
		fts_set_calibration_information(info, info->cal_count, info->fw_main_version_of_ic);
		//fts_set_calibration_information(info, info->cal_count, 0);
		input_info(true, &info->client->dev,
			"%s: initialize nv as default value & excute autotune\n", __func__);
	}

	if (run_force) {

		/* LCIA or External Factory  by run_force_calibration, real calibration was done at run_force_calibration */
		if (info->external_factory) {
			if (info->cal_count >= PAT_MAX_EXT)
				info->cal_count = PAT_MAX_EXT;
			else if (info->cal_count >= PAT_EXT_FACT)
				info->cal_count++;
			else
				info->cal_count = PAT_EXT_FACT;
		} else {
			/*change  from ( virtual pat  or vpat by external fatory )	to real pat by forced calibarion by LCIA   */
			if (info->cal_count > PAT_MAX_LCIA || info->cal_count == PAT_COUNT_ZERO)
				info->cal_count = PAT_ONE_LCIA;
			else if (info->cal_count == PAT_MAX_LCIA)
				info->cal_count = PAT_MAX_LCIA;
			else
				info->cal_count++;
		}

	} else {

		/* distinguish  pat function at dt */
		if (info->board->pat_function == PAT_CONTROL_NONE) {
			if (info->cal_count != PAT_COUNT_ZERO)
				goto out_without_nvsave;
		} else if (info->board->pat_function == PAT_CONTROL_CLEAR_NV) {
			info->cal_count = PAT_COUNT_ZERO;
		} else if(info->board->pat_function == PAT_CONTROL_PAT_MAGIC) {

			if (info->board->afe_base > info->tune_fix_ver) {

				/* mismatch calibration - ic has too old calibration data after pat enabled*/
				info->cal_count = PAT_MAGIC_NUMBER;
				input_info(true, &info->client->dev,
					"%s: re-calibration (afe_base > tune_fix_ver)\n", __func__);

			} else if (info->cal_count == PAT_COUNT_ZERO) {

				info->cal_count = PAT_MAGIC_NUMBER;

			} else if (PAT_MAGIC_NUMBER <= info->cal_count && info->cal_count < PAT_MAX_MAGIC) {

				if (boot)
					goto out_without_nvsave;
				else
					info->cal_count++;

			} else {
				goto out_without_nvsave;
			}

		} else if (info->board->pat_function == PAT_CONTROL_FORCE_UPDATE) {
			info->cal_count = PAT_MAGIC_NUMBER;
		}

		/* need to be calibrated as new one */
		{
			input_err(true, &info->client->dev, "%s: RUN OFFSET CALIBRATION(0x%02X)\n", __func__, info->cal_count);
			fts_execute_autotune(info);
		}
	}
	input_info(true, &info->client->dev,
		"%s: modified cal_count(0x%02X) \n", __func__, info->cal_count);

	/* Save nv data   cal_count & tune_fix_ver */
	fts_set_calibration_information(info, info->cal_count, info->fw_main_version_of_ic);

	fts_get_calibration_information(info);

out_without_nvsave:
	input_info(true, &info->client->dev,
		"%s: cal_count [%2X] tune_fix_ver [%04X]\n", __func__, info->cal_count, info->tune_fix_ver);
	return 0;
}
#endif

static void run_force_calibration(void *device_data)
{
	struct sec_cmd_data *sec = (struct sec_cmd_data *)device_data;
	struct fts_ts_info *info = container_of(sec, struct fts_ts_info, sec);
	char buff[SEC_CMD_STR_LEN] = { 0 };
	bool touch_on = false;

	sec_cmd_set_default_result(sec);

	if (info->touch_stopped) {
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n",
			__func__);
		snprintf(buff, sizeof(buff), "%s", "TSP turned off");
		goto autotune_fail;
	}

	if (info->rawdata_read_lock == 1) {
		input_err(true, &info->client->dev, "%s: ramdump mode is runing, %d\n", __func__, info->rawdata_read_lock);
		snprintf(buff, sizeof(buff), "%s", "NG");
		goto autotune_fail;
	}

	if (info->touch_count > 0) {
		touch_on = true;
		input_err(true, info->dev, "%s: finger on touch(%d)\n", __func__, info->touch_count);
	}

	/* for Tablet model : TSP connection check at pretest apk */
	if (info->external_factory && !tsp_connection_check(info)) {
		input_err(true, info->dev, "%s: TSP is not connected. Do not run calibration\n", __func__);
		snprintf(buff, sizeof(buff), "%s", "NG_TSP_NOT_CONNECT");
		goto autotune_fail;
	}

	disable_irq(info->irq);

	fts_interrupt_set(info, INT_DISABLE);

	fts_command(info, SENSEOFF);
	fts_delay(50);

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey) {
		fts_command(info, FTS_CMD_KEY_SENSE_OFF);
	}
#endif
	fts_command(info, FLUSHBUFFER);
	fts_delay(10);

	fts_release_all_finger(info);
#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_release_all_key(info);
#endif

	fts_command(info,FTS_CMD_FORCE_AUTOTUNE);

	if (touch_on) {
		input_err(true, info->dev, "%s: finger! do not run autotune\n", __func__);
	} else {
		input_info(true, info->dev, "%s: run autotune\n", __func__);
#ifdef PAT_CONTROL
		input_err(true, &info->client->dev, "%s: RUN OFFSET CALIBRATION \n", __func__);
		fts_execute_autotune(info);
		fts_ts_tclm(info, false, true);
#else
		input_err(true, &info->client->dev, "%s: RUN OFFSET CALIBRATION \n", __func__);
		fts_execute_autotune(info);
#endif
	}

	fts_command(info, SENSEON);
#ifdef FTS_SUPPORT_PRESSURE_SENSOR
	fts_command(info, FTS_CMD_PRESSURE_SENSE_ON);
#endif
	fts_fw_wait_for_event (info, STATUS_EVENT_FORCE_CAL_DONE_D3);

#ifdef FTS_SUPPORT_TOUCH_KEY
	if (info->board->support_mskey)
		fts_command(info, FTS_CMD_KEY_SENSE_ON);
#endif

	fts_interrupt_set(info, INT_ENABLE);
	enable_irq(info->irq);

	if (touch_on) {
		snprintf(buff, sizeof(buff), "NG_FINGER_ON");
		sec->cmd_state = SEC_CMD_STATUS_FAIL;
	} else {
		snprintf(buff, sizeof(buff), "%s", "OK");
		sec->cmd_state = SEC_CMD_STATUS_OK;
	}
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	/* not to enter external factory mode without setting everytime */
	info->external_factory = false;

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
	return;

autotune_fail:
	/* not to enter external factory mode without setting everytime */
	info->external_factory = false;

	snprintf(buff, sizeof(buff), "%s", "NG");
	sec->cmd_state = SEC_CMD_STATUS_FAIL;
	sec_cmd_set_cmd_result(sec, buff, strnlen(buff, sizeof(buff)));

	input_info(true, &info->client->dev, "%s: %s\n", __func__, buff);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	return;
}

#ifdef FTS_SUPPORT_TOUCH_KEY
int read_touchkey_data(struct fts_ts_info *info, unsigned char type, unsigned int keycode)
{
	unsigned char pCMD[3] = { 0xD0, 0x00, 0x00};
	unsigned char buf[9] = { 0 };
	int i;
	int ret = 0;

	pCMD[2] = type;

	ret = fts_read_reg(info, &pCMD[0], 3, buf, 3);
	if (ret >= 0) {
<<<<<<< HEAD
		if (info->digital_rev == FTS_DIGITAL_REV_1) {
			pCMD[1] = buf[1];
			pCMD[2] = buf[0];
		}
		else {
			pCMD[1] = buf[2];
			pCMD[2] = buf[1];
		}
=======
		pCMD[1] = buf[2];
		pCMD[2] = buf[1];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	} else
		return -1;

	ret = fts_read_reg(info, &pCMD[0], 3, buf, 9);
	if (ret < 0)
		return -2;

	for (i = 0 ; i < info->board->num_touchkey ; i++)
		if (info->board->touchkey[i].keycode == keycode) {
<<<<<<< HEAD
			if (info->digital_rev == FTS_DIGITAL_REV_1)
				return *(short *)&buf[(info->board->touchkey[i].value - 1) * 2];
			else
				return *(short *)&buf[(info->board->touchkey[i].value - 1) * 2 + 1];
=======
			return *(short *)&buf[(info->board->touchkey[i].value - 1) * 2 + 1];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}

	return -3;
}

static ssize_t touchkey_recent_strength(struct device *dev,
				       struct device_attribute *attr, char *buf) {
	struct fts_ts_info *info = dev_get_drvdata(dev);
	int value = 0;

	if (info->touch_stopped) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "%d\n", value);
	}

	value = read_touchkey_data(info, TYPE_TOUCHKEY_STRENGTH, KEY_RECENT);

	return sprintf(buf, "%d\n", value);
}

static ssize_t touchkey_back_strength(struct device *dev,
				       struct device_attribute *attr, char *buf) {
	struct fts_ts_info *info = dev_get_drvdata(dev);
	int value = 0;

	if (info->touch_stopped) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "%d\n", value);
	}

	value = read_touchkey_data(info, TYPE_TOUCHKEY_STRENGTH, KEY_BACK);

	return sprintf(buf, "%d\n", value);
}

static ssize_t touchkey_recent_raw(struct device *dev,
				       struct device_attribute *attr, char *buf) {
	struct fts_ts_info *info = dev_get_drvdata(dev);
	int value = 0;

	if (info->touch_stopped) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "%d\n", value);
	}

	value = read_touchkey_data(info, TYPE_TOUCHKEY_RAW, KEY_RECENT);

	return sprintf(buf, "%d\n", value);
}

static ssize_t touchkey_back_raw(struct device *dev,
				       struct device_attribute *attr, char *buf) {
	struct fts_ts_info *info = dev_get_drvdata(dev);
	int value = 0;

	if (info->touch_stopped) {
<<<<<<< HEAD
		tsp_debug_info(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
=======
		input_err(true, &info->client->dev, "%s: [ERROR] Touch is stopped\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		return sprintf(buf, "%d\n", value);
	}

	value = read_touchkey_data(info, TYPE_TOUCHKEY_RAW, KEY_BACK);

	return sprintf(buf, "%d\n", value);
}

static ssize_t touchkey_threshold(struct device *dev,
				       struct device_attribute *attr, char *buf) {
	struct fts_ts_info *info = dev_get_drvdata(dev);
	unsigned char pCMD[3] = { 0xD0, 0x00, 0x00};
	int value;
	int ret = 0;

	value = -1;
<<<<<<< HEAD
	pCMD[2] = TYPE_TOUCHKEY_THRESHOLD;
	ret = fts_read_reg(info, &pCMD[0], 3, buf, 3);
	if (ret >= 0) {
		if (info->digital_rev == FTS_DIGITAL_REV_1)
			value = *(unsigned short *)&buf[0];
		else
			value = *(unsigned short *)&buf[1];
=======
	pCMD[2] = FTS_SI_SS_KEY_THRESHOLD;
	ret = fts_read_reg(info, &pCMD[0], 3, buf, 3);
	if (ret >= 0) {
		value = *(unsigned short *)&buf[1];
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	info->touchkey_threshold = value;
	return sprintf(buf, "%d\n", info->touchkey_threshold);
}

static ssize_t fts_touchkey_led_control(struct device *dev,
				 struct device_attribute *attr, const char *buf,
				 size_t size)
{
	struct fts_ts_info *info = dev_get_drvdata(dev);
<<<<<<< HEAD
	int data, ret;

	ret = sscanf(buf, "%d", &data);
	tsp_debug_dbg(true, &info->client->dev, "%s, %d\n", __func__, data);

	if (ret != 1) {
		tsp_debug_err(true, &info->client->dev, "%s, %d err\n",
			__func__, __LINE__);
		return size;
	}

	if (data != 0 && data != 1) {
		tsp_debug_err(true, &info->client->dev, "%s wrong cmd %x\n",
=======
	int ret;
	unsigned long data;

	if (size > 2) {
		input_err(true, &info->client->dev,
			"%s: cmd length is over (%s,%d)!!\n",
			__func__, buf, (int)strlen(buf));
		return -EINVAL;
	}

	ret = kstrtoul(buf, 10, &data);
	if (ret != 0) {
		input_err(true, &info->client->dev, "%s: failed to read:%d\n",
					__func__, ret);
		return -EINVAL;
	}
	input_dbg(true, &info->client->dev, "%s: %d\n", __func__, data);

	if (data != 0 && data != 1) {
		input_err(true, &info->client->dev, "%s: wrong cmd %x\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			__func__, data);
		return size;
	}

	ret = info->board->led_power(info, (bool)data);
	if (ret) {
<<<<<<< HEAD
		tsp_debug_err(true, &info->client->dev, "%s: Error turn on led %d\n",
=======
		input_err(true, &info->client->dev, "%s: Error turn on led %d\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			__func__, ret);

		goto out;
	}
	msleep(30);

out:
	return size;
}

static DEVICE_ATTR(brightness, S_IRUGO | S_IWUSR | S_IWGRP, NULL, fts_touchkey_led_control);
static DEVICE_ATTR(touchkey_recent, S_IRUGO, touchkey_recent_strength, NULL);
static DEVICE_ATTR(touchkey_back, S_IRUGO, touchkey_back_strength, NULL);
static DEVICE_ATTR(touchkey_recent_raw, S_IRUGO, touchkey_recent_raw, NULL);
static DEVICE_ATTR(touchkey_back_raw, S_IRUGO, touchkey_back_raw, NULL);
static DEVICE_ATTR(touchkey_threshold, S_IRUGO, touchkey_threshold, NULL);

static struct attribute *sec_touchkey_factory_attributes[] = {
	&dev_attr_touchkey_recent.attr,
	&dev_attr_touchkey_back.attr,
	&dev_attr_touchkey_recent_raw.attr,
	&dev_attr_touchkey_back_raw.attr,
	&dev_attr_touchkey_threshold.attr,
	&dev_attr_brightness.attr,
	NULL,
};

static struct attribute_group sec_touchkey_factory_attr_group = {
	.attrs = sec_touchkey_factory_attributes,
};
#endif

#endif
