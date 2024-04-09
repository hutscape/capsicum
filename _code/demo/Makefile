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
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int,-readability/todo *.ino

display:
	@echo "BOARD: $(BOARD)"
	@echo "PORT: $(PORT)"
	@echo "EXTRA_FLAGS: $(EXTRA_FLAGS)"

compile: clean lint display
	@if [ "$(PRODUCTION)" = "1" ]; then \
		echo "Compiling with extra flags..."; \
		arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) --build-property build.extra_flags=$(EXTRA_FLAGS) ./; \
	else \
		echo "Compiling..."; \
		arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./; \
	fi

upload:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -rf build
