#include <random> 
#include <vector>
using namespace std; 

int hintLocation(const vector <bool> found){
  vector <int> notFound; 
  for (int i = 0; i < found.size(); ++i){
    if (!found[i]){
      notFound.push_back(i); 
    }
  }
  
  // if the answer was found, but hint was called 
  if (notFound.empty()) {
    return -1; 
  }

  //choose a random index from the notFound vector 
  random_device rd; 
  mt19937 gen(rd()); 
  uniform_int_distribution<> distrib(0, notFound.size() -1); 

  return notFound[distrib(gen)]; 
}
