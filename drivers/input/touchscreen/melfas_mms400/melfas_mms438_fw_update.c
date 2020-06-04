/*
 * MELFAS MMS438/449/458 Touchscreen
 *
 * Copyright (C) 2014 MELFAS Inc.
 *
 *
 * Firmware update functions
 *
 */

#include "melfas_mms400.h"

//ISC Info
#define ISC_PAGE_SIZE				128

//ISC Command
<<<<<<< HEAD
#define ISC_CMD_ERASE_ALL			{0xFB, 0x4A, 0x00, 0x15, 0x00, 0x00}
#define ISC_CMD_ERASE_PAGE			{0xFB, 0x4A, 0x00, 0x8F, 0x00, 0x00}
#define ISC_CMD_READ_PAGE			{0xFB, 0x4A, 0x00, 0xC2, 0x00, 0x00}
#define ISC_CMD_WRITE_PAGE			{0xFB, 0x4A, 0x00, 0xA5, 0x00, 0x00}
#define ISC_CMD_PROGRAM_PAGE		{0xFB, 0x4A, 0x00, 0x54, 0x00, 0x00}
#define ISC_CMD_READ_STATUS			{0xFB, 0x4A, 0x36, 0xC2, 0x00, 0x00}
#define ISC_CMD_EXIT				{0xFB, 0x4A, 0x00, 0x66, 0x00, 0x00}
=======
#define ISC_CMD_ERASE_ALL			{0xFB,0x4A,0x00,0x15,0x00,0x00}
#define ISC_CMD_ERASE_PAGE			{0xFB,0x4A,0x00,0x8F,0x00,0x00}
#define ISC_CMD_READ_PAGE			{0xFB,0x4A,0x00,0xC2,0x00,0x00}
#define ISC_CMD_WRITE_PAGE			{0xFB,0x4A,0x00,0xA5,0x00,0x00}
#define ISC_CMD_PROGRAM_PAGE			{0xFB,0x4A,0x00,0x54,0x00,0x00}
#define ISC_CMD_READ_STATUS			{0xFB,0x4A,0x36,0xC2,0x00,0x00}
#define ISC_CMD_EXIT				{0xFB,0x4A,0x00,0x66,0x00,0x00}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

//ISC Status
#define ISC_STATUS_BUSY				0x96
#define ISC_STATUS_DONE				0xAD

/**
 * Read ISC status
 */
static int mms_isc_read_status(struct mms_ts_info *info)
{
	struct i2c_client *client = info->client;
	u8 cmd[6] =  ISC_CMD_READ_STATUS;
	u8 result = 0;
	int cnt = 100;
	int ret = 0;
	struct i2c_msg msg[2] = {
		{
			.addr = client->addr,
			.flags = 0,
			.buf = cmd,
			.len = 6,
		}, {
			.addr = client->addr,
			.flags = I2C_M_RD,
			.buf = &result,
			.len = 1,
		},
	};

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	do {
		if (i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg)) != ARRAY_SIZE(msg)) {
			input_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	do {
		if (i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg))!=ARRAY_SIZE(msg)) {
			tsp_debug_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return -1;
		}

		if (result == ISC_STATUS_DONE) {
			ret = 0;
			break;
		} else if (result == ISC_STATUS_BUSY) {
			ret = -1;
			msleep(1);
		} else {
<<<<<<< HEAD
			input_err(true, &info->client->dev, "%s [ERROR] wrong value [0x%02X]\n",
				__func__, result);
			ret = -1;
			usleep_range(1 * 1000, 1 * 1000);
=======
			tsp_debug_err(true, &info->client->dev, "%s [ERROR] wrong value [0x%02X]\n",
				__func__, result);
			ret = -1;
			msleep(1);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		}
	} while (--cnt);

	if (!cnt) {
<<<<<<< HEAD
		input_err(true, &info->client->dev,
=======
		tsp_debug_err(true, &info->client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			"%s [ERROR] count overflow - cnt [%d] status [0x%02X]\n",
			__func__, cnt, result);
		goto ERROR;
	}

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [DONE]\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [DONE]\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;

ERROR:
	return ret;
}

