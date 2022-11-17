rules: directoryBuild libraryArithmetic compileBuild directoryResults libraryResultsLibArithmetic linkMain copyBuild compileResult

directoryBuild :
	mkdir -p build 

libraryArithmetic: buildSubtract buildSum
	ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

buildSubtract: 
	c++ -c  -I./include/ src/subtract.cpp -o build/subtract.o

buildSum:
	c++ -c  -I./include/ src/sum.cpp -o build/sum.o 

compileBuild: 
	c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o

directoryResults: directoryBin directoryLib
	mkdir -p results
directoryBin:
	mkdir -p results/bin
directoryLib:
	mkdir -p results/lib

libraryResultsLibArithmetic:
	ar rcs results/lib/libipb_arithmetic.a build/sum.o build/subtract.o

linkMain:
	c++ -std=c++17 build/main.o -L build/ -lipb_arithmetic -o build/test_ipb_arithmetic

copyBuild:
	cp build/libipb_arithmetic.a results/lib

compileResult:
	c++ -std=c++17 build/main.o -L results/lib/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic

	
