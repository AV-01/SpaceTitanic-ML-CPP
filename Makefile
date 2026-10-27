PRJ_NAME := Space Titanic ML C++

### Paths ###
PRJ_ROOT        := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
PRJ_SOURCE_CODE := ${PRJ_ROOT}/src
PRJ_INCLUDE_CODE := ${PRJ_ROOT}/include
PRJ_OUTPUT_DIR  := ${PRJ_ROOT}/bin
PRJ_OBJECTS_DIR := ${PRJ_ROOT}/build/objects
INCLUDES        := -I${PRJ_INCLUDE_CODE} -I${PRJ_SOURCE_CODE}

### Compiler & Flags ###
CXX             := g++
CXXFLAGS        := -std=c++20 -Wall -Wextra -Werror -pedantic -g

### Derived Variables ###
CPP_SRC_FILES   := $(shell find -L $(PRJ_SOURCE_CODE) -type f -name "*.cpp" -print)
CPP_OBJECTS     := $(patsubst $(PRJ_SOURCE_CODE)/%.cpp,$(PRJ_OBJECTS_DIR)/%.o, $(CPP_SRC_FILES))

### Targets ###
.PHONY: all exec clean

all: exec

exec: ${PRJ_OUTPUT_DIR}/exec

${PRJ_OUTPUT_DIR}/exec: $(CPP_OBJECTS)
	@mkdir -p $(PRJ_OUTPUT_DIR)
	${CXX} ${CXXFLAGS} ${INCLUDES} $(CPP_OBJECTS) -o $@
	@echo "Built executable: $@"

${PRJ_OBJECTS_DIR}/%.o: ${PRJ_SOURCE_CODE}/%.cpp
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o $@

clean:
	rm -rf ${PRJ_ROOT}/build ${PRJ_OUTPUT_DIR}/exec