
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

// NOTE: You may not include any other libraries!
#include <unordered_map>
#include <vector>
#include <utility> // Has pair and swap

using namespace std;

template <typename T>
class MinPriorityQueue
{
	// For the mandatory running times below:
	//
	// n is the number of strings in the MinPriorityQueue.
	//
	// Assume the operations of map are O(1) time 
	// (they are average case, but not worst-case).

	public:
		// Creates an empty MinPriorityQueue
		MinPriorityQueue()
		{
			// TODO
		}

		// Returns the number of elements in the MinPriorityQueue.
		//
		// Must run in O(1) time.
		int size()
		{
			// TODO	
		}	

		// Pushes a new element x with priority p
		// into the MinPriorityQueue.
		//
		// Must run in O(log(n)) time. 
		void push(T x, int p)
		{
			// TODO
		}

		// Returns the string at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		// 
		// Must run in O(1) time.
		T front()
		{
			// TODO	
		}

		// Removes the string at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		//
		// Must run in O(log(n)) time. 
		void pop()
		{
			// TODO	
		}

		// If s is in the MinPriorityQueue 
		// with current priority at least new_p,  
		// then changes the priority of x to new_p.
		// Undefined behavior otherwise.
		//
		// Must run in O(log(n)) time. 
		void decrease_key(T x, int new_p)
		{
			// TODO
		}

	private:
		// You don't need any other instance variables,
		// but you can add some if you want to.
		unordered_map<T, int> I; // Maps elements to indices in H.
		vector< pair<T, int> > H;     // The array containing the heap.
};

#endif 

