TARGET = linked_list_demo
OBJDIR = obj
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/**/*.c)
HEADERS = $(wildcard $(SRCDIR)/*.h $(SRCDIR)/**/*.h) 
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS = $(HEADERS)
CC = gcc

# main goal
all: $(TARGET)

debug: CFLAGS += -DDEBUG -g
debug: $(TARGET)

# target executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

# object files
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLPATH)

# create object files directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# clean
clean:
	rm -rf $(OBJDIR)

# distclean
distclean: clean
	rm -f $(TARGET)
	
	
.PHONY: all clean distclean