SUBDIRS_C := $(wildcard c/*/.)
SUBDIRS_CPP := $(wildcard cpp/*/.)

all: c cpp

c: $(SUBDIRS_C)
$(SUBDIRS_C):
	$(MAKE) -C $@ test
	$(MAKE) -C $@ memcheck
	$(MAKE) -C $@ clean

cpp: $(SUBDIRS_CPP)
$(SUBDIRS_CPP):
	cmake -S $@ -B $@/build -G "Unix Makefiles"
	cmake --build $@/build
	rm -rf $@/build

.PHONY: c cpp clean_cpp $(SUBDIRS_C) $(SUBDIRS_CPP)
