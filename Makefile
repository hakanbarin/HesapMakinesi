
exe: build/main.o build/hesap.o build/calculation.o
	gcc build/main.o build/hesap.o -o build/exe -lpthread

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< -o $@ -Iinclude 
	

clean:
	rm -rf build
