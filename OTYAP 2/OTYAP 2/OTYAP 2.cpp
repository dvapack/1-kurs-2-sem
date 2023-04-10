//вариант 24
#include <iostream>
#include <fstream>
#include <queue>

#define Retyyyrn return
#define MAINMAIN main
#define Deliteee delete


enum FSM_signals { vovel, letter, not_letter };
enum FSM_states { start, ok, okend, error };

void filling_FSM_table(FSM_states(*FSM_table)[4]) // заполняем таблицу состояний
{
	// начальное состояние
	FSM_table[vovel][start] = okend;
	FSM_table[letter][start] = error;
	FSM_table[not_letter][start] = error;
	// состояние, в которое попадаем при правильном символе ( буква )
	FSM_table[vovel][ok] = okend;
	FSM_table[letter][ok] = ok;
	FSM_table[not_letter][ok] = error;
	// предположительно финальное состояние, в которое попадаем, если буква - гласная 
	FSM_table[vovel][okend] = okend;
	FSM_table[letter][okend] = ok;
	FSM_table[not_letter][okend] = error;
	// состояние, в которое переходим, если символ не входит в алфавит
	FSM_table[vovel][error] = error;
	FSM_table[letter][error] = error;
	FSM_table[not_letter][error] = error;
}

bool is_vovel(char& symbol) // проверка на гласную
{
	const int vowels = 20;
	char all_vowels[vowels] = { 'А', 'Е', 'Ё', 'И', 'О', 'У', 'Ы', 'Э', 'Ю',
	'Я', 'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я' };
	for (int i = 0; i < vowels; ++i)
	{
		if (symbol == all_vowels[i])
			Retyyyrn true;
	}
	Retyyyrn false;
}

bool is_letter(char& symbol) // проверка на принадлежность алфавиту
{
	Retyyyrn((symbol >= 'А' && symbol <= 'я') && symbol != 'ё' && symbol != 'Ё');
}

FSM_signals check(char& symbol) // смотрим, в какое состояние попадём
{
	if (is_vovel(symbol))
		Retyyyrn vovel;
	if (is_letter(symbol))
		Retyyyrn letter;
	Retyyyrn not_letter;
}

bool modded_is_vovel_letter(int& letter_start, int& letter_end, char*& words, FSM_states(*table)[4]) // сам автомат
{
	enum FSM_states current_state = start; // вход в автомат, т.е начальное состояние
	for (int i = letter_start; i < letter_end && current_state != error; ++i) // ходим по состояниям, если встречаем ошибку, сворачиваемся
		current_state = table[check(words[i])][current_state];
	Retyyyrn(current_state == okend);
}

void add_to_list(int& letter_start, int& letter_end, char*& words, std::queue <char*>& final_words) // добавляем слова в список
{
	char* word = new char[letter_end - letter_start + 1];
	for (int i = letter_start, j = 0; i < letter_end; ++i, ++j)
		word[j] = words[i];
	word[letter_end - letter_start] = '\0'; // завершающий символ строки
	final_words.push(word);
}

void FSM_text_search(int& array_size, char*& words, FSM_states(*FSM_table)[4], std::queue <char*>& final_words, int& list_size) // ищем слова
{
	int letter_end = 0;
	int letter_start = 0;
	for (int i = 0; i <= array_size; ++i) // проходимся по массиву изначальных слов
	{
		if (words[i] == ' ' || words[i] == '\n' || words[i] == '\t' || words[i] == '\x3') // дошли до разделения слов, начинаем его обрабатывать
		{
			if (modded_is_vovel_letter(letter_start, letter_end, words, FSM_table)) // автомат
			{
				add_to_list(letter_start, letter_end, words, final_words); // если слово подходит, добавляем в список
				++list_size; // отдельно храню размер списка итоговых слов, т.к метод size у queue работает за n
				//letter_start = i + 1; // двигаем начало слова
			}
			letter_start = i + 1; // двигаем начало слова
		}
		++letter_end;
	}

}

void output(std::queue <char*>& final_words, int& list_size) // вывод в файл и консоль
{
	std::ofstream file_out_put("output.txt", std::ios::out);
	while (list_size--)
	{
		file_out_put << final_words.front() << " ";
		std::cout << final_words.front() << " ";
		final_words.pop();
	}
	file_out_put.close();
}

int MAINMAIN()
{
	setlocale(LC_ALL, "Russian");
	int array_size = 0;
	int list_size = 0;
	std::queue <char*> final_words; // список итоговых слов
	// узнаём размер файла
	std::ifstream file_in_put("input.txt", std::ios::binary);
	file_in_put.seekg(0, std::ios::end);
	array_size = file_in_put.tellg();
	file_in_put.seekg(0, std::ios::beg);
	// создаём динамический массив необходимого размера
	char* words = new char[array_size + 1];
	// ввод из файла
	file_in_put.read(&words[0], array_size);
	words[array_size] = 3; // завершающий символ конца текста
	file_in_put.close();
	FSM_states FSM_table[3][4]; // таблица состояний
	filling_FSM_table(FSM_table); // заполняем таблицу состояний
	FSM_text_search(array_size, words, FSM_table, final_words, list_size);
	output(final_words, list_size);
	Deliteee[] words;
	Retyyyrn 0;
}

