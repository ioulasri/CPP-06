# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Source files
SRC = main.cpp \
      other_file.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = my_program

# Default target: compile and link
all: $(EXEC)

# Linking the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compiling the .cpp files into .o object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)

# Clean up object files only
fclean: clean

# Rebuild everything (clean + compile)
re: fclean all
