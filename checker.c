#include <stdio.h>
#include <assert.h>

int checkRange(float data, float min, float max){
 int output = 0;
 if (data > max || data < min){
 output = 1;
 }
 return output;
}

int CheckParam(float temperature, float soc, float chargeRate){
    float batteryParam[3][3] = {{temperature,0,45}, {soc,20,80}, {chargeRate,0,0.8}};
    int index = 0;
    int checkRangeResult = 0;
    while (index < 4){
     checkRangeResult = checkRange(batteryParam[index][0],batteryParam[index][1],batteryParam[index][2]);
     if (checkRangeResult == 1){
     break;
     }
     index++;
    }
    return index;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 char nameOfParam[3][12] = {"Temperature","State of Charge","Charge Rate"};
 int index = 0;
 index = CheckParam(temperature, soc, chargeRate);
 if (index < 3){
 printf("%s out of range!\n",nameOfParam[index]);
 }
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
