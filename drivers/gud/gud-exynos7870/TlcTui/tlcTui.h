/*
<<<<<<< HEAD
 * Copyright (c) 2013-2014 TRUSTONIC LIMITED
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

#ifndef TLCTUI_H_
#define TLCTUI_H_

void reset_global_command_id(void);
int tlc_wait_cmd(uint32_t *cmd_id);
int tlc_ack_cmd(struct tlc_tui_response_t *rsp_id);
<<<<<<< HEAD
bool tlc_notify_event(uint32_t event_type);

=======
bool tlc_notify_event(u32 event_type);

extern atomic_t fileopened;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#endif /* TLCTUI_H_ */
