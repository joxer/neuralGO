#include "common.hpp"

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

class Output{

  std::vector<std::pair < Hidden*, float> > hidden;

public:
  Output(std::vector<Hidden*> in){
    for (std::vector<Hidden*>::iterator it = in.begin(); it!=in.end(); ++it) {
      hidden.push_back(std::make_pair(*it,RAND));
    }
  }
  
  float propagate(){

    float sum = 0;
    for (int i = 0; i < hidden.size();++i){
      
      sum += hidden[i].first->propagate()*hidden[i].second;

    }
    sum = 1/(1+exp(-sum));
    
    return sum;
    
  }

  float learn(){
    float sum;
    do{
      sum = propagate();
      float error = 1-sum;
      backpropagate(error);
    }
    while(sum < 0.9);
    std::cout << "true" << std::endl;
  }
  
  void backpropagate(float error){
    
    for(int i = 0; i < hidden.size();++i){
      
      hidden[i].second += error*RAND*RAND;
      hidden[i].first->backpropagate(error);
    }   
  }

    std::string serialize(){
    std::string result;
    std::stringstream buf1,buf2;
       
    for (int i = 0; i < hidden.size();++i){
      buf1 << i;
      buf2 << hidden[i].second;
      result += "{"+buf1.str()+ "*"+hidden[i].first->serialize()+"*"+buf2.str()+"}";
      buf1.str("");
      buf2.str("");
    }

    return result;
    }

};
#endif
