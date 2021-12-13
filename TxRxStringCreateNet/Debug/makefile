################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Adafruit_TMP006.o" \
"./CreateNetwork/CreateNetwork.o" \
"./CreateNetwork/main.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-Wl,-T"C:/ti/energia_cc3220emt_5.6.2/system/energia/linker.cmd" \
-lcc3220emt_CC3220SF-LAUNCHXL_WiFiMKII \
-lcc3220emt_CC3220SF-LAUNCHXL_core \
-l:simplelink.a \
-l:driverlib.a \
-l:dpl_cc32xx.am4g \
-lstdc++ \
-lgcc \
-lc \
-lm \
-lnosys \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include CreateNetwork/subdir_vars.mk
-include subdir_rules.mk
-include CreateNetwork/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TxRxStringCreateNet.out \

EXE_OUTPUTS__QUOTED += \
"TxRxStringCreateNet.out" \

BIN_OUTPUTS += \
TxRxStringCreateNet.bin \

BIN_OUTPUTS__QUOTED += \
"TxRxStringCreateNet.bin" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "TxRxStringCreateNet.out" secondary-outputs

dependents:
	-cd C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_core/Debug && $(MAKE) all
	-cd C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_WiFiMKII/Debug && $(MAKE) all

# Tool invocations
TxRxStringCreateNet.out: $(OBJS) $(GEN_CMDS) C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_core/Debug/libcc3220emt_CC3220SF-LAUNCHXL_core.a C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_WiFiMKII/Debug/libcc3220emt_CC3220SF-LAUNCHXL_WiFiMKII.a
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1.exe" -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4g.h\" -Dxdc__nolocalstring=1 -DBOARD_CC3220SF_LAUNCHXL -DF_CPU=80000000L -DENERGIA_CC3220SF_LAUNCHXL -DENERGIA_ARCH_CC3220EMT -DSL_PLATFORM_MULTI_THREADED -DENERGIA=18 -DARDUINO=10610 -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -march=armv7e-m -mthumb -Wl,-Map,"TxRxStringCreateNet.map" -nostartfiles -Wl,--gc-sections -L"C:/Users/runes/ti/cc3220emt_CC3220S-LAUNCHXL_Adafruit_TMP006" -L"C:/Users/runes/ti/cc3220emt_CC3220S-LAUNCHXL_WiFiMKII" -Wl,--undefined,main -Os -specs=nano.specs -specs=rdimon.specs -specs=nosys.specs -Wl,--check-sections -o"TxRxStringCreateNet.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

TxRxStringCreateNet.bin: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/bin/arm-none-eabi-objcopy.exe" -O binary $(EXE_OUTPUTS__QUOTED) "TxRxStringCreateNet.bin"
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Adafruit_TMP006.o" "CreateNetwork\CreateNetwork.o" "CreateNetwork\main.o" 
	-$(RM) "Adafruit_TMP006.d" "CreateNetwork\CreateNetwork.d" "CreateNetwork\main.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:
C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_core/Debug/libcc3220emt_CC3220SF-LAUNCHXL_core.a:
C:/Users/runes/ti/cc3220emt_CC3220SF-LAUNCHXL_WiFiMKII/Debug/libcc3220emt_CC3220SF-LAUNCHXL_WiFiMKII.a:

-include ../makefile.targets

