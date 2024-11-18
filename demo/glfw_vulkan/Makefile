# Install
BIN = demo
GLSLC_BIN ?=

# Flags
CFLAGS += -std=c89 -Wall -Wextra -pedantic

SRC = main.c
OBJ = $(SRC:.c=.o)

ifeq ($(OS),Windows_NT)
BIN := $(BIN).exe
LIBS = -lglfw3 -lvulkan -lm
else
	UNAME_S := $(shell uname -s)
	GLFW3 := $(shell pkg-config --libs glfw3)
    LIBS = $(GLFW3) -lvulkan -lm
endif


ifeq ($(GLSLC_BIN), )
$(BIN):
else
$(BIN): shaders/demo.vert.spv shaders/demo.frag.spv nuklear_glfw_vulkan.h
	@mkdir -p bin
	rm -f bin/$(BIN) $(OBJS)
	$(CC) $(SRC) $(CFLAGS) -o bin/$(BIN) $(LIBS)

shaders/demo.vert.spv: shaders/demo.vert
	$(GLSLC_BIN) --target-env=vulkan shaders/demo.vert -o shaders/demo.vert.spv

shaders/demo.frag.spv: shaders/demo.frag
	$(GLSLC_BIN) --target-env=vulkan shaders/demo.frag -o shaders/demo.frag.spv

nuklear_glfw_vulkan.h: src/nuklearshaders/nuklear.vert.spv src/nuklearshaders/nuklear.frag.spv
	awk -v st='// NUKLEAR_SHADERS_START' -v et='// NUKLEAR_SHADERS_END' -v repl="$$(xxd -i src/nuklearshaders/nuklear.vert.spv && xxd -i src/nuklearshaders/nuklear.frag.spv)" '$$0 == st{del=1} $$0 == et{$$0 = repl; del=0} !del' src/nuklear_glfw_vulkan.in.h > nuklear_glfw_vulkan.h

src/nuklearshaders/nuklear.vert.spv: src/nuklearshaders/nuklear.vert
	$(GLSLC_BIN) --target-env=vulkan src/nuklearshaders/nuklear.vert -o src/nuklearshaders/nuklear.vert.spv

src/nuklearshaders/nuklear.frag.spv: src/nuklearshaders/nuklear.frag
	$(GLSLC_BIN) --target-env=vulkan src/nuklearshaders/nuklear.frag -o src/nuklearshaders/nuklear.frag.spv

clean:
	rm src/nuklearshaders/nuklear.vert.spv src/nuklearshaders/nuklear.frag.spv nuklear_glfw_vulkan.h
endif
