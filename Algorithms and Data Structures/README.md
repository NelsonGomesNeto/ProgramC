# Flow and Matching :heart:
## Max Flow, Maximum Matching :heart:
* #### Dinic's algorithm is enough for every problem I've tested. NEVER change the algorithm, there's always a way to model in a way that it will magically work :smiley:
* #### Problems
  * [Fast Flow](https://www.spoj.com/problems/FASTFLOW/) (Heavy optimization needed)
  * [Matching](https://www.spoj.com/problems/MATCHING/) (Heavy optimization needed)
  * [Attacking Rooks](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=602&page=show_problem&problem=4406) (Modeling is pretty incredible)
  * [Martian Volei](https://thehuxley.com/problem/643) (Modeling is beautiful and a bit simple)
  * [UVA Problem Package](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=685)

## Min Cost Flow :heart:
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


# Segment Tree :heart:
## Segment Tree without Lazy Propagation :heart:
* #### Problems
  * MISSING PROBLEMS, FILL IT PLEASE :)

## Segment Tree with Lazy Propagation :heart:
* #### Problems
  * [Light Switching](https://www.spoj.com/problems/LITE/) (Pure Segment Tree)
  * [11402 - Ahoy Pirates](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397) (Set update, be careful)
  * [Acordes Intergaláticos](https://www.urionlinejudge.com.br/judge/en/problems/view/2658) (Time is very short, be careful with constants)


# LCA
* #### Problems
  * [Lowest Common Ancestor](https://www.spoj.com/problems/LCA/) (Pure LCA, no tricks)
  * [Match Match](http://www.codcad.com/problem/147) (Pure LCA, but queries for distance)
  * [Ants Colony](http://www.codcad.com/problem/160) (Same as above, but edges have distance)
  * [10938 - Flea Circus](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1879) (Pretty mind blowing, but very good to practice)


# Graph
* #### Problems
  * [Shipping](https://thehuxley.com/problem/1997) (Very pure Dijkstra)
  * [Zak Galou](https://www.urionlinejudge.com.br/judge/pt/problems/view/1409) (Coin change DP + Dijkstra)
  * [Galactic Taxes](https://www.urionlinejudge.com.br/judge/pt/problems/view/2011) (Ternary Search + Dijkstra)


# DP
* #### Problems
  * [10755 - Garbage Heap](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696) (Maximum subarray sum, easy to think: O(n^6), mind blowing accSum: O(n^5); both pass very easily though)


# Search
* #### Problems
  * [12192 - Grapevine](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3344) (Interesting lowerBound + upperBound)
