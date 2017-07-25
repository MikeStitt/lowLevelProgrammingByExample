# connect to the J-Link gdb server
#
# change localhost:2331 to the ip address and port of your gdb server
target remote localhost:2331
#
# Enable flash download and flash breakpoints.
# Flash download and flash breakpoints are features of
# the J-Link software which require separate licenses from SEGGER.

# Select flash device
monitor flash device = STM32F437VG

# Enable FlashDL and FlashBPs
monitor flash download = 1
monitor flash breakpoints = 1

# Clear all pending breakpoints
monitor clrbp

# Set gdb server to little endian
monitor endian little

# Set JTAG speed to 5 kHz
monitor speed 5

# Reset the target
monitor reset
monitor sleep 100

# Set JTAG speed in khz
monitor speed auto

# Vector table placed in Flash
####monitor writeu32 0xE000ED08 = 0x00000000 # Place the vector table at the start of Flash.
####monitor writeu32 0xE000ED0C = 0x05FA0304 # Reset the chip.

#define hook-quit
#  echo \n
#  echo --- Placing processor in reset on QUIT to load pc via reset vector\n
#  echo --- This minimizes loss of processor control and flash corruption\n
#  echo \n
#  monitor reset
#  stepi
#  echo \n
#end

define hook-load
  echo \n
  echo --- Placing processor in reset PRIOR to LOAD to load pc via reset vector\n
  echo --- This minimizes loss of processor control and flash corruption\n
  echo \n
  monitor reset
  echo \n
end

define hookpost-load
  echo \n
  echo --- Placing processor in reset AFTER LOAD to load pc via reset vector\n
  echo --- This minimizes loss of processor control and flash corruption\n
  echo \n
  monitor reset
  stepi
  echo \n
end

# Start out reset
monitor reset

