#include<iostream>
#include<cstring>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int TellApplePrice()
    {
        return APPLE_PRICE;
    }
    void ShowSalesResult()
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl;
    }
    int SaleApples(int money)
    {
    	int num = money/APPLE_PRICE;
    	
		numOfApples -= num;
    	myMoney+= money;
    	
    	return num;
	}
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void ShowBuyResult()
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl;
    }
    void BuyApples(FruitSeller& seller, int num)
    {
    	int price = seller.TellApplePrice();
    	int pay = price * num;
    	numOfApples += seller.SaleApples(pay);
    	myMoney -= pay;
    	
	}
};

int main(void)
{
	FruitSeller seller;
	FruitBuyer me;
	seller.InitMembers(1000, 20, 0);
	me.InitMembers(5000);
	
	me.BuyApples(seller, 2);
	cout<< "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout<< "과일 구매자의 현황" << endl;
	me.ShowBuyResult();
	
	return 0;
}


