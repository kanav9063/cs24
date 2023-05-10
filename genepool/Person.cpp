#include "Person.h"

Person::Person(const std::string& name, Gender gender, Person* mother, Person* father){
    this->m_name=name;
    this->m_gender=gender;
    this->m_mother=mother;
    this->m_name=name;

}

// Destructor
Person::~Person() {}

// Required Getter Functions
const std::string& Person::name() const {
    return this->m_name;
}

Gender Person::gender() const {
    return this->m_gender;
}

Person* Person::mother()  {
    return this->m_mother;
}

Person* Person::father()  {
    return this->m_father;
}

// Required Relationship Functions
std::set<Person*> Person::ancestors(PMod pmod) {
  /* std::set<Person*> ancestors;

    for (Person* ptr: parents(pmod)) {
        ancestors.merge(ptr->ancestors());}
        ancestors.merge(parents(pmod));
    return ancestors;*/
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod) {
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod) {

}

std::set<Person*> Person::children() {}

std::set<Person*> Person::cousins(PMod pmod, SMod smod) {
}

std::set<Person*> Person::daughters() {}


  std::set<Person*> descendants(){

  }
  std::set<Person*> grandchildren(){

  }
  std::set<Person*> granddaughters(){

  }
  std::set<Person*> grandfathers(PMod pmod = PMod::ANY){

  }
  std::set<Person*> grandmothers(PMod pmod = PMod::ANY){

  }
  std::set<Person*> grandparents(PMod pmod = PMod::ANY){

  }
  std::set<Person*> grandsons(){

  }
  std::set<Person*> nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }
  std::set<Person*> nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }
 std::set<Person*> Person::parents(PMod pmod) {
  std::set<Person*> parent_set;
  if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
    if (m_mother != nullptr) {
      parent_set.insert(m_mother);
    }
  }
  if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
    if (m_father != nullptr) {
      parent_set.insert(m_father);
    }
  }
  return parent_set;
}
  std::set<Person*> siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }
  std::set<Person*> sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }
  std::set<Person*> sons(){

  }
  std::set<Person*> uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    
  }
