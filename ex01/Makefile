CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++11

TARGET = serializer

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/Serializer.cpp


OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -r $(OBJ_DIR) || true

fclean: clean
	rm -f $(TARGET)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re