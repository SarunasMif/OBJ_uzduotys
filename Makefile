vector: main_vector.o
	g++ main_vector.o -o vector

main_vector.o: main_vector.cpp headers_vector.h includes.h
	g++ -c main_vector.cpp

clean_vector:
	rm *.o vector

list: main_list.o
	g++ main_list.o -o list 

main_list.o: main_list.cpp headers_list.h includes.h 
	g++ -c main_list.cpp 

clean_list:
	rm *.o list

deque: main_deque.o
	g++ main_deque.o -o deque 

main_deque.o: main_deque.cpp headers_deque.h includes.h 
	g++ -c main_deque.cpp

clean_deque:
	rm *.o deque