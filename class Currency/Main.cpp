#include <iostream>
#include "Purse.h"

using namespace std;

int main(){

    Purse my_wallet;

    my_wallet.current();
    my_wallet.rate_change("RUB", 80);
    my_wallet.transfer("USD", +100);
    my_wallet.transfer("USD", -39);
    my_wallet.transfer("USD", +800);
    my_wallet.transfer("EUR", +10);
    my_wallet.transfer("GBP", +100);
    my_wallet.transfer("GBP", -10);
    my_wallet.history();
    my_wallet.current();

    return 0;
}