CXX = g++
CXXFLAGS = -std=c++11

top:
	echo "It works"
	# comparisons with bash isn't wokring on mac so I'm doing it with awk
	#cmp --silent answer testBubble || echo "different"
	# $(CXX) $(CXXFLAGS) BubbleSort.cpp
test:
	g++ -std=c++11 BubbleSort.cpp
	./a.out < unsortedArray > testBubble
	cmp -s answer testBubble
	RETVAL=$$?; \
	if [ $$RETVAL -eq 0 ]; then \
		echo "SAME" >> results; \
	else \
		echo "NOT SAME" >> results; \
	fi
clean:
	rm results a.out
