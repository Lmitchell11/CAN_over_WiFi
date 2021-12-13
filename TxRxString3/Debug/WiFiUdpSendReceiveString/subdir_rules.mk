################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1515560943:
	@$(MAKE) --no-print-directory -Onone -f WiFiUdpSendReceiveString/subdir_rules.mk build-1515560943-inproc

build-1515560943-inproc: ../WiFiUdpSendReceiveString/WiFiUdpSendReceiveString.ino
	@echo 'Building file: "$<"'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: "$<"'
	@echo ' '

WiFiUdpSendReceiveString/WiFiUdpSendReceiveString.cpp: build-1515560943 ../WiFiUdpSendReceiveString/WiFiUdpSendReceiveString.ino
WiFiUdpSendReceiveString/main.cpp: build-1515560943

WiFiUdpSendReceiveString/%.o: ./WiFiUdpSendReceiveString/%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=soft -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4g.h\" -Dxdc__nolocalstring=1 -DBOARD_CC3220S_LAUNCHXL -DF_CPU=80000000L -DENERGIA_CC3220S_LAUNCHXL -DENERGIA_ARCH_CC3220EMT -DSL_PLATFORM_MULTI_THREADED -DENERGIA=18 -DARDUINO=10610 -I"C:/ti/energia_cc3220emt_5.6.2/cores/cc3220emt/ti/runtime/wiring/" -I"C:/ti/energia_cc3220emt_5.6.2/cores/cc3220emt/ti/runtime/wiring/cc32xx" -I"C:/ti/energia_cc3220emt_5.6.2/system/kernel/tirtos/packages/ti/sysbios/posix" -I"C:/ti/energia_cc3220emt_5.6.2/system/kernel/tirtos/packages" -I"C:/ti/energia_cc3220emt_5.6.2/system/source" -I"C:/ti/energia_cc3220emt_5.6.2/system/energia" -I"C:/ti/energia_cc3220emt_5.6.2/system/source/ti/devices/cc32xx/driverlib" -I"C:/ti/energia_cc3220emt_5.6.2/system/source/ti/devices/cc32xx/inc" -I"C:/ti/energia_cc3220emt_5.6.2/system/source/ti/devices/cc32xx/" -I"C:/ti/energia_cc3220emt_5.6.2/cores/cc3220emt" -I"C:/ti/energia_cc3220emt_5.6.2/variants/CC3220S_LAUNCHXL" -I"D:/Backup from SSD/TxRxString3" -I"C:/ti/energia_cc3220emt_5.6.2/libraries/WiFiMKII/src" -I"C:/ti/energia_tool_arm-none-eabi-gcc_6.3.1-20170620/arm-none-eabi/include" -I"C:/ti/energia_core_18.0.0/libraries/Adafruit_TMP006" -I"C:/Users/Liam/Downloads/energia-1.8.7E20/libraries/Adafruit_TMP006" -I"C:/ti/energia_core_18.0.0/libraries/Adafruit_TMP006" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -MMD -MP -MF"WiFiUdpSendReceiveString/$(basename $(<F)).d_raw" -MT"$(@)"  -fno-rtti -fno-threadsafe-statics -fno-exceptions $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


