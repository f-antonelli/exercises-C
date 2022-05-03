#include <iostream>
#include <stdbool.h>

using namespace std;

class Boolean{
    private:
        int falseBoolean, trueBoolean;
    public:
        Boolean(int, int);
        int _and(int);
        int _or(int);
        int _not();
};

Boolean::Boolean(int _false, int _true){
    falseBoolean = _false;
    trueBoolean = _true;
}

//int Boolean::_and() {}

int main()
{

    Boolean falseBoolean, trueBoolean(1); //true

    Boolean resultFalseAndTrue = falseBoolean._and(trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean._or(trueBoolean);
    Boolean resultNotFalse = falseBoolean._not();

    cout << "resultFalseAndTrue:" << resultFalseAndTrue.getValue() << endl;
    cout << "resultTrueOrTrue  :" << resultTrueOrTrue.getValue() << endl;
    cout << "resultNotFalse    :" << resultNotFalse.getValue() << endl;

    return 0;
}
