rules: rule_1 rule_2 rule_3 rule_4 rule_5 rule_6 rule_7 rule_8 rule_10 rule_9
rule_1 :
	mkdir -p build 
rule_2:
	c++ -c  -I./include/ src/subtract.cpp -o build/subtract.o
rule_3:
	c++ -c  -I./include/ src/sum.cpp -o build/sum.o
rule_4:
	ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
rule_5: 
	c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o
rule_6:
	mkdir -p results/bin
rule_7:
	mkdir -p results/lib
rule_8:
	ar rcs results/lib/libipb_arithmetic.a build/sum.o build/subtract.o
rule_9:
	c++ -std=c++17 build/main.o -L build/ -lipb_arithmetic -o build/test_ipb_arithmetic
rule_10:
	c++ -std=c++17 build/main.o -L results/lib/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic

	
