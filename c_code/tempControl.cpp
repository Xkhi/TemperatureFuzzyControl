#include "eFLL/Fuzzy.h"
#include <iostream>
#include <ctime>

using namespace std;

class TempControl{
	private:
		//Declare inputs
		FuzzyInput *tempErr;
		FuzzyInput *tempErrDev;
		//Declare tempErr membership functions
		FuzzySet *tempErrVeryCold;
		FuzzySet *tempErrCold;
		FuzzySet *tempErrMid;
		FuzzySet *tempErrHot;
		FuzzySet *tempErrVeryHot;
		//Declare tempErrDev membership functions
		FuzzySet *tempErrDevNeg;
		FuzzySet *tempErrDevZero;
		FuzzySet *tempErrDevPos;
		
		//Declare outputs
		FuzzyOutput *fan;
		FuzzyOutput *pelt;
		//Declare fan membership functions
		FuzzySet *fanVeryLow;
		FuzzySet *fanLow;
		FuzzySet *fanMid;
		FuzzySet *fanHigh;
		FuzzySet *fanVeryHigh;
		//Declare peltier membership functions
		FuzzySet *peltVeryLow;
		FuzzySet *peltLow;
		FuzzySet *peltMid;
		FuzzySet *peltHigh;
		FuzzySet *peltVeryHigh;
		
		//Declare ruleset antecedents
		FuzzyRuleAntecedent *tempErrVeryColdANDtempErrDevNeg;
		FuzzyRuleAntecedent *tempErrVeryColdANDtempErrDevZero;
		FuzzyRuleAntecedent *tempErrVeryColdANDtempErrDevPos;
		FuzzyRuleAntecedent *tempErrColdANDtempErrDevNeg;
		FuzzyRuleAntecedent *tempErrColdANDtempErrDevZero;
		FuzzyRuleAntecedent *tempErrColdANDtempErrDevPos;
		FuzzyRuleAntecedent *tempErrMidANDtempErrDevNeg;
		FuzzyRuleAntecedent *tempErrMidANDtempErrDevZero;
		FuzzyRuleAntecedent *tempErrMidANDtempErrDevPos;
		FuzzyRuleAntecedent *tempErrHotANDtempErrDevNeg;
		FuzzyRuleAntecedent *tempErrHotANDtempErrDevZero;
		FuzzyRuleAntecedent *tempErrHotANDtempErrDevPos;
		FuzzyRuleAntecedent *tempErrVeryHotANDtempErrDevNeg;
		FuzzyRuleAntecedent *tempErrVeryHotANDtempErrDevZero;
		FuzzyRuleAntecedent *tempErrVeryHotANDtempErrDevPos;
		//Declare ruleset consequent
		FuzzyRuleConsequent *then_fanVLowANDpeltVHigh;
		FuzzyRuleConsequent *then_fanVHighANDpeltVLow;
		FuzzyRuleConsequent *then_fanVLowANDpeltHigh;
		FuzzyRuleConsequent *then_fanLowANDpeltMid;
		FuzzyRuleConsequent *then_fanVLowANDpeltMid;
		FuzzyRuleConsequent *then_fanLowANDpeltLow;
		FuzzyRuleConsequent *then_fanMidANDpeltLow;
		FuzzyRuleConsequent *then_fanMidANDpeltVLow;
		FuzzyRuleConsequent *then_fanHighANDpeltVLow;
		//Declare fuzzy rules containers
		FuzzyRule *fuzzyRule1;
		FuzzyRule *fuzzyRule2;
		FuzzyRule *fuzzyRule3;
		FuzzyRule *fuzzyRule4;
		FuzzyRule *fuzzyRule5;
		FuzzyRule *fuzzyRule6;
		FuzzyRule *fuzzyRule7;
		FuzzyRule *fuzzyRule8;
		FuzzyRule *fuzzyRule9;
		FuzzyRule *fuzzyRule10;
		FuzzyRule *fuzzyRule11;
		FuzzyRule *fuzzyRule12;
		FuzzyRule *fuzzyRule13;
		FuzzyRule *fuzzyRule14;
		FuzzyRule *fuzzyRule15;
		
	public:
		//Declare fuzzy intrinsic system
		Fuzzy *fis;
	
