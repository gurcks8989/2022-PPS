/*
7701. 염라대왕의 이름 정렬 D4

염라대왕은 이승의 사람들의 모든 이름을 가지고 있다.
어느날 저승에 일어난 진도 8.0 지진에 항상 정리되어 있던 이승 명부가 흐트러졌다.
이승 명부는 이름의 길이가 짧을수록 이 앞에 있었고, 같은 길이면 사전 순으로 앞에 있었다.
이왕 이렇게 된 김에 모든 이름을 다시 정리하고 같은 이름은 하나만 남겨놓기로 한 염라대왕을 도와주자.


[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 50)가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 이승 명부의 이름 개수 N(1 ≤ N ≤ 20,000)이 주어진다.
각 테스트 케이스의 두 번째 줄부터 N개의 줄에 걸쳐서 알파벳 소문자로 이루어진 이름들이 주어진다.
이름에는 공백이 포함되지 않으며 최소 1개, 최대 50개의 알파벳으로 이루어져 있다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
정리된 이름을 한 줄에 하나씩 출력하라. 같은 이름은 한 번만 출력해야 하는 것을 주의하라.

입력
2       // 테스트 케이스 개수
5       // 첫 번째 테스트 케이스, N = 5
my
name
is
ho
seok
12      // 두 번째 테스트 케이스, N = 12
s
a
m
s
u
n
g
j
j
a
n
g	
s_input.txt


출력
#1      // 첫 번째 테스트 케이스 결과
ho
is
my
name
seok
#2      // 두 번째 테스트 케이스 결과
a
g
j
m
n
s
u	
*/
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool str_compare(string & a, string & b){
    if(a.length() == b.length())
        return a < b ;
    return a.length() < b.length() ;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num ;
        string temp;
        cin >> num ;
        vector<string> names ;
        for(int i = 0 ; i < num ; i++){
            cin >> temp ;
            names.push_back(temp) ;
        }
        sort(names.begin(), names.end(), str_compare) ;
        
        cout << "#" << test_case << "\n" ;
        cout << names[0] <<"\n" ;
        temp = names[0] ;
        for(int i = 1 ; i < num ; i++){
            if(temp.compare(names[i]) != 0)
       			cout << names[i] <<"\n" ;
            	temp = names[i] ;
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}