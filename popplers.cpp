//
// Created by Jakob Ferguson on 4/12/23.
//
#include "randomengine.h"
#include "linkedqueue.h"
#include <iostream>
using namespace std;

int main(){
    struct Customer{
        string name;
        int numPopplers;
        int popEaten;
    };

    randomEngine eng;

    Customer highEater, lowEater;
    int numToServe, temp_numPop, totalPopEaten=0;
    string temp_name;
    cin >> numToServe;
    LinkedQueue<Customer> line;

    for(int i=0;i<numToServe;i++){
        cin >> temp_name >> temp_numPop;
        Customer tempC;
        tempC.popEaten=0;
        tempC.name = temp_name;
        tempC.numPopplers = (temp_numPop/5)*5;
        if((temp_numPop%5)>0){tempC.numPopplers+=5;}
        line.enqueue(tempC);
    }
    /used to trrp first iteration through for inital set up of high and low eater
    bool flag = false; /
    while(!line.isEmpty()){
        Customer temp = line.front();
        bool satisfied=true;
        for(int i=temp.numPopplers;i>0;i--){
            if(eng.rollD(6) == 6){
                satisfied = false;
            }
        }
        totalPopEaten+=temp.numPopplers;
        if(satisfied){
            temp.popEaten += temp.numPopplers;
            cout << temp.name << " eats " << temp.numPopplers << " popplers. " << temp.name << " is satisfied after eating " << temp.popEaten << " popplers." << endl;
            if(!flag){ //check for record eaters, both high and low. Change variables appropriately.
                highEater = temp;
                lowEater = temp;
                flag=true;
            }else{
                if(highEater.popEaten<temp.popEaten){highEater = temp;}
                if(lowEater.popEaten>temp.popEaten){lowEater = temp;}
            }
            line.dequeue();
        }else{
            temp.popEaten += temp.numPopplers;
            cout << temp.name << " eats " << temp.numPopplers << " popplers. " << temp.name << " wants one more poppler!" << endl;
            temp.numPopplers = 5;
            line.enqueue(temp);
            line.dequeue();
        }
        satisfied = true;
    }

    cout << endl << "A total of " << totalPopEaten << " popplers were eaten." << endl;
    cout << highEater.name << " ate the most popplers: " << highEater.popEaten << endl;
    cout << lowEater.name << " ate the fewer popplers: " << lowEater.popEaten;

    return 0;
}