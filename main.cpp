//
//  main.cpp
//  1931
//
//  Created by dongho on 2020/03/06.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    vector <vector<int> > conf;
    
    //데이터 입력
    int a, b;
    for(int i=0; i<num; i++){
        conf.push_back(vector<int>());
        cin >> a >> b;
        conf.at(i).push_back(a);
        conf.at(i).push_back(b);
    }
    
    //정렬
    sort(conf.at(0).at(0), conf.at(num-1).at(0));
    
    //sort확인
    for(int i=0; i<num; i++){
        cout << conf.at(i).at(0)<<" ";
    }
}
