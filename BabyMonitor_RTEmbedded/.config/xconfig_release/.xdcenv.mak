#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv8/ccs_base;C:/Users/DANIEL~1/workspace_v8/BabyMonitor_RTEmbedded_ZoharDaniel/.config
override XDCROOT = C:/ti/xdctools_3_50_05_12_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv8/ccs_base;C:/Users/DANIEL~1/workspace_v8/BabyMonitor_RTEmbedded_ZoharDaniel/.config;C:/ti/xdctools_3_50_05_12_core/packages;..
HOSTOS = Windows
endif
