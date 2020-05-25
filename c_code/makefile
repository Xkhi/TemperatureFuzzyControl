fuzzyLib = Fuzzy.o FuzzyComposition.o FuzzyIO.o FuzzyInput.o FuzzyOutput.o FuzzyRule.o FuzzyRuleAntecedent.o FuzzyRuleConsequent.o FuzzySet.o

all: 
	$(MAKE) lib
	$(MAKE) examples
	$(MAKE) app
	
lib:
	gcc -c ./eFLL/*.cpp
	gcc -c eFLL/*.cpp

examples: lib
	g++ ./eFLL/examples/general_simple_sample/general_simple_sample.cpp $(fuzzyLib) -o eFLL/examples/general_simple_sample/general_simple_sample.bin -fPIC -O2 -g -Wall
	g++ ./eFLL/examples/general_advanced_sample/general_advanced_sample.cpp $(fuzzyLib) -o eFLL/examples/general_advanced_sample/general_advanced_sample.bin -fPIC -O2 -g -Wall
	
app: lib
	g++ tempControl.cpp $(fuzzyLib) -o tempControl.bin
	
debug: lib
	g++ -ggdb tempControl.cpp $(fuzzyLib) -o tempControl.bin


clean:
	rm -rf *.o *.bin
	rm -f eFLL/*.o eFLL/*.bin