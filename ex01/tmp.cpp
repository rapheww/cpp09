// static bool isDigit(const std::string &token)
// {
//     return token.length() == 1 && std::isdigit(token[0]);
// }

// static bool isOperator(const std::string &token)
// {
//     return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
// }

// int RPN::calculate(std::string &str)
// {
//     std::stack<int> stack;
//     std::stringstream ss(str);
//     std::string token;

//     while (ss >> token)
//     {
//         if (isDigit(token))
//             stack.push(token[0] - '0');
//         else if (isOperator(token))
//         {
//             if (stack.size() < 2)
//                 throw std::runtime_error("Error: RPN invalid.");
//             int second = stack.top();
//             stack.pop();
//             int first = stack.top();
//             stack.pop();
//             switch (token[0])
//             {
//                 case '+':
//                     stack.push(first + second);
//                     break;
//                 case '-':
//                     stack.push(first - second);
//                     break;
//                 case '*':
//                     stack.push(first * second);
//                     break;
//                 case '/':
//                     if (second == 0)
//                         throw std::runtime_error("Error: RPN invalid.");
//                     stack.push(first / second);
//                     break;
//             }
//         }
//         else
//             throw std::runtime_error("Error: RPN invalid.");
//     }
//     if (stack.size() != 1)
//         throw std::runtime_error("Error: RPN invalid.");
//     return stack.top();
// }