#ifndef BANKINGACCOUNTFUNCTION_H
#define BANKINGACCOUNTFUNCTION_H


class BankingAccountFunction
{
    public:
        BankingAccountFunction()
        {
            depTally = 0;
            withTally = 0;
            ATMTally = 0;
            mnthTally = 0;
            totalFees = 0.00;
            staTally = 0;
            totTally = 0;
            acctBalance = 0.00;
        }
//        virtual ~BankingAccountFunction();
//        BankingAccountFunction(const BankingAccountFunction& other);
//        BankingAccountFunction& operator=(const BankingAccountFunction& other);
        void calcDep (double);
        void calcWith (double);
        void calcATM (double);
        void calcFees (double);
        void calcBal (double);
        void calcMnthFee (double);
        void displayATMFee (double);
        void displayFees ();
        void displayBalance ();
        void displaySummary ();

    protected:

    private:
        char name;
        double depLimit = DPL, dailyLimit = DL, initbalance = IB, runBalance = RB, totalFees;
        double ATMAmount = AA, ATMFee = AF, mnthFee = MF, depFee = DF, depAmount = DA, withFee = WF;
        double withAmount = WA, acctBalance = AB;
        double DPL = 10000.00, DL = 1000.00, IB = 2372.36, AF = 3.00, MF = 12.50, RB = 0.00;
        double AB = IB + RB, DF = 2.50, DA = 0.00, WF = 0.25, WA = 0.00, AA = 0.00;
        float depTally, withTally, ATMTally, mnthTally, staTally, totTally;
};

#endif // BANKINGACCOUNTFUNCTION_H
