#pragma once

#include <string>
#include <map>

#include <boost/variant.hpp>

namespace parser {
  class Object;
  typedef boost::variant<Object,std::string> Value;

  class Object {
    std::map<const std::string, Value> elements;
  };
}
