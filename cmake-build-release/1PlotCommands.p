set terminal pdf font "cmr"
name = "Hashtable"
series = name.".txt"
filename = name.".png"
title = name

# Set the output to a png file
set terminal png size 1000,1000
set key box
# The file we'll write to
set output filename
set title title
set xlabel "N Elements"
set ylabel "t [ms]"
set xrange [0.0:]

plot series using 1:($2*1000) lt 7 lc 1 smooth csplines title "Line", series using 1:($2*1000):3 title "Input" lc 7 with errorbars
