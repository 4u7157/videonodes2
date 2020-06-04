#include <linux/device.h>

#include <linux/notifier.h>
#include <linux/muic/muic.h>
#include <linux/muic/muic_notifier.h>
#include <linux/sec_sysfs.h>

<<<<<<< HEAD
=======
/*
  * The src & dest addresses of the noti.
  * keep the same value defined in ccic_notifier.h
  *     b'0001 : CCIC
  *     b'0010 : MUIC
  *     b'1111 : Broadcasting
  */
#define NOTI_ADDR_SRC (1 << 1)
#define NOTI_ADDR_DST (0xf)

/* ATTACH Noti. ID */
#define NOTI_ID_ATTACH (1)


>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#define SET_MUIC_NOTIFIER_BLOCK(nb, fn, dev) do {	\
		(nb)->notifier_call = (fn);		\
		(nb)->priority = (dev);			\
	} while (0)

#define DESTROY_MUIC_NOTIFIER_BLOCK(nb)			\
		SET_MUIC_NOTIFIER_BLOCK(nb, NULL, -1)

static struct muic_notifier_struct muic_notifier;
<<<<<<< HEAD

struct device *switch_device;

=======
#if defined(CONFIG_CCIC_S2MU004)
static struct muic_notifier_struct muic_ccic_notifier;
#endif

struct device *switch_device;

static int muic_uses_new_noti;
#if defined(CONFIG_CCIC_S2MU004)
static int muic_ccic_uses_new_noti;
#endif

void muic_notifier_set_new_noti(bool flag)
{
	muic_uses_new_noti = flag ? 1: 0;
}

static void __set_noti_cxt(int attach, int type)
{
	if (type < 0) {
		muic_notifier.cmd = attach;
#if defined(CONFIG_CCIC_NOTIFIER)
		muic_notifier.cxt.attach = attach;
#endif
		return;
	}

	/* Old Interface */
	muic_notifier.cmd = attach;
	muic_notifier.attached_dev = type;

#if defined(CONFIG_CCIC_NOTIFIER)
	/* New Interface */
	muic_notifier.cxt.src = NOTI_ADDR_SRC;
	muic_notifier.cxt.dest = NOTI_ADDR_DST;
	muic_notifier.cxt.id = NOTI_ID_ATTACH;
	muic_notifier.cxt.attach = attach;
	muic_notifier.cxt.cable_type = type;
	muic_notifier.cxt.rprd = 0;
#endif
}

#if defined(CONFIG_CCIC_S2MU004)
static void __set_ccic_noti_cxt(int attach, int type)
{
	if (type < 0) {
		muic_ccic_notifier.cmd = attach;
#if defined(CONFIG_CCIC_NOTIFIER)
		muic_ccic_notifier.cxt.attach = attach;
#endif
		return;
	}

	/* Old Interface */
	muic_ccic_notifier.cmd = attach;
	muic_ccic_notifier.attached_dev = type;

#if defined(CONFIG_CCIC_NOTIFIER)
	/* New Interface */
	muic_ccic_notifier.cxt.src = NOTI_ADDR_SRC;
	muic_ccic_notifier.cxt.dest = NOTI_ADDR_DST;
	muic_ccic_notifier.cxt.id = NOTI_ID_ATTACH;
	muic_ccic_notifier.cxt.attach = attach;
	muic_ccic_notifier.cxt.cable_type = type;
	muic_ccic_notifier.cxt.rprd = 0;
#endif
}
#endif

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
int muic_notifier_register(struct notifier_block *nb, notifier_fn_t notifier,
			muic_notifier_device_t listener)
{
	int ret = 0;
<<<<<<< HEAD

	printk(KERN_DEBUG "[muic] %s: listener=%d\n", __func__, listener);
=======
#if defined(CONFIG_CCIC_NOTIFIER)
	void *pcxt;;
#endif

	pr_info("%s: listener=%d register\n", __func__, listener);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	SET_MUIC_NOTIFIER_BLOCK(nb, notifier, listener);
	ret = blocking_notifier_chain_register(&(muic_notifier.notifier_call_chain), nb);
	if (ret < 0)
<<<<<<< HEAD
		printk(KERN_ERR "[muic] notifier_chain_register error(%d)\n", ret);

	/* current muic's attached_device status notify */
	nb->notifier_call(nb, muic_notifier.cmd,
			&(muic_notifier.attached_dev));
=======
		pr_err("%s: blocking_notifier_chain_register error(%d)\n",
				__func__, ret);

#if defined(CONFIG_CCIC_NOTIFIER)
	pcxt = muic_uses_new_noti ? &(muic_notifier.cxt) : \
			(void *)&(muic_notifier.attached_dev);

	/* current muic's attached_device status notify */
	nb->notifier_call(nb, muic_notifier.cxt.attach, pcxt);
#else
	nb->notifier_call(nb, muic_notifier.cmd,
			&(muic_notifier.attached_dev));
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	return ret;
}

