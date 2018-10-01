#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv8/ccs_base
override XDCROOT = C:/ti/xdctools_3_50_05_12_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv8/ccs_base;C:/ti/xdctools_3_50_05_12_core/packages;..
HOSTOS = Windows
endif
