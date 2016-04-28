for i in *.cpp; do
		echo "compiling $i"
		g++ -o `basename $i .cpp` `basename $i` -lcurses;
done
