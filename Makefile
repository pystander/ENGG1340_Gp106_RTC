COMPILE_CMD=g++ --std=c++11 -I.
ccsrc = $(wildcard libs/enviro/*.cc) \
		$(wildcard libs/enviro/maps/*.cc) \
		$(wildcard libs/enviro/commands/*.cc) \
		$(wildcard libs/entities/*.cc) \
		$(wildcard libs/entities/enemies/*.cc) \
		$(wildcard libs/entities/items/*.cc) \
		$(wildcard libs/skills/*.cc) \
		$(wildcard libs/utils/*.cc) \
		$(wildcard src/*.cc)
obj = $(ccsrc:.cc=.o)

all: clean main

main: $(obj)
	$(COMPILE_CMD) -o bin/$@ $^

%.o: %.cc
	$(COMPILE_CMD) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(obj)
