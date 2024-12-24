CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src/primitives

SRC_DIR = src/primitives
TEST_DIR = tests
BUILD_DIR = build

SRC_FILES = $(SRC_DIR)/tuple.cpp
TEST_FILES = $(TEST_DIR)/test_tuple.cpp

PRIMITIVE_TEST = $(BUILD_DIR)/primitive_test

GTEST_LIB = -lgtest -lgtest_main -pthread

all: $(PRIMITIVE_TEST)

$(PRIMITIVE_TEST): $(SRC_FILES) $(TEST_FILES) | $(BUILD_DIR) 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

test: $(PRIMITIVE_TEST)
	./$(PRIMITIVE_TEST)

.PHONY: all clean test
