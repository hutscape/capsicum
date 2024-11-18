# Description: Makefile for the demo code
# Usage: make [PRODUCTION=1] [lint] [compile] [upload] [clean]
# With battery: make PRODUCTION=1
# With USB power: make

ifeq ($(PRODUCTION),1)
  BOARD := esp32:esp32:esp32c3
else
  BOARD := esp32:esp32:esp32c3:CDCOnBoot=cdc
endif
PORT ?= /dev/cu.usbmodem1410*
BUILD = build

EXTRA_FLAGS := $(if $(filter 1,$(PRODUCTION)),-DPRODUCTION=1,)

.PHONY: default lint display compile upload clean

default: lint compile upload clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int,-readability/todo,-readability/casting *.ino

display:
	@echo "BOARD: $(BOARD)"
	@echo "PORT: $(PORT)"
	@echo "EXTRA_FLAGS: $(if $(EXTRA_FLAGS),$(EXTRA_FLAGS),none)"

compile: clean lint display
	@if [ "$(PRODUCTION)" = "1" ]; then \
		echo "\033[34mDisabling all serial prints and debug messages\033[0m"; \
		echo "Compiling with extra flags..."; \
		arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) --build-property build.extra_flags=$(EXTRA_FLAGS) ./; \
	else \
		echo "Compiling..."; \
		arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./; \
	fi

upload:
	@if [ -n "$(PORT)" ]; then \
		arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD); \
	else \
		echo "Port $(PORT) is not available. Please check if another serial monitor is using it, or press BOOT-RESET button on board the PCB."; \
	fi

clean:
	rm -rf build
