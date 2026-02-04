##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile
##

NAME			:= nanotekspice
CXX				:= clang++

# --- Folders
SRC_DIR			:= src
TESTS_DIR		:= tests
OBJS_DIR		:= obj

# --- Files to compile
SRCS			:= $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJ_SRCS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# --- Tests
OBJ_NO_MAIN		:= $(filter-out $(OBJS_DIR)/$(SRC_DIR)/main.o, $(OBJ_SRCS))
# TESTS_TARGET	:= unit_tests
# TESTS_SRCS	:= $(shell find $(TESTS_DIR) -type f -name '*.cpp')
OBJ_TESTS		:= $(TESTS_SRCS:%.cpp=$(OBJS_DIR)/%.o)

# --- Flags
CPPFLAGS		:= -MMD -MP
CXXFLAGS		:= -Wall -Wextra -std=c++20
_COVERAGE_FLAGS	:= --coverage
COVERAGE_FLAGS	:=

# --- Progress bar
TOTAL_FILES		:= $(words $(SRCS) $(TESTS_SRCS))
CUR_FILES		= 0

# --- Colors
BOLD			:= \033[1m
FAINT			:= \033[2m
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
RESET			:= \033[0m

# --- Rules
all: $(NAME)

debug: CXXFLAGS += -g3
debug: re

$(NAME): $(OBJ_SRCS)
	@printf "\n$(YELLOW)Linking $(NAME)...$(RESET)\n"
	@$(CXX) -o $@ $(OBJ_SRCS) $(CXXFLAGS)
	@printf "$(BOLD)$(GREEN)./$@ compiled successfully (˶ᵔ ᵕ ᵔ˶)$(RESET)\n"

# --- Compilation
GET_PERCENT	= $(shell echo $$(($(CUR_FILES) * 100 / $(TOTAL_FILES))))

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(eval CUR_FILES=$(shell echo $$(($(CUR_FILES)+1))))
	@printf "\r$(BLUE)[%3d%%]$(RESET) Compiling $(BOLD)$<$(RESET)\033[K" \
		$(GET_PERCENT)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

# --- Clean
clean:
	@printf "$(FAINT)Cleaning objects...$(RESET)\n"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@printf "$(FAINT)Cleaning binaries...$(RESET)\n"
	@rm -f $(NAME) $(TESTS_TARGET)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

# --- Tests
# unit_tests: $(eval TOTAL_FILES=$(shell echo $$(($(TOTAL_FILES)-1))))
# unit_tests: COVERAGE_FLAGS += $(_COVERAGE_FLAGS)
# unit_tests: $(OBJ_NO_MAIN) $(OBJ_TESTS)
# 	@printf "\n$(YELLOW)Linking tests binary...$(RESET)\n"
# 	@$(CXX) -o $(TESTS_TARGET) $(OBJ_NO_MAIN) $(OBJ_TESTS) \
# 		$(CXXFLAGS) $(CPPFLAGS) $(_COVERAGE_FLAGS) -lcriterion
# 	@printf "$(GREEN)$(BOLD)Tests compiled successfully (˶ᵔ ᵕ ᵔ˶)$(RESET)\n"
#
# tests_run: unit_tests
# 	@printf "$(BOLD)$(YELLOW)Running tests...$(RESET)\n"
# 	@./$(TESTS_TARGET)
#
# tests_clean:
# 	@printf "$(YELLOW)Cleaning coverage data...$(RESET)\n"
# 	@find . -type f \( -name '*.gcda' -o -name '*.gcno' \) -delete

# --- Special
.PHONY: all clean fclean re unit_tests tests_run tests_clean debug
-include $(OBJ_SRCS:.o=.d) $(OBJ_TESTS:.o=.d)
