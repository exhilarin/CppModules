
#include "Class.hpp"
#include "Functions.hpp"

int main()
{
    srand(time(NULL));
    
    Base *obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
}
