
#include "tiling.h"

using namespace std;

class Vertex
{
        public:
                unordered_set<Vertex*> neighs;
                unordered_map<Vertex*, int> weights;
};

// Finds a (shortest according to edge length) augmenting path
// from s to t in a graph with vertex set V.
// Returns whether there is an augmenting path.
bool augmenting_path(Vertex* s, Vertex* t, 
        unordered_set<Vertex*> V, vector<Vertex*> &P)
{
        // Check that s and t aren't nullptr
        if (s == nullptr || t == nullptr)
	{
		cerr << "augmenting_path() was passed nullptr s or t." << endl;
		abort();
	}

        // Check that s and t are in the graph
        if (V.find(s) == V.end() || V.find(t) == V.end())
	{
		cerr << "augmenting_path() was passed s or t not in V." << endl;
		abort();
	}

	// Check that every vertex has valid neighs/weights.
	for (Vertex* v : V)
		for (Vertex* vn : v->neighs)
			if (v->weights.find(vn) == v->weights.end())
			{
				cerr << "augmenting_path() was passed invalid vertex." << endl;
				abort();
			}

        // Since augmenting paths should have the fewest edges,
	// not the minimum weight, run BFS.
	queue<Vertex*> Q;
	Q.push(s);

	unordered_set<Vertex*> R;
	R.clear(); 
	R.insert(s);

	unordered_map<Vertex*, Vertex*> prev;

	while (!Q.empty())
	{
		Vertex* cur = Q.front();
		Q.pop();

		for (Vertex* nei : cur->neighs)
		{
			// Must have positive edge weight
			if (cur->weights[nei] == 0)
				continue;

			if (R.find(nei) == R.end())
			{
				Q.push(nei);
				R.insert(nei);
				prev[nei] = cur; 
			}
		}
	}      

        // If BFS never reached t
        if (R.find(t) == R.end())
                return false;

        // Reconstruct shortest path backwards
        P.clear();
        P.push_back(t);
        while (P[P.size()-1] != s)
                P.push_back(prev[P[P.size()-1]]);

        // Reverse shortest path
        for (int i = 0; i < P.size()/2; ++i)
		swap(P[i], P[P.size()-1-i]);

        return true;
}

// Returns the maximum flow from s to t in a weighted graph with vertex set V.
// Assumes all edge weights are non-negative.
int max_flow(Vertex* s, Vertex* t, unordered_set<Vertex*> V)
{
	// If s or t is invalid.
        if (s == nullptr || t == nullptr)
	{
		cerr << "max_flow() was passed nullptr s or t." << endl;
		abort(); 
	}

	// If s or t is not in the vertex set.
        if (V.find(s) == V.end() || V.find(t) == V.end())
	{
		cerr << "max_flow() was passed s or t not in V." << endl;
		abort(); 
	}

	// Check that every vertex has valid neighs/weights.
	for (Vertex* v : V)
		for (Vertex* vn : v->neighs)
			if (v->weights.find(vn) == v->weights.end())
			{
				cerr << "max_flow() was passed invalid vertex." << endl;
				abort();
			}

        // Create a deep copy of V to use as the residual graph
        unordered_set<Vertex*> resV;
        unordered_map<Vertex*, Vertex*> C; // Maps vertices in V to copies in resV
        for (Vertex* vp : V)
        {
                Vertex* rp = new Vertex;
                resV.insert(rp);
                C[vp] = rp;
        }
        for (Vertex* vp : V)
                for (Vertex* np : vp->neighs)
                {
                        C[vp]->neighs.insert(C[np]);
                        C[vp]->weights[C[np]] = vp->weights[np];
                }
	// Add any missing necessary "back" edges. 
        for (Vertex* vp : V)
                for (Vertex* np : vp->neighs)
		{
			if (C[np]->neighs.find(C[vp]) == C[np]->neighs.end())
			{
				C[np]->neighs.insert(C[vp]);
				C[np]->weights[C[vp]] = 0;
			}
		}

        // Run Edmonds-Karp
        while (true)
        {
                // Find an augmenting path
                vector<Vertex*> P;
                if (!augmenting_path(C[s], C[t], resV, P))
                        break;  
                // Update residual graph
                for (int i = 0; i < P.size()-1; ++i)
                {
                        --((*(resV.find(P[i])))->weights[P[i+1]]);
                        ++((*(resV.find(P[i+1])))->weights[P[i]]);
                }
        }

        // Compute actual flow amount
        int flow = 0;
        for (Vertex* snp : C[s]->neighs)
                flow += 1 - C[s]->weights[snp];

        // Delete residual graph
        for (Vertex* vp : resV)
                delete vp;

        return flow;
}

