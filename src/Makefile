CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11
GCOVFLAGS := -fprofile-arcs -ftest-coverage
LDFLAGS := -lcheck -lgcov -fprofile-arcs --coverage
ifeq ($(shell uname), Linux)
    LDFLAGS += -lpthread -lrt -lm -lsubunit
    OPEN_CMD := xdg-open
else ifeq ($(shell uname), Darwin)
    OPEN_CMD := open
endif

SRC := $(wildcard modules/source/*.c)
OBJ = $(patsubst modules/source/%.c, obj/%.o, $(SRC))
OBJ_GCOV = $(patsubst modules/source/%.c, gcov_obj/%.o, $(SRC))
TEST_SRC := $(wildcard tests/*.c)
TEST_OBJ = $(patsubst tests/%.c, tests/%.o, $(TEST_SRC))

TARGET := 3DViewer

all: clean install
	
obj/%.o: modules/source/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

gcov_obj/%.o: modules/source/%.c
	@$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

3d_viewer.a: $(OBJ)
	@ar -src $@ $(OBJ)

3d_viewer_gcov.a: $(OBJ_GCOV)
	@ar -src $@ $(OBJ_GCOV)

test: tests/tests.o 3d_viewer_gcov.a
	@$(CC) -g $< 3d_viewer_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	@clear
	@./$@

install: uninstall
	@clear
	@echo "===>    Installation has started     <==="
	@mkdir -p ../build
	@cd view/3DViewer/ && qmake && make && make clean && rm -rf Makefile && mv $(TARGET).app ../../../build
	@cp -R ../build/$(TARGET).app ~/Desktop/$(TARGET).app
	@echo "===> 3DViewer V1.0 application installed <==="

uninstall: clean
	@rm -rf ~/Desktop/$(TARGET).app
	@echo "===>  3DViewer V1.0 application removed  <==="

dvi:
	@open README.md

dist:
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp README.md ../dist && cp README.md ../dist
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET).app src/README.md

gcov_report: test
	lcov -c -d gcov_obj/. -o gcov_obj/coverage.info
	genhtml gcov_obj/coverage.info --output-directory out
	$(OPEN_CMD) out/index.html

clean:
	@rm -rf ../build ../dist gcov_obj/*.o test
	@rm -rf gcov_obj/*.gcda gcov_obj/*.gcno 
	@rm -rf gcov_obj/*.info out *.a *.gcno tests/tests.o qt/*
	@rm -rf ../.DS_Store .DS_Store ../.vscode view/.DS_Store

ultra_test: clean test gcov_report

clang:
	@clang-format -i modules/source/*.c modules/header/*.h tests/*.c view/3DViewer/*.cpp view/3DViewer/*.h view/3DViewer/*.ui

style:
	@clang-format -n modules/source/*.c modules/header/*.h tests/*.c view/3DViewer/*.cpp view/3DViewer/*.h view/3DViewer/*.ui

cppcheck: clean test
	@cppcheck --enable=all --suppress=missingIncludeSystem modules/source/ modules/header/ view/3DViewer/

valgrind: clean test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

leaks: clean test
	@leaks -atExit -- ./test

file:
	open https://drive.google.com/file/d/1YEcNc4zkODRtwU2QbIEbBAbtLYOCrjo5/view?usp=drive_link