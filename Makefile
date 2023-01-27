SYSCONF_LINK = g++ -ggdb -g -pg -O0
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./
TARGET  = renderer

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)
	-rm -f *.tga
# profiler output
	-rm -f *.out 	
# profile information text
	-rm -f profInfo 