bool has_perfect_matching(unordered_set<Vertex*> V1, unordered_set<Vertex*> V2)
{
        // Easy case
        if (V1.size() != V2.size())
                return false;

        // Create a new graph that's a deep copy graph of the union of V1 and V2
        unordered_set<Vertex*> V;
        unordered_map<Vertex*, Vertex*> C;
        for (Vertex* vp : V1)
        {
                Vertex* vcp = new Vertex;
                V.insert(vcp);
                C[vp] = vcp;
        }
        for (Vertex* vp : V2)
        {
                Vertex* vcp = new Vertex;
                V.insert(vcp);
                C[vp] = vcp;
        }

        // Only bother to add directed edges from V1 to V2
        for (Vertex* vp : V1)
                for (Vertex* np : vp->neighs)
		{
                        C[vp]->neighs.insert(C[np]);
			C[vp]->weights[C[np]] = 1;
		}

        // Add new vertex s that points to everything in V1
        Vertex s;
        for (Vertex* vp : V1)
	{
                s.neighs.insert(C[vp]);
                s.weights[C[vp]] = 1;
	}
        V.insert(&s);
        
        // Add new vertex t that everything V2 points to
        Vertex t;
        for (Vertex* vp : V2)
	{
                C[vp]->neighs.insert(&t);
                C[vp]->weights[&t] = 1;
	}
        V.insert(&t);

        int mf = max_flow(&s, &t, V);

        // Cleanup
        for (Vertex* vp : V1)
                delete C[vp];
        for (Vertex* vp : V2)
                delete C[vp];

        // Return the answer
        return (mf == V1.size()); 
}

void dual_graph(string floor, unordered_set<Vertex*> &V1, 
        unordered_set<Vertex*> &V2)
{
        int width = floor.find_first_of('\n');
        int height = floor.length() / (width+1);

        char** F = new char*[height];
        for (int r = 0; r < height; ++r)
                F[r] = new char[width];
        
        Vertex*** FV = new Vertex**[height];
        for (int r = 0; r < height; ++r)
                FV[r] = new Vertex*[width];
        
        for (int r = 0; r < height; ++r)
                for (int c = 0; c < width; ++c)
                        F[r][c] = floor[r*(width+1) + c];

        // Construct vertices
        V1.clear();
        V2.clear();
        for (int r = 0; r < height; ++r)
                for (int c = 0; c < width; ++c)
                {
                        if (F[r][c] != ' ')
                        {
                                FV[r][c] = nullptr;
                                continue;
                        }
                        FV[r][c] = new Vertex;
                        (r+c) % 2 ? V1.insert(FV[r][c]) : V2.insert(FV[r][c]);
                }

        // Construct edges
        for (int r = 1; r < height-1; ++r)
                for (int c = 1; c < width-1; ++c)
                {
                        if (FV[r][c] == nullptr)
                                continue;
                        if (FV[r-1][c] != nullptr)
                                FV[r][c]->neighs.insert(FV[r-1][c]);
                        if (FV[r+1][c] != nullptr)
                                FV[r][c]->neighs.insert(FV[r+1][c]);
                        if (FV[r][c-1] != nullptr)
                                FV[r][c]->neighs.insert(FV[r][c-1]);
                        if (FV[r][c+1] != nullptr)
                                FV[r][c]->neighs.insert(FV[r][c+1]);
                }      

        // Delete used arrays
        for (int r = 0; r < height; ++r)
                delete[] FV[r];
        delete[] FV;

        for (int r = 0; r < height; ++r)
                delete[] F[r];
        delete[] F;
}

bool has_tiling(string floor)
{
        // Turn it into a graph
        unordered_set<Vertex*> V1;
        unordered_set<Vertex*> V2;
        dual_graph(floor, V1, V2);
        return has_perfect_matching(V1, V2);
}







