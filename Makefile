CC ?= cc
CFLAGS := -std=c11 -Wall -Wextra -Werror -Iinclude
BUILD := build

.PHONY: all check clean
all: check

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/lite-smoke: src/orion_browser.c tests/lite_smoke.c include/orion_browser.h include/orion_vela_bridge.h | $(BUILD)
	$(CC) $(CFLAGS) src/orion_browser.c tests/lite_smoke.c -o $@

check: $(BUILD)/lite-smoke
	./$(BUILD)/lite-smoke

clean:
	rm -rf $(BUILD)
