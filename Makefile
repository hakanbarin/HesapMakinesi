
exe: build/main.o build/hesap.o build/calculation.o
	gcc build/calculation.o build/hesap.o build/main.o  -o build/exe -lpthread

build/%.o: src/%.c
	mkdir -p build
	gcc -c $< -o $@ -Iinclude 
	

clean:
	rm -rf build
