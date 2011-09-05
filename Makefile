CXXFLAGS =	-O2 -g -Wall -fmessage-length=0  `pkg-config glib-2.0 --cflags --libs`
OBJS =		main.o  config.o  input.o egg.o
 
LIBS = -lfcgi -lscholar -legg2 -lboost_regex

TARGET =	cc.fcgi

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

