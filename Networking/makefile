# === CONFIGURATION ===
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./sockets -I./servers
SRC_DIRS = sockets servers
BUILD_DIR = build
TARGET = $(BUILD_DIR)/server.exe

# === SOURCE FILES ===
SOURCES := main.cpp \
           $(wildcard sockets/*.cpp) \
           $(wildcard servers/*.cpp)
OBJECTS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SOURCES)))

# === PLATFORM ===
ifeq ($(OS),Windows_NT)
	LIBS = -lws2_32
else
	LIBS =
endif

# === BUILD RULES ===
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: sockets/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: servers/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === CLEAN RULE ===
clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean


### to run the file
# make        # Builds build/server.exe
# make clean  # Cleans the build/
