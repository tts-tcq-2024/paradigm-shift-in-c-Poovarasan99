#include <stdio.h>
#include <assert.h>

#define OUTOFBOUNDARY 1

int checkRange(float data, float min, float max)
{
 int output = 0;
 if (data > max || data < min)
 {
  output = 1;
 }
 return output;
}

/*Function to print the error logs*/
void logger(const char* stringToBePrinted)
{
 printf("%s out of range!\n",stringToBePrinted);
}

/*Function to check whether the battery paramter is within the range*/
int boundaryCheck(const char* batteryParameterString, int checkRangeResult)
{
 if(checkRangeResult == OUTOFBOUNDARY)
 {
  logger(batteryParameterString);
  return 1;
 }
 return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
 int functionResult = 1; 
 if(boundaryCheck("Temperature", checkRange(temperature,0,45)) == OUTOFBOUNDARY)
 {
  functionResult = 0;
 }
 else if(boundaryCheck("State of Charge", checkRange(soc,20,80)) == OUTOFBOUNDARY)
 {
  functionResult = 0;
 }
 else
 {
  functionResult = boundaryCheck("Charge Rate",checkRange(chargeRate,0,0.8));
 }
  return functionResult;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
