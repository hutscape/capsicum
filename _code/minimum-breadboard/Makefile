# Uncomment for PCB
BOARD?=esp32:esp32:esp32c3:CDCOnBoot=cdc
PORT?=/dev/cu.usbmodem1410*

# Uncomment for breadboard with PCB
# BOARD?=esp32:esp32:esp32c3
# PORT?=/dev/cu.SLAB_USBtoUART*

BUILD=build

.PHONY: default lint compile flash clean

default: lint compile flash clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int *.ino

compile: clean lint
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -rf build
