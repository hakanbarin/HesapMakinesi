
exe: build/main.o build/hello.o build/hakan.o
	gcc build/main.o build/hello.o build/hakan.o -o build/exe -lpthread

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< -o $@ -Iinclude 
	

clean:
	rm -rf build
