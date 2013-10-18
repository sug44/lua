LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_C_INCLUDES += ../include 
LOCAL_MODULE    := lua52
LOCAL_CFLAGS    := -DLUA_ANSI -I../include
LOCAL_SRC_FILES :=  \
 ../../src/lapi.cpp ../../src/lauxlib.cpp ../../src/lbaselib.cpp ../../src/lbitlib.cpp ../../src/lcode.cpp ../../src/lcorolib.cpp ../../src/lctype.cpp \
 ../../src/ldblib.cpp ../../src/ldebug.cpp ../../src/ldo.cpp ../../src/ldump.cpp ../../src/lfunc.cpp ../../src/lgc.cpp ../../src/linit.cpp ../../src/liolib.cpp \
 ../../src/llex.cpp ../../src/lmathlib.cpp ../../src/lmem.cpp ../../src/lnet.cpp ../../src/loadlib.cpp ../../src/lobject.cpp \
 ../../src/lopcodes.cpp ../../src/loslib.cpp ../../src/lparser.cpp ../../src/lstate.cpp ../../src/lstring.cpp ../../src/lstrlib.cpp ../../src/ltable.cpp \
 ../../src/ltablib.cpp ../../src/ltm.cpp ../../src/lundump.cpp ../../src/lvm.cpp ../../src/lzio.cpp
 

include $(BUILD_SHARED_LIBRARY)
