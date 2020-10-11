//checkbook.h - A class for a checkbook

class Checkbook
{
    //依据惯例，函数原型位于共用部分，数据成员位于私有部分
    //有时候函数原型也位于私有部分，但是仅类的设计人员不希望在对象之外调用这个函数时才使用这种方式。
    //类的设计人员希望该函数只能被对象内的其他函数调用
    public:
        void setBalance(float amount);
        bool writeCheck(float amount);//return false if amount is greater than balance;
                                      //otherwise returns true
        void deposit(float amount);
        float getBalance();
        float getLastCheck();
        float getLaastDeposit();
    
    private:
        float balance;
        float lastCheck;
        float lastDeposit;
};