BOARD?=esp32:esp32:esp32c3
PORT?=/dev/cu.usbserial-*
BUILD=build

.PHONY: default lint compile upload clean

default: lint compile upload clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int *.ino

compile: clean lint
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

upload:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -rf build
