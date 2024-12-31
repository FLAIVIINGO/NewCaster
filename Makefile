CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src/utils

SRC_DIR = src/utils
TEST_DIR = tests
BUILD_DIR = build

SRC_FILES = $(SRC_DIR)/tuple.cpp $(SRC_DIR)/point.cpp $(SRC_DIR)/vector.cpp
TEST_FILES = $(TEST_DIR)/test_tuple.cpp

UTILS_TEST = $(BUILD_DIR)/utils_test

GTEST_LIB = -lgtest -lgtest_main -pthread

all: $(UTILS_TEST)

$(UTILS_TEST): $(SRC_FILES) $(TEST_FILES) | $(BUILD_DIR) 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

test: $(UTILS_TEST)
	./$(UTILS_TEST)

.PHONY: all clean test
