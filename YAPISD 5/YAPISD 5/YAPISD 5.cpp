#include <iostream>
#include <string>


class Time
{
	std::string time; // в формате часы:минуты:секунды или только секунды
public:
	Time() : time("00:00:00") {};
	Time(const Time&);
	Time(std::string);
	//~Time();
	Time& operator=(Time&);
	Time operator+(Time&);	
	Time operator-(Time&);
	Time time_format(char);
	int to_seconds();
	bool operator>(Time&);
	bool operator<(Time&);
	bool operator>=(Time&);
	bool operator<=(Time&);
	bool operator==(Time&);
	bool operator!=(Time&);

	friend std::ostream& operator<<(std::ostream&, Time);
	friend std::istream& operator>>(std::istream&, Time&);
};

Time::Time(const Time& to_copy)
{
	time = to_copy.time;
}

Time::Time(std::string input_time)
{
	if (input_time.size() == 8 || input_time.size() <= 5 || input_time.size() == 10)
		time = input_time;
	else
	{
		time = "00:00:00";
		std::cout << "wrong time format, it'll be initialized by default settings (00:00:00)";
	}
}
Time& Time::operator=(Time& to_assign)
{
	time = to_assign.time;
	return *this;
}

Time Time::time_format(const char type) // 'n' for normal time format, 's' for time in seconds, 'a' for time in  am/pm format
{
	if (time.size() == 8 && (type == 'n' || type == 'a' || type == 's'))
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
				new_time.replace(0, 2, std::to_string(hours));
				new_time[2] = 'A';
				new_time[3] = 'M';
			}
			else if (hours > 12)
			{
				hours -= 12;
				new_time.replace(0, 2, std::to_string(hours));
				new_time[2] = 'P';
				new_time[3] = 'M';
			}
			else if (hours == 0)
			{
				hours = 12;
				new_time.replace(0, 2, std::to_string(hours));
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
		if (type == 's')
		{
			std::string new_time;
			int hours = stoi(time);
			int minutes = stoi(time.substr(3, 2));
			int seconds = stoi(time.substr(6, 2));
			seconds = seconds + minutes * 60 + hours * 3600;
			new_time = std::to_string(seconds);
			Time other_format(new_time);
			return other_format;
		}
	}
	else if (time.size() == 10 && (type == 'n' || type == 'a' || type == 's'))
	{
		if (type == 'a')
		{
			Time other_format(time);
			return other_format;
		}
		if (type == 'n')
		{
			std::string new_time;
			new_time.resize(2, '0');
			int hours = stoi(time) / 1440;
			if (hours > 9)
				new_time.replace(0, 2, std::to_string(hours));
			else
				new_time.replace(1, 1, std::to_string(hours));
			new_time += time;
			new_time.erase(2, 4);
			Time other_format(new_time);
			return other_format;
		}
		if (type == 's')
		{
			std::string new_time;
			int hours = stoi(time);
			if (time[3] == 'P')
				hours += 12;
			if (hours == 24)
				hours = 0;
			int minutes = stoi(time.substr(5, 2));
			int seconds = stoi(time.substr(8, 2));
			seconds = seconds + minutes * 60 + hours * 3600;
			new_time = std::to_string(seconds);
			Time other_format(new_time);
			return other_format;
		}
	}
	else if (time.size() <= 5 && (type == 'n' || type == 'a' || type == 's'))
	{
		if (type == 's')
		{
			Time other_format(time);
			return other_format;
		}
		std::string new_time;
		int seconds = stoi(time);
		int hours = seconds / 3600;
		int minutes = seconds / 60 - hours * 60;
		seconds -= (minutes * 60 + hours * 3600);
		if (type == 'n')
		{
			new_time.resize(8, '0');
			if (hours > 9)
				new_time.replace(0, 2, std::to_string(hours));
			else
				new_time.replace(1, 1, std::to_string(hours));
			new_time[2] = ':';
			if (minutes > 9)
				new_time.replace(3, 2, std::to_string(minutes));
			else
				new_time.replace(4, 1, std::to_string(minutes));
			new_time[5] = ':';
			if (seconds > 9)
				new_time.replace(6, 2, std::to_string(seconds));
			else
				new_time.replace(7, 1, std::to_string(seconds));
		}
		if (type == 'a')
		{
			new_time.resize(10, '0');
			if (hours > 9 && hours <= 12)
			{
				new_time.replace(0, 2, std::to_string(hours));
				new_time[2] = 'A';
				new_time[3] = 'M';
				new_time[4] = ':';
			}
			else if (hours > 12)
			{
				hours -= 12;
				new_time.replace(0, 2, std::to_string(hours));
				new_time[2] = 'P';
				new_time[3] = 'M';
				new_time[4] = ':';
			}
			else if (hours == 0)
			{
				hours = 12;
				new_time.replace(0, 2, std::to_string(hours));
				new_time[2] = 'P';
				new_time[3] = 'M';
				new_time[4] = ':';
			}
			else if (hours > 0 && hours < 10)
			{
				new_time.replace(1, 1, std::to_string(hours));
				new_time[2] = 'A';
				new_time[3] = 'M';
				new_time[4] = ':';
			}
			if (minutes > 9)
				new_time.replace(5, 2, std::to_string(minutes));
			else
				new_time.replace(6, 1, std::to_string(minutes));
			new_time[7] = ':';
			if (seconds > 9)
				new_time.replace(8, 2, std::to_string(seconds));
			else
				new_time.replace(9, 1, std::to_string(seconds));
		}
		Time other_format(new_time);
		return other_format;
	}
}

int Time::to_seconds()
{
	int result;
	return result = stoi(this->time_format('s').time);
}

bool Time::operator>(Time& to_compare)
{
	return this->to_seconds() > to_compare.to_seconds();
}

bool Time::operator<(Time& to_compare)
{
	return this->to_seconds() < to_compare.to_seconds();
}

bool Time::operator>=(Time& to_compare)
{
	return this->to_seconds() >= to_compare.to_seconds();
}

bool Time::operator<=(Time& to_compare)
{
	return this->to_seconds() <= to_compare.to_seconds();
}

bool Time::operator==(Time& to_compare)
{
	return this->to_seconds() == to_compare.to_seconds();
}

bool Time::operator!=(Time& to_compare)
{
	return this->to_seconds() != to_compare.to_seconds();
}

Time Time::operator+(Time& to_plus)
{
	int result = stoi(to_plus.time_format('s').time) + stoi(this->time_format('s').time);
	if (result > 86400)
		result -= 86400;
	Time result_time(std::to_string(result));
	return result_time;
}

Time Time::operator-(Time& to_minus)
{
	int result = stoi(this->time_format('s').time) - stoi(to_minus.time_format('s').time);
	if (result < 0)
		result += 86400;
	Time result_time(std::to_string(result));
	return result_time;
}

std::ostream& operator<<(std::ostream& out, Time time_out)
{
	out << time_out.time << " ";
	return out;
}

std::istream& operator>>(std::istream& in, Time& time_in)
{
	in >> time_in.time;
	return in;
}

int main()
{
	Time current;
	std::cin >> current;
	Time old_time;
	std::cin >> old_time;
	std::cout << (current - old_time).time_format('n');
	/*int key;
	std::cin >> key;*/

}
