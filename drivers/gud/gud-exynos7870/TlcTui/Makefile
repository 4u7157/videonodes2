#
# Makefile for the <t-base trusted UI driver
#
<<<<<<< HEAD

GUD_ROOT_FOLDER := drivers/gud/
=======
PLATFORM := exynos7870

GUD_ROOT_FOLDER := drivers/gud/gud-exynos7870
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

# add our modules to kernel.
obj-$(CONFIG_TRUSTONIC_TRUSTED_UI) += TlcTui.o

<<<<<<< HEAD
TlcTui-y := main.o tlcTui.o trustedui.o tui-hal.o
=======
TlcTui-y := main.o tlcTui.o trustedui.o	\
	platforms/$(PLATFORM)/tui-hal.o
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

# Release mode by default
ccflags-y += -DNDEBUG
ccflags-y += -Wno-declaration-after-statement

<<<<<<< HEAD
ccflags-$(CONFIG_MOBICORE_DEBUG) += -DDEBUG
=======
ccflags-$(CONFIG_TRUSTONIC_TEE_DEBUG) += -DDEBUG

ccflags-y += -I$(GUD_ROOT_FOLDER)/TlcTui
ccflags-y += -Idrivers/video/fbdev/exynos/decon_7870
>>>>>>> 6e0bf6af... a6 without drivers/media/platform/exynos

# MobiCore Driver includes
ccflags-y += -I$(GUD_ROOT_FOLDER)/MobiCoreDriver/public

# MobiCore TlcTui required includes
ccflags-y += -I$(GUD_ROOT_FOLDER)/TlcTui/inc \
             -I$(GUD_ROOT_FOLDER)/TlcTui/public
