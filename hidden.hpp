#include "common.hpp"
#include "input.hpp"
#ifndef HIDDEN_HPP
#define HIDDEN_HPP

class Hidden{
  
  std::vector<std::pair < Input*, float> > inputs;

public:
  Hidden(std::vector<Input*> in){
    for (std::vector<Input*>::iterator it = in.begin(); it!=in.end(); ++it) {
      inputs.push_back(std::make_pair(*it,RAND));
    }
  }
  float propagate(){
    float sum = 0;
    for (int i = 0; i < inputs.size();++i){
      
      sum += inputs[i].first->getValue()*inputs[i].second;

    }
    sum = atan(0.5*sum);

    return sum;
  }
  void backpropagate(float error){
    for (int i = 0; i < inputs.size();++i){
      
     inputs[i].second += error*RAND*RAND;

    }

  }
  std::string serialize(){
    std::string result;
    std::stringstream buf1,buf2;
       
    for (int i = 0; i < inputs.size();++i){
      buf1 << i;
      buf2 << inputs[i].second;
      result += "["+buf1.str()+ "#"+inputs[i].first->serialize()+"#"+buf2.str()+"]";
      buf1.str("");
      buf2.str("");
    }
    
    return result;
    }
};

#endif