		TempControl(){
			//Declare fuzzy intrinsic system
			this->fis = new Fuzzy();
			//Declare inputs
			this->tempErr = new FuzzyInput(1);
			this->tempErrDev = new FuzzyInput(2);
			//Declare tempErr membership functions
			this->tempErrVeryCold = new FuzzySet(-5, -5, -4, -2);
			this->tempErr->addFuzzySet(tempErrVeryCold);
			this->tempErrCold = new FuzzySet(-4, -2, -2, 0);
			this->tempErr->addFuzzySet(tempErrCold);
			this->tempErrMid = new FuzzySet(-2, 0, 0, 2);
			this->tempErr->addFuzzySet(tempErrMid);
			this->tempErrHot = new FuzzySet(0, 2, 2, 4);
			this->tempErr->addFuzzySet(tempErrHot);
			this->tempErrVeryHot = new FuzzySet(2, 4, 5, 5);
			this->tempErr->addFuzzySet(tempErrVeryHot);
			//Declare tempErrDev membership functions
			this->tempErrDevNeg = new FuzzySet(-2, -2, -1, 0);
			this->tempErrDev->addFuzzySet(tempErrDevNeg);
			this->tempErrDevZero = new FuzzySet(-1, 0, 0, 1);
			this->tempErrDev->addFuzzySet(tempErrDevZero);
			this->tempErrDevPos = new FuzzySet(0, 1, 2, 2);
			this->tempErrDev->addFuzzySet(tempErrDevPos);
			//Add inputs
			this->fis->addFuzzyInput(tempErr);
			this->fis->addFuzzyInput(tempErrDev);
			
			//Declare outputs
			this->fan = new FuzzyOutput(1);
			this->pelt = new FuzzyOutput(2);
			//Declare fan membership functions
			this->fanVeryLow = new FuzzySet(30, 30, 37, 51);
			this->fan->addFuzzySet(fanVeryLow);
			this->fanLow = new FuzzySet(37, 51, 51, 65);
			this->fan->addFuzzySet(fanLow);
			this->fanMid = new FuzzySet(51, 65, 65, 79);
			this->fan->addFuzzySet(fanMid);
			this->fanHigh = new FuzzySet(65, 79, 79, 93);
			this->fan->addFuzzySet(fanHigh);
			this->fanVeryHigh = new FuzzySet(79, 93, 100, 100);
			this->fan->addFuzzySet(fanVeryHigh);
			//Declare peltier membership functions
			this->peltVeryLow = new FuzzySet(0, 0, 10, 30);
			this->pelt->addFuzzySet(peltVeryLow);
			this->peltLow = new FuzzySet(10, 30, 30, 50);
			this->pelt->addFuzzySet(peltLow);
			this->peltMid = new FuzzySet(30, 50, 50, 70);
			this->pelt->addFuzzySet(peltMid);
			this->peltHigh = new FuzzySet(50, 70, 70, 90);
			this->pelt->addFuzzySet(peltHigh);
			this->peltVeryHigh = new FuzzySet(70, 90, 100, 100);
			this->pelt->addFuzzySet(peltVeryHigh);
			//Add outputs
			this->fis->addFuzzyOutput(fan);
			this->fis->addFuzzyOutput(pelt);
			
			//Declare ruleset antecedents
			this->tempErrVeryColdANDtempErrDevNeg = new FuzzyRuleAntecedent();
			this->tempErrVeryColdANDtempErrDevNeg->joinWithAND(tempErrVeryCold, tempErrDevNeg);
			this->tempErrVeryColdANDtempErrDevZero = new FuzzyRuleAntecedent();
			this->tempErrVeryColdANDtempErrDevZero->joinWithAND(tempErrVeryCold, tempErrDevZero);
			this->tempErrVeryColdANDtempErrDevPos = new FuzzyRuleAntecedent();
			this->tempErrVeryColdANDtempErrDevPos->joinWithAND(tempErrVeryCold, tempErrDevPos);
			this->tempErrColdANDtempErrDevNeg = new FuzzyRuleAntecedent();
			this->tempErrColdANDtempErrDevNeg->joinWithAND(tempErrCold, tempErrDevNeg);
			this->tempErrColdANDtempErrDevZero = new FuzzyRuleAntecedent();
			this->tempErrColdANDtempErrDevZero->joinWithAND(tempErrCold, tempErrDevZero);
			this->tempErrColdANDtempErrDevPos = new FuzzyRuleAntecedent();
			this->tempErrColdANDtempErrDevPos->joinWithAND(tempErrCold, tempErrDevPos);
			this->tempErrMidANDtempErrDevNeg = new FuzzyRuleAntecedent();
			this->tempErrMidANDtempErrDevNeg->joinWithAND(tempErrMid, tempErrDevNeg);
			this->tempErrMidANDtempErrDevZero = new FuzzyRuleAntecedent();
			this->tempErrMidANDtempErrDevZero->joinWithAND(tempErrMid, tempErrDevZero);
			this->tempErrMidANDtempErrDevPos = new FuzzyRuleAntecedent();
			this->tempErrMidANDtempErrDevPos->joinWithAND(tempErrMid, tempErrDevPos);
			this->tempErrHotANDtempErrDevNeg = new FuzzyRuleAntecedent();
			this->tempErrHotANDtempErrDevNeg->joinWithAND(tempErrHot, tempErrDevNeg);
			this->tempErrHotANDtempErrDevZero = new FuzzyRuleAntecedent();
			this->tempErrHotANDtempErrDevZero->joinWithAND(tempErrHot, tempErrDevZero);
			this->tempErrHotANDtempErrDevPos = new FuzzyRuleAntecedent();
			this->tempErrHotANDtempErrDevPos->joinWithAND(tempErrHot, tempErrDevPos);
			this->tempErrVeryHotANDtempErrDevNeg = new FuzzyRuleAntecedent();
			this->tempErrVeryHotANDtempErrDevNeg->joinWithAND(tempErrVeryHot, tempErrDevNeg);
			this->tempErrVeryHotANDtempErrDevZero = new FuzzyRuleAntecedent();
			this->tempErrVeryHotANDtempErrDevZero->joinWithAND(tempErrVeryHot, tempErrDevZero);
			this->tempErrVeryHotANDtempErrDevPos = new FuzzyRuleAntecedent();
			this->tempErrVeryHotANDtempErrDevPos->joinWithAND(tempErrVeryHot, tempErrDevPos);
						
			//Declare ruleset consequent
			this->then_fanVLowANDpeltVHigh = new FuzzyRuleConsequent();
			this->then_fanVLowANDpeltVHigh->addOutput(fanVeryLow);
			this->then_fanVLowANDpeltVHigh->addOutput(peltVeryHigh);
			this->then_fanVLowANDpeltHigh = new FuzzyRuleConsequent();
			this->then_fanVLowANDpeltHigh->addOutput(fanVeryLow);
			this->then_fanVLowANDpeltHigh->addOutput(peltHigh);
			this->then_fanVLowANDpeltMid = new FuzzyRuleConsequent();
			this->then_fanVLowANDpeltMid->addOutput(fanVeryLow);
			this->then_fanVLowANDpeltMid->addOutput(peltMid);
			this->then_fanLowANDpeltMid = new FuzzyRuleConsequent();
			this->then_fanLowANDpeltMid->addOutput(fanLow);
			this->then_fanLowANDpeltMid->addOutput(peltMid);
			this->then_fanLowANDpeltLow = new FuzzyRuleConsequent();
			this->then_fanLowANDpeltLow->addOutput(fanLow);
			this->then_fanLowANDpeltLow->addOutput(peltLow);
			this->then_fanMidANDpeltLow = new FuzzyRuleConsequent();
			this->then_fanMidANDpeltLow->addOutput(fanMid);
			this->then_fanMidANDpeltLow->addOutput(peltLow);
			this->then_fanMidANDpeltVLow = new FuzzyRuleConsequent();
			this->then_fanMidANDpeltVLow->addOutput(fanMid);
			this->then_fanMidANDpeltVLow->addOutput(peltVeryLow);
			this->then_fanHighANDpeltVLow = new FuzzyRuleConsequent();
			this->then_fanHighANDpeltVLow->addOutput(fanHigh);
			this->then_fanHighANDpeltVLow->addOutput(peltVeryLow);
			this->then_fanVHighANDpeltVLow = new FuzzyRuleConsequent();
			this->then_fanVHighANDpeltVLow->addOutput(fanVeryHigh);
			this->then_fanVHighANDpeltVLow->addOutput(peltVeryLow);
			
			//Declare fuzzy rules containers
			this->fuzzyRule1 = new FuzzyRule(1, tempErrVeryColdANDtempErrDevNeg, then_fanVLowANDpeltVHigh);
			this->fuzzyRule2 = new FuzzyRule(2, tempErrVeryColdANDtempErrDevZero, then_fanVLowANDpeltVHigh);
			this->fuzzyRule3 = new FuzzyRule(3, tempErrVeryColdANDtempErrDevPos, then_fanVHighANDpeltVLow);
			this->fuzzyRule4 = new FuzzyRule(4, tempErrColdANDtempErrDevNeg, then_fanVLowANDpeltHigh);
			this->fuzzyRule5 = new FuzzyRule(5, tempErrColdANDtempErrDevZero, then_fanLowANDpeltMid);
			this->fuzzyRule6 = new FuzzyRule(6, tempErrColdANDtempErrDevPos, then_fanHighANDpeltVLow);
			this->fuzzyRule7 = new FuzzyRule(7, tempErrMidANDtempErrDevNeg, then_fanVLowANDpeltMid);
			this->fuzzyRule8 = new FuzzyRule(8, tempErrMidANDtempErrDevZero, then_fanLowANDpeltLow);
			this->fuzzyRule9 = new FuzzyRule(9, tempErrMidANDtempErrDevPos, then_fanMidANDpeltLow);
			this->fuzzyRule10 = new FuzzyRule(10, tempErrHotANDtempErrDevNeg, then_fanMidANDpeltLow);
			this->fuzzyRule11 = new FuzzyRule(11, tempErrHotANDtempErrDevZero, then_fanMidANDpeltVLow);
			this->fuzzyRule12 = new FuzzyRule(12, tempErrHotANDtempErrDevPos, then_fanHighANDpeltVLow);
			this->fuzzyRule13 = new FuzzyRule(13, tempErrVeryHotANDtempErrDevNeg, then_fanHighANDpeltVLow);
			this->fuzzyRule14 = new FuzzyRule(14, tempErrVeryHotANDtempErrDevZero, then_fanVHighANDpeltVLow);
			this->fuzzyRule15 = new FuzzyRule(15, tempErrVeryHotANDtempErrDevPos, then_fanVHighANDpeltVLow);
			
			//Add rules to fuzzy system
			this->fis->addFuzzyRule(fuzzyRule1);
			this->fis->addFuzzyRule(fuzzyRule2);
			this->fis->addFuzzyRule(fuzzyRule3);
			this->fis->addFuzzyRule(fuzzyRule4);
			this->fis->addFuzzyRule(fuzzyRule5);
			this->fis->addFuzzyRule(fuzzyRule6);
			this->fis->addFuzzyRule(fuzzyRule7);
			this->fis->addFuzzyRule(fuzzyRule8);
			this->fis->addFuzzyRule(fuzzyRule9);
			this->fis->addFuzzyRule(fuzzyRule10);
			this->fis->addFuzzyRule(fuzzyRule11);
			this->fis->addFuzzyRule(fuzzyRule12);
			this->fis->addFuzzyRule(fuzzyRule13);
			this->fis->addFuzzyRule(fuzzyRule14);
			this->fis->addFuzzyRule(fuzzyRule15);	
		}
		
		float* getControlValues(float tempErr, float tempErrDev){
			float *fout = new float[2];
			this->fis->setInput(1,tempErr);
			this->fis->setInput(2,tempErrDev);
			this->fis->fuzzify();
			fout[0] = this->fis->defuzzify(1);
			fout[1] = this->fis->defuzzify(2);
			return fout;
		}
};

int random(int from, int to)
{
  return (rand() % (to - from)) + from;
}

int main(void){
	TempControl test;
	float input1;
	float input2;
	float *outs;
	for(int i=0; i<10; i++){
		input1 = (random(0, 100)/10.0) - 5.0;
		input2 = (random(0, 100)/25.0) - 2.0;
		std::cout << "Test " << i << std::endl;
		std::cout << "TempErr:\t\t" << input1 << " TempErrDev:\t" << input2 << endl;
		outs = test.getControlValues(input1, input2);
		std::cout << "Fan:\t" << outs[0] << "\tPeltier:\t" << outs[1] << endl;
		
	}
}