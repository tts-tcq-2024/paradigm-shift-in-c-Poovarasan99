#include <stdio.h>
#include <assert.h>

int checkRange(float data, float min, float max){
 int output = 0;
 if (data > max || data < min)
 {
 output = 1;
 }
 return output;
}

int printLogs(const char* parameter, int checkRangeResult){
 if(checkRangeResult == 1){
  printf("%s out of range \n",parameter);
  return 0;
 }
 return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 int checkRangeResult = 1;
 checkRangeResult = checkRange(temperature,0,45);
  return printLogs("Temperature", checkRangeResult);
 checkRangeResult = checkRange(soc,20,80);
  return printLogs("State of Charge", checkRangeResult);
 checkRangeResult = checkRange(chargeRate,0,0.8);
  return printLogs("Charge Rate",checkRangeResult);
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
