EE_BIN = mcc-ps2.elf
EE_OBJS = src/main.o

EE_INCS = -I$(PS2DEV)/gsKit/include
EE_LDFLAGS = -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/ports/lib
EE_LIBS = -lgskit_toolkit -lgskit -ldmakit -lpng -lz

all: $(EE_BIN)

ifdef OS
   RM = del /Q /F /S
else
   RM = rm -f
endif

clean:
	$(RM) *.o *.elf


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

DIR_GUARD =
