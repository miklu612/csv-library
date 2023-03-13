.PHONY: clean build

c_compiler=$(CC)
includes=-I ./include
warnings=-Wall -Wextra -Werror -pedantic
release=-O3
debug=-g -Og
standard=-std=c11

flags=$(includes) $(warnings) $(release) $(standard)

build: build/csv_row.o build/csv.o build/csv_reader.o

build/csv_row.o: src/csv_row.c
	$(c_compiler) $(flags) -c src/csv_row.c -o build/csv_row.o
build/csv.o: src/csv.c build/csv_row.o
	$(c_compiler) $(flags) -c src/csv.c -o build/csv.o
build/csv_reader.o: src/csv_reader.c build/csv_row.o build/csv_row.o
	$(c_compiler) $(flags) -c src/csv_reader.c -o build/csv_reader.o

clean:
	rm build/csv_row.o
	rm build/csv.o
	rm build/csv_reader.o
