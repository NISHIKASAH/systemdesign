#include <iostream>
#include <vector>
#include <string>
#include "./cart/product.hpp"
#include "./cart/cart.hpp"
#include "./manager/couponmanager.hpp"
#include "./manager/strategymanager.hpp"
#include "./manager/strategytype.hpp"
#include "./strategy/discountstrategy.hpp"
#include "./coupon/bulkcoupon.hpp"
#include "./coupon/loyalitycoupon.hpp"
#include "./coupon/seasonalcoupon.hpp"

using namespace std;

int main()
{
    Product *product1 = new Product("sweater", 12000, "winter");
    Product *product2 = new Product("jacket", 13500, "winter");
    Product *product3 = new Product("cap", 4500, "winter");
    Product *product4 = new Product("shirt", 1405, "summer");
    Product *product5 = new Product("pant", 13400, "summer");
    Product *product6 = new Product("tshirt", 4590, "summer");

    Cart *mycart = new Cart();
    mycart->addProduct(product1, 2);
    mycart->addProduct(product2, 1);
    mycart->addProduct(product3, 2);
    mycart->addProduct(product4, 1);
    mycart->addProduct(product5, 1);
    mycart->addProduct(product6, 4);
    mycart->setLoyality(true);

    cout << "Original Cart Total: " << mycart->getTotal() << " Rs" << endl;
    Coupon *seasonal = new SeasonalCoupon(20, "winter");
    Coupon *loyality= new LoyalityCoupon(4 , 30);
    Coupon *bulk = new BulkCoupon(2 , 55);
    CouponManager *couponmanager = CouponManager::getCouponManagerinstance();

    couponmanager->RegisterCoupon(seasonal);
    couponmanager->RegisterCoupon(loyality);
    couponmanager->RegisterCoupon(bulk);
    int finalTotal = couponmanager->applyAvailableCoupon(mycart);
    cout << "Final Cart Total after discounts: " << finalTotal << " Rs" << endl;
    vector<string> viewallcoupons = couponmanager->showApplycoupon(mycart);
    cout<<"\ncoupon applied size : "<<viewallcoupons.size() <<endl;
    for (string name : viewallcoupons)
    {
        cout << " - " << name << endl;
    }

    delete product1;
    delete product2;
    delete product2;
    delete product3;
    delete product4;
    delete product5;
    delete product6;
    delete mycart;
}