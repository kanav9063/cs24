#include "GenePool.h"
#include <iostream>
#include <sstream>

GenePool::GenePool(std::istream& stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        if (line[0] == '#' || line.empty())
        {
            continue;
        }
        std::istringstream iss(line);
        std::string tmp;
        size_t c=0;
        std::string name;
        Gender gender;
        Person* mother;
        Person* father;

        while (std::getline(iss, tmp, '\t'))
        {
            switch (c)
            {
                case 0:
                    name = tmp;
                    break;
                case 1:
                    gender = (tmp == "M") ? Gender::MALE : Gender::FEMALE;
                    break;
                case 2:
                    if (tmp != "NULL")
                    {
                        mother = find(tmp);
                    }
                    else
                    {
                        mother = nullptr;
                    }
                    break;
                case 3:
                    if (tmp != "NULL")
                    {
                        father = find(tmp);
                    }
                    else
                    {
                        father = nullptr;
                    }
                    break;
                default:
                    std::cerr << "Too many fields in line: " << line << std::endl;
                    break;
            }
            c++;
        }

        Person *p = new Person(name, gender, mother, father);
        people.insert(p);
    }
}

GenePool::~GenePool()
{
    for (auto person : people)
    {
        delete person;
    }
}

std::set<Person *> GenePool::everyone() const
{
    return people;
}


Person* GenePool::find(const std::string& name) const
{
    for (auto person : people)
    {
        if (person->name() == name)
        {
            return person;
        }
    }

    return nullptr;
}