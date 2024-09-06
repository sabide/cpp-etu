set terminal png size 800,600
set output 'lotka_volterra.png'

set title "Population Dynamics (Lotka-Volterra)"
set xlabel "Time"
set ylabel "Population"
set grid

plot "euler_explicit.csv" using 1:2 with lines title 'Proies (Euler Explicite)', \
     "euler_explicit.csv" using 1:3 with lines title 'Prédateurs (Euler Explicite)', \
     "euler_implicit.csv" using 1:2 with lines title 'Proies (Euler Implicite)', \
     "euler_implicit.csv" using 1:3 with lines title 'Prédateurs (Euler Implicite)'
