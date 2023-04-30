#include <fstream>
#include <string>


class Time
{
	std::string time; // в формате часы:минуты:секунды или только секунды
public:
	Time() : time("00:00:00") {};
	Time(const Time&); // используется в методе time_format
	Time(std::string); // используется в методе time_format
	// деструктор не нужен
	Time& operator=(Time); // 1
	Time operator+(Time); // 2
	Time operator-(Time); // 3
	Time time_format(char); // 4
	int to_seconds(); // 5
	bool operator>(Time); // 6
	bool operator<(Time); // 6
	bool operator>=(Time); // 6
	bool operator<=(Time); // 6
	bool operator==(Time); // 6
	bool operator!=(Time); // 6

	friend std::ostream& operator<<(std::ostream&, Time);
	friend std::istream& operator>>(std::istream&, Time&);
};

Time::Time(const Time& to_copy)
{
	time = to_copy.time;
}

Time::Time(std::string input_time)
{
	if (input_time.size() == 8 || input_time.size() <= 5 || input_time.size() == 11)
		time = input_time;
	else
		time = "00:00:00";
}
Time& Time::operator=(Time to_assign)
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
			std::string new_time = time;
			new_time.resize(11, '0');
			int hours = stoi(time);
			if (hours > 9 && hours <= 12)
			{
				new_time.replace(0, 2, std::to_string(hours));
				new_time[9] = 'A';
				new_time[10] = 'M';
			}
			else if (hours > 12)
			{
				hours -= 12;
				if (hours > 9)
					new_time.replace(0, 2, std::to_string(hours));
				else
					new_time.replace(1, 1, std::to_string(hours));
				new_time[9] = 'P';
				new_time[10] = 'M';
			}
			else if (hours == 0)
			{
				hours = 12;
				new_time.replace(0, 2, std::to_string(hours));
				new_time[9] = 'P';
				new_time[10] = 'M';
			}
			else if (hours > 0 && hours < 10)
			{
				new_time.replace(1, 1, std::to_string(hours));
				new_time[9] = 'A';
				new_time[10] = 'M';
			}
			new_time[8] = ' ';
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
	else if (time.size() == 11 && (type == 'n' || type == 'a' || type == 's'))
	{
		if (type == 'a')
		{
			Time other_format(time);
			return other_format;
		}
		if (type == 'n')
		{
			std::string new_time = time;
			new_time.resize(8, '0');
			int hours = stoi(time);
			if (hours > 9)
				new_time.replace(0, 2, std::to_string(hours));
			else
				new_time.replace(1, 1, std::to_string(hours));
			Time other_format(new_time);
			return other_format;
		}
		if (type == 's')
		{
			std::string new_time;
			int hours = stoi(time);
			if (time[9] == 'P')
				hours += 12;
			if (hours == 24)
				hours = 0;
			int minutes = stoi(time.substr(3, 2));
			int seconds = stoi(time.substr(6, 2));
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
			new_time.resize(11, '0');
			if (hours > 9 && hours <= 12)
			{
				new_time.replace(0, 2, std::to_string(hours));
				new_time[9] = 'A';
				new_time[10] = 'M';
				new_time[2] = ':';
			}
			else if (hours > 12)
			{
				hours -= 12;
				if (hours > 9)
					new_time.replace(0, 2, std::to_string(hours));
				else
					new_time.replace(1, 1, std::to_string(hours));
				new_time[9] = 'P';
				new_time[10] = 'M';
				new_time[2] = ':';
			}
			else if (hours == 0)
			{
				hours = 12;
				new_time.replace(0, 2, std::to_string(hours));
				new_time[9] = 'P';
				new_time[10] = 'M';
				new_time[2] = ':';
			}
			else if (hours > 0 && hours < 10)
			{
				new_time.replace(1, 1, std::to_string(hours));
				new_time[9] = 'A';
				new_time[10] = 'M';
				new_time[2] = ':';
			}
			if (minutes > 9)
				new_time.replace(3, 2, std::to_string(minutes));
			else
				new_time.replace(4, 1, std::to_string(minutes));
			new_time[5] = ':';
			if (seconds > 9)
				new_time.replace(6, 2, std::to_string(seconds));
			else
				new_time.replace(7, 1, std::to_string(seconds));
			new_time[8] = ' ';
		}
		Time other_format(new_time);
		return other_format;
	}
	Time other_format;
	return other_format;
}

int Time::to_seconds()
{
	int result;
	return result = stoi(this->time_format('s').time);
}

bool Time::operator>(Time to_compare)
{
	return this->to_seconds() > to_compare.to_seconds();
}

bool Time::operator<(Time to_compare)
{
	return this->to_seconds() < to_compare.to_seconds();
}

bool Time::operator>=(Time to_compare)
{
	return this->to_seconds() >= to_compare.to_seconds();
}

bool Time::operator<=(Time to_compare)
{
	return this->to_seconds() <= to_compare.to_seconds();
}

bool Time::operator==(Time to_compare)
{
	return this->to_seconds() == to_compare.to_seconds();
}

bool Time::operator!=(Time to_compare)
{
	return this->to_seconds() != to_compare.to_seconds();
}

Time Time::operator+(Time to_plus)
{
	int result = stoi(to_plus.time_format('s').time) + stoi(this->time_format('s').time);
	if (result > 86400)
		result -= 86400;
	Time result_time(std::to_string(result));
	return result_time;
}

Time Time::operator-(Time to_minus)
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
	Time first;
	Time second;
	Time third;
	std::ifstream file_input("input.txt");
	std::ofstream file_output("output.txt");
	int key;
	file_input >> key;
	switch (key)
	{
	case 1:
		file_input >> first;
		file_input >> second;
		first = second;
		file_output << first;
		break;
	case 2:
		file_input >> first;
		file_input >> second;
		third = first + second;
		file_output << third.time_format('n') << '\n';
		file_output << third.time_format('s') << '\n';
		file_output << third.time_format('a') << '\n';
		break;
	case 3:
		file_input >> first;
		file_input >> second;
		third = first - second;
		file_output << third.time_format('n') << '\n';
		file_output << third.time_format('s') << '\n';
		file_output << third.time_format('a') << '\n';
		break;
	case 4:
		file_input >> first;
		file_output << first.time_format('n') << '\n';
		file_output << first.time_format('s') << '\n';
		file_output << first.time_format('a') << '\n';
		break;
	case 5:
		file_input >> first;
		file_output << first.to_seconds();
		break;
	case 6:
		file_input >> first;
		file_input >> second;
		file_input >> third;
		file_output << "First > second " << (first > second) << '\n';
		file_output << "First < third " << (first < third) << '\n';
		file_output << "Second >= third " << (second >= third) << '\n';
		file_output << "Second == third " << (second == third) << '\n';
		file_output << "Second <= third " << (second <= third) << '\n';
		file_output << "First != second " << (first != second) << '\n';
		break;
	}
	return 0;
}
