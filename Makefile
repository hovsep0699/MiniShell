include compile/libs.mk
include compile/debug.mk
include compile/main.mk

.DEFAULT_GOAL := clear_on_fail

clear_on_fail:
	$(MAKE) all || $(MAKE) fclean

.PHONY: clear_on_fail
