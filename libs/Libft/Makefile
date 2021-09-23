include make.mk

.DEFAULT_GOAL := clear_on_fail 

clear_on_fail:
	$(MAKE) all || $(MAKE) fclean		

.PHONY: clear_on_fail
