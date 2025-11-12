#include <iostream>
#include "Md5Class.h"

using namespace std;

void print_help()
{
	cout << "-f 'file name' - Set file.\n-h - Call the Startup Help.";
}

void Save_Log(string LogText)
{
    ofstream FileLog;

    FileLog.open("C:/IT/LogMD5.txt", ios::app);

    if (FileLog.is_open())
    {
        FileLog << LogText << endl;
        FileLog.close();
    }
    else
    {
        cout << "Не удалось записать логи." << endl;
    }
}

int main(int argc, char* argv[])
{
    try 
    {
        if (argc < 2) 
        {
            print_help();
            Save_Log("Вызов справки(Нет параметров).");
            return 0;
        }

        string arg = argv[1];

        

        if (arg == "-f") 
        {

            if (argc < 3) 
            {
                cerr << "Error.\n";
                Save_Log("Ошибка: Не задан путь файла");
                return 0;
            }

            string filename = argv[2];
            Md5Class calc(filename);

            calc.calculate_md5();

            Save_Log("Md5(" + filename + ") = " + calc.Md5());
        }
        else if (arg == "-h") 
        {
            print_help();
            Save_Log("Вызов справки(-h).");
            return 0;
        }
        else 
        {
            print_help();
            return 0;
        }
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

	return 0;
}