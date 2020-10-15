// Copyright 2020 ALexei Kushpelev leha.kushpelev@mail.ru
#ifndef INCLUDE_PARSER_HPP_
#define INCLUDE_PARSER_HPP_

#include <string>
#include <vector>

#include "student.hpp"
using nlohmann::json;

class Parser {
 public:
  explicit Parser(const std::string& jsonPath);
  void Print_columns(std::ostream& out) const;
  void Print_lines(std::ostream& out) const;
  const std::vector<Student>& getStudents() const;
  const std::vector<size_t>& getColumn_width() const;
  const std::vector<std::string>& getColumn_name() const;
  friend std::ostream& operator<<(std::ostream& out, Parser& pars);

 private:
  std::vector<Student> students;
  std::vector<size_t> column_width{0, 9, 7, 15};
  std::vector<std::string> column_name{"name", "group", "avg", "debt"};
};

#endif  // INCLUDE_PARSER_HPP_
