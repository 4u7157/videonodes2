#ifndef __PWRCAL_H__
#define __PWRCAL_H__
<<<<<<< HEAD
=======

>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef __cplusplus
extern "C" {
#endif

#define BLKPWR_MAGIC	0xB1380000

extern unsigned int cal_clk_get(char *name);
extern unsigned int cal_clk_is_enabled(unsigned int vclkid);
extern int cal_clk_setrate(unsigned int vclkid, unsigned long rate);
extern unsigned long cal_clk_getrate(unsigned int vclkid);
extern int cal_clk_enable(unsigned int vclkid);
extern int cal_clk_disable(unsigned int vclkid);


extern int cal_pd_control(unsigned int id, int on);
extern int cal_pd_status(unsigned int id);


extern int cal_pm_enter(int mode);
extern int cal_pm_exit(int mode);
extern int cal_pm_earlywakeup(int mode);

<<<<<<< HEAD
#ifdef CONFIG_PMUCAL_MOD
extern int cal_cpu_enable(unsigned int cpu);
extern int cal_cpu_disable(unsigned int cpu);
extern int cal_cpu_status(unsigned int cpu);
extern int cal_cluster_enable(unsigned int cluster);
extern int cal_cluster_disable(unsigned int cluster);
extern int cal_cluster_status(unsigned int cluster);
#endif
=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

extern unsigned int cal_dfs_get(char *name);
extern unsigned long cal_dfs_get_max_freq(unsigned int id);
extern unsigned long cal_dfs_get_min_freq(unsigned int id);
extern int cal_dfs_set_rate(unsigned int id, unsigned long rate);
extern int cal_dfs_set_rate_switch(unsigned int id, unsigned long switch_rate);
extern unsigned long cal_dfs_cached_get_rate(unsigned int id);
extern unsigned long cal_dfs_get_rate(unsigned int id);
extern int cal_dfs_get_rate_table(unsigned int id, unsigned long *table);
extern int cal_dfs_get_asv_table(unsigned int id, unsigned int *table);


struct dvfs_rate_volt {
	unsigned long rate;
	unsigned int volt;
};
int cal_dfs_get_rate_asv_table(unsigned int id,
					struct dvfs_rate_volt *table);
extern void cal_dfs_set_volt_margin(unsigned int id, int volt);
extern unsigned long cal_dfs_get_rate_by_member(unsigned int id,
							char *member,
							unsigned long rate);
extern int cal_dfs_set_ema(unsigned int id, unsigned int volt);

enum cal_dfs_ext_ops {
	cal_dfs_initsmpl		= 0,
	cal_dfs_setsmpl		= 1,
	cal_dfs_get_smplstatus	= 2,

	cal_dfs_dvs = 30,

	/* Add new ops at below */
	cal_dfs_mif_is_dll_on	= 50,

	cal_dfs_cpu_idle_clock_down = 60,
};

extern int cal_dfs_ext_ctrl(unsigned int id,
				enum cal_dfs_ext_ops ops,
				int para);


extern void cal_asv_print_info(void);
extern void cal_rcc_print_info(void);
extern int cal_asv_set_rcc_table(void);
extern void cal_asv_set_grp(unsigned int id, unsigned int asvgrp);
extern int cal_asv_get_grp(unsigned int id, unsigned int lv);
extern void cal_asv_set_tablever(unsigned int version);
extern int cal_asv_get_tablever(void);
extern void cal_asv_set_ssa0(unsigned int id, unsigned int ssa0);


extern int cal_init(void);
extern int is_sicd_factory(void);

/* It is for debugging. */
extern void cal_vclk_dbg_info(unsigned int id);

<<<<<<< HEAD
extern int cal_get_cp_cpu_freq(void);

=======
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos
#ifdef __cplusplus
}
#endif

#endif
