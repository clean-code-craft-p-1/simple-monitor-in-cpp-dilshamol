#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;

int callSleep()
{
     for (int i = 0; i < 6; i++)
    {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
    return 0;
}

int isTemperatureOk(float temperature)
{
    if(temperature > 102 || temperature <95)
    {
        cout<<"Temperature critical!\n";
        callSleep();
        return 0;
    }
    return 1;

}

int isPulseRateOk(float pulseRate)
{
    if(pulseRate < 60 || pulseRate > 100)
    {
        cout<<"Pulse Rate is out of range!\n";
        callSleep();
        return 0;
    }
    return 1;
}

int isSpo2Ok(float spo2)
{
    if(spo2 < 90)
    {
        cout << "Oxygen Saturation out of range!\n";
        callSleep();
        return 0;
    }
    return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) 
{
     !isTemperatureOk(temperature) || !isPulseRateOk(pulseRate) || !isSpo2Ok(spo2);
}

int main() 
{
  assert(!vitalsOk(99, 102, 70));
  assert(!vitalsOk(90, 80, 100));
  assert(!vitalsOk(105, 80, 100));
  assert(!vitalsOk(96, 70, 85));
  assert(vitalsOk(98.1, 70, 98));
  cout << "Done\n";
}
