CXX = g++
CXXFLAGS = -std=c++11
OBJFILES = BubbleSort.o CountingSort.o HeapSort.o HeapSort2.o \
			MergeSort.o QuickSort.o RadixSort.o SelectionSort.o \
			main.o

all:  $(OBJFILES) test 
BubbleSort.o: ../BubbleSort.cpp
	$(CXX) $(CXXFLAGS) -c ../BubbleSort.cpp
CountingSort.o: ../CountingSort.cpp
	$(CXX) $(CXXFLAGS) -c ../CountingSort.cpp
HeapSort.o: ../HeapSort.cpp
	$(CXX) $(CXXFLAGS) -c ../HeapSort.cpp
HeapSort2.o: ../HeapSort2.cpp
	$(CXX) $(CXXFLAGS) -c ../HeapSort2.cpp
MergeSort.o: ../MergeSort.cpp
	$(CXX) $(CXXFLAGS) -c ../MergeSort.cpp
QuickSort.o: ../QuickSort.cpp
	$(CXX) $(CXXFLAGS) -c ../QuickSort.cpp
RadixSort.o: ../RadixSort.cpp
	$(CXX) $(CXXFLAGS) -c ../RadixSort.cpp
SelectionSort.o: ../SelectionSort.cpp
	$(CXX) $(CXXFLAGS) -c ../SelectionSort.cpp
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.out
test:
	./main.out
	./main.sh
clean_junk:
	rm -f *.o *.out *Sort*.txt
.PHONY: clean
clean: clean_junk
	rm -f results.txt
