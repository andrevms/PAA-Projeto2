
cmake -S src/ -B out/ && cmake --build out/ --target clean && make -C out 
valgrind --leak-check=no --track-origins=no -s ./out/PAA-Projeto2 src/instancias/v10.txt