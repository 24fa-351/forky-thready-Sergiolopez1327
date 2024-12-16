# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Source files
SOURCES = forky.c pattern1.c pattern2.c pattern3.c

# Header files
HEADERS = pattern1.h pattern2.h pattern3.h

# Executable name
EXEC = forky

# Default target to build the executable
$(EXEC): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCES)

# Pattern 1 tests
test_pattern1_1: $(EXEC)
	@echo "Pattern 1 Test 1:"
	@./$(EXEC) 1 $(shell echo $$((RANDOM % 15 + 5)))
	@echo

test_pattern1_2: $(EXEC)
	@echo "Pattern 1 Test 2:"
	@./$(EXEC) 1 $(shell echo $$((RANDOM % 20 + 10)))
	@echo

# Pattern 2 tests
test_pattern2_1: $(EXEC)
	@echo "Pattern 2 Test 1:"
	@./$(EXEC) 2 $(shell echo $$((RANDOM % 15 + 5)))
	@echo

test_pattern2_2: $(EXEC)
	@echo "Pattern 2 Test 2:"
	@./$(EXEC) 2 $(shell echo $$((RANDOM % 20 + 10)))
	@echo

# Pattern 3 tests
test_pattern3_1: $(EXEC)
	@echo "Pattern 3 Test 1:"
	@./$(EXEC) 3 $(shell echo $$((RANDOM % 20 + 5)))
	@echo

test_pattern3_2: $(EXEC)
	@echo "Pattern 3 Test 2:"
	@./$(EXEC) 3 $(shell echo $$((RANDOM % 25 + 10)))
	@echo

# Target to run all tests and save output to results.txt
results: $(EXEC)
	@echo "Running all tests..."
	@( \
		$(MAKE) test_pattern1_1; \
		$(MAKE) test_pattern1_2; \
		$(MAKE) test_pattern2_1; \
		$(MAKE) test_pattern2_2; \
		$(MAKE) test_pattern3_1; \
		$(MAKE) test_pattern3_2; \
	) > results.txt 2>&1
	@echo "All tests completed. Results saved to results.txt."

# Clean target to remove the executable
clean:
	rm -f $(EXEC)
