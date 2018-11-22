# Flow and Matching :star:
## Max Flow, Maximum Matching :star:
* #### Dinic's algorithm is enough for every problem I've tested. NEVER change the algorithm, there's always a way to model in a way that it will magically work :smiley:
* #### Problems
  * [Fast Flow](https://www.spoj.com/problems/FASTFLOW/) (Heavy optimization needed)
  * [Matching](https://www.spoj.com/problems/MATCHING/) (Heavy optimization needed)
  * [Attacking Rooks](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=602&page=show_problem&problem=4406) (Modeling is pretty incredible)
  * [Martian Volei](https://thehuxley.com/problem/643) (Modeling is beautiful and a bit simple)
  * [670 - The dog task](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=611) (Modeling isn't hard)
  * [Keep It Covered](https://www.urionlinejudge.com.br/judge/pt/problems/view/2705) (Modeling is quite hard... Probably because I wanted to retrieve exact pieces and orientation (for visualization purpose: [keepitcovered.pde](https://github.com/NelsonGomesNeto/ProgramC/tree/master/Visualization/KeepItCovered/keepitcovered)), but here are some hints: bipartite, needs "unification vertex", checkerboard, only dots and lines need to be mapped)
  * [UVA Problem Package](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=685)

## Min Cost Flow :star:
* #### minCostFlow with successive shortest paths.
  * ##### Shortest path algorithms (ordered by the fastest first):
    Always use *Dijkstra with Potentials*, unless the graph has negative edges at the first step; in these cases, use *SPFA*
    * Dijkstra with Potentials O(|E| + |V|log|V|): The intuition behind is that it calculates to difference in cost instead of the actual cost of each step; therefore, it won't have negative costs. It's identical to an ordinary Dijkstra, except that "cost[v] = cost[u] + graph[u][v]", you will have "cost[v] = cost[u] + graph[u][v] + potentials[u] - potentials[v]" and after running dijkstra, you will need to add the costs to the potentials.
    * SPFA O(|V||E|) but usually O(|E|): Kind of a mix between bellmanFord and dijkstra, but doesn't uses a priority queue, so it works perfectly even with negative costs.
    * bellmanFord O(|V||E|): It's very straight forward, but it's dangerous to use it here, although will work mostly.

* #### The successive shortest paths implementation is easy to implement and understand, so I'm using it. It seems like it's more then enough for everything.
* #### Problems
  * [10594 - Data Flow](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1535) (It requires bidirectional edges, so be careful)
  * [11301 - Great Wall of China](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=808&problem=2276) (Requires better shortest path algorithm then bellmanFord's, SPFA will do; and has cost on vertices)
  * [10806 - Dijsktra, Dijsktra](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=808&page=show_problem&problem=1747) (Edges must me utilized only once, so modeling is a bit mind blowing, but quite easy)
  * [Beating the dices in their own game](https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-cost-maximum-flow/practice-problems/algorithm/beating-the-dices-in-their-own-game/) (Matrix won't do, use list of edges)
  * [Amazing Race](https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-cost-maximum-flow/practice-problems/algorithm/amazing-race-3/)
  * [Ciel and Duel](https://codeforces.com/contest/321/problem/B) (*maxCostFlow* haha, an additional if is needed though)
  * [UVA Problem Package](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=808)


# Segment Tree :star:
## Segment Tree without Lazy Propagation :star:
* #### Problems
  * [Fundraising](https://www.urionlinejudge.com.br/judge/en/problems/view/2700) (It's not trivial, we use a max segtree to apply a greedy strategy)
  * [Keep It Energized](https://www.urionlinejudge.com.br/judge/en/problems/view/2010) (It's not trivial, we use min segtree to apply a greedy strategy)
  * PLEASE ADD MORE PROBLEMS HERE

## Segment Tree with Lazy Propagation :star:
* #### Problems
  * [Light Switching](https://www.spoj.com/problems/LITE/) (Pure Segment Tree)
  * [11402 - Ahoy Pirates](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397) (Set update, be careful)
  * [Acordes Intergaláticos](https://www.urionlinejudge.com.br/judge/en/problems/view/2658) (Time is very short, be careful with constants)


# Lowest Common Ancestor (LCA)
* There are two main implementations of LCA, both use a Sparse Table to speed up their queries and takes O(n\*lg) to preprocess.
* Eulerian Tour (O(1) queries):
  * Despite being extremely fast and very easy to understand, it's not flexible
  * It works by build a RMQ on top of the tree's Eulerian tour
    * Run a DFS, *every time* you're in u: add u to the Eulerian tour
      * Even each single time you return from it's child
    * Build RMQ on top of the Eulerian Tour
      * LCA == min RMQ query(from min(first[u], first[v]) to max(first[u], first[v]))
* Binary Lifting (O(lg) queries):
  * Probably more then enough for every problem, and it's very flexible. You can
  answer not only LCA queries, but also all sort of query that involves the path
  (and even weight) between two nodes.
  * It uses DP, where: ancestor(u, i) is the 2^i ancestor of u
    * ancestor(u, 0) = parent of u (you run a DFS to fill up these, also store the level of each node)
    * ancestor(u, i) = ancestor(ancestor(u, i - 1), i - 1)
      * It's saying that the 2^i ancestor is the 2^(i - 1) ancestor of the 2^(i - 1) ancestor
      * Think this way: what is in the middle between u and it's 2^i ancestor?
      Yes, the 2^(i - 1) ancestor, which it self has a 2^(i - 1) ancestor; and
      it's exactly the 2^i ancestor of u. Why this? Because we can bottom up fill it easily.
      We already have the 2^0 ancestor, therefore, we can fill the 2^1, then 2^2, ...
    * To answer the query, we first will need u and v to be at the same level, so
    we go up with the lowest until the levels are the same. Now, we can climb up until
    the ancestor of them are equal. It's quite tricky to grasp everything that is going
    on, but I will so do a video about it (*TODO*).
* #### Problems
  * [Lowest Common Ancestor](https://www.spoj.com/problems/LCA/) (Pure LCA, no tricks; but test cases are very weak)
  * [Match Match](http://www.codcad.com/problem/147) (Pure LCA, but queries for distance)
  * [Ants Colony](http://www.codcad.com/problem/160) (Same as above, but edges have distance)
  * [Lowest Common Ancestor](https://www.codechef.com/problems/TALCA) (Clever, but only uses standard and pure LCA)
  * [10938 - Flea Circus](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1879) (Pretty mind blowing, but very good to practice)


# Graph
* #### Problems
  * [Shipping](https://thehuxley.com/problem/1997) (Very pure Dijkstra)
  * [Zak Galou](https://www.urionlinejudge.com.br/judge/pt/problems/view/1409) (Coin change DP + Dijkstra)
  * [Galactic Taxes](https://www.urionlinejudge.com.br/judge/pt/problems/view/2011) (Ternary Search + Dijkstra)


# Dynamic Programming (DP)
## Longest Common Sequence (LCS)
* #### Problems:
  * [531 - Compromise](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472) (Pure, but needs retrieval)

## Coin change
* #### Problems:
  * [357 - Let Me Count The Ways](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=293) (Very pure)

## Maximum subarray
* #### Problems
  * [10755 - Garbage Heap](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696) (Maximum subarray sum, easy to think: O(n^6), mind blowing accSum: O(n^5); both pass very easily though)

## Digit DP
* #### Problems
  * [Enigma](https://www.urionlinejudge.com.br/judge/en/problems/view/2699) (Pure + mod of bigInteger)


# Search
* #### Problems
  * [12192 - Grapevine](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3344) (Interesting lowerBound + upperBound)


# Math
* #### Problems
  * [Jumping Frog](https://www.urionlinejudge.com.br/judge/pt/problems/view/2704) (GCD, it's a very brilliant problem)
