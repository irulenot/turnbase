//
//  main.cpp
//  ExploringSTL
//
//  Created by Ian Wilson on 9/19/15.
//  Copyright (c) 2015 ia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::iterator It;
typedef vector<int>::reverse_iterator RIt;

void vectorEx1();
void vectorEx2();

int main()
{
 //   vectorEx1();
    vectorEx2();
    
    
}

void vectorEx1()
{
    vector<int> v(4);
    for (int i = 0; i<4; i++)
        v[i] = 222*i + 333;
    
    cout << "Using the iterator it in a for loop: \n";
    for(It it=v.begin(); it!=v.end(); it++)         // iterator begin() returns an iterator pointing
        cout << "\t*it=" << *it << "\n";            // to the first element of the vector
    // end() returns the pointer to a dummy that follows the last element
    cout << "Using the iterator p in a while loop: \n";
    
    It p = v.begin();
    while(p != v.end())
        cout << "\t*p++=" << *p++ << "\n";
}

void vectorEx2()
{
    vector<int> v(4);
    for (int i = 0; i<4; i++)
        v[i] = 222*i + 333;
    cout << "Using the reverse iterator rit in a for loop: \n";
    for(RIt rit=v.rbegin(); rit!= v.rend(); rit++)
        cout << "\t*rit=" << *rit << "\n";
    cout << "Using the reverse iterator rp in a while loop: \n";
    RIt rp=v.rbegin();
    while(rp != v.rend())
        cout << "\t*rp++=" << *rp++ << "\n";
    
}