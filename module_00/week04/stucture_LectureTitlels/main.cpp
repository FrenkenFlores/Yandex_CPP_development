#include <string>

struct Specialization {
	std::string value;
	explicit Specialization(std::string _value){
		this->value = _value;
	}
};

struct Course {
	std::string value;
	explicit Course(std::string _value){
		this->value = _value;
	}
};

struct Week {
	std::string value;
	explicit Week(std::string _value){
		this->value = _value;
	}
};

struct LectureTitle {
	std::string specialization;
	std::string course;
	std::string week;
	LectureTitle(Specialization _specialization, Course _course, Week _week) {
		specialization = _specialization.value;
		course = _course.value;
		week = _week.value;
	}
};