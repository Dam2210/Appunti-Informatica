emial prof: clementi@mat.uniroma2.it

## Shortest Paths in a Graph

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine1.png]]

## Shortest Path Problem

Input: Weighted connected graph $<G=(V,E),l:E\rightarrow R^+>$; Source $s$ in $V$ (Length $l_e=$ length of edge $e$)
Feasible Solution: Any set of simple paths from $s$ to $t$, for all $t$ in $V$.
Goal: for any $t$ in $V$, minimize the cost of the s-t path.

>cost of path = sum of edge costs in path

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine2.png]]

## Shortest Path Trees

Theorem: For any Input $[<G=(V,E),l:E\rightarrow R^+>; s \ in \ V]$, there always exists an optimal solution that forms a Spanning Tree for $G$.
Proof. Easy consequence of the Principle of Sub-Optimality of Shortest Paths in a graph with positive weights:
"Any sub-path of a shortest path is a shortest path".

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine3.png]]

## Dijkstra's Algorithm

Dijkstra's Algorithm:
- Maintain a set of explored nodes $S$ for which we have determined the shortest distance $d(u)$ from $s$ to $u$.
- Initialize $S=\{s\},d(s)=0$ 
- Repeatedly choose unexplored node $v$ which minimizes

$$\pi(v)=min_{e=(u,v):u\in S} \ d(u)+l_e$$
>$l_e=$ shortest path to some $u$ in explored part, followed by a single edge $(u,v)$ 

Add $v$ to $S$, set $d(v)=\pi(v)$ and store the father of $v(i.e \ u)$ 

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine4.png]]

## Dijkstra's Algorithm: Proof of Correctness

THM 1.
For each node $u\in S, \ d(u)$ is the length of the shortest s-u path.
Base case: $|S|=1$ is trivial
Inductive hypothesis: Assume true for $|S|=k\geq 1$ 
- Let $v$ be next node added to $S$, and let u-v be the chosen edge.
- The shortest s-u path plus $(u, v)$ is an s-v path of lenght $\pi(v)$.
- Consider ani s-v path $P$. We'll see that it's no shorter than $\pi(v)$.
- Let x-y be the first edge in $P$ that leaves $S$, and let P' be the subpath to x.
- P is already too long as soon as it leaves $S$.

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine5.png]]

$$l(P)\geq l(P')+l(x,y)\geq d(x)+l(x,y)\geq \pi(y) \geq \pi(v)$$

## Dijkstra's Algorithm: Property of its execution

Corollary. For any $t=0,...,n$, let $v(t)$ be the t-th node selected by D.'s Algorithm. Then, $v(t)$ is the t-th closest node to the source node $s$.

Proof.
By induction on t (similar to proof of THM 1).
Do as excercise.

## Dijkstra's Algorithm: Implementation

For each unexplored node, explicitly maintain $\pi(v)=min_{e=(u,v):u\in S} \ d(u)+l_e$.
- Next node to explore = node with minimum $\pi(v)$.
- When exploring $v$, for each incident edge $e=(v,w)$, update
	- $\pi(w)=min\{ \pi(w),\pi(v)+l_e\}$. 

Efficient implementation: Maintain a priority queue of unexplored nodes, prioritized by $\pi(v)$.

![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine6.png]]
![[Anni Universitari - Appunti Obsidian/2o anno/Algoritmi e Strutture Dati/MOD II/Immagini - Algoritmi MOD II/immagine7.png]]