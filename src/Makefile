BD=../build/
QMAKE=$(BD)
CFLAGS=-c# -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./
EXE=$(QMAKE)Algorithm_traiding.app/Contents/MacOS/Algorithm_traiding
APP=$(QMAKE)Algorithm_traiding.app
APPDIR=$(HOME)/Applications/Algorithm_traiding/
APP_EXE=$(APPDIR)Algorithm_traiding.app/Contents/MacOS/Algorithm_traiding
CC=g++

all: install
	$(APP_EXE)

build: $(BD) $(BD)qmake.pro
	cd $(QMAKE); qmake qmake.pro
	make -C $(QMAKE)

./$(BD):
	mkdir $(BD)

arrange:
	rm -f $(QMAKE)qmake.*
	cd $(QMAKE); qmake -project ../src/; mv build.pro ../src/qmake.pro

./$(BD)qmake.pro:
	cp qmake.pro $(QMAKE)

./$(BD)%.o: */%.cpp
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

install: build 
	@mkdir $(APPDIR) || echo "Directory already exists. Skip."
	cp -rf manual/ $(APPDIR)manual/
	cp -rf $(APP) $(APPDIR)
	make clean

uninstall:
	rm -rf $(APPDIR)
	rm -rf $(HOME)/Applications/Algorithm_traiding.tar.gz

dvi:
	@open $(APPDIR)manual/manual.html || echo "Please, install application first!"

dist:
	tar -cvf $(APPDIR)../Algorithm_traiding.tar $(APPDIR)
	gzip $(APPDIR)../Algorithm_traiding.tar

clean:
	test -f $(QMAKE)Makefile && make distclean -C $(QMAKE) || printf ""
	rm -rf ./$(BD)*

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

format:
	cp ../materials/linters/.clang-format . && \
	clang-format -i */*/*/*.cc */*/*.cc */*.cc *.cc */*/*/*.h */*/*.h */*.h; \
	rm -f .clang-format

clang:
	cp ../materials/linters/.clang-format . && \
	clang-format -n */*/*/*.cc */*/*.cc */*.cc *.cc */*/*/*.h */*/*.h */*.h; \
	rm -f .clang-format
