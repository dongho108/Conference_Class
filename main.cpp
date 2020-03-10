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

bool cmp_start(vector<int>a, vector<int>b){return a.at(0) < b.at(0);}
bool cmp_next(vector<int>a, vector<int>b){return a.at(2) > b.at(2);}

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
        conf.at(i).push_back(1);
    }
    
    //정렬
    sort(conf.begin(), conf.end(), cmp_start);
    
    int maxIndex = num-1;
    int temp = conf.at(maxIndex).at(0); // 마지막 강의의 시작시간
    while(conf.at(maxIndex).at(0) == temp){maxIndex--;}
    
    for(int i=maxIndex; i>=0; i--){
        //늦게시작하는 강의찾기
        int late=conf.at(i).at(1);
        int lateIndex=0;
        while(late >= conf.at(lateIndex).at(0)){
            lateIndex++;
            if(lateIndex == num){
                lateIndex = 10;
                break;
            }
                
        }
        int next=conf.at(lateIndex).at(2);
        while(lateIndex <= (num-1)){
            if(next < conf.at(lateIndex).at(2))
                next = conf.at(lateIndex).at(2);
            lateIndex++;
        }
        conf.at(i).at(2) = next + 1;
    }
    sort(conf.begin(), conf.end(), cmp_next);
    cout << conf.at(0).at(2);
}
