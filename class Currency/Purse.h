#include <fstream>
#include <string>
#include "Currency.h"

class Purse
{
public:
    Purse();

    
    void transfer(std::string cur, double amount);
    
    
    void history();
    
    void current();

    
    void rate_change(std::string cur, double CUR_EUR);
    
    double rate_get(std::string cur);

    
    double amount_currency(std::string cur);
    
    double amount_rubles(std::string cur);

    
    void history_create();
    
    void history_add(std::string operation);

private:

    Dollar USD = 1.1224;
    Euro EUR = 1;
    Pound GBP = 0.90120;

    std::ofstream history_stream;
    std::string history_file = "Purse_history.txt";
};