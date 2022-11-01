COMBO_ENABLE = yes
STENO_ENABLE = yes
NKRO_ENABLE = yes           # USB Nkey Rollover

SRC += ./swapper.c

# save firmware storage space
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
