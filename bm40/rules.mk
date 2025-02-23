# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = custom
WS2812_DRIVER_REQUIRED = no
COMBO_ENABLE = yes
LTO_ENABLE = yes
CAPS_WORD_ENABLE = yes

# COMMON_VPATH += $(DRIVER_PATH)/led/issi
# SRC += is31fl3733.c
# QUANTUM_LIB_SRC += i2c_master.c

LAYOUTS_HAS_RGB = yes
