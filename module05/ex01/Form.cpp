#include "Form.hpp"

Form::Form(/* args */)
{
}

Form::~Form()
{
}

std::ostream& operator<<(std::ostream& os, const Form& point) {
        os << "Form name : " << point.getName() << ", Grade to sign : " << \
				point.getSignGrade() << ", Grade to execute : " << point.getExecGrade() \
				<< ", Form " << (point.getIsSigned() == true ? ", is signed" : ", is not signed");
        return os;
}