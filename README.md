# Conference_Class
백준 1931번 회의실 배정 문제 풀이입니다.


# 알고리즘
* vector를 이용해 동적으로 메모리를 할당한다.
* 회의가 끝나는 시간 기준으로 벡터를 정렬한다.
* 끝나는 시간이 같은 회의들은 시작시간으로 다시 정렬한다.
* 끝나는 시간이상으로 시작시간인 회의에 대해 다시 반복한다.



## 외부 함수 및 변수
```c++
bool cmp_start(vector<int>a, vector<int>b){return a.at(0) < b.at(0);}
bool cmp_end(vector<int>a, vector<int>b){return a.at(1) < b.at(1);}
int result=0;
```
* sort에 필요한 비교함수이다.
* 결과값을 저장하는 전역변수이다.

##  데이터 입력
```c++
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
```
2차원 벡터로 메모리를 아끼며 데이터를 받는다.

## 구현
```c++
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
```
* 먼저 회의가 끝나는시간 기준으로 벡터 전체를 정렬한다.
* 전의 회의가 끝난 시간을 now_start에 저장해 시작시간과 비교한다.
* 회의의 끝나는 시간이 같은 회의들은 시작시간 순으로 정렬한다.
* 회의가 끝나는 시간을 시작시간으로 초기화하고 result++ 해준다.

## 어려웠던 점
처음 알고리즘 짤 때가 제일 어려웠다. history를 보면 O(n^2)의 시간복잡도로 짰기 때문에 10만개의 회의시간들을 계산하기에 시간소모가 너무커서 시간초과가 났다. 그래서 O(nlogn)의 새로운 알고리즘을 짜야했다.
