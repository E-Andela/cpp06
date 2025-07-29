CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++11 
#-DDEBUG

TARGET = intern

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/Bureaucrat.cpp \
	  $(SRC_DIR)/AForm.cpp \
	  $(SRC_DIR)/ShrubberyCreationForm.cpp \
	  $(SRC_DIR)/RobotomyRequestForm.cpp \
	  $(SRC_DIR)/PresidentialPardonForm.cpp \
	  $(SRC_DIR)/Intern.cpp \
	  $(SRC_DIR)/tests.cpp


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