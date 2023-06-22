# 编译器设置
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
OC = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -std=c11 -Wall -Werror $(addprefix -I, $(INC))
CXXFLAGS = -mcpu=cortex-m3 -mthumb -std=c++17 -Wall -Werror $(addprefix -I, $(INC)) -fno-exceptions
LDFLAGS = -Tstm32_flash.ld -nostdlib -lstdc++
TARGET = main # 输出文件名

# debug = 1
ifeq ($(debug), 1)
	CFLAGS += -Og -Ddebug
	CXXFLAGS += -Og -Ddebug
else
	CFLAGS += -ffunction-sections -fdata-sections -O2
	CXXFLAGS += -ffunction-sections -fdata-sections -O2
	LDFLAGS += -Wl,--gc-sections -s
endif

# 包含目录
INC += include include/std 
LIB += /usr/arm-none-eabi/lib

# 源文件
FILES = $(wildcard src/*) $(wildcard src/sys/*) $(wildcard src/sys/std/*)
SRCS = $(filter %.c %.cpp %.s,$(FILES))

# 目标文件
OBJS = $(addsuffix .o,$(SRCS))

# 生成目标文件
%.c.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
%.s.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

# 主目标
BINS += $(addsuffix .elf,$(TARGET))
BINS += $(addsuffix .bin,$(TARGET))
BINS += $(addsuffix .hex,$(TARGET))
all: $(BINS)

# 生成 ELF 文件
%.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
%.hex: %.elf
	$(OC) -O ihex $< $@
%.bin: %.elf
	$(OC) -O binary $< $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(BINS)
c: clean

# 烧录
write:
	st-flash --reset write $(addsuffix .bin,$(TARGET)) 0x8000000
w: write