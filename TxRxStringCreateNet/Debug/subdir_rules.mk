################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=soft -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4g.h\" -Dxdc__nolocalstring=1 -DBOARD_CC3220SF_LAUNCHXL -DF_CPU=80000000L -DENERGIA_CC3220SF_LAUNCHXL -DENERGIA_ARCH_CC3220EMT -DSL_PLATFORM_MULTI_THREADED -DENERGIA=18 -DARDUINO=10610 -I"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/arm-none-eabi/include" -I"C:/ti/energia_core_18.0.0/libraries/Adafruit_TMP006" -I"C:/ti/energia_cc3220emt_5.6.2/libraries/WiFiMKII/src" -I"C:/Users/runes/ti/TxRxStringCreateNet" -I"C:/Users/runes/ti/cc3220emt_CC3220S-LAUNCHXL_core" -I"C:/Users/runes/ti/cc3220emt_CC3220S-LAUNCHXL_core/Debug" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  -fno-rtti -fno-threadsafe-statics -fno-exceptions $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


