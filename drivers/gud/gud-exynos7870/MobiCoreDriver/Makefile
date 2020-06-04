#
# Makefile for the <t-base core driver
#

GUD_ROOT_FOLDER := drivers/gud/gud-exynos7870

# add our modules to kernel.
obj-$(CONFIG_TRUSTONIC_TEE) += mcDrvModule.o

mcDrvModule-y := \
	admin.o \
	client.o \
	clientlib.o \
	clock.o \
	fastcall.o \
	logging.o \
	main.o \
	mcp.o \
	mmu.o \
	pm.o \
	scheduler.o \
	session.o \
	user.o

# Release mode by default
ccflags-y += -DNDEBUG
ccflags-y += -Wno-declaration-after-statement

<<<<<<< HEAD
ccflags-$(CONFIG_MOBICORE_DEBUG) += -DDEBUG
=======
ccflags-$(CONFIG_TRUSTONIC_TEE_DEBUG) += -DDEBUG
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

# MobiCore Driver includes
ccflags-y += -I$(GUD_ROOT_FOLDER)/MobiCoreDriver
