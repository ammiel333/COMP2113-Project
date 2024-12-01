#include <random> 
#include <vector>
using namespace std; 

int hintLocation(const vector <bool>& found){
  vector <int>* notFound = new vector<int>(); 

  vector<bool>::const_iterator current; 
  for (current = found.begin(); current != found.end(); ++current){
    if (!(*current)){
      notFound->push_back(distance(found.begin(), current)); 
    }
  }
  
  // if the answer was found, but hint was called 
  if (notFound->empty()) {
    delete notFound; 
    return -1; 
  }

  //choose a random index from the notFound vector 
  random_device rd; 
  mt19937 gen(rd()); 
  uniform_int_distribution<> distrib(0, notFound->size() -1); 

  int position = (*notFound)[distrib(gen)]; 
  delete notFound; 
  return position; 
}
