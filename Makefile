OBJS=emnod.o emlink.o
TESTS=emnod.test emlink.test
CFLAGS=-Wall

# Compile and run a single test suite
%.test: %.c %.h %.test.c util_test.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $@.c $(OBJS)
	./$@

# Run all tests
tests: $(TESTS)

clean_tests:
	rm -vf *.test

clean:
	rm -vf *.o *.test

.PHONY: clean clean_tests
