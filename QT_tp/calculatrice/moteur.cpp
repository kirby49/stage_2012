#include "moteur.h"

Moteur::Moteur()
{
}

Moteur::~Moteur()
{
    m_stack_nbr.clear();
    m_stack_op.clear();
}

void Moteur::add1()
{
    m_number.append("1");
    emit valueChanged(m_number);
}

void Moteur::add2()
{
    m_number.append("2");
    emit valueChanged(m_number);
}

void Moteur::add3()
{
    m_number.append("3");
    emit valueChanged(m_number);
}

void Moteur::add4()
{
    m_number.append("4");
    emit valueChanged(m_number);
}

void Moteur::add5()
{
    m_number.append("5");
    emit valueChanged(m_number);
}

void Moteur::add6()
{
    m_number.append("6");
    emit valueChanged(m_number);
}

void Moteur::add7()
{
    m_number.append("7");
    emit valueChanged(m_number);
}

void Moteur::add8()
{
    m_number.append("8");
    emit valueChanged(m_number);
}

void Moteur::add9()
{
    m_number.append("9");
    emit valueChanged(m_number);
}

void Moteur::add0()
{
    m_number.append("0");
    emit valueChanged(m_number);
}

void Moteur::dot()
{
    m_number.append(".");
    emit valueChanged(m_number);
}

void Moteur::plus()
{
    if(!m_number.isEmpty())
    {
        m_stack_nbr.push(m_number);
        test.push_back(m_number);
        m_number.clear();
        calculateOrder("+");
    }
    else
    {
        if(!m_stack_nbr.isEmpty())
        {
            if(!m_stack_op.isEmpty()) m_stack_op.pop();
            m_stack_op.push("+");
            test.push_back("+");
            emit opChanged("+");
        }
    }

}

void Moteur::less()
{
    if(!m_number.isEmpty())
    {
        m_stack_nbr.push(m_number);
        test.push_back(m_number);
        m_number.clear();
        calculateOrder("-");
    }
    else
    {
        if(!m_stack_nbr.isEmpty())
        {
            if(!m_stack_op.isEmpty()) m_stack_op.pop();
            m_stack_op.push("-");
            test.push_back("-");
            emit opChanged("-");
        }
    }
}

void Moteur::times()
{
    if(!m_number.isEmpty())
    {
        m_stack_nbr.push(m_number);
        test.push_back(m_number);
        m_number.clear();
        calculateOrder("*");
    }
    else
    {
        if(!m_stack_nbr.isEmpty())
        {
            if(!m_stack_op.isEmpty()) m_stack_op.pop();
            m_stack_op.push("*");
            test.push_back("*");
            emit opChanged("*");
        }
    }
}

void Moteur::divide()
{
    if(!m_number.isEmpty())
    {
        m_stack_nbr.push(m_number);
        test.push_back(m_number);
        m_number.clear();
        calculateOrder("/");
    }
    else
    {
        if(!m_stack_nbr.isEmpty())
        {
            if(!m_stack_op.isEmpty()) m_stack_op.pop();
            m_stack_op.push("/");
            test.push_back("/");
            emit opChanged("/");
        }
    }
}

void Moteur::bracketL()
{

}

void Moteur::bracketR()
{

}

void Moteur::square()
{
    if(!m_number.isEmpty())
    {
        m_stack_nbr.push(m_number);
        test.push_back(m_number);
        m_number.clear();
        calculateOrder("^2");
    }
    else
    {
        if(!m_stack_nbr.isEmpty())
        {
            if(!m_stack_op.isEmpty()) m_stack_op.pop();
            calculate("^2");
        }
    }
}

void Moteur::clear()
{
    m_stack_nbr.clear();
    m_stack_op.clear();
    test.clear();
}

void Moteur::afficheEqu()
{
}

void Moteur::calculateOrder(QString sign)
{   echoVector();
    if(!m_stack_op.isEmpty())
    {
        QString signpop = m_stack_op.pop();
        int signP = getPriority(sign);
        int signpopP = getPriority(signpop);

        if(signP > signpopP)
        {
                m_stack_op.push(signpop);
                test.push_back(sign);
                m_stack_op.push(sign);
        }
        else
        {

            calculate(signpop);
            if(!m_stack_op.isEmpty()) calculateOrder(sign);
            else {m_stack_op.push(sign);
                test.push_back(sign);
            }
        }
    }
    else
    {
        m_stack_op.push(sign);
        test.push_back(sign);
        emit opChanged(sign);
    }
}

void Moteur::calculate(QString sign)
{

    float secnum = m_stack_nbr.pop().toFloat();
    float num = m_stack_nbr.pop().toFloat();

    if(sign == "+")
    {
        num += secnum;
    }
    if(sign == "-")
    {
        num -= secnum;
    }
    if(sign == "*")
    {
        num *= secnum;
    }
    if(sign == "/")
    {
        num = num / secnum;
    }
    if(sign == "^2")
    {
        m_stack_nbr.push(m_number.setNum(num));
        num = secnum*secnum;
    }
    std::cout << qPrintable(sign) << " :" << num << endl;
    m_stack_nbr.push(m_number.setNum(num,'f'));
    emit valueChanged(m_number.setNum(num,'f'));
    m_number.clear();
}

int Moteur::getPriority(QString sign)
{
    if(sign == "+" || sign == "-") return 0;
    else return (sign == "*" || sign == "/") ? 1 : 2;
}

void Moteur::echoVector()
{
    QString var;
    foreach(var,test)

        std::cout << qPrintable(var);
}

