//Quinton Dean
//Lab- 8 Widgets
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

/* This program takes input of a code, quantity, and grams of different parts and adds them together
*/
using namespace std;
float widgets(float, int);
float nuts(float, int);
float bolts(float, int);
float screws(float, int);
float (*ptr)(float, int);     // this can give address of function ptr=&widgets

int main()
{
    typedef map<char,float(*)(float,int)> map;
    map func;
    func['w']=&widgets;
    func['b']=&bolts;
    func['s']=&screws;
    func['n']=&nuts;
    string junk;
    char code;
    int q;
    float g, cost, totalCost;
    fstream orders;
    orders.open("orders.txt");
    if(!orders.is_open())
    {
        cout << "can not find 'orders.txt'";
        return 10;
    }

    getline(orders, junk);
    orders >> code >> q >> g;
    while(!orders.eof())
    {
        ptr=func[code];
        /*if(code=='w')
        {
            ptr=&widgets;
            //cost=widgets(g,q);
            //totalCost=+cost;
        }
        if(code=='s')
        {
            ptr=&screws;
            //cost=screws(g,q);
            //totalCost=+cost;
        }
        if(code=='b')
        {
            ptr=&bolts;
            //cost=screws(g,q);
            //totalCost=+cost;
        }
        if(code=='n')
        {
            ptr=&nuts;
            //cost=screws(g,q);
            //totalCost=+cost;
        }*/
        cost=ptr(g,q);
        totalCost=+cost;
        orders >> code >> q >> g;
    }

    cout << "Total Cost = " << totalCost;
    return 0;

}
float widgets(float grams, int quantity)
{
    float difficulty=1.3;
    float cost=difficulty*grams*quantity*.07;
    return cost;
}
float nuts(float grams, int quantity)
{
    float difficulty=1.5;
    float cost=difficulty*grams*quantity*.07;
    return cost;
}
float bolts(float grams, int quantity)
{
    float difficulty=1.7;
    float cost=difficulty*grams*quantity*.07;
    return cost;
}
float screws(float grams, int quantity)
{
    float difficulty=1.25;
    float cost=difficulty*grams*quantity*.07;
    return cost;
}
