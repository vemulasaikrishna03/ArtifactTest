#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
#include <stdexcept>

struct TestCase{
  std::string input;
  std::string output;
};

class WrongAnswer: public std::exception{
  public:
    const char* what() const throw(){
      return "Wrong Answer";
    }
};

template <typename T>
std::string to_string(std::vector<T>& arr){
  std::string res = "";
  for(int i=0;i<arr.size();i++){
    res += std::to_string(arr[i]);
    if(i!=arr.size()-1){
      res += " ";
    }
  }
  return res;
}

std::vector<std::string> split(std::string& s, char delimiter){
  std::string token;
  std::vector<std::string> res;
  std::stringstream ss(s);
  while(std::getline(ss,token,delimiter)){
    res.push_back(token);
  }
  return res;
}

std::vector<int> splitInt(std::string& s, char delimiter){
  std::string token;
  std::vector<int> res;
  std::stringstream ss(s);
  while(std::getline(ss,token,delimiter)){
    res.push_back(std::stoi(token));
  }
  return res;
}



std::vector<int> sortArray(std::vector<int>& arr){
  int n = arr.size();
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return arr;
}


int main(){
  std::ifstream myfile; myfile.open("testcases.txt");
  std::vector<TestCase> lines;
  std::string temp;
  while(std::getline(myfile,temp,'\n')){
    std::vector<std::string> words = split(temp,'#');
    TestCase tc = {words[0],words[1]};
    lines.push_back(tc);
  }
  myfile.close();
  
  for(auto& line:lines){
    std::vector<int> arr = splitInt(line.input,' ');
    std::vector<int> res = sortArray(arr);
    std::string output = to_string(res);
    if(output==line.output){
      std::cout<<"Test Passed"<<std::endl;
    }else{
      throw std::runtime_error("Wrong answer");
    }
  }
}