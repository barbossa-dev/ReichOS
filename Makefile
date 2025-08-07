CXX = g++
AS = nasm
LD = ld

CXXFLAGS = -m32 -std=c++17 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASFLAGS = -f elf32
LDFLAGS = -T src/linker.ld -m elf_i386

BUILD = build
SRC = src

all: iso

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/boot.o: $(SRC)/boot/boot.s | $(BUILD)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD)/kernel.o: $(SRC)/kernel/kernel.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/kernel.elf: $(BUILD)/boot.o $(BUILD)/kernel.o
	$(CXX) -m32 -ffreestanding -O2 -nostdlib -lgcc -T $(SRC)/linker.ld -o $@ $^

iso: $(BUILD)/kernel.elf
	mkdir -p $(BUILD)/isodir/boot/grub
	cp $(BUILD)/kernel.elf $(BUILD)/isodir/boot/kernel.elf
	cp grub/grub.cfg $(BUILD)/isodir/boot/grub/
	grub-mkrescue -o $(BUILD)/myos.iso $(BUILD)/isodir

run: iso
	qemu-system-i386 -cdrom $(BUILD)/myos.iso

clean:
	rm -rf $(BUILD)
