# Compiler to use
CC := cc

# Default Cflags used for compilation
CFLAGS := -Werror -Wall -Wextra -MMD -g3

LIBFT := ./libft/lib/libft.a
FT_PRINTF := ./ft_printf/lib/libftprintf.a

# Directory where header files are located
INCLUDES := -Iincludes -Ift_printf/includes -Ilibft/includes

OBJ_DIR := objs
SRC_DIR := src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))



TARGET := push_swap

# Dependency files for header dependencies
DEPEND := $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $^ -o $(TARGET)

# Rule to generate all object files and create OBJ_DIR if it doesn't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

# Include the dependency files to manage header dependencies
-include $(DEPEND)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

re: fclean all
