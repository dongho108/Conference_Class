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
bool cmp_end(vector<int>a, vector<int>b){return a.at(1) < b.at(1);}

int result=0;

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
    sort(conf.begin(), conf.end(), cmp_end);
    int now_start=0;
    for(int i=0; i<num; i++){
        if(now_start <= conf[i][0]){
            
            if(i == num-1){
                result++;
                break;
            }
            
            int j = i+1;
            while(conf[i][1] == conf[j][1] && j<num-1){
                j++;
                if(j==num)
                    break;
            }
                
            sort(conf.begin()+i, conf.begin()+j, cmp_start);
            now_start = conf[i][1];
            result++;
        }
    }
    cout << result;
}
