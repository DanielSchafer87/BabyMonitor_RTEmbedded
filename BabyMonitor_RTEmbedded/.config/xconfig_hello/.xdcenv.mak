#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv7/ccs_base;C:/A-Z/programming/my_projects/Kinerert/RTOS/CCS_cc3220_workspace_labs1/hello_CC3220S_LAUNCHXL_tirtos_ccs/.config
override XDCROOT = C:/ti/xdctools_3_50_02_20_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/simplelink_cc32xx_sdk_1_40_01_00/source;C:/ti/simplelink_cc32xx_sdk_1_40_01_00/kernel/tirtos/packages;C:/ti/ccsv7/ccs_base;C:/A-Z/programming/my_projects/Kinerert/RTOS/CCS_cc3220_workspace_labs1/hello_CC3220S_LAUNCHXL_tirtos_ccs/.config;C:/ti/xdctools_3_50_02_20_core/packages;..
HOSTOS = Windows
endif
