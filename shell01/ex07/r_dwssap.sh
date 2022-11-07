cat /etc/passwd | grep -v "^#" | sed -n 'p;n' | sort -r | sed "s/:.*//" | rev | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr '\n' "," | sed "s/,/, /g" | sed 's/, $/./' | tr -d '\n'
