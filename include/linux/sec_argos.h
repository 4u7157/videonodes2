#ifndef _SEC_ARGOS_H
#define _SEC_ARGOS_H

extern int irq_set_affinity(unsigned int irq, const struct cpumask *mask);
<<<<<<< HEAD
extern void argos_dm_hotplug_enable(void);
extern void argos_dm_hotplug_disable(void);
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

extern int sec_argos_register_notifier(struct notifier_block *n, char *label);
extern int sec_argos_unregister_notifier(struct notifier_block *n, char *label);

#endif