/**
 * Command : Erase Page
 */
static int mms_isc_erase_page(struct mms_ts_info *info, int offset)
{
<<<<<<< HEAD
	u8 write_buf[6] = ISC_CMD_ERASE_PAGE;
=======
	u8 write_buf[6] =ISC_CMD_ERASE_PAGE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	struct i2c_msg msg[1] = {
		{
			.addr = info->client->addr,
			.flags = 0,
			.buf = write_buf,
			.len = 6,
		},
	};

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [START]\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [START]\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	write_buf[4] = (u8)(((offset)>>8) & 0xFF);
	write_buf[5] = (u8)(((offset)>>0) & 0xFF);
	if (i2c_transfer(info->client->adapter, msg, ARRAY_SIZE(msg)) != ARRAY_SIZE(msg)) {
<<<<<<< HEAD
		input_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
		goto ERROR;
	}

	if (mms_isc_read_status(info) != 0)
		goto ERROR;

	input_dbg(true, &info->client->dev, "%s [DONE] - Offset [0x%04X]\n", __func__, offset);
=======
		tsp_debug_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
		goto ERROR;
	}

	if (mms_isc_read_status(info) != 0) {
		goto ERROR;
	}

	tsp_debug_dbg(true, &info->client->dev, "%s [DONE] - Offset [0x%04X]\n", __func__, offset);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return 0;

ERROR:
	return -1;
}

/**
 * Command : Read Page
 */
static int mms_isc_read_page(struct mms_ts_info *info, int offset, u8 *data)
{
<<<<<<< HEAD
	u8 write_buf[6] = ISC_CMD_READ_PAGE;
=======
	u8 write_buf[6] =ISC_CMD_READ_PAGE;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	struct i2c_msg msg[2] = {
		{
			.addr = info->client->addr,
			.flags = 0,
			.buf = write_buf,
			.len = 6,
		}, {
			.addr = info->client->addr,
			.flags = I2C_M_RD,
			.buf = data,
			.len = ISC_PAGE_SIZE,
		},
	};

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [START]\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [START]\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	write_buf[4] = (u8)(((offset)>>8) & 0xFF);
	write_buf[5] = (u8)(((offset)>>0) & 0xFF);
	if (i2c_transfer(info->client->adapter, msg, ARRAY_SIZE(msg)) != ARRAY_SIZE(msg)) {
<<<<<<< HEAD
		input_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
		goto ERROR;
	}

	input_dbg(true, &info->client->dev, "%s [DONE] - Offset [0x%04X]\n", __func__, offset);
=======
		tsp_debug_err(true, &info->client->dev, "%s [ERROR] i2c_transfer\n", __func__);
		goto ERROR;
	}

	tsp_debug_dbg(true, &info->client->dev, "%s [DONE] - Offset [0x%04X]\n", __func__, offset);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return 0;

ERROR:
	return -1;
}

/**
 * Command : Program Page
 */
