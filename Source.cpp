//14. Программирование.
#include<iostream>
#include<string>
#include<vector>

class Programmer {
protected:
  std::vector<std::string> skills;
public:
  Programmer(const std::vector<std::string>& list) :skills{ list }{}
  ~Programmer() = default;
  void show_programmer() {
    std::cout << "Programmer with skils:" << std::endl;
    for (int i = 0; i < skills.size(); i++) {
      std::cout <<"-"<< skills[i] << std::endl;
    }
  }
};
class FrontendProgrammer : virtual public Programmer {
protected:
  bool use_adeptive_ui;
public:
  FrontendProgrammer(bool use_adeptive_ui,const std::vector<std::string>& list):use_adeptive_ui(use_adeptive_ui),Programmer(list){
    skills.push_back("Frontend");
  }
  ~FrontendProgrammer() = default;
  bool get_use_adeptive_ui() {
    return use_adeptive_ui;
  }
};

class WebProgrammer : public FrontendProgrammer {
protected:
  std::string framework;
public:
  WebProgrammer(std::string framework, bool use_adeptive_ui,const std::vector<std::string>& list) : framework(framework),FrontendProgrammer(use_adeptive_ui,list), Programmer(list) {
    skills.push_back("Web");
  } 
  ~WebProgrammer() = default;
};

class SystemProgrammer : virtual public Programmer {
protected:
  std::string os;
public:
  SystemProgrammer(std::string os, const std::vector<std::string>& list) :os(os),Programmer(list) {
    skills.push_back("System");
  }
  ~SystemProgrammer() = default;

  std::string get_os() {
    return os;
  }
};

class BackendProgrammer : public SystemProgrammer {
public:
  BackendProgrammer(std::string os,const std::vector<std::string>& list) 
    : SystemProgrammer(os,list), Programmer(list) {
    skills.push_back("Backend");
  }
  ~BackendProgrammer() = default;
};

class FullStackProgrammer : public WebProgrammer, public BackendProgrammer {
public:
  FullStackProgrammer(std::string os, std::string framework, bool use_adeptive_ui, const std::vector<std::string>& list)
    : WebProgrammer(framework, use_adeptive_ui, list), BackendProgrammer(os,list), Programmer(list){}
  ~FullStackProgrammer() = default;
  void show_programmer() {
    std::cout << "Programmer with skils:" << std::endl;
    for (int i = 0; i < skills.size(); i++) {
      std::cout << "-" << skills[i] << std::endl;
    }
    std::cout << "Operation system - " << os << std::endl;
    std::cout << "Framework - " << framework << std::endl;
    std::cout << "Use adaptive ui - " << std::boolalpha << use_adeptive_ui << std::endl;
  }
};

int main() {
  std::cout << "Please, enter skills for programmer(* to stop):" << std::endl;
  std::vector<std::string>skills;

  while (true) {
    std::string skill;
    std::getline(std::cin, skill);
    if (skill == "*") {
      break;
    }
    skills.push_back(skill);
  }
  std::cout << "Enter operating system:";
  std::string os;
  std::getline(std::cin, os);
  std::cout << "Enter framework:";
  std::string framework;
  std::getline(std::cin, framework);
  std::cout << "Is programmer use adaptive ui?(yes/no)" << std::endl;
  bool use_adeptive_ui;
  while (true) {
    std::string buffer;
    std::getline(std::cin, buffer);
    if (buffer != "yes" && buffer != "no") {
      std::cout << "yes or no!!" << std::endl;
    }
    if (buffer == "yes") {
      use_adeptive_ui = true;
      break;
    } else if (buffer == "no") {
      use_adeptive_ui = false;
      break;
    }
  }
  FullStackProgrammer fullStackProgrammer(os, framework, use_adeptive_ui, skills);
  fullStackProgrammer.show_programmer();
  return 0;
}