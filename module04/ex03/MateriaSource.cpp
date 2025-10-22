#include "MateriaSource.hpp"

MateriaSource::MateriaSource () {
	std::cout << "Default constructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "Copy constructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "Copy assignment of MateriaSource operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia) {
	std::cout << "MateriaSource learnMateria was called" << std::endl;
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++){
		if (!_templates[i]) {
			_templates[i] = materia;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	std::cout << "MateriaSource createMateria was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (NULL);
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
	}
}