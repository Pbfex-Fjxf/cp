# --- Environment Setup ---
export MACOSX_DEPLOYMENT_TARGET = 26.2

# --- User Config ---
CXX      = g++-15
CXXFLAGS = -std=c++23 -Wall -Wextra -O2 -I./lib -DDEBUG

# --- File Config ---
TARGET   = ./build/a.out
SRC      = ./src/main.cpp
HEADERS  = $(wildcard ./lib/*.hpp)
SUBMIT   = ./build/submit.cpp
BUNDLER  = ./bin/bundle.py
INPUT    = ./build/input.in

# --- Targets ---
all: run

run: $(TARGET)
	@echo "[RUN] File Input"
	@echo "--------------------------------------------------"
	@$(TARGET) < $(INPUT)
	@echo "\n--------------------------------------------------"
r: run

manual: $(TARGET)
	@echo "[MANUAL] TTY Input"
	@echo "--------------------------------------------------"
	$(TARGET)
m: manual

# compile
$(TARGET): $(SRC) $(HEADERS)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

bundle:
	@mkdir -p build
	$(BUNDLER) $(SRC) ./lib > $(SUBMIT)
	@echo "[BUNDLE] Generated: $(SUBMIT)"
	@cat $(SUBMIT) | pbcopy
	@echo "[BUNDLE] Copied to clipboard!"
b: bundle

clean:
	rm -rf build/*.out build/submit.cpp
c: clean

.PHONY: all run r manual m bundle b clean c
