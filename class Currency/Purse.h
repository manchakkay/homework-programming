#include <fstream>
#include <string>
#include "Currency.h"

class Purse
{
public:
    Purse();

    //Изменение суммы cur: USD/EUR/GBP amount: -XXX(вычесть) | +XXX(добавить)
    void transfer(std::string cur, double amount);
    
    //Вывод всех операций
    void history();
    //Вывод общего баланса кошелька
    void current();

    //Смена курса cur: USD/EUR/GBP/RUB
    void rate_change(std::string cur, double CUR_EUR);
    //Вывод курса cur: USD/EUR/GBP/RUB
    double rate_get(std::string cur);

    //Вывод баланса в валюте cur: USD/EUR/GBP
    double amount_currency(std::string cur);
    //Вывод баланса в рублях cur: USD/EUR/GBP
    double amount_rubles(std::string cur);

    //Создать файл для сохранения истории
    void history_create();
    //Добавить в историю информацию об операции
    void history_add(std::string operation);

private:

    Dollar USD = 1.1224;
    Euro EUR = 1;
    Pound GBP = 0.90120;

    std::ofstream history_stream;
    std::string history_file = "Purse_history.txt";
};