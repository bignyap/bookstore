bookStore: common.o csvutil.o user.o book.o action.o bookStore.o
	g++ common.o csvutil.o user.o book.o action.o bookStore.o -o bookStore.exe

common.o: common.cpp
	g++ -c common.cpp

csvutil.o: csvutil.cpp
	g++ -c csvutil.cpp

user.o: user.cpp
	g++ -c user.cpp

book.o: book.cpp
	g++ -c book.cpp

action.o: action.cpp
	g++ -c action.cpp

bookStore.o: bookStore.cpp
	g++ -c bookStore.cpp

clean:
	@echo "clean project"
	-$(RM) *.o
	@echo "clean completed"
.PHONY: clean