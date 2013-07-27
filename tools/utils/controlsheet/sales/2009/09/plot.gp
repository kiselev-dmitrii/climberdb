set terminal svg
set output "graph.svg"
set encoding koi8r
set xlabel "Days"
set ylabel "Clothes"
set yrange[0:50]
set xrange[0:31]
set style line 1 lt 1 pt 0
plot "plot.data" using 2 title "Statistic" with linespoints linestyle 1