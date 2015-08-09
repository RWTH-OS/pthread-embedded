NEWLIB = ../x86/x86_64-hermit
MAKE = make
ARFLAGS = rsv
CP = cp
C_source =  $(wildcard *.c) platform/hermit/pte_osal.c platform/helper/tls-helper.c
NAME = libpthread.a
OBJS = $(C_source:.c=.o)

#
# Prettify output
V = 0
ifeq ($V,0)
	Q = @
	P = > /dev/null
endif

# other implicit rules
%.o : %.c
	@echo [CC] $@
	$Q$(CC_FOR_TARGET) -c $(CFLAGS) -o $@ $< 

default: all

all: $(NAME)

$(NAME): $(OBJS)
	$Q$(AR_FOR_TARGET) $(ARFLAGS) $@ $(OBJS)
	$Q$(CP) $@ $(NEWLIB)/lib
	$Q$(CP) pthread.h $(NEWLIB)/include
	$Q$(CP) platform/hermit/pte_types.h $(NEWLIB)/include
	
clean:
	@echo Cleaning examples
	$Q$(RM) $(NAME) *.o *~ 

veryclean:
	@echo Propper cleaning examples
	$Q$(RM) $(NAME) *.o *~

depend:
	$Q$(CC_FOR_TARGET) -MM $(CFLAGS) *.c > Makefile.dep

-include Makefile.dep
# DO NOT DELETE
