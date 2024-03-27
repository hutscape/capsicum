BOARD?=esp32:esp32:esp32c3
PORT?=/dev/cu.usbserial*
# PORT?=/dev/cu.usbmodem1410*
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
