#include "Person.h"

#include <iostream>
#include <set>
#include <algorithm>

Person::Person(const std::string& name, Gender gender, Person* mother, Person* father):_name(name){
    this->_gender=gender;
    this->_mother=mother;
    this->_father=father;
    if (_mother !=nullptr)
    _mother-> addChild(this);
      if (_father !=nullptr)
    _father-> addChild(this);

}

void Person::addChild(Person *person)
{
    if (person->gender() == Gender::MALE)
    {
        _sons.insert(person);
    }
    else
    {
        _daughters.insert(person);
    }
}

// Person Member Functions
const std::string &Person::name() const
{
    return _name;
}

Gender Person::gender() const
{
    return _gender;
}

Person *Person::mother()
{
    return _mother;
}

Person *Person::father()
{
    return _father;
}

std::set<Person *> Person::ancestors(PMod pmod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            result.insert(_mother);
            std::set<Person *> res2 = _mother->ancestors(PMod::ANY);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            result.insert(_father);
            std::set<Person *> res2 = _father->ancestors(PMod::ANY);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    return result;
}
std::set<Person *> Person::aunts(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->sisters(PMod::ANY, smod);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->sisters(PMod::ANY, smod);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    return result;
}
std::set<Person *> Person::brothers(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->sons();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->father() == _father)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->father() != _father)
                {
                    result.insert(person);
                }
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->sons();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->mother() == _mother)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->mother() != _mother)
                {
                    result.insert(person);
                }
            }
        }
    }
    return result;
}
std::set<Person *> Person::children()
{
    std::set<Person *> result;
    std::merge(_sons.begin(), _sons.end(), _daughters.begin(), _daughters.end(), std::inserter(result, result.begin()));
    return result;
}
std::set<Person *> Person::cousins(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->siblings(PMod::ANY, smod);
            for (Person *person : res2)
            {
                std::set<Person *> res3 = person->children();
                if (!res3.empty())
                    result.insert(res3.begin(), res3.end());
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->siblings(PMod::ANY, smod);
            for (Person *person : res2)
            {
                std::set<Person *> res3 = person->children();
                if (!res3.empty())
                    result.insert(res3.begin(), res3.end());
            }
        }
    }
    return result;
}
std::set<Person *> Person::daughters()
{
    return _daughters;
}
std::set<Person *> Person::descendants()
{
    std::set<Person *> result;
    std::set<Person *> res2 = children();
    if (!res2.empty())
    {
        result.insert(res2.begin(), res2.end());
        for (Person *person : res2)
        {
            std::set<Person *> res3 = person->descendants();
            if (!res3.empty())
                result.insert(res3.begin(), res3.end());
        }
    }
    return result;
}
std::set<Person *> Person::grandchildren()
{
    std::set<Person *> result;
    for (Person *person : _sons)
    {
        std::set<Person *> res2 = person->children();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    for (Person *person : _daughters)
    {
        std::set<Person *> res2 = person->children();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    return result;
}
std::set<Person *> Person::granddaughters()
{
    std::set<Person *> result;
    for (Person *person : _sons)
    {
        std::set<Person *> res2 = person->daughters();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    for (Person *person : _daughters)
    {
        std::set<Person *> res2 = person->daughters();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    return result;
}
std::set<Person *> Person::grandfathers(PMod pmod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr && _mother->father() != nullptr)
        {
            result.insert(_mother->father());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr && _father->father() != nullptr)
        {
            result.insert(_father->father());
        }
    }
    return result;
}
std::set<Person *> Person::grandmothers(PMod pmod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr && _mother->mother() != nullptr)
        {
            result.insert(_mother->mother());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr && _father->mother() != nullptr)
        {
            result.insert(_father->mother());
        }
    }

    return result;
}
std::set<Person *> Person::grandparents(PMod pmod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->parents(PMod::ANY);
            result.insert(res2.begin(), res2.end());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->parents(PMod::ANY);
            result.insert(res2.begin(), res2.end());
        }
    }

    return result;
}
std::set<Person *> Person::grandsons()
{
    std::set<Person *> result;
    for (Person *person : _sons)
    {
        std::set<Person *> res2 = person->sons();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    for (Person *person : _daughters)
    {
        std::set<Person *> res2 = person->sons();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    return result;
}
std::set<Person *> Person::nephews(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    std::set<Person *> _siblings = siblings(pmod, smod);
    for (Person *person : _siblings)
    {
        std::set<Person *> res2 = person->sons();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    return result;
}
std::set<Person *> Person::nieces(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    std::set<Person *> _siblings = siblings(pmod, smod);
    for (Person *person : _siblings)
    {
        std::set<Person *> res2 = person->daughters();
        if (!res2.empty())
            result.insert(res2.begin(), res2.end());
    }
    return result;
}
std::set<Person *> Person::parents(PMod pmod)
{
    std::set<Person *> result;
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            result.insert(_father);
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            result.insert(_mother);
        }
    }
    return result;
}
std::set<Person *> Person::siblings(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->children();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->father() == _father)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->father() != _father)
                {
                    result.insert(person);
                }
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->children();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->mother() == _mother)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->mother() != _mother)
                {
                    result.insert(person);
                }
            }
        }
    }

    return result;
}
std::set<Person *> Person::sisters(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->daughters();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->father() == _father)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->father() != _father)
                {
                    result.insert(person);
                }
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->daughters();
            for (Person *person : res2)
            {
                if (person == this)
                {
                    continue;
                }
                if ((smod == SMod::FULL || smod == SMod::ANY) && person->mother() == _mother)
                {
                    result.insert(person);
                }
                if ((smod == SMod::HALF || smod == SMod::ANY) && person->mother() != _mother)
                {
                    result.insert(person);
                }
            }
        }
    }
    return result;
}
std::set<Person *> Person::sons()
{
    return _sons;
}
std::set<Person *> Person::uncles(PMod pmod, SMod smod)
{
    std::set<Person *> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if (_mother != nullptr)
        {
            std::set<Person *> res2 = _mother->brothers(PMod::ANY, smod);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if (_father != nullptr)
        {
            std::set<Person *> res2 = _father->brothers(PMod::ANY, smod);
            if (!res2.empty())
                result.insert(res2.begin(), res2.end());
        }
    }
    return result;
}