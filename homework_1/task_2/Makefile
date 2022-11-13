rules: rule_1 rule_2
rule_1: 
	c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o
rule_2:
	c++ -std=c++17 build/main.o -L results/lib/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic