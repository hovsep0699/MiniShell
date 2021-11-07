MDEBUGGER		=	valgrind

DEBUGGER		=	gdb

MDBG_FLAGS		=	--leak-check=full -s

DEBUG_NAME		=	$(BIN_DIR)/debug

DEBUG_FLAGS		=	-g

DEBUG_DIR		=	debug

DEBUG_SRCS		=	$(wildcard debug/*.c)

DEBUG_OBJS		=	$(patsubst debug/%.c, debug/%.o, $(DEBUG_SRCS))

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
	DEBUG_PREQ = debug
	CHECK_MEMORY = $(MDEBUGGER) $(MDBG_FLAGS) $(DEBUG_NAME)
endif
ifeq ($(UNAME), Darwin)
	DEBUG_PREQ =
	CHECK_MEMORY = bash ./debug/check_memory.sh
endif


$(DEBUG_DIR)/%.o: $(DEBUG_DIR)/%.c
					$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

debug_clean:		
					$(RM) $(DEBUG_OBJS)

debug:				debug_clean $(DEBUG_OBJS)
					@$(MAKELIBS)
					@$(MAKELIBS2)
					@if [ ! -d $(BIN_DIR) ]; then $(MKDIR) $(BIN_DIR); fi
					$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(DEBUG_NAME) $(DEBUG_OBJS) $(LINKERS)

memory:				$(DEBUG_PREQ)
					@$(CHECK_MEMORY)

gdb:				debug
					$(DEBUGGER) $(DEBUG_NAME)