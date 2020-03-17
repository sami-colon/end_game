#include <bits/stdc++.h>
using namespace std;

int getDigits(long long n){
  int c=0;
  while(n){
    c++;
    n = n / 3;
  }
  return c;
}

bool isGood(long long n){
  string str = "";
  while(n){
    string x(1,(char)(n%3) + '0');
    str = str + x;
    n = n / 3;
  }
  for(int i=0; i<str.length(); i++){
    if(str[i] - '0' > 1){
      return false;
    }
  }
  return true;
}

long long getAnswer(long long n){
  string str = "";
  while(n){
    string x(1,(char)(n%3) + '0');
    str = str + x;
    n = n / 3;
  }
  for(int i=0; i<str.length(); i++){
    if(str[i] - '0' > 1){
      str[i] = '0';
      for(int j=i+1; j<str.length(); j++){
      	if(str[j] - '0' >= 1){
      		str[j] = '0';
      	}
      	else{
      		str[j] = '1';
      		i = j;
      		break;
      	}
      }
    }
  }
  long long ans = 0;
  for(int i=0; i<str.length(); i++){
  	ans = ans + pow(3,i) * (str[i] - '0');
  }
  return ans;
}

int main()
{
  //write your code here
  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    if(isGood(n)){
      cout << n << endl;
    }
    else{
      // find no of digits of this number.
      int d = getDigits(n);
      // make upper bound.
      long long upper = 0;
      for(int i=0; i<d; i++){
        upper = upper + pow(3,i);
      }
      if(upper < n){
      	// next higher is answer.
      	cout << pow(3, d) << endl;
      }
      else{
      	cout << getAnswer(n) << endl;
      }
    }
  }
  return 0;
}