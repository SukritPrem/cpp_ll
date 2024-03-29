#include "AForm.hpp"

AForm::AForm(void):  _nameStr("UnknowName"),
                    _name("UnknowName"),
                    _signed(false),
                    _gradeSignein(0),
                    _gradeExecute(0)
{
    // std::cout << "AForm Constructor void Called " << std::endl;
}

AForm::~AForm(void)
{
    // std::cout << "AForm Deconstructor Called " << std::endl;
}

AForm::AForm(AForm &r_obj) : _nameStr(r_obj.getName()),
                            _signed(r_obj.getSigned()),
                            _gradeSignein(r_obj.getGradeSignein()),
                            _gradeExecute(r_obj.getGradeExecute())
{
    std::cout << "AForm Copy Constructor Called " << std::endl; 
}


void    AForm::beSigned(Bureaucrat &obj)
{

        if(obj.getGrade() > _gradeSignein){
            throw GradeTooLowException();
        }
        else 
            _signed = true;
}

 bool       AForm::checkGradeExecutor(Bureaucrat const & executor) const
 {
    if(executor.getGrade() > _gradeExecute)
        throw AForm::GradeTooLowException();
    return true;
 }

std::ostream& operator<<(std::ostream &o, AForm &r_obj)
{
    o << "AForm Name : " << r_obj.getName() << std::endl
    <<  "Sign : " << r_obj.getSigned() << std::endl
    <<  "Grade Signin : " << r_obj.getGradeSignein() << std::endl
    <<  "Grade Execute : " << r_obj.getGradeExecute() << std::endl;
    return o;
}
// AForm & operator=(AForm &r_obj);
// AForm(AForm &r_obj);

AForm::AForm(const char *ptr,
        int gradeSignein,
        int gradeExecute) :
        _name(ptr),
        _signed(false),
        _gradeSignein(gradeSignein),
        _gradeExecute(gradeExecute)
{
    if(_name == NULL)
        throw StrNull();
    else
        _nameStr = _name;

    if(gradeExecute < GRADE_MAX|| gradeSignein < GRADE_MAX)
    {
        throw GradeTooHighException();
    }
    else if(gradeExecute > GRADE_MIN || gradeSignein > GRADE_MIN)
    {
        throw GradeTooLowException();
    }
    // std::cout << "AForm Constructor name signed gradesignein gradeexecute Called " << std::endl;
}

std::string    AForm::getName(void) const{return _nameStr;}
bool    AForm::getSigned(void) const{return _signed;}
int AForm::getGradeSignein(void) const{return _gradeSignein;}
int AForm::getGradeExecute(void) const{return _gradeExecute;}
void    AForm::setSigned(bool sign){_signed = sign;}


