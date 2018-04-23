
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
class MinPriorityQueue
{
	// For the mandatory running times below:
	//
	// n is the number of strings in the MinPriorityQueue.
	//
	// Assume that the operations of unordered_map are O(1) time 
	// (they are average case, but not worst-case).

	public:
		// Creates an empty MinPriorityQueue
		MinPriorityQueue()
		{

		}

		// Returns the number of elements in the MinPriorityQueue.
		//
		// Must run in O(1) time.
		int size()
		{
			return H.size();
		}	

		// Pushes a new element x with priority p
		// into the MinPriorityQueue.
		//
		// Must run in O(log(n)) time.		 
		void push(T x, int p)
		{
			pair<T, int> e(x, p);
			H.push_back(e);
			I[x] = H.size()-1;
			bubble_up(I[x]);
		}

		// Returns the string at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		// 
		// Must run in O(1) time.
		T front()
		{
			return H[0].first;
		}

		// Removes the string at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		//
		// Must run in O(log(n)) time. 
		void pop()
		{
			if (size() == 0)
				return;

			H[0] = H[H.size()-1];
			H.pop_back();
			I[H[0].first] = 0;

			int cur = 0;
			while (true)
			{
				if (cur >= H.size())
					break;
				int l = 2*cur+1;
				int r = 2*cur+2;		

				// Both children don't exist
				if (l >= H.size())
					break;

				// Right child doesn't exist and
				// left child is too big
				if (r >= H.size() && H[l].second >= H[cur].second)
					break;

				// Right and left children exist and
				// both are too big
				if (r < H.size() && H[l].second >= H[cur].second && H[r].second >= H[cur].second)
					break;

				// Now we need to swap 
				int chi;
				if (r >= H.size() || H[l].second <= H[r].second)
					chi = l;
				else
					chi = r;	
				
				// Update I
				I[H[chi].first] = cur;
				I[H[cur].first] = chi;

				// Swap parent and child in heap
				swap(H[chi], H[cur]);

				cur = chi;
			}
		}

		// If s is in the MinPriorityQueue 
		// with current priority at least new_p,  
		// then changes the priority of x to new_p.
		// Undefined behavior otherwise.
		//
		// Must run in O(log(n)) time. 
		void decrease_key(T x, int new_p)
		{
			H[I[x]].second = new_p;	
			bubble_up(I[x]);	
		}

	private:

		void bubble_up(int i)
		{
			int cur = i;
			while (true)
			{
				if (cur == 0)
					break;
				int par = (cur-1)/2;
				if (H[par].second <= H[cur].second)
					break;

				// Update I
				I[H[par].first] = cur;
				I[H[cur].first] = par;

				// Swap parent and child in heap
				swap(H[par], H[cur]);

				cur = par;
			} 

		}

		unordered_map<T, int> I; // Maps elements to indices in H.
		vector< pair<T, int> > H;    // The heap 
};

#endif 

