#include <vector>
#include <iostream>
#include <string>
using namespace std;

class line{
  private: 
  long long int Sum;
  
  public: 
  void SetSum(vector<int> a){
    Sum=0;
    for(int i=0;i<a.size();i++)
      Sum+=a[i];
  };

  long long int GetSum(){
    return Sum;
  };
};

class line_collection{
  public: vector<line> Lines;
  
  public:
  line_collection(int count){
    Lines.resize(count);
  };

  vector<long long int> SumLines(int poz){
    int Index=Lines.size();
    int out=0;
    vector<long long int> result {0, 0};
    for(int i=0;i<Index; i++){
      if(i==poz)
        out++;
      else
        result[out]+=Lines[i].GetSum();
    };
    return result;
  };
};

int solution(vector< vector<int> > &A){
  int Index_x=A.size();
  if( Index_x==0)
    return 0;
  int Index_y=A[0].size();
  // co jeśli któryś wiersz ma mniej elementów?
  line_collection Lines_x(Index_x);
  line_collection Lines_y(Index_y);
  int result=0;
  vector<int> results_x;
  vector<int> results_y;

  for(int i=0;i<Index_x;i++)
      Lines_x.Lines[i].SetSum(A[i]);

  vector<int> tmp(Index_x, 0);
  for(int j=0;j<Index_y;j++){
    for(int i=0;i<Index_x;i++){
      tmp[i]=A[i][j];
    };
    Lines_y.Lines[j].SetSum(tmp);
  };

  for(int i=0;i<Index_x;i++){
    vector<long long int> sum_x=Lines_x.SumLines(i);
    if(sum_x[0]==sum_x[1]){
      for(int j=0;j<Index_y;j++){
        vector<long long int> sum_y=Lines_y.SumLines(j);
        if(sum_y[0]==sum_y[1]){
          result++;
          results_x.push_back(i);
          results_y.push_back(j);
        };
      };
    };
  };
  return result;
};

int main(int argc,char *argv[]){
  
  vector< vector<string> > a;
  if (argc!=2)
    return -1;
  string arg=argv[1];
  long long int k=arg.size();
  string temporary;
  for (long long int i=0;i<k;i++){
    switch(arg[i]){
      case '[':{
        vector<string> tmp;
        a.push_back(tmp);
        break;
      };
      case ']':{
        a[a.size()-1].push_back(temporary);
        temporary="";
        break;
      };
        //continue; 
      case ',':{
        a[a.size()-1].push_back(temporary);
        temporary="";
        break;
      };
      default:{
        temporary.push_back(arg[i]);
        break;
      };
    };
  };
vector< vector<int> > A;
if (a[0][0]!=""){
    for(int i=0;i<a.size(); i++){
      vector<int> tmp;
      A.push_back(tmp);
      for(int j=0;j<a[i].size(); j++){
        int tmp=stoi(a[i][j]);
        A[i].push_back(tmp);
      };
    };
};
int res= solution(A);
return res;
 

};