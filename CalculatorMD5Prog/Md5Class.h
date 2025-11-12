#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <openssl/md5.h>
#include <openssl/evp.h>

using namespace std;

/**
 * @brief Класс для вычисления хеш-суммы заданного файла.
 */

class Md5Class
{
private:

	/**
	 * @brief Имя файла, для которого выполняется расчёт MD5.
	 */
	string filename;

	/**
	 * @brief Хранит рассчитанную хеш-сумму в шестнадцатеричном виде.
	 */
	string HashValue;

public:

	/**
	 * @brief Конструктор класса MD5Calculator.
	 * @param FileName Имя файла, для которого требуется рассчитать хеш-сумму.
	 */
	Md5Class(const string& FileName);

	/**
	 * @brief Выполняет расчёт MD5 хеша указанного файла.
	 */
	void calculate_md5();
	
	/**
	 * @brief Возвращает рассчитанную хеш-сумму.
	 * @return Строка, содержащая хеш-сумму в шестнадцатеричном виде.
	 */
	string Md5();
};

