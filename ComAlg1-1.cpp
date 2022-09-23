#include <iostream>

using namespace std;

class InputNum
{
    public:
        InputNum()
        {
            cout << "Enter number\n";
            cin >> _num;
        }

        int GetValue () const { return _num; }

        void SubtractInput()
        {
            InputNum aNum;  // get a number from user
            _num = _num - aNum.GetValue();
        }
    private:
        int _num;
};

int main()
{
    InputNum num;
    cout << "The value is " << num.GetValue() << "\n";
    num.SubtractInput();
    cout << "Now the value is " << num.GetValue() << "\n";
}