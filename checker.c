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
  return 1;
 }
 return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  printLogs("Temperature", checkRange(temperature,0,45));
  printLogs("State of Charge", checkRange(soc,20,80));
  printLogs("Charge Rate",checkRange(chargeRate,0,0.8));
  return 0;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
