APP_NAME = example.app

APP_DIR = app
APP_CONTENTS_DIR = app.contents
SCAFFOLDING_DIR = scaffolding
HAL_CHIP_DIR = hal.stm.stm32f4xx.chip.st32f437
HAL_ARM_CORTEX_DIR = hal.arm.cortex
HAL_STM_STM32F4XX_COMMON_DIR = hal.stm.stm32f4xx.common
HAL_STM_STM32FPERIPHERALLIB_DIR = hal.stm.stm32PeripheralLib
HAL_BOARD_DIR = hal.stm.stm32f4xx.board.stm3240g-eval
HAL_BOARD_DIR = hal.stm.stm32f4xx.board.brd_cust_0000_0001
BSP_DIR = bsp

-include ../$(SCAFFOLDING_DIR)/MakeCommonVars

INCLUDE_DIRS-y                     += -I../$(APP_DIR)/include
INCLUDE_DIRS-y                     += -I../$(APP_DIR)/include/generated

-include ../$(APP_CONTENTS_DIR)/MakeInclude
-include ../$(APP_CONTENTS_DIR)/MakeSource
-include ../$(SCAFFOLDING_DIR)/MakeInclude
-include ../$(SCAFFOLDING_DIR)/MakeSource
-include ../$(HAL_BOARD_DIR)/MakeInclude
-include ../$(HAL_BOARD_DIR)/MakeSource
-include ../$(HAL_CHIP_DIR)/MakeInclude
-include ../$(HAL_CHIP_DIR)/MakeSource
-include ../$(HAL_ARM_CORTEX_DIR)/MakeInclude
-include ../$(HAL_ARM_CORTEX_DIR)/MakeSource
-include ../$(HAL_STM_STM32F4XX_COMMON_DIR)/MakeInclude
-include ../$(HAL_STM_STM32F4XX_COMMON_DIR)/MakeSource
-include ../$(BSP_DIR)/MakeInclude
-include ../$(BSP_DIR)/MakeSource


.PHONY: all
all: \
$(DEVICE_LOAD_DIR)$(APP_NAME).bin 

.PHONY: app
app: \
$(DEVICE_LOAD_DIR)$(APP_NAME).bin 


INCLUDE_DIRS = $(INCLUDE_DIRS-y)

SOURCE = $(SOURCE-y)

APP_FLAGS = $(APP_FLAGS-y)

LD_LIBS-y                               =
LD_LIBS-$(CONFIG_NEWLIB_NORM_NO_DEBUG) += $(shell $(CC) $(CFLAGS) -print-file-name=libc.a)
LD_LIBS-$(CONFIG_NEWLIB_NORM_DEBUG)    += $(shell $(CC) $(CFLAGS) -print-file-name=libg.a)
LD_LIBS-$(CONFIG_NEWLIB_NANO_NO_DEBUG) += $(shell $(CC) $(CFLAGS) -print-file-name=libc_s.a)
LD_LIBS-$(CONFIG_NEWLIB_NANO_DEBUG)    += $(shell $(CC) $(CFLAGS) -print-file-name=libg_s.a)
LD_LIBS-y                              += $(shell $(CC) $(CFLAGS) -print-file-name=libm.a)
LD_LIBS-y                              += $(shell $(CC) $(CFLAGS) -print-libgcc-file-name)

LD_LIBS = $(LD_LIBS-y)

LIBS-y =

LIBS = $(LIBS-y)

DEPS        = $(addprefix $(BUILD_DIR), $(SOURCE:.c=.d))
OBJS        = $(addprefix $(BUILD_DIR), $(SOURCE:.c=.o))


APP_LDFLAGS = $(APP_LDFLAGS-y)


-include $(DEPS)


-include ../$(SCAFFOLDING_DIR)/MakeKconfigTargets

$(TOP_BUILD_DIR)source/startup/armCortexCommonIntHandlers.o : ../$(HAL_ARM_CORTEX_DIR)/source/startup/armCortexCommonIntHandlers.c Makefile
	@echo "+--$(CC) $<"
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CC) $(CPPFLAGS) -O1 $(filter-out -O%, $(CFLAGS)) $(APP_FLAGS) $(TARGET_DOT_O_SPECIFIC_CFLAGS) -c -o $@ $<

$(TOP_BUILD_DIR)%.bin : $(TOP_BUILD_DIR)%.axf

$(DEVICE_LOAD_DIR)$(APP_NAME).bin : $(TOP_BUILD_DIR)$(APP_NAME).bin
	@echo "+--cp $< $@"
	$(Q)cp $< $@

$(TOP_BUILD_DIR)$(APP_NAME).axf : ldCfg/configLoadModule.ld.preProc ../$(APP_CONTENTS_DIR)/include/memoryMap.h ../$(APP_DIR)/include/generated/autoconf.h $(TOP_BUILD_DIR)source/startup/armCortexCommonIntHandlers.o $(OBJS)
	@echo $(SEP)
	@echo "+--$(LD) $@"
	$(Q)$(CC) -E - -I../$(APP_CONTENTS_DIR)/include -I../$(APP_CONTENTS_DIR)/include/generated -P < ldCfg/configLoadModule.ld.preProc > obj/$(APP_NAME).ld
	$(Q)$(LD) $(APP_LDFLAGS) -Map=$(TOP_BUILD_DIR)$(APP_NAME).map -T obj/$(APP_NAME).ld -o $@ $(filter %.o, $(^)) $(filter %.a, $(^)) $(LD_LIBS)
	@echo $(SEP)

.PHONY: clean
clean :
ifneq ($(strip $(TOP_BUILD_DIR)),)
ifneq ($(strip $(DEVICE_LOAD_DIR)),)
	$(RM) -fr $(TOP_BUILD_DIR)*
	$(RM) -f include/generated/*
	$(RM) -f $(DEVICE_LOAD_DIR)*
else
	$(Q)echo "DEVICE_LOAD_DIR is not defined or empty, can't clean."
endif
else
	$(Q)echo "TOP_BUILD_DIR is not defined or empty, can't clean."
endif

.PHONY: distclean
distclean : clean
	$(RM)  -f .config
	$(RM)  -f .config.old
	$(RM)  -f .config_test.yaml
	find . -name "*~" -exec rm -f {} \;
	find . -name "*.o" -exec rm -f {} \;

.PHONY: printdefines
printdefines :
	$(Q)$(CC) $(CFLAGS) -dM -E - < /dev/null

.PHONY: help
help :
	$(Q)echo ""
	$(Q)echo "make help              - Print this message"
	$(Q)echo ""
	$(Q)echo "make all               - Build the executable software - same as \"make\""
	$(Q)echo "make clean             - Clean build products"
	$(Q)echo "make distclean         - Clean to repository distribution clean. Removes configuration files."
	$(Q)echo "make printincludedirs  - Show the -I include dir list."
	$(Q)echo "make printdefines      - Show a list of default compiler defines."
	$(Q)echo "make findinclude       - make findinclude INAME=*.h will list the .h files in the include dir list."

