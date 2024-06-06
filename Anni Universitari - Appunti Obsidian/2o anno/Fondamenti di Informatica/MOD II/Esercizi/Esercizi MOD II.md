## ES1. Stringa palindroma (1 o 0)

$\Sigma = \{a, \ b,\}$ 

Stati:

$$
\begin{aligned} 
	& \langle q_0, \ \square, \ \square, \ q_{pal}, \ fermo \rangle \\
    & \langle q_0, \ a, \ \square, \ q_a, \ destra \rangle, \\
    & \langle q_0, \ b, \ \square, \ q_b, \ destra \rangle, \\
    & \\
    & \langle q_a, \ a, \ a, \ q_a, \ destra \rangle, \\
	& \langle q_a, \ b, \ b, \ q_a, \ destra \rangle, \\
	& \langle q_a, \ \square, \ \square, \ q_{as}, \ sinistra \rangle, \\
	& \\
	& \langle q_{as}, \ a, \ \square, \ q_{ind}, \ sinistra \rangle, \\
	& \langle q_{as}, \ b, \ b, \ q_{nopal}, \ fermo \rangle, \\
	& \langle q_{as}, \ \square, \ \square, \ q_{pal}, \ fermo \rangle, \\
	& \\
    & \langle q_b, \ a, \ a, \ q_b, \ destra \rangle, \\
	& \langle q_b, \ b, \ b, \ q_b, \ destra \rangle, \\
	& \langle q_b, \ \square, \ \square, \ q_{bs}, \ sinistra \rangle, \\
	& \\
	& \langle q_{bs}, \ b, \ \square, \ q_{ind}, \ sinistra \rangle, \\
	& \langle q_{bs}, \ a, \ a, \ q_{nopal}, \ fermo \rangle, \\
	& \langle q_{bs}, \ \square, \ \square, \ q_{pal}, \ fermo \rangle, \\
	& \\
	& \langle q_{ind}, \ a, \ a, \ q_{ind}, \ sinistra \rangle, \\
	& \langle q_{ind}, \ b, \ b, \ q_{ind}, \ sinistra \rangle, \\
	& \langle q_{ind}, \ \square, \ \square, \ q_0, \ destra \rangle, \\
\end{aligned}
$$


## Es2. Ricevendo in input k parole conta 

