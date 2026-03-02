#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>

#include "MathWorker/MathUtils/MathDefines.hpp"
#include "MathWorker/Parse/ParseException.hpp"
#include "MathWorker/Parse/Parser.hpp"
#include "MathWorker/Parse/Tokenizer.hpp"
#include "MathWorker/Signature/FunctionConnector.hpp"
#include "MathWorker/Signature/Signature.hpp"
#include "MathWorker/Signature/SignatureGenerator.hpp"
#include "MathWorker/StringConvert/ComplexStringConverter.hpp"

static void printHelp()
{
    std::cout << R"help(mclc — консольный калькулятор (MathWorker)

Использование:
  mclc [опции] [определения...] <выражение>

Где:
  <выражение>           математическое выражение (последний аргумент).
  [определения...]      определения констант/функций, которые будут доступны в выражении.
                        Форматы:
                          a=2
                          z=3+4i
                          f(x)=x^2+1
                          g(x,y)=x+y

Опции форматирования результата:
  --prec <N>            точность (кол-во знаков после точки). По умолчанию: 6
  --algebr              комплексное число в алгебраической форме. По умолчанию
  --triganam            тригонометрическая форма
  --indicat             показательная форма
  --polar               полярная форма

Опции углов (для форм с аргументом):
  --degree              аргумент в градусах. По умолчанию
  --radian              аргумент в радианах

Опции вывода числа:
  --fixed               числа выводятся в десятичной записи. По умолчанию
  --scient              числа выводятся в научном формате

Служебные опции:
  --help                показать эту справку
  --version             показать версию

Примеры:
  mclc "2+2"
  mclc a=2 "a^3+1"
  mclc f(x)=x^2 --prec 4 "f(1.5)"
  mclc --polar --radian "1+i"
)help" << '\n';
}

static void printVersion()
{
    std::cout << R"(mclc utility version: 1.0.0)" << '\n';
}

int main(int argc, char **argv)
{
#ifdef _WIN32
    std::system("chcp 65001 > nul");
#endif

    if (argc == 1)
    {
        printHelp();
        return 0;
    }

    mathWorker::ComplexStringConverter converter;
    mathWorker::Signature signature = mathWorker::generator::mathSignature();
    mathWorker::DirectSignatureConnector connector(signature);

    for (int i = 1; i < argc; ++i)
    {
        if (!std::strcmp(argv[i], "--help"))
            printHelp();
        else if (!std::strcmp(argv[i], "--version"))
            printVersion();
        else if (!std::strcmp(argv[i], "--prec") && i != argc - 1)
            converter.precession = std::atoi(argv[++i]);
        else if (!std::strcmp(argv[i], "--algebr"))
            converter.complexType = mathWorker::ComplexOutputType::algebraic;
        else if (!std::strcmp(argv[i], "--triganam"))
            converter.complexType = mathWorker::ComplexOutputType::trigonometric;
        else if (!std::strcmp(argv[i], "--indicat"))
            converter.complexType = mathWorker::ComplexOutputType::indicative;
        else if (!std::strcmp(argv[i], "--polar"))
            converter.complexType = mathWorker::ComplexOutputType::polar;
        else if (!std::strcmp(argv[i], "--radian"))
            converter.angleType = mathWorker::AngleOutputType::radians;
        else if (!std::strcmp(argv[i], "--degree"))
            converter.angleType = mathWorker::AngleOutputType::degrees;
        else if (!std::strcmp(argv[i], "--fixed"))
            converter.realOutType = mathWorker::RealOutputType::fixed;
        else if (!std::strcmp(argv[i], "--scient"))
            converter.realOutType = mathWorker::RealOutputType::scientific;
        else
        {
            if (i == argc - 1)
                continue;
            try
            {
                connector.addTerm(argv[i]);
            }
            catch (const mathWorker::ParseException &e)
            {
                std::cout << "Parse exception: " << e.what() << "\nException type: " << static_cast<int>(e.type()) << '\n';
            }
            catch (const std::exception &e)
            {
                std::cout << "Std exception: " << e.what() << '\n';
            }
            catch (...)
            {
                std::cout << "Unknown exception\n";
            }
        }
    }
    if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == '-')
        return 0;
    mathWorker::BaseTokenizer tokenizer(signature);
    mathWorker::MathParser parser(tokenizer);
    mathWorker::ComplexType result{};
    try
    {
        mathWorker::MathNodeP node = parser.parse(argv[argc - 1]);
        result = node->replace(signature.getVariableContext())->calculate(signature)->getNumberForced();
    }
    catch (const mathWorker::ParseException &e)
    {
        std::cout << "Parse exception: " << e.what() << "\nException type: " << static_cast<int>(e.type()) << '\n';
        return static_cast<int>(e.type());
    }
    catch (const std::exception &e)
    {
        std::cout << "Std exception: " << e.what() << '\n';
        return 4;
    }
    catch (...)
    {
        std::cout << "Unknown exception\n";
        return 5;
    }

    std::cout << converter.toString(result) << '\n';

    return 0;
}