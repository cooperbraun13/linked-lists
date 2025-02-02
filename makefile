all: compile run clean

compile: 
	@g++ -std=c++11 linked_list.cpp main.cpp -o link

run:
	@./link

clean:
	@rm link

test: test_compile test_run test_clean

test_compile:
	@g++ -std=c++11 linked_list.cpp testing.cpp -o test

test_run:
	@./test

test_clean:
	@rm test