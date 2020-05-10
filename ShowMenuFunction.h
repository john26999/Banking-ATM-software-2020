#ifndef SHOWMENUFUNCTION_H
#define SHOWMENUFUNCTION_H


class ShowMenuFunction
{
    public:
        ShowMenuFunction();
        virtual ~ShowMenuFunction();
        ShowMenuFunction(const ShowMenuFunction& other);
        ShowMenuFunction& operator=(const ShowMenuFunction& other);

        void showMenu(ofstream &);
        void PrintIntroScreen (ofstream &);


    protected:

    private:
};

#endif // SHOWMENUFUNCTION_H
