#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Release.mk)" "nbproject/Makefile-local-Release.mk"
include nbproject/Makefile-local-Release.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Release
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=LibConfig.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/LibConfig.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/LibConfig.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/LibConfig.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=LibConfig.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC24FJ1024GB610
ProjectDir="C:\Users\marce\Documents\GitHub\R1-1-P1_1-C1-1"
ProjectName=R1-1-P1_1-C1-1
ConfName=Release
ImagePath="dist\Release\${IMAGE_TYPE}\R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\Release\${IMAGE_TYPE}"
ImageName="R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif
MDFUHostPath="C:\Program Files\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pymdfu-bin.exe"
PYFWImageBuilderPath="C:\Program Files\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pyfwimagebuilder-bin.exe"

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Release.mk ${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [PowerShell -ExecutionPolicy Bypass -File ${CURDIR}\GitVersion\CopyHexfile.ps1 ${ImagePath} ${CURDIR}]"
	PowerShell -ExecutionPolicy Bypass -File ${CURDIR}\GitVersion\CopyHexfile.ps1 ${ImagePath} ${CURDIR}
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=24FJ1024GB610
MP_LINKER_FILE_OPTION=,--script="KG-Bootloader\Bootloader.X\p24FJ1024GB610_App.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/LibConfig.o: LibConfig.c  .generated_files/flags/Release/866a6e1bb1e7dade4008affaa6f26cfa7a0d2603 .generated_files/flags/Release/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LibConfig.o.d 
	@${RM} ${OBJECTDIR}/LibConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LibConfig.c  -o ${OBJECTDIR}/LibConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LibConfig.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)  --partition 1 -mlarge-code -O0 -D__PIC24FJ1024GB610__ -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/Release/81effb6b1a65c93da7e55bfff32c1b8601bc1c01 .generated_files/flags/Release/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)  --partition 1 -mlarge-code -O0 -D__PIC24FJ1024GB610__ -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/LibConfig.o: LibConfig.c  .generated_files/flags/Release/676cde1eb5c7367ea8abe5d6951009c40d6bb27f .generated_files/flags/Release/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LibConfig.o.d 
	@${RM} ${OBJECTDIR}/LibConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LibConfig.c  -o ${OBJECTDIR}/LibConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LibConfig.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)  --partition 1 -mlarge-code -O0 -D__PIC24FJ1024GB610__ -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/Release/35b9f665f20cd2d972cfa752a905da6b43526b09 .generated_files/flags/Release/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)  --partition 1 -mlarge-code -O0 -D__PIC24FJ1024GB610__ -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  KG-Lib/dist/PIC24FJ1024GB610/debug/KG-Lib.a  KG-Bootloader/Bootloader.X/p24FJ1024GB610_App.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    KG-Lib\dist\PIC24FJ1024GB610\debug\KG-Lib.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,--partition,1,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--no-isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  KG-Lib/dist/PIC24FJ1024GB610/production/KG-Lib.a KG-Bootloader/Bootloader.X/p24FJ1024GB610_App.gld KG-Bootloader/Bootloader.X/dist/DebugConfig_PIC24FJ1024GB610/production/Bootloader.X.production.hex
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    KG-Lib\dist\PIC24FJ1024GB610\production\KG-Lib.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_Release=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,--partition,1,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--no-isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf --offset 0x0  -mdfp="${DFP_DIR}/xc16" 
	
	@echo "Creating unified hex file"
	@"C:/Program Files/Microchip/MPLABX/v6.25/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.25/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" -break=1003000  ${DISTDIR}/R1-1-P1_1-C1-1.${IMAGE_TYPE}.hex KG-Bootloader/Bootloader.X/dist/DebugConfig_PIC24FJ1024GB610/production/Bootloader.X.production.hex -odist/${CND_CONF}/production/R1-1-P1_1-C1-1.production.unified.hex

endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: [PowerShell -ExecutionPolicy Bypass -File ${CURDIR}\GitVersion\GitVersion.ps1 ${CURDIR}]"
	PowerShell -ExecutionPolicy Bypass -File  ${CURDIR}\GitVersion\GitVersion.ps1 ${CURDIR}
	@echo "--------------------------------------"

# Subprojects
.build-subprojects:
	cd KG-Lib && ${MAKE}  -f Makefile CONF=PIC24FJ1024GB610
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd KG-Bootloader/Bootloader.X && ${MAKE}  -f Makefile CONF=DebugConfig_PIC24FJ1024GB610 TYPE_IMAGE=DEBUG_RUN
else
	cd KG-Bootloader/Bootloader.X && ${MAKE}  -f Makefile CONF=DebugConfig_PIC24FJ1024GB610
endif


# Subprojects
.clean-subprojects:
	cd KG-Lib && rm -rf "build/PIC24FJ1024GB610" "dist/PIC24FJ1024GB610"
	cd KG-Bootloader/Bootloader.X && rm -rf "build/DebugConfig_PIC24FJ1024GB610" "dist/DebugConfig_PIC24FJ1024GB610"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
