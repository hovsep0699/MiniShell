LIBFT_PATH		=	libs/Libft

LIBFT2_PATH		=	libs/Libft_Vache

MAKELIBFT		=	$(MAKE) -C $(LIBFT_PATH)

MAKELIBFT2		=	$(MAKE) -C $(LIBFT2_PATH)

LINKERS			=	-L$(LIBFT_PATH)/bin -lft -L$(LIBFT2_PATH) -lft_vache -lreadline

MAKELIBS		=	@if [ ! -f $(LIBFT_PATH)/bin/libft.a  ]; then $(MAKELIBFT); fi

MAKELIBS2		=	@if [ ! -f $(LIBFT2_PATH)/bin/libft.a  ]; then $(MAKELIBFT2); fi

libs:
					$(MAKELIBFT) re
					$(MAKELIBFT2) re