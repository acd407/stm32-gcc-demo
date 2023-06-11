# 编译器设置
CC = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -std=c99 -Wall -Werror $(addprefix -I, $(INC))
LDFLAGS = -Tstm32_flash.ld -nostdlib -s
TARGET = main # 输出文件名

# 包含目录
INC = sys/include sys/include/std user/include

SYS_SRCS = $(wildcard sys/src/*.c) $(wildcard sys/src/std/*.c) # 系统源文件
STARTUP_ASMS = sys/startup/startup_stm32f10x_md.s # 启动汇编
USER_SRCS = $(wildcard user/src/*.c) # 用户源文件

# 目标文件
OBJS = $(SYS_SRCS:.c=.o) $(STARTUP_ASMS:.s=.o) $(USER_SRCS:.c=.o)

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
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