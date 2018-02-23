NAME := 1.out
SRC_DIR := src
BIN_DIR := bin
C_SRCS := $(wildcard $(SRC_DIR)/*.c)
CXX_SRCS := $(wildcard $(SRC_DIR)/*.cpp)
C_OBJS := ${C_SRCS:.c=.o}
CXX_OBJS := ${CXX_SRCS:.cpp=.o}
OBJS := $(C_OBJS) $(CXX_OBJS)
INCLUDE_DIRS := .
LIBRARY_DIRS := .
LIBRARIES := .
OUTPUT := $(BIN_DIR)/$(NAME)

SUBDIRS := testing

CPPFLAGS += -std=c++11  $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(LIBRARIES),-L$(library))

.PHONY: all clean

all: $(NAME)
	cd testing && cmake CMakeLists.txt;
	make -C $(SUBDIRS)

$(NAME): $(OBJS)
	g++ -g $(CPPFLAGS) $(OBJS) -o $(OUTPUT)

clean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	make -C $(SUBDIRS) clean

