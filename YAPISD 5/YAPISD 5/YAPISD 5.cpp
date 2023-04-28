#include <iostream>
#include <string>


class Time
{
	std::string time; // в формате часы:минуты:секунды
public:
	Time() : time("00:00:00") {};
	Time(const Time&);
	Time(std::string);
	//~Time();
	Time& operator+(Time&);
	Time& time_format(char);
};

Time::Time(const Time& to_copy)
{
	time = to_copy.time;
}

Time::Time(std::string input_time)
{
	if (input_time.size() == 8)
		time = input_time;
	else
		if (input_time.size() <= 5)
		{
			int seconds = stoi(input_time);
			int hours = seconds / 1440;
			int minutes = seconds / 60 - hours * 60;
			seconds -= (minutes * 60 + hours * 3600);
			time.resize(8, '0');
			if (hours > 9)
				time.replace(0, 1, std::to_string(hours));
			else
				time.replace(1, 1, std::to_string(hours));
			time[2] = ':';
			if (minutes > 9)
				time.replace(3, 4, std::to_string(minutes));
			else
				time.replace(4, 4, std::to_string(minutes));
			time[5] = ':';
			if (seconds > 9)
				time.replace(6, 7, std::to_string(seconds));
			else
				time.replace(7, 7, std::to_string(seconds));
		}
		else
		{
			time = "00:00:00";
			std::cout << "wrong time format, it'll be initialized by default settings (00:00:00)";
		}
}

Time& Time::time_format(char type) // 'n' for normal time format, 's' for time in seconds, 'a' for time in  am/pm format
{
	if (time.size() == 8 && (type == 'n' || type == 'a'))
	{
		if (type == 'n')
		{
			Time other_format(time);
			return other_format;
		}
		if (type == 'a')
		{
			std::string new_time;
			new_time.resize(4, '0');
			int hours = stoi(time) / 1440;
			if (hours > 9 && hours <= 12)
			{
				new_time.replace(0, 1, std::to_string(hours));
				new_time[2] = 'A';
				new_time[3] = 'M';
			}
			else if (hours > 12)
			{
				hours -= 12;
				new_time.replace(0, 1, std::to_string(hours));
				new_time[2] = 'P';
				new_time[3] = 'M';
			}
			else if (hours == 0)
			{
				hours = 12;
				new_time.replace(0, 1, std::to_string(hours));
				new_time[2] = 'P';
				new_time[3] = 'M';
			}
			else if (hours > 0 && hours < 10)
			{
				new_time.replace(1, 1, std::to_string(hours));
				new_time[2] = 'A';
				new_time[3] = 'M';
			}
			new_time += time;
			new_time.erase(4, 2);
			Time other_format(new_time);
			return other_format;
		}

	}
	else if (time.size() <= 5 && (type == 'n' || type == 'a'))
	{
		int seconds = stoi(time);
		int hours = seconds / 1440;
		int minutes = seconds / 60 - hours * 60;
		seconds -= (minutes * 60 + hours * 3600);
		if (type == 'n')
		{
			time.resize(8, '0');
			if (hours > 9)
				time.replace(0, 1, std::to_string(hours));
			else
				time.replace(1, 1, std::to_string(hours));
			time[2] = ':';
			if (minutes > 9)
				time.replace(3, 4, std::to_string(minutes));
			else
				time.replace(4, 4, std::to_string(minutes));
			time[5] = ':';
			if (seconds > 9)
				time.replace(6, 7, std::to_string(seconds));
			else
				time.replace(7, 7, std::to_string(seconds));
		}
		if (type == 'a')
		{
			time.resize(10, '0');
			if (hours > 9 && hours <= 12)
			{
				time.replace(0, 1, std::to_string(hours));
				time[2] = 'A';
				time[3] = 'M';
				time[4] = ':';
			}
			else if (hours > 12)
			{
				hours -= 12;
				time.replace(0, 1, std::to_string(hours));
				time[2] = 'P';
				time[3] = 'M';
				time[4] = ':';
			}
			else if (hours == 0)
			{
				hours = 12;
				time.replace(0, 1, std::to_string(hours));
				time[2] = 'P';
				time[3] = 'M';
				time[4] = ':';
			}
			else if (hours > 0 && hours < 10)
			{
				time.replace(1, 1, std::to_string(hours));
				time[2] = 'A';
				time[3] = 'M';
				time[4] = ':';
			}
			if (minutes > 9)
				time.replace(5, 6, std::to_string(minutes));
			else
				time.replace(6, 6, std::to_string(minutes));
			time[7] = ':';
			if (seconds > 9)
				time.replace(8, 9, std::to_string(seconds));
			else
				time.replace(9, 9, std::to_string(seconds));
		}
	}
}
//
//Time& Time::operator+(Time& to_plus)
//{
//	if (this->time.size() == 8)
//	{
//
//	}
//	else
//		if (this->time.size() == 5)
//		{
//
//		}
//		//else
//			//if (this->time.size() == 10)
//}

int main()
{
	std::string time = "33:44:23";
	std::string new_time = "12PM";
	new_time += time;
	new_time.erase(4, 2);
	std::cout << new_time << " " << time;
}

