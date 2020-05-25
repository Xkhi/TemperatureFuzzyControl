import sys
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl

class TemperatureControl(object):
    def __init__(self):
        ## Stablish work environment
        ## Inputs
        tempErr = ctrl.Antecedent(np.arange(-5,6,1),'tempErr')
        tempErrDev = ctrl.Antecedent(np.arange(-2,3,1),'tempErrDev')
        ## Output
        fanPow = ctrl.Consequent(np.arange(30,101,1),'fanPow')

        ## Membership functions
        tempMf = ['Cold', 'Mid', 'Hot']
        fanMf = ['VeryLow','Low','Mid','High','VeryHigh']

        tempErr.automf(names = tempMf)
        tempErrDev.automf(names = tempMf)
        fanPow.automf(names = fanMf)

        ## Rules
        ##      | Cold | Mid | Hot <- tempErrDev
        ## Cold |  VL  |  L  |  M 
        ## Mid  |   L  |  M  |  H
        ## Hot  |   M  |  H  |  VH
        ##  ^tempErr
        rule1 = ctrl.Rule(tempErr['Cold'] & tempErrDev['Cold'], fanPow['VeryLow'])
        rule2 = ctrl.Rule(tempErr['Cold'] & tempErrDev['Mid'],  fanPow['Low'])
        rule3 = ctrl.Rule(tempErr['Cold'] & tempErrDev['Hot'],  fanPow['Mid'])

        rule4 = ctrl.Rule(tempErr['Mid']  & tempErrDev['Cold'], fanPow['Low'])
        rule5 = ctrl.Rule(tempErr['Mid']  & tempErrDev['Mid'],  fanPow['Mid'])
        rule6 = ctrl.Rule(tempErr['Mid']  & tempErrDev['Hot'],  fanPow['High'])

        rule7 = ctrl.Rule(tempErr['Hot']  & tempErrDev['Cold'], fanPow['Mid'])
        rule8 = ctrl.Rule(tempErr['Hot']  & tempErrDev['Mid'],  fanPow['High'])
        rule9 = ctrl.Rule(tempErr['Hot']  & tempErrDev['Hot'],  fanPow['VeryHigh'])

        # Define temperature control system
        tempCtrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9])

        # Define simulation
        self.sim = ctrl.ControlSystemSimulation(tempCtrl)

    def compute(self, in1=0, in2=0):
        self.sim.input['tempErr'] = in1
        self.sim.input['tempErrDev'] = in2
        self.sim.compute()
        return self.sim.output['fanPow']
 


if __name__ == '__main__':
    test = TemperatureControl()
    print(test.compute(float(sys.argv[1]), float(sys.argv[2])))
