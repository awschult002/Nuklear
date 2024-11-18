# Install
BIN = demo

# Flags
CFLAGS += -std=c89 -Wall -Wextra -pedantic -fsanitize=address -O2
CFLAGS += -DSDL_DISABLE_IMMINTRIN_H

GLSLC_BIN ?=

SRC = main.c
OBJ = $(SRC:.c=.o)

ifeq ($(OS),Windows_NT)
BIN := $(BIN).exe
LIBS = -lsdl2 -lvulkan -lm
else
	UNAME_S := $(shell uname -s)
	SDL2 := $(shell pkg-config --libs sdl2)
	LIBS = $(SDL2) -lvulkan -lm
endif

# if you don't have GLSLC, then don't build
ifeq ($(GLSLC_BIN), )
$(BIN): 
else
$(BIN): shaders/demo.vert.spv shaders/demo.frag.spv nuklear_sdl_vulkan.h
	@mkdir -p bin
	rm -f bin/$(BIN) $(OBJS)
	$(CC) $(SRC) $(CFLAGS) -o bin/$(BIN) $(LIBS)
shaders/demo.vert.spv: shaders/demo.vert
	$(GLSLC_BIN) --target-env=vulkan shaders/demo.vert -o shaders/demo.vert.spv

shaders/demo.frag.spv: shaders/demo.frag
	$(GLSLC_BIN) --target-env=vulkan shaders/demo.frag -o shaders/demo.frag.spv


nuklear_sdl_vulkan.h: src/nuklearshaders/nuklear.vert.spv src/nuklearshaders/nuklear.frag.spv src/nuklear_sdl_vulkan.in.h
	awk -v st='// NUKLEAR_SHADERS_START' -v et='// NUKLEAR_SHADERS_END' -v repl="$$(xxd -i src/nuklearshaders/nuklear.vert.spv && xxd -i src/nuklearshaders/nuklear.frag.spv)" '$$0 == st{del=1} $$0 == et{$$0 = repl; del=0} !del' src/nuklear_sdl_vulkan.in.h > nuklear_sdl_vulkan.h

src/nuklearshaders/nuklear.vert.spv: src/nuklearshaders/nuklear.vert
	glslc --target-env=vulkan src/nuklearshaders/nuklear.vert -o src/nuklearshaders/nuklear.vert.spv

src/nuklearshaders/nuklear.frag.spv: src/nuklearshaders/nuklear.frag
	glslc --target-env=vulkan src/nuklearshaders/nuklear.frag -o src/nuklearshaders/nuklear.frag.spv

clean:
	rm src/nuklearshaders/nuklear.vert.spv src/nuklearshaders/nuklear.frag.spv nuklear_sdl_vulkan.h

endif
