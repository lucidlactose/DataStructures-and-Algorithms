CXX = g++
CXXFLAGS = -std=c++11
OBJFILES = BubbleSort.o SelectionSort.o RadixSort.o MergeSort.o \
		QuickSort.o HeapSort.o HeapSort2.o RadixSort.o test.o

all:  $(OBJFILES) test
BubbleSort.o: ../BubbleSort.cpp
	$(CXX) $(CXXFLAGS) -c ../BubbleSort.cpp
SelectionSort.o: ../SelectionSort.cpp
	$(CXX) $(CXXFLAGS) -c ../SelectionSort.cpp
MergeSort.o: ../MergeSort.cpp
	$(CXX) $(CXXFLAGS) -c ../MergeSort.cpp
QuickSort.o: ../QuickSort.cpp
	$(CXX) $(CXXFLAGS) -c ../QuickSort.cpp
HeapSort.o: ../HeapSort.cpp
	$(CXX) $(CXXFLAGS) -c ../HeapSort.cpp
HeapSort2.o: ../HeapSort2.cpp
	$(CXX) $(CXXFLAGS) -c ../HeapSort2.cpp
RadixSort.o: ../RadixSort.cpp
	$(CXX) $(CXXFLAGS) -c ../RadixSort.cpp
test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test.out
test:
	# use shell scripts for the comparison
	# for t in test*.sh; do ./$$t; echo $$?; done
	./test.out
	./test1.sh
.PHONY: clean
clean:
	rm -f results.txt *.o *.out *Sort*.txt

