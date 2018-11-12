target = tcp_client

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

APP = g++

all:$(target)

$(target):$(OBJS)
	@echo "Linking $@"
	$(APP) $(OBJS) -o $@

%.o:%.cpp
	@echo "Compling $<"
	$(APP) -c $<
.PHONY:clean
clean:
	rm -f $(target)
	rm -f $(OBJS)
