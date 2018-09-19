import sys
import os
import time
from filecmp import cmp

def compileCode(solver):
    extension = solver.split('.')
    extension = extension[len(extension) - 1]
    if (extension == "cpp"):
        os.system("g++ \"%s\" -o test -std=c++14 -O2" % solver)
    elif (extension == "c"):
        os.system("gcc \"%s\" -o test -O2" % solver)

solver, testCasesPath, timeLimit = sys.argv[1:]
timeLimit = float(timeLimit)
compileCode(solver)
print("Compiled Code", solver)
inputPath, outputPath = testCasesPath + "/input/", testCasesPath + "/output/"
testCases = os.listdir(inputPath)
<<<<<<< HEAD
for test in sorted(testCases, key=lambda x: int(x.split('_')[1])):
    startTime = time.time()
    os.system("./test < \"%s\" > auxOut" % (inputPath + test))
    executionTime = time.time() - startTime
    print(test.split("_")[1], "- Verdict:", "Accpected" if cmp("auxOut", outputPath + test) and executionTime <= timeLimit else "Wrong Answer" if executionTime <= timeLimit else "Time Limit Exceeded")
=======
for test in testCases:
    startTime = time.time()
    os.system("./test < \"%s\" > auxOut" % (inputPath + test))
    executionTime = time.time() - startTime
    print("Verdict:", "Accpected" if cmp("auxOut", outputPath + test) and executionTime <= timeLimit else "Wrong Answer" if executionTime <= timeLimit else "Time Limit Exceeded")
>>>>>>> 56eb7b497b6b3122088c1ce44e156402209ef6fa
