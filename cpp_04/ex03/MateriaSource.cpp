#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    _skillIndex = 0;
    for(size_t i = 0; i < MATERIA_LENGTH ; i++)
    {
        _aMateria[i] = NULL;
    }
    std::cout << "MateriaSource constructor void calledl " << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    for(size_t i = 0; i < MATERIA_LENGTH; i++)
    {
        if(_aMateria[i])
        {
            delete _aMateria[i];
        }
    }
    std::cout << "MateriaSource Deconstructor void calledl " << std::endl;
}

void    MateriaSource::learnMateria(AMateria *materia)
{
    if(_skillIndex < 4 && _skillIndex >= 0)
    {
        _aMateria[_skillIndex++] = materia;
    // std::cout << "c1reateMateria" <<   _aMateria[0]->getType() <<std::endl;

    }    
    else
        delete materia;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
    for(size_t i = 0; i < MATERIA_LENGTH; i++)
    {
        if(_aMateria[i] != NULL && _aMateria[i]->getType() == type)
             return _aMateria[i]->clone();
            // std::cout << "createMateria" <<   _aMateria[i]->getType() <<std::endl;
            // return _aMateria[i]->clone();
    }
    // std::cout <<"type >> "<< type <<std::endl;

    return NULL;
}
//  void learnMateria(AMateria*);
//         AMateria* createMateria(std::string const & type);
