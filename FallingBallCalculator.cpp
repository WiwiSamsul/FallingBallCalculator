#include<iostream>
#include "constants.h"

void printHeight(int time, double current_height)
{
	std::cout << "At " << time << " seconds, the ball is at height : " << current_height << " meters." << std::endl;
}

double update_height(int elapsed_time, double height)
{
	double output{0};
	double distance_fallen{0};
	distance_fallen = constants::earth_gravity*(elapsed_time*elapsed_time)/2;
	
	output = height - distance_fallen;
	return output;
}

int main()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initial_height{0};
	std::cin >> initial_height;
	
	double current_height{initial_height};
	int time{0};
	
	while (current_height >= 0)
	{
		current_height = update_height(time, initial_height);
		if(current_height <= 0)
		{
			std::cout << "At " << time << " seconds, the ball is on the ground." << std::endl;
			return 0;
		}
		printHeight(time, current_height);
		time = time + 1;
	}
	
	
	return 0;
}
