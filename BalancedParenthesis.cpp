#include <bits/stdc++.h> 

using namespace std;

/* 

	this function will return true only when the popped element matches the category of the closing 	bracket.

	Otherwise, we will return false.

*/

bool isMatching(char openingBracket, char closingBracket) {

	if(openingBracket == '{' && closingBracket == '}')

		return true;

	if(openingBracket == '(' && closingBracket == ')')

		return true;

	if(openingBracket == '[' && closingBracket == ']')

		return true;

	return false;

}

/* function which will return whether the expression is balanced or not */

bool isBalanced(string expression) {

	/* initialization of stack of characters */

	stack<char> s;

	

	/* start iterating over the string */

	for(int i = 0; i < expression.length(); i++) {

		/* if expression is any of the opening brackets, push it onto the stack */

		if(expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {

			s.push(expression[i]);

		}

		else {

			/* 

				check if stack is empty, return false directly.

				Because, having a closing bracket without any opening bracket doesn't mean balanced.

			 */

			if(s.empty()) {

				return false;

			}

			/* 

				otherwise check if, current closing brackets matches with the 

				category of top element of stack, if it so we pop the element.

				Otherwise, we directly return false.

			*/

			else if(!isMatching(s.top(), expression[i])){

					return false;

			}

			s.pop();

		}

	}

	/* 

		if everything is perfect till here and stack becomes empty, means the expression is balanced

		otherwise, if stack doesn't become empty, then return false.

	 */

	if(s.empty())

		return true;

	return false;

}

int main(int argc, char const *argv[]) {

	string expression1 = "[[({})]]";

	string expression2 = "[[))";

	cout << isBalanced(expression1) << endl;

	cout << isBalanced(expression2) << endl;

	return 0;

}
