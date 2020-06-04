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
<<<<<<< HEAD
#include <linux/types.h>
#include <linux/uidgid.h>
=======

#include <linux/types.h>
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/jiffies.h>
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <linux/err.h>
#include <linux/mm.h>
#include <crypto/hash.h>
#include <linux/scatterlist.h>
#include <linux/fs.h>
<<<<<<< HEAD

#include "public/mc_linux.h"
#include "public/mc_admin.h"

#include "platform.h"		/* MC_UIDGID_OLDSTYLE */
#include "main.h"
=======
#include <linux/version.h>
#if KERNEL_VERSION(4, 11, 0) <= LINUX_VERSION_CODE
#include <linux/sched/clock.h>	/* local_clock */
#include <linux/sched/task.h>	/* put_task_struct */
#endif

#include "public/mc_user.h"
#include "public/mc_admin.h"

#if KERNEL_VERSION(3, 5, 0) <= LINUX_VERSION_CODE
#include <linux/uidgid.h>
#else
#define kuid_t uid_t
#define kgid_t gid_t
#define KGIDT_INIT(value) ((kgid_t)value)

static inline uid_t __kuid_val(kuid_t uid)
{
	return uid;
}

static inline gid_t __kgid_val(kgid_t gid)
{
	return gid;
}

static inline bool gid_eq(kgid_t left, kgid_t right)
{
	return __kgid_val(left) == __kgid_val(right);
}

static inline bool gid_gt(kgid_t left, kgid_t right)
{
	return __kgid_val(left) > __kgid_val(right);
}

static inline bool gid_lt(kgid_t left, kgid_t right)
{
	return __kgid_val(left) < __kgid_val(right);
}
#endif
#include "main.h"
#include "admin.h"		/* mc_is_admin_tgid */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#include "mmu.h"
#include "mcp.h"
#include "client.h"		/* *cbuf* */
#include "session.h"
#include "mci/mcimcp.h"		/* WSM_INVALID */

#define SHA1_HASH_SIZE       20

struct wsm {
	/* Buffer NWd addr (uva or kva, used only for lookup) */
	uintptr_t		va;
	/* buffer length */
	u32			len;
	/* Buffer SWd addr */
	u32			sva;
	/* mmu L2 table */
	struct tee_mmu		*mmu;
	/* possibly a pointer to a cbuf */
	struct cbuf		*cbuf;
	/* list node */
	struct list_head	list;
};

<<<<<<< HEAD
/*
 * Postponed closing for GP TAs.
 * Implemented as a worker because cannot be executed from within isr_worker.
 */
