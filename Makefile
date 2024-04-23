SUBDIRS := $(wildcard c/*/.)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ test
	$(MAKE) -C $@ memcheck
	$(MAKE) -C $@ clean

.PHONY: all $(SUBDIRS)