int muic_notifier_unregister(struct notifier_block *nb)
{
	int ret = 0;

<<<<<<< HEAD
	printk(KERN_DEBUG "[muic] %s: listener=%d unregister\n", __func__, nb->priority);

	ret = blocking_notifier_chain_unregister(&(muic_notifier.notifier_call_chain), nb);
	if (ret < 0)
		printk(KERN_ERR "[muic] notifier_chain_unregister error(%d)\n", ret);
=======
	pr_info("%s: listener=%d unregister\n", __func__, nb->priority);

	ret = blocking_notifier_chain_unregister(&(muic_notifier.notifier_call_chain), nb);
	if (ret < 0)
		pr_err("%s: blocking_notifier_chain_unregister error(%d)\n",
				__func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	DESTROY_MUIC_NOTIFIER_BLOCK(nb);

	return ret;
}

static int muic_notifier_notify(void)
{
	int ret = 0;
<<<<<<< HEAD

	printk(KERN_DEBUG "[muic] %s: CMD=%d, DATA=%d\n", __func__, muic_notifier.cmd,
			muic_notifier.attached_dev);

#ifdef CONFIG_SEC_FACTORY
	if (muic_notifier.cmd != 0)
		muic_send_attached_muic_cable_intent(muic_notifier.attached_dev);
	else
		muic_send_attached_muic_cable_intent(0);
#endif
	ret = blocking_notifier_call_chain(&(muic_notifier.notifier_call_chain),
			muic_notifier.cmd, &(muic_notifier.attached_dev));
=======
#if defined(CONFIG_CCIC_NOTIFIER)
	void *pcxt;

	pr_info("%s: CMD=%d, DATA=%d\n", __func__, muic_notifier.cxt.attach,
			muic_notifier.cxt.cable_type);

#ifdef CONFIG_SEC_FACTORY
	if(muic_notifier.cxt.attach != 0)
		muic_send_attached_muic_cable_intent(muic_notifier.cxt.cable_type);
	else
		muic_send_attached_muic_cable_intent(0);
#endif

	pcxt = muic_uses_new_noti ? &(muic_notifier.cxt) : \
			(void *)&(muic_notifier.attached_dev);

	ret = blocking_notifier_call_chain(&(muic_notifier.notifier_call_chain),
			muic_notifier.cxt.attach, pcxt);
#else
	pr_info("%s: CMD=%d, DATA=%d\n", __func__, muic_notifier.cmd,
			muic_notifier.attached_dev);
	ret = blocking_notifier_call_chain(&(muic_notifier.notifier_call_chain),
			muic_notifier.cmd, &(muic_notifier.attached_dev));
#endif

	switch (ret) {
	case NOTIFY_STOP_MASK:
	case NOTIFY_BAD:
		pr_err("%s: notify error occur(0x%x)\n", __func__, ret);
		break;
	case NOTIFY_DONE:
	case NOTIFY_OK:
		pr_info("%s: notify done(0x%x)\n", __func__, ret);
		break;
	default:
		pr_info("%s: notify status unknown(0x%x)\n", __func__, ret);
		break;
	}

	return ret;
}

#if defined(CONFIG_CCIC_S2MU004)
int muic_ccic_notifier_register(struct notifier_block *nb, notifier_fn_t notifier,
			muic_notifier_device_t listener)
{
	int ret = 0;
#if defined(CONFIG_CCIC_NOTIFIER)
	void *pcxt;;
#endif

	pr_info("%s: listener=%d register\n", __func__, listener);

	SET_MUIC_NOTIFIER_BLOCK(nb, notifier, listener);
	ret = blocking_notifier_chain_register(&(muic_ccic_notifier.notifier_call_chain), nb);
	if (ret < 0)
		pr_err("%s: blocking_notifier_chain_register error(%d)\n",
				__func__, ret);

#if defined(CONFIG_CCIC_NOTIFIER)
	pcxt = muic_ccic_uses_new_noti ? &(muic_ccic_notifier.cxt) : \
			(void *)&(muic_ccic_notifier.attached_dev);

	/* current muic's attached_device status notify */
	nb->notifier_call(nb, muic_ccic_notifier.cxt.attach, pcxt);
#else
	nb->notifier_call(nb, muic_ccic_notifier.cmd,
			&(muic_ccic_notifier.attached_dev));
#endif

	return ret;
}

int muic_ccic_notifier_unregister(struct notifier_block *nb)
{
	int ret = 0;

	pr_info("%s: listener=%d unregister\n", __func__, nb->priority);

	ret = blocking_notifier_chain_unregister(&(muic_ccic_notifier.notifier_call_chain), nb);
	if (ret < 0)
		pr_err("%s: blocking_notifier_chain_unregister error(%d)\n",
				__func__, ret);
	DESTROY_MUIC_NOTIFIER_BLOCK(nb);

	return ret;
}

static int muic_ccic_notifier_notify(void)
{
	int ret = 0;
#if defined(CONFIG_CCIC_NOTIFIER)
	void *pcxt;

	pr_info("%s: CMD=%d, DATA=%d\n", __func__, muic_ccic_notifier.cxt.attach,
			muic_ccic_notifier.cxt.cable_type);

	pcxt = muic_ccic_uses_new_noti ? &(muic_ccic_notifier.cxt) : \
			(void *)&(muic_ccic_notifier.attached_dev);

	ret = blocking_notifier_call_chain(&(muic_ccic_notifier.notifier_call_chain),
			muic_ccic_notifier.cxt.attach, pcxt);
#else
	pr_info("%s: CMD=%d, DATA=%d\n", __func__, muic_ccic_notifier.cmd,
			muic_ccic_notifier.attached_dev);
	ret = blocking_notifier_call_chain(&(muic_ccic_notifier.notifier_call_chain),
			muic_ccic_notifier.cmd, &(muic_ccic_notifier.attached_dev));
#endif
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	switch (ret) {
	case NOTIFY_STOP_MASK:
	case NOTIFY_BAD:
<<<<<<< HEAD
		printk(KERN_ERR "[muic] %s: notify error occur(0x%x)\n", __func__, ret);
		break;
	case NOTIFY_DONE:
	case NOTIFY_OK:
		printk(KERN_DEBUG "[muic] %s: notify done(0x%x)\n", __func__, ret);
		break;
	default:
		printk(KERN_DEBUG "[muic] %s: notify status unknown(0x%x)\n", __func__, ret);
=======
		pr_err("%s: notify error occur(0x%x)\n", __func__, ret);
		break;
	case NOTIFY_DONE:
	case NOTIFY_OK:
		pr_info("%s: notify done(0x%x)\n", __func__, ret);
		break;
	default:
		pr_info("%s: notify status unknown(0x%x)\n", __func__, ret);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
		break;
	}

	return ret;
}
<<<<<<< HEAD

void muic_notifier_attach_attached_dev(muic_attached_dev_t new_dev)
{
	printk(KERN_DEBUG "[muic] %s: (%d)\n", __func__, new_dev);

	muic_notifier.cmd = MUIC_NOTIFY_CMD_ATTACH;
	muic_notifier.attached_dev = new_dev;
=======
#endif

void muic_notifier_attach_attached_dev(muic_attached_dev_t new_dev)
{
	pr_info("%s: (%d)\n", __func__, new_dev);

	__set_noti_cxt(MUIC_NOTIFY_CMD_ATTACH, new_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* muic's attached_device attach broadcast */
	muic_notifier_notify();
}

<<<<<<< HEAD
void muic_notifier_detach_attached_dev(muic_attached_dev_t cur_dev)
{
	printk(KERN_DEBUG "[muic] %s: (%d)\n", __func__, cur_dev);

	muic_notifier.cmd = MUIC_NOTIFY_CMD_DETACH;

	if (muic_notifier.attached_dev != cur_dev)
		printk(KERN_DEBUG "[muic] %s:  muic_notifier(%d) != muic_data(%d)\n",
=======
void muic_pdic_notifier_attach_attached_dev(muic_attached_dev_t new_dev)
{
	pr_info("%s: (%d)\n", __func__, new_dev);

#if defined(CONFIG_CCIC_S2MU004)
	__set_ccic_noti_cxt(MUIC_PDIC_NOTIFY_CMD_ATTACH, new_dev);

	/* muic's attached_device attach broadcast */
	muic_ccic_notifier_notify();
#else
	__set_noti_cxt(MUIC_PDIC_NOTIFY_CMD_ATTACH, new_dev);

	/* muic's attached_device attach broadcast */
	muic_notifier_notify();
#endif
}

void muic_pdic_notifier_detach_attached_dev(muic_attached_dev_t new_dev)
{
	pr_info("%s: (%d)\n", __func__, new_dev);

#if defined(CONFIG_CCIC_S2MU004)
	__set_ccic_noti_cxt(MUIC_PDIC_NOTIFY_CMD_DETACH, new_dev);

	/* muic's attached_device attach broadcast */
	muic_ccic_notifier_notify();
#else
	__set_noti_cxt(MUIC_PDIC_NOTIFY_CMD_DETACH, muic_notifier.attached_dev);
	/* muic's attached_device attach broadcast */
	muic_notifier_notify();
#endif
}

void muic_notifier_detach_attached_dev(muic_attached_dev_t cur_dev)
{
	pr_info("%s: (%d)\n", __func__, cur_dev);

	__set_noti_cxt(MUIC_NOTIFY_CMD_DETACH, -1);

#if defined(CONFIG_CCIC_NOTIFIER)
	if (muic_notifier.cxt.cable_type != cur_dev)
		pr_warn("%s: attached_dev of muic_notifier(%d) != muic_data(%d)\n",
				__func__, muic_notifier.cxt.cable_type, cur_dev);

	if (muic_notifier.cxt.cable_type != ATTACHED_DEV_NONE_MUIC) {
		/* muic's attached_device detach broadcast */
		muic_notifier_notify();
	}
#else
	if (muic_notifier.attached_dev != cur_dev)
		pr_warn("%s: attached_dev of muic_notifier(%d) != muic_data(%d)\n",
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
				__func__, muic_notifier.attached_dev, cur_dev);

	if (muic_notifier.attached_dev != ATTACHED_DEV_NONE_MUIC) {
		/* muic's attached_device detach broadcast */
		muic_notifier_notify();
	}
<<<<<<< HEAD

	muic_notifier.attached_dev = ATTACHED_DEV_NONE_MUIC;
=======
#endif

	__set_noti_cxt(0, ATTACHED_DEV_NONE_MUIC);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

void muic_notifier_logically_attach_attached_dev(muic_attached_dev_t new_dev)
{
<<<<<<< HEAD
	printk(KERN_DEBUG "[muic] %s: (%d)\n", __func__, new_dev);

	muic_notifier.cmd = MUIC_NOTIFY_CMD_LOGICALLY_ATTACH;
	muic_notifier.attached_dev = new_dev;
=======
	pr_info("%s: (%d)\n", __func__, new_dev);

	__set_noti_cxt(MUIC_NOTIFY_CMD_ATTACH, new_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* muic's attached_device attach broadcast */
	muic_notifier_notify();
}

void muic_notifier_logically_detach_attached_dev(muic_attached_dev_t cur_dev)
{
<<<<<<< HEAD
	printk(KERN_DEBUG "[muic] %s: (%d)\n", __func__, cur_dev);

	muic_notifier.cmd = MUIC_NOTIFY_CMD_LOGICALLY_DETACH;
	muic_notifier.attached_dev = cur_dev;
=======
	pr_info("%s: (%d)\n", __func__, cur_dev);

	__set_noti_cxt(MUIC_NOTIFY_CMD_DETACH, cur_dev);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

	/* muic's attached_device detach broadcast */
	muic_notifier_notify();

<<<<<<< HEAD
	muic_notifier.attached_dev = ATTACHED_DEV_NONE_MUIC;
=======
	__set_noti_cxt(0, ATTACHED_DEV_NONE_MUIC);
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
}

static int __init muic_notifier_init(void)
{
	int ret = 0;

<<<<<<< HEAD
	printk(KERN_DEBUG "[muic] %s\n", __func__);

#ifdef CONFIG_SEC_SYSFS
	switch_device = sec_device_create(NULL, "switch");
	if (IS_ERR(switch_device)) {
		printk(KERN_ERR "[muic] Failed to create device(switch)!\n");
		ret = -ENODEV;
		goto out;
	}
#endif

	BLOCKING_INIT_NOTIFIER_HEAD(&(muic_notifier.notifier_call_chain));
	muic_notifier.cmd = MUIC_NOTIFY_CMD_DETACH;
	muic_notifier.attached_dev = ATTACHED_DEV_UNKNOWN_MUIC;

#ifdef CONFIG_SEC_SYSFS
out:
#endif
=======
	pr_info("%s\n", __func__);
#if defined(CONFIG_CCIC_NOTIFIER)
	muic_uses_new_noti = 1;
#endif

	switch_device = sec_device_create(NULL, "switch");
	if (IS_ERR(switch_device)) {
		pr_err("%s Failed to create device(switch)!\n", __func__);
		ret = -ENODEV;
		goto out;
	}

	BLOCKING_INIT_NOTIFIER_HEAD(&(muic_notifier.notifier_call_chain));
	__set_noti_cxt(0 ,ATTACHED_DEV_UNKNOWN_MUIC);
#if defined(CONFIG_CCIC_S2MU004)
	BLOCKING_INIT_NOTIFIER_HEAD(&(muic_ccic_notifier.notifier_call_chain));
	__set_ccic_noti_cxt(0 ,ATTACHED_DEV_UNKNOWN_MUIC);
	muic_ccic_uses_new_noti = 1;
#endif

out:
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
	return ret;
}
device_initcall(muic_notifier_init);

