EE_BIN = mcc-ps2.elf
EE_OBJS = src/main.o

EE_INCS = -IF:/tools/ps2dev/gsKit/include
EE_LDFLAGS = -LF:/tools/ps2dev/gsKit/lib
EE_LIBS = -lgskit -ldmakit

all: $(EE_BIN)

clean:
	del /Q $(EE_OBJS) $(EE_BIN) 2>NUL

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

DIR_GUARD =
