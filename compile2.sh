
cmake -S src/ -B out/ && cmake --build out/ --target clean && make -C out
valgrind --leak-check=yes --track-origins=yes -s ./out/PAA-Projeto2 src/instancias/instancia01-10.txt