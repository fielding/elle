//
//  Entity.h
//  elle
//
//  Created by Fielding Johnston on 6/5/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Entity__
#define __elle__Entity__

#include <unordered_map>
#include "common.h"

class Entity
{
public:
  Entity() {}
  
  template<typename T> void addComponent(T* comp)
  {
    components.insert(std::pair<const std::type_info*, IComponent*>(&typeid(*comp), comp));
  }
  
  template<typename T> T *getComponent()
  {
    return static_cast<T*>(components[&typeid(T)]);
  }
  
  template<typename T> void removeComponent()
  {
    if (components.count(&typeid(T)))
    {
      T *component = static_cast<T*>(components[&typeid(T)]);
      components.erase(&typeid(T));
      delete component;
    }
  }
  
  
  
  std::unordered_map<const std::type_info*, IComponent*> components;
};

#endif /* defined(__elle__Entity__) */

