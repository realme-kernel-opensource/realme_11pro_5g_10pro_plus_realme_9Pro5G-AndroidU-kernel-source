/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2019 MediaTek Inc.
 */

#ifndef __MTK_BOOT_COMMON_H__
#define __MTK_BOOT_COMMON_H__

/* boot type definitions */
enum boot_mode_t {
	NORMAL_BOOT = 0,
	META_BOOT = 1,
	RECOVERY_BOOT = 2,
	SW_REBOOT = 3,
	FACTORY_BOOT = 4,
	ADVMETA_BOOT = 5,
	ATE_FACTORY_BOOT = 6,
	ALARM_BOOT = 7,
	KERNEL_POWER_OFF_CHARGING_BOOT = 8,
	LOW_POWER_OFF_CHARGING_BOOT = 9,
	DONGLE_BOOT = 10,
#ifdef OPLUS_BUG_STABILITY
/* Bin.Li@EXP.BSP.bootloader.bootflow, 2017/05/24, Add for oplus boot mode */
	OPLUS_SAU_BOOT = 11,
	SILENCE_BOOT = 12,
/* xiaofan.yang@PSW.TECH.AgingTest, 2019/09/09,Add for factory agingtest */
	AGING_BOOT = 998,
	SAFE_BOOT = 999,
#endif /* OPLUS_BUG_STABILITY */
	UNKNOWN_BOOT
};

#ifdef OPLUS_BUG_STABILITY
/* Bin.Li@EXP.BSP.bootloader.bootflow, 2017/05/24, Add for oplus boot mode */
typedef enum
{
	OPLUS_NORMAL_BOOT = 0,
	OPLUS_SILENCE_BOOT = 1,
	OPLUS_SAFE_BOOT = 2,
	/* xiaofan.yang@PSW.TECH.AgingTest, 2019/09/09,Add for factory agingtest */
	OPLUS_AGING_BOOT = 3,
	OPLUS_UNKNOWN_BOOT
}OPLUS_BOOTMODE;

extern OPLUS_BOOTMODE oplus_boot_mode;
#endif /* OPLUS_BUG_STABILITY */


/* for boot type usage */
#define BOOTDEV_NAND            (0)
#define BOOTDEV_SDMMC           (1)
#define BOOTDEV_UFS             (2)

#define BOOT_DEV_NAME           "BOOT"
#define BOOT_SYSFS              "boot"
#define BOOT_MODE_SYSFS_ATTR    "boot_mode"
#define BOOT_TYPE_SYSFS_ATTR    "boot_type"

extern enum boot_mode_t get_boot_mode(void);
extern unsigned int get_boot_type(void);
extern bool is_meta_mode(void);
extern bool is_advanced_meta_mode(void);
extern void set_boot_mode(unsigned int bm);

#endif
