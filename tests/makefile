.PHONY: clean build

c_compiler=$(CC)
includes=-I ./../include/
object_files=./../build/*.o
warnings=-Wall -Wextra -Werror -pedantic
release=-O3
debug=-Og -g
standard=-std=c11

flags  = $(includes) 
flags += $(object_files)
flags += $(warnings)
flags += $(standard)
flags += $(release)

build: test_1 test_2 test_3 test_4 test_5 test_6

test_1: test_1.c
	$(c_compiler) $(flags) test_1.c -o test_1
test_2: test_2.c
	$(c_compiler) $(flags) test_2.c -o test_2
test_3: test_3.c
	$(c_compiler) $(flags) test_3.c -o test_3
test_4: test_4.c
	$(c_compiler) $(flags) test_4.c -o test_4
test_5: test_5.c
	$(c_compiler) $(flags) test_5.c -o test_5
test_6: test_6.c
	$(c_compiler) $(flags) test_6.c -o test_6

clean:
	rm test_1
	rm test_2
	rm test_3
	rm test_4
	rm test_5
	rm test_6
