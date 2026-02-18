#include <iostream>
#include "./zepto.hpp"
#include "./order/user.hpp"
#include "./manager/ordermanager.hpp"
using namespace std;

int main()
{
    Zeptorchestra ::initilization();

    User *user = new User("nisha", 0, 0);

    cout << "user with username " << user->getName() << "came on plateform" << endl;
    Zeptorchestra ::viewAllItems(user);

    Cart *cart = user->getCart();
    cart->addToCart(101, 2);
    cart->addToCart(102, 3);
    cart->addToCart(103, 4);

    cart->getTotal();

    OrderManager *ordermanager = OrderManager::getOrdermanagerinstance();

    ordermanager->placeOrder(user, cart);


    delete user;
}