#include <vector>
#include <algorithm>

class FunctionPart {
public:
	FunctionPart(const char opr, const double  val) {
		this->operation = opr;
		this->value = val;
	}
	double Apply(double val) const{
		if (operation == '+') {
			val += value;
		} else if (operation == '-') {
			val -= value;
		} else if (operation == '*') {
			val *= value;
		} else if (operation == '/') {
			val /= value;
		}
		return val;
	};
	void Invert(void) {
		if (operation == '+') {
			operation = '-';
		} else if (operation == '-') {
			operation = '+';
		} else if (operation == '*') {
			operation = '/';
		} else if (operation == '/') {
			operation = '*';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(const char opr, const double val) {
		parts.push_back(FunctionPart(opr, val));
	}
	double Apply(double val) const {
		for (const FunctionPart &part : parts) {
			val = part.Apply(val);
		}
		return val;
	}
	void Invert(void) {
		for (FunctionPart &part : parts) {
			part.Invert();
		}
		std::reverse(begin(parts), end(parts));
	}

private:
	std::vector<FunctionPart> parts;
};