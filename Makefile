all: install

build:
	$(MAKE) -C cpart_src clean
	$(MAKE) -C cpart_src

install:
	$(MAKE) build
	$(MAKE) -C cpart_src

clean:
	$(MAKE) -C cpart_src clean

usage:
	@echo "Usage: make [build|install]\nbuild only builds mininit binary and api, install puts it in bin/ aswell\n"