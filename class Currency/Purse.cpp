#include <iostream>
#include <iomanip>
#include <ctime>
#include "Purse.h"

//конструктор кошелька
Purse::Purse()
{
    USD.amount = 0;
    EUR.amount = 0;
    GBP.amount = 0;

    history_create();
}

//вывод баланса в валюте
double Purse::amount_currency(std::string cur)
{
    if (!cur.compare("EUR"))
    {
        return EUR.get_euro();
    }
    else if (!cur.compare("USD"))
    {
        return USD.get_dollar();
    }
    else if (!cur.compare("GBP"))
    {
        return GBP.get_pound();
    }
    else
    {
        std::cerr << "ERROR! Check currency input (EUR, GBP, USD)";
        exit(-1001);
    }
}

//вывод баланса в рублях
double Purse::amount_rubles(std::string cur)
{
    if (!cur.compare("EUR"))
    {
        return EUR.get_rubles();
    }
    else if (!cur.compare("USD"))
    {
        return USD.get_rubles();
    }
    else if (!cur.compare("GBP"))
    {
        return GBP.get_rubles();
    }
    else
    {
        std::cerr << "ERROR! Check currency input (EUR, GBP, USD)";
        exit(-1001);
    }
}

//смена курса
void Purse::rate_change(std::string cur, double CUR_EUR)
{
    if (!cur.compare("EUR"))
    {
        EUR.CUR_EUR = CUR_EUR;
    }
    else if (!cur.compare("USD"))
    {
        USD.CUR_EUR = CUR_EUR;
    }
    else if (!cur.compare("GBP"))
    {
        GBP.CUR_EUR = CUR_EUR;
    }
    else if (!cur.compare("RUB"))
    {
        EUR.RUB_EUR = CUR_EUR;
        USD.RUB_EUR = CUR_EUR;
        GBP.RUB_EUR = CUR_EUR;
    }
    else
    {
        std::cerr << "ERROR! Check currency input (EUR, GBP, USD, RUB)";
        exit(-1001);
    }
}

//вывод курса
double Purse::rate_get(std::string cur)
{
    if (!cur.compare("EUR"))
    {
        return EUR.CUR_EUR;
    }
    else if (!cur.compare("USD"))
    {
        return USD.CUR_EUR;
    }
    else if (!cur.compare("GBP"))
    {
        return GBP.CUR_EUR;
    }
    else if (!cur.compare("RUB"))
    {
        return EUR.RUB_EUR;
    }
    else
    {
        std::cerr << "ERROR! Check currency input (EUR, GBP, USD, RUB)";
        exit(-1001);
    }
}

//вывод общего баланса кошелька
void Purse::current()
{
    double rub_balance = EUR.get_rubles() + USD.get_rubles() + GBP.get_rubles();
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Overall balance: " << rub_balance << " RUB" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Euro balance: " << EUR.get_euro() << " EUR, " << EUR.get_rubles() << " RUB" << std::endl;
    std::cout << "Dollar balance: " << USD.get_dollar() << " USD, " << USD.get_rubles() << " RUB" << std::endl;
    std::cout << "Pound balance: " << GBP.get_pound() << " GBP, " << GBP.get_rubles() << " RUB" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

//Изменение суммы
void Purse::transfer(std::string cur, double amount)
{
    std::string to_history = "";

    if (!cur.compare("EUR"))
    {
        if ((EUR.get_euro() + amount) < 0)
        {
            std::cerr << "ERROR! The balance cannot be less than zero";
            return;
        }
        else
        {
            EUR.amount += amount;
            if (amount > 0)
            {
                to_history.append("+");
            }
            to_history.append(std::to_string(amount));
            to_history.append(" EUR, Balance: ");
            to_history.append(std::to_string(EUR.amount));
            to_history.append(" EUR");
            history_add(to_history);
        }
    }
    else if (!cur.compare("USD"))
    {
        if ((USD.get_dollar() + amount) < 0)
        {
            std::cerr << "ERROR! The balance cannot be less than zero";
            return;
        }
        else
        {
            USD.amount += amount;
            if (amount > 0)
            {
                to_history.append("+");
            }
            to_history.append(std::to_string(amount));
            to_history.append(" USD, Balance: ");
            to_history.append(std::to_string(USD.amount));
            to_history.append(" USD");
            history_add(to_history);
        }
    }
    else if (!cur.compare("GBP"))
    {
        if ((GBP.get_pound() + amount) < 0)
        {
            std::cerr << "ERROR! The balance cannot be less than zero";
            return;
        }
        else
        {
            GBP.amount += amount;
            if (amount > 0)
            {
                to_history.append("+");
            }
            to_history.append(std::to_string(amount));
            to_history.append(" GBP, Balance: ");
            to_history.append(std::to_string(GBP.amount));
            to_history.append(" GBP");
            history_add(to_history);
        }
    }
    else
    {
        std::cerr << "ERROR! Check currency input (EUR, GBP, USD)";
        exit(-1001);
    }
}

void Purse::history_create()
{
    history_stream.open(history_file, std::ofstream::out | std::ofstream::trunc);

    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    history_stream << "Multicurrency Purse History" << std::endl
                   << "Created at: "
                   << std::setfill('0') << std::setw(4) << (now->tm_year + 1900) << '-'
                   << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '-'
                   << std::setfill('0') << std::setw(2) << now->tm_mday << ' '
                   << std::setfill('0') << std::setw(2) << now->tm_hour << ':'
                   << std::setfill('0') << std::setw(2) << now->tm_min << ':'
                   << std::setfill('0') << std::setw(2) << now->tm_sec << std::endl
                   << "----------------------------------" << std::endl;

    history_stream.close();
}

void Purse::history_add(std::string operation)
{
    history_stream.open(history_file, std::ofstream::out | std::ofstream::app);

    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    history_stream << operation << " - "
                   << std::setfill('0') << std::setw(4) << (now->tm_year + 1900) << '-'
                   << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '-'
                   << std::setfill('0') << std::setw(2) << now->tm_mday << ' '
                   << std::setfill('0') << std::setw(2) << now->tm_hour << ':'
                   << std::setfill('0') << std::setw(2) << now->tm_min << ':'
                   << std::setfill('0') << std::setw(2) << now->tm_sec << std::endl;

    history_stream.close();
}

void Purse::history()
{
    std::string line;
    std::ifstream history_istream(history_file);
    if (history_istream.is_open())
    {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "History:" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        while (std::getline(history_istream, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "----------------------------------" << std::endl;

        history_istream.close();
    } else {
        std::cerr << "ERROR! History file not available";
        exit(-1002);
    }
}