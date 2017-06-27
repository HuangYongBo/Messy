

include $(TOPDIR)/config.mk

LIB = $(obj)libupgrade.a

AOBJS =
COBJS-y += my_upgrade.o
COBJS-y += Charbitmap36.o
COBJS-y += Charbitmap50.o


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
