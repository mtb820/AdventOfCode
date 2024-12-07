PROJ=Day7
CXX=g++
CXXFLAGS= -Wall -g

.PHONY: all clean
all: build/$(PROJ)

build/$(PROJ): main.cpp
ifeq ("$(wildcard build)", "")
	@echo "creating build directory"
	@mkdir build
endif
	$(CXX) $(CXXFLAGS) -o $@ $^ -I inc
clean:
	rm -rf build