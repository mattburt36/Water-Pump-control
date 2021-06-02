#include <iostream> 
#include <string>
using namespace std; 
// hp = House pump available state
// wp = Well pump state 
// s1 = Sensor 1
// s2 = Sensor 2 

int get_sensor_value(int sensor_id); // prototype for the function for getting sensor value

int main()
{
	int s1 = 0;
	int s2 = 0;
	bool hp_avail = false;
	bool wp_on = false;



	while (1)
	{
		hp_avail = true;
		wp_on = false;
		// Test Top Sensor for water level
		do
		{
			// (get_value_s2)
			s2 = get_sensor_value(2);
		} while (s2 == 1); // if 1 indicates its 'ON')

		// Stay in this state until the bottom switch turns off indicating empty...
		// We now need to wait for the lower sensor to turn OFF (0)
		do
		{
			// (get_value_s1)
			s1 = get_sensor_value(1);
			

		} while (s1 == 1);

		hp_avail = false; // we could possibly allow this but dangerous 
		wp_on = true;
		// Fill the tank until the top sensor indicates its completely full again...
		do
		{
			// (get_value_s2)
			s2 = get_sensor_value(2);
			// (get_value_s1)
			s1 = get_sensor_value(1);
			if (s1 == 1)
			{
				hp_avail = true; // we know the tank is full enough to allow for the house to draw water
			}
			else
			{
				hp_avail = false; // the house drew to much water, disable the house pump
			};

		} while (s2 == 0); // wait until the top sensor indicates full

		return 0;
	}
};

int get_sensor_value(int sensor_id)
{
	// pass it 1 or 2 - ask the user the value and return it
	int sensor_value2;
	int sensor_value1;

	if (sensor_id == 2)
	{
		 cout << "Please enter sensor 2 value." << "\n";

cin >> sensor_value2;

		 if (sensor_value2 == 1)
		 {
			 cout << "The tank is full" "\n";
			 return 1;
		 } 
		 else if (sensor_value2 == 0)
		 {
			 cout << "The tank is not full""\n";
			 return 0;
		 };

	}
	else if (sensor_id == 1)
	{
		cout << "Please enter sensor 1 value.""\n";
		cin >> sensor_value1;

		if (sensor_value1 == 1)
		{
			cout << "The house pump is available to use.""\n";
			cout << "The well pump is on.""\n";
			return 1;
		}
		else if (sensor_value1 == 0)
		{
			cout << "The tank is empty.""\n";
			cout << "House pump is unavailable.""\n";
			cout << "Well pump is turned on.""\n";
			return 0;
		};
	};
};
