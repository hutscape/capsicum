# Description: Makefile for the demo code
# Usage: make [lint] [compile] [upload] [clean]
BOARD := esp32:esp32:esp32c3:CDCOnBoot=cdc
PORT ?= /dev/cu.usbmodem1410*
BUILD = build

.PHONY: default lint compile upload clean

default: lint compile upload clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int,-readability/todo,-whitespace/line_length *.ino

compile: clean lint
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

upload:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -rf build
