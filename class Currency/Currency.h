/*
Определите абстрактный класс Сurrency для работы с денежными суммами. 

Определить в нем методы перевода в рубли и вывода на экран. 
На его основе реализуйте классы Dollar, Euro и Pound (фунт стерлингов) 
с возможностью пересчета в центы и пенсы соответственно и указанием текущего курса. 
Создайте класс Purse (кошелек), содержащий массив объектов этих классов в динамической памяти. 
Предусмотрите возможность случайного наполнения кошелька купюрами различного 
типа и подсчета общей суммы кошелька при изменении курса валют. 
В программе продемонстрируйте функциональность разработанных классов. 
Реализуйте метод print печатающий историю пополнения кошелька.
*/

class Currency
{
public:
    //сумма в валюте
    double amount = 0;
    //курс евро к рублю
    double RUB_EUR = 80.2153;
    //курс определённой валюты к евро
    double CUR_EUR = 1;

    //получить валюту в рублях
    double get_rubles();
    //получить валюту в копейках
    double get_kopek();
protected:
    //перевод в рубли
    double to_rubles(double cur_amount);

    //перевод в мелкую валюту
    double to_lower(double high_currency);
    //перевод в крупную валюту
    double to_higher(double low_currency);
};

class Dollar : public Currency
{
public:
    double get_cent();
    double get_dollar();

    Dollar(double EUR_USD);
};

class Euro : public Currency
{
public:
    double get_eurocent();
    double get_euro();

    Euro(double EUR_EUR);
};

class Pound : public Currency
{
public:
    double get_penny();
    double get_pound();

    Pound(double EUR_GBP);
};