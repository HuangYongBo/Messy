

include $(TOPDIR)/config.mk

LIB = $(obj)libselect.a

AOBJS =
COBJS-y += select.o


COBJS := $(sort $(COBJS-y))
SRC   := $(AOBJC:.o=.S) $(COBJS:.o=.c)
OBJS  := $(addprefix $(obj),$(AOBJC) $(COBJS))

CPPFLAGS += -I..

all: $(LIB) $(AOBJS)
$(LIB):$(obj).depend $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)


###################################################
 #defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend
#################################################
