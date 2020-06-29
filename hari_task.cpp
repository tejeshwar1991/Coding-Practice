#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <thread>
#include <unistd.h>
#include <future>

#define TEST_CODE 0

using namespace std;
using std::chrono::system_clock;

class TemperatureSensor
{
private:
    unsigned int u8_SensorTemperature;
    unsigned int u8_PresentSensorTemperature;
    string s_SensorVersionInfo;
public:
    unsigned int u8_GenerateTemperature(void) ;  // Task to run at 1ms
    unsigned int u8_CurrentTemperature(void);    //  Function provides current temperature
    string s_ProvideSensorInfo(void);     //  Sensor Version number
};

//This has to be made a task that would run at every 1ms.
unsigned int TemperatureSensor:: u8_GenerateTemperature(void)
{
    u8_SensorTemperature = rand() % 110 + 20; //Generates temperature between 20 to 110.
    //cout << u8_SensorTemperature << endl;
    return u8_SensorTemperature;
}

unsigned int TemperatureSensor::u8_CurrentTemperature(void)
{
    u8_PresentSensorTemperature = u8_GenerateTemperature();
    return u8_PresentSensorTemperature;
}

string TemperatureSensor::s_ProvideSensorInfo(void)
{
    s_SensorVersionInfo = "1.1.1.0";
    return s_SensorVersionInfo;
}

//Diagonsis inherts from Sensor class since it has to provide information about temperature and sensor version number
class Diagonsis:public TemperatureSensor
{
private:
    static const int u8_SizeOfArr = 7;
    unsigned int uArrStoreTemperatureValues[u8_SizeOfArr];
    int u8_ArrIndex;
    unsigned int uAverageSensorTemperature;
    string s_DiagonsisVersionInfo;
    string s_SensorVersionInfo;
public:
    Diagonsis();
    void vPeriodicTaskToReadTemperature(void);
    unsigned int u8_AverageTemperature(void);
    string s_SensorDiagonsisVersionInfo(uint8_t);
};

Diagonsis::Diagonsis(void)
{
    u8_ArrIndex = 0;
    uAverageSensorTemperature = 0;
    memset(uArrStoreTemperatureValues,'0',u8_SizeOfArr*sizeof(unsigned int));
};

void Diagonsis::vPeriodicTaskToReadTemperature(void)
{
    uArrStoreTemperatureValues[u8_ArrIndex] = u8_GenerateTemperature();
    cout<<uArrStoreTemperatureValues[u8_ArrIndex]<<endl;
    u8_ArrIndex++;
    u8_ArrIndex = (u8_ArrIndex%u8_SizeOfArr);
}

unsigned int  Diagonsis::u8_AverageTemperature(void)
{
    for(int i=0 ; i<u8_SizeOfArr; i++)
    {
        cout<<i<<uArrStoreTemperatureValues[i] << endl;
        //uAverageSensorTemperature +=  uArrStoreTemperatureValues[i];
    }
    
    uAverageSensorTemperature /= u8_SizeOfArr;
    //cout << uAverageSensorTemperature << endl;
    return uAverageSensorTemperature;
}

string Diagonsis::s_SensorDiagonsisVersionInfo(uint8_t u8_RequestVersionInfo)
{
    if(u8_RequestVersionInfo == 1)
    {
        s_SensorVersionInfo = s_ProvideSensorInfo();
        return s_SensorVersionInfo;
    }
    else if(u8_RequestVersionInfo == 2)
    {
        s_DiagonsisVersionInfo = "0.0.0.1";
        return s_DiagonsisVersionInfo;
    }
    
    return "ERROR - Invalid request";
}


int main()
{
	int count = 0; unsigned int *u_pStoreTemp;
            TemperatureSensor                        CreateSensorObj;
            Diagonsis                                CreateDiagonsisObj;
    
    while(1)
    {        
		thread SensorTask(&TemperatureSensor::u8_GenerateTemperature,CreateSensorObj);
		if (SensorTask.joinable())
			SensorTask.join();
		
		this_thread::sleep_for(chrono::milliseconds(1));
		
		thread DiagonsisTask(&Diagonsis::vPeriodicTaskToReadTemperature,CreateDiagonsisObj);	
		if (DiagonsisTask.joinable())
			DiagonsisTask.join();

		this_thread::sleep_for(chrono::milliseconds(5));
		

		if(count < 7)
		{
			count++;
//			thread DiagonsisTask(&Diagonsis::u8_AverageTemperature,CreateDiagonsisObj);	
//			if (DiagonsisTask.joinable())
//				DiagonsisTask.join();
		
//			this_thread::sleep_for(chrono::seconds(1));
			sleep(1);
		}
		else
		{
			cout<<"I'm here"<<CreateDiagonsisObj.u8_AverageTemperature()<<endl;
			break;
		}
			
    }	
    
#if TEST_CODE
                string ver;
                unsigned int avgtemp;

                TemperatureSensor obj1;
                Diagonsis obj2;

                ver = obj1.s_ProvideSensorInfo();
                cout << "Sensor Version: " << ver << endl;

                ver = obj2.s_ProvideSensorInfo();
                cout << "Sensor Version: " << ver << endl;
                cout << "Diagonsis Version: "<<obj2.s_SensorDiagonsisVersionInfo(2)<<endl;

                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                obj2.vPeriodicTaskToReadTemperature();
                avgtemp = obj2.u8_AverageTemperature();
                cout << "Average Temperature: " << avgtemp << endl;
#endif

    return 0;
}
