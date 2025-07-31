CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++11 
#-DDEBUG

TARGET = convert
TEST_TARGET = test_converter

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/ScalarConverter.cpp

TEST_SRC =	$(SRC_DIR)/test.cpp \
			$(SRC_DIR)/ScalarConverter.cpp

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ = $(TEST_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

test: $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)

re: fclean all

.PHONY: all clean fclean re test