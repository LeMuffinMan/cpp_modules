#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character 
{
  public: 
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string& getName();
  protected: 
    std::string& _name;
};

#endif 
