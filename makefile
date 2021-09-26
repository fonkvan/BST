Solution:
	g++ -std=c++11 main.cpp BST.cpp Node.cpp -o Solution

clean:
	rm -f *.o
	rm Solution

run:
	./Solution
