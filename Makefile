# Makefile

# set File
program = DesktopChara
objs = DesktopChara.o Config.o Screen.o Character.o

# set option
CC = g++
RM = del
CFLAGS = -g -Wall -s --exec-charset=cp932
DXFLAGS = -IC:/msys64/mingw64/site-packages/dxlib \
			-LC:/msys64/mingw64/site-packages/dxlib \
			-DDX_GCC_COMPILE \
			-DDX_NON_INLINE_ASM \
			-lDxLib \
			-lDxUseCLib \
			-lDxDrawFunc \
			-ljpeg \
			-lpng \
			-lzlib \
			-ltiff \
			-ltheora_static \
			-lvorbis_static \
			-lvorbisfile_static \
			-logg_static \
			-lbulletdynamics \
			-lbulletcollision \
			-lbulletmath \
			-lopusfile \
			-lopus \
			-lsilk_common \
			-lcelt \
			-mwindows

# SUFFIXES RULE
.SUFFIXES: .cpp .o

# Compile
$(program): $(objs)
	$(CC) -o $(program) $^ $(CFLAGS) $(DXFLAGS)

# make Objects
.c.o:
	$(CC) -c $< $(CFLAGS) $(DXFLAGS)

# run exe
.PHONY: run
run:
	$(program).exe

# clean objects
.PHONY: clean
clean:
	$(RM) $(program).exe $(objs)

# header files
Config.o: Config.h
Screen.o: Screen.h
Character.o: Character.h
