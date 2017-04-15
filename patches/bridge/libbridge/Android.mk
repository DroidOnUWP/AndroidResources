LOCAL_PATH:= $(call my-dir)

#
# libbridge
#

include $(CLEAR_VARS)

#
# DO NOT REMOVE --exclude-libs!

LOCAL_LDFLAGS := -Wl,--exclude-libs=libgcc.a
# -Wl,--version-script=$(LOCAL_PATH)/libbridge.map

# for x86, exclude libgcc_eh.a for the same reasons as above
LOCAL_LDFLAGS_x86 := -Wl,--exclude-libs=libgcc_eh.a
LOCAL_LDFLAGS_x86_64 := $(LOCAL_LDFLAGS_x86)

LOCAL_SRC_FILES:= libbridge.c
LOCAL_CFLAGS := -Wall -Wextra -Wunused
LOCAL_CXX_STL := none

LOCAL_MODULE := libbridge
LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk
LOCAL_C_INCLUDES += bridge/include
LOCAL_EXPORT_C_INCLUDE_DIRS := bridge/include


# NOTE: libdl needs __aeabi_unwind_cpp_pr0 from libgcc.a but libgcc.a needs a
# few symbols from libc. Using --no-undefined here results in having to link
# against libc creating a circular dependency which is removed and we end up
# with missing symbols. Since this library is just a bunch of stubs, we set
# LOCAL_ALLOW_UNDEFINED_SYMBOLS to remove --no-undefined from the linker flags.
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
LOCAL_SYSTEM_SHARED_LIBRARIES :=

LOCAL_ADDRESS_SANITIZER := false
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= libbridge.c
LOCAL_CFLAGS := -Wall -Wextra -Wunused
LOCAL_CXX_STL := none

LOCAL_MODULE := libbridge
LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk
LOCAL_ADDRESS_SANITIZER := false
LOCAL_C_INCLUDES += bridge/include
LOCAL_EXPORT_C_INCLUDE_DIRS := bridge/include

include $(BUILD_STATIC_LIBRARY)
