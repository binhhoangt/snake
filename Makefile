.PHONY: all, print, clean

TARGET=snake

CC:= gcc
CXX:= g++

INC+= $(wildcard *.hpp)
CSRCS+= $(wildcard *.cpp)
$(info ${CSRCS})

OBJSDIR=build
OBJS+= $(patsubst %.cpp, $(OBJSDIR)/%.o, $(CSRCS))

CFLAGS += -I./include -DDEBUG -Wall -g
# LDFLAGS += -L./lib

all: mkdir ${TARGET}
	@echo Build complete!

${TARGET} : $(OBJS)
	@echo " [LINK] $@"
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJSDIR)/%.o: %.cpp $(INC)
	@echo " [CXX]  $@"
	$(CXX) -c $< -o $@ $(CFLAGS)

mkdir:
	@mkdir -p $(OBJSDIR)

print:
	@echo $(OBJS)

clean:
	rm -rf ${OBJSDIR}
	rm -rf ${TARGET}