=======
/* Cleanup for GP TAs, implemented as a worker to not impact other sessions */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static void session_close_worker(struct work_struct *work)
{
	struct mcp_session *mcp_session;
	struct tee_session *session;

	mcp_session = container_of(work, struct mcp_session, close_work);
<<<<<<< HEAD
	session = container_of(mcp_session, struct tee_session, mcp_session);
	session_close(session);
=======
	mc_dev_devel("session %x worker", mcp_session->id);
	session = container_of(mcp_session, struct tee_session, mcp_session);
	if (!mcp_close_session(mcp_session))
		complete(&session->close_completion);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static struct wsm *wsm_create(struct tee_session *session, uintptr_t va,
			      u32 len)
{
	struct wsm *wsm;

	/* Allocate structure */
	wsm = kzalloc(sizeof(*wsm), GFP_KERNEL);
	if (!wsm)
		return ERR_PTR(-ENOMEM);

	wsm->mmu = client_mmu_create(session->client, va, len, &wsm->cbuf);
	if (IS_ERR(wsm->mmu)) {
		int ret = PTR_ERR(wsm->mmu);

		kfree(wsm);
		return ERR_PTR(ret);
	}

	/* Increment debug counter */
	atomic_inc(&g_ctx.c_wsms);
	wsm->va = va;
	wsm->len = len;
<<<<<<< HEAD
	list_add_tail(&wsm->list, &session->wsms);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	mc_dev_devel("created wsm %p: mmu %p cbuf %p va %lx len %u\n",
		     wsm, wsm->mmu, wsm->cbuf, wsm->va, wsm->len);
	return wsm;
}

/*
 * Free a WSM object, must be called under the session's wsms_lock
 */
static void wsm_free(struct tee_session *session, struct wsm *wsm)
{
<<<<<<< HEAD
	/* Remove wsm from its parent session's list */
	list_del(&wsm->list);
	/* Free MMU table */
	client_mmu_free(session->client, wsm->va, wsm->mmu, wsm->cbuf);

	/* Delete wsm object */
	mc_dev_devel("freed wsm %p: mmu %p cbuf %p va %lx len %u\n",
		     wsm, wsm->mmu, wsm->cbuf, wsm->va, wsm->len);
=======
	/* Free MMU table */
	client_mmu_free(session->client, wsm->va, wsm->mmu, wsm->cbuf);
	/* Delete wsm object */
	mc_dev_devel("freed wsm %p: mmu %p cbuf %p va %lx len %u sva %x\n",
		     wsm, wsm->mmu, wsm->cbuf, wsm->va, wsm->len, wsm->sva);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	kfree(wsm);
	/* Decrement debug counter */
	atomic_dec(&g_ctx.c_wsms);
}

<<<<<<< HEAD
static int hash_path_and_data(u8 *hash, const void *data, unsigned int data_len)
{
	struct mm_struct *mm = current->mm;
=======
#if KERNEL_VERSION(4, 6, 0) <= LINUX_VERSION_CODE
static int hash_path_and_data(struct task_struct *task, u8 *hash,
			      const void *data, unsigned int data_len)
{
	struct mm_struct *mm = task->mm;
	struct crypto_shash *tfm;
	char *buf;
	char *path;
	unsigned int path_len;
	int ret = 0;

	buf = (char *)__get_free_page(GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	down_read(&mm->mmap_sem);
	if (!mm->exe_file) {
		ret = -ENOENT;
		goto end;
	}

	path = d_path(&mm->exe_file->f_path, buf, PAGE_SIZE);
	if (IS_ERR(path)) {
		ret = PTR_ERR(path);
		goto end;
	}

	mc_dev_devel("process path =");
	{
		char *c;

		for (c = path; *c; c++)
			mc_dev_devel("%c %d", *c, *c);
	}

	path_len = (unsigned int)strnlen(path, PAGE_SIZE);
	mc_dev_devel("path_len = %u", path_len);
	/* Compute hash of path */
	tfm = crypto_alloc_shash("sha1", 0, 0);
	if (IS_ERR(tfm)) {
		ret = PTR_ERR(tfm);
		mc_dev_err("cannot allocate shash: %d", ret);
		goto end;
	}

	{
		SHASH_DESC_ON_STACK(desc, tfm);

		desc->tfm = tfm;
		desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;

		crypto_shash_init(desc);
		crypto_shash_update(desc, (u8 *)path, path_len);
		if (data) {
			mc_dev_devel("hashing additional data");
			crypto_shash_update(desc, data, data_len);
		}

		crypto_shash_final(desc, hash);
		shash_desc_zero(desc);
	}

	crypto_free_shash(tfm);

end:
	up_read(&mm->mmap_sem);
	free_page((unsigned long)buf);

	return ret;
}
#else
static int hash_path_and_data(struct task_struct *task, u8 *hash,
			      const void *data, unsigned int data_len)
{
	struct mm_struct *mm = task->mm;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	struct hash_desc desc;
	struct scatterlist sg;
	char *buf;
	char *path;
	unsigned int path_len;
	int ret = 0;

	buf = (char *)__get_free_page(GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	down_read(&mm->mmap_sem);
	if (!mm->exe_file) {
		ret = -ENOENT;
		goto end;
	}

	path = d_path(&mm->exe_file->f_path, buf, PAGE_SIZE);
	if (IS_ERR(path)) {
		ret = PTR_ERR(path);
		goto end;
	}

<<<<<<< HEAD
	mc_dev_devel("current process path =\n");
=======
	mc_dev_devel("process path =\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	{
		char *c;

		for (c = path; *c; c++)
			mc_dev_devel("%c %d\n", *c, *c);
	}

<<<<<<< HEAD
	path_len = strnlen(path, PAGE_SIZE);
	mc_dev_devel("path_len = %u\n", path_len);
=======
	path_len = (unsigned int)strnlen(path, PAGE_SIZE);
	mc_dev_devel("path_len = %u\n", path_len);
	/* Compute hash of path */
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	desc.tfm = crypto_alloc_hash("sha1", 0, CRYPTO_ALG_ASYNC);
	if (IS_ERR(desc.tfm)) {
		ret = PTR_ERR(desc.tfm);
		mc_dev_devel("could not alloc hash = %d\n", ret);
		goto end;
	}

	desc.flags = 0;
	sg_init_one(&sg, path, path_len);
	crypto_hash_init(&desc);
	crypto_hash_update(&desc, &sg, path_len);
	if (data) {
		mc_dev_devel("current process path: hashing additional data\n");
		sg_init_one(&sg, data, data_len);
		crypto_hash_update(&desc, &sg, data_len);
	}

	crypto_hash_final(&desc, hash);
	crypto_free_hash(desc.tfm);

end:
	up_read(&mm->mmap_sem);
	free_page((unsigned long)buf);

	return ret;
}
<<<<<<< HEAD
=======
#endif

#if KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
#define GROUP_AT(gi, i) ((gi)->gid[i])
#endif

/*
 * groups_search is not EXPORTed so copied from kernel/groups.c
 * a simple bsearch
 */
int has_group(const struct cred *cred, gid_t id_gid)
{
	const struct group_info *group_info = cred->group_info;
	unsigned int left, right;
	kgid_t gid = KGIDT_INIT(id_gid);

	if (gid_eq(gid, cred->fsgid) || gid_eq(gid, cred->egid))
		return 1;

	if (!group_info)
		return 0;

	left = 0;
	right = group_info->ngroups;
	while (left < right) {
		unsigned int mid = (left + right) / 2;

		if (gid_gt(gid, GROUP_AT(group_info, mid)))
			left = mid + 1;
		else if (gid_lt(gid, GROUP_AT(group_info, mid)))
			right = mid;
		else
			return 1;
	}
	return 0;
}
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

static int check_prepare_identity(const struct mc_identity *identity,
				  struct identity *mcp_identity)
{
	struct mc_identity *mcp_id = (struct mc_identity *)mcp_identity;
	u8 hash[SHA1_HASH_SIZE];
	bool application = false;
	const void *data;
	unsigned int data_len;
<<<<<<< HEAD

	/* Mobicore doesn't support GP client authentication. */
	if (!g_ctx.f_client_login &&
	    (identity->login_type != TEEC_LOGIN_PUBLIC)) {
=======
	struct task_struct *task;

	/* Mobicore doesn't support GP client authentication. */
	if (!g_ctx.f_client_login &&
	    (identity->login_type != LOGIN_PUBLIC)) {
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		mc_dev_err("Unsupported login type %d\n", identity->login_type);
		return -EINVAL;
	}

<<<<<<< HEAD
=======
	/* Only proxy can provide a PID */
	if (identity->pid) {
		if (!mc_is_admin_tgid(current->tgid)) {
			mc_dev_err("Incorrect PID %d\n", current->tgid);
			return -EPERM;
		}
		rcu_read_lock();
		task = pid_task(find_vpid(identity->pid), PIDTYPE_PID);
		if (!task) {
			rcu_read_unlock();
			mc_dev_err("No task for PID %d\n", identity->gid);
			return -EINVAL;
		}
	} else {
		rcu_read_lock();
		task = current;
	}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	/* Copy login type */
	mcp_identity->login_type = identity->login_type;

	/* Fill in uid field */
<<<<<<< HEAD
	if ((identity->login_type == TEEC_LOGIN_USER) ||
	    (identity->login_type == TEEC_LOGIN_USER_APPLICATION)) {
		/* Set euid and ruid of the process. */
#if !defined(KUIDT_INIT) || defined(MC_UIDGID_OLDSTYLE)
		mcp_id->uid.euid = current_euid();
		mcp_id->uid.ruid = current_uid();
#else
		mcp_id->uid.euid = current_euid().val;
		mcp_id->uid.ruid = current_uid().val;
#endif
	}

	/* Check gid field */
	if ((identity->login_type == TEEC_LOGIN_GROUP) ||
	    (identity->login_type == TEEC_LOGIN_GROUP_APPLICATION)) {
#if !defined(KUIDT_INIT) || defined(MC_UIDGID_OLDSTYLE)
		kgid_t gid = {
			.val = identity->gid,
		};

#else
		kgid_t gid = {
			.val = identity->gid,
		};
#endif
		/* Check if gid is one of: egid of the process, its rgid or one
		 * of its supplementary groups */
		if (!in_egroup_p(gid) && !in_group_p(gid)) {
			mc_dev_devel("group %d not allowed\n", identity->gid);
=======
	if ((identity->login_type == LOGIN_USER) ||
	    (identity->login_type == LOGIN_USER_APPLICATION)) {
		/* Set euid and ruid of the process. */
		mcp_id->uid.euid = __kuid_val(task_euid(task));
		mcp_id->uid.ruid = __kuid_val(task_uid(task));
	}

	/* Check gid field */
	if ((identity->login_type == LOGIN_GROUP) ||
	    (identity->login_type == LOGIN_GROUP_APPLICATION)) {
		const struct cred *cred = __task_cred(task);

		/*
		 * Check if gid is one of: egid of the process, its rgid or one
		 * of its supplementary groups
		 */
		if (!has_group(cred, identity->gid)) {
			rcu_read_unlock();
			mc_dev_err("group %d not allowed\n", identity->gid);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			return -EACCES;
		}

		mc_dev_devel("group %d found\n", identity->gid);
		mcp_id->gid = identity->gid;
	}
<<<<<<< HEAD

	switch (identity->login_type) {
	case TEEC_LOGIN_PUBLIC:
	case TEEC_LOGIN_USER:
	case TEEC_LOGIN_GROUP:
		break;
	case TEEC_LOGIN_APPLICATION:
=======
	rcu_read_unlock();

	switch (identity->login_type) {
	case LOGIN_PUBLIC:
	case LOGIN_USER:
	case LOGIN_GROUP:
		break;
	case LOGIN_APPLICATION:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		application = true;
		data = NULL;
		data_len = 0;
		break;
<<<<<<< HEAD
	case TEEC_LOGIN_USER_APPLICATION:
=======
	case LOGIN_USER_APPLICATION:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		application = true;
		data = &mcp_id->uid;
		data_len = sizeof(mcp_id->uid);
		break;
<<<<<<< HEAD
	case TEEC_LOGIN_GROUP_APPLICATION:
=======
	case LOGIN_GROUP_APPLICATION:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		application = true;
		data = &identity->gid;
		data_len = sizeof(identity->gid);
		break;
	default:
		/* Any other login_type value is invalid. */
		mc_dev_err("Invalid login type %d\n", identity->login_type);
		return -EINVAL;
	}

	if (application) {
<<<<<<< HEAD
		if (hash_path_and_data(hash, data, data_len)) {
=======
		if (hash_path_and_data(task, hash, data, data_len)) {
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			mc_dev_devel("error in hash calculation\n");
			return -EAGAIN;
		}

		memcpy(&mcp_id->login_data, hash, sizeof(mcp_id->login_data));
	}

	return 0;
}

/*
 * Create a session object.
 * Note: object is not attached to client yet.
 */
struct tee_session *session_create(struct tee_client *client, bool is_gp,
				   struct mc_identity *identity)
{
	struct tee_session *session;
	struct identity mcp_identity;

	if (is_gp) {
		/* Check identity method and data. */
		int ret = check_prepare_identity(identity, &mcp_identity);

		if (ret)
			return ERR_PTR(ret);
	}

	/* Allocate session object */
	session = kzalloc(sizeof(*session), GFP_KERNEL);
	if (!session)
		return ERR_PTR(-ENOMEM);

	/* Increment debug counter */
	atomic_inc(&g_ctx.c_sessions);
	mutex_init(&session->close_lock);
<<<<<<< HEAD
=======
	init_completion(&session->close_completion);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	/* Initialise object members */
	mcp_session_init(&session->mcp_session, is_gp, &mcp_identity);
	INIT_WORK(&session->mcp_session.close_work, session_close_worker);
	client_get(client);
	session->client = client;
	kref_init(&session->kref);
	INIT_LIST_HEAD(&session->list);
	mutex_init(&session->wsms_lock);
	INIT_LIST_HEAD(&session->wsms);
	mc_dev_devel("created session %p: client %p\n",
		     session, session->client);
	return session;
}

int session_open(struct tee_session *session, const struct tee_object *obj,
		 const struct tee_mmu *obj_mmu, uintptr_t tci, size_t len)
{
	struct mcp_buffer_map map;

	tee_mmu_buffer(obj_mmu, &map);
	/* Create wsm object for tci */
	if (tci && len) {
		struct wsm *wsm;
		struct mcp_buffer_map tci_map;
		int ret = 0;

<<<<<<< HEAD
		mutex_lock(&session->wsms_lock);
		wsm = wsm_create(session, tci, len);
		if (IS_ERR(wsm))
			ret = PTR_ERR(wsm);

		mutex_unlock(&session->wsms_lock);
		if (ret)
			return ret;
=======
		wsm = wsm_create(session, tci, len);
		if (IS_ERR(wsm))
			return PTR_ERR(wsm);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

		tee_mmu_buffer(wsm->mmu, &tci_map);
		ret = mcp_open_session(&session->mcp_session, obj, &map,
				       &tci_map);
		if (ret) {
<<<<<<< HEAD
			mutex_lock(&session->wsms_lock);
			wsm_free(session, wsm);
			mutex_unlock(&session->wsms_lock);
		}

		return ret;
=======
			wsm_free(session, wsm);
			return ret;
		}

		mutex_lock(&session->wsms_lock);
		list_add_tail(&wsm->list, &session->wsms);
		mutex_unlock(&session->wsms_lock);
		return 0;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	if (tci || len) {
		mc_dev_err("Tci pointer and length are incoherent\n");
		return -EINVAL;
	}

	return mcp_open_session(&session->mcp_session, obj, &map, NULL);
}

/*
 * Close TA and unreference session object.
 * Object will be freed if reference reaches 0.
 * Session object is assumed to have been removed from main list, which means
 * that session_close cannot be called anymore.
 */
int session_close(struct tee_session *session)
{
	int ret = 0;

	mutex_lock(&session->close_lock);
	switch (mcp_close_session(&session->mcp_session)) {
	case 0:
<<<<<<< HEAD
		/* TA is closed, remove from client's closing list */
		mutex_lock(&session->client->sessions_lock);
		list_del(&session->list);
		mutex_unlock(&session->client->sessions_lock);
		/* Remove the ref we took on creation, exit if session freed */
		if (session_put(session))
			return 0;

		break;
	case -EBUSY:
		/*
		 * (GP) TA needs time to close. The "TA closed" notification
		 * will trigger a new call to session_close().
		 * Return OK but do not unref.
		 */
=======
		break;
	case -EAGAIN:
		/*
		 * GP TAs need time to close. The "TA closed" notification shall
		 * trigger the session_close_worker which will unblock us
		 */
		 mc_dev_devel("wait for session %x worker",
			     session->mcp_session.id);
		wait_for_completion(&session->close_completion);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		break;
	default:
		mc_dev_err("failed to close session %x in SWd\n",
			   session->mcp_session.id);
		ret = -EPERM;
	}

	mutex_unlock(&session->close_lock);
<<<<<<< HEAD
=======
	if (ret)
			return ret;

		mc_dev_devel("closed session %x", session->mcp_session.id);
		/* Remove session from client's closing list */
		mutex_lock(&session->client->sessions_lock);
		list_del(&session->list);
		mutex_unlock(&session->client->sessions_lock);

		/* Remove the ref we took on creation */
		session_put(session);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	return ret;
}

/*
 * Free session object and all objects it contains (wsm).
 */
static void session_release(struct kref *kref)
{
	struct tee_session *session;
	struct wsm *wsm, *next;

	/* Remove remaining shared buffers (unmapped in SWd by mcp_close) */
	session = container_of(kref, struct tee_session, kref);
	list_for_each_entry_safe(wsm, next, &session->wsms, list) {
		mc_dev_devel("session %p: free wsm %p\n", session, wsm);
<<<<<<< HEAD
=======
		if (wsm->sva)
			atomic_dec(&g_ctx.c_maps);

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		wsm_free(session, wsm);
	}

	mc_dev_devel("freed session %p: client %p id %x\n",
		     session, session->client, session->mcp_session.id);
	client_put(session->client);
	kfree(session);
	/* Decrement debug counter */
	atomic_dec(&g_ctx.c_sessions);
}

/*
 * Unreference session.
 * Free session object if reference reaches 0.
 */
int session_put(struct tee_session *session)
{
	return kref_put(&session->kref, session_release);
}

/*
 * Session is to be removed from NWd records as SWd is dead
 */
int session_kill(struct tee_session *session)
{
	mcp_kill_session(&session->mcp_session);
	return session_put(session);
}

/*
 * Send a notification to TA
 */
int session_notify_swd(struct tee_session *session)
{
	if (!session) {
		mc_dev_err("Session pointer is null\n");
		return -EINVAL;
	}

	return mcp_notify(&session->mcp_session);
}

/*
 * Read and clear last notification received from TA
 */
s32 session_exitcode(struct tee_session *session)
{
	return mcp_session_exitcode(&session->mcp_session);
}

<<<<<<< HEAD
static inline int wsm_check(struct tee_session *session,
			    struct mc_ioctl_buffer *buf)
{
	struct wsm *wsm;

	list_for_each_entry(wsm, &session->wsms, list) {
		if ((buf->va < (wsm->va + wsm->len)) &&
		    ((buf->va + buf->len) > wsm->va)) {
			mc_dev_err("buffer %lx overlaps with existing wsm\n",
				   wsm->va);
			return -EADDRINUSE;
		}
	}

	return 0;
}

static inline struct wsm *wsm_find(struct tee_session *session, uintptr_t va)
{
	struct wsm *wsm;

	list_for_each_entry(wsm, &session->wsms, list)
		if (wsm->va == va)
			return wsm;

	return NULL;
}

=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
static inline int wsm_debug_structs(struct kasnprintf_buf *buf, struct wsm *wsm)
{
	ssize_t ret;

<<<<<<< HEAD
	ret = kasnprintf(buf, "\t\twsm %p: mmu %p cbuf %p va %lx len %u\n",
			 wsm, wsm->mmu, wsm->cbuf, wsm->va, wsm->len);
=======
	ret = kasnprintf(buf,
			 "\t\twsm %p: mmu %pK cbuf %pK va %pK len %u sva %x\n",
			 wsm, wsm->mmu, wsm->cbuf, (void *)wsm->va, wsm->len, wsm->sva);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	if (ret < 0)
		return ret;

	if (wsm->mmu) {
		ret = tee_mmu_debug_structs(buf, wsm->mmu);
		if (ret < 0)
			return ret;
	}

	return 0;
}

/*
 * Share buffers with SWd and add corresponding WSM objects to session.
 */
int session_wsms_add(struct tee_session *session,
		     struct mc_ioctl_buffer *bufs)
{
<<<<<<< HEAD
	struct mc_ioctl_buffer *buf;
	struct mcp_buffer_map maps[MC_MAP_MAX];
	struct mcp_buffer_map *map;
	int i, ret = 0;
	u32 n_null_buf = 0;
=======
	struct wsm *wsms[MC_MAP_MAX] = { 0 };
	struct mcp_buffer_map maps[MC_MAP_MAX];
	int i, ret = 0;
	bool at_least_one = false;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* Check parameters */
	if (!session)
		return -ENXIO;

<<<<<<< HEAD
	/* Lock the session */
	mutex_lock(&session->wsms_lock);

	for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX; i++, buf++, map++) {
		if (!buf->va) {
			n_null_buf++;
			continue;
		}

		/* Avoid mapping overlaps */
		if (wsm_check(session, buf)) {
			ret = -EADDRINUSE;
			mc_dev_err("maps[%d] va=%llx already map'd\n",
				   i, buf->va);
			goto unlock;
		}
	}

	if (n_null_buf >= MC_MAP_MAX) {
		ret = -EINVAL;
		mc_dev_err("va=NULL\n");
		goto unlock;
	}

	for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX; i++, buf++, map++) {
		struct wsm *wsm;

		if (!buf->va) {
			map->type = WSM_INVALID;
			continue;
		}

		wsm = wsm_create(session, buf->va, buf->len);
		if (IS_ERR(wsm)) {
			ret = PTR_ERR(wsm);
			mc_dev_err("maps[%d] va=%llx create failed: %d\n",
				   i, buf->va, ret);
			goto end;
		}

		tee_mmu_buffer(wsm->mmu, map);
		mc_dev_devel("maps[%d] va=%llx: t:%u a:%llx o:%u l:%u\n",
			     i, buf->va, map->type, map->phys_addr, map->offset,
			     map->length);
=======
	/* Create MMU and map for each buffer */
	for (i = 0; i < MC_MAP_MAX; i++) {
		if (!bufs[i].va) {
			maps[i].type = WSM_INVALID;
			continue;
		}

		wsms[i] = wsm_create(session, bufs[i].va, bufs[i].len);
		if (IS_ERR(wsms[i])) {
			ret = PTR_ERR(wsms[i]);
			mc_dev_err("maps[%d] va=%llx create failed: %d\n",
				   i, bufs[i].va, ret);
			goto err;
		}

		tee_mmu_buffer(wsms[i]->mmu, &maps[i]);
		mc_dev_devel("maps[%d] va=%llx: t:%u a:%llx o:%u l:%u\n",
			     i, bufs[i].va, maps[i].type, maps[i].phys_addr,
			     maps[i].offset, maps[i].length);
		at_least_one = true;
	}

	if (!at_least_one) {
		mc_dev_err("no buffers to map\n");
		return -EINVAL;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

	/* Map buffers */
	if (g_ctx.f_multimap) {
		/* Send MCP message to map buffers in SWd */
		ret = mcp_multimap(session->mcp_session.id, maps);
<<<<<<< HEAD
		if (ret)
			mc_dev_err("multimap failed: %d\n", ret);
	} else {
		/* Map each buffer */
		for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX; i++, buf++,
		     map++) {
			if (!buf->va)
				continue;

			/* Send MCP message to map buffer in SWd */
			ret = mcp_map(session->mcp_session.id, map);
			if (ret) {
				mc_dev_err("maps[%d] va=%llx map failed: %d\n",
					   i, buf->va, ret);
				break;
			}
		}
	}

end:
	for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX; i++, buf++, map++) {
		struct wsm *wsm = wsm_find(session, buf->va);

		if (!buf->va)
			continue;

		if (ret) {
			if (!wsm)
				break;

			/* Destroy mapping */
			wsm_free(session, wsm);
		} else {
			/* Store mapping */
			buf->sva = map->secure_va;
			wsm->sva = buf->sva;
			mc_dev_devel("maps[%d] va=%llx map'd len=%u sva=%llx\n",
				     i, buf->va, buf->len, buf->sva);
		}
	}

unlock:
	/* Unlock the session */
	mutex_unlock(&session->wsms_lock);
	return ret;
}

=======
		if (ret) {
			mc_dev_err("multimap failed: %d\n", ret);
			goto err;
		}

		for (i = 0; i < MC_MAP_MAX; i++) {
			if (!wsms[i])
				continue;

			wsms[i]->sva = maps[i].secure_va;
			atomic_inc(&g_ctx.c_maps);
		}
	} else {
		/* Map each buffer */
		for (i = 0; i < MC_MAP_MAX; i++) {
			if (!wsms[i])
				continue;

			/* Send MCP message to map buffer in SWd */
			ret = mcp_map(session->mcp_session.id, &maps[i]);
			if (ret) {
				mc_dev_err("maps[%d] va=%llx map failed: %d\n",
					   i, bufs[i].va, ret);
				break;
			}

			wsms[i]->sva = maps[i].secure_va;
			atomic_inc(&g_ctx.c_maps);
		}

		/* Unmap what was mapped on failure */
		if (ret) {
			for (i = 0; i < MC_MAP_MAX; i++) {
				if (!wsms[i] || !wsms[i]->sva)
					continue;

				if (mcp_unmap(session->mcp_session.id,
					      &maps[i]))
					mc_dev_err("unmap failed: %d\n", ret);
				else
					atomic_dec(&g_ctx.c_maps);
			}

			goto err;
		}
	}

	for (i = 0; i < MC_MAP_MAX; i++) {
		if (!wsms[i])
			continue;

		/* Store WSM into session */
		mutex_lock(&session->wsms_lock);
		list_add_tail(&wsms[i]->list, &session->wsms);
		mutex_unlock(&session->wsms_lock);
		bufs[i].sva = wsms[i]->sva;
		mc_dev_devel("maps[%d] va=%llx map'd len=%u sva=%llx\n",
			     i, bufs[i].va, bufs[i].len, bufs[i].sva);
	}

	return 0;

err:
	for (i = 0; i < MC_MAP_MAX; i++)
		if (!IS_ERR_OR_NULL(wsms[i]))
			wsm_free(session, wsms[i]);

	return ret;
}

static inline struct wsm *wsm_find(struct tee_session *session, uintptr_t sva)
{
	struct wsm *wsm;

	list_for_each_entry(wsm, &session->wsms, list)
		if (wsm->sva == sva)
			return wsm;

	return NULL;
}

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
/*
 * Stop sharing buffers and delete corrsponding WSM objects.
 */
int session_wsms_remove(struct tee_session *session,
			const struct mc_ioctl_buffer *bufs)
{
<<<<<<< HEAD
	const struct mc_ioctl_buffer *buf;
	struct mcp_buffer_map maps[MC_MAP_MAX];
	struct mcp_buffer_map *map;
	int i, ret = 0;
	u32 n_null_buf = 0;
=======
	struct wsm *wsms[MC_MAP_MAX] = { 0 };
	struct mcp_buffer_map maps[MC_MAP_MAX];
	int i, ret = 0;
	bool at_least_one = false;
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	if (!session) {
		mc_dev_err("session pointer is null\n");
		return -EINVAL;
	}

<<<<<<< HEAD
	/* Lock the session */
	mutex_lock(&session->wsms_lock);

	/* Find, check and map buffer */
	for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX; i++, buf++, map++) {
		struct wsm *wsm;

		if (!buf->va) {
			n_null_buf++;
			map->secure_va = 0;
			continue;
		}

		wsm = wsm_find(session, buf->va);
		if (!wsm) {
			ret = -EADDRNOTAVAIL;
			mc_dev_err("maps[%d] va=%llx not found\n", i, buf->va);
			goto out;
		}

		/* Check input params consistency */
		if ((wsm->sva != buf->sva) || (wsm->len != buf->len)) {
			mc_dev_err("maps[%d] va=%llx no match: %x != %llx\n",
				   i, buf->va, wsm->sva, buf->sva);
			mc_dev_err("maps[%d] va=%llx no match: %u != %u\n",
				   i, buf->va, wsm->len, buf->len);
			ret = -EINVAL;
			goto out;
		}

		tee_mmu_buffer(wsm->mmu, map);
		map->secure_va = buf->sva;
		mc_dev_devel("maps[%d] va=%llx: t:%u a:%llx o:%u l:%u s:%llx\n",
			     i, buf->va, map->type, map->phys_addr, map->offset,
			     map->length, map->secure_va);
	}

	if (n_null_buf >= MC_MAP_MAX) {
		ret = -EINVAL;
		mc_dev_err("va=NULL\n");
=======
	mutex_lock(&session->wsms_lock);

	/* Find, check and map buffer */
	for (i = 0; i < MC_MAP_MAX; i++) {
		struct wsm *wsm;

		if (!bufs[i].va) {
			maps[i].secure_va = 0;
			continue;
		}

		wsm = wsm_find(session, bufs[i].sva);
		if (!wsm) {
			ret = -EINVAL;
			mc_dev_err("maps[%d] va=%llx sva=%llx not found\n",
				   i, bufs[i].va, bufs[i].sva);
			goto out;
		}

		/* Check VA */
		if (wsm->va != bufs[i].va) {
			ret = -EINVAL;
			mc_dev_err("maps[%d] va=%llx does not match %lx\n",
				   i, bufs[i].va, wsm->va);
			goto out;
		}

		/* Check length */
		if (wsm->len != bufs[i].len) {
			ret = -EINVAL;
			mc_dev_err("maps[%d] va=%llx len mismatch: %u != %u\n",
				   i, bufs[i].va, wsm->len, bufs[i].len);
			goto out;
		}

		wsms[i] = wsm;
		tee_mmu_buffer(wsms[i]->mmu, &maps[i]);
		maps[i].secure_va = wsms[i]->sva;
		mc_dev_devel("maps[%d] va=%llx: t:%u a:%llx o:%u l:%u s:%llx\n",
			     i, bufs[i].va, maps[i].type, maps[i].phys_addr,
			     maps[i].offset, maps[i].length, maps[i].secure_va);
		at_least_one = true;
	}

	if (!at_least_one) {
		ret = -EINVAL;
		mc_dev_err("no buffers to unmap\n");
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		goto out;
	}

	if (g_ctx.f_multimap) {
		/* Send MCP command to unmap buffers in SWd */
		ret = mcp_multiunmap(session->mcp_session.id, maps);
<<<<<<< HEAD
		if (ret)
			mc_dev_err("mcp_multiunmap failed: %d\n", ret);
	} else {
		for (i = 0, buf = bufs, map = maps; i < MC_MAP_MAX;
		     i++, buf++, map++) {
			if (!buf->va)
				continue;

			/* Send MCP command to unmap buffer in SWd */
			ret = mcp_unmap(session->mcp_session.id, map);
			if (ret) {
				mc_dev_err(
					"maps[%d] va=%llx unmap failed: %d\n",
					i, buf->va, ret);
				break;
=======
		if (ret) {
			mc_dev_err("mcp_multiunmap failed: %d\n", ret);
		} else {
			for (i = 0; i < MC_MAP_MAX; i++)
				if (maps[i].secure_va)
					atomic_dec(&g_ctx.c_maps);
		}
	} else {
		for (i = 0; i < MC_MAP_MAX; i++) {
			if (!maps[i].secure_va)
				continue;

			/* Send MCP command to unmap buffer in SWd */
			ret = mcp_unmap(session->mcp_session.id, &maps[i]);
			if (ret) {
				mc_dev_err(
					"maps[%d] va=%llx unmap failed: %d\n",
					i, bufs[i].va, ret);
				/* Keep going */
			} else {
				atomic_dec(&g_ctx.c_maps);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			}
		}
	}

<<<<<<< HEAD
	for (i = 0, buf = bufs; i < MC_MAP_MAX; i++, buf++) {
		struct wsm *wsm = wsm_find(session, buf->va);

		if (!wsm)
			break;

		/* Free wsm */
		wsm_free(session, wsm);
		mc_dev_devel("maps[%d] va=%llx unmap'd len=%u sva=%llx\n",
			     i, buf->va, buf->len, buf->sva);
=======
	for (i = 0; i < MC_MAP_MAX; i++) {
		if (!wsms[i])
			continue;

		/* Remove wsm from its parent session's list */
		list_del(&wsms[i]->list);
		/* Free wsm */
		wsm_free(session, wsms[i]);
		mc_dev_devel("maps[%d] va=%llx unmap'd len=%u sva=%llx\n",
			     i, bufs[i].va, bufs[i].len, bufs[i].sva);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	}

out:
	mutex_unlock(&session->wsms_lock);
	return ret;
}

/*
 * Sleep until next notification from SWd.
 */
<<<<<<< HEAD
int session_waitnotif(struct tee_session *session, s32 timeout)
{
	return mcp_session_waitnotif(&session->mcp_session, timeout);
=======
int session_waitnotif(struct tee_session *session, s32 timeout,
		      bool silent_expiry)
{
	return mcp_session_waitnotif(&session->mcp_session, timeout,
				     silent_expiry);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

int session_debug_structs(struct kasnprintf_buf *buf,
			  struct tee_session *session, bool is_closing)
{
	struct wsm *wsm;
	s32 exit_code;
	int ret;

	exit_code = mcp_session_exitcode(&session->mcp_session);
<<<<<<< HEAD
	ret = kasnprintf(buf, "\tsession %p [%d]: %x %s ec %d%s\n", session,
=======
	ret = kasnprintf(buf, "\tsession %pK [%d]: %x %s ec %d%s\n", session,
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
			 kref_read(&session->kref), session->mcp_session.id,
			 session->mcp_session.is_gp ? "GP" : "MC", exit_code,
			 is_closing ? " <closing>" : "");
	if (ret < 0)
		return ret;

	/* WMSs */
	mutex_lock(&session->wsms_lock);
	if (list_empty(&session->wsms))
		goto done;

	list_for_each_entry(wsm, &session->wsms, list) {
		ret = wsm_debug_structs(buf, wsm);
		if (ret < 0)
			goto done;
	}

done:
	mutex_unlock(&session->wsms_lock);
	if (ret < 0)
		return ret;

	return 0;
}
