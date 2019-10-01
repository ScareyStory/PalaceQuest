CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-sign-compare -Wno-return-type -pedantic-errors -g

SRCS = Main.cpp Space.cpp Grotto.cpp Prison.cpp Swamp.cpp MountainPass.cpp  Foothills.cpp Hut.cpp CursedValley.cpp HiddenCrypt.cpp Forest.cpp Shrine.cpp Ruins.cpp Lake.cpp Darkness.cpp  Character.cpp Warrior.cpp Rogue.cpp Mage.cpp Monk.cpp Bard.cpp Enemy.cpp Warden.cpp Yeti.cpp Ratman.cpp Skellybones.cpp Spiders.cpp Pentapus.cpp Nightsprites.cpp Evil.cpp

OBJS = ${SRCS: .cpp = .o}

HEADERS = Space.hpp Grotto.hpp Prison.hpp Swamp.hpp MountainPass.hpp Foothills.hpp Hut.hpp CursedValley.hpp HiddenCrypt.hpp Forest.hpp Shrine.hpp Ruins.hpp Lake.hpp Darkness.hpp Character.hpp Warrior.hpp Rogue.hpp Mage.hpp Monk.hpp Bard.hpp Enemy.hpp Warden.hpp Yeti.hpp Ratman.hpp Skellybones.hpp Spiders.hpp Pentapus.hpp Nightsprites.hpp Evil.hpp

MAIN = PalaceQuest

all: ${MAIN}
	@echo
	@echo sucessfully compiled!
	@echo

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