static int mms_isc_program_page(struct mms_ts_info *info, int offset,
				const u8 *data, int length)
{
	u8 write_buf[134] = ISC_CMD_PROGRAM_PAGE;

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	if (length > 128) {
		input_err(true, &info->client->dev, "%s [ERROR] page length overflow\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	if (length > 128) {
		tsp_debug_err(true, &info->client->dev, "%s [ERROR] page length overflow\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto ERROR;
	}

	write_buf[4] = (u8)(((offset)>>8) & 0xFF);
	write_buf[5] = (u8)(((offset)>>0) & 0xFF);

	memcpy(&write_buf[6], data, length);

<<<<<<< HEAD
	if (i2c_master_send(info->client, write_buf, length+6) != length+6) {
		input_err(true, &info->client->dev, "%s [ERROR] i2c_master_send\n", __func__);
		goto ERROR;
	}

	if (mms_isc_read_status(info) != 0)
		goto ERROR;

	input_dbg(true, &info->client->dev, "%s [DONE] - Offset[0x%04X] Length[%d]\n",
=======
	if (i2c_master_send(info->client, write_buf, length+6 )!=length+6) {
		tsp_debug_err(true, &info->client->dev, "%s [ERROR] i2c_master_send\n", __func__);
		goto ERROR;
	}

	if (mms_isc_read_status(info) != 0) {
		goto ERROR;
	}

	tsp_debug_dbg(true, &info->client->dev, "%s [DONE] - Offset[0x%04X] Length[%d]\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		__func__, offset, length);

	return 0;

ERROR:
	return -1;
}

/**
 * Command : Exit ISC
 */
static int mms_isc_exit(struct mms_ts_info *info)
{
	u8 write_buf[6] = ISC_CMD_EXIT;

<<<<<<< HEAD
	input_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	if (i2c_master_send(info->client, write_buf, 6) != 6) {
		input_err(true, &info->client->dev, "%s [ERROR] i2c_master_send\n", __func__);
		goto ERROR;
	}

	input_dbg(true, &info->client->dev, "%s [DONE]\n", __func__);
=======
	tsp_debug_dbg(true, &info->client->dev, "%s [START]\n", __func__);

	if (i2c_master_send(info->client, write_buf, 6) != 6) {
		tsp_debug_err(true, &info->client->dev, "%s [ERROR] i2c_master_send\n", __func__);
		goto ERROR;
	}

	tsp_debug_dbg(true, &info->client->dev, "%s [DONE]\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return 0;

ERROR:
	return -1;
}

/**
 * Flash chip firmware (main function)
 */
int mms_flash_fw(struct mms_ts_info *info, const u8 *fw_data,
				size_t fw_size, bool force, bool section)
{

	struct mms_bin_hdr *fw_hdr;
	struct mms_fw_img **img;
	struct i2c_client *client = info->client;
	int i;
	int retires = 3;
	int nRet;
	int nStartAddr;
	int nWriteLength;
	int nLast;
	int nOffset;
	int nTransferLength;
	int size;
	u8 *data;
	u8 *cpydata;

	int offset = sizeof(struct mms_bin_hdr);

	bool update_flag = false;
	bool update_flags[MMS_FW_MAX_SECT_NUM] = {false, };

	u16 ver_chip[MMS_FW_MAX_SECT_NUM];
	u16 ver_file[MMS_FW_MAX_SECT_NUM];

	int offsetStart = 0;
	u8 initData[ISC_PAGE_SIZE];
<<<<<<< HEAD

	memset(initData, 0xFF, sizeof(initData));

	input_dbg(true, &client->dev, "%s [START]\n", __func__);

	//Read firmware file
	fw_hdr = (struct mms_bin_hdr *)fw_data;
	if (fw_hdr->section_num > MMS_FW_MAX_SECT_NUM) {
		input_err(true, &client->dev, "Failed over max section num \n");
		nRet = -EINVAL;
		goto err_alloc_img;
	}

	img = vzalloc(sizeof(*img) * fw_hdr->section_num);
	if (!img) {
		input_err(true, &client->dev, "Failed to allocate memory\n");
=======
	memset(initData, 0xFF, sizeof(initData));

	tsp_debug_dbg(true, &client->dev, "%s [START]\n", __func__);

	//Read firmware file
	fw_hdr = (struct mms_bin_hdr *)fw_data;
	img = vzalloc(sizeof(*img) * fw_hdr->section_num);
	if (!img) {
		tsp_debug_err(true, &client->dev, "Failed to img allocate memory\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		nRet = -ENOMEM;
		goto err_alloc_img;
	}


	//Check firmware file
	if (memcmp(CHIP_FW_CODE, &fw_hdr->tag[4], 4)) {
<<<<<<< HEAD
		input_err(true, &client->dev, "%s [ERROR] F/W file is not for %s\n",
=======
		tsp_debug_err(true, &client->dev, "%s [ERROR] F/W file is not for %s\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			__func__, CHIP_NAME);

		nRet = fw_err_file_type;
		goto EXIT;
	}
<<<<<<< HEAD
	//Reboot chip
	mms_reboot(info);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	//Check chip firmware version
	while (retires--) {
		if (!mms_get_fw_version_u16(info, ver_chip))
			break;
<<<<<<< HEAD

		mms_reboot(info);
	}

	if (retires < 0) {
		input_err(true, &client->dev,
			"%s [ERROR] cannot read chip firmware version\n", __func__);

		memset(ver_chip, 0xFFFF, sizeof(ver_chip));
		input_dbg(true, &client->dev,
			"%s - Chip firmware version is set to [0xFFFF]\n", __func__);
	} else {
		input_info(true, &client->dev,
=======
		else
			mms_reboot(info);
	}

	if (retires < 0) {
		tsp_debug_err(true, &client->dev,
			"%s [ERROR] cannot read chip firmware version\n",__func__);

		memset(ver_chip, 0xFFFF, sizeof(ver_chip));
		tsp_debug_dbg(true, &client->dev,
			"%s - Chip firmware version is set to [0xFFFF]\n", __func__);
	} else {
		tsp_debug_info(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			"%s - Chip firmware version [0x%04X 0x%04X 0x%04X 0x%04X]\n",
			__func__, ver_chip[0], ver_chip[1], ver_chip[2], ver_chip[3]);
	}

	//Set update flag
<<<<<<< HEAD
	input_info(true, &client->dev,
=======
	tsp_debug_info(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		"%s - Firmware file info : Sections[%d] Offset[0x%08X] Length[0x%08X]\n",
		__func__, fw_hdr->section_num, fw_hdr->binary_offset, fw_hdr->binary_length);

	for (i = 0; i < fw_hdr->section_num; i++, offset += sizeof(struct mms_fw_img)) {
		img[i] = (struct mms_fw_img *)(fw_data + offset);
		ver_file[i] = img[i]->version;

<<<<<<< HEAD
		input_dbg(true, &client->dev,
			"%s - Section info : Section[%d] Version[0x%04X] StartPage[%d]",
			__func__, i, img[i]->version, img[i]->start_page);
		input_dbg(true, &client->dev,
			" EndPage[%d] Offset[0x%08X] Length[0x%08X]\n",
			img[i]->end_page, img[i]->offset, img[i]->length);

		input_err(true, &client->dev,
=======
		tsp_debug_dbg(true, &client->dev,
			"%s - Section info : Section[%d] Version[0x%04X] StartPage[%d]"
			" EndPage[%d] Offset[0x%08X] Length[0x%08X]\n",
			__func__, i, img[i]->version, img[i]->start_page,
			img[i]->end_page,img[i]->offset, img[i]->length);

		tsp_debug_err(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			"%s - Section[%d] IC: %04X / BIN: %04X\n",
			__func__, i, ver_chip[i], ver_file[i]);

		//Compare section version
		if (ver_chip[i] < ver_file[i] || ver_chip[i] > ver_file[i] + 0x20) {
			//Set update flag
			update_flag = true;
			update_flags[i] = true;

<<<<<<< HEAD
			input_info(true, &client->dev,
=======
			tsp_debug_info(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				"%s - Section[%d] is need to be updated.", __func__, i);
		}
	}

	//Set force update flag
	if (force == true) {
		update_flag = true;
		update_flags[0] = true;
		update_flags[1] = true;
		update_flags[2] = true;
		update_flags[3] = true;

<<<<<<< HEAD
		input_info(true, &client->dev, "%s - Force update\n", __func__);
	}

	//Exit when up-to-date
	if (update_flag == false) {
		nRet = fw_err_uptodate;
		input_dbg(true, &client->dev,
=======
		tsp_debug_info(true, &client->dev, "%s - Force update\n", __func__);
	}

	if(info->dtdata->fw_update_skip)
		update_flag = false;

	//Exit when up-to-date
	if (update_flag == false) {
		nRet = fw_err_uptodate;
		tsp_debug_dbg(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			"%s [DONE] Chip firmware is already up-to-date\n", __func__);
		goto EXIT;
	}

	//Set start addr offset
	if (section == true) {
		if (update_flags[0] == true) {
			//boot
			offsetStart = img[0]->start_page;
		} else if (update_flags[1] == true) {
			//core
			offsetStart = img[1]->start_page;
		} else if (update_flags[2] == true) {
			//custom
			offsetStart = img[2]->start_page;
		} else if (update_flags[3] == true) {
			//param
			offsetStart = img[3]->start_page;
		}
	} else
		offsetStart = 0;

	offsetStart = offsetStart * 1024;

	//Load firmware data
	data = vzalloc(sizeof(u8) * fw_hdr->binary_length);
	if (!data) {
<<<<<<< HEAD
		input_err(true, &client->dev, "%s Failed to allocate memory\n", __func__);
=======
		tsp_debug_err(true, &client->dev, "Failed to data allocate memory\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		nRet = -ENOMEM;
		goto err_alloc_data;
	}
	size = fw_hdr->binary_length;
	cpydata = vzalloc(ISC_PAGE_SIZE);
	if (!cpydata) {
<<<<<<< HEAD
		input_err(true, &client->dev, "%s Failed to allocate memory\n", __func__);
=======
		tsp_debug_err(true, &client->dev, "Failed to cpydata allocate memory\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		nRet = -ENOMEM;
		goto err_alloc_cpydata;
	}

	//Check firmware size
<<<<<<< HEAD
	if (size % ISC_PAGE_SIZE != 0)
		size += (ISC_PAGE_SIZE - (size % ISC_PAGE_SIZE));
=======
	if (size % ISC_PAGE_SIZE !=0) {
		size += ( ISC_PAGE_SIZE - (size % ISC_PAGE_SIZE) );
	}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	nStartAddr = 0;
	nWriteLength = size;
	nLast = nStartAddr + nWriteLength;

	if ((nLast) % 8 != 0) {
		nRet = fw_err_file_type;
<<<<<<< HEAD
		input_err(true, &client->dev, "%s [ERROR] Firmware size mismatch\n", __func__);
		goto ERROR;
	} else
		memcpy(data, fw_data+fw_hdr->binary_offset, fw_hdr->binary_length);
=======
		tsp_debug_err(true, &client->dev, "%s [ERROR] Firmware size mismatch\n", __func__);
		goto ERROR;
	} else
		memcpy(data,fw_data+fw_hdr->binary_offset,fw_hdr->binary_length);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	//Set address
	nOffset = nStartAddr + nWriteLength - ISC_PAGE_SIZE;
	nTransferLength = ISC_PAGE_SIZE;

	//Erase first page
<<<<<<< HEAD
	input_info(true, &client->dev, "%s - Erase first page : Offset[0x%04X]\n",
=======
	tsp_debug_info(true, &client->dev, "%s - Erase first page : Offset[0x%04X]\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				__func__, offsetStart);
	retires = 3;
	while (retires--) {
		nRet = mms_isc_erase_page(info, offsetStart);
<<<<<<< HEAD
		if (nRet == 0)
			break;
	}
	if (retires < 0) {
		input_err(true, &client->dev, "%s [ERROR] clear first page failed\n", __func__);
=======
		if (nRet == 0) {
			break;
		}
	}
	if (retires < 0) {
		tsp_debug_err(true, &client->dev, "%s [ERROR] clear first page failed\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto ERROR;
	}

	//Flash firmware
<<<<<<< HEAD
	input_info(true, &client->dev, "%s - Start Download : Offset Start[0x%04X] End[0x%04X]\n",
				__func__, nOffset, offsetStart);
	while (nOffset >= offsetStart) {
		input_dbg(true, &client->dev, "%s - Downloading : Offset[0x%04X]\n", __func__, nOffset);
=======
	tsp_debug_info(true, &client->dev, "%s - Start Download : Offset Start[0x%04X] End[0x%04X]\n",
				__func__, nOffset, offsetStart);
	while( nOffset >= offsetStart )
	{
		tsp_debug_dbg(true, &client->dev, "%s - Downloading : Offset[0x%04X]\n", __func__, nOffset);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

		//Program (erase and write) a page
		nRet = mms_isc_program_page(info, nOffset, &data[nOffset], nTransferLength);
		if (nRet != 0) {
<<<<<<< HEAD
			input_err(true, &client->dev, "%s [ERROR] isc_program_page\n", __func__);
=======
			tsp_debug_err(true, &client->dev, "%s [ERROR] isc_program_page\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			goto ERROR;
		}

		//Verify (read and compare)
		if (mms_isc_read_page(info, nOffset, cpydata)) {
<<<<<<< HEAD
			input_err(true, &client->dev, "%s [ERROR] mms_isc_read_page\n", __func__);
=======
			tsp_debug_err(true, &client->dev, "%s [ERROR] mms_isc_read_page\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			goto ERROR;
		}

		if (memcmp(&data[nOffset], cpydata, ISC_PAGE_SIZE)) {
#if MMS_FW_UPDATE_DEBUG
			print_hex_dump(KERN_ERR, "Firmware Page Write : ",
				DUMP_PREFIX_OFFSET, 16, 1, data, ISC_PAGE_SIZE, false);
			print_hex_dump(KERN_ERR, "Firmware Page Read : ",
				DUMP_PREFIX_OFFSET, 16, 1, cpydata, ISC_PAGE_SIZE, false);
#endif
<<<<<<< HEAD
			input_err(true, &client->dev, "%s [ERROR] verify page failed\n", __func__);
=======
			tsp_debug_err(true, &client->dev, "%s [ERROR] verify page failed\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

			nRet = -1;
			goto ERROR;
		}

		nOffset -= nTransferLength;
	}

	//Exit ISC
	nRet = mms_isc_exit(info);
	if (nRet != 0) {
<<<<<<< HEAD
		input_err(true, &client->dev, "%s [ERROR] mms_isc_exit\n", __func__);
=======
		tsp_debug_err(true, &client->dev, "%s [ERROR] mms_isc_exit\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto ERROR;
	}

	//Reboot chip
	mms_reboot(info);

	//Check chip firmware version
	if (mms_get_fw_version_u16(info, ver_chip)) {
<<<<<<< HEAD
		input_err(true, &client->dev,
=======
		tsp_debug_err(true, &client->dev,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			"%s [ERROR] cannot read chip firmware version after flash\n", __func__);

		nRet = -1;
		goto ERROR;
	} else {
		for (i = 0; i < fw_hdr->section_num; i++) {
			if (ver_chip[i] != ver_file[i]) {
<<<<<<< HEAD
				input_err(true, &client->dev,
					"%s [ERROR] version mismatch after flash.  Section[%d] : Chip[0x%04X] != File[0x%04X]\n",
=======
				tsp_debug_err(true, &client->dev,
					"%s [ERROR] version mismatch after flash."
					" Section[%d] : Chip[0x%04X] != File[0x%04X]\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
					__func__, i, ver_chip[i], ver_file[i]);

				nRet = -1;
				goto ERROR;
			}
		}
	}

	nRet = 0;
<<<<<<< HEAD
	input_dbg(true, &client->dev, "%s [DONE]\n", __func__);
	goto DONE;

ERROR:
	input_err(true, &client->dev, "%s [ERROR]\n", __func__);
=======
	tsp_debug_dbg(true, &client->dev, "%s [DONE]\n", __func__);
	goto DONE;

ERROR:
	tsp_debug_err(true, &client->dev, "%s [ERROR]\n", __func__);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
DONE:
	vfree(cpydata);
err_alloc_cpydata:
	vfree(data);
err_alloc_data:
EXIT:
	vfree(img);
err_alloc_img:
	return nRet;
}
